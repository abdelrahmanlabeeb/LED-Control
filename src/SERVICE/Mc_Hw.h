 /**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MC_HW.h>
 *       Module:  -Common 
 *
 *  Description:  contains TM4C123GH6PM registers      
 *  
 *********************************************************************************************************************/
#ifndef MC_HW_H
#define MC_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "TYPES.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define RCGCGPIO										*((volatile uint32t*)(0x400fe000+0x0608))
#define NVIC_Base 0xE000E000 
#define EN_0 			*((volatile uint32t*)(NVIC_Base+0x0100))
#define EN_1 			*((volatile uint32t*)(NVIC_Base+0x0104))
#define EN_2 			*((volatile uint32t*)(NVIC_Base+0x0108))
#define EN_3 			*((volatile uint32t*)(NVIC_Base+0x010C))
#define EN_4 			*((volatile uint32t*)(NVIC_Base+0x0110))
#define PRI(x)	  *((volatile uint32t*)(NVIC_Base+0x400+((x)*0x4)))
#define APINT  		*((volatile uint32t*)(NVIC_Base+0x0D0C)) //PRIORITYGROUP
#define VECTKEY    0x05FA0000

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define GPIO_PORT_BA(x)          (x<4? ((0x40004000) + ((x)*0x1000)):((0x40024000) + ((x-4)*0x1000)))
#define GPIODATA(x)             *((volatile uint32t*)(GPIO_PORT_BA(x)+0x3Fc)) //has 265 Adress see example p.654 
#define GPIODIR(x)                 *((volatile uint32t*)(GPIO_PORT_BA(x)+0x0400)) // 0--> input
#define GPIOIS(x)                 *((volatile uint32t*)(GPIO_PORT_BA(x)+0x0404)) 
#define GPIOIBE(x)                 *((volatile uint32t*)(GPIO_PORT_BA(x)+0x0408)) 
#define GPIOIEV(x)                 *((volatile uint32t*)(GPIO_PORT_BA(x)+0x040C))
#define GPIOIM(x)                 *((volatile uint32t*)(GPIO_PORT_BA(x)+0x0410))
#define GPIORIS(x)                 *((volatile uint32t*)(GPIO_PORT_BA(x)+0x0414))
#define GPIOMIS(x)                 *((volatile uint32t*)(GPIO_PORT_BA(x)+0x0418)) 	
#define GPIOICR(x)                 *((volatile uint32t*)(GPIO_PORT_BA(x)+0x041C)) 
#define GPIOAFSEL(x)		*((volatile uint32t*)(GPIO_PORT_BA(x)+ 0x0420) )        																																//1-->output 
#define GPIOPDR(x)		*((volatile uint32t*)(GPIO_PORT_BA(x)+ 0x0514) )
#define GPIOPUR(x)										 *((volatile uint32t*)(GPIO_PORT_BA(x)+ 0x0510) )
#define GPIOAMSEL(x)		*((volatile uint32t*)(GPIO_PORT_BA(x)+ 0x0528) )
#define GPIODEN(x)											*((volatile uint32t*)(GPIO_PORT_BA(x)+ 0x051c) )
#define GPIOLOCK(x)								*((volatile uint32t*)(GPIO_PORT_BA(x)+ 0x0520))
#define GPIOLOCKEN(x)							GPIOLOCK(x) = 0x4c4f434b // allows you to write in GPIOCR
#define GPIOCR(x)										*((volatile uint32t*)(GPIO_PORT_BA(x)+ 0x0524))


 
#endif  /* MC_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: MC_HW.h
 *********************************************************************************************************************/
