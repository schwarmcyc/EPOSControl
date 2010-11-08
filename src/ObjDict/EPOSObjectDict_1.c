
/* File generated by gen_cfile.py. Should not be modified. */

#include "EPOSObjectDict_1.h"

/**************************************************************************/
/* Declaration of mapped variables                                        */
/**************************************************************************/
static UNS16 Node1Data_Statusword = 0x0;		/* Mapped at index 0x2000, subindex 0x01 */
static INTEGER32 Node1Data_Actual_Position = 0x0;		/* Mapped at index 0x2000, subindex 0x02 */

/**************************************************************************/
/* Declaration of value range types                                       */
/**************************************************************************/

#define valueRange_EMC 0x9F /* Type for index 0x1003 subindex 0x00 (only set of value 0 is possible) */
UNS32 EPOSObjectDict_1_valueRangeTest (UNS8 typeValue, void * value)
{
  switch (typeValue) {
    case valueRange_EMC:
      if (*(UNS8*)value != (UNS8)0) return OD_VALUE_RANGE_EXCEEDED;
      break;
  }
  return 0;
}

/**************************************************************************/
/* The node id                                                            */
/**************************************************************************/
/* node_id default value.*/
UNS8 EPOSObjectDict_1_bDeviceNodeId = 0x00;

/**************************************************************************/
/* Array of message processing information */

const UNS8 EPOSObjectDict_1_iam_a_slave = 0;

TIMER_HANDLE EPOSObjectDict_1_heartBeatTimers[1];

/*
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

                               OBJECT DICTIONARY

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/

/* index 0x1000 :   Device Type. */
                    UNS32 EPOSObjectDict_1_obj1000 = 0x0;	/* 0 */
                    subindex EPOSObjectDict_1_Index1000[] = 
                     {
                       { RO, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1000 }
                     };

/* index 0x1001 :   Error Register. */
                    UNS8 EPOSObjectDict_1_obj1001 = 0x0;	/* 0 */
                    subindex EPOSObjectDict_1_Index1001[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1001 }
                     };

/* index 0x1003 :   Pre-defined Error Field */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1003 = 0; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1003[] = 
                    {
                      0x0	/* 0 */
                    };
                    ODCallback_t EPOSObjectDict_1_Index1003_callbacks[] = 
                     {
                       NULL,
                       NULL,
                     };
                    subindex EPOSObjectDict_1_Index1003[] = 
                     {
                       { RW, valueRange_EMC, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1003 },
                       { RO, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1003[0] }
                     };

/* index 0x1005 :   SYNC COB ID */
                    UNS32 EPOSObjectDict_1_obj1005 = 0x0;   /* 0 */

/* index 0x1006 :   Communication / Cycle Period */
                    UNS32 EPOSObjectDict_1_obj1006 = 0x0;   /* 0 */

/* index 0x1014 :   Emergency COB ID */
                    UNS32 EPOSObjectDict_1_obj1014 = 0x80 + 0x00;   /* 128 + NodeID */

/* index 0x1016 :   Consumer Heartbeat Time */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1016 = 0;
                    UNS32 EPOSObjectDict_1_obj1016[]={0};

/* index 0x1017 :   Producer Heartbeat Time */ 
                    UNS16 EPOSObjectDict_1_obj1017 = 0x0;   /* 0 */

/* index 0x1018 :   Identity. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1018 = 4; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1018_Vendor_ID = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1018_Product_Code = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1018_Revision_Number = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1018_Serial_Number = 0x0;	/* 0 */
                    subindex EPOSObjectDict_1_Index1018[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1018 },
                       { RO, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1018_Vendor_ID },
                       { RO, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1018_Product_Code },
                       { RO, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1018_Revision_Number },
                       { RO, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1018_Serial_Number }
                     };

