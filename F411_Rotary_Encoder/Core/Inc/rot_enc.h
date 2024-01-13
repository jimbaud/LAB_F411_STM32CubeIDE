/***************************************************
* Module name: ENC
*
* Copyright 2016 Company as an unpublished work.
* All Rights Reserved.
*
* The information contained herein is confidential
* property of Company. The user, copying, transfer or
* disclosure of such information is prohibited except
* by express written agreement with Company.
*
* First written on 01.03.2016 by BogTog.
*
* Module Description:
* Driver for using a quadrature signal rotary encoder
* with STM32 uController
*
***************************************************/
#ifndef __ENC
#define __ENC

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "main.h"

/* Exported types ------------------------------------------------------------*/

/* Defines -------------------------------------------------------------------*/
/* Rotary encoder PIN */ 
#define ENC_A_Pin RB_DT_Pin
#define ENC_B_Pin RB_clock_Pin

/* Rotary encoder PORT */
#define ENC_A_GPIO_Port RB_DT_GPIO_Port
#define ENC_B_GPIO_Port RB_clock_GPIO_Port
	
#define ENC_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOD_CLK_ENABLE()  
#define ENC_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOD_CLK_DISABLE()

/* Exported constants --------------------------------------------------------*/
typedef enum{
	left = 0, 
	right = 1
}ENC_tenDir;
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/**************************************************/
/* Function Prototype Section
* Add prototypes for all functions called by this
* module, with the exception of runtime routines.
*
***************************************************/
void ENC_vInit(void);
void ENC__vINT_Handler(void);
#ifdef __cplusplus
}
#endif

#endif /* __ENC */
