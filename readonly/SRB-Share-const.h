/*
The share const for SRB,
server and master and may C# function use it
*/
#ifndef __SRB_SHARE_CONST_H_
#define __SRB_SHARE_CONST_H_

#define SC_DEFAULT_ADDR 0x00
#define SC_SHUTUP_ADDR 0xee
#define SC_GLOBAL_SYNC 0xf0

#define SC_GLOBAL_SYNC_A 0xf1
#define SC_GLOBAL_SYNC_B 0x8e

#define SC_GLOBAL_RST_A 0xf7
#define SC_GLOBAL_RST_B 0x88


#define SC_GLOBAL_ESTOP_A 0xfc
#define SC_GLOBAL_ESTOP_B 0x84




#define SC_ESCAPE 0xf5
#define SC_EE 0xf3
#define SC_BROADCAST 0xff

#define SC_PORT_D0 0
#define SC_PORT_D1 1
#define SC_PORT_D2 2
#define SC_PORT_D3 3

#define SC_PORT_CMD 4
#define SC_PORT_CFG 5
#define SC_PORT_RPT 6
#define SC_PORT_RES 7

#define SC_DC_TEST		0x80
#define SC_DC_RESET		0xf0
#define SC_DC_ESTOP		0xf1
#define SC_DC_DESCRIPTOR	0xc0

#define SC_DC_COLOR_CLOSE			0xE0
#define SC_DC_COLOR_ADDR_LOW 		0XE1	
#define SC_DC_COLOR_ADDR_HIGH		0xE2

//define for error report (RE_)
//when receive wrong package or something error
//the value is return
#define SC_RECV_DONE 0
#define SC_RECV_TOO_SHORT 0xfd
#define SC_RECV_LENGTH_ERROR 0xfe
#define SC_RECV_BAD_HEAD 0xf0
#define SC_RECV_BAD_CLUSTER 0xf1
#define SC_NO_CLUSTER 0xf1



#define RE_CFG_NO_CLUSTER_ID 0xe0
#define RE_CFG_EMPTY_CLUSTER 0xe1
#define RE_CFG_LEN_NO_MATCH  0xe2



#define BAUD485 1250000
//#define UBRRDATA485 (F_CPU/(8*BAUD485)-1)
#define UBRRDATA485 0

#define MAX_PKG_DATA_LEN 31
#define MAX_PKG_LEN (MAX_PKG_DATA_LEN + 2)

union sBfc{
	uint8 byte;
	struct	{
		uint8 length:5;
		uint8 port:3;
	};	
	struct	{
		uint8 __no_used:7;
		uint8 is_not_Data:1;
	};
	struct	{
		uint8 length_2:5;
		uint8 event:1;
		uint8 busy:1;
		uint8 error:1;
	};
};
#define bfcGetLen(bfc) (bfc&((1<<5)-1))
#define bfcGetPort(bfc) (b>>5)

struct sMacPkg{
	sBfc bfc;
	//when pkg length = 31, the last in data is CRC
	uint8 data[MAX_PKG_DATA_LEN+1];
};

struct sStaticMapping{
	uint8 up_len;
	uint8 down_len;
	uint8 table[];
};



#endif /* __SRB_SHARE_CONST_H_ */

