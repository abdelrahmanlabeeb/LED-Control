/**********************************************************************************************************************

 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Bit_Math.h
 *       Module:  Common
 *
 *  Description: Contains Bit operations using read write modify method and bit band method    
 *  
 *********************************************************************************************************************/
 
#ifndef Bit_Math
#define Bit_Math
#include "TYPES.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define SET_BIT_BB(REG,Bit) 					((*((volatile uint32_t *)( 0x42000000 +(((uint32_t)(&REG) -0x40000000)*32)+((Bit)*4))))=0xff)
#define RESET_BIT_BB(Reg,Bit) 					((*((volatile uint32_t *)( 0x42000000 +(((uint32_t)(&Reg) -0x40000000)*32)+((Bit)*4))))=0x00)
#define Set_Bit(REG,BIT)							(REG |= (1<<BIT))
#define Clear_Bit(REG,BIT) 						(REG &= (~(1<<BIT)))
#define GetBit(REG,BIT) 						((REG>>BIT)&(0x01))

#endif /* Bit_Math_H */

/**********************************************************************************************************************
 *  END OF FILE: Bit_Math.h
 *********************************************************************************************************************/
