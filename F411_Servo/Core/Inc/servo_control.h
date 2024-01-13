/*
 * servo_control.h
 *
 *  Created on: Dec 11, 2023
 *      Author: Joel
 */

#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include "stm32f4xx_hal.h"
#include "main.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

extern unsigned char MSG1[4]; // Variable globale du buffer de réception
extern UART_HandleTypeDef huart2;

/**
 * @file
 * @brief Servo Control API
 *
 * This header file provides an API for controlling a servo motor using PWM.
 */

/**
 * @brief Initialize PWM for servo control.
 *
 * This function initializes the PWM for servo control.
 *
 * @param htim Pointer to the TIM_HandleTypeDef structure for PWM configuration.
 * @param channel PWM channel used for servo control.
 */
void Servo_Init(TIM_HandleTypeDef *htim, uint32_t channel);

/**
 * @brief Set the servo position.
 *
 * This function sets the servo position based on the desired angle.
 *
 * @param angle Desired angle for the servo (0 to 180 degrees).
 */
void Servo_SetPosition(uint8_t angle);

/**
 * @brief Callback function for handling UART receive interrupt.
 *
 * This function is called when a UART receive interrupt occurs.
 * It processes the received data and sets the servo angle accordingly.
 *
 * @param huart Pointer to the UART_HandleTypeDef structure for UART communication.
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

/**
 * @brief Test the servo PWM time settings.
 *
 * This function tests the servo PWM time settings by varying the PWM time
 * from start to stop values.
 *
 * @param start Start value for PWM time.
 * @param stop Stop value for PWM time.
 */
void Servo_Test_TimeSet(int start, int stop);

#endif /* SERVO_CONTROL_H */
