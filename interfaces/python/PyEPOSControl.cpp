//------------------------------------------------------------------------------
// Exposes the EPOSControl library as a Python extension
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include "Python.h"
#include "structmember.h"

#include <math.h>
#include "EPOSControl/EPOSControl.h"

//#define GP_CHANNEL_IDX 1
//#define GP_CHANNEL_IDX_STR "1"
#define GP_CHANNEL_IDX 2
#define GP_CHANNEL_IDX_STR "2"

//------------------------------------------------------------------------------
static CANChannel* gpChannel = NULL;

//------------------------------------------------------------------------------
typedef struct 
{
    PyObject_HEAD
    
    // Motor controller states
    S32 MCS_INACTIVE;
    S32 MCS_SETTING_UP;
    S32 MCS_RUNNING;
    S32 MCS_HOMING;
} EPOSControlObject;

//------------------------------------------------------------------------------
// Returns data for the motor controllers on the CAN channels.
// The data is returned as a dictionary of CAN channels. Each CAN channel
// is then a dictionary containing the data tuples
//
//         ( controllerState, angleValid, angle )
//
static PyObject* getMotorControllerData( PyObject* pSelf, PyObject* args )
{
    // Get the information from the EPOS control library
    MotorControllerData controllerData[ CANChannel::MAX_NUM_MOTOR_CONTROLLERS ];
    S32 numControllers = 0;
    gpChannel->GetMotorControllerData( controllerData, &numControllers );
    
    // Build the information into dictionaries
    PyObject* pNodeDict = PyDict_New();
    for ( S32 i = 0; i < numControllers; i++ )
    {
        PyObject* pKey = PyString_FromFormat( "%i", controllerData[ i ].mNodeId );
        
        PyObject *pTuple = PyTuple_New( 3 );
        PyTuple_SetItem( pTuple, 0, PyInt_FromLong( controllerData[ i ].mState ) );
        PyTuple_SetItem( pTuple, 1, PyBool_FromLong( controllerData[ i ].mbAngleValid ) );
        PyTuple_SetItem( pTuple, 2, PyInt_FromLong( controllerData[ i ].mAngle ) );

        PyDict_SetItem( pNodeDict, pKey, pTuple );
        Py_DECREF( pKey );
        Py_DECREF( pTuple );
    }
    
    PyObject* pChannelDict = PyDict_New();
    PyDict_SetItem( pChannelDict, PyString_FromString( GP_CHANNEL_IDX_STR ), pNodeDict );
    Py_DECREF( pNodeDict );
    
    return pChannelDict;
}

//------------------------------------------------------------------------------
// Sets the joint angles of a number of the motor controllers on the CAN bus.
// Joint angles are passed in a list of tuples of the form
//      ( channelIdx, nodeIdx, position )
static PyObject* setJointAngles( PyObject* pSelf, PyObject* args )
{
    PyObject* pList = NULL;
    if ( !PyArg_ParseTuple( args, "O", &pList )
        || !PyList_Check( pList ) )
    {
        PyErr_SetString( PyExc_Exception, "Invalid arguments" );
        return NULL;
    }
    
    Py_ssize_t listLength = PyList_Size( pList );
    for ( Py_ssize_t listIdx = 0; listIdx < listLength; listIdx++ )
    {
        PyObject* pInputTuple = PyList_GetItem( pList, listIdx );
        if ( !PyTuple_Check( pInputTuple ) 
            || PyTuple_Size( pInputTuple ) < 3 )
        {
            PyErr_SetString( PyExc_Exception, "Found list item which isn't a tuple with 3 items" );
            return NULL;
        }
        
        S32 channelIdx;
        S32 nodeId;
        S32 angle;
        
        bool bDataInvalid = false;
        channelIdx = PyInt_AsLong( PyTuple_GetItem( pInputTuple, 0 ) );
        bDataInvalid = ( bDataInvalid || ( -1 == channelIdx && PyErr_Occurred() ) );
        nodeId = PyInt_AsLong( PyTuple_GetItem( pInputTuple, 1 ) );
        bDataInvalid = ( bDataInvalid || ( -1 == nodeId && PyErr_Occurred() ) );
        angle = PyInt_AsLong( PyTuple_GetItem( pInputTuple, 2 ) );
        bDataInvalid = ( bDataInvalid || ( -1 == angle && PyErr_Occurred() ) );
        
        if ( bDataInvalid )
        {
            PyErr_SetString( PyExc_Exception, "Invalid data in tuple" );
            return NULL;
        }
        
        if ( GP_CHANNEL_IDX == channelIdx )
        {
            gpChannel->SetMotorAngle( (U8)nodeId, angle );
        }
    }
    
    Py_RETURN_NONE;
}

//------------------------------------------------------------------------------
// Sets the speed in encoder ticks per second at which the motors move
static PyObject* setMotorProfileVelocity( PyObject* pSelf, PyObject* args )
{    
    S32 profileVelocity;
    if ( !PyArg_ParseTuple( args, "i", &profileVelocity ) )
    {
        PyErr_SetString( PyExc_Exception, "Invalid arguments" );
        return NULL;
    }
    
    gpChannel->SetMotorProfileVelocity( (U32)profileVelocity );
    
    Py_RETURN_NONE;
}

//------------------------------------------------------------------------------
// Tries to bring a halted EPOS node back to life
static PyObject* sendFaultReset( PyObject* pSelf, PyObject* args )
{
    S32 channelIdx;
    S32 nodeId;
    if ( !PyArg_ParseTuple( args, "ii", &channelIdx, &nodeId ) )
    {
        PyErr_SetString( PyExc_Exception, "Invalid arguments" );
        return NULL;
    }
    
    if ( GP_CHANNEL_IDX == channelIdx )
    {
        gpChannel->SendFaultReset( (U8)nodeId );
    }
    
    Py_RETURN_NONE;
}

