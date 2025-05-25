/*
 * PWM0_interface.h
 *
 * Created: 15/02/2025 05:23:52 م
 *  Author: Kareem Hussein
 */ 


#ifndef PWM0_INTERFACE_H_
#define PWM0_INTERFACE_H_


                      /*************** APIS PROTOTYPES ***************/

void PWM0_voidInit       (void);
void PWM0_voidGeneratePWM(u8 copy_u8DutyCycle);
void PWM0_voidStop       (void);


#endif /* PWM0_INTERFACE_H_ */