/*
 * uart.h
 *
 *  Created on: Jan 09, 2025
 *      Author: 🌻
 */

#ifndef UART_H_
#define UART_H_
#include <stdint.h>
#include "stm32f4xx.h"

void uart2_write(int ch);
void uart2_tx_init(void);

#endif
