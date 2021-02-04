

#include "PowerLed.h"
#include "usart.h"

PowerLed_Type Power_led1;
PowerLed_Type Power_led2;
led_elec_type Led1,Led2,Led3;
int main()
{
	usart_init();
	PowerLed_Type Power_led3;
	PowerLed_ctor(&Power_led1,RED,ON,DIAM_2MM,CURR_LOW,VOL_LOW);
	PowerLed_ctor(&Power_led2,YELLOW,ON,DIAM_7MM,CURR_HIGH,VOL_NORMAL);
	PowerLed_ctor(&Power_led3,GREEN,ON,DIAM_4MM,CURR_NORMAL,VOL_HIGH);

	Led1 =PowerLed_ComputePower(&Power_led1);
	Led2 =PowerLed_ComputePower(&Power_led2);
	Led3 =PowerLed_ComputePower(&Power_led3);
	
	while(1)
	{
		
	}
	
}




