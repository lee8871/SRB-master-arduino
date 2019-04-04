#ifndef __SRB_APP_Changer_SHARE_H_
#define __SRB_APP_Changer_SHARE_H_
	           //123456789abcdef
#define NODENAME Charger_2LiB
	 
	 
namespace NODENAME
{
		
#define DM0 {8,2, 0,1, 2,3, 4,5, 6,7,  8,9}
#define M1 {8,2, 0,1, 2,3, 4,5, 6,7,  8,9}
#define M2 {1,0,9}
#define M3 {8,2, 0,1, 2,3, 4,5, 6,7,  8,9}
	

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
{
	
	//out
	uint8 buzzer_now;
	sChargeStatus status;
	uint16 battery_voltage;
	uint16 battery_adc;
	uint16 last_change_sec;
	
	
	//in
	uint8 buzzer_commend;
	sStatusCfg sc;
	//out Power

	uint8 point;
	uint8 record[30];

};

#define voltageToAdc(voltage) (((uint16)(voltage*10.0))<<8)
struct csBattery{
	uint16 low_power_threshold;
	uint16 full_threshold;
	sStatusCfg sc;
};


struct csBuzzer{
	uint8 power_on;
	uint8 jack_in_vot_low;//
	uint8 jack_in_charge_close;//
	uint8 charging;//
	uint8 charge_done;//
	uint8 change_done_next;
	uint8 jack_out;//
	uint8 low_power;
};

//1 means ___ and 0 to _


}
#endif /* __SRB_APP_Changer_SHARE_H_ */

