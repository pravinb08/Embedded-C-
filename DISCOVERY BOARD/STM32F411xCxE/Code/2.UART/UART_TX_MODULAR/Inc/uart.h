/*
 * uart.h
 *
 *  Created on: Jan 22, 2025
 *      Author: prave
 */


#ifndef UART_H_
#define UART_H_
#include <stdint.h>
#include "stm32f4xx.h"

void uart2_write(int ch);
void uar2_tx_init(void);

#endif
