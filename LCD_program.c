/*
 * LCD_program.c
 *
 * Created: 17/01/2025 05:57:21 م
 *  Author: Kareem Hussein
 */ 


#define  F_CPU			16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"


void LCD_voidInit(void)
{
	DIO_voidSetPinDirection(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_E_PORT,  LCD_E_PIN,  DIO_PIN_OUTPUT);
	
	_delay_ms(35);
	
#if LCD_MODE == LCD_8_BIT_MODE

	DIO_voidSetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	
	/* Function set (2Lines, 5*7 font) */
	LCD_voidSendCommand(0b00111000);
	_delay_us(45);
	
#elif LCD_MODE == LCD_4_BIT_MODE	
    
    DIO_voidSetPinDirection(LCD_D4_PORT, LCD_D4_PIN, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(LCD_D5_PORT, LCD_D5_PIN, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(LCD_D6_PORT, LCD_D6_PIN, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(LCD_D7_PORT, LCD_D7_PIN, DIO_PIN_OUTPUT);
	
	/* set Rs pin = 0 (command) */
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);
	PRV_voidWriteHalfPort(0b0010);
	/* Enable */
	PRV_voidEnableTriggerWrite();
	
	/* Function set (2Lines, 5*7 font) */
	LCD_voidSendCommand(0b00101000);
	_delay_us(45);
	
#endif

	/* Display On/Off Control (DisplayOn, Cursor on, Blink on) */
	LCD_voidSendCommand(0b00001111);
	_delay_us(45);
	
	/* Display Clear */
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
	
	/* Entry Mode Set (Increment on, Shift off)*/
	LCD_voidSendCommand(0b00000110);
}


void LCD_voidSendCommand(u8 copy_u8cmnd)
{
	/* set Rs pin = 0 (command) */
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);
	
#if LCD_MODE == LCD_8_BIT_MODE
	
	/* Write bits Of command on Data Pins */
	DIO_voidSetPortValue(LCD_DATA_PORT, copy_u8cmnd);
	/* Enable */
	PRV_voidEnableTriggerWrite();
	
#elif LCD_MODE == LCD_4_BIT_MODE
    
	// Write The Most 4 bits Of command on Data Pins
	PRV_voidWriteHalfPort(copy_u8cmnd >> 4);
	/* Enable */
	PRV_voidEnableTriggerWrite();
	
	// Write The Least 4 bits Of command on Data Pins
	PRV_voidWriteHalfPort(copy_u8cmnd);
	/* Enable */
	PRV_voidEnableTriggerWrite();
	
#endif
}


void LCD_voidDisplayChar(u8 copy_u8Data)
{
	/* set Rs pin = 1 (Data) */
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_HIGH);
	
#if LCD_MODE == LCD_8_BIT_MODE

    /* Write bits Of command on Data Pins */
    DIO_voidSetPortValue(LCD_DATA_PORT, copy_u8Data);
    /* Enable */
    PRV_voidEnableTriggerWrite();

#elif LCD_MODE == LCD_4_BIT_MODE

    // Write The Most 4 bits Of data on Data Pins
    PRV_voidWriteHalfPort(copy_u8Data >> 4);
    /* Enable */
    PRV_voidEnableTriggerWrite();
    
    // Write The Least 4 bits Of data on Data Pins
    PRV_voidWriteHalfPort(copy_u8Data);
    /* Enable */
    PRV_voidEnableTriggerWrite();

#endif
}


 void	PRV_voidEnableTriggerWrite(void)
{
	/* H -> L*/
	DIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_LOW);
}


 void	PRV_voidWriteHalfPort(u8 copy_u8Value)
{
	DIO_voidSetPinValue(LCD_D4_PORT, LCD_D4_PIN, GET_BIT(copy_u8Value, 0));
	DIO_voidSetPinValue(LCD_D5_PORT, LCD_D5_PIN, GET_BIT(copy_u8Value, 1));
	DIO_voidSetPinValue(LCD_D6_PORT, LCD_D6_PIN, GET_BIT(copy_u8Value, 2));
	DIO_voidSetPinValue(LCD_D7_PORT, LCD_D7_PIN, GET_BIT(copy_u8Value, 3));
}