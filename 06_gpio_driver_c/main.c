
#include "stm32f4xx.h"


GPIO_InitTypeDef gpio_initStruct;
int main()
{
	__RCC_GPIOA_CLOCK_ENABLE();
	gpio_initStruct.Pin  =GPIO_PIN_5;
	gpio_initStruct.Mode =GPIO_MODE_OUTPUT_PP;
	gpio_initStruct.Pull =GPIO_NOPULL;
	
	Gpio_Init(GPIOA,&gpio_initStruct);
	
	while(1)
	{
		Gpio_Write_Pin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
		for(int i=0;i<200000;i++);
		Gpio_Write_Pin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
		for(int i=0;i<200000;i++);
	}

}


