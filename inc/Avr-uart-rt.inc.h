#define __UDRn(n) UDR##n
#define _UDRn(n) __UDRn(n)
#define UDRn _UDRn(UART_PORT_NUM)

#define __UCSRnA(n) UCSR##n##A
#define _UCSRnA(n) __UCSRnA(n)
#define UCSRnA _UCSRnA(UART_PORT_NUM)

#define __UCSRnB(n) UCSR##n##B
#define _UCSRnB(n) __UCSRnB(n)
#define UCSRnB _UCSRnB(UART_PORT_NUM)

#define __UCSRnC(n) UCSR##n##C
#define _UCSRnC(n) __UCSRnC(n)
#define UCSRnC _UCSRnC(UART_PORT_NUM)

#define __UBRRnL(n) UBRR##n##L
#define _UBRRnL(n) __UBRRnL(n)
#define UBRRnL _UBRRnL(UART_PORT_NUM)

#define __UBRRnH(n) UBRR##n##H
#define _UBRRnH(n) __UBRRnH(n)
#define UBRRnH _UBRRnH(UART_PORT_NUM)

#define __UBRRn(n) UBRR##n
#define _UBRRn(n) __UBRRn(n)
#define UBRRn _UBRRn(UART_PORT_NUM)

#define __UMSELn1(n) UMSEL##n##1
#define _UMSELn1(n) __UMSELn1(n)
#define UMSELn1 _UMSELn1(UART_PORT_NUM)

#define __UMSELn0(n) UMSEL##n##0
#define _UMSELn0(n) __UMSELn0(n)
#define UMSELn0 _UMSELn0(UART_PORT_NUM)

#define __UPMn1(n) UPM##n##1
#define _UPMn1(n) __UPMn1(n)
#define UPMn1 _UPMn1(UART_PORT_NUM)

#define __UPMn0(n) UPM##n##0
#define _UPMn0(n) __UPMn0(n)
#define UPMn0 _UPMn0(UART_PORT_NUM)

#define __USBSn(n) USBS##n
#define _USBSn(n) __USBSn(n)
#define USBSn _USBSn(UART_PORT_NUM)

#define __UCSZn1(n) UCSZ##n##1
#define _UCSZn1(n) __UCSZn1(n)
#define UCSZn1 _UCSZn1(UART_PORT_NUM)

#define __UCSZn0(n) UCSZ##n##0
#define _UCSZn0(n) __UCSZn0(n)
#define UCSZn0 _UCSZn0(UART_PORT_NUM)

#define __UCPOLn(n) UCPOL##n
#define _UCPOLn(n) __UCPOLn(n)
#define UCPOLn _UCPOLn(UART_PORT_NUM)

#define __UDORDn(n) UDORD##n
#define _UDORDn(n) __UDORDn(n)
#define UDORDn _UDORDn(UART_PORT_NUM)

#define __UCPHAn(n) UCPHA##n
#define _UCPHAn(n) __UCPHAn(n)
#define UCPHAn _UCPHAn(UART_PORT_NUM)

#define __RXCIEn(n) RXCIE##n
#define _RXCIEn(n) __RXCIEn(n)
#define RXCIEn _RXCIEn(UART_PORT_NUM)

#define __TXCIEn(n) TXCIE##n
#define _TXCIEn(n) __TXCIEn(n)
#define TXCIEn _TXCIEn(UART_PORT_NUM)

#define __UDRIEn(n) UDRIE##n
#define _UDRIEn(n) __UDRIEn(n)
#define UDRIEn _UDRIEn(UART_PORT_NUM)

#define __RXENn(n) RXEN##n
#define _RXENn(n) __RXENn(n)
#define RXENn _RXENn(UART_PORT_NUM)

#define __TXENn(n) TXEN##n
#define _TXENn(n) __TXENn(n)
#define TXENn _TXENn(UART_PORT_NUM)

#define __UCSZn2(n) UCSZ##n##2
#define _UCSZn2(n) __UCSZn2(n)
#define UCSZn2 _UCSZn2(UART_PORT_NUM)

#define __RXB8n(n) RXB8##n
#define _RXB8n(n) __RXB8n(n)
#define RXB8n _RXB8n(UART_PORT_NUM)

#define __TXB8n(n) TXB8##n
#define _TXB8n(n) __TXB8n(n)
#define TXB8n _TXB8n(UART_PORT_NUM)

#define __RXCn(n) RXC##n
#define _RXCn(n) __RXCn(n)
#define RXCn _RXCn(UART_PORT_NUM)

#define __TXCn(n) TXC##n
#define _TXCn(n) __TXCn(n)
#define TXCn _TXCn(UART_PORT_NUM)

#define __UDREn(n) UDRE##n
#define _UDREn(n) __UDREn(n)
#define UDREn _UDREn(UART_PORT_NUM)

#define __FEn(n) FE##n
#define _FEn(n) __FEn(n)
#define FEn _FEn(UART_PORT_NUM)

#define __DORn(n) DOR##n
#define _DORn(n) __DORn(n)
#define DORn _DORn(UART_PORT_NUM)

#define __UPEn(n) UPE##n
#define _UPEn(n) __UPEn(n)
#define UPEn _UPEn(UART_PORT_NUM)

#define __U2Xn(n) U2X##n
#define _U2Xn(n) __U2Xn(n)
#define U2Xn _U2Xn(UART_PORT_NUM)

#define __MPCMn(n) MPCM##n
#define _MPCMn(n) __MPCMn(n)
#define MPCMn _MPCMn(UART_PORT_NUM)

#define __USARTn_RX_vect(n) USART##n##_RX_vect
#define _USARTn_RX_vect(n) __USARTn_RX_vect(n)
#define USARTn_RX_vect _USARTn_RX_vect(UART_PORT_NUM)

#define __USARTn_UDRE_vect(n) USART##n##_UDRE_vect
#define _USARTn_UDRE_vect(n) __USARTn_UDRE_vect(n)
#define USARTn_UDRE_vect _USARTn_UDRE_vect(UART_PORT_NUM)

#define __USARTn_TX_vect(n) USART##n##_TX_vect
#define _USARTn_TX_vect(n) __USARTn_TX_vect(n)
#define USARTn_TX_vect _USARTn_TX_vect(UART_PORT_NUM)




/*
UDRn 
UCSRnA
UCSRnB
UCSRnC
UBRRnL
UBRRnH
UBRRn
UMSELn1 
UMSELn0	
UPMn1	
UPMn0 	
USBSn 	
UCSZn1 	
UCSZn0 	
UCPOLn 	
UDORDn 	
UCPHAn 	
RXCIEn 
TXCIEn 	
UDRIEn	
RXENn 	
TXENn 	
UCSZn2	
RXB8n	
TXB8n 	
RXCn 
TXCn	
UDREn	
FEn 	
DORn 	


UPEn 		
U2Xn 		
MPCMn 		
USARTn_RX_vect    
USARTn_UDRE_vect  
USARTn_TX_vect  
*/
