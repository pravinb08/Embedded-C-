#include "stm32f4xx.h"


#define GPIOAEN				(1U<<0)
#define GPIODEN				(1U<<3) // 0b 0000 0000 0000 0000 0000 0000 0000 1000

#define PIN0				(1U<<0)
#define PIN12				(1U<<12)
#define PIN13				(1U<<13)
#define PIN14				(1U<<14)
#define PIN15				(1U<<15)

int main (void){

	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIODEN;

	GPIOA->MODER  &= ~(1U<<0);
	GPIOA->MODER  &= ~(1U<<1);

	GPIOD->MODER  |= (1U<<24);
	GPIOD->MODER  &= ~(1U<<25);

	GPIOD->MODER  |= (1U<<26);
	GPIOD->MODER  &= ~(1U<<27);

	GPIOD->MODER  |= (1U<<28);
	GPIOD->MODER  &= ~(1U<<29);

	GPIOD->MODER  |= (1U<<30);
	GPIOD->MODER  &= ~(1U<<31);

	while(1){

		if( GPIOA->IDR & PIN0){
			GPIOD->BSRR = PIN12;
			GPIOD->BSRR = PIN13;
			GPIOD->BSRR = PIN14;
			GPIOD->BSRR = PIN15;
		}
		else{
			GPIOD->BSRR = (1<<28);
			GPIOD->BSRR = (1<<29);
			GPIOD->BSRR = (1<<30);
			GPIOD->BSRR = (1<<31);
		}
	}
}
