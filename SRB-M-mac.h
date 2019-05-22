#ifndef __SRB_M_MAC_H_
#define __SRB_M_MAC_H_

#include "readonly/SRB-share-const.h"
#include <lee.h>

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


extern sMacPkg Recv_pkg, Send_pkg;


void srbPhyInit();


void masterSendAddr(uint8 addr);
void masterSendBfc(uint8 bfc);
void masterSendData(uint8 bfc);
void masterSendCrc();
void masterWaitBfc();
uint8 masterRecvPkg();


#endif /* __SRB_M_MAC_H_ */
