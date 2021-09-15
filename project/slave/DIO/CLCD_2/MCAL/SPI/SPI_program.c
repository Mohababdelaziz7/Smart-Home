/*
 * SPI_program.c


 *
 *  Created on: Jul 6, 2021
 *      Author: mohamed els
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidMasterInit (void)
{ // in master mode
	 DIO_voidSetPinDirection  (PORTB , PIN5 , OUTPUT); // set MOSI pin output
	 DIO_voidSetPinDirection  (PORTB , PIN6 , INPUT); // set MISO pin input
	 DIO_voidSetPinDirection  (PORTB , PIN7 , OUTPUT); // set clock pin output
	 DIO_voidSetPinDirection  (PORTB , PIN4 , OUTPUT); // set chip select pin output
	SPCR_REG = 0b01111110; /* disable interrupt, enable SPI, enable LSB, enable master SPI mode, leading edge is falling and Trailing edge is rising, Leading Edge is setup
	and Trailing edge is sample and prescaller is divided by 64 */

}

void SPI_voidSlaveInit (void)
{ // in slave mode
	DIO_voidSetPinDirection  (PORTB , PIN5 , INPUT); // set MOSI pin input
	DIO_voidSetPinDirection  (PORTB , PIN6 , OUTPUT); // set MISO pin output
	DIO_voidSetPinDirection  (PORTB , PIN7 , INPUT); // set clock pin input
	DIO_voidSetPinDirection  (PORTB , PIN4 , INPUT); // set chip select pin input
	SPCR_REG = 0b01101100; /* disable interrupt, enable SPI, enable LSB, enable slave SPI mode, leading edge is falling and Trailing edge is rising,Leading Edge is setup
	and Trailing edge is sample and no need for clock */
}

u8 SPI_u8MasterTransmitReceive (u8 Data)
{
	DIO_voidSetPinValue      (PORTB , PIN4 , 0);
	SPDR_REG = Data;                            //  send data
	while (GET_BIT (SPSR_REG , 7) == 0);        // wait on flag
	DIO_voidSetPinValue      (PORTB , PIN4 , 1);
	return SPDR_REG; // return data
}

u8 SPI_u8SlaveTransmitReceive (u8 Data)
{
	SPDR_REG = Data; // send data
	while (GET_BIT (SPSR_REG , 7) == 0); // wait on flag
	return SPDR_REG; // return data
}
