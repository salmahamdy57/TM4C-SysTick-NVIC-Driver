/***********************************************************************************************************************************
 Module      : SysTick
 Name        : SysTick.h
 Author      : Salma Hamdy
 Description : Header file for the ARM Cortex M4 SysTick driver
 ************************************************************************************************************************************/


#ifndef SYSTICK_H_
#define SYSTICK_H_

/*******************************************************************************
 *                                Inclusions                                   *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
void SysTick_Init(uint16 a_TimeInMilliSeconds);

void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds);

void SysTick_Handler(void);

void SysTick_SetCallBack(volatile void (*Ptr2Func) (void));

void SysTick_Stop(void);

void SysTick_Start(void);

void SysTick_DeInit(void);

/*******************************************************************************
 *                                 End of File                                 *
 *******************************************************************************/

#endif /* SYSTICK_H_ */
