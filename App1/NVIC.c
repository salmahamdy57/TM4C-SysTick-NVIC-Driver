/***********************************************************************************************************************************
 Module      : NVIC
 Name        : NVIC.c
 Author      : Salma Hamdy
 Description : Source file for the ARM Cortex M4 NVIC driver
 ************************************************************************************************************************************/

#include "tm4c123gh6pm_registers.h"
#include "NVIC.h"


/***************************************************************************************************************************************
 * Service Name: NVIC_EnableIRQ
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to enable an Interrupt request for a specific IRQ
 ****************************************************************************************************************************************/
void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num)
{
    if (IRQ_Num < 32)
    {
        NVIC_EN0_REG |= (1 << IRQ_Num);          /* Enable IRQ in EN0 register (IRQ numbers 0-31) */
    }
    else if (IRQ_Num < 64)
    {
        NVIC_EN1_REG |= (1 << (IRQ_Num - 32));   /* Enable IRQ in EN1 register (IRQ numbers 32-63) */
    }
    else if (IRQ_Num < 96)
    {
        NVIC_EN2_REG |= (1 << (IRQ_Num - 64));   /* Enable IRQ in EN2 register (IRQ numbers 64-95) */
    }
    else if (IRQ_Num < 128)
    {
        NVIC_EN3_REG |= (1 << (IRQ_Num - 96));   /* Enable IRQ in EN3 register (IRQ numbers 96-127) */
    }
    else
    {
        NVIC_EN4_REG |= (1 << (IRQ_Num - 128));  /* Enable IRQ in EN4 register (IRQ numbers 128-159) */
    }
}

/***************************************************************************************************************************************
 * Service Name: NVIC_DisableIRQ
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to disable an Interrupt request for a specific IRQ
 ****************************************************************************************************************************************/
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num)
{
    if (IRQ_Num < 32)
    {
        NVIC_DIS0_REG |= (1 << IRQ_Num);          /* Disable IRQ in DIS0 register (IRQ numbers 0-31) */
    }
    else if (IRQ_Num < 64)
    {
        NVIC_DIS1_REG |= (1 << (IRQ_Num - 32));   /* Disable IRQ in DIS1 register (IRQ numbers 32-63) */
    }
    else if (IRQ_Num < 96)
    {
        NVIC_DIS2_REG |= (1 << (IRQ_Num - 64));   /* Disable IRQ in DIS2 register (IRQ numbers 64-95) */
    }
    else if (IRQ_Num < 128)
    {
        NVIC_DIS3_REG |= (1 << (IRQ_Num - 96));   /* Disable IRQ in DIS3 register (IRQ numbers 96-127) */
    }
    else
    {
        NVIC_DIS4_REG |= (1 << (IRQ_Num - 128));  /* Disable IRQ in DIS4 register (IRQ numbers 128-159) */
    }
}
/***************************************************************************************************************************************
 * Service Name: NVIC_SetPriorityIRQ
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): IRQ_Num - Number of the IRQ from the target vector table,
                    IRQ_Priority - Priority of the IRQ from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the priority value for a specific IRQ.
 ****************************************************************************************************************************************/
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority)
{
    uint8 priority_register = IRQ_Num / 4;       /* Calculate which priority register to use based on the IRQ number. (each register handles 4 IRQs) */
    uint8 priority_shift = (IRQ_Num % 4) * 8;    /* Calculate the bit shift based on the position of the IRQ in the register (each IRQ occupies 8 bits). */

    /* Set the priority in the corresponding register */
    if (priority_register == 0)
    {
        NVIC_PRI0_REG = (NVIC_PRI0_REG & ~(0xFF << priority_shift)) | (IRQ_Priority << priority_shift);   /* Clear the previous bits and set the new priority for IRQ in NVIC_PRI0_REG. */
    }
    else if (priority_register == 1)
    {
        NVIC_PRI1_REG = (NVIC_PRI1_REG & ~(0xFF << priority_shift)) | (IRQ_Priority << priority_shift);   /* Clear the previous bits and set the new priority for IRQ in NVIC_PRI1_REG. */
    }
    else if (priority_register == 2)
    {
        NVIC_PRI2_REG = (NVIC_PRI2_REG & ~(0xFF << priority_shift)) | (IRQ_Priority << priority_shift);   /* Clear the previous bits and set the new priority for IRQ in NVIC_PRI2_REG. */
    }
    else if (priority_register == 3)
    {
        NVIC_PRI3_REG = (NVIC_PRI3_REG & ~(0xFF << priority_shift)) | (IRQ_Priority << priority_shift);   /* Clear the previous bits and set the new priority for IRQ in NVIC_PRI3_REG. */
    }
    else if (priority_register == 4)
    {
        NVIC_PRI4_REG = (NVIC_PRI4_REG & ~(0xFF << priority_shift)) | (IRQ_Priority << priority_shift);   /* Clear the previous bits and set the new priority for IRQ in NVIC_PRI4_REG. */
    }
    else if (priority_register == 5)
    {
        NVIC_PRI5_REG = (NVIC_PRI5_REG & ~(0xFF << priority_shift)) | (IRQ_Priority << priority_shift);   /* Clear the previous bits and set the new priority for IRQ in NVIC_PRI5_REG. */
    }
    else if (priority_register == 6)
    {
        NVIC_PRI6_REG = (NVIC_PRI6_REG & ~(0xFF << priority_shift)) | (IRQ_Priority << priority_shift);   /* Clear the previous bits and set the new priority for IRQ in NVIC_PRI6_REG. */
    }
    else if (priority_register == 7)
    {
        NVIC_PRI7_REG = (NVIC_PRI7_REG & ~(0xFF << priority_shift)) | (IRQ_Priority << priority_shift);   /* Clear the previous bits and set the new priority for IRQ in NVIC_PRI7_REG. */
    }
    else if (priority_register == 8)
    {
        NVIC_PRI8_REG = (NVIC_PRI8_REG & ~(0xFF << priority_shift)) | (IRQ_Priority << priority_shift);   /* Clear the previous bits and set the new priority for IRQ in NVIC_PRI8_REG. */
    }
    else if (priority_register == 9)
    {
        NVIC_PRI9_REG = (NVIC_PRI9_REG & ~(0xFF << priority_shift)) | (IRQ_Priority << priority_shift);   /* Clear the previous bits and set the new priority for IRQ in NVIC_PRI9_REG. */
    }
}

