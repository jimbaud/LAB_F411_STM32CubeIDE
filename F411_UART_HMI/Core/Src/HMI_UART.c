/**
 * @file HMI_UART.c
 * @brief Fonctions pour l'interface UART de l'interface homme-machine.
 * @date Sep 8, 2023
 * @author Joel Imbaud
 */

#include "HMI_UART.h"

#define MAX_STRING_SIZE 256
#define MAX_NAME_SIZE 32
#define MAX_AGE_SIZE 8

/**
 * @brief Fonction de réception d'une chaîne de caractères depuis l'UART.
 *
 * Cette fonction reçoit une chaîne de caractères depuis l'UART, traitant les caractères de contrôle et effectuant l'écho des caractères reçus.
 *
 * @param huart     Pointeur vers la structure UART_HandleTypeDef pour l'UART à utiliser.
 * @param pData     Pointeur vers le tableau où stocker la chaîne de caractères reçue.
 * @param Size      Taille maximale de la chaîne de caractères à recevoir.
 * @param Timeout   Délai maximal d'attente pour la réception.
 * @return HAL_StatusTypeDef  État de la réception.
 */

HAL_StatusTypeDef HMI_UART_ReceiveString(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout) {

	const char newline[] = "\r\n";  // Séquence de saut de ligne
	const char delete[] = "\x08 \x08";  // Séquence pour effacer un caractère
	HAL_StatusTypeDef status;

	if (Size == 0)
		return HAL_ERROR;  // Taille invalide

	int i = 0;

	for (;;) {
		status = HAL_UART_Receive(huart, &pData[i], 1, Timeout);

		if (status != HAL_OK)
			return status;  // Erreur de réception

		if ((pData[i] == '\x08') || (pData[i] == '\x7F')) { // backspace
			if (i > 0) {
				status = HAL_UART_Transmit(huart, (uint8_t*)delete, sizeof(delete)-1, Timeout);
				if (status != HAL_OK)
					return status;  // Erreur d'envoi

				i--;
			}
			continue;
		}

		if ((pData[i] == '\r') || (pData[i] == '\n')) {
			pData[i] = '\0';  // Remplace le caractère de fin de ligne par le caractère nul
			status = HAL_UART_Transmit(huart, (uint8_t*)newline, sizeof(newline)-1, Timeout);
			if (status != HAL_OK)
				return status;  // Erreur d'envoi
			break;
		}

		if (i == (Size - 1))
			continue;  // Ignorer le dernier caractère réservé pour le caractère nul

		status = HAL_UART_Transmit(huart, &pData[i], 1, Timeout);
		if (status != HAL_OK)
			return status;  // Erreur d'envoi
		i++;
	}

	return HAL_OK;  // Réception et traitement réussis
}

/**
 * @brief Fonction pour effacer la console via l'UART.
 *
 * Cette fonction envoie une séquence ANSI pour effacer l'écran de la console et positionner le curseur en haut à gauche.
 *
 * @param huart     Pointeur vers la structure UART_HandleTypeDef pour l'UART à utiliser.
 */

void HMI_UART_ClearConsole(UART_HandleTypeDef *huart) {
	const char clearScreen[] = "\x1B[2J\x1B[H";  // Séquence ANSI pour effacer l'écran et positionner le curseur en haut à gauche
	HAL_UART_Transmit(huart, (uint8_t*)clearScreen, sizeof(clearScreen)-1, HAL_MAX_DELAY);
}

/**
 * @brief Fonction d'initialisation de l'interface homme-machine.
 *
 * Cette fonction initialise l'interface homme-machine en effaçant la console et en envoyant un message "Ready!".
 *
 * @param huart     Pointeur vers la structure UART_HandleTypeDef pour l'UART à utiliser.
 */

void HMI_UART_Init(UART_HandleTypeDef *huart) {
	HMI_UART_ClearConsole(huart);  // Efface la console au démarrage
	const char ready[] = "Ready!\r\n";  // Message de démarrage
	HAL_UART_Transmit(huart, (uint8_t*)ready, sizeof(ready)-1, HAL_MAX_DELAY);
}

/**
 * @brief Fonction de gestion des erreurs.
 *
 * Cette fonction effectue une attente infinie en cas d'erreur.
 */

void HMI_UART_Error(void) {

	HAL_Delay(HAL_MAX_DELAY);  // Fonction de gestion des erreurs
}

/**
 * @brief Fonction principale de l'interface utilisateur via UART.
 *
 * Cette fonction gère l'interaction utilisateur via UART en posant des questions, recevant des réponses
 * et renvoyant une phrase construite avec les informations reçues.
 *
 * @param huart     Pointeur vers la structure UART_HandleTypeDef pour l'UART à utiliser.
 */

void HMI_UART_interface(UART_HandleTypeDef *huart) {

	HAL_StatusTypeDef status;

	char buffer[MAX_STRING_SIZE];  // Tampon pour stocker les réponses
	char name[MAX_NAME_SIZE];
	char firstname[MAX_NAME_SIZE];
	char age[MAX_AGE_SIZE];

	// Tableaux de questions pour les réponses
	const char questions[][64] = {
			"Quel est votre nom?\r\n",
			"Quel est votre prenom?\r\n",
			"Quel est votre age?\r\n"
	};

	for (int i = 0; i < 3; i++) {
		// Envoi de la question via l'UART
		status = HAL_UART_Transmit(huart, (uint8_t*)questions[i], strlen(questions[i]), HAL_MAX_DELAY);
		if (status != HAL_OK)
			HMI_UART_Error();  // Gestion d'erreur

		// Réception de la réponse depuis l'UART
		status = HMI_UART_ReceiveString(huart, (uint8_t*)buffer, sizeof(buffer), HAL_MAX_DELAY);
		if (status != HAL_OK)
			HMI_UART_Error();  // Gestion d'erreur

		if (i == 0) {
			strcpy(name, buffer);  // Stocke le nom
		} else if (i == 1) {
			strcpy(firstname, buffer);  // Stocke le prénom
		} else if (i == 2) {
			strcpy(age, buffer);  // Stocke l'âge
		}
	}

	// Construction de la phrase avec les informations obtenues
	char sentence[256];
	sprintf(sentence, "Vous vous appelez %s %s et vous avez %s an(s)\r\n", firstname, name, age);

	// Envoi de la phrase via l'UART
	status = HAL_UART_Transmit(huart, (uint8_t*)sentence, strlen(sentence), HAL_MAX_DELAY);
	if (status != HAL_OK)
		HMI_UART_Error();  // Gestion d'erreur

	HAL_Delay(100);  // Attente de 100 millisecondes
}
