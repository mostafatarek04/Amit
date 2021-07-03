
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"


void SPI_InitMaster(void){
	// configure SPI PINS
	//SS pin output
	DIO_voidSetPinDirection(PORTB,4,OUTPUT);
	//mosi pin output
	DIO_voidSetPinDirection(PORTB,5,OUTPUT);
	// miso pin input
	DIO_voidSetPinDirection(PORTB,6,INPUT);
	//sck pin output
	DIO_voidSetPinDirection(PORTB,7,OUTPUT);
	// masterMode
	SET_BIT(SPCR,4);
	//enable spi
	SET_BIT(SPCR,6);
	
	//set clockrate to fso/4
	// 	CLR_BIT(SPCR,0);
	// 	CLR_BIT(SPCR,1);
	
	
}
void SPI_InitSlave(void){
	
	
	// configure SPI PINS
	
	//SS pin input
	DIO_voidSetPinDirection(PORTB,4,INPUT);
	//mosi pin input
	DIO_voidSetPinDirection(PORTB,5,INPUT);
	// miso pin output
	DIO_voidSetPinDirection(PORTB,6,OUTPUT);
	//sck pin input
	DIO_voidSetPinDirection(PORTB,7,INPUT);
	// slave mode
	CLR_BIT(SPCR,4);
	//enable spi
	SET_BIT(SPCR,6);

	//set clockrate to fso/4
	// 		CLR_BIT(SPCR,0);
	// 	    CLR_BIT(SPCR,1);
}


void SPI_SendData(u8 Data){
	
	// send data by spi
	SPDR = Data;
	
	//wait till interrupt flag is 1 (data is sent correctly)
	while (GET_BIT(SPSR,7) != 1);
}


u8 SPI_RecieveData(){

	
	//wait till interrupt flag is 1 (data is recieved correctly)
	while (GET_BIT(SPSR,7) != 1);
	// return data
	return SPDR;
}