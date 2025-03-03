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
// EUSART1 CTS on PC07
#ifndef EUSART1_CTS_PORT                        
#define EUSART1_CTS_PORT                         gpioPortC
#endif
#ifndef EUSART1_CTS_PIN                         
#define EUSART1_CTS_PIN                          7
#endif

// EUSART1 RTS on PC04
#ifndef EUSART1_RTS_PORT                        
#define EUSART1_RTS_PORT                         gpioPortC
#endif
#ifndef EUSART1_RTS_PIN                         
#define EUSART1_RTS_PIN                          4
#endif

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
// EUSART2 RX on PD01
#ifndef EUSART2_RX_PORT                         
#define EUSART2_RX_PORT                          gpioPortD
#endif
#ifndef EUSART2_RX_PIN                          
#define EUSART2_RX_PIN                           1
#endif

// EUSART2 TX on PD02
#ifndef EUSART2_TX_PORT                         
#define EUSART2_TX_PORT                          gpioPortD
#endif
#ifndef EUSART2_TX_PIN                          
#define EUSART2_TX_PIN                           2
#endif

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
// [EUSART0]$

// $[PTI]
// [PTI]$

// $[MODEM]
// [MODEM]$

// $[CUSTOM_PIN_NAME]
#ifndef _PORT                                   
#define _PORT                                    gpioPortA
#endif
#ifndef _PIN                                    
#define _PIN                                     0
#endif

#ifndef LED1_PORT                               
#define LED1_PORT                                gpioPortA
#endif
#ifndef LED1_PIN                                
#define LED1_PIN                                 7
#endif

#ifndef LED2_PORT                               
#define LED2_PORT                                gpioPortA
#endif
#ifndef LED2_PIN                                
#define LED2_PIN                                 8
#endif

#ifndef RTS_PORT                                
#define RTS_PORT                                 gpioPortC
#endif
#ifndef RTS_PIN                                 
#define RTS_PIN                                  4
#endif

#ifndef TX_PORT                                 
#define TX_PORT                                  gpioPortC
#endif
#ifndef TX_PIN                                  
#define TX_PIN                                   5
#endif

#ifndef RX_PORT                                 
#define RX_PORT                                  gpioPortC
#endif
#ifndef RX_PIN                                  
#define RX_PIN                                   6
#endif

#ifndef CTS_PORT                                
#define CTS_PORT                                 gpioPortC
#endif
#ifndef CTS_PIN                                 
#define CTS_PIN                                  7
#endif

#ifndef UART2_PORT                              
#define UART2_PORT                               gpioPortD
#endif
#ifndef UART2_PIN                               
#define UART2_PIN                                1
#endif

#ifndef UART1_PORT                              
#define UART1_PORT                               gpioPortD
#endif
#ifndef UART1_PIN                               
#define UART1_PIN                                2
#endif

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

