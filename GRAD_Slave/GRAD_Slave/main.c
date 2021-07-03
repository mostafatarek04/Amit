/*
 * main.c
 *
 * Created: 7/2/2021 6:59:49 AM
 *  Author: mosta
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"

int main(void)
{
	
	 u8 spiData;
	DIO_voidSetPortDirection(PORTC,OUTPUT);
	SPI_InitSlave();
    while(1)
    {
		
         spiData = SPI_RecieveData();
	
	     if (spiData == '1')
	     {
			 DIO_voidTogglePinValue(PORTC,0);
	     }
		 
		    if (spiData == '2')
		    {
			    DIO_voidTogglePinValue(PORTC,1);
		    }
	
	
    }
	
	
}