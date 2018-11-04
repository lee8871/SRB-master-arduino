#define __ARDUINO__

#include <lee.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <Led.h>
#include <CRC8.h>



#include "readonly/SRB-share-const.h"
#include "SRB-M-mac.h"



#define PORTx PORTD
#define DDRx DDRD
#define bit_ bit1
#define instance_name noReadMode
#include "inc/led-cpp.ih.h"

#define PORTx PORTD
#define DDRx DDRD
#define bit_ bit0
#define instance_name sendMode
#include "inc/led-cpp.ih.h"


static inline void uartInit9b();

#define UART_PORT_NUM 1
#include "inc/Avr-uart-rt.inc.h"
#define UBRRDATA UBRRDATA485

void srbPhyInit()
{
  uartInit9b();
  sendMode.init();
  noReadMode.init();
}

static inline void uartInit9b(){
  UCSRnA set bit(U2Xn);
  UCSRnB set bit(RXENn)|bit(TXENn)|bit(UCSZn2);
  UCSRnC = bit(UCSZn1)|bit(UCSZn0);
  UBRRn = UBRRDATA;
  PORTD set bit(2);
}





//********************* phy ************************************

sMacPkg Recv_pkg, Send_pkg;//send_pkg is not in used


static uint8* const recv_pkg_u8 = (uint8*)(&Recv_pkg);
static const uint8* const send_pkg_u8 = (uint8*)(&Send_pkg);



static uint8 send_crc;

void masterSendAddr(uint8 addr){
	sendMode.on();
	noReadMode.on();
	red.on();
	UCSRnB set bit(TXB8n);
	UDRn = addr;
	send_crc = 0;
	crcInput(send_crc,addr);

	return;
}

void masterSendBfc(uint8 bfc){

	while((UCSRnA & bit(UDREn))==0);

	UCSRnB clr bit(TXB8n);
	UDRn = bfc;
	crcInput(send_crc,bfc);

	return;
}

void masterSendData(uint8 data){

	while((UCSRnA & bit(UDREn))==0);

	UDRn = data;
	crcInput(send_crc,data);

	return;
}

void masterSendCrc(){
	while((UCSRnA & bit(UDREn))==0);
	UDRn = send_crc;
	UCSRnA set bit(TXCn);
	return;
}
void masterWaitBfc(){
	while((UCSRnA & bit(TXCn))==0);
	red.off();
	yellow.on();
	sendMode.off();
	noReadMode.off();
}

#define TIMER_OUT (250)
inline uint8 waitRecvDone(){
	uint8 timer=TIMER_OUT;
	while((UCSRnA & bit(RXCn))==0){
		if( --timer == 0){
			return fail;
		}
	}
	return done;
}

uint8 masterRecvPkg(){
	uint8 b;
	uint8 recv_conter = 0;
	uint8 recv_length;
	uint8 recv_crc = 0;

	if(waitRecvDone()==fail){
		return fail;
	}
	b = UDRn;
	sBfc bfc; bfc.byte = b;
	recv_length = bfc.length+2;

	crcInput(recv_crc,b);
	recv_pkg_u8[recv_conter] = b;
	recv_conter++;

	while(recv_conter != recv_length){
		if(waitRecvDone()==fail){
			return fail;
		}
		b = UDRn;
		crcInput(recv_crc,b);
		recv_pkg_u8[recv_conter] = b;
		recv_conter++;
	}
	if(recv_crc == 0){
		yellow.off();
		return done;
	}
	else{
		return fail;
	}

}
