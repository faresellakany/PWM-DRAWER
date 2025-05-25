/*
 * PWM0_program.c
 *
 * Created: 15/02/2025 05:22:50 م
 *  Author: Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "PWM0_interface.h"
#include "PWM0_config.h"
#include "PWM0_private.h"
#include "PWM0_register.h"


void PWM0_voidInit(void)
{
	//Select fast PWM Mode
	SET_BIT(TCCR0_REG, WGM00);
	SET_BIT(TCCR0_REG, WGM01);
	
	// Select Non Inverting Output
	CLR_BIT(TCCR0_REG, COM00);
	SET_BIT(TCCR0_REG, COM01);
}


void PWM0_voidGeneratePWM(u8 copy_u8DutyCycle)
{
	if(copy_u8DutyCycle <= 100)
	{
		//Under condition non-inverting o/p	
		OCR0_REG = ((copy_u8DutyCycle * 256) / 100)-1;
		
		//Select Prescaler Value = 64
		SET_BIT(TCCR0_REG, CS00);
		SET_BIT(TCCR0_REG, CS01);
		CLR_BIT(TCCR0_REG, CS02);
	} 
	else
	{
		//return Error State
	}
}


void PWM0_voidStop(void)
{
	CLR_BIT(TCCR0_REG, CS00);
	CLR_BIT(TCCR0_REG, CS01);
	CLR_BIT(TCCR0_REG, CS02);
}