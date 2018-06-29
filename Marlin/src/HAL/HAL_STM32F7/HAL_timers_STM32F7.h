/**
 * Marlin 3D Printer Firmware
 *
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 * Copyright (c) 2016 Bob Cousins bobcousins42@googlemail.com
 * Copyright (c) 2017 Victor Perez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _HAL_TIMERS_STM32F7_H
#define _HAL_TIMERS_STM32F7_H

// --------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------

#include <stdint.h>

// --------------------------------------------------------------------------
// Defines
// --------------------------------------------------------------------------

#define FORCE_INLINE __attribute__((always_inline)) inline

#define  hal_timer_t uint32_t  
#define HAL_TIMER_TYPE_MAX 0xFFFF

#define  HAL_TIMER_RATE         (HAL_RCC_GetSysClockFreq() / 2)  

#define  STEP_TIMER_NUM 0  
#define  TEMP_TIMER_NUM 1  
#define PULSE_TIMER_NUM STEP_TIMER_NUM

#define  TEMP_TIMER_FREQUENCY    1000 
#define  TEMP_TIMER_PRESCALE     1000 

#define  STEPPER_TIMER_PRESCALE 54    
#define  STEPPER_TIMER_RATE     (HAL_TIMER_RATE / STEPPER_TIMER_PRESCALE)   
#define  STEPPER_TIMER_TICKS_PER_US ((STEPPER_TIMER_RATE) / 1000000) 

#define  PULSE_TIMER_RATE       STEPPER_TIMER_RATE   
#define PULSE_TIMER_PRESCALE   STEPPER_TIMER_PRESCALE
#define PULSE_TIMER_TICKS_PER_US STEPPER_TIMER_TICKS_PER_US

#define ENABLE_STEPPER_DRIVER_INTERRUPT() HAL_timer_enable_interrupt(STEP_TIMER_NUM)
#define DISABLE_STEPPER_DRIVER_INTERRUPT() HAL_timer_disable_interrupt(STEP_TIMER_NUM)

#define ENABLE_TEMPERATURE_INTERRUPT() HAL_timer_enable_interrupt(TEMP_TIMER_NUM)
#define DISABLE_TEMPERATURE_INTERRUPT() HAL_timer_disable_interrupt(TEMP_TIMER_NUM)

// TODO change this


extern void TC5_Handler();
extern void TC7_Handler();
#define HAL_STEP_TIMER_ISR  void TC5_Handler()
#define HAL_TEMP_TIMER_ISR  void TC7_Handler()

// --------------------------------------------------------------------------
// Types
// --------------------------------------------------------------------------

typedef struct {
  TIM_HandleTypeDef timerdef;
  IRQn_Type   IRQ_Id;
  uint32_t callback;
} tTimerConfig;

// --------------------------------------------------------------------------
// Public Variables
// --------------------------------------------------------------------------

//extern const tTimerConfig timerConfig[];

// --------------------------------------------------------------------------
// Public functions
// --------------------------------------------------------------------------

void HAL_timer_start(const uint8_t timer_num, const uint32_t frequency);
void HAL_timer_enable_interrupt(const uint8_t timer_num);
void HAL_timer_disable_interrupt(const uint8_t timer_num);

void HAL_timer_set_compare(const uint8_t timer_num, const uint32_t compare);
hal_timer_t HAL_timer_get_compare(const uint8_t timer_num);
uint32_t HAL_timer_get_count(const uint8_t timer_num);
void HAL_timer_restrain(const uint8_t timer_num, const uint16_t interval_ticks);

void HAL_timer_isr_prologue(const uint8_t timer_num);
#define HAL_timer_isr_epilogue(TIMER_NUM)

#endif // _HAL_TIMERS_STM32F7_H
