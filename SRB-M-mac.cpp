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
}

static inline void uartInit9b(){
  UCSRnA set bit(U2Xn);
  UCSRnB set bit(RXENn)|bit(TXENn)|bit(UCSZn2);
  UCSRnC = bit(UCSZn1)|bit(UCSZn0);
  UBRRn = UBRRDATA;
}





///////////////////////////////     PHY     ////////////////////////////////////////

sMacPkg Recv_pkg, Send_pkg;

static uint8* const recv_pkg_u8 = (uint8*)(&Recv_pkg);
static const uint8* const send_pkg_u8 = (uint8*)(&Send_pkg);



static uint8 send_crc, recv_crc;

void masterSendAddr(uint8 addr){
	sendMode.on();	
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

void masterSendData(uint8 bfc){
	
	while((UCSRnA & bit(UDREn))==0);	
	
	UDRn = bfc;	
	crcInput(send_crc,bfc);
	
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
	recv_crc = 0;
	sendMode.off();
}
#define TIMER_OUT (240/4)
uint8 masterRecvPkg(){
	uint8 b;
	uint8 recv_conter = 0;
	uint8 recv_length;
	uint8 timer=TIMER_OUT;
	while((UCSRnA & bit(RXCn))==0){
		if( --timer == 0)
		{
			return BS_LOSE;
		}		
	}
	b = UDRn;
	sBfc bfc; bfc.byte = b;
	recv_length = bfc.length+2;		
	
	crcInput(recv_crc,b);
	recv_pkg_u8[recv_conter] = b;
	recv_conter++;
	
	while(recv_conter != recv_length){
		
		timer=TIMER_OUT;
		while((UCSRnA & bit(RXCn))==0){
			if( --timer == 0)
			{
				return BS_LOSE;
			}		
		}
		
		b = UDRn;
		crcInput(recv_crc,b);
		recv_pkg_u8[recv_conter] = b;
		recv_conter++;
	}		
	if(recv_crc == 0){
		yellow.off();			
		return BS_DONE;
	}	
	else{
		return BS_LOSE;
	}
	
}
/****************

ISR(USART1_RX_vect){
	uint8 b = UDRn;
	if(Bus_state == BS_SEND_DONE)
	{	
		Bus_state = BS_RECVING;
		sBfc bfc;
		bfc.byte = b;
		recv_length	= bfc.length+2;	
	}		
	crcInput(recv_crc,b);
	recv_conter++;
	if(recv_conter == recv_length){//receive end
		if(recv_crc == 0){
			Bus_state = BS_DONE;
			yellow.off();			
		}	
		else{
			Bus_state = BS_LOSE;
		}
	}
}

ISR(USART1_TX_vect){
	if(send_conter<send_length){
		UDRn = send_pkg_u8[send_conter];
		crcInput(send_crc,send_pkg_u8[send_conter]);
		send_conter++;
	}
	else if(send_conter==send_length){
		UDRn = send_crc;
		send_conter++;
	}
	else{
		sendMode.off();
		red.off();
		yellow.on();
		recv_conter = 0;
		recv_length = 0;
		recv_crc = 0;
		send_conter = 0xff;
		send_length = 0;
		send_crc = 0;
		Bus_state = BS_SEND_DONE;
	}
}

//********************/
