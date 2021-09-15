/*
 * UART_interface.h
 *
 *  Created on: Jul 16, 2021
 *      Author: user
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#define    PARITY_ON       1  // enable parity bit
#define    PARITY_OFF      0  // disable parity bit

#define    MPCM_ON         1  // enable MPCM mode
#define    MPCM_OFF        0  // disable MPCM mode

//FRAME SIZE
#define    FIVE_BITS       0
#define    SIX_BITS        1
#define    SEVEN_BITS      2
#define    EIGHT_BITS      3

//STOP BITS
#define    ONE_BIT         1
#define    TWO_BITS        2

#define    RISING          0  // enable capturing at rising
#define    FALLING         1  // enable capturing at falling

#define    Asynchronous    1  // enable UART Asynchronous mode
#define    synchronous     0  // enable UART synchronous mode

#define    DISABLE         0 // disable parity
#define    EVEN            1 // enable even parity
#define    ODD             2 // enable odd parity

#define    DOUBLE_SPEED_MODE_ON       1 // enable Double Speed Mode
#define    DOUBLE_SPEED_MODE_OFF      0 // disable Double Speed Mode




void UART_VoidInit(void); // initialize UART
void UART_VoidTransmit(u8 Data);  // transmit data
u8   UART_VoidRecieve(void); // receive data
void UART_voidWriteString(u8 *ptr); // transmit string
u8 * UART_voidReadString(void); // receive string
#endif /* MCAL_UART_UART_INTERFACE_H_ */
