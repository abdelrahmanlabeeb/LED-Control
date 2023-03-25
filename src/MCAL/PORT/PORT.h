/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <PORT.H>
 *       Module:  -MCAL
 *
 *  Description:  <This file includes the PORT module prototypes >     
 *  
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../SERVICE/Mc_Hw.h"
#include "../../SERVICE/Bit_Math.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	Low , High
}Pin_Level;

typedef enum
{
	input, output
}Pin_Direction;

typedef enum 
{
	Degital,Analog
}Pin_Mode;

typedef enum 
{
Pullup, Pulldown /*drain not supported*/
}Pin_Int_Attatch;

typedef enum 
{
	Port_A, Port_b,Port_C,Port_D,Port_E, Port_F
}Port_Num;

typedef uint8t Pin_Num;

typedef struct
{
  Pin_Level PIN_LEVEL;
	Pin_Direction PIN_DIR;
	Pin_Mode PIN_MODE;
	Pin_Int_Attatch PIN_ATTATCH;
	Port_Num PORT;
	Pin_Num pin;

}	Port_ConfigType;

typedef void (*cb_type)(void);

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Port_init(const Port_ConfigType*);
void GPIOF_Handler();
void GPIOF_cb(cb_type ptr);
void Port_int_en(Port_Num port , Pin_Num pin);
 
#endif  /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT.h
 *********************************************************************************************************************/
