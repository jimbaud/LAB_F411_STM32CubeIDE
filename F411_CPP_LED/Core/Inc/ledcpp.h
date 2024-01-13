/*
 * ledcpp.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Joel
 */

#ifndef INC_LEDCPP_H_
#define INC_LEDCPP_H_

#include "stm32f4xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

// Déclaration de la classe CLed
class CLed
{
    GPIO_TypeDef* _port;      // GPIOA, GPIOB, etc.
    uint16_t _pin;            // GPIO_PIN_0, GPIO_PIN_1, etc.
    uint16_t _toggleTime;     // Temps de basculement en ms
    uint32_t lastToggleTime;  // Dernier temps de basculement
    uint16_t counter;         // Compteur de temps de basculement

    // Fonctions privées pour manipuler la LED
    void on() { HAL_GPIO_WritePin(_port, _pin, GPIO_PIN_SET); }    // Allumer la LED
    void off() { HAL_GPIO_WritePin(_port, _pin, GPIO_PIN_RESET); } // Éteindre la LED
    void toggle() { HAL_GPIO_TogglePin(_port, _pin); }             // Bascule de la LED

public:
    // Constructeur de la classe CLed
    CLed(GPIO_TypeDef* port, uint16_t pin, uint16_t toggleTime);

    // Fonction pour exécuter le basculement de la LED
    void runToggle();
};

#ifdef __cplusplus
}
#endif

#endif /* INC_LEDCPP_H_ */

