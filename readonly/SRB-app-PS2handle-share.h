#ifndef __SRB_APP_PS2_handle_SHARE_H_
#define __SRB_APP_PS2_handle_SHARE_H_
//Node name should less than 16 :  
	           //0123456789abcdef 
#define NODENAME PS2_handle
	 
	 
namespace NODENAME
{
	
		
#define DM0 {7,3,3,4,5,6,7,8,9,0,1,2}
#define M1 {6,3,4,5,6,7,8,9,0,1,2}
#define M2 {4,3,6,7,8,9,0,1,2}
#define M3 {7,3,3,4,5,6,7,8,9,0,1,2}
	

//if defined DMx an array len = 30 is decleared for dynamic mapping 
//or defined Mx, than a mapping array is decleared 
#ifdef __MAPPING_DECLEAR__		
	#ifdef DM0 	
		#ifndef __MASTER__	
			uint8 mapping0[30];
		#endif		
	#else 
		uint8 mapping0[] = M0;
	#endif

	#ifdef DM1 	
		#ifndef __MASTER__	
			uint8 mapping1[30];
		#endif		
	#else 
		uint8 mapping1[] = M1;
	#endif
		
	#ifdef DM2 	
		#ifndef __MASTER__	
			uint8 mapping2[30];
		#endif		
	#else 
		uint8 mapping2[] = M2;
	#endif

	#ifdef DM3 	
		#ifndef __MASTER__	
			uint8 mapping3[30];
		#endif		
	#else 
		uint8 mapping3[] = M3;
	#endif		
#endif


#ifdef __MASTER__
	#undef NODENAME
	#undef M0
	#undef M1
	#undef M2
	#undef M3
	#undef DM0
	#undef DM1
	#undef DM2
	#undef DM3
#endif
		

			
	

#define KEYDOWN_

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
	uint8 u8[6];
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
	};
};		

struct sDataRs 
{
	uint16 rumble_time;	
	uint8 rumble;
	struct{
		uint8 handle_exist :1;
		uint8 handle_analog :1;
		uint8 dataChanged:1;
		uint8 noused :5;
	};
	sPS2_Handle_report handle;
};

struct Handle_mode{
	uint8 analog :1;
	uint8 rumble:1;
	//uint8 lock_mode:1;
};
struct csHandleConfig{
	Handle_mode mode;
	uint8 period_ms;
};

}


//----------------datas----------------	

#endif /* __SRB_APP_PS2_handle_SHARE_H_ */

