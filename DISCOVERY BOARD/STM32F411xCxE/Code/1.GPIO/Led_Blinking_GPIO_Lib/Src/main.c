#include "stm32f4xx.h"

#define GPIODEN				(1U<<3) // 0b 0000 0000 0000 0000 0000 0000 0000 1000

#define PIN12				(1<<12)
#define PIN13				(1<<13)
#define PIN14				(1<<14)
#define PIN15				(1<<15)
/*		(1U<<10)
		&=~(1U<<11)  // TO ONLY BIT 11 TO ZERO*/
int main (void){
	//enable clock
	//set pd12 as output pin
	RCC->AHB1ENR |= GPIODEN;
	GPIOD->MODER  |= (3<<24);  //set bit 10 to 1
	GPIOD->MODER  &= ~(1<<25);  //set bit 11 to 0

	GPIOD->MODER  |= (3<<26);  //set bit 10 to 1
	GPIOD->MODER  &= ~(1<<27);  //set bit 11 to 0

	GPIOD->MODER  |= (3<<28);  //set bit 10 to 1
	GPIOD->MODER  &= ~(1<<29);  //set bit 11 to 0

	GPIOD->MODER  |= (3<<30);  //set bit 10 to 1
	GPIOD->MODER  &= ~(1<<31);  //set bit 11 to 0

	while(1){

		GPIOD->ODR ^= PIN12;
		for( int i=0;i<100000;i++) {}
		GPIOD->ODR ^= PIN13;
		for( int i=0;i<100000;i++) {}
		GPIOD->ODR ^= PIN14;
		for( int i=0;i<100000;i++) {}
		GPIOD->ODR ^= PIN15;
		for( int i=0;i<100000;i++) {}
	}

}
