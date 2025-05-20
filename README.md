# TM4C-SysTick-NVIC-Driver-Project

## Overview 📖
Develop low-level drivers for the **SysTick** timer and **Nested Vectored Interrupt Controller (NVIC)** on TI TM4C microcontrollers (16 MHz). Leverage **CMSIS-style APIs** for portability across ARM Cortex‑M platforms, ensuring modular, maintainable code and accurate millisecond-resolution timing.

## Objectives 🎯
1. **SysTick Timer Driver**
   - Initialize SysTick for millisecond-precision interrupts (≤ 1 ms resolution)
   - Start/stop timer in **interrupt** and **busy-wait** modes with low overhead
   - Implement `SysTick_Handler` ISR and **callback registration** for user-driven actions
   - Provide APIs: `SysTick_Init`, `SysTick_StartBusyWait`, `SysTick_Start`, `SysTick_Stop`, `SysTick_DeInit`, `SysTick_SetCallBack`

2. **NVIC Driver**
   - Enable/disable IRQs by IRQ number (`NVIC_EnableIRQ`, `NVIC_DisableIRQ`)
   - Set IRQ priority dynamically (`NVIC_SetPriorityIRQ`) with support for up to 256 levels
   - Manage ARM system/fault exceptions (e.g., SysTick, BusFault) to improve system robustness
   - Configure exception priority (`NVIC_EnableException`, `NVIC_DisableException`, `NVIC_SetPriorityException`)

## Features 💡
- **Periodic Callbacks**: Register custom callbacks for SysTick events to toggle LEDs or trigger tasks
- **Blocking & Non-Blocking Delays**: Choose between busy-wait and interrupt-driven delay methods
- **Dynamic IRQ Control**: Enable, disable, and reprioritize interrupts at runtime for flexible event handling
- **Fault Management**: Enable and prioritize system exceptions to handle hard faults and memory errors gracefully

## Drivers & API 📚
All APIs adhere to **CMSIS naming conventions**, are **reentrant-safe**, and clearly distinguish main-context versus ISR-safe functions.

- **SysTick Driver**:
  ```c
  void SysTick_Init(uint16 ms);
  void SysTick_StartBusyWait(uint16 ms);
  void SysTick_Handler(void);                  // ISR
  void SysTick_SetCallBack(void (*cb)(void));  // Register ISR callback
  void SysTick_Start(void);
  void SysTick_Stop(void);
  void SysTick_DeInit(void);

- **NVIC Driver**:
  ```c
  void NVIC_EnableIRQ(NVIC_IRQType irq);
  void NVIC_DisableIRQ(NVIC_IRQType irq);
  void NVIC_SetPriorityIRQ(NVIC_IRQType irq, NVIC_PriorityType prio);

  void NVIC_EnableException(NVIC_ExceptionType ex);
  void NVIC_DisableException(NVIC_ExceptionType ex);
  void NVIC_SetPriorityException(NVIC_ExceptionType ex, NVIC_PriorityType prio);
