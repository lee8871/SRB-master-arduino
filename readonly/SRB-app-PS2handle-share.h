#ifndef __SRB_APP_PS2_handle_SHARE_H_
#define __SRB_APP_PS2_handle_SHARE_H_
//Node name should less than 16 :  
	           //0123456789abcdef 
#define NODENAME Ps2_Handle
	 
	 
namespace NODENAME
{
	
		
#define DM0 {6,3,	3,4,5,6,7,8,  		0,1,2}
#define M1  {6,3,	3,4,5,6,7,8,		0,1,2}
#define M2  {4,3,	5,6,7,8, 			0,1,2}
#define M3  {18,3,	3,4,5, 6,7,8,   9,10,11,   12,13,14,   15,16,17,  18,19,20 ,	0,1,2}
	

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

}


//----------------datas----------------	

#endif /* __SRB_APP_PS2_handle_SHARE_H_ */

