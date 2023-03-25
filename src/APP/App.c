/**********************************************************************************************************************
 *  Application layer function implemintations 
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  App.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "App.h"

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
extern const Port_ConfigType Port_Config_arr[];
uint8t deuty = 50; // the duety cycle is initialized with 50%

/******************************************************************************
* \Syntax          : void App_start(void)        
* \Description     : initializes the drivers and waits for systick and gpio_f interrups                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                 
*******************************************************************************/

void App_start(void)
{
	Port_init(Port_Config_arr);
	Systick_cb(Systick_handler_Func);
	Systick_Start(1000);
	NVIC_int();
	GPIOF_cb(GPIOF_handler_func);
	Port_int_en(Port_F,0);
	while (1)
	{}
}


/******************************************************************************
* \Syntax          : void Systick_handler_Func(void)       
* \Description     : checks the duety cycle and sets the on and off time accordingly       
*                                                                             
* \Sync\Async      :  Synchronous      
* \Reentrancy      :  Non Reentrant      
* \Parameters (in) :  None      
* \Parameters (out):  None      
* \Return value:   :  None
*                           
*******************************************************************************/

void Systick_handler_Func(void)
{
	volatile DIO_ChannelType channel = {1,PORT_F};
	Dio_FlipChannel(channel);
	/*setting ON and Off time according to deuty cycle where T = 10s*/
		/*Level 1*/
	if (deuty ==25)
	{
		if (Dio_ReadChannel(channel) == High)
		{
		Systick_Start(2500); // setting the ON time to 2.5 seconds (25% of T)
		}
		else if (Dio_ReadChannel(channel) ==Low)
		{Systick_Start(7500);} //setting the Off time to 7.5 seconds (75% of T)
		}
	
			/*Level 2*/
		else if (deuty == 50)
		{Systick_Start(5000);} // setting the ON and off time 5 seconds (50% of T)
	
		/*Level 3*/
		else if (deuty == 75)
				{
		if (Dio_ReadChannel(channel) == High)
		{
		Systick_Start(7500); // setting the ON time to 2.5 seconds (25% of T)
		}
		else if (Dio_ReadChannel(channel) ==Low)
		{Systick_Start(2500);} //setting the Off time to 7.5 seconds (75% of T)
		}
				
				/*Level 4*/
		else if (deuty == 100)
				{
		if (Dio_ReadChannel(channel) == High)
		{
		Systick_Start(10000); // setting the ON time to 10 seconds (25% of T)
		}
		else if (Dio_ReadChannel(channel) ==Low)
		{Systick_Start(1);} //setting the Off time to 62.5ns seconds (75% of T)
		}
				
	}


/******************************************************************************
* \Syntax          : void GPIOF_handler_func(void)        
* \Description     : Sets the deuty cycle                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                       
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/

void GPIOF_handler_func(void)
{
	/*this function sets the deuty cycle ,we have 4 levels: 25%,50%,75%,100%*/
  if (deuty == 25)
		deuty = 50; // set to level 2
	else if (deuty == 50)
		deuty = 75; // set to level 3
	else if (deuty == 75)
		deuty = 100; // set to level 4
	else if (deuty == 100)
		deuty = 25; // set to level 1
	
	SET_BIT_BB(GPIOICR(PORT_F),0); // clearing the interrupt flag 

}