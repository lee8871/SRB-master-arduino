#ifndef __SRB_APP_Changer_SHARE_H_
#define __SRB_APP_Changer_SHARE_H_

namespace srb{
#define NODE_VERSION {1,0}
#define NODE_TYPE LiBatT2
namespace NODE_TYPE{

#define DM0 {10,2, 0,1, 2,3, 4,5, 6,7, 8,9,10,11}
#define M1 {10,2, 0,1, 2,3, 4,5, 6,7, 8,9,10,11}
#define M2 {1,0,11}
#define M3 {0,0}



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



//----------------datas----------------

union sChargeStatus{
	uint8 u8;
	struct {
		uint8 is_charge_enable:1;
		uint8 is_charging:1;
		uint8 is_charge_done:1;
		uint8 is_jack_in:1;
	};
};


union sStatusCfg{
	uint8 u8;
	struct{
		uint8 is_charge_enable:1;
		uint8 is_mute:1;
		uint8 is_powerLED_enable:1;
	};
};

struct sDataRs
{	//out
	uint8 buzzer_now;
	sChargeStatus status;
	uint16 battery_voltage;
	uint16 battery_adc;
	uint16 last_change_sec;
	uint16 capacity;
	//in
	uint8 buzzer_commend;
	sStatusCfg sc;
};

#define voltageToAdc(voltage) (((uint16)(voltage*10.0))<<8)
struct csBattery{
	uint16 low_power_alram_mV;
	uint16 charger_current_mA;
	uint16 capacity_mAh;
	uint16 inn_res_mOhm;
	sStatusCfg sc;
};


struct csInnRes{
	int16 mOhm_a[15];
};

struct csBuzzer{
	uint8 power_on;
	uint8 jack_in_vot_low;
	uint8 jack_in_charge_close;
	uint8 charging;
	uint8 charge_done;
	uint8 change_done_next;
	uint8 jack_out;
	uint8 low_power;
};

//1 means ___ and 0 to _


}}
#endif /* __SRB_APP_Changer_SHARE_H_ */
