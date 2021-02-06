

#include "MedicalLed.h"
#include "PowerLed.h"
#include "usart.h"



int main()
{
	usart_init();
	MedicalLed_Type mLed1;
	PowerLed_Type   pLed1;

	MedicalLed_ctor(&mLed1,INFARARED,(LedColor_Type)INFARARED,ON);
	PowerLed_ctor(&pLed1,GREEN,ON,DIAM_2MM,CURR_HIGH,VOL_NORMAL);
	
	PowerLed_runDiagnostics(&pLed1);
	MedicalLed_runDiagnostics(&mLed1);
	
	while(1)
	{
		
	}
	
}




