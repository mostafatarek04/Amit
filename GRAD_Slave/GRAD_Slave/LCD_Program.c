#include "STD_TYPES.H"
#include "BIT_MATH.H"
#include "DIO_Interface.H"
#include "LCD_Interface.H"
#include <util/delay.h>





void LCD_voidInit(void){
		DIO_voidSetPortDirection(PORTB,OUTPUT);
	    DIO_voidSetPortDirection(PORTA,OUTPUT);
	_delay_ms(40);
	LCD_voidSendCMD(0x38);
	LCD_voidSendCMD(0x0C);
	LCD_voidSendCMD(0x06);
	LCD_voidSendCMD(0x01);
	LCD_voidSendCMD(0x02);
	LCD_voidSendCMD(0x80);
	
}

void LCD_voidSendCMD(u8 cmd){
	
	
	/*1- RS = 0 (send command mode )*/
	
	DIO_voidSetPinValue(LCD_Control_Port,LCD_RS,LOW);
	
	/*2-RW = 0 write mode */
	
	DIO_voidSetPinValue(LCD_Control_Port,LCD_RW,LOW);
	
	/*3- enable pulse*/
	
	DIO_voidSetPinValue(LCD_Control_Port,LCD_EN,HIGH);
	_delay_ms(10);
	
	DIO_voidSetPortValue(LCD_Data_Port,cmd);
	
	DIO_voidSetPinValue(LCD_Control_Port,LCD_EN,LOW);
	_delay_ms(10);
	
	
	
}

void LCD_voidSendWord(const u8 *word){
	volatile u8 i = 0;
	while (word[i] != '\0'){
		
		LCD_voidSendData(word[i]);
		
		i++;
	}
}

void LCD_voidSendData(u8 Data){
	/*1- RS = 1 (send command mode )*/
	
	DIO_voidSetPinValue(LCD_Control_Port,LCD_RS,HIGH);
	
	/*2-RW = 0 write mode */
	
	DIO_voidSetPinValue(LCD_Control_Port,LCD_RW,LOW);
	
	/*3- enable pulse*/
	
	DIO_voidSetPinValue(LCD_Control_Port,LCD_EN,HIGH);
	_delay_ms(10);
	
	DIO_voidSetPortValue(LCD_Data_Port,Data);
	
	DIO_voidSetPinValue(LCD_Control_Port,LCD_EN,LOW);
	_delay_ms(10);
	
}