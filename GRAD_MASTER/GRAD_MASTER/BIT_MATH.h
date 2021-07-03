#ifndef BIT_MATH_H
#define BIT_MATH_H

/*Set Bit */

#define SET_BIT(REG,BIT)    REG |= (1<<BIT)


/*clr Bit */

#define CLR_BIT(REG,BIT)    REG &= ~(1<<BIT)

/*toggle Bit */

#define TOG_BIT(REG,BIT)    REG ^= (1<<BIT)

/*Get Bit */

#define GET_BIT(REG,BIT)    ((REG>>BIT)&1) 




#endif