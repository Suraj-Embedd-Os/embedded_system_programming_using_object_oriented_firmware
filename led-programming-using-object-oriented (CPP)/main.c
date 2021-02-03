

#include "led.h"
#include "usart.h"

Led_Type led1;
Led_Type led2;
Led_Type led3;
Led_Type led4;
int main()
{
	usart_init();
	Led_ctor(&led1,RED,ON);
	Led_ctor(&led2,YELLOW,ON);
	Led_ctor(&led3,BLUE,ON);
	Led_ctor(&led4,GREEN,OFF);
	
	Led_getStatus(&led1);
	Led_getStatus(&led2);
	Led_getStatus(&led3);
	Led_getStatus(&led4);
	while(1)
	{
		
	}
	
}




