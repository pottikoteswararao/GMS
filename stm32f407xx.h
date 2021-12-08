/*
 * stm32f407xx.h
 * MCU specific Header file (with every definition included)
 *  Created on: Sep 18, 2021
 *      Author: Koteswararao p
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include<stdint.h>
#define __vo volatile

/*
 * Base addresses of Memories in Micro controller(Flash, SRAM1, SRAM2, ROM, SRAM(address))
 */

#define FLASH_BASEADDR					0x08000000U

#define SRAM1_BASEADDR					0x20000000U
#define SRAM2_BASEADDR					0x2001C000U
#define SRAM_BASEADDR					SRAM1_BASEADDR

#define ROM_BASEADDR					0x1FFF0000U


/*
 * Base Addresses of AHBx and APBx bus peripherals
 */

#define APB1PERIPH_BASEADDR				0x40000000U
#define APB2PERIPH_BASEADDR				0x40010000U
#define AHB1PERIPH_BASEADDR 				0x40020000U
#define AHB2PERIPH_BASEADDR				0x50000000U
#define AHB3PERIPH_BASEADDR				0xA0000000U

/*
 * Base Addresses of AHB1 bus peripherals
 */

#define GPIOA_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR					(AHB1PERIPH_BASEADDR + 0X0400)
#define GPIOC_BASEADDR					(AHB1PERIPH_BASEADDR + 0X0800)
#define GPIOD_BASEADDR					(AHB1PERIPH_BASEADDR + 0X0C00)
#define GPIOE_BASEADDR					(AHB1PERIPH_BASEADDR + 0X1000)
#define GPIOF_BASEADDR					(AHB1PERIPH_BASEADDR + 0X1400)
#define GPIOG_BASEADDR					(AHB1PERIPH_BASEADDR + 0X1800)
#define GPIOH_BASEADDR					(AHB1PERIPH_BASEADDR + 0X1C00)
#define GPIOI_BASEADDR					(AHB1PERIPH_BASEADDR + 0X2000)
#define RCC_BASEADDR					(AHB1PERIPH_BASEADDR + 0x3800)

/*
 * Base Addresses of APB1 bus peripherals
 */

#define SPI2_BASEADDR					(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR					(APB1PERIPH_BASEADDR + 0x3C00)
#define USART2_BASEADDR					(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR					(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR					(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR					(APB1PERIPH_BASEADDR + 0x5000)
#define I2C1_BASEADDR					(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR					(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR					(APB1PERIPH_BASEADDR + 0x5C00)

/*
 * Base Addresses of APB2 bus peripherals
 */

#define USART1_BASEADDR					(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR					(APB2PERIPH_BASEADDR + 0x1400)
#define SPI1_BASEADDR					(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDRESS				(APB2PERIPH_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR					(APB2PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR					(APB2PERIPH_BASEADDR + 0x3C00)


/*
 * To define macros for all internal peripherals structures of GPIOx, we consider struct function for less repetition of declaration
 */

typedef struct
{
	 //sequence of peripherals should not be changed, becuse OP code is defined internally in this sequence

	__vo uint32_t MODER;		// Mode register
	__vo uint32_t OTYPER;		// Output type register
	__vo uint32_t OSPEEDR;		// Output speed register
	__vo uint32_t PUPDR;		// Port Pull up Pull down register
	__vo uint32_t IDR;		// Input data register
	__vo uint32_t ODR;		// Output data register
	__vo uint32_t BSRR;		// Bit set/reset register
	__vo uint32_t LCKR;		// port configuration lock register
	__vo uint32_t AFR[2];		// Alternate function register. 0 --> low and 1 ---> High
}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	uint32_t RESERVED2;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t RESERVED3[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	__vo uint32_t RESERVED4;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t RESERVED5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t RESERVED6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
}RCC_RegDef_t;

/*
 * internal Peripheral definitions (GPIOx)
 */

#define GPIOA				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF				((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG				((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH				((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI				((GPIO_RegDef_t*)GPIOI_BASEADDR)
#define RCC				((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * Clock Enable Macros for GPIOx, I2Cx, SPIx, UARTx Peripherals
 */

#define GPIOA_PCLK_ENA()		(RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_ENA()		(RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_ENA()		(RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_ENA()		(RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_ENA()		(RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_ENA()		(RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_ENA()		(RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_ENA()		(RCC->AHB1ENR |= (1<<7))
#define GPIOI_PCLK_ENA()		(RCC->AHB1ENR |= (1<<8))

