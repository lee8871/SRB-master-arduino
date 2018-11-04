

#ifndef __SRB_SHARE_BASE_CLUSTER_H_
#define __SRB_SHARE_BASE_CLUSTER_H_


#define ERROR_LOOP 255
#define ERROR_5_LOOP_RESET 5
#define ERROR_20_LOOP_RESET 20
#define ERROR_100_LOOP_RESET 100
#define ERROR_RESET 0

struct csBase
{
	uint8 addr;
	uint8 name[17];
	uint8 error_behavior;
};


struct csInfo
{
	uint8 version_BCD[2];
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

#endif /* __SRB_SHARE_BASE_CLUSTER_H_ */

