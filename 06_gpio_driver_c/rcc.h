

#ifndef __RCC_H
#define __RCC_H

#include "stm32f4xx.h"
#define _IO			volatile

typedef struct
{
		_IO uint32_t CR;  			//0x00
		_IO uint32_t PLLCFGR;		//0x04
		_IO uint32_t CFGR;			//0x08
		_IO uint32_t CIR;				//0x0c
		_IO uint32_t AHB1RSTR;	//0x10
		_IO uint32_t AHB2RSTR;	//0x14
		_IO uint32_t AHB3RSTR;	//0x18
				uint32_t DUMMY1;		//0x1c
		_IO uint32_t APB1RSTR;	//0x20
		_IO uint32_t APB2RSTR;	//0x24
				uint32_t DUMMY2[2]; //0x28,//0x2c
		_IO uint32_t AHB1ENR;		//0x30
		_IO uint32_t AHB2ENR;		//0x34
		_IO uint32_t AHB3ENR;		//0x38
				uint32_t DUMMY3;		//0x3c
		_IO uint32_t APB1ENR;		//0x40	
		_IO uint32_t APB2ENR;		//0x44
				uint32_t DUMMY4[2]; //0x48,//0x4c
		_IO uint32_t AHB1LPENR;	//0x50
		_IO uint32_t AHB2LPENR;	//0x54
		_IO uint32_t AHB3LPENR;	//0x58
				uint32_t DUMMY5; 		//0x5c,
		_IO uint32_t APB1LPENR;	//0x60
		_IO uint32_t APB2LPENR;	//0x64
				uint32_t DUMMY6[2];	//0x68 ,//0x6C
		_IO uint32_t BDCR;			//0x70	
		_IO uint32_t CSR;				//0x74	
				uint32_t DUMMY7[2];	//0x78 ,0x7c
		_IO uint32_t SSCGR;			//0x80
		_IO uint32_t PLLI2SCFGR;//0x84
		_IO uint32_t PLLSAICFGR;//0x88
		_IO uint32_t DCKCFGR;		//0x8c
		_IO uint32_t CKGATENR;	//0x90
		_IO uint32_t DCKCFGR2;	//0x94

}RCC_TypeDef;

#endif


