#ifndef __SRB_APP_PS2_handle_SHARE_H_
#define __SRB_APP_PS2_handle_SHARE_H_
//Node name should less than 16 :  

namespace srb{ 
#define NODENAME Ps2_Handle
namespace NODENAME{

#define DM0 {6,3,	3,4,5,6,7,8,  		0,1,2}
#define M1  {6,3,	3,4,5,6,7,8,		0,1,2}
#define M2  {4,3,	5,6,7,8, 			0,1,2}
#define M3  {18,3,	3,4,5, 6,7,8,   9,10,11,   12,13,14,   15,16,17,  18,19,20 ,	0,1,2}

	
	
#ifdef BUILD_FOR_SRB_MASTER
	static const uint8 Dynamic_mapping0[] = DM0;
	static const uint8 Mapping1[] = M1;
	static const uint8 Mapping2[] = M2;
	static const uint8 Mapping3[] = M3;
	
	
	#undef DM0	
	#undef DM1	
	#undef DM2	
	#undef DM3	
	
	#undef M0
	#undef M1
	#undef M2
	#undef M3
	
	#define _TO_STRING(n) #n
	#define TO_STRING(n) _TO_STRING(n) 	
	static const char Node_name[] = TO_STRING(NODENAME);
	#undef NODENAME
	#undef TO_STRING
	#undef _TO_STRING	
#endif
	

	
	
struct	sKeyMapping{
	uint8 sel			:1;
	uint8 l3			:1;
	uint8 r3			:1;
	uint8 sta			:1;
	uint8 u				:1;
	uint8 r				:1;
	uint8 d				:1;
	uint8 l				:1;
	
	uint8 l2			:1;
	uint8 r2			:1;
	uint8 l1			:1;
	uint8 r1			:1;
	uint8 trag			:1;
	uint8 cir			:1;
	uint8 cros			:1;
	uint8 squ			:1;
	
};

union sPS2_Handle_report
{
	uint8 u8[18];
	struct	{
		sKeyMapping key;
		struct{				
			struct{
				uint8 x;
				uint8 y;
			}r;
			struct{
				uint8 x;
				uint8 y;
			}l;
		}joy;
		struct {	
			uint8 u;
			uint8 r;
			uint8 d;
			uint8 l;
			
			uint8 trag;
			uint8 cir;
			uint8 cros;
			uint8 squ;	
			
			uint8 l1;
			uint8 r1;	
			uint8 l2;
			uint8 r2;			
		}pressure;
	};
};		

struct sDataRs{
	uint8 rumble_L_set;	
	uint8 rumble_R_set;	
	uint8 rumble_L_strength;
	sPS2_Handle_report handle;		

};


struct csHandleConfig{
	uint8 online_rumble_10ms;
	uint8 lose_rumble_10ms;	
	uint8 rumble_L_strength;
};

}}//namespace

#endif /* __SRB_APP_PS2_handle_SHARE_H_ */

