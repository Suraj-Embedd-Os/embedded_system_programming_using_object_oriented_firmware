


#ifndef __LED_H
#define __LED_H

#include<stdint.h>
#include "stm32f4xx.h"

#define  LED_PORT				 GPIOA
#define  LED1_PIN				(1<<7U)
#define  LED2_PIN				(1<<8U)
#define  LED3_PIN				(1<<4U)
#define  LED4_PIN				(1<<5U)

#define LED1_MODE_BIT		(1<<7*2)
#define LED2_MODE_BIT		(1<<8*2)
#define LED3_MODE_BIT		(1<<4*2)
#define LED4_MODE_BIT		(1<<5*2)

#define LED_CLOCK				(1<<0U)
 
typedef enum{
	
	RED	=0,
	YELLOW,
	BLUE,
	GREEN
}LedColor_Type;

typedef enum{
	
	OFF	=0,
	ON,
}LedState_Type;


class Led{
	private:
			LedColor_Type color;
			LedState_Type	state;
	public:
			
		Led(LedColor_Type _color,LedState_Type _state);
		void Led_setStatus(LedState_Type _state);
		LedState_Type Led_getStatus();
	
};



#endif








