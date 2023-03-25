/**********************************************************************************************************************
 *  Cotains the implementations of systick functoins 
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Systick.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Systick.h"
#include <Math.h>

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
cb_type Callback_ptr = NULL_ptr;
uint32t R;

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          :void Systick_Start (uint32t time_ms)        
* \Description     : Starts the systick timer count                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Time_ms   time in milliseconds                      
* \Parameters (out): None                                                      
* \Return value:   : none  
*                                               
*******************************************************************************/
void Systick_Start(uint32t Time_ms)
{
	/*step 0: calculate the number of counts*/
	volatile uint32t counts =0;
	volatile double ticks = (double)(((double)Time_ms/1000.0)*(double)(clock));
	R = 1;
	if (ticks >Max_count)
	{
	  R = ceil(ticks/(double)Max_count);
		counts = ticks/R;
		
	}
	else 
	{counts = ticks;}
	/*Step 1: Clearing the Count bit in STCTRL*/
	STCURRENT |= 0x000000;
	/*Step 2: Putting the cunts value in Streload register*/
	STRELOAD = counts;
	/*Step 3: setting the STCTRL register*/
	STCTRL |= 0x07;
}



/******************************************************************************
* \Syntax          : void Systick_cb(cb_type ptr)        
* \Description     : puts interrupt service routine function in app.c to the global poiter to function in systick                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Cb_type   contains the address of the Interrupt service routine function in main                   
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Systick_cb(cb_type ptr)
{
 if (ptr != NULL_ptr) 
 {
     Callback_ptr = ptr;
 }
}

/******************************************************************************
* \Syntax          : void Systick handler()        
* \Description     : calls the interrupt service routine functoin in main                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None

*******************************************************************************/
void SysTick_Handler()
{
if (Callback_ptr != NULL_ptr)
{
	volatile static uint32t repeats = 0;
	if (repeats == (R-1))
	{
		Callback_ptr();
		repeats = 0 ;
	}
	else 
		repeats++;
}

}
	/**********************************************************************************************************************
 *  END OF FILE: Systick.c
 *********************************************************************************************************************/
