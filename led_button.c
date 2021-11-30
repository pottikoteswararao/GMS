/*
 * led_button.c
 *
 *  Created on: 20 Sep 2021
 *      Author: Koteswararao pk
 */
#include "stm32f407xx.h"

void delay(void)
{
	for(uint32_t i=0;i<5000000;i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed, GPIOBtn;
	GpioLed.pGPIOx=GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	GPIOBtn.pGPIOx=GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GPIOBtn);

	while(1)
	{
		// orange 13 green 12 red 14 blue 12
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay();
		if(GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0) == ENABLE)
		{
			while(1)
			{
				GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
				delay();
				GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
				delay();
				GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
				delay();
				GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
				delay();	
			}
		}
	}
	
    return 0;
}


