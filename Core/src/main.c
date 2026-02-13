/*
 * main.c
 *
 *  Created on: Feb 12, 2026
 *      Author: Rubin Khadka
 */
 
#include "stm32f10x.h"		// Device header
#include "gpio.h"

int main(void)
{
	// GPIO PC13 initialization
	LED_init();

	while(1)
	{
		LED_ON();
		Delay_ms(500);
		LED_OFF();
		Delay_ms(500);
	}
}