/***************************************************************************************************************************************
 * Service Name: NVIC_EnableException
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): Exception_Num - Number of the Exception from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to enable specific ARM system or fault exceptions.
 ****************************************************************************************************************************************/
void NVIC_EnableException(NVIC_ExceptionType Exception_Num)
{
    switch (Exception_Num)
    {
    case EXCEPTION_MEM_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL |= MEM_FAULT_ENABLE_MASK;     /* Set Memory Fault Enable */
        break;
    case EXCEPTION_BUS_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL |= BUS_FAULT_ENABLE_MASK;     /* Set Bus Fault Enable */
        break;
    case EXCEPTION_USAGE_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL |= USAGE_FAULT_ENABLE_MASK;   /* Set Usage Fault Enable */
        break;
    case EXCEPTION_SVC_TYPE:
    case EXCEPTION_DEBUG_MONITOR_TYPE:
    case EXCEPTION_PEND_SV_TYPE:
    case EXCEPTION_SYSTICK_TYPE:
        break;                                               /* No change in SYSHNDCTRL */
    default:
        break;
    }
}
/***************************************************************************************************************************************
 * Service Name: NVIC_DisableException
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): Exception_Num - Number of the Exception from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to disable specific ARM system or fault exceptions.
 ****************************************************************************************************************************************/
