
#include "PowerLed.h"
#include "usart.h"

void PowerLed_ctor(PowerLed_Type *const me,
									 LedColor_Type _color,
									 LedState_Type _state,
									 LedDimeter_Type _diameter,
									 LedCurrent_Type _current,
									 LedVoltage_Type _voltage)
{
	static const struct LedVtable vtable ={
		(void(*)(Led_Type const * const me))&PowerLed_runDiagnostics,
		(uint32_t(*)(Led_Type const * const me))&PowerLed_computeEfficiency,
			
	};
	
	Led_ctor(&me->super,_color,_state);
	me->super.vptr =&vtable;
	
	me->current = _current;
	me->diameter= _diameter;
	me->voltage	= _voltage;
}

void PowerLed_setCurrent(PowerLed_Type *const  me,LedCurrent_Type _current){
	
	me->current =_current;
}

void PowerLed_setVoltage(PowerLed_Type *const  me,LedVoltage_Type _voltage){
	me->voltage =_voltage;
}

void PowerLed_setDiameter(PowerLed_Type *const  me,LedDimeter_Type _diameter){
	me->diameter =_diameter;
}

led_elec_type	PowerLed_ComputePower(PowerLed_Type *const  me){
	return me->current*me->voltage;
}

led_elec_type	PowerLed_getCurrent(PowerLed_Type *const  me){
	return me->current;
}
led_elec_type	PowerLed_getVoltage(PowerLed_Type *const  me){
	return me->voltage;
}
led_elec_type	PowerLed_getDiameter(PowerLed_Type *const  me){
	return me->diameter;
}

uint32_t PowerLed_computeEfficiency(PowerLed_Type const *const me){
		//Dummy efficiency computations
	
	const int8_t input=120;
	const int8_t output=80;
	
	int8_t eff =((input/output)*100)-((int8_t)(me->current)/2);;
	
	printf("medical Led Module Efficiency is  : %d...\r\n",eff);
	return eff;
}
void PowerLed_runDiagnostics(PowerLed_Type const *const me){
		/* dummy diagnosis */
	for(int i=0;i<(int)me->current;i++)
	{
		printf("Power Led diagnositics stage :%d...\n\r",i);
		
		// do something
	}
}