/* index 0x1280 :   Client SDO 1 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1280 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1280_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1280_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1280_Node_ID_of_the_SDO_Server = 0x1;	/* 1 */
                    subindex EPOSObjectDict_1_Index1280[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1280 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1280_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1280_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1280_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1281 :   Client SDO 2 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1281 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1281_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1281_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1281_Node_ID_of_the_SDO_Server = 0x2;	/* 2 */
                    subindex EPOSObjectDict_1_Index1281[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1281 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1281_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1281_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1281_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1282 :   Client SDO 3 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1282 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1282_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1282_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1282_Node_ID_of_the_SDO_Server = 0x3;	/* 3 */
                    subindex EPOSObjectDict_1_Index1282[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1282 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1282_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1282_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1282_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1283 :   Client SDO 4 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1283 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1283_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1283_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1283_Node_ID_of_the_SDO_Server = 0x4;	/* 4 */
                    subindex EPOSObjectDict_1_Index1283[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1283 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1283_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1283_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1283_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1284 :   Client SDO 5 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1284 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1284_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1284_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1284_Node_ID_of_the_SDO_Server = 0x5;	/* 5 */
                    subindex EPOSObjectDict_1_Index1284[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1284 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1284_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1284_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1284_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1285 :   Client SDO 6 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1285 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1285_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1285_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1285_Node_ID_of_the_SDO_Server = 0x6;	/* 6 */
                    subindex EPOSObjectDict_1_Index1285[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1285 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1285_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1285_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1285_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1286 :   Client SDO 7 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1286 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1286_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1286_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1286_Node_ID_of_the_SDO_Server = 0x7;	/* 7 */
                    subindex EPOSObjectDict_1_Index1286[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1286 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1286_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1286_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1286_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1287 :   Client SDO 8 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1287 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1287_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1287_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1287_Node_ID_of_the_SDO_Server = 0x8;	/* 8 */
                    subindex EPOSObjectDict_1_Index1287[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1287 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1287_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1287_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1287_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1288 :   Client SDO 9 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1288 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1288_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1288_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1288_Node_ID_of_the_SDO_Server = 0x9;	/* 9 */
                    subindex EPOSObjectDict_1_Index1288[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1288 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1288_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1288_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1288_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1289 :   Client SDO 10 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1289 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1289_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1289_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1289_Node_ID_of_the_SDO_Server = 0xA;	/* 10 */
                    subindex EPOSObjectDict_1_Index1289[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1289 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1289_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1289_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1289_Node_ID_of_the_SDO_Server }
                     };

/* index 0x128A :   Client SDO 11 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj128A = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj128A_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj128A_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj128A_Node_ID_of_the_SDO_Server = 0xB;	/* 11 */
                    subindex EPOSObjectDict_1_Index128A[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj128A },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128A_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128A_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj128A_Node_ID_of_the_SDO_Server }
                     };

/* index 0x128B :   Client SDO 12 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj128B = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj128B_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj128B_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj128B_Node_ID_of_the_SDO_Server = 0xC;	/* 12 */
                    subindex EPOSObjectDict_1_Index128B[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj128B },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128B_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128B_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj128B_Node_ID_of_the_SDO_Server }
                     };

/* index 0x128C :   Client SDO 13 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj128C = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj128C_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj128C_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj128C_Node_ID_of_the_SDO_Server = 0xD;	/* 13 */
                    subindex EPOSObjectDict_1_Index128C[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj128C },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128C_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128C_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj128C_Node_ID_of_the_SDO_Server }
                     };

/* index 0x128D :   Client SDO 14 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj128D = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj128D_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj128D_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj128D_Node_ID_of_the_SDO_Server = 0xE;	/* 14 */
                    subindex EPOSObjectDict_1_Index128D[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj128D },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128D_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128D_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj128D_Node_ID_of_the_SDO_Server }
                     };

/* index 0x128E :   Client SDO 15 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj128E = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj128E_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj128E_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj128E_Node_ID_of_the_SDO_Server = 0xF;	/* 15 */
                    subindex EPOSObjectDict_1_Index128E[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj128E },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128E_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128E_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj128E_Node_ID_of_the_SDO_Server }
                     };

/* index 0x128F :   Client SDO 16 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj128F = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj128F_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj128F_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj128F_Node_ID_of_the_SDO_Server = 0x10;	/* 16 */
                    subindex EPOSObjectDict_1_Index128F[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj128F },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128F_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj128F_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj128F_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1290 :   Client SDO 17 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1290 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1290_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1290_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1290_Node_ID_of_the_SDO_Server = 0x11;	/* 17 */
                    subindex EPOSObjectDict_1_Index1290[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1290 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1290_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1290_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1290_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1291 :   Client SDO 18 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1291 = 3; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1291_COB_ID_Client_to_Server_Transmit_SDO = 0x0;	/* 0 */
                    UNS32 EPOSObjectDict_1_obj1291_COB_ID_Server_to_Client_Receive_SDO = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1291_Node_ID_of_the_SDO_Server = 0x12;	/* 18 */
                    subindex EPOSObjectDict_1_Index1291[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1291 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1291_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1291_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1291_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1400 :   Receive PDO 1 Parameter. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1400 = 5; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1400_COB_ID_used_by_PDO = 0x200;	/* 512 */
                    UNS8 EPOSObjectDict_1_obj1400_Transmission_Type = 0x0;	/* 0 */
                    UNS16 EPOSObjectDict_1_obj1400_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 EPOSObjectDict_1_obj1400_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 EPOSObjectDict_1_obj1400_Event_Timer = 0x0;	/* 0 */
                    subindex EPOSObjectDict_1_Index1400[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1400 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1400_COB_ID_used_by_PDO },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1400_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&EPOSObjectDict_1_obj1400_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_obj1400_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&EPOSObjectDict_1_obj1400_Event_Timer }
                     };

