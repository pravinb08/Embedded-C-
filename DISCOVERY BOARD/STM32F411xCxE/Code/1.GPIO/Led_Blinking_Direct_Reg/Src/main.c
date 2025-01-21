//Where is the led connected ?
// what is the port and the pin  ?
#define PERIPH_BASE			(0x40000000UL)

#define AHB1_PERIPH_OFFSET	(0x00020000UL)
#define AHB1_PERIPH_BASE	( PERIPH_BASE + AHB1_PERIPH_OFFSET)

#define GPIOD_OFFSET		(0x0C00UL)
#define GPIOD_BASE			(AHB1_PERIPH_BASE+GPIOD_OFFSET)

#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1_PERIPH_BASE+RCC_OFFSET)

#define AHB1ENR_OFFSET 		(0x30UL)
#define RCC_AHB1ENR_R		(*(volatile unsigned int *)(RCC_BASE+AHB1ENR_OFFSET))

#define MODE_R_OFFSET		(0x00UL)
#define GPIOD_MODE_R		(*(volatile unsigned int *)(MODE_R_OFFSET+GPIOD_BASE))

#define OD_R_OFFSET 		(0x14UL)
#define GPIOD_OD_R			(*(volatile unsigned int *)(OD_R_OFFSET+GPIOD_BASE))

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
	RCC_AHB1ENR_R |= GPIODEN;
	GPIOD_MODE_R  |= (1<<24);
	GPIOD_MODE_R  &= ~(1<<25);

	GPIOD_MODE_R  |= (1<<26);
	GPIOD_MODE_R  &= ~(1<<27);

	GPIOD_MODE_R  |= (1<<28);
	GPIOD_MODE_R  &= ~(1<<29);

	GPIOD_MODE_R  |= (1<<30);
	GPIOD_MODE_R  &= ~(1<<31);

	while(1){
		//set pd12 high
		GPIOD_OD_R ^= PIN12;
		GPIOD_OD_R ^= PIN13;
		GPIOD_OD_R ^= PIN14;
		GPIOD_OD_R ^= PIN15;
		for( int i=0;i<100000;i++) {}
	}

}
