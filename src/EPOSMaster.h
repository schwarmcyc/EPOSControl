
/* File generated by gen_cfile.py. Should not be modified. */

#ifndef EPOSMASTER_H
#define EPOSMASTER_H

#include "data.h"

/* Prototypes of function provided by object dictionnary */
UNS32 EPOSMaster_valueRangeTest (UNS8 typeValue, void * value);
const indextable * EPOSMaster_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks);

/* Master node data struct */
extern CO_Data EPOSMaster_Data;

#endif // EPOSMASTER_H
