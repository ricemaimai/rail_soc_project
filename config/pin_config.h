#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[CMU]
// [CMU]$

// $[LFXO]
// [LFXO]$

// $[PRS.ASYNCH0]
// [PRS.ASYNCH0]$

// $[PRS.ASYNCH1]
// [PRS.ASYNCH1]$

// $[PRS.ASYNCH2]
// [PRS.ASYNCH2]$

// $[PRS.ASYNCH3]
// [PRS.ASYNCH3]$

// $[PRS.ASYNCH4]
// [PRS.ASYNCH4]$

// $[PRS.ASYNCH5]
// [PRS.ASYNCH5]$

// $[PRS.ASYNCH6]
// [PRS.ASYNCH6]$

// $[PRS.ASYNCH7]
// [PRS.ASYNCH7]$

// $[PRS.ASYNCH8]
// [PRS.ASYNCH8]$

// $[PRS.ASYNCH9]
// [PRS.ASYNCH9]$

// $[PRS.ASYNCH10]
// [PRS.ASYNCH10]$

// $[PRS.ASYNCH11]
// [PRS.ASYNCH11]$

// $[PRS.SYNCH0]
// [PRS.SYNCH0]$

// $[PRS.SYNCH1]
// [PRS.SYNCH1]$

// $[PRS.SYNCH2]
// [PRS.SYNCH2]$

// $[PRS.SYNCH3]
// [PRS.SYNCH3]$

// $[GPIO]
// [GPIO]$

// $[TIMER0]
// [TIMER0]$

// $[TIMER1]
// [TIMER1]$

// $[TIMER2]
// [TIMER2]$

// $[TIMER3]
// [TIMER3]$

// $[TIMER4]
// [TIMER4]$

// $[USART0]
// [USART0]$

// $[I2C1]
// [I2C1]$

// $[EUSART1]
// EUSART1 RX on PC06
#ifndef EUSART1_RX_PORT                         
#define EUSART1_RX_PORT                          gpioPortC
#endif
#ifndef EUSART1_RX_PIN                          
#define EUSART1_RX_PIN                           6
#endif

// EUSART1 TX on PC05
#ifndef EUSART1_TX_PORT                         
#define EUSART1_TX_PORT                          gpioPortC
#endif
#ifndef EUSART1_TX_PIN                          
#define EUSART1_TX_PIN                           5
#endif

// [EUSART1]$

// $[EUSART2]
// [EUSART2]$

// $[KEYSCAN]
// [KEYSCAN]$

// $[LETIMER0]
// [LETIMER0]$

// $[IADC0]
// [IADC0]$

// $[ACMP0]
// [ACMP0]$

// $[ACMP1]
// [ACMP1]$

// $[VDAC0]
// [VDAC0]$

// $[PCNT0]
// [PCNT0]$

// $[LESENSE]
// [LESENSE]$

// $[HFXO0]
// [HFXO0]$

// $[I2C0]
// [I2C0]$

// $[EUSART0]
// EUSART0 CTS on PA00
#ifndef EUSART0_CTS_PORT                        
#define EUSART0_CTS_PORT                         gpioPortA
#endif
#ifndef EUSART0_CTS_PIN                         
#define EUSART0_CTS_PIN                          0
#endif

// EUSART0 RTS on PA06
#ifndef EUSART0_RTS_PORT                        
#define EUSART0_RTS_PORT                         gpioPortA
#endif
#ifndef EUSART0_RTS_PIN                         
#define EUSART0_RTS_PIN                          6
#endif

// EUSART0 RX on PA04
#ifndef EUSART0_RX_PORT                         
#define EUSART0_RX_PORT                          gpioPortA
#endif
#ifndef EUSART0_RX_PIN                          
#define EUSART0_RX_PIN                           4
#endif

// EUSART0 TX on PA05
#ifndef EUSART0_TX_PORT                         
#define EUSART0_TX_PORT                          gpioPortA
#endif
#ifndef EUSART0_TX_PIN                          
#define EUSART0_TX_PIN                           5
#endif

// [EUSART0]$

// $[PTI]
// [PTI]$

// $[MODEM]
// [MODEM]$

// $[CUSTOM_PIN_NAME]
#ifndef CTS_PORT                                
#define CTS_PORT                                 gpioPortA
#endif
#ifndef CTS_PIN                                 
#define CTS_PIN                                  0
#endif

#ifndef _PORT                                   
#define _PORT                                    gpioPortA
#endif
#ifndef _PIN                                    
#define _PIN                                     1
#endif

#ifndef eusart0_rx_PORT                         
#define eusart0_rx_PORT                          gpioPortA
#endif
#ifndef eusart0_rx_PIN                          
#define eusart0_rx_PIN                           4
#endif

#ifndef eusart0_tx_PORT                         
#define eusart0_tx_PORT                          gpioPortA
#endif
#ifndef eusart0_tx_PIN                          
#define eusart0_tx_PIN                           5
#endif

#ifndef RTS_PORT                                
#define RTS_PORT                                 gpioPortA
#endif
#ifndef RTS_PIN                                 
#define RTS_PIN                                  6
#endif

#ifndef UART2_PORT                              
#define UART2_PORT                               gpioPortC
#endif
#ifndef UART2_PIN                               
#define UART2_PIN                                5
#endif

#ifndef UART1_PORT                              
#define UART1_PORT                               gpioPortC
#endif
#ifndef UART1_PIN                               
#define UART1_PIN                                6
#endif

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

