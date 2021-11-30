/*
 * stm32f407xx_gpio_driver.h
 * STM32 Board specific header file(Peripheral specific header file)
 *  Created on: 19 Sep 2021
 *      Author: Koteswararao p
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

/*
 * GPIO configurable items selection using GPIO_PinConfig_t structure handle
 */

typedef struct // GPIO pin Handle structure
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/* structure handle for a GPIOx pin */

typedef struct
{
	GPIO_RegDef_t *pGPIOx; // Base address of the GIPOx port
	GPIO_PinConfig_t GPIO_PinConfig; // GPIO pin configuration
}GPIO_Handle_t;

/*
 * Pin numbers for GPIOx
 */

#define GPIO_PIN_NO_0				0
#define GPIO_PIN_NO_1				1
#define GPIO_PIN_NO_2				2
#define GPIO_PIN_NO_3				3
#define GPIO_PIN_NO_4				4
#define GPIO_PIN_NO_5				5
#define GPIO_PIN_NO_6				6
#define GPIO_PIN_NO_7				7
#define GPIO_PIN_NO_8				8
#define GPIO_PIN_NO_9				9
#define GPIO_PIN_NO_10				10
#define GPIO_PIN_NO_11				11
#define GPIO_PIN_NO_12				12
#define GPIO_PIN_NO_13				13
#define GPIO_PIN_NO_14				14
#define GPIO_PIN_NO_15				15

/*
 * GPIO pin modes
 */

#define GPIO_MODE_IN				0 // Input(reset mode)
#define GPIO_MODE_OUT				1 // General purpose output mode
#define GPIO_MODE_ALTFN				2 // Alternate function mode
#define GPIO_MODE_ANALOG			3 // Analog mode

/*
 * GPIO_Pinspeed macros
 */

#define GPIO_SPEED_LOW				0
#define GPIO_SPEED_MEDIUM			1
#define GPIO_SPEED_HIGH				2
#define GPIO_SPEED_VHIGH			3

/*
 * GPIO_PinPuPdControl
 */

#define GPIO_NO_PUPD				0
#define GPIO_PU						1
#define GPIO_PD						2

/*
 * GPIO_PinOPType
 */

#define GPIO_OP_TYPE_PP				0
#define GPIO_OP_TYPE_OD				1

// User defined API's//

/*
 * Init and DeInit of API's
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx); // Deinit register conditions are present in AHB1RSTR peripheral reset register


/*
 * Peripheral clock control
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENAorDIS);

/*
 * Data read and write configurations and toggle configuration
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WritetoOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WritetoOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
