/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: 19 Sep 2021
 *      Author: Koteswararao p
 */

#include "stm32f407xx_gpio_driver.h"

/*
 * @Brief   GPIO Initialization
 * @Param1: GPIO Pin Handle
 * @Param2:
 * @Param3:
 * @return value: None
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	/*
	 * point 1. configure mode
	 * point 2. configure speed
	 * point 3. configure Pull up and Pull down settings
	 * point 4. configure output file
	 * point 5. configure Alternating function mode
	 */

	//	point 1

	uint32_t temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2* pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2* pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->MODER |= temp;
	temp=0;

	// point 2
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2* pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2* pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;
	temp=0;

	// point 3
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2* pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2* pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp=0;

	// point 4
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << (pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp=0;

	//point 5
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
 	{
		uint8_t temp1,temp2;
		temp1=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8;
  		temp2=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xf <<(4*temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode<<(4*temp2));
 	}

}

/*
 * @Brief   GPIO De-initialization
 * @Param1: Base address of GPIO's
 * @Param2:
 * @Param3:
 * @return value: None
 */

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	// Deinit register conditions are present in AHB1RSTR peripheral reset register
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	}
	else if(pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	}
	else if(pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}
	else if(pGPIOx == GPIOI)
	{
		GPIOI_REG_RESET();
	}
}


/*
 * @Brief   GPIO peripheral clock control
 * @Param1: GPIO Base address
 * @Param2: GPIO (Enable or disable) parameter
 * @Param3:
 * @return value: None
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENAorDIS)
{
	if(ENAorDIS == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_ENA();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_ENA();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_ENA();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_ENA();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_ENA();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_ENA();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_ENA();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_ENA();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_ENA();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DIS();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DIS();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DIS();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DIS();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DIS();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DIS();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DIS();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DIS();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_DIS();
		}
	}
}

/*
 * @Brief   GPIO Data Read from input pin
 * @Param1: GPIO Base address
 * @Param2: GPIO Pin Number
 * @return value: None
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t Value;
	Value = (uint8_t)((pGPIOx->IDR >> PinNumber)&0x00000001); // Reading using masking technique
	/*
	 * required pin will redirect to pin 0 and pin 0 will act as required for whole register
	 * can apply to all other pins present in register.[eg:10(required)&1=1 in embedded]
	 */
	return Value;
}

/*
 * @Brief   GPIO Data Read from input port
 * @Param1: GPIO Base address
 * @return value: None
 */

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t Value;
	Value = (uint16_t)pGPIOx->IDR;
	return Value;
}

/*
 * @Brief   GPIO Data Write to output pin
 * @Param1: GPIO Base address
 * @Param2: GPIO Pin number
 * @Param3: GPIO Pin value
 * @return value: None
 */

void GPIO_WritetoOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1<<PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1<<PinNumber);
	}
}

/*
 * @Brief   GPIO Data write to output port
 * @Param1: GPIO Base address
 * @Param2: GPIO Pin value
 * @return value: None
 */


void GPIO_WritetoOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t Value)
{
	pGPIOx->ODR = Value;
}

/*
 * @Brief   GPIO Output Data toggle pin
 * @Param1: GPIO Base address
 * @Param2: GPIO Pin value
 * @return value: None
 */


void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1<<PinNumber);
}
