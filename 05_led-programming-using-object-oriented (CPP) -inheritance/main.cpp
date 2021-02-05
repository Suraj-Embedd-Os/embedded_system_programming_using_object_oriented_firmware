

#include "PowerLed.h"
#include "usart.h"

PowerLed Led1(RED,ON,DIAM_2MM,CURR_LOW,VOL_LOW);
led_elec_type led1_power,led2_power,led3_power;

int main()
{
	usart_init();
	PowerLed Led2(YELLOW,ON,DIAM_7MM,CURR_NORMAL,VOL_HIGH);
	PowerLed *Led3 =new PowerLed(GREEN,ON,DIAM_4MM,CURR_HIGH,VOL_NORMAL);
	
	led1_power=Led1.PowerLed_ComputePower();
	led2_power=Led2.PowerLed_ComputePower();
	led3_power=Led3->PowerLed_ComputePower();
	
	
	while(1)
	{
		
	}
	
}