/* index 0x1600 :   Receive PDO 1 Mapping. */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj1600 = 8; /* number of subindex - 1*/
                    UNS32 EPOSObjectDict_1_obj1600[] = 
                    {
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0	/* 0 */
                    };
                    subindex EPOSObjectDict_1_Index1600[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj1600 },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1600[0] },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1600[1] },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1600[2] },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1600[3] },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1600[4] },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1600[5] },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1600[6] },
                       { RW, uint32, sizeof (UNS32), (void*)&EPOSObjectDict_1_obj1600[7] }
                     };

/* index 0x2000 :   Mapped variable Node1Data */
                    UNS8 EPOSObjectDict_1_highestSubIndex_obj2000 = 2; /* number of subindex - 1*/
                    subindex EPOSObjectDict_1_Index2000[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&EPOSObjectDict_1_highestSubIndex_obj2000 },
                       { RW, uint16, sizeof (UNS16), (void*)&Node1Data_Statusword },
                       { RW, int32, sizeof (INTEGER32), (void*)&Node1Data_Actual_Position }
                     };

/**************************************************************************/
/* Declaration of pointed variables                                       */
/**************************************************************************/

const indextable EPOSObjectDict_1_objdict[] = 
{
  { (subindex*)EPOSObjectDict_1_Index1000,sizeof(EPOSObjectDict_1_Index1000)/sizeof(EPOSObjectDict_1_Index1000[0]), 0x1000},
  { (subindex*)EPOSObjectDict_1_Index1001,sizeof(EPOSObjectDict_1_Index1001)/sizeof(EPOSObjectDict_1_Index1001[0]), 0x1001},
  { (subindex*)EPOSObjectDict_1_Index1018,sizeof(EPOSObjectDict_1_Index1018)/sizeof(EPOSObjectDict_1_Index1018[0]), 0x1018},
  { (subindex*)EPOSObjectDict_1_Index1280,sizeof(EPOSObjectDict_1_Index1280)/sizeof(EPOSObjectDict_1_Index1280[0]), 0x1280},
  { (subindex*)EPOSObjectDict_1_Index1281,sizeof(EPOSObjectDict_1_Index1281)/sizeof(EPOSObjectDict_1_Index1281[0]), 0x1281},
  { (subindex*)EPOSObjectDict_1_Index1282,sizeof(EPOSObjectDict_1_Index1282)/sizeof(EPOSObjectDict_1_Index1282[0]), 0x1282},
  { (subindex*)EPOSObjectDict_1_Index1283,sizeof(EPOSObjectDict_1_Index1283)/sizeof(EPOSObjectDict_1_Index1283[0]), 0x1283},
  { (subindex*)EPOSObjectDict_1_Index1284,sizeof(EPOSObjectDict_1_Index1284)/sizeof(EPOSObjectDict_1_Index1284[0]), 0x1284},
  { (subindex*)EPOSObjectDict_1_Index1285,sizeof(EPOSObjectDict_1_Index1285)/sizeof(EPOSObjectDict_1_Index1285[0]), 0x1285},
  { (subindex*)EPOSObjectDict_1_Index1286,sizeof(EPOSObjectDict_1_Index1286)/sizeof(EPOSObjectDict_1_Index1286[0]), 0x1286},
  { (subindex*)EPOSObjectDict_1_Index1287,sizeof(EPOSObjectDict_1_Index1287)/sizeof(EPOSObjectDict_1_Index1287[0]), 0x1287},
  { (subindex*)EPOSObjectDict_1_Index1288,sizeof(EPOSObjectDict_1_Index1288)/sizeof(EPOSObjectDict_1_Index1288[0]), 0x1288},
  { (subindex*)EPOSObjectDict_1_Index1289,sizeof(EPOSObjectDict_1_Index1289)/sizeof(EPOSObjectDict_1_Index1289[0]), 0x1289},
  { (subindex*)EPOSObjectDict_1_Index128A,sizeof(EPOSObjectDict_1_Index128A)/sizeof(EPOSObjectDict_1_Index128A[0]), 0x128A},
  { (subindex*)EPOSObjectDict_1_Index128B,sizeof(EPOSObjectDict_1_Index128B)/sizeof(EPOSObjectDict_1_Index128B[0]), 0x128B},
  { (subindex*)EPOSObjectDict_1_Index128C,sizeof(EPOSObjectDict_1_Index128C)/sizeof(EPOSObjectDict_1_Index128C[0]), 0x128C},
  { (subindex*)EPOSObjectDict_1_Index128D,sizeof(EPOSObjectDict_1_Index128D)/sizeof(EPOSObjectDict_1_Index128D[0]), 0x128D},
  { (subindex*)EPOSObjectDict_1_Index128E,sizeof(EPOSObjectDict_1_Index128E)/sizeof(EPOSObjectDict_1_Index128E[0]), 0x128E},
  { (subindex*)EPOSObjectDict_1_Index128F,sizeof(EPOSObjectDict_1_Index128F)/sizeof(EPOSObjectDict_1_Index128F[0]), 0x128F},
  { (subindex*)EPOSObjectDict_1_Index1290,sizeof(EPOSObjectDict_1_Index1290)/sizeof(EPOSObjectDict_1_Index1290[0]), 0x1290},
  { (subindex*)EPOSObjectDict_1_Index1291,sizeof(EPOSObjectDict_1_Index1291)/sizeof(EPOSObjectDict_1_Index1291[0]), 0x1291},
  { (subindex*)EPOSObjectDict_1_Index1400,sizeof(EPOSObjectDict_1_Index1400)/sizeof(EPOSObjectDict_1_Index1400[0]), 0x1400},
  { (subindex*)EPOSObjectDict_1_Index1600,sizeof(EPOSObjectDict_1_Index1600)/sizeof(EPOSObjectDict_1_Index1600[0]), 0x1600},
  { (subindex*)EPOSObjectDict_1_Index2000,sizeof(EPOSObjectDict_1_Index2000)/sizeof(EPOSObjectDict_1_Index2000[0]), 0x2000},
};

