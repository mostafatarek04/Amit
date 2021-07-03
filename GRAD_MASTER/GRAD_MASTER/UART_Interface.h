#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_Init(void);
void UART_sendData(u8 data);
u8 UART_recieveData();



#endif