//------------------------------------------------------------------------------
// Updates a given channel
static PyObject* updateChannel( PyObject* pSelf, PyObject* args )
{
    S32 channelIdx;
    if ( !PyArg_ParseTuple( args, "i", &channelIdx ) )
    {
        PyErr_SetString( PyExc_Exception, "Invalid arguments" );
        return NULL;
    }
    
    if ( GP_CHANNEL_IDX == channelIdx )
    {
        gpChannel->Update();
    }
    
    Py_RETURN_NONE;
}

//------------------------------------------------------------------------------
static void EPOSControlObject_dealloc( EPOSControlObject* self )
{
    // Shut down the EPOSControl library
    EPOS_CloseCANChannel( gpChannel );
    EPOS_DeinitLibrary();
    
    self->ob_type->tp_free((PyObject*)self);
}

//------------------------------------------------------------------------------
static PyObject* EPOSControlObject_new( PyTypeObject *type, 
                                         PyObject *args, PyObject *kwds )
{
    EPOSControlObject *self = (EPOSControlObject *)type->tp_alloc(type, 0);
    return (PyObject *)self;
}

//------------------------------------------------------------------------------
static int EPOSControlObject_init( EPOSControlObject *self, 
                                   PyObject *args, PyObject *kwds )
{
    // Setup 'constants'
    self->MCS_INACTIVE = CANMotorController::eS_Inactive;
    self->MCS_SETTING_UP = CANMotorController::eS_SettingUp;
    self->MCS_RUNNING = CANMotorController::eS_Running;
    self->MCS_HOMING = CANMotorController::eS_Homing;
    
    // Hacky check
    if ( NULL != gpChannel )
    {
        fprintf( stderr, "Error: Channel already in use\n" );
        return -1;
    }
    
    // Start up the EPOSControl library
    if ( !EPOS_InitLibaray() )
    {
        fprintf( stderr, "Error: Unable to open EPOSControl library\n" );
        return -1;
    }
    
    gpChannel = EPOS_OpenCANChannel( "32", eBR_1M );
    if ( NULL == gpChannel )
    {
        fprintf( stderr, "Error: Unable top open CAN bus channel\n" );
        return -1;
    }
    
    gpChannel->ConfigureAllMotorControllersForPositionControl();
    
    return 0;
}

//------------------------------------------------------------------------------
static PyMethodDef EPOSControlObjectMethods[] = 
{
    { "getMotorControllerData", getMotorControllerData, METH_VARARGS, "Get data about the motor controllers" },
    { "setJointAngles", setJointAngles, METH_VARARGS, "Set one or more motor controller joint angles" },
    { "setMotorProfileVelocity", setMotorProfileVelocity, METH_VARARGS, "Sets the speed in encoder ticks per second at which the motors move" },
    { "sendFaultReset", sendFaultReset, METH_VARARGS, "Tries to reset a halted EPOS node" },
    { "updateChannel", updateChannel, METH_VARARGS, "Updates a given channel" },
    {NULL}  /* Sentinel */
};

//------------------------------------------------------------------------------
static PyMemberDef EPOSControlObjectMembers[] = 
{
    { (char*)"MCS_INACTIVE", T_INT, offsetof(EPOSControlObject, MCS_INACTIVE), 0, (char*)"'Inactive' Motor Controller state"},
    { (char*)"MCS_SETTING_UP", T_INT, offsetof(EPOSControlObject, MCS_SETTING_UP), 0, (char*)"'Setting Up' Motor Controller state"},
    { (char*)"MCS_RUNNING", T_INT, offsetof(EPOSControlObject, MCS_RUNNING), 0, (char*)"'Running' Motor Controller state"},
    { (char*)"MCS_HOMING", T_INT, offsetof(EPOSControlObject, MCS_HOMING), 0, (char*)"'Homing' Motor Controller state"},

    {NULL}  /* Sentinel */
};

//------------------------------------------------------------------------------
static PyTypeObject EPOSControlObjectType = 
{
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "PyEPOSControl.EPOSControl",             /*tp_name*/
    sizeof(EPOSControlObject), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)EPOSControlObject_dealloc, /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    "Object to manage the lifetime of communication with the EPOS motor controllers",          /* tp_doc */
    0,                     /* tp_traverse */
    0,                     /* tp_clear */
    0,                     /* tp_richcompare */
    0,                     /* tp_weaklistoffset */
    0,                     /* tp_iter */
    0,                     /* tp_iternext */
    EPOSControlObjectMethods,             /* tp_methods */
    EPOSControlObjectMembers,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)EPOSControlObject_init,      /* tp_init */
    0,                         /* tp_alloc */
    EPOSControlObject_new,                 /* tp_new */
};

//------------------------------------------------------------------------------
static PyMethodDef PyEPOSControlMethods[] = 
{
    { NULL, NULL, 0, NULL }     // Sentinel - marks the end of this structure
};

//------------------------------------------------------------------------------
PyMODINIT_FUNC initPyEPOSControl()  
{
    if ( PyType_Ready( &EPOSControlObjectType ) < 0 )
    {
        return;
    }
    
    PyObject * pModule = Py_InitModule( "PyEPOSControl", PyEPOSControlMethods );
    
    
    Py_INCREF( &EPOSControlObjectType );
    PyModule_AddObject( pModule, "EPOSControl", (PyObject *)&EPOSControlObjectType );
}


