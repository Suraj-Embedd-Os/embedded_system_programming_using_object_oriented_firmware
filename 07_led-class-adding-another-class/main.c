

#include "MedicalLed.h"
#include "usart.h"

MedicalLed_Type Med_led1;
MedicalLed_Type Med_led1;
LedWaveLenght_Type Led1,Led2,Led3;
int main()
{
	usart_init();
	MedicalLed_Type Power_led3;
	MedicalLed_ctor(&Med_led1,INFARARED,GREEN,ON);
	MedicalLed_ctor(&Med_led1,INFARARED,GREEN,ON);
	MedicalLed_ctor(&Med_led1,NEAR_INFARARED,RED,ON);

	Led1 =MedicalLed_GetWaveLength(&Med_led1);
	Led2 =MedicalLed_GetWaveLength(&Med_led1);
	Led3 =MedicalLed_GetWaveLength(&Med_led1);
	
	while(1)
	{
		
	}
	
}




