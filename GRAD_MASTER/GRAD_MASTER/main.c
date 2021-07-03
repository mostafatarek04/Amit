/*
 * main.c
 *
 * Created: 6/30/2021 9:17:54 PM
 *  Author: mosta
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "SPI_Interface.h"
#include <avr/delay.h>




int main(void)
{
DIO_voidSetPortDirection(PORTA,OUTPUT);
  u8 uartData;
	  SPI_InitMaster();
	  UART_Init();
	
	
    while(1)
    {
		   uartData = UART_recieveData();
		   UART_sendData(uartData);
		   _delay_ms(100);
           SPI_SendData(uartData);
	
    }
}