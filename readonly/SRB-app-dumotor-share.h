#ifndef __SRB_APP_DMOTOR_SHARE_H_
#define __SRB_APP_DMOTOR_SHARE_H_

namespace srb{
#define NODE_VERSION {1,0}
#define NODE_TYPE MotorX2
namespace NODE_TYPE{

#define DM0	{0,4,0,1,2,3}
#define M1	{0,4,0,1,2,3}
#define M2	{0,2,0,2}
#define M3	{0,4,2,3,0,1}


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
	static const char Node_name[] = TO_STRING(NODE_TYPE);
	#undef NODE_TYPE
	#undef TO_STRING
	#undef _TO_STRING
	
	static const char Node_version[2] = NODE_VERSION;
	#undef NODE_VERSION
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
	uint8 lose_control_10ms;
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

}}//namespace


#endif /* __SRB_APP_DMOTOR_SHARE_H_ */
