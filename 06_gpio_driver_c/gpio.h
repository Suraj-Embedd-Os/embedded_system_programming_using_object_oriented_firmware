

#ifndef __GPIO_H
#define __GPIO_H
#include "stm32f4xx.h"
#define _IO			volatile

/********gpio pin ***********************/
#define				GPIO_PIN_0				((uint16_t)0x0000)
#define				GPIO_PIN_1				((uint16_t)0x0002)
#define				GPIO_PIN_2				((uint16_t)0x0004)
#define				GPIO_PIN_3				((uint16_t)0x0008)
#define				GPIO_PIN_4				((uint16_t)0x0010)
#define				GPIO_PIN_5				((uint16_t)0x0020)
#define				GPIO_PIN_6				((uint16_t)0x0040)
#define				GPIO_PIN_7				((uint16_t)0x0080)
#define				GPIO_PIN_8				((uint16_t)0x0100)
#define				GPIO_PIN_9				((uint16_t)0x0200)
#define				GPIO_PIN_10				((uint16_t)0x0400)
#define				GPIO_PIN_11				((uint16_t)0x0800)
#define				GPIO_PIN_12				((uint16_t)0x1000)
#define				GPIO_PIN_13				((uint16_t)0x2000)
#define				GPIO_PIN_14				((uint16_t)0x4000)
#define				GPIO_PIN_15				((uint16_t)0x8000)

#define 			GPIO_PIN_NUMBER		  (16U)
#define				GPIO_MODER_MODE0		0x3
#define   		GPIO_MODE						0x3
#define       GPIO_PUPDR_PUPDR0		0x3

/********************gpio mode **************/	
#define				GPIO_MODE_INPUT					0x00
#define				GPIO_MODE_OUTPUT_PP			0x01
#define				GPIO_MODE_AF_PP					0x02
#define				GPIO_MODE_ANALOG				0x03

/****************gpio pull register*****************/
#define			GPIO_NOPULL								0x00
#define			GPIO_PULLUP								0x01
#define			GPIO_PULLDOWN							0x02
	
/****************gpio speed register*****************/	
typedef struct
{
		_IO	uint32_t MODER; 			//0x00
		_IO	uint32_t OTYPER;			//0x04
		_IO	uint32_t OSPEEDR;			//0x08
		_IO	uint32_t PUPDR;				//0x0c
		_IO	uint32_t IDR;					//0x10
		_IO	uint32_t ODR;					//0x14
		_IO	uint32_t BSRR;				//0x18
		_IO	uint32_t LCKR;				//0x1c
		_IO	uint32_t AFRL;				//0x20
		_IO	uint32_t AFRH;				//0x24
}GPIO_typeDef;

typedef struct
{
	uint32_t Pin;
	uint32_t Mode;
	uint32_t Pull;
	uint32_t Speed;
	uint32_t Alternate;
	
}GPIO_InitTypeDef;

typedef enum{
	GPIO_PIN_RESET=0,
	GPIO_PIN_SET
}GPIO_PinState;

void Gpio_Init(GPIO_typeDef * GPIOx, GPIO_InitTypeDef * Gpio_init);
GPIO_PinState Gpio_Read_Pin(GPIO_typeDef * GPIOx,uint16_t Gpio_Pin);
void Gpio_Write_Pin(GPIO_typeDef * GPIOx,uint16_t Gpio_Pin,GPIO_PinState _state);
void Gpio_Toggle_Pin(GPIO_typeDef * GPIOx,uint16_t Gpio_Pin);

void __RCC_GPIOA_CLOCK_ENABLE(void);
void __RCC_GPIOB_CLOCK_ENABLE(void);
void __RCC_GPIOC_CLOCK_ENABLE(void);
void __RCC_GPIOD_CLOCK_ENABLE(void);
void __RCC_GPIOE_CLOCK_ENABLE(void);
void __RCC_GPIOF_CLOCK_ENABLE(void);
void __RCC_GPIOG_CLOCK_ENABLE(void);
void __RCC_GPIOH_CLOCK_ENABLE(void);


#endif


