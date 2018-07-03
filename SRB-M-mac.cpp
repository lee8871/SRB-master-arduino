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
  UCSRnB set bit(RXCIEn)|bit(TXCIEn)|bit(RXENn)|bit(TXENn)|bit(UCSZn2);
  UCSRnC = bit(USBSn)|bit(UCSZn1)|bit(UCSZn0);
  UBRRn = UBRRDATA;
}





///////////////////////////////     PHY     ////////////////////////////////////////

sMacPkg Recv_pkg, Send_pkg;

static uint8* const recv_pkg_u8 = (uint8*)(&Recv_pkg);
static const uint8* const send_pkg_u8 = (uint8*)(&Send_pkg);

uint8 SendAddr = 0x00;
volatile uint8 Bus_state = BS_IDLE;

static uint8 recv_conter = 0xff;
static uint8 recv_length = 0;
static uint8 recv_crc = 0;

static uint8 send_conter = 0xff;
static uint8 send_length = 0;
static uint8 send_crc = 0;

uint8 mstBeginSend(){
	if(send_conter!=0xff){
		green.tog();
		return 1;
	}
	
	sendMode.on();
	
	Bus_state = BS_SENDING;
	red.on();
	crcInput(send_crc,SendAddr);
	send_length = Send_pkg.bfc.length;
	send_length = send_length + 2 - 1;
	send_conter = 0;	
	
	
	UCSRnB set bit(TXB8n);
	UDRn = SendAddr;	

	UCSRnB clr bit(TXB8n);
	return 0;
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


ISR(USART1_RX_vect){
	uint8 b = UDRn;
	if(Bus_state == BS_SEND_DONE)
	{	
		Bus_state = BS_RECVING;
		sBfc bfc;
		bfc.byte = b;
		recv_length	= bfc.length+2;	
	}		
	recv_pkg_u8[recv_conter] = b;
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

