/**********************************************************************************************************************
 *  This fiel contains the implementations of the degital input output module in TM4C123GH6PM
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "DIO.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : Pin_Level Dio_ReadChannel(DIO_ChannelType Channel_ID)        
* \Description     : returns the Pin current Level high/Low                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel_ID   contains the required Port and Pin number                     
* \Parameters (out): Pin_Level                                                      
* \Return value:   : High/Low                                
*******************************************************************************/
Pin_Level Dio_ReadChannel(DIO_ChannelType Channel_ID)
{
	Pin_Level level= ((GPIODATA(Channel_ID.Port_number))&1<<Channel_ID.Pin_number)>>Channel_ID.Pin_number;
	return level;
}



/******************************************************************************
* \Syntax          : void Dio_WriteChannel(DIO_ChannelType Channel_ID,Pin_Level Level)        
* \Description     : Writes to the pin given in the function parameter                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel contains port and pin info, Level has the Level you want to write to the pin High/Low
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                        
*******************************************************************************/
void Dio_WriteChannel(DIO_ChannelType Channel_ID,Pin_Level Level)
{
	if (Level == High)
		SET_BIT_BB(GPIODATA(Channel_ID.Port_number),Channel_ID.Pin_number);
	else 
		RESET_BIT_BB(GPIODATA(Channel_ID.Port_number),Channel_ID.Pin_number);
		
}

/******************************************************************************
* \Syntax          : DIO_PortLevelType Dio_ReadPort(DIO_Port_Type PortID)        
* \Description     : Reads the whole Port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Port_ID    the port number you want to read                     
* \Parameters (out): PortLevelType                                                       
* \Return value:   : Uint32_t  

*******************************************************************************/

DIO_PortLevelType Dio_ReadPort(DIO_Port_Type PortID)
{
	DIO_PortLevelType Port_lev;
	Port_lev = (GPIODATA(PortID));
	return Port_lev;
}
/******************************************************************************
* \Syntax          : void Dio_WritePort(DIO_Port_Type PortID,DIO_PortLevelType Level)       
* \Description     : writes to the whole port                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortID the port you want , Level a number from 0 to 256                  
* \Parameters (out): None                                                      
* \Return value:   : None
*
*******************************************************************************/
void Dio_WritePort(DIO_Port_Type PortID,DIO_PortLevelType Level)
{
	GPIODATA(PortID) = Level;
}
/******************************************************************************
* \Syntax          : Pin_Level Dio_FlipChannel(DIO_ChannelType Channel_ID)        
* \Description     : Toggles the pin level               
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel_ID-->Port number and Pin number                    
* \Parameters (out): None                                                      
* \Return value:   : None
*
*******************************************************************************/
void Dio_FlipChannel(DIO_ChannelType Channel_ID)
{
	if (Dio_ReadChannel(Channel_ID) == High)
		Dio_WriteChannel(Channel_ID,Low);
	else 
		Dio_WriteChannel(Channel_ID,High);
}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/