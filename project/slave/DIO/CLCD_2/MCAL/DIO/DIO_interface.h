/*
 * DIO_interface.h
 *
 *  Created on: May 29, 2021
 *      Author: AMIT
 */

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_

#define OUTPUT  1
#define INPUT   0

#define HIGH    1
#define LOW     0

#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

void DIO_voidSetPortDirection (u8 Copy_u8Port , u8 Copy_u8Direction); // select port and direction
void DIO_voidSetPortValue     (u8 Copy_u8Port , u8 Copy_u8Value); // select port and put value
u8   DIO_u8GetPortValue       (u8 Copy_u8Port); // get value of selected port


void DIO_voidSetPinDirection  (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction); // select port, pin and direction
void DIO_voidSetPinValue      (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value); // select port, pin and put value
u8   DIO_u8GetPinValue        (u8 Copy_u8Port , u8 Copy_u8Pin ); // get value of selected pin


#endif /* DIO_DIO_INTERFACE_H_ */
