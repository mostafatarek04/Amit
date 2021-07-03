#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "UART_Private.h"
#include "UART_Interface.h"

void UART_Init(void){
	
	
	SET_BIT(DDRD_REG,0);
	SET_BIT(DDRD_REG,1);
    SET_BIT(UCSRC,7);
	
	// Enable the RX and TX 
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
	// Data frame format 
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	CLR_BIT(UCSRB,2);
	//CLR_BIT(UCSRC,6);
	//SET_BIT(UCSRC,5);
	//CLR_BIT(UCSRC,4);
	// Set BaudRate
	//CLR_BIT(UBRRH,7);
	UBRRH = 0;
	UBRRL = 103;
	

	
}
void UART_sendData(u8 data){
	//u8 bufferState = GET_BIT(UCSRA,5);
	while ( GET_BIT(UCSRA,5) == 0);

	UDR = data;
}
u8 UART_recieveData(){
	//u8 recieveComplete = GET_BIT(UCSRA,7);
	
	while ( GET_BIT(UCSRA,7) == 0);
	
	return UDR;
	
}