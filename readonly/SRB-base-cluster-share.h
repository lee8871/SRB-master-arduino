#ifndef __SRB_SHARE_BASE_CLUSTER_H_
#define __SRB_SHARE_BASE_CLUSTER_H_
#include "SRB-share-const.h" 

namespace srb{
	
enum eErrorLoop{
	ERROR_LOOP = 255,
	ERROR_5_LOOP_RESET = 5,
	ERROR_20_LOOP_RESET = 20,
	ERROR_100_LOOP_RESET = 100,
	ERROR_RESET = 0,
};

enum eBaseClusterCmd{
	BCC_RANDOM_ADDR = 0xf0,
	BCC_FORSE_RANDOM_ADDR = 0xfa,
	BCC_SHOW_LOW_ADDR = 0xf3,
	BCC_SHOW_HIGH_ADDR = 0xf4,
	BCC_SHOW_CLOSE = 0xf5,
};

struct csBase{
	uint8 addr;
	uint8 name[27];
	uint8 error_behavior;
};

struct csInfo{
	uint8 node_version[2];
	uint8 srb_version[2];
	int32 time_stamp;
	uint8 node_type[17];
};	

struct csError{
	uint8 err_num;
	uint8 description[24];
	uint8 v[5];
};

struct csMapping{
	union {
		uint8 u8[30];
		sMapping m;
	};
};

};
#endif /* __SRB_SHARE_BASE_CLUSTER_H_ */

