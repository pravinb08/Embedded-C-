#include "stm32f4xx.h"

#define GPIODEN				(1U<<3)

#define Motor_EN_1			(1<<12)
#define IN_1				(1<<13)
#define IN_2				(1<<15)

void Run_Forward();
void Run_Backward();

int main (void){
	//enable clock
	//set pd12 as output pin
	RCC->AHB1ENR |= GPIODEN;
	GPIOD->MODER  |= (1<<24);
	GPIOD->MODER  &= ~(1<<25);

	GPIOD->MODER  |= (1<<26);
	GPIOD->MODER  &= ~(1<<27);

	GPIOD->MODER  |= (1<<30);
	GPIOD->MODER  &= ~(1<<31);

	while(1){

		Run_Forward();
		for( int i=0;i<10000000;i++) {}
		Run_Backward();
		for( int i=0;i<10000000;i++) {}
	}

}

void Run_Forward(){
	GPIOD->BSRR = Motor_EN_1;
	GPIOD->BSRR = IN_1;
	GPIOD->BSRR = (1<<31);

}

void Run_Backward(){
	GPIOD->BSRR = Motor_EN_1;
	GPIOD->BSRR = (1<<29);
	GPIOD->BSRR = IN_2;
}
