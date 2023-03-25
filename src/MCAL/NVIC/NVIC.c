/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Nvic.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "NVIC.h"
#include "../../SERVICE/Bit_Math.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void NVIC_int()       
* \Description     : this function initialize any interrupt                                     
* \Reentrancy      : Reentrant                                                                            
* \Sync\Async      : Synchronous                                               
* \Parameters (in) : 	none    
* \Parameters (out): None                                                      
* \Return value:   : None  
*******************************************************************************/

void NVIC_int()
	{
	uint32_t i;
	uint8t PRI_i;
	uint32_t offset;
	int n;
		
	   APINT = VECTKEY;
		APINT|= (PRI_8G_1SG*256);
	
	
	for(i=0;i<=139;i++)
		{
			 PRI_i= i/4;
				 n=i%4;
				switch(n)
					{
								case 0:
								PRI(PRI_i)|= NVIC_Cfg[i].Priority *  32 ;
								break;
								case 1:
								PRI(PRI_i)|= NVIC_Cfg[i].Priority *  32 * 256;
								break;
								case 2:
								PRI(PRI_i)|=	NVIC_Cfg[i].Priority *  32 * 65536;
								break;	
								case 3:
								PRI(PRI_i)|= NVIC_Cfg[i].Priority *  32 * 16777216;
								break;
					}
					
				if (i<=31){
				if (NVIC_Cfg[i].state==Enable) Set_Bit(EN_0,i);
				else if (NVIC_Cfg[i].state==Disable) Clear_Bit(EN_0,i);
				}
				if (i>31 & i<=63){
				if (NVIC_Cfg[i].state==Enable) Set_Bit(EN_1, (i-32));
				else if (NVIC_Cfg[i].state==Disable) Clear_Bit(EN_1, (i-32));
				}
				if (i>63 & i<=95){
				if (NVIC_Cfg[i].state==Enable) Set_Bit(EN_2,(i-64));
				else if (NVIC_Cfg[i].state==Disable) Clear_Bit(EN_2,(i-64));
				}
				if (i>95 & i<=127){
				if (NVIC_Cfg[i].state==Enable) Set_Bit(EN_3,(i-96));
				else if (NVIC_Cfg[i].state==Disable) Clear_Bit(EN_3,(i-96));
				}
				if (i>127 & i<=139){
				if (NVIC_Cfg[i].state==Enable) Set_Bit(EN_4,(i-128));
				else if (NVIC_Cfg[i].state==Disable) Clear_Bit(EN_4,(i-128));
			}
				
			
				
		}
	
	}
	
/**********************************************************************************************************************
 *  END OF FILE: Nvic.c
 *********************************************************************************************************************/
