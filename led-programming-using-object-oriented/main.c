

#include "led.h"
#include "usart.h"

Led_Type led1;
int main()
{
	usart_init();
	Led_ctor(&led1,RED,OFF);
	
	Led_getStatus(&led1);
	while(1)
	{
		
	}
	
}




