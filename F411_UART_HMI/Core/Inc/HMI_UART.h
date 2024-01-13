/**
 * @file HMI_UART.h
 * @brief Fonctions pour l'interface UART de l'interface homme-machine.
 * @date Sep 8, 2023
 * @author Joel Imbaud
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_HMI_UART_H_
#define INC_HMI_UART_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>

/* Exported functions prototypes ---------------------------------------------*/

HAL_StatusTypeDef HMI_UART_ReceiveString(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
void HMI_UART_ClearConsole(UART_HandleTypeDef *huart);
void HMI_UART_Init(UART_HandleTypeDef *huart);
void HMI_UART_Error(void);
void HMI_UART_interface(UART_HandleTypeDef *huart);

#endif /* INC_HMI_UART_H_ */
