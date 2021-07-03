#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H



void SPI_InitMaster(void);
void SPI_InitSlave(void);


void SPI_SendData(u8 Data);


u8 SPI_RecieveData();


#endif
