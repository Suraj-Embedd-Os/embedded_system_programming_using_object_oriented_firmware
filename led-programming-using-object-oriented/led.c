

#include "led.h"
#include "usart.h"

void Led_ctor(Led_Type * const me,LedColor_Type _color,LedState_Type _state)
{
	me->color =_color;
	me->state	=_state;
}

void Led_setStatus(Led_Type * const me,LedState_Type _state)
{
	me->state	=_state;
	
	//printf("The %d led is set to %d \n\r",me->color,me->state); 
	switch(me->color)
	{
		case RED:
				 printf("the red led state is %d\n\r",me->state);
				 break;
		
		case YELLOW:
				 printf("the yellow led state is  %d\n\r",me->state);
				 break;
		
		case BLUE:
				 printf("the blue led state is  %d\n\r",me->state);
				 break;
				
		case GREEN:
				 printf("the green led state is  %d\n\r",me->state);
				 break;
		
	}
}

LedState_Type Led_getStatus(Led_Type * const me)
{
	printf("The %d led is set to %d \n\r",me->color,me->state); 
//	switch(me->color)
//	{
//		case RED:
//				 printf("the red led currently is %d\n\r",me->state);
//				 break;
//		
//		case YELLOW:
//				 printf("the yellow led currently is  %d\n\r",me->state);
//				 break;
//		
//		case BLUE:
//				 printf("the blue led currently is  %d\n\r",me->state);
//				 break;
//				
//		case GREEN:
//				 printf("the green led currently is  %d\n\r",me->state);
//				 break;
//		
//	}
	return me->state;
}


