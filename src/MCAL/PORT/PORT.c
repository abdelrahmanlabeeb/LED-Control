/**********************************************************************************************************************
 *  Implemintation of Port module functions 
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PORT.h"

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
cb_type Callback_ptr_GPIOF = NULL_ptr;

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Port_init(const Port_ConfigType* port_config_ptr)       
* \Description     : initializes Ports according to the configuration array
*                                                                            
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Port_config_ptr configurations array                     
* \Parameters (out): None                                                   
* \Return value:   : None
*                                                                     
*******************************************************************************/

void Port_init(const Port_ConfigType* port_config_ptr)
{
	uint8t pin_count =0;
	  volatile Pin_Num Pin;
	volatile Port_Num Port;
	
	
for (pin_count = 0; pin_count<3; pin_count++)
	{
		 Pin = port_config_ptr[pin_count].pin;
	
	   Port = port_config_ptr[pin_count].PORT;
		//step 0 : Initiate the clock for ports 
 RCGCGPIO |= 0x3f;		// all port have clock 
		
			// step 4: Degital enable 
			if (port_config_ptr[pin_count].PIN_MODE == Degital)
			{
				RESET_BIT_BB(GPIOAFSEL(Port),Pin);
				SET_BIT_BB(GPIODEN(Port),Pin);
				RESET_BIT_BB(GPIOAMSEL(Port),Pin);
			}
				else 
					{/*Not supported yet: TODO*/}
					
		//step 1: set direction 
		if (port_config_ptr[pin_count].PIN_DIR == output)
		{	
		Set_Bit(GPIODIR(Port),Pin);
		
			//step 2.1 set pin level in case of output
		if (port_config_ptr[pin_count].PIN_LEVEL == High)
			Set_Bit(GPIODATA(Port),Pin);
			else 
		RESET_BIT_BB(GPIOCR(Port),Pin);
		}
			else 
			{
				RESET_BIT_BB(GPIODIR(Port),Pin);
				//step 2.2 set port internal attach in case of input 
				if (port_config_ptr[pin_count].PIN_ATTATCH == Pullup)
				SET_BIT_BB(GPIOPUR(Port),Pin);
					else 
						SET_BIT_BB(GPIOPDR(Port),Pin);
			}
			//step 3 the output current not supported (not needed because of the absence of hardware)
			
			
		
	}

}


/******************************************************************************
* \Syntax          :  void Port_int_en(Port_Num port , Pin_Num pin)        
* \Description     : enables the pin external interrupt                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Port  Port number (ie A,B,C..), Pin Pin number (ie 1,2,3..)                     
* \Parameters (out): None                                                      
* \Return value:   : None

*******************************************************************************/

void Port_int_en(Port_Num port , Pin_Num pin)
{
	/*this function only supports Falling-edge interrupt*/
	/*1- No need to configure GPIS, its edge sensitive by defult*/
	/*2-No need to configue GPIOIBE, we will support both edges interrupt triggering*/
	/*3-no need to configure GPIOIEV, its low level or falling edge by defult */
	/*4- enabeling the pin interrupt*/
	SET_BIT_BB(GPIOIM(port),pin);
	/*end of function */
	
	
}
/******************************************************************************
* \Syntax          :  void GPIOF_cb(cb_type GPIOF_cb)        
* \Description     : puts the address of the GPIO ISR in the global pointer to function                                    
*                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : GPIOF_cb contains the address of ISR
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                         
*******************************************************************************/
void GPIOF_cb(cb_type GPIOF_cb)
{
if (GPIOF_cb != NULL_ptr)
	Callback_ptr_GPIOF = GPIOF_cb;
}
/******************************************************************************
* \Syntax          :  void GPIOF_Handler(Void)        
* \Description     : this function is called when GPIOF interrupt is triggerd and it calls the Function in the application layer                                
*                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : GPIOF_cb contains the address of ISR
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                         
*******************************************************************************/

void GPIOF_Handler()
{
if (Callback_ptr_GPIOF!= NULL_ptr)
  Callback_ptr_GPIOF();
}

/**********************************************************************************************************************
 *  END OF FILE: PORT.c
 *********************************************************************************************************************/
