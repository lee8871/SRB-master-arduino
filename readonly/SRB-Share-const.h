#ifndef __SRB_SHARE_CONST_H_
#define __SRB_SHARE_CONST_H_
#include "lee.h"

namespace srb{
enum eAddr{
//	SC_DEFAULT_ADDR=  0x00,
	SC_RDM_ADDR_BASE = 100,
	SC_BROADCAST  = 0xff,
	SC_SYNC = 239,
	SC_NO_UP_PKG = 228,
};


#define RANDOM_ADDR_MASK 7


enum ePort{
	SC_PORT_D0 = 0,
	SC_PORT_D1 = 1,
	SC_PORT_D2 = 2,
	SC_PORT_D3 = 3,
	SC_PORT_UDP = 4,
	SC_PORT_CFG = 5,
	SC_PORT_RPT = 6,
};

enum eAccess_error{
	RE_CFG_NO_CLUSTER_ID =0xe0,
	RE_CFG_EMPTY_CLUSTER =0xe1,
	RE_CFG_LEN_NO_MATCH  =0xe2,
	RE_CFG_WRITE_ONLY  =0xe3,
};

enum eSystem_error{
	E_NO_ERROR = 0,
};


const uint8 MAX_PKG_DATA_LEN = 31;
const uint8 MAX_PKG_LEN = (MAX_PKG_DATA_LEN + 2);
const uint8 MAX_CLUSTER_LEN = (MAX_PKG_DATA_LEN-1);
union sBfc{
	uint8 byte;
	struct	{
		uint8 length:5;
		uint8 port:3;
	};
	struct	{
		uint8 length_2:5;
		uint8 event:1;
		uint8 busy:1;
		uint8 error:1;
	};
};
inline uint8 bfcGetLen(uint8 bfc){
	return (bfc&((1<<5)-1));
}

inline uint8 getBfc(uint8 length,bool is_error,bool is_busy){
	uint8 e = is_error;
	uint8 b = is_busy;
	return (length|(e<<7)|(b<<6));
}

struct sSrbPkg{
	sBfc bfc;
	//when pkg length = 31, the last in data is CRC
	uint8 data[MAX_PKG_DATA_LEN+1];
};

struct sMapping{
	uint8 up_len;
	uint8 down_len;
	uint8 table[UNDEF_LENGTH];
};


//for USB device
union sUsbToSrbPkg{
	uint8 u8[UNDEF_LENGTH];// not min length
	struct{
		uint8 sno;
		uint8 addr;
		sSrbPkg pkg;
	};
	struct{
		uint8 ___sno2;
		uint8 err;
		sSrbPkg ___pkg2;
	};
};

enum eUSB_error{
	USB_ERR_BROADCAST =0xff,
	USB_ERR_BUS_TIMEOUT =0xfe,
};

struct sHardwareInfo{
	uint8 code[9];
	uint8 bl_version[3];
	uint32 time_stamp;
};




};
#endif /* __SRB_SHARE_CONST_H_ */
