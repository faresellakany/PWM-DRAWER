﻿/*
 * LCD_config.h
 *
 * Created: 17/01/2025 05:58:03 م
 *  Author: Kareem Hussein
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define LCD_RS_PORT			DIO_PORTB
#define LCD_RS_PIN			DIO_PIN1

#define LCD_E_PORT			DIO_PORTB
#define LCD_E_PIN			DIO_PIN2


#define LCD_DATA_PORT			DIO_PORTD

#define LCD_D4_PORT			DIO_PORTA
#define LCD_D4_PIN          DIO_PIN4

#define LCD_D5_PORT			DIO_PORTA
#define LCD_D5_PIN          DIO_PIN5

#define LCD_D6_PORT			DIO_PORTA
#define LCD_D6_PIN          DIO_PIN6

#define LCD_D7_PORT			DIO_PORTA
#define LCD_D7_PIN          DIO_PIN7

/* 
LCD_8_BIT_MODE
LCD_4_BIT_MODE
*/
#define LCD_MODE			LCD_4_BIT_MODE


#endif /* LCD_CONFIG_H_ */