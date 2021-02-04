
#ifndef  _USART_H
#define	 _USART_H
#include "stm32f4xx.h"
#include<stdio.h>

void usart_init(void);
int USART2_write(int ch);
int USART2_read(void);
void test_setup();









#endif



