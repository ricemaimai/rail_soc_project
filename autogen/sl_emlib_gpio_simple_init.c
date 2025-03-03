#include "sl_emlib_gpio_simple_init.h"
#include "sl_emlib_gpio_init_LED1_config.h"
#include "sl_emlib_gpio_init_LED2_config.h"
#include "em_gpio.h"
#include "em_cmu.h"

void sl_emlib_gpio_simple_init(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(SL_EMLIB_GPIO_INIT_LED1_PORT,
                  SL_EMLIB_GPIO_INIT_LED1_PIN,
                  SL_EMLIB_GPIO_INIT_LED1_MODE,
                  SL_EMLIB_GPIO_INIT_LED1_DOUT);

  GPIO_PinModeSet(SL_EMLIB_GPIO_INIT_LED2_PORT,
                  SL_EMLIB_GPIO_INIT_LED2_PIN,
                  SL_EMLIB_GPIO_INIT_LED2_MODE,
                  SL_EMLIB_GPIO_INIT_LED2_DOUT);
}