void NVIC_DisableException(NVIC_ExceptionType Exception_Num)
{
    switch (Exception_Num)
    {
    case EXCEPTION_MEM_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL &= ~MEM_FAULT_ENABLE_MASK;   /* Clear Memory Fault Enable */
        break;
    case EXCEPTION_BUS_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL &= ~BUS_FAULT_ENABLE_MASK;   /* Clear Bus Fault Enable */
        break;
    case EXCEPTION_USAGE_FAULT_TYPE:
        NVIC_SYSTEM_SYSHNDCTRL &= ~USAGE_FAULT_ENABLE_MASK; /* Clear Usage Fault Enable */
        break;
    case EXCEPTION_SVC_TYPE:
    case EXCEPTION_DEBUG_MONITOR_TYPE:
    case EXCEPTION_PEND_SV_TYPE:
    case EXCEPTION_SYSTICK_TYPE:
        break;                                              /* No change in SYSHNDCTRL */
    default:
        break;
    }
}
/***************************************************************************************************************************************
 * Service Name: NVIC_SetPriorityException
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): Exception_Num - Number of the Exception from the target vector table,
                    Exception_Priority - Priority of the Exception from the target vector table
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the priority value for specific ARM system or fault exceptions.
 ****************************************************************************************************************************************/
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority)
{
    uint32 priority = (uint32)Exception_Priority;        /* Convert the exception priority to uint32 type */

    switch (Exception_Num)
    {
    case EXCEPTION_MEM_FAULT_TYPE:
        /* Clear the previous priority settings by masking out the bits defined for MEM_FAULT_PRIORITY_MASK,
         * Set the new priority by shifting it into the correct position defined by MEM_FAULT_PRIORITY_BITS_POS. */
        NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG & ~MEM_FAULT_PRIORITY_MASK) | (priority << MEM_FAULT_PRIORITY_BITS_POS);
        break;

    case EXCEPTION_BUS_FAULT_TYPE:
        /* Clear the previous priority settings by masking out the bits defined for BUS_FAULT_PRIORITY_MASK,
         * Set the new priority by shifting it into the correct position defined by BUS_FAULT_PRIORITY_BITS_POS. */
        NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG & ~BUS_FAULT_PRIORITY_MASK) | (priority << BUS_FAULT_PRIORITY_BITS_POS);
        break;

    case EXCEPTION_USAGE_FAULT_TYPE:
        /* Clear the previous priority settings by masking out the bits defined for USAGE_FAULT_PRIORITY_MASK,
         * Set the new priority by shifting it into the correct position defined by USAGE_FAULT_PRIORITY_BITS_POS. */
        NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG & ~USAGE_FAULT_PRIORITY_MASK) | (priority << USAGE_FAULT_PRIORITY_BITS_POS);
        break;

    case EXCEPTION_SVC_TYPE:
        /* Clear the previous priority settings by masking out the bits defined for SVC_PRIORITY_MASK,
         * Set the new priority by shifting it into the correct position defined by SVC_PRIORITY_BITS_POS. */
        NVIC_SYSTEM_PRI2_REG = (NVIC_SYSTEM_PRI2_REG & ~SVC_PRIORITY_MASK) | (priority << SVC_PRIORITY_BITS_POS);
        break;

    case EXCEPTION_DEBUG_MONITOR_TYPE:
        /* Clear the previous priority settings by masking out the bits defined for DEBUG_MONITOR_PRIORITY_MASK,
         * Set the new priority by shifting it into the correct position defined by DEBUG_MONITOR_PRIORITY_BITS_POS. */
        NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & ~DEBUG_MONITOR_PRIORITY_MASK) | (priority << DEBUG_MONITOR_PRIORITY_BITS_POS);
        break;

    case EXCEPTION_PEND_SV_TYPE:
        /* Clear the previous priority settings by masking out the bits defined for PENDSV_PRIORITY_MASK,
         * Set the new priority by shifting it into the correct position defined by PENDSV_PRIORITY_BITS_POS. */
        NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & ~PENDSV_PRIORITY_MASK) | (priority << PENDSV_PRIORITY_BITS_POS);
        break;

    case EXCEPTION_SYSTICK_TYPE:
        /* Clear the previous priority settings by masking out the bits defined for SYSTICK_PRIORITY_MASK,
         * Set the new priority by shifting it into the correct position defined by SYSTICK_PRIORITY_BITS_POS. */
        NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & ~SYSTICK_PRIORITY_MASK) | (priority << SYSTICK_PRIORITY_BITS_POS);
        break;

    default:
        break;
    }

}



