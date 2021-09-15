/*
 * UART_program.c
 *
 *  Created on: Jul 16, 2021
 *      Author: user
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"






void UART_VoidInit(void){

	u8 ucsra =0b00000000; // initialize flags, use normal speed and no multiprocessor communication
	u8 ucsrb =0b00011000; /* disable Interrupt, enable transmit and receive, define character with other 2 bits in UCSRC register
	the last data bit if the frame is 9 bits */
	u8 ucsrc =0b10000110; /* enable UCSRC register, enable Asynchronous mode, disable parity bits, enable 1 stop bit
	enable 8 bits */

	// if U want to use post build configuration
	// UCSRA
#if PARITY_STATE == PARITY_OFF // disable parity
	CLR_BIT(ucsra,2);
#elif PARITY_STATE == PARITY_ON // enable parity
	SET_BIT(ucsra,2);
#endif

#if PARITY_MODE == DISABLE // disable parity
	CLR_BIT(ucsrc,4);
	CLR_BIT(ucsrc,5);
#elif PARITY_MODE == EVEN  // enable even parity mode
	CLR_BIT(ucsrc,4);
	SET_BIT(ucsrc,5);
#elif PARITY_MODE == ODD  // enable odd parity mode
	SET_BIT(ucsrc,4);
	SET_BIT(ucsrc,5);
#endif


#if DOUBLE_SPEED_MODE == DOUBLE_SPEED_MODE_OFF // disable double speed
	CLR_BIT(ucsra,1);
#elif DOUBLE_SPEED_MODE == DOUBLE_SPEED_MODE_ON // enable double speed
	SET_BIT(ucsra,1);
#endif


	//FRAM SIZE

#if FRAM_SIZE == FIVE_BITS // enable 5 bits
	CLR_BIT(ucsrb,2);
	CLR_BIT(ucsrc,1);
	CLR_BIT(ucsrc,2);
#elif FRAM_SIZE == SIX_BITS // enable 6 bits
	CLR_BIT(ucsrb,2);
	SET_BIT(ucsrc,1);
	CLR_BIT(ucsrc,2);
#elif FRAM_SIZE == SEVEN_BITS // enable 7 bits
	CLR_BIT(ucsrb,2);
	CLR_BIT(ucsrc,1);
	SET_BIT(ucsrc,2);
#elif FRAM_SIZE == EIGHT_BITS // // enable 8 bits
	CLR_BIT(ucsrb,2);
	SET_BIT(ucsrc,1);
	SET_BIT(ucsrc,2);
#endif

	//UART MODE

#if UART_MODE == Asynchronous // enable Asynchronous
	CLR_BIT(ucsrc,6);
#elif UART_MODE == synchronous // enable synchronous
	SET_BIT(ucsrc,6);
#endif

#if STOP_BITS == ONE_BIT // enable one stop bit
	CLR_BIT(ucsrc,3);
#elif STOP_BITS == TWO_BITS // enable 2 stop bits
	SET_BIT(ucsrc,3);
#endif


#if TRANSMIT_AT == RISING // enable rising if you are in synchronous
	CLR_BIT(ucsrc,0);
#elif TRANSMIT_AT == FALLING // enable falling if you are in synchronous
	SET_BIT(ucsrc,0);
#endif
	UCSRA=ucsra;
	UCSRB=ucsrb;
	UCSRC=ucsrc;
	UBRRL=103; // set baud rate at 9600
	UBRRH=0;   // set baud rate at 9600




}

void UART_VoidTransmit(u8 Data){
	while(GET_BIT(UCSRA,5)==0); // wait on transmit flag
	UDR=Data;
}
u8 UART_VoidRecieve(void){

	while(GET_BIT(UCSRA,7)==0); // wait on receive flag

	return UDR;
}
void UART_voidWriteString  ( u8 *ptr ){

	u8 i = 0 ; // counter for array of character

	while( ptr[ i ] != '\0' ){ // check when the array reached the null character

		UART_VoidTransmit(ptr[i] ); // transmit array of character
		i++; // increase counter

	}

}

u8 String[20];
u8 * UART_voidReadString(void){
	u8 i=0;u8 x=0;

	while((x=UART_VoidRecieve()) != 'E') // check when if the last character in receive string is E
	{
		String[i]=x; // store the receive string in array of character
		i++; // increase counter
	}
	String[i]='\0'; // end array with the null character
	return String; // return receive data

}
