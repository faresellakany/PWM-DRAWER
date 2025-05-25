﻿/*
 * PWM0_register.h
 *
 * Created: 15/02/2025 05:23:16 م
 *  Author: Kareem Hussein
 */ 


#ifndef PWM0_REGISTER_H_
#define PWM0_REGISTER_H_


// Timer/Counter Control Register
#define TCCR0_REG			(*(volatile u8*)0x53)
#define CS00                0
#define CS01                1
#define CS02                2
#define WGM01               3
#define COM00               4
#define COM01               5
#define WGM00               6
#define FOC0                7

// Timer/Counter Register
#define TCNT0_REG           (*(volatile u8*)0x52)

// Output Compare Register
#define OCR0_REG            (*(volatile u8*)0x5C)

// Timer/Counter Interrupt Mask Register
#define TIMSK_REG           (*(volatile u8*)0x59)
#define TOIE0               0
#define OCIE0               1

// Timer/Counter Interrupt Flag Register
#define TIFR_REG            (*(volatile u8*)0x58)
#define TOV0                0
#define OCF0                1


#endif /* PWM0_REGISTER_H_ */