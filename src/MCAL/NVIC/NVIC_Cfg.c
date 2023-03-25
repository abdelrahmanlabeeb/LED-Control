/**********************************************************************************************************************
 *  Initialization array for the NVIC Module
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file NVIC_CGF.c  
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


const NVIC_CfgType NVIC_Cfg[139] ={
	//statte						priority
	{ Enable				,				5}, //PORTA
	{ Enable				,				6}, //PORTB
	{ Enable				,				7}, //PORTC
	{ Disable				,				0}, //PORTD
	{ Disable				,				0}, //PORTE
	{ Disable				,				0}, //UARTDisable
	{ Disable				,				0}, //UART1
	{ Disable				,				0}, //SSI0
	{ Disable				,				0}, //I2CO
	{ Disable				,				0}, //PWM0 Fault
	{ Disable				,				0}, //PWM0 Generator 0
	{ Disable				,				0}, //PWM0 Generator 1
	{ Disable				,				0}, //PWM0 Generator 2
	{ Disable				,				0}, //QEI0
	{ Disable				,				0}, //ADC0 Sequence 0
	{ Disable				,				0}, //ADC0 Sequence 1
	{ Disable				,				0}, //ADC0 Sequence 2
	{ Disable				,				0}, //ADC0 Sequence 3
	{ Enable				,				7}, //WDT 0 and 1
	{ Enable				,				0}, //Timer 0A
	{ Disable				,				4}, //Timer 0B
	{ Disable				,				0}, //Timer 1A
	{ Disable				,				0}, //Timer 1B
	{ Disable				,				0}, //Timer 2A
	{ Disable				,				0}, //Timer 2B
	{ Disable				,				0}, //Analog comparator 0
	{ Disable				,				0}, //Analog compartor 1
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //system control
	{ Disable				,				0}, //Flash Memory Control and EEPROM Control
	{ Enable			,					0}, //PORTF
	{ Disable				,				0}, //Reserved
	{ Disable				,				0}, //Reserved
	{ Disable				,				0}, //UART2
	{ Disable				,				2}, //SSI1
	{ Disable				,				0}, //Timer 3A
	{ Disable				,				2}, //Timer 3B
	{ Disable				,				0}, //I2C1
	{ Disable				,				0}, //QEI1
	{ Disable				,				0}, //CAN0
	{ Disable				,				0}, //CAN1
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //Hibernation Module
	{ Disable				,				0}, //USB
	{ Disable				,				0}, //PWM Generator 3
	{ Disable				,				0}, //uDMA software
	{ Disable				,				0}, //uDMA error
	{ Disable				,				0}, //ADC1 Sequence 0
	{ Disable				,				0}, //ADC1 Sequence 1
	{ Disable				,				0}, //ADC1 Sequence 2
	{ Disable				,				0}, //ADC1 Sequence 3
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //SSI2
	{ Disable				,				0}, //SSI3
	{ Disable				,				0}, //UART3
	{ Disable				,				0}, //UART4
	{ Disable				,				0}, //UART5
	{ Disable				,				0}, //UART6
	{ Disable				,				0}, //UART7
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //I2C2
	{ Disable				,				0}, //I2C3
	{ Disable				,				0}, //Timer 4A
	{ Disable				,				0}, //Timer 4B
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //Timer 5A
	{ Disable				,				0}, //Timer 5B
	{ Disable				,				0}, //Timer 0A 32/64
	{ Disable				,				0}, //Timer 0B 32/64
	{ Disable				,				0}, //Timer 1A 32/64
	{ Disable				,				0}, //Timer 1B 32/64
	{ Disable				,				0}, //Timer 2A 32/64
	{ Disable				,				0}, //Timer 2B 32/64
	{ Enable				,				0}, //Timer 3A 32/64
	{ Disable				,				0}, //Timer 3B 32/64
	{ Disable				,				0}, //Timer 4A 32/64
	{ Disable				,				0}, //Timer 4B 32/64
	{ Disable				,				0}, //Timer 5A 32/64
	{ Disable				,				0}, //Timer 5B 32/64
	{ Disable				,				0}, //System Exception (imprecise)
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Disable				,				0}, //reserved
	{ Enable				,				0}, //PWM1 Generator 0
	{ Disable				,				0}, //PWM1 Generator 1
	{ Disable				,				0}, //PWM1 Generator 2
	{ Disable				,				3}, //PWM1 Generator 3
	{ Enable				,				6}, //PWM1 fault
};

/**********************************************************************************************************************
 *  END OF FILE: NVIC_cfg.c
 *********************************************************************************************************************/