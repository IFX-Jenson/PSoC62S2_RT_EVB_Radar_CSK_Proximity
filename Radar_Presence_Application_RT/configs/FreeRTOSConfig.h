/* ===========================================================================
** Copyright (C) 2021 Infineon Technologies AG. All rights reserved.
** ===========================================================================
**
** ===========================================================================
** Infineon Technologies AG (INFINEON) is supplying this file for use
** exclusively with Infineon's sensor products. This file can be freely
** distributed within development tools and software supporting such
** products.
**
** THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
** OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
** MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
** INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON
** WHATSOEVER.
** ===========================================================================
*/


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#if defined(__ICCARM__) || defined(__GNUC__)
#include "cy_pdl.h"
#endif

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

/* Ensure stdint is only used by the compiler, and not the assembler. */
#ifdef __ICCARM__
    #include <stdint.h>
    extern uint32_t SystemCoreClock;
#endif

#include "../libs/TARGET_CYSBSYSKIT-DEV-01/COMPONENT_BSP_DESIGN_MODUS/GeneratedSource/cycfg_system.h"

#define configTOTAL_HEAP_SIZE                       ( ( size_t ) ( CY_SRAM_SIZE - (64 * 1024)))
#define configUSE_DAEMON_TASK_STARTUP_HOOK          0
#define configUSE_PREEMPTION                        1
#define configUSE_IDLE_HOOK                         0
#define configUSE_TICK_HOOK                         0
#define configCPU_CLOCK_HZ                          ( SystemCoreClock )
#define configTICK_RATE_HZ                          ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES                        ( 7 )
#define configMINIMAL_STACK_SIZE                    ( ( unsigned short ) 130 )
#define configTIMER_TASK_STACK_DEPTH                ( configMINIMAL_STACK_SIZE * 2 )
#define configMAX_TASK_NAME_LEN                     ( 32 )
#define configUSE_TRACE_FACILITY                    1
#define configUSE_16_BIT_TICKS                      0
#define configIDLE_SHOULD_YIELD                     1
#define configUSE_MUTEXES                           1
#define configQUEUE_REGISTRY_SIZE                   8
#define configCHECK_FOR_STACK_OVERFLOW              2
#define configUSE_RECURSIVE_MUTEXES                 1
#define configUSE_MALLOC_FAILED_HOOK                1
#define configUSE_APPLICATION_TASK_TAG              0
#define configUSE_COUNTING_SEMAPHORES               1
#define configGENERATE_RUN_TIME_STATS               0
#define configENABLE_FPU                            1
#define configENABLE_MPU                            0
#define configENABLE_TRUSTZONE                      0
#define configSUPPORT_DYNAMIC_ALLOCATION            1
#define configSUPPORT_STATIC_ALLOCATION             1
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS     16
#define configUSE_NEWLIB_REENTRANT                  1

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES       0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Software timer definitions. */
#define configUSE_TIMERS                1
#define configTIMER_TASK_PRIORITY       ( 2 )
#define configTIMER_QUEUE_LENGTH        10
#define configTIMER_TASK_STACK_DEPTH    ( configMINIMAL_STACK_SIZE * 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet        1
#define INCLUDE_uxTaskPriorityGet       1
#define INCLUDE_vTaskDelete             1
#define INCLUDE_vTaskCleanUpResources   1
#define INCLUDE_vTaskSuspend            1
#define INCLUDE_vTaskDelayUntil         1
#define INCLUDE_vTaskDelay              1
#define INCLUDE_xTaskIsTaskFinished     1
#define INCLUDE_xTimerPendFunctionCall  1

/*
Interrupt nesting behavior configuration.
This is explained here: http://www.freertos.org/a00110.html

Priorities are controlled by two macros:
- configKERNEL_INTERRUPT_PRIORITY determines the priority of the RTOS daemon task
- configMAX_API_CALL_INTERRUPT_PRIORITY dictates the priority of ISRs that make API calls

Notes:
1. Interrupts that do not call API functions should be >= configKERNEL_INTERRUPT_PRIORITY
   and will nest.
2. Interrupts that call API functions must have priority between KERNEL_INTERRUPT_PRIORITY
   and MAX_API_CALL_INTERRUPT_PRIORITY (inclusive).
3. Interrupts running above MAX_API_CALL_INTERRUPT_PRIORITY are never delayed by the OS.
*/
/*
PSoC 6 __NVIC_PRIO_BITS = 3

0 (high)
1           MAX_API_CALL_INTERRUPT_PRIORITY 001xxxxx (0x3F)
2
3
4
5
6
7 (low)     KERNEL_INTERRUPT_PRIORITY       111xxxxx (0xFF)

!!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html

*/

/* Put KERNEL_INTERRUPT_PRIORITY in top __NVIC_PRIO_BITS bits of CM4 register */
#define configKERNEL_INTERRUPT_PRIORITY         0xFF
/*
Put MAX_SYSCALL_INTERRUPT_PRIORITY in top __NVIC_PRIO_BITS bits of CM4 register
NOTE For IAR compiler make sure that changes of this macro is reflected in
file portable\IAR\CM4F\portasm.s in PendSV_Handler: routine
*/
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    0x3F
/* configMAX_API_CALL_INTERRUPT_PRIORITY is a new name for configMAX_SYSCALL_INTERRUPT_PRIORITY
 that is used by newer ports only. The two are equivalent. */
#define configMAX_API_CALL_INTERRUPT_PRIORITY   configMAX_SYSCALL_INTERRUPT_PRIORITY


/* Normal assert() semantics without relying on the provision of an assert.h
header file. */
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names. */
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

/* Dynamic Memory Allocation Schemes */
#define HEAP_ALLOCATION_TYPE1                       (1)     /* heap_1.c*/
#define HEAP_ALLOCATION_TYPE2                       (2)     /* heap_2.c*/
#define HEAP_ALLOCATION_TYPE3                       (3)     /* heap_3.c*/
#define HEAP_ALLOCATION_TYPE4                       (4)     /* heap_4.c*/
#define HEAP_ALLOCATION_TYPE5                       (5)     /* heap_5.c*/
#define NO_HEAP_ALLOCATION                          (0)

#define configHEAP_ALLOCATION_SCHEME                (HEAP_ALLOCATION_TYPE3)

#if defined(CY_CFG_PWR_SYS_IDLE_MODE) && \
    ((CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_SLEEP) || \
    (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP))
extern void vApplicationSleep( uint32_t xExpectedIdleTime );
#define portSUPPRESS_TICKS_AND_SLEEP( xIdleTime ) vApplicationSleep( xIdleTime )
#define configUSE_TICKLESS_IDLE     2
#else
#define configUSE_TICKLESS_IDLE     0
#endif

/* Deep Sleep Latency Configuration */
#if CY_CFG_PWR_DEEPSLEEP_LATENCY > 0
#define configEXPECTED_IDLE_TIME_BEFORE_SLEEP   CY_CFG_PWR_DEEPSLEEP_LATENCY
#endif

#endif /* FREERTOS_CONFIG_H */

