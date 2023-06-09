/**********************************************************************************************************************

 *  This fle contains the prototypes of the application layer 
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <App.h>
 *       Module:  -App
 *
 *  Description:  <This fle contains the prototypes of the application layer>     
 *  
 *********************************************************************************************************************/
#ifndef APP_H
#define APP_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/NVIC/NVIC.h"
#include "../MCAL/SYSTICK/Systick.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void GPIOF_handler_func(void);
void Systick_handler_Func(void);
void Systick_Start(uint32t Time_ms);
void App_start(void);


#endif				 /* APP_H */

/**********************************************************************************************************************
 *  END OF FILE: App.h
 *********************************************************************************************************************/
