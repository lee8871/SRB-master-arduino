

#ifndef __SRB_SHARE_BASE_CLUSTER_H_
#define __SRB_SHARE_BASE_CLUSTER_H_

#include "SRB-share-const.h" 

#define ERROR_LOOP 255
#define ERROR_5_LOOP_RESET 5
#define ERROR_20_LOOP_RESET 20
#define ERROR_100_LOOP_RESET 100
#define ERROR_RESET 0

struct 
csBase
{
	uint8 addr;
	uint8 name[27];
	uint8 error_behavior;
};


struct csInfo
{
	uint8 node_version_BCD[2];
	uint8 srb_version_BCD[2];
	uint16 time_stamp;
	uint8 node_type[17];
};	
//
struct csError
{
	uint16 file;
	uint16 line;
	uint8 description[24];
};

struct csMapping{
	union {
		uint8 u8[30];
		sStaticMapping m;
	};
};

#endif /* __SRB_SHARE_BASE_CLUSTER_H_ */

