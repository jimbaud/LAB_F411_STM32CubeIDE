/**
  ******************************************************************************
  * @file    temperature_controller.c
  * @brief   This file provides functions for temperature control.
  * @author  Joel
  ******************************************************************************
 */

#include "temperature_controller.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

// Déclaration des variables statiques utilisées dans tout le fichier
static UART_HandleTypeDef *huart2; /**< Pointer to the UART_HandleTypeDef structure for UART communication. */
static ADC_HandleTypeDef *hadc1; /**< Pointer to the ADC_HandleTypeDef structure for analog-to-digital conversion. */
static GPIO_TypeDef *ld2GpioPort; /**< Pointer to the GPIO_TypeDef structure for the LED port. */
static uint16_t ld2GpioPin; /**< LED pin. */
static char clearScreen[] = "\e[1;1H\e[2J"; /**< Clear screen command. */
static char output[100]; /**< Output buffer. */
static char inputBuffer[5]; /**< Input buffer. */
static double T; /**< Temperature variable. */
static float MaxTemp, MinTemp; /**< Maximum and minimum temperature thresholds. */

/**
 * @brief Initializes the temperature controller.
 *
 * @param huart Pointer to the UART_HandleTypeDef structure for UART communication.
 * @param hadc Pointer to the ADC_HandleTypeDef structure for analog-to-digital conversion.
 * @param gpioPort Pointer to the GPIO_TypeDef structure for the LED port.
 * @param gpioPin LED pin.
 */
void initTemperatureController(UART_HandleTypeDef *huart, ADC_HandleTypeDef *hadc, GPIO_TypeDef *gpioPort, uint16_t gpioPin) {
    huart2 = huart;
    hadc1 = hadc;
    ld2GpioPort = gpioPort;
    ld2GpioPin = gpioPin;
}

/**
 * @brief Starts the temperature controller.
 *
 * This function initializes the temperature controller by prompting the user
 * to enter the maximum and minimum temperature values. Then, it enters an
 * infinite loop where it measures the temperature, compares it with the
 * maximum and minimum values, turns on the LED accordingly, and displays
 * information on the UART console.
 */
void startTemperatureController(void) {
    // Initialisation du contrôleur de température
    HAL_UART_Transmit(huart2, (uint8_t*)clearScreen, strlen(clearScreen), HAL_MAX_DELAY);

    // Positionne le curseur en haut à gauche de l'écran
    char homeCursor[] = {0x1B, '[', 'H', 0};
    HAL_UART_Transmit(huart2, (uint8_t*)homeCursor, sizeof(homeCursor), HAL_MAX_DELAY);

    // Demande à l'utilisateur d'entrer la température maximale
    char maxTempMsg[] = "\r\nEntrer Max temperature XX.XX : ";
    HAL_UART_Transmit(huart2, (uint8_t*)maxTempMsg, strlen(maxTempMsg), HAL_MAX_DELAY);
    HAL_UART_Receive(huart2, (uint8_t*)inputBuffer, sizeof(inputBuffer), HAL_MAX_DELAY);
    MaxTemp = strtof(inputBuffer, NULL);

    // Demande à l'utilisateur d'entrer la température minimale
    char minTempMsg[] = "\r\nEntrer Min temperature XX.XX : ";
    HAL_UART_Transmit(huart2, (uint8_t*)minTempMsg, strlen(minTempMsg), HAL_MAX_DELAY);
    HAL_UART_Receive(huart2, (uint8_t*)inputBuffer, sizeof(inputBuffer), HAL_MAX_DELAY);
    MinTemp = strtof(inputBuffer, NULL);

    while (1) {
        HAL_ADC_Start(hadc1);
        HAL_StatusTypeDef conv = HAL_ADC_PollForConversion(hadc1, 100);

        if (conv != HAL_OK) {
            // Gestion d'une éventuelle erreur de conversion ADC
            char errorMsg[30];
            snprintf(errorMsg, sizeof(errorMsg), "ADC ERROR!\r\nError code: %i", conv);
            HAL_UART_Transmit(huart2, (uint8_t*)errorMsg, strlen(errorMsg), HAL_MAX_DELAY);
        }

        // Calcul de la température en degrés Celsius
        T = (HAL_ADC_GetValue(hadc1) * 330.0) / 4096.0;

        // Positionne le curseur pour afficher les informations de température
        char gotoScr[] = {0x1B, '[', '7', ';', '0', 'H', 0};
        HAL_UART_Transmit(huart2, (uint8_t*)gotoScr, sizeof(gotoScr), HAL_MAX_DELAY);

        // Compare la température avec les seuils et prend des actions appropriées
        if (T < MaxTemp && T > MinTemp) {
            char normalMsg[] = "Normal - Temperature     = ";
            HAL_UART_Transmit(huart2, (uint8_t*)normalMsg, strlen(normalMsg), HAL_MAX_DELAY);
            HAL_GPIO_WritePin(ld2GpioPort, ld2GpioPin, GPIO_PIN_RESET);  // Éteint la LED
        } else if (T >= MaxTemp) {
            char highTempMsg[] = "Alarm High - Temperature = ";
            HAL_UART_Transmit(huart2, (uint8_t*)highTempMsg, strlen(highTempMsg), HAL_MAX_DELAY);
            HAL_GPIO_WritePin(ld2GpioPort, ld2GpioPin, GPIO_PIN_SET);  // Allume la LED
        } else if (T <= MinTemp) {
            char lowTempMsg[] = "Alarm low - Temperature  = ";
            HAL_UART_Transmit(huart2, (uint8_t*)lowTempMsg, strlen(lowTempMsg), HAL_MAX_DELAY);
            HAL_GPIO_WritePin(ld2GpioPort, ld2GpioPin, GPIO_PIN_SET);  // Allume la LED
        }

        // Affiche la température sur la console
        snprintf(output, sizeof(output), "%5.2f", T);
        HAL_UART_Transmit(huart2, (uint8_t*)output, strlen(output), HAL_MAX_DELAY);
        HAL_Delay(1000);  // Pause d'une seconde
    }
}
