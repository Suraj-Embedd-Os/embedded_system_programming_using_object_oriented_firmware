

#include "led.h"
#include "usart.h"

Led:: Led(LedColor_Type _color,LedState_Type _state)
{
	this->color =_color;
	this->state	=_state;
	RCC->AHB1ENR	|=LED_CLOCK;
	
	switch(color)
	{
		case RED:
			LED_PORT->MODER |=LED1_MODE_BIT;
			if(this->state == ON){
				LED_PORT->ODR |=LED1_PIN;
				//printf("red led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED1_PIN;
				//printf("red led set to OFF\n\r");
			}
			break;
			case YELLOW:
			LED_PORT->MODER |=LED2_MODE_BIT;
			if(this->state == ON){
				LED_PORT->ODR |=LED2_PIN;
				printf("yellow led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED2_PIN;
				//printf("yellow led set to OFF\n\r");
			}
			break;
			case BLUE:
			LED_PORT->MODER |=LED3_MODE_BIT;
			if(this->state == ON){
				LED_PORT->ODR |=LED3_PIN;
				//printf("blue led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED3_PIN;
				//printf("blue led set to OFF\n\r");
			}
			break;
			case GREEN:
			LED_PORT->MODER |=LED4_MODE_BIT;
			if(this->state == ON){
				LED_PORT->ODR |=LED4_PIN;
				//printf("green led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED4_PIN;
				//printf("green led set to OFF\n\r");
			}
			break;
			
			default :
				break;
			
	}
}

void Led:: Led_setStatus(LedState_Type _state)
{
	this->state	=_state;
	
	switch(color)
	{
		case RED:
			LED_PORT->MODER |=LED1_MODE_BIT;
			if(this->state == ON){
				LED_PORT->ODR |=LED1_PIN;
				//printf("red led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED1_PIN;
				//printf("red led set to OFF\n\r");
			}
			break;
			case YELLOW:
			LED_PORT->MODER |=LED2_MODE_BIT;
			if(this->state == ON){
				LED_PORT->ODR |=LED2_PIN;
				printf("yellow led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED2_PIN;
				//printf("yellow led set to OFF\n\r");
			}
			break;
			case BLUE:
			LED_PORT->MODER |=LED3_MODE_BIT;
			if(this->state == ON){
				LED_PORT->ODR |=LED3_PIN;
				//printf("blue led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED3_PIN;
				//printf("blue led set to OFF\n\r");
			}
			break;
			case GREEN:
			LED_PORT->MODER |=LED4_MODE_BIT;
			if(this->state == ON){
				LED_PORT->ODR |=LED4_PIN;
				//printf("green led set to ON\n\r");
			}
			else{
				LED_PORT->ODR &=~LED4_PIN;
				//printf("green led set to OFF\n\r");
			}
			break;
			default:
					break;
	}
}

LedState_Type Led::Led_getStatus()
{
	//printf("The %d led is set to %d \n\r",me->color,me->state); 
	switch(this->color)
	{
		case RED:
				 //printf("the red led currently is %d\n\r",this->state);
				 break;
		
		case YELLOW:
				// printf("the yellow led currently is  %d\n\r",this->state);
				 break;
		
		case BLUE:
				 //printf("the blue led currently is  %d\n\r",this->state);
				 break;
				
		case GREEN:
				 //printf("the green led currently is  %d\n\r",this->state);
				 break;
		
	}
	return this->state;
}


