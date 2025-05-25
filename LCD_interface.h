/*
 * LCD_interface.h
 *
 * Created: 17/01/2025 05:57:37 م
 *  Author: Kareem Hussein
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


                                /*************** APIS PROTO TYPES ***************/

void LCD_voidInit         (void);
void LCD_voidSendCommand  (u8 copy_u8cmnd);
void LCD_voidDisplayChar  (u8 copy_u8Data);


void LCD_voidDisplayString(u8* copy_pu8String); //loop on string

void LCD_voidClear(void); //command data sheet
void LCD_voidShift(u8 copy_u8ShifttingDirection); //command data sheet
void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position); //command data sheet

void LCD_voidDisplayNumber(u32 copy_u32Number); // Integer to string 


#endif /* LCD_INTERFACE_H_ */