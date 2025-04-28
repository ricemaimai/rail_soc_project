/***************************************************************************//**
 * @file
 * @brief app_init.c
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

// -----------------------------------------------------------------------------
//                                   Includes
// -----------------------------------------------------------------------------
#include "sl_rail_util_init.h"
#include <stdio.h>
#include "uartdrv.h"

#include "stdio.h"
#include "em_device.h"
#include "em_cmu.h"
#include "em_iadc.h"
#include "em_gpio.h"
#include "sl_udelay.h"


// -----------------------------------------------------------------------------
//                                Defines
// -----------------------------------------------------------------------------
#define LED1_PORT gpioPortA
#define LED1_PIN  7
#define LED2_PORT gpioPortA
#define LED2_PIN  8


//ADC 用の PIN設定
#define AD_VA_CHANNEL iadcPosInputPortCPin2 // PC02 = IADC0_SCAN10POS
#define AD_VB_CHANNEL iadcPosInputPortCPin3   // PC03 = IADC0_SCAN0POS

// AVDD_EN 用の GPIO 設定
#define AVDD_EN_PORT gpioPortD
#define AVDD_EN_PIN  3
#define AVDD_VOLTAGE 3.3f


#define CLK_SRC_ADC_FREQ          20000000
#define CLK_ADC_FREQ              10000000

//LTC2431　用の GPIO　設定
#define LTC2431_CS_PORT   gpioPortB
#define LTC2431_CS_PIN    1
#define LTC2431_CLK_PORT  gpioPortA
#define LTC2431_CLK_PIN   6
#define LTC2431_DAT_PORT  gpioPortA
#define LTC2431_DAT_PIN   5




// -----------------------------------------------------------------------------
//                              Macros and Typedefs
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                          Static Function Declarations
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                                Global Variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                                Static Variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                          Public Function Definitions
// -----------------------------------------------------------------------------
/******************************************************************************
 * The function is used for some basic initialization related to the app.
 *****************************************************************************/
void avdd_enable(void)
{
    CMU_ClockEnable(cmuClock_GPIO, true);

    GPIO_PinOutSet(AVDD_EN_PORT, AVDD_EN_PIN);
    //GPIO_PinOutClear(AVDD_EN_PORT, AVDD_EN_PIN);



    sl_udelay_wait(1000); // 少し待機して安定させる（1ms）
}

void iadc_gpio_init(void)
{
    // PC02 / PC03 を IADC 入力モードに設定
    CMU_ClockEnable(cmuClock_GPIO, true);
    GPIO_PinOutSet(gpioPortC, 2); // PC02 (AD_VA)
    GPIO_PinOutSet(gpioPortC, 3); // PC03 (AD_VB)
}

void ltc2431_gpio_init(void)
{
    CMU_ClockEnable(cmuClock_GPIO, true);

    // CS: PB01 → 初期Highで変換スタンバイ
    GPIO_PinOutClear(gpioPortB, 1);

    // CLK: PA06 → 初期Low（アイドル）
    GPIO_PinOutSet(gpioPortA, 6);

    // DAT: PA05 → 入力
    GPIO_PinOutClear(gpioPortA, 5);
}





RAIL_Handle_t app_init(void)
{
  // Get RAIL handle, used later by the application
  RAIL_Handle_t rail_handle = sl_rail_util_get_handle(SL_RAIL_UTIL_HANDLE_INST0);
  sl_iostream_init_instances();

  printf("hello\n");

  printf("IADC Initialized\n");

  avdd_enable();
  iadc_gpio_init();
  ltc2431_gpio_init();





  /////////////////////////////////////////////////////////////////////////////
  // Put your application init code here!                                    //
  // This is called once during start-up.                                    //
  /////////////////////////////////////////////////////////////////////////////

  return rail_handle;
}

// -----------------------------------------------------------------------------
//                          Static Function Definitions
// -----------------------------------------------------------------------------