#define I2C1_PCLK_ENA()			(RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_ENA()			(RCC->APB1ENR |= (1<<22))
#define I2C3_PCLK_ENA()			(RCC->APB1ENR |= (1<<23))

#define SPI1_PCLK_ENA()			(RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_ENA()			(RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_ENA()			(RCC->APB1ENR |= (1<<15))

#define USART1_PCLK_ENA()		(RCC->APB2ENR |= (1<<4))
#define USART2_PCLK_ENA()		(RCC->APB1ENR |= (1<<17))
#define USART3_PCLK_ENA()		(RCC->APB1ENR |= (1<<18))
#define UART4_PCLK_ENA()		(RCC->APB1ENR |= (1<<19))
#define UART5_PCLK_ENA()		(RCC->APB1ENR |= (1<<20))
#define USART6_PCLK_ENA()		(RCC->APB2ENR |= (1<<6))

#define SYSCFG_PCLK_ENA()		(RCC->APB2ENR |= (1<<14))

/*
 *Clock Disable Macros for GPIOx, I2Cx, SPIx, UARTx Peripherals
 */

#define GPIOA_PCLK_DIS()		(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DIS()		(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DIS()		(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DIS()		(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DIS()		(RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DIS()		(RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DIS()		(RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DIS()		(RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DIS()		(RCC->AHB1ENR &= ~(1<<8))

//I2C peripherals

#define I2C1_PCLK_DIS()			(RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DIS()			(RCC->APB1ENR &= ~(1<<22))
#define I2C3_PCLK_DIS()			(RCC->APB1ENR &= ~(1<<23))

#define SPI1_PCLK_DIS()			(RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DIS()			(RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DIS()			(RCC->APB1ENR &= ~(1<<15))

#define USART1_PCLK_DIS()		(RCC->APB2ENR &= ~(1<<4))
#define USART2_PCLK_DIS()		(RCC->APB1ENR &= ~(1<<17))
#define USART3_PCLK_DIS()		(RCC->APB1ENR &= ~(1<<18))
#define UART4_PCLK_DIS()		(RCC->APB1ENR &= ~(1<<19))
#define UART5_PCLK_DIS()		(RCC->APB1ENR &= ~(1<<20))
#define USART6_PCLK_DIS()		(RCC->APB2ENR &= ~(1<<6))

#define SYSCFG_PCLK_DIS()		(RCC->APB2ENR &= ~(1<<14))

/*
 * Some generic Macros
 */

#define ENABLE			1
#define DISABLE			0
#define SET			ENABLE
#define RESET			DISABLE
#define GPIO_PIN_SET		ENABLE
#define GPIO_PIN_RESET		DISABLE

/*
 * GPIO Resetting
 */

#define GPIOA_REG_RESET()		do{ (RCC->AHB1RSTR |= (1<<0));	(RCC->AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_REG_RESET()		do{ (RCC->AHB1RSTR |= (1<<1));	(RCC->AHB1RSTR &= ~(1<<1)); }while(0)
#define GPIOC_REG_RESET()		do{ (RCC->AHB1RSTR |= (1<<2));	(RCC->AHB1RSTR &= ~(1<<2)); }while(0)
#define GPIOD_REG_RESET()		do{ (RCC->AHB1RSTR |= (1<<3));	(RCC->AHB1RSTR &= ~(1<<3)); }while(0)
#define GPIOE_REG_RESET()		do{ (RCC->AHB1RSTR |= (1<<4));	(RCC->AHB1RSTR &= ~(1<<4)); }while(0)
#define GPIOF_REG_RESET()		do{ (RCC->AHB1RSTR |= (1<<5));	(RCC->AHB1RSTR &= ~(1<<5)); }while(0)
#define GPIOG_REG_RESET()		do{ (RCC->AHB1RSTR |= (1<<6));	(RCC->AHB1RSTR &= ~(1<<6)); }while(0)
#define GPIOH_REG_RESET()		do{ (RCC->AHB1RSTR |= (1<<7));	(RCC->AHB1RSTR &= ~(1<<7)); }while(0)
#define GPIOI_REG_RESET()		do{ (RCC->AHB1RSTR |= (1<<8));	(RCC->AHB1RSTR &= ~(1<<8)); }while(0)


#include "stm32f407xx_gpio_driver.h"


#endif /* INC_STM32F407XX_H_ */
