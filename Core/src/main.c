/*
 * main.c
 *
 *  Created on: Feb 12, 2026
 *      Author: Rubin Khadka
 */
 
#include "stm32f10x.h"		// Device header
#include "gpio.h"
#include "timer2.h"

int main(void)
{
	// GPIO PC13 initialization
	LED_init();
	TIMER2_Init();

	while(1)
	{
		LED_ON();
		TIMER2_Delay_ms(500);
		LED_OFF();
		TIMER2_Delay_ms(500);
	}
}
