/*
 * LCD_private.h
 *
 * Created: 17/01/2025 05:58:25 م
 *  Author: Kareem Hussein
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_


#define LCD_8_BIT_MODE			1
#define LCD_4_BIT_MODE			2


static void	PRV_voidEnableTriggerWrite(void);
static void	PRV_voidWriteHalfPort(u8 copy_u8Value);

#endif /* LCD_PRIVATE_H_ */