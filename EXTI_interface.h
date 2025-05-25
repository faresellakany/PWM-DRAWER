﻿/*
 * EXTI_interface.h
 *
 * Created: 31/01/2025 03:05:09 م
 *  Author: Kareem Hussein
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/* Enum Values For Interrupt Source */
typedef enum
{
	EXTI_INT0 = 0,
	EXTI_INT1,
	EXTI_INT2
}EXTI_intSrc_t;

/* Enum Values For Interrupt Trigger Edge */
typedef enum
{
	EXTI_RISING_EDGE = 0,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE,
}EXTI_intSenseCtrl_t;

                         /*************** APIS PROTOTYPES ***************/ 

void EXTI_voidInit   (EXTI_intSrc_t copy_tIntSource, EXTI_intSenseCtrl_t copy_tIntSenseCtrl);
void EXTI_voidEnable (EXTI_intSrc_t copy_tIntSource);
void EXTI_voidDisable(EXTI_intSrc_t copy_tIntSource);
void EXTI_voidSetCallBackINT0(void(*copy_pFunAction)(void));


#endif /* EXTI_INTERFACE_H_ */