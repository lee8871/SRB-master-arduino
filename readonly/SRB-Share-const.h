/*
The share const for SRB,
server and master and may C# function use it
*/
#ifndef __SRB_SHARE_CONST_H_
#define __SRB_SHARE_CONST_H_
enum eAddr{
//	SC_DEFAULT_ADDR=  0x00,
	SC_RDM_ADDR_BASE = 100,
	SC_BROADCAST  = 0xff,
};




enum ePort{
	SC_PORT_D0 = 0,
	SC_PORT_D1 = 1,
	SC_PORT_D2 = 2,
	SC_PORT_D3 = 3,
	SC_PORT_CFG = 5,
	SC_PORT_RPT = 6,
};

enum eError{	
	RE_CFG_NO_CLUSTER_ID =0xe0,
	RE_CFG_EMPTY_CLUSTER =0xe1,
	RE_CFG_LEN_NO_MATCH  =0xe2,
};


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

struct sMapping{
	uint8 up_len;
	uint8 down_len;
	uint8 table[];
};



#endif /* __SRB_SHARE_CONST_H_ */