const indextable * EPOSObjectDict_1_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks)
{
	int i;
	*callbacks = NULL;
	switch(wIndex){
		case 0x1000: i = 0;break;
		case 0x1001: i = 1;break;
		case 0x1018: i = 2;break;
		case 0x1280: i = 3;break;
		case 0x1281: i = 4;break;
		case 0x1282: i = 5;break;
		case 0x1283: i = 6;break;
		case 0x1284: i = 7;break;
		case 0x1285: i = 8;break;
		case 0x1286: i = 9;break;
		case 0x1287: i = 10;break;
		case 0x1288: i = 11;break;
		case 0x1289: i = 12;break;
		case 0x128A: i = 13;break;
		case 0x128B: i = 14;break;
		case 0x128C: i = 15;break;
		case 0x128D: i = 16;break;
		case 0x128E: i = 17;break;
		case 0x128F: i = 18;break;
		case 0x1290: i = 19;break;
		case 0x1291: i = 20;break;
		case 0x1400: i = 21;break;
		case 0x1600: i = 22;break;
		case 0x2000: i = 23;break;
		default:
			*errorCode = OD_NO_SUCH_OBJECT;
			return NULL;
	}
	*errorCode = OD_SUCCESSFUL;
	return &EPOSObjectDict_1_objdict[i];
}

/* 
 * To count at which received SYNC a PDO must be sent.
 * Even if no pdoTransmit are defined, at least one entry is computed
 * for compilations issues.
 */
s_PDO_status EPOSObjectDict_1_PDO_status[1] = {s_PDO_status_Initializer};

const quick_index EPOSObjectDict_1_firstIndex = {
  0, /* SDO_SVR */
  3, /* SDO_CLT */
  21, /* PDO_RCV */
  22, /* PDO_RCV_MAP */
  0, /* PDO_TRS */
  0 /* PDO_TRS_MAP */
};

const quick_index EPOSObjectDict_1_lastIndex = {
  0, /* SDO_SVR */
  20, /* SDO_CLT */
  21, /* PDO_RCV */
  22, /* PDO_RCV_MAP */
  0, /* PDO_TRS */
  0 /* PDO_TRS_MAP */
};

const UNS16 EPOSObjectDict_1_ObjdictSize = sizeof(EPOSObjectDict_1_objdict)/sizeof(EPOSObjectDict_1_objdict[0]); 

CO_Data EPOSObjectDict_1_Data = CANOPEN_NODE_DATA_INITIALIZER(EPOSObjectDict_1);
