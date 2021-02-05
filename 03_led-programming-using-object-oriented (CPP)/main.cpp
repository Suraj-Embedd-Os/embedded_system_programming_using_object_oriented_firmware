

#include "led.h"
#include "usart.h"

Led led1(RED,ON);
LedState_Type led1_statue;
LedState_Type led2_statue;
LedState_Type led3_statue;
int main()
{
	usart_init();
	Led led2(YELLOW,ON);
	Led *led3 =new Led(BLUE,ON);
	
	led1_statue=led1.Led_getStatus();
	led2_statue=led2.Led_getStatus();
	led3_statue=led3->Led_getStatus();
	
	led1.Led_setStatus(OFF);
	led2.Led_setStatus(OFF);
	led3->Led_setStatus(OFF);
	
	delete led3;
		
	while(1)
	{
		
	}
	
}




