/*
 * colorful.h
 *
 * Created: 2017/8/29 22:12:28
 *  Author: lee-home
 */ 


#ifndef __SRB_APP_DMOTOR_SHARE_H_
#define __SRB_APP_DMOTOR_SHARE_H_
	           //123456789abcdef
#define NODENAME Du_Motor
	 
	 
namespace NODENAME
{
//----------------datas----------------	
#ifdef __MASTER__
#undef NODENAME
#endif


#ifdef __MAPPING_DECLEAR__
uint8 mapping0[] = {0,4,0,1,2,3};
uint8 mapping1[] = {0,4,2,3,0,1};
uint8 mapping2[] = {0,4,0,1,2,3};
uint8 mapping3[] = {0,4,2,3,0,1};
#endif

#define MOTOR_DIR_FOWARD 0
#define MOTOR_DIR_REVERSE 3
#define MOTOR_DIR_BRAKE 1
#define MOTOR_DIR_FREE 2
union sMotor
{
	uint16 u16;
	struct	{
		int16 speed:15;
		uint16 _no_used_2:1;
	};
	struct {
		uint8 _no_used_0;
		uint8 _no_used_1:7;
		uint8 brake:1;
	};
};		

struct sDataRs 
{
	sMotor ma;
	sMotor mb;
};

//------------cluster---------------
#define LOSE_BEHAVIOR_KEEP 2
#define LOSE_BEHAVIOR_BRAKE 1
#define LOSE_BEHAVIOR_FREE 0
struct csMotorSet{
	uint16 min_pwm_a;
	uint16 min_pwm_b;
	uint16 period;
	uint16 lose_control_ms;
	uint8 lose_behavior;
};
#define ADJ_DISABLE 0
#define ADJ_255 1
#define ADJ_1000 2
#define ADJ_10000 3

struct csMotorAdj{
	uint8 Adj;
	uint8 TogMotorA;
	uint8 TogMotorB;
};


}
#endif /* __SRB_APP_DMOTOR_SHARE_H_ */

