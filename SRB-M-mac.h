#ifndef __SRB_M_MAC_H_
#define __SRB_M_MAC_H_

#include "readonly/SRB-share-const.h"

#define BS_FINISH		20
#define BS_RECV_ACCEPT	10
#define BS_IDLE  		0
#define BS_SENDING		1
#define BS_SEND_DONE	(2+BS_RECV_ACCEPT)
#define BS_RECVING		(3+BS_RECV_ACCEPT)
#define BS_DONE			4
#define BS_LOSE 		5
#define BS_SEND_TIMEOUT 6
#define BS_RECV_TIMEOUT 7


extern uint8 SendAddr;
extern volatile uint8 Bus_state;
extern sMacPkg Recv_pkg, Send_pkg;


uint8 mstBeginSend();
void srbPhyInit();

#endif /* __SRB_M_MAC_H_ */
