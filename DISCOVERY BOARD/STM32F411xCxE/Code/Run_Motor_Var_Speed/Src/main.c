#include "stm32f4xx.h"

#define GPIODEN     (1U<<3)
#define Motor_EN_1  (1U<<12)
#define IN_1        (1U<<13)
#define IN_2        (1U<<15)

void GPIO_Init(void);
void Timer2_Init(void);
void Delay_ms(uint32_t ms);
void Run_Forward(void);
void Run_Backward(void);
void Set_Speed(uint8_t duty_cycle);

int main(void) {
    GPIO_Init();
    Timer2_Init();

    while (1) {
        Run_Forward();
        for (int speed = 0; speed <= 100; speed += 10) {
            for (int i = 0; i < 100; i++)
                Set_Speed(speed);
            Delay_ms(500);
        }

        Run_Backward();
        for (int speed = 100; speed >= 0; speed -= 10) {
            for (int i = 0; i < 100; i++)
                Set_Speed(speed);
            Delay_ms(500);
        }
    }
}

void GPIO_Init(void) {
    RCC->AHB1ENR |= GPIODEN;

    // Set PD12, PD13, PD15 as output
	GPIOD->MODER  |= (1<<24);
	GPIOD->MODER  &= ~(1<<25);

	GPIOD->MODER  |= (1<<26);
	GPIOD->MODER  &= ~(1<<27);

	GPIOD->MODER  |= (1<<30);
	GPIOD->MODER  &= ~(1<<31);
}

void Run_Forward(void) {
    GPIOD->BSRR = IN_1;
    GPIOD->BSRR = (1<<31); // Reset IN_2 TO LOW
}

void Run_Backward(void) {
    GPIOD->BSRR = IN_2;
    GPIOD->BSRR = (1<<29); // Reset IN_1 TO LOW
}

void Set_Speed(uint8_t duty_cycle) {
    if (duty_cycle > 100) duty_cycle = 100;

    uint32_t on_time = duty_cycle;
    uint32_t off_time = 100 - duty_cycle;

    GPIOD->BSRR = Motor_EN_1;
    Delay_ms(on_time);
    GPIOD->BSRR = (1<<28); // Reset PD12
    Delay_ms(off_time);
}

void Timer2_Init(void) {
    RCC->APB1ENR |= (1<<0);        // Enable TIM2 clock

    TIM2->PSC = 8 - 1;             // 8 MHz / 8 = 1 MHz → 1 µs per tick
    TIM2->ARR = 1000 - 1;          // 1000 ticks = 1 ms
    TIM2->CR1 |= (1<<0);           // Enable counter
}

void Delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms; i++) {
        TIM2->CNT = 0;
        while (!(TIM2->SR & 1));   // Wait for UIF flag
        TIM2->SR &= ~1;            // Clear UIF flag
    }
}
