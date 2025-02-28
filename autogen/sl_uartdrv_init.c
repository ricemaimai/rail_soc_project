#include "uartdrv.h"
#include "sl_uartdrv_instances.h"
#include <stddef.h>

#include "sl_uartdrv_eusart_inst_config.h"

UARTDRV_HandleData_t sl_uartdrv_eusart_inst_handle_data;
UARTDRV_Handle_t sl_uartdrv_eusart_inst_handle = &sl_uartdrv_eusart_inst_handle_data;


static UARTDRV_Handle_t sli_uartdrv_default_handle = NULL;

/* If CTS and RTS not defined, define a default value to avoid errors */
#ifndef SL_UARTDRV_EUSART_INST_CTS_PORT
#define SL_UARTDRV_EUSART_INST_CTS_PORT  gpioPortA
#define SL_UARTDRV_EUSART_INST_CTS_PIN   0
#endif

#ifndef SL_UARTDRV_EUSART_INST_RTS_PORT
#define SL_UARTDRV_EUSART_INST_RTS_PORT  gpioPortA
#define SL_UARTDRV_EUSART_INST_RTS_PIN   0
#endif


/* Define RX and TX buffer queues */
DEFINE_BUF_QUEUE(SL_UARTDRV_EUSART_INST_RX_BUFFER_SIZE, sl_uartdrv_eusart_inst_rx_buffer);
DEFINE_BUF_QUEUE(SL_UARTDRV_EUSART_INST_TX_BUFFER_SIZE, sl_uartdrv_eusart_inst_tx_buffer);


/* Create uartdrv initialization structs */
UARTDRV_InitEuart_t sl_uartdrv_eusart_init_inst = {   
  .port = SL_UARTDRV_EUSART_INST_PERIPHERAL,
  .useLowFrequencyMode = SL_UARTDRV_EUSART_INST_LF_MODE,
  .baudRate = SL_UARTDRV_EUSART_INST_BAUDRATE,
  .txPort = SL_UARTDRV_EUSART_INST_TX_PORT,
  .rxPort = SL_UARTDRV_EUSART_INST_RX_PORT,
  .txPin = SL_UARTDRV_EUSART_INST_TX_PIN,
  .rxPin = SL_UARTDRV_EUSART_INST_RX_PIN,
  .uartNum = SL_UARTDRV_EUSART_INST_PERIPHERAL_NO,
  .stopBits = SL_UARTDRV_EUSART_INST_STOP_BITS,
  .parity = SL_UARTDRV_EUSART_INST_PARITY,
  .oversampling = SL_UARTDRV_EUSART_INST_OVERSAMPLING,
  .mvdis = SL_UARTDRV_EUSART_INST_MVDIS,
  .fcType = SL_UARTDRV_EUSART_INST_FLOW_CONTROL_TYPE,
  .ctsPort = SL_UARTDRV_EUSART_INST_CTS_PORT,
  .ctsPin = SL_UARTDRV_EUSART_INST_CTS_PIN,
  .rtsPort = SL_UARTDRV_EUSART_INST_RTS_PORT,
  .rtsPin = SL_UARTDRV_EUSART_INST_RTS_PIN,
  .rxQueue = (UARTDRV_Buffer_FifoQueue_t *)&sl_uartdrv_eusart_inst_rx_buffer,
  .txQueue = (UARTDRV_Buffer_FifoQueue_t *)&sl_uartdrv_eusart_inst_tx_buffer,
};


void sl_uartdrv_init_instances(void){
  UARTDRV_InitEuart(sl_uartdrv_eusart_inst_handle, &sl_uartdrv_eusart_init_inst);
  sl_uartdrv_set_default(sl_uartdrv_eusart_inst_handle);
}

sl_status_t sl_uartdrv_set_default(UARTDRV_Handle_t handle)
{
  sl_status_t status = SL_STATUS_INVALID_HANDLE;

  if (handle != NULL) {
    sli_uartdrv_default_handle = handle;
    status = SL_STATUS_OK;
  }

  return status;
}

UARTDRV_Handle_t sl_uartdrv_get_default(void)
{
  return sli_uartdrv_default_handle;
}
