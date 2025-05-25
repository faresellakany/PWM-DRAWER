/*
 * PWM_DRAWER.c
 *
 * Created: 17/05/2025 06:00:00 م
 * Author : Fares ELLAKANY
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "GI_interface.h"
#include "EXTI_interface.h"
#include "DIO_interface.h"
#include "TMR0_interface.h"
#include "PWM0_interface.h"

/* HAL */
#include "LCD_interface.h"

/* Delay Functions */
#define F_CPU 16000000UL
#include <util/delay.h>

/* Interruption functions of Timer0 and External Interrupts     */

void funActionINT0(void);
void action_OVF0(void);

/* Timer0 Register */
#define TCNT0_REG           (*(volatile u8*)0x52)

/* ICU calculations variables*/
u8 ovfc,es;
u32 onc,ont,pc,pt;

/* Frequency, Duty and loop exit counter */
u32 f;
u32 d;
u8 i;

int main(void)
{
	
    /* Enable General interrupt */
	GI_voidEnable();
	
	/* Timer0 Initialization */
	TMR0_voidInit();
	
	/* external INT0 DIO direction and set with Rising Edge */
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
    EXTI_voidInit(EXTI_INT0, EXTI_RISING_EDGE); //push
	
	
	
	/* External interrupt set call back function and enable external input and set event state to zero */

	EXTI_voidSetCallBackINT0(&funActionINT0);
	es=0;
	d=50;
	EXTI_voidEnable(EXTI_INT0);
	
	
	/* Timer0 Set callback function and start */

	TMR0_voidSetCallBackOVF(&action_OVF0);
	TMR0_voidStart();
	
	/* LCD Initiation function for Display*/	
	LCD_voidInit();
	
	//LCD_voidDisplayString((u8*)"Frequency in KHzz");
	 
	 /* Set PWM0 port as output port */
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);	
	PWM0_voidInit();
   
	/* Calculate Frequency by ICU and displaying it on LCD and Oscilloscope */
    LCD_voidDisplayChar('F');
	LCD_voidDisplayChar('=');
	//u8 x1=(f*100)/10;
	//u8 x2=(f*100)%10;
	//PWM0_voidGeneratePWM(50);
	LCD_voidDisplayChar('2'); 
	LCD_voidDisplayChar('5'); 
	LCD_voidDisplayChar('0'); 
	LCD_voidDisplayChar('K'); 
	LCD_voidDisplayChar('H'); 
	LCD_voidDisplayChar('z');  
	
	while(1)
	{		}
		
}


void funActionINT0(void)
{
	if(0 ==es)
	{
		ovfc=0;
		TCNT0_REG=0;
		EXTI_voidInit(EXTI_INT0, EXTI_FALLING_EDGE);
		
		
		es++;
	
	}else if(1==es)
	{
		ont=TCNT0_REG;
		onc=ovfc;
		EXTI_voidInit(EXTI_INT0, EXTI_RISING_EDGE);
		
		es++;
		
	}else if(2==es)
	{
	  pt=TCNT0_REG;
	  pc=ovfc;
	  EXTI_voidInit(EXTI_INT0, EXTI_FALLING_EDGE);
	 
	  es++;
	
	}
	
	if(3==es)
	{
		f=(1000000UL)/((pt+(pc*256))*4);
		d=((ont+(onc*256))*4)/((pt+(pc*256))*4);
		es=0;
		
		/* Delay to make another capture after one second*/
		EXTI_voidDisable(EXTI_INT0);
		_delay_ms(1000);
		EXTI_voidInit(EXTI_INT0, EXTI_RISING_EDGE);
		if(d*100<100 && d*100>0)
		{PWM0_voidGeneratePWM(d*100);}
		
	//	u32 * ptr[8];
	//	for(u8 j=8; j>-1;j--)
	//	{
	//		ptr[j]=(u32) f%10;
	//		f=(u32)f/10;
	//		
	//	}
	//	for(u8 j=0; j<9;j++)
	//	{
	//		LCD_voidDisplayChar(ptr[j]);
			
	//	}
		while(f>0)
		{
			LCD_voidDisplayChar(f%10);
			f=f/10;
		
		}
		
		
	}
	
	
}

void action_OVF0(void)
{
	ovfc++;
}

//void __vector_2 (void) __attribute__((signal));
//void __vector_2 (void)
//{
//	//Action
//	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT); //INT0
//}
//void action_OVF0(void)
//{
//	LED_voidToggle(DIO_PORTC, DIO_PIN2);
//}
