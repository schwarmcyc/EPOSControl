
/* File generated by gen_cfile.py. Should not be modified. */

#ifndef EPOSOBJECTDICT_1_H
#define EPOSOBJECTDICT_1_H

#include "data.h"

/* Prototypes of function provided by object dictionnary */
UNS32 EPOSObjectDict_1_valueRangeTest (UNS8 typeValue, void * value);
const indextable * EPOSObjectDict_1_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks);

/* Master node data struct */
extern CO_Data EPOSObjectDict_1_Data;
//extern UNS16 Node1Data_Statusword;		/* Mapped at index 0x2000, subindex 0x01 */
//extern INTEGER32 Node1Data_Actual_Position;		/* Mapped at index 0x2000, subindex 0x02 */

#endif // EPOSOBJECTDICT_1_H