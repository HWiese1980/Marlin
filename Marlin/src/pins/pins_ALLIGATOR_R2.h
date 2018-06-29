/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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

/**
 * Alligator Board R2
 * http://www.3dartists.org/
 */

#ifndef __SAM3X8E__
  #error "Oops!  Make sure you have 'Arduino Due' selected from the 'Tools -> Boards' menu."
#endif

#define BOARD_NAME            "Alligator Board R2"

//
// Servos
//
#define SERVO0_PIN            36
#define SERVO1_PIN            40
#define SERVO2_PIN            41
#define SERVO3_PIN            -1

//
// Limit Switches
//
#define  X_MIN_PIN             33   
#define  X_MAX_PIN             34   
#define  Y_MIN_PIN             35   
#define  Y_MAX_PIN             37   
#define  Z_MIN_PIN             38   
#define  Z_MAX_PIN             39   

//
// Steppers
//
#define  X_STEP_PIN            96   
#define  X_DIR_PIN              2   
#define  X_ENABLE_PIN          24   

#define  Y_STEP_PIN            94   
#define  Y_DIR_PIN             95   
#define  Y_ENABLE_PIN          24   

#define  Z_STEP_PIN            98   
#define  Z_DIR_PIN              3   
#define  Z_ENABLE_PIN          24   

#define  E0_STEP_PIN            5   
#define  E0_DIR_PIN             4   
#define  E0_ENABLE_PIN         24   

#define  E1_STEP_PIN           28   
#define  E1_DIR_PIN            27   
#define  E1_ENABLE_PIN         24   

#define  E2_STEP_PIN           11   
#define  E2_DIR_PIN            29   
#define  E2_ENABLE_PIN         24   

#define  E3_STEP_PIN           30   
#define  E3_DIR_PIN            12   
#define  E3_ENABLE_PIN         24   

// Microstepping pins - Mapping not from fastio.h (?)
#define  X_MS1_PIN             99   
#define  Y_MS1_PIN             10   
#define  Z_MS1_PIN             44   
#define  E0_MS1_PIN            45   

//#define  MOTOR_FAULT_PIN     22   

//
// Temperature Sensors
//
#define  TEMP_0_PIN             1   
#define  TEMP_1_PIN             2   
#define  TEMP_2_PIN             3   
#define  TEMP_3_PIN             4   
#define  TEMP_BED_PIN           0   

//
// Heaters / Fans
//
// Note that on the Due pin A0 on the board is channel 2 on the ARM chip
#define  HEATER_0_PIN          68   
#define  HEATER_1_PIN           8   
#define  HEATER_2_PIN           9   
#define  HEATER_3_PIN          97   
#define  HEATER_BED_PIN        69   

#ifndef FAN_PIN
  #define  FAN_PIN             92   
#endif
#define  FAN1_PIN              31   

//
// Misc. Functions
//
#define  SDSS                  77   
#define  SD_DETECT_PIN         87   
#define  LED_RED_PIN           40   
#define  LED_GREEN_PIN         41   

#define EXP_VOLTAGE_LEVEL_PIN 65

#define SPI_CHAN_DAC           1

#define  DAC0_SYNC             53   
#define  DAC1_SYNC              6   

// 64K SPI EEPROM
#define SPI_EEPROM
#define SPI_CHAN_EEPROM1       2
#define  SPI_EEPROM1_CS        25   

// 2K SPI EEPROM
#define  SPI_EEPROM2_CS        26   

// FLASH SPI
// 32Mb
#define  SPI_FLASH_CS          23   

//
// LCD / Controller
//
#if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)

  #define LCD_PINS_RS         18
  #define LCD_PINS_ENABLE     15
  #define LCD_PINS_D4         19
  #define BEEPER_PIN          64

  #define BTN_EN1             14
  #define BTN_EN2             16
  #define BTN_ENC             17

  #if UI_VOLTAGE_LEVEL != 1
    #undef UI_VOLTAGE_LEVEL
    #define UI_VOLTAGE_LEVEL   1
  #endif

#endif // REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
