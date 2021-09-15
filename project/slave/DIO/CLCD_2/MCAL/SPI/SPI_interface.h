/*
 * SPI_interface.h
 *
 *  Created on: Jul 6, 2021
 *      Author: mohamed els
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

void SPI_voidMasterInit (void); // initialize master

void SPI_voidSlaveInit (void); // initialize slave

u8 SPI_u8MasterTransmitReceive (u8 Data); // transmit data to slave

u8 SPI_u8SlaveTransmitReceive (u8 Data); // receive data from master



#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
