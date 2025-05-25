/*
 * TMR0_interface.h
 *
 * Created: 08/02/2025 05:38:02 م
 *  Author: Kareem Hussein
 */ 


#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_


                      /*************** APIS PROTOTYPES ***************/

void TMR0_voidInit          (void);
void TMR0_voidStart         (void);
void TMR0_voidStop          (void);
void TMR0_voidSetCallBackOVF(void(*copy_pFunAction)(void));


#endif /* TMR0_INTERFACE_H_ */