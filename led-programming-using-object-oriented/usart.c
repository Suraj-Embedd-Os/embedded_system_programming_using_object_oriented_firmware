
#include "usart.h"

void usart_init()
{
	// Enable UART and port clock
	RCC->APB1ENR |=(1<<17);
	RCC->AHB1ENR |=0x1;
	
	// select pin mode PA3 PA3
	GPIOA->MODER &=~((0x3<<2*2) |(0x3<<3*2));
	GPIOA->MODER |=((0x2<<(2*2))|(0x2<<(3*2)));
	
	GPIOA->AFR[0] &=~((0xf<<2*4)|(0xf<<3*4));
	GPIOA->AFR[0] |=((0x7<<2*4)|(0x7<<3*4));
	
	USART2->BRR = 0x8B;
	USART2->CR1	|= (0x3<<2); //enable rx and tx
	USART2->CR2 =0;
	USART2->CR3 =0;
	USART2->CR1 |=(0x1<<13);
}

int USART2_write(int ch)
{
		while(!(USART2->SR & (0x1<<7))){}
			USART2->DR = (ch &0xff);
			
			return ch;	
}
int USART2_read(void)
{
		while(!(USART2->SR & (0x1<<5))){}
			return USART2->DR;
}

struct __FILE {int handle ;};

FILE __stdin 	={0};
FILE __stdout ={1};
FILE __stderr ={2};

int fgetc(FILE *f)
{
	int c;
			c=USART2_read();
	  if(c=='\r')
		{
			USART2_write(c);
			c='\n';
		}
	USART2_write(c); /* echo */	
}

int fputc(int c,FILE *f)
{
	return USART2_write(c);
}

int n;
char str[80];

void test_setup()
{
	printf("Please enter a number: ");
	scanf("%d",&n);
	printf("the number entered is %d",n);
	printf("please type a character entered is: ");
	gets(str);
	printf("character entered is: ");
	puts(str);
	printf("\n\r");
}





