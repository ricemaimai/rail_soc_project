/***************************************************************************//**
 * @file
 * @brief app_process.c
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
#include "sl_component_catalog.h"
#include "rail.h"

#if defined(SL_CATALOG_KERNEL_PRESENT)
#include "app_task_init.h"
#endif

#include "stdio.h"
#include "em_device.h"
#include "em_cmu.h"
#include "em_iadc.h"
#include "em_gpio.h"
#include "sl_udelay.h"
#include "app_init.h"


// -----------------------------------------------------------------------------
//                                Defines
// -----------------------------------------------------------------------------
//LED 用の GPIO　設定
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

//クロック周波数の 設定
#define CLK_SRC_ADC_FREQ          20000000
#define CLK_ADC_FREQ              10000000

//LTC2431　用の GPIO　設定
#define LTC2431_CS_PORT   gpioPortB
#define LTC2431_CS_PIN    1
#define LTC2431_CLK_PORT  gpioPortA
#define LTC2431_CLK_PIN   6
#define LTC2431_DAT_PORT  gpioPortA
#define LTC2431_DAT_PIN   5
#define LTC2431_VREF      0.00000001f



// -----------------------------------------------------------------------------
//                          Function Prototypes
// -----------------------------------------------------------------------------

//uint32_t iadc_read_raw(uint32_t iadc_channel);


// -----------------------------------------------------------------------------
//                          Function Definitions
// -----------------------------------------------------------------------------
void initIADC(uint32_t iadc_channel)
{

  CMU_ClockEnable(cmuClock_IADC0, true);

  // Use the FSRC0 as the IADC clock so it can run in EM2
  CMU_ClockSelectSet(cmuClock_IADCCLK, cmuSelect_FSRCO);

  // Declare initialization structures
  IADC_Init_t init = IADC_INIT_DEFAULT;
  IADC_AllConfigs_t initAllConfigs = IADC_ALLCONFIGS_DEFAULT;
  IADC_InitSingle_t initSingle = IADC_INITSINGLE_DEFAULT;
  IADC_SingleInput_t initSingleInput = IADC_SINGLEINPUT_DEFAULT;

  IADC_reset(IADC0);

  CMU_ClockEnable(cmuClock_IADC0, true);

  // Use the FSRC0 as the IADC clock so it can run in EM2
  CMU_ClockSelectSet(cmuClock_IADCCLK, cmuSelect_FSRCO);


  initAllConfigs.configs[0].reference =  iadcCfgReferenceVddx;
  initAllConfigs.configs[0].vRef = 3300;
  initAllConfigs.configs[0].osrHighSpeed = iadcCfgOsrHighSpeed2x;
  initAllConfigs.configs[0].analogGain = iadcCfgAnalogGain1x;

  initAllConfigs.configs[0].adcClkPrescale = IADC_calcAdcClkPrescale(IADC0,
                                             CLK_ADC_FREQ,
                                             0,
                                             iadcCfgModeNormal,
                                             init.srcClkPrescale);

  // Allocate the analog bus for ADC0 inputs
  GPIO->CDBUSALLOC |= GPIO_CDBUSALLOC_CDODD0_ADC0;
  GPIO->CDBUSALLOC |= GPIO_CDBUSALLOC_CDEVEN0_ADC0;

  // Assign pins to positive and negative inputs in differential mode
  initSingleInput.posInput = iadc_channel;
  initSingleInput.negInput = iadcNegInputGnd;

  // Initialize IADC
  IADC_init(IADC0, &init, &initAllConfigs);

  // Initialize Single
  IADC_initSingle(IADC0, &initSingle, &initSingleInput);
}



// getting ADC value
uint32_t iadc_read_raw(void)
{
    IADC_command(IADC0, iadcCmdStartSingle);

    while (IADC0->STATUS & IADC_STATUS_CONVERTING);

    //read single data
    uint32_t result2 = IADC_readSingleData(IADC0);

    return  result2;
}

//Lchika
void LED_Blinking(){
  // LED 点滅
  GPIO_PinOutClear(LED1_PORT, LED1_PIN);
  GPIO_PinOutClear(LED2_PORT, LED2_PIN);
  sl_udelay_wait(1000000);
  GPIO_PinOutSet(LED1_PORT, LED1_PIN);
  GPIO_PinOutSet(LED2_PORT, LED2_PIN);
  sl_udelay_wait(1000000);
}

//get value of CPU's temperature
float read_cpu_temperature_celsius(void)
{
  EMU->CMD = EMU_CMD_TEMPAVGREQ;

  // 平均化完了まで待つ
  while (EMU->STATUS & EMU_STATUS_TEMPAVGACTIVE);

  uint32_t temp_raw = EMU->TEMP;
  uint32_t temp_int = (temp_raw >> 2) & 0x1FF;
  uint32_t temp_frac = temp_raw & 0x3;
  float temp_kelvin = (float)temp_int + (0.25f * temp_frac);
  float temp_celsius = temp_kelvin - 273.15f;



  //uint32_t avg_raw = (temp_raw >> 16) & 0x7ff;
  //float avg_kelvin = avg_raw * 0.25f;
  //float avg_celsius = avg_kelvin - 273.15f;


  return temp_celsius;
}



//データ出力モードの時のデータ取得関数
uint8_t spi_read_bit(void)
{
  //CLK（SCK）のピンを上げる（下げる）
  GPIO_PinOutClear(LTC2431_CLK_PORT, LTC2431_CLK_PIN);
  sl_udelay_wait(2);

  //DAT(SDO)のPIn情報を取得
  uint8_t bit = GPIO_PinInGet(LTC2431_DAT_PORT, LTC2431_DAT_PIN);

  //CLK（SCK）のピンを下げる（上げる）
  GPIO_PinOutSet(LTC2431_CLK_PORT, LTC2431_CLK_PIN);
  sl_udelay_wait(2);
  bit = ~bit;
  return bit;
}

//シングルサイクル動作
float read_ltc2431_software_spi()
{

  /////変換開始/////
  //CSピンを下げて（上げて）初期データ出力
  GPIO_PinOutSet(LTC2431_CS_PORT, LTC2431_CS_PIN);
  sl_udelay_wait(2);


  int timeout = 1000000;
  //DAT(SDO)のデータを取得もし取得できなかったら-999を返す
  while (GPIO_PinInGet(LTC2431_DAT_PORT, LTC2431_DAT_PIN) == 1 && timeout--);
  if (timeout <= 0) {
    printf("LTC2431: EOC timeout. DAT pin stuck low.\r\n");
    printf(" \r\n");
    return -999.0f;
  }

  //CSピンを上げて（下げて）初期出力終了
  GPIO_PinOutClear(LTC2431_CS_PORT, LTC2431_CS_PIN);
  sl_udelay_wait(2);


  /////EOCtest開始/////
  //CSピンを下げて（上げて）EOC
  GPIO_PinOutSet(LTC2431_CS_PORT, LTC2431_CS_PIN);

  //DAT(SDO)のデータを取得もし取得できなかったら-9999を返す
  while (GPIO_PinInGet(LTC2431_DAT_PORT, LTC2431_DAT_PIN) == 1 && timeout--);
  if (timeout <= 0) {
    printf("LTC2431: EOC timeout. DAT pin stuck low.\r\n");
    printf(" \r\n");
    return -9999.0f;
  }
  //CSピンを上げて（下げて）EOC終了
  GPIO_PinOutClear(LTC2431_CS_PORT, LTC2431_CS_PIN);
  sl_udelay_wait(4);





  /////データ出力モード/////

  //CSピンを下げてげて（上げて）出力モード開始
  GPIO_PinOutSet(LTC2431_CS_PORT, LTC2431_CS_PIN);

  uint32_t raw = 0;
  for (int i = 0; i < 24; i++) {
    raw = (raw << 1) | spi_read_bit();
  }



  //CSピンを上げて（下げて）出力モード終了
  GPIO_PinOutSet(LTC2431_CS_PORT, LTC2431_CS_PIN);
  //符号bitを取り出す
  bool sign_bit = (raw >> 21) & 0x01;
  //rowから21bitを取り出す
  uint32_t data = raw & 0x1FFFFF;
  //A/D変換したデータが正になるように変換
  int32_t signed_adc = sign_bit ? data : data - (1 << 21);
  //電圧計算
  float voltage = (signed_adc * (LTC2431_VREF / 2.0f)) / (float)(1 << 20);

  printf("LTC2431 Raw 24bit: 0x%06lX, SIGN=%d, Data=0x%05lX, Voltage: %.6f V signed_adc:%lu \r\n",
         raw, sign_bit, data, voltage, signed_adc);

  return voltage;
}









// main loop
void app_process_action(RAIL_Handle_t rail_handle)
{
    (void) rail_handle;



    //LED Blinking
    LED_Blinking();


    //get ADC value
    initIADC(AD_VA_CHANNEL);
    uint32_t adc_value_A = iadc_read_raw();

    //delay
    sl_udelay_wait(1000000);

    //get ADC value
    initIADC(AD_VB_CHANNEL);
    uint32_t adc_value_B = iadc_read_raw();


    // convert ADC value to Voltage value
    float voltage_A = (adc_value_A * 3.3f/2) / 4096.0f;
    float voltage_B = (adc_value_B * 3.3f/2) / 4096.0f;

    //get and convert cpu_CelsiusTemperture
    float cpu_temp = read_cpu_temperature_celsius();

    float ltc2431_voltage = read_ltc2431_software_spi();




    // serial output
    printf(" \r\n");
    printf("ADC Raw AD_VA: %lu, AD_VB: %lu        Voltage AD_VA: %.3f V, AD_VB: %.3f V\r\n", adc_value_A, adc_value_B, voltage_A, voltage_B);
    printf(" \r\n\r\n");
    printf("CPU Temperature: %.2f C\r\n", cpu_temp);
    printf(" \r\n\r\n\r\n\r\n");
    printf("LTC2431 Voltage: %f V\r\n", ltc2431_voltage);
    printf(" \r\n\r\n\r\n");

}



/******************************************************************************
 * RAIL callback, called if a RAIL event occurs
 *****************************************************************************/
void sl_rail_util_on_event(RAIL_Handle_t rail_handle, RAIL_Events_t events)
{
    (void) rail_handle;
    (void) events;

#if defined(SL_CATALOG_KERNEL_PRESENT)
    app_task_notify();
#endif
}
