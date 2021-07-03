#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


#define LCD_Control_Port      PORTA
#define LCD_Data_Port         PORTB

#define LCD_RS                PIN0
#define LCD_RW                PIN1
#define LCD_EN                PIN2


void LCD_voidInit(void);
void LCD_voidSendWord(const u8 *word);
void LCD_voidSendCMD(u8 cmd);

void LCD_voidSendData(u8 Data);


#endif