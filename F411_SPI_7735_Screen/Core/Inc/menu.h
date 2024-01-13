/*
 * menu.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Joel
 */

#ifndef INC_MENU_H_
#define INC_MENU_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "st7735.h"
#include "main.h"
#include "stdio.h"


/* Private defines -----------------------------------------------------------*/
#define SCREEN_WIDTH  160
#define SCREEN_HEIGHT 80

// Couleurs
#define COLOR_BG        ST7735_BLACK
#define COLOR_RECT      ST7735_BLUE
#define COLOR_TEXT      ST7735_WHITE
#define COLOR_SELECTED  ST7735_YELLOW

// Coordonnées des rectangles
#define RECT_WIDTH  140
#define RECT_HEIGHT 20
#define RECT_SPACING 10

// Coordonnées des rectangles
#define RECT_X  (SCREEN_WIDTH / 2 - RECT_WIDTH / 2)
#define RECT_Y1 (10)
#define RECT_Y2 (RECT_Y1 + RECT_HEIGHT + RECT_SPACING)
#define RECT_Y3 (RECT_Y2 + RECT_HEIGHT + RECT_SPACING)
#define RECT_Y4 (RECT_Y3 + RECT_HEIGHT + RECT_SPACING)

// Bouton poussoir utilisé
#define Push_Btn_Pin GPIO_PIN_13
#define Push_Btn_GPIO GPIOC

// Définir un délai de rebond (en millisecondes)
#define DEBOUNCE_DELAY 50

#define BAR_WIDTH 120
#define BAR_HEIGHT 20
#define BAR_X (SCREEN_WIDTH / 2 - BAR_WIDTH / 2)
#define BAR_Y (SCREEN_HEIGHT / 2 - BAR_HEIGHT / 2)
#define TEXT_HEIGHT 12

// Constants for ADC configuration
#define ADC_CHANNEL     ADC_CHANNEL_0  // ADC channel you are using
#define ADC_RESOLUTION  4095           // Maximum ADC value for 12-bit resolution
#define MAX_BAR_VALUE   100            // Maximum value for the bar graph

//extern const uint16_t test_img_160x80[][160];


void drawMenu(void);
void navigateMenu(int direction);
void menu_demo(void);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void executeMenuFunction(int menuItem);
void drawBarGraph(float value);
uint32_t ReadAndConvertADC(void);

#ifdef __cplusplus
}
#endif
#endif /* INC_MENU_H_ */
