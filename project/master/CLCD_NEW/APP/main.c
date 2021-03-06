/*
 * main.c
 *
 *  Created on: SEP 14, 2021
 *      Author: MOHAB ABD ELAZIZ
 */
#include <stdio.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.H"
#include <util/delay.h>

#include "../HAL/CLCD_KHALED/CLCD_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_private.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/GIE/GIE_private.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/UART/UART_interface.h"

int main(void){

	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT); // set led on portc in pin2 and output
	DIO_voidSetPinDirection(PORTD,PIN1,OUTPUT); // set UART on portd in pin1 and output
	DIO_voidSetPinDirection(PORTD,PIN0,INPUT); // set UART on portd in pin0 and input

	UART_VoidInit(); // iniallization UART
	SPI_voidMasterInit(); // iniallization SPI master
	u8 Recieved_Data; // decleration variable ( flag )
	while(1){
		_delay_ms(500); // delay before to prevent data collision

		Recieved_Data=UART_VoidRecieve(); // put data recieved from bluetooth in flag
		SPI_u8MasterTransmitReceive(Recieved_Data); // transimmit flag to other micro through SPI
		if(Recieved_Data=='1') {
			DIO_voidSetPinValue(PORTC,PIN2,HIGH);
		} // check if flag == 1 --> led on
		else
		{
			DIO_voidSetPinValue(PORTC,PIN2,LOW); // chech if flag == 0 --> led off
		}
	}
	return 0;
}
