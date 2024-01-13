/*
 * ledcpp.cpp
 *
 *  Created on: Nov 20, 2023
 *      Author: Joel
 */

#include <ledcpp.h>

#ifdef __cplusplus
extern "C" {
#endif

// Constructeur de la classe CLed
CLed::CLed(GPIO_TypeDef* port, uint16_t pin, uint16_t toggleTime)
{
    _port = port;                           // Initialisation du port GPIO
    _pin = pin;                             // Initialisation du numéro de la broche GPIO
    _toggleTime = toggleTime;               // Initialisation du temps de basculement
    counter = 0;                            // Initialisation du compteur
    lastToggleTime = HAL_GetTick();         // Initialisation du temps de basculement en utilisant le tick HAL
    off();                                  // Éteindre la LED
}

// Fonction pour exécuter le basculement de la LED
void CLed::runToggle()
{
    // Obtention du temps actuel en utilisant le tick HAL
    uint32_t currentTime = HAL_GetTick();

    // Calcul du temps écoulé depuis la dernière bascule
    uint32_t elapsedTime = currentTime - lastToggleTime;

    // Vérification si le temps écoulé est supérieur ou égal au temps de basculement
    if (elapsedTime >= _toggleTime)
    {
        counter = 0;    // Réinitialiser le compteur
        toggle();       // Bascule de la LED

        // Mettre à jour le temps de la dernière bascule
        lastToggleTime = currentTime;
    }
}

#ifdef __cplusplus
}
#endif
