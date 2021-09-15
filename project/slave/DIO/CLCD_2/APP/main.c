/*
 * main.c
 *
 *  Created on: May 29, 2021
 *      Author: KHAlED ABD EL AZIZ
 */
#include <stdio.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.H"

#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_private.h"
#include "../HAL/CLCD_Eng_Hesham/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/GIE/GIE_private.h"
#include "../MCAL/SPI/SPI_interface.h"


int main(void){
	// output led
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN3,OUTPUT);

	SPI_voidSlaveInit(); // initilization SPI
	u8 RECIEVED = 0; // defination data = 0
	while(1){

		RECIEVED = SPI_u8SlaveTransmitReceive('1'); // transimmit the data through SPI in variable data

		// check the data if data == 1 --> led on
		if(RECIEVED=='1') {
			DIO_voidSetPinValue(PORTC,PIN2,HIGH);
			DIO_voidSetPinValue(PORTC,PIN7,HIGH);
			DIO_voidSetPinValue(PORTD,PIN3,HIGH);

		}
		else if(RECIEVED=='0') // if data == 0 --> led off
		{
			DIO_voidSetPinValue(PORTC,PIN2,LOW);
			DIO_voidSetPinValue(PORTC,PIN7,HIGH);
			DIO_voidSetPinValue(PORTD,PIN3,HIGH);
		}
	}
	return 0;
}
