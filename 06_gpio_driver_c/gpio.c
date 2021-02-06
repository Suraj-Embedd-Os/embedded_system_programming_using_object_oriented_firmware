
#include "gpio.h"
#define RCC_GPIOA_CLOCK_ENABLE		0x1<<0
#define RCC_GPIOB_CLOCK_ENABLE		0x1<<1
#define RCC_GPIOC_CLOCK_ENABLE		0x1<<2
#define RCC_GPIOD_CLOCK_ENABLE		0x1<<3
#define RCC_GPIOE_CLOCK_ENABLE		0x1<<4
#define RCC_GPIOF_CLOCK_ENABLE		0x1<<5
#define RCC_GPIOG_CLOCK_ENABLE		0x1<<6
#define RCC_GPIOH_CLOCK_ENABLE		0x1<<7

void Gpio_Init(GPIO_typeDef * GPIOx, GPIO_InitTypeDef * pin_init)
{
	uint32_t _temp=0U;
	uint32_t	position;
	uint32_t 	iopostion=0U;
	uint32_t	iocurrent=0U;
	
	for(position=0U;position<GPIO_PIN_NUMBER;position++)
	{
		iopostion = 0x01<<position;
		iocurrent	=(uint32_t)(pin_init->Pin &iopostion);
	
		if(iocurrent==iopostion)
		{
			if(pin_init->Mode == GPIO_MODE_AF_PP || pin_init->Mode == GPIO_MODE_AF_OD)
			{
				_temp	=GPIOx->AFR[position>>3U];
				_temp &=(0xFU<<(uint32_t)(position & 7U)*4U);
				_temp	|= (uint32_t)((pin_init->Alternate)<<((uint32_t)(position & 7U)*4U));
				 
				 GPIOx->AFR[position>>3U]= _temp;
				
			}
			if(GPIOx->MODER ==GPIO_MODE_OUTPUT_PP ||GPIOx->MODER ==GPIO_MODE_OUTPUT_OD
					||GPIOx->MODER==GPIO_MODE_AF_PP || GPIOx->MODER==GPIO_MODE_AF_OD)
			{
				_temp	=GPIOx->OSPEEDR;
				_temp &=~(GPIO_SPEED_OSPEEDR0<<(position*2));
				_temp	|= (pin_init->Speed &0x3)<<(position*2);
					GPIOx->OSPEEDR= _temp;
				
				_temp  =GPIOx->OTYPER;
				_temp	&=~(position);
				_temp |=((pin_init->Mode>>4U)&0x1);
				 GPIOx->OTYPER	=_temp;
			
			}
				_temp =GPIOx->PUPDR;
				_temp &=~(GPIO_PUPDR_PUPDR0<<(position*2));
				_temp	|= pin_init->Pull <<(position*2);
				GPIOx->PUPDR= _temp;
			}
			
	}	
}

GPIO_PinState Gpio_Read_Pin(GPIO_typeDef * GPIOx,uint16_t Gpio_Pin)
{
	GPIO_PinState bitStaus;
	if((GPIOx->IDR & Gpio_Pin)!=(uint32_t)GPIO_PIN_RESET)
			bitStaus=GPIO_PIN_SET;
	else
		bitStaus=GPIO_PIN_RESET;
	
	return bitStaus;
}
void Gpio_Write_Pin(GPIO_typeDef * GPIOx,uint16_t Gpio_Pin,GPIO_PinState _state)
{
	if(_state!=GPIO_PIN_RESET)
		GPIOx->BSRR = Gpio_Pin;
	else
		GPIOx->BSRR = (uint32_t)Gpio_Pin<<16;
}
void Gpio_Toggle_Pin(GPIO_typeDef * GPIOx,uint16_t Gpio_Pin)
{
	GPIOx->ODR ^=Gpio_Pin;
}

void __RCC_GPIOA_CLOCK_ENABLE(void)
{
	RCC->AHB1ENR |=RCC_GPIOA_CLOCK_ENABLE;
}
void __RCC_GPIOB_CLOCK_ENABLE(void)
{
	RCC->AHB1ENR |=RCC_GPIOB_CLOCK_ENABLE;
}
void __RCC_GPIOC_CLOCK_ENABLE(void)
{
	RCC->AHB1ENR |=RCC_GPIOC_CLOCK_ENABLE;
}
void __RCC_GPIOD_CLOCK_ENABLE(void)
{
	RCC->AHB1ENR |=RCC_GPIOD_CLOCK_ENABLE;
}
void __RCC_GPIOE_CLOCK_ENABLE(void)
{
	RCC->AHB1ENR |=RCC_GPIOE_CLOCK_ENABLE;
}
void __RCC_GPIOF_CLOCK_ENABLE(void)
{
	RCC->AHB1ENR |=RCC_GPIOF_CLOCK_ENABLE;
}
void __RCC_GPIOG_CLOCK_ENABLE(void)
{
	RCC->AHB1ENR |=RCC_GPIOG_CLOCK_ENABLE;
}
void __RCC_GPIOH_CLOCK_ENABLE(void)
{
	RCC->AHB1ENR |=RCC_GPIOH_CLOCK_ENABLE;
}