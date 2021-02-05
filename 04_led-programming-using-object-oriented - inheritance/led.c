

#include "led.h"
#include "usart.h"

void Led_ctor(Led_Type * const me,LedColor_Type _color,LedState_Type _state)
{
	me->color =_color;
	me->state	=_state;
	RCC->AHB1ENR	|=LED_CLOCK;
	
	switch(me->color)
	{
		case RED:
			LED_PORT->MODER |=LED1_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |=LED1_PIN;
				printf("red led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED1_PIN;
				printf("red led set to OFF\n\r");
			}
			break;
			case YELLOW:
			LED_PORT->MODER |=LED2_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |=LED2_PIN;
				printf("yellow led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED2_PIN;
				printf("yellow led set to OFF\n\r");
			}
			break;
			case BLUE:
			LED_PORT->MODER |=LED3_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |=LED3_PIN;
				printf("blue led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED3_PIN;
				printf("blue led set to OFF\n\r");
			}
			break;
			case GREEN:
			LED_PORT->MODER |=LED4_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |=LED4_PIN;
				printf("green led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED4_PIN;
				printf("green led set to OFF\n\r");
			}
			break;
			
			default :
				break;
			
	}
}

void Led_setStatus(Led_Type * const me,LedState_Type _state)
{
	me->state	=_state;
	
	switch(me->color)
	{
		case RED:
			LED_PORT->MODER |=LED1_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |=LED1_PIN;
				printf("red led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED1_PIN;
				printf("red led set to OFF\n\r");
			}
			break;
			case YELLOW:
			LED_PORT->MODER |=LED2_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |=LED2_PIN;
				printf("yellow led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED2_PIN;
				printf("yellow led set to OFF\n\r");
			}
			break;
			case BLUE:
			LED_PORT->MODER |=LED3_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |=LED3_PIN;
				printf("blue led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED3_PIN;
				printf("blue led set to OFF\n\r");
			}
			break;
			case GREEN:
			LED_PORT->MODER |=LED4_MODE_BIT;
			if(me->state == ON){
				LED_PORT->ODR |=LED4_PIN;
				printf("green led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED4_PIN;
				printf("green led set to OFF\n\r");
			}
			break;
			default:
					break;
	}
}

LedState_Type Led_getStatus(Led_Type * const me)
{
	//printf("The %d led is set to %d \n\r",me->color,me->state); 
	switch(me->color)
	{
		case RED:
				 printf("the red led currently is %d\n\r",me->state);
				 break;
		
		case YELLOW:
				 printf("the yellow led currently is  %d\n\r",me->state);
				 break;
		
		case BLUE:
				 printf("the blue led currently is  %d\n\r",me->state);
				 break;
				
		case GREEN:
				 printf("the green led currently is  %d\n\r",me->state);
				 break;
		
	}
	return me->state;
}


