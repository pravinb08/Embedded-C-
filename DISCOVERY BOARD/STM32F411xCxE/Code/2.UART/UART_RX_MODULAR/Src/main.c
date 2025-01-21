#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include <uart.h>

#define GPIODEN				(1U<<3)

#define PIN12				(1<<12)
#define PIN13				(1<<13)
#define PIN14				(1<<14)
#define PIN15				(1<<15)

char key;

int main (void){

	RCC->AHB1ENR |= GPIODEN;
	GPIOD->MODER  |= (3<<24);  //set bit 10 to 1
	GPIOD->MODER  &= ~(1<<25);  //set bit 11 to 0

	GPIOD->MODER  |= (3<<26);  //set bit 10 to 1
	GPIOD->MODER  &= ~(1<<27);  //set bit 11 to 0

	GPIOD->MODER  |= (3<<28);  //set bit 10 to 1
	GPIOD->MODER  &= ~(1<<29);  //set bit 11 to 0

	GPIOD->MODER  |= (3<<30);  //set bit 10 to 1
	GPIOD->MODER  &= ~(1<<31);  //set bit 11 to 0



	uart2_rxtx_init();

	while(1){
		  key = uart2_read();

		if (key == '1'){
			GPIOD->ODR |= PIN12;
		}
		else if(key == '2'){
			GPIOD->ODR |= PIN13;
		}
		else if(key == '3'){
			GPIOD->ODR |= PIN14;
		}
		else if(key == '4'){
			GPIOD->ODR |= PIN15;
		}
		else{
			GPIOD->ODR &=~ PIN12;
			GPIOD->ODR &=~ PIN13;
			GPIOD->ODR &=~ PIN14;
			GPIOD->ODR &=~ PIN15;
		}
	}
}
