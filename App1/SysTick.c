/**************************************************************************************************************************************
 Module      : SysTick
 Name        : SysTick.c
 Author      : Salma Hamdy
 Description : Source file for the ARM Cortex M4 SysTick driver
 ***************************************************************************************************************************************/

#include "tm4c123gh6pm_registers.h"
#include "SysTick.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variable to hold the address of the call back function in the application */
static volatile void (*g_SysTickCallBackPtr)(void) = NULL_PTR;

/***************************************************************************************************************************************
 * Service Name: SysTick_Init
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): a_TimeInMilliSeconds - required time in milliseconds
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to initialize the SysTick timer with the specified time in milliseconds using interrupts.
****************************************************************************************************************************************/
void SysTick_Init(uint16 a_TimeInMilliSeconds)
{
    SYSTICK_CTRL_REG    = 0;                                      /* Disable the SysTick Timer by Clear the ENABLE Bit */
    SYSTICK_RELOAD_REG  = (16000 * a_TimeInMilliSeconds) - 1;     /* Set the reload value for 16MHz clock */
    SYSTICK_CURRENT_REG = 0;                                      /* Clear the Current Register value */
    /* Configure the SysTick Control Register
     * Enable the SysTick Timer (ENABLE = 1)
     * Enable SysTick Interrupt (INTEN = 1)
     * Choose the clock source to be System Clock (CLK_SRC = 1) */
    SYSTICK_CTRL_REG   |= 0x07;
}

/****************************************************************************************************************************************
 * Service Name: SysTick_StartBusyWait
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): a_TimeInMilliSeconds - required time in milliseconds
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to initialize the SysTick timer with the specified time in milliseconds using polling or busy-wait technique.
                The function should exit when the time is elapsed and stops the timer at the end.
****************************************************************************************************************************************/
void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds)
{
    SYSTICK_CTRL_REG    = 0;                                     /* Disable the SysTick Timer by Clear the ENABLE Bit */
    SYSTICK_RELOAD_REG  = (16000 * a_TimeInMilliSeconds) - 1;    /* Set the Reload value with 7999999 to count half Second */
    SYSTICK_CURRENT_REG = 0;                                     /* Clear the Current Register value */
    /* Configure the SysTick Control Register
     * Enable the SysTick Timer (ENABLE = 1)
     * Disable SysTick Interrupt (INTEN = 0)
     * Choose the clock source to be System Clock (CLK_SRC = 1) */
    SYSTICK_CTRL_REG   |= 0x05;

    while(!(SYSTICK_CTRL_REG & (1<<16)));                       /* Wait until the COUNT flag = 1 which mean SysTick Timer reaches ZERO value */

    SYSTICK_CTRL_REG = 0;                                       /* Disable SysTick after completion */
}

/***************************************************************************************************************************************
 * Service Name: SysTick_Handler
 * Sync/Async: Asynchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function Handler for SysTick interrupt used to call the call-back function..
****************************************************************************************************************************************/
void SysTick_Handler(void)
{
    if (g_SysTickCallBackPtr != NULL_PTR)
    {
        (*g_SysTickCallBackPtr)();       /* Call the callback function if it's set */
    }
}

/***************************************************************************************************************************************
 * Service Name: SysTick_SetCallBack
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Ptr2Func - Pointer to CallBack Function
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to setup the SysTick Timer call back to be executed in SysTick Handler.
****************************************************************************************************************************************/
void SysTick_SetCallBack(volatile void (*Ptr2Func) (void))
{
    g_SysTickCallBackPtr = Ptr2Func;       /* Set the callback function pointer */
}

/***************************************************************************************************************************************
 * Service Name: SysTick_Stop
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Stop the SysTick timer.
****************************************************************************************************************************************/
void SysTick_Stop(void)
{
    SYSTICK_CTRL_REG &= ~0x01;              /* Clear the ENABLE bit */
}

/***************************************************************************************************************************************
 * Service Name: SysTick_Start
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Start/Resume the SysTick timer.
****************************************************************************************************************************************/
void SysTick_Start(void)
{
    SYSTICK_CTRL_REG |= 0x01;               /* Set the ENABLE bit */
}

/***************************************************************************************************************************************
 * Service Name: SysTick_DeInit
 * Sync/Async: Synchronous
 * Reentrancy: Non-reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to De-initialize the SysTick Timer.
 ****************************************************************************************************************************************/
void SysTick_DeInit(void)
{
    SYSTICK_CTRL_REG = 0;                   /* Disable the SysTick Timer by Clear the ENABLE Bit */
    SYSTICK_RELOAD_REG = 0;                 /* Clear the reload value */
    SYSTICK_CURRENT_REG = 0;                /* Clear the Current Register value */
}

