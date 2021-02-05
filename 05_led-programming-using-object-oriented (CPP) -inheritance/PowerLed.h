#ifndef _POWERLED_H
#define _POWERLED_H

#include "led.h"

typedef uint8_t led_elec_type;
typedef uint8_t led_dim_type;

typedef enum{
	CURR_LOW			=10,
	CURR_NORMAL		=20,
	CURR_HIGH			=40,
	CURR_VERY_HIGH=60
}LedCurrent_Type;

typedef enum{
	DIAM_2MM	=2,
	DIAM_4MM	=4,
	DIAM_7MM	=7
}LedDimeter_Type;

typedef enum{
	VOL_LOW			=3,
	VOL_NORMAL	=5,
	VOL_HIGH		=9
}LedVoltage_Type;

class PowerLed : public Led{
	private:
		LedCurrent_Type current;
		LedDimeter_Type diameter;
		LedVoltage_Type	voltage;
	public:
		
	 PowerLed( LedColor_Type _color,
						 LedState_Type _state,
						 LedDimeter_Type _diameter,
						 LedCurrent_Type _current,
						 LedVoltage_Type _voltage);

void PowerLed_setCurrent(LedCurrent_Type _current);
void PowerLed_setVoltage(LedVoltage_Type _voltage);
void PowerLed_setDiameter(LedDimeter_Type _diameter);

led_elec_type	PowerLed_ComputePower();
led_elec_type	PowerLed_getCurrent();
led_elec_type	PowerLed_getVoltage();
led_elec_type	PowerLed_getDiameter();
};






#endif


