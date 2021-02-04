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

typedef struct{
		Led_Type				super;
		LedCurrent_Type current;
		LedDimeter_Type diameter;
		LedVoltage_Type	voltage;
}PowerLed_Type;


void PowerLed_ctor(PowerLed_Type const * me,
									 LedColor_Type _color,
									 LedState_Type _state,
									 LedDimeter_Type _diameter,
									 LedCurrent_Type _current,
									 LedVoltage_Type _voltage);

void PowerLed_setCurrent(PowerLed_Type const * me,LedCurrent_Type _current);
void PowerLed_setVoltage(PowerLed_Type const * me,LedCurrent_Type _voltage);
void PowerLed_setDiameter(PowerLed_Type const * me,LedCurrent_Type _diameter);

led_elec_type	PowerLed_ComputePower(PowerLed_Type const * me);
led_elec_type	PowerLed_getCurrent(PowerLed_Type const * me);
led_elec_type	PowerLed_getVoltage(PowerLed_Type const * me);
led_elec_type	PowerLed_getDiameter(PowerLed_Type const * me);



#endif


