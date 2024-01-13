/**
 ******************************************************************************
 * @file    app_bluenrg_ms.c
 * @author  SRA Application Team
 * @brief   BlueNRG-M0 initialization and applicative code
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "app_bluenrg_ms.h"

#include "hci.h"
#include "hci_le.h"
#include "hci_tl.h"
#include "link_layer.h"
#include "sensor.h"
#include "gatt_db.h"

#include "compiler.h"
#include "bluenrg_utils.h"
#include "bluenrg_gap.h"
#include "bluenrg_gap_aci.h"
#include "bluenrg_gatt_aci.h"
#include "bluenrg_hal_aci.h"
#include "sm.h"
#include "stm32f4xx_hal_tim.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private defines -----------------------------------------------------------*/
/**
 * 1 to send environmental and motion data when pushing the user button
 * 0 to send environmental and motion data automatically (period = 1 sec)
 */
#define USE_BUTTON 1

/* Private macros ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

extern volatile uint8_t set_connectable;
extern volatile int     connected;

//uint8_t bnrg_expansion_board = IDB05A1;
uint8_t bdaddr[BDADDR_SIZE];
static volatile uint8_t user_button_init_state = 1;
static volatile uint8_t user_button_pressed = 0;

/* Private function prototypes -----------------------------------------------*/
static void User_Process(void);
static void User_Init(void);
static void Set_Random_Environmental_Values(float *data_t, float *data_p);
static void Set_Random_Motion_Values(uint32_t cnt);
static void Reset_Motion_Values(void);


void MX_BlueNRG_MS_Init(void)
{

	/* Initialize the peripherals and the BLE Stack */
	const char *name = "BlueNRG";
	uint16_t service_handle, dev_name_char_handle, appearance_char_handle;

	uint8_t  bdaddr_len_out;
	User_Init();
	hci_init(user_notify, NULL);

	//	Reset BlueNRG to be able to change its MAC address.

	hci_reset();
	HAL_Delay(100);
	aci_hal_read_config_data(CONFIG_DATA_RANDOM_ADDRESS, BDADDR_SIZE, &bdaddr_len_out, bdaddr);

	/* GATT Init */
	aci_gatt_init();

	/* GAP Init */
	aci_gap_init_IDB05A1(GAP_PERIPHERAL_ROLE_IDB05A1, 0, 0x07, &service_handle, &dev_name_char_handle, &appearance_char_handle);

	/* Update device name */
	aci_gatt_update_char_value(service_handle, dev_name_char_handle, 0,
			strlen(name), (uint8_t *)name);

	aci_gap_set_auth_requirement(MITM_PROTECTION_REQUIRED,
			OOB_AUTH_DATA_ABSENT,
			NULL,
			7,
			16,
			USE_FIXED_PIN_FOR_PAIRING,
			123456,
			BONDING);
	Add_HWServW2ST_Service();
	Add_SWServW2ST_Service();

	/* Set output power level */
	aci_hal_set_tx_power_level(1,4);
}

/*
 * BlueNRG-MS background task
 */
void MX_BlueNRG_MS_Process(void)
{
	User_Process();
	hci_user_evt_proc();
}



static void User_Process(void)
{
	float data_t;
	float data_p;
	static uint32_t counter = 0;

	if (set_connectable)
	{
		Set_DeviceConnectable();
		set_connectable = FALSE;
	}

	if (connected)
	{

	}
}



//void BSP_PB_Callback(Button_TypeDef Button)
//{
//	/* Set the User Button flag */
//	user_button_pressed = 1;
//}
