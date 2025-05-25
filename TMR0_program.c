/*
 * TMR0_program.c
 *
 * Created: 08/02/2025 05:37:45 م
 *  Author: Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TMR0_interface.h"
#include "TMR0_config.h"
#include "TMR0_private.h"
#include "TMR0_register.h"


static void(*PRV_pFunCallBackOVF)(void) = NULL;

void TMR0_voidInit(void)
{
	//Select Normal Mode
	CLR_BIT(TCCR0_REG, WGM00);	
	CLR_BIT(TCCR0_REG, WGM01);
	
	//Enable OVF Interrupt
	SET_BIT(TIMSK_REG, TOIE0);
	
	//Set Preload Value
//	TCNT0_REG = TMR0_PRELOAD_VALUE;
}


void TMR0_voidStart(void)
{
	//Select Prescaler Value = 64
	SET_BIT(TCCR0_REG, CS00);
	SET_BIT(TCCR0_REG, CS01);
	CLR_BIT(TCCR0_REG, CS02);	
}


void TMR0_voidStop(void)
{
	CLR_BIT(TCCR0_REG, CS00);
	CLR_BIT(TCCR0_REG, CS01);
	CLR_BIT(TCCR0_REG, CS02);
}


void TMR0_voidSetCallBackOVF(void(*copy_pFunAction)(void))
{
	if(copy_pFunAction != NULL)
	{
		PRV_pFunCallBackOVF = copy_pFunAction;
	} 
	else
	{
		//return Error State
	}
}


void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	//static u16 local_u16Counter = 0;
	//local_u16Counter++;
	
	//if(TMR0_OVER_FLOW_COUNTER == local_u16Counter)
//	{
		//Re-Init Timer With Preload Value
//		TCNT0_REG = TMR0_PRELOAD_VALUE;
		
		//Clear Counter
//		local_u16Counter = 0;
		
		//Call Action
		if(PRV_pFunCallBackOVF != NULL)
		{
			PRV_pFunCallBackOVF();
		}
//	}
}