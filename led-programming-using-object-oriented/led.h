


#ifndef __LED_H
#define __LED_H

#include<stdint.h>
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


typedef struct{
	
	LedColor_Type color;
	LedState_Type	state;
}Led_Type;



void Led_ctor(Led_Type * const me,LedColor_Type _color,LedState_Type _state);
void Led_setStatus(Led_Type * const me,LedState_Type _state);
LedState_Type Led_getStatus(Led_Type * const me);
#endif








