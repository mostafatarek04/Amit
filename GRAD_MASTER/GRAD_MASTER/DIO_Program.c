#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"


void DIO_voidSetPinDirection(u8 PORTID, u8 PINID, u8 Direction){
	/*Range Check*/
	if ((PORTID < 4)  && (PINID <8)){
		
		if (Direction == INPUT){
			switch(PORTID){
				case PORTA: CLR_BIT(DDRA_REG,PINID);   break;
							
				case PORTB: CLR_BIT(DDRB_REG,PINID);   break;
							
				case PORTC: CLR_BIT(DDRC_REG,PINID);   break;
							
				case PORTD: CLR_BIT(DDRD_REG,PINID);   break;
			}
			
		}else if (Direction == OUTPUT){
			
			switch(PORTID){
				case PORTA: SET_BIT(DDRA_REG,PINID);   break;
				
				case PORTB: SET_BIT(DDRB_REG,PINID);   break;
				
				case PORTC: SET_BIT(DDRC_REG,PINID);   break;
				
				case PORTD: SET_BIT(DDRD_REG,PINID);   break;
				
			}
			
		}
		
		
	}else{
		
		return 0;
	}
	
}
void DIO_voidSetPinValue(u8 PORTID, u8 PINID, u8 Value){
		if ((PORTID < 4)  && (PINID <8)){
		if (Value == HIGH){
			
			switch (PORTID){
			
			case PORTA :  SET_BIT(PortA_REG,PINID);   break;
			case PORTB :  SET_BIT(PortB_REG,PINID);    break;
			case PORTC :  SET_BIT(PortC_REG,PINID);   break;
			case PORTD :  SET_BIT(PortD_REG,PINID);     break;
		}
		}
		
			if (Value == LOW){
			
			switch (PORTID){
			
			case PORTA :  CLR_BIT(PortA_REG,PINID);   break;
			case PORTB :  CLR_BIT(PortB_REG,PINID);    break;
			case PORTC :  CLR_BIT(PortC_REG,PINID);   break;
			case PORTD :  CLR_BIT(PortD_REG,PINID);     break;
		}
		}
		
	}
	
}


void DIO_voidTogglePinValue(u8 PORTID, u8 PINID){
	if ((PORTID < 4)  && (PINID <8)){
		
			
			switch (PORTID){
				
				case PORTA :  TOG_BIT(PortA_REG,PINID);   break;
				case PORTB :  TOG_BIT(PortB_REG,PINID);    break;
				case PORTC :  TOG_BIT(PortC_REG,PINID);   break;
				case PORTD :  TOG_BIT(PortD_REG,PINID);     break;
			}
			
	}
	
}

u8   DIO_u8GetPinValue(u8 PORTID, u8 PINID){
	u8 local_Data = 0xFF;
	if ((PORTID < 4)  && (PINID <8)){
		
		switch (PORTID){
			
			case PORTA : local_Data = GET_BIT(PINA_REG,PINID);   break;
			case PORTB : local_Data = GET_BIT(PINB_REG,PINID);    break;
			case PORTC : local_Data = GET_BIT(PINC_REG,PINID);   break;
			case PORTD : local_Data = GET_BIT(PIND_REG,PINID);     break;
		}
		
	}else{
	
	return 0;
	}
	
	return local_Data;
	
}

void DIO_voidSetPortDirection(u8 PORTID, u8 Direction){
	
	/*Range Check*/
	
	if (PORTID < 4){
		if (Direction == OUTPUT){
			
			
			switch(PORTID){
			
			case PORTA:  DDRA_REG = 0b11111111;        break;
			case PORTB:  DDRB_REG = 0b11111111;        break;
			case PORTC:  DDRB_REG = 0b11111111;        break;
			case PORTD:  DDRD_REG = 0b11111111;        break;
			
	    }
		}else if(Direction == INPUT){
			
			
			switch(PORTID){
			
			case PORTA:  DDRA_REG = 0b00000000;        break;
			case PORTB:  DDRB_REG = 0b00000000;        break;
			case PORTC:  DDRC_REG = 0b00000000;        break;
			case PORTD:  DDRD_REG = 0b00000000;        break;
			
	    }
		}
		
	}
	
	
}

void DIO_voidSetPortValue(u8 PORTID, u8 Value){
	
	/*Range Check*/
	
	if (PORTID < 4){
	
			
			
			switch(PORTID){
			
			case PORTA:  PortA_REG = Value;        break;
			case PORTB:  PortB_REG = Value;        break;
			case PORTC:  PortC_REG = Value;        break;
			case PORTD:  PortD_REG = Value;        break;
			
	    }
		
		
	
	
	
}else{
	
	return 0;
}


}