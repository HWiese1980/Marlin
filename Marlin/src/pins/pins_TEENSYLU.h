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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.   If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 *  Rev C  2 JUN 2017
 *
 *  Converted to Arduino pin numbering
 */

/**
 *  There are two Arduino IDE extensions that are compatible with this board
 *  and with the mainstream Marlin software.  All have been used with Arduino 1.6.12
 *
 *  Teensyduino - http://www.pjrc.com/teensy/teensyduino.html
 *    Select Teensy++ 2.0 in Arduino IDE from the 'Tools -> Boards' menu
 *
 *    Installation instructions are at the above URL.  Don't bother loading the
 *    libraries - they are not used with the Marlin software.
 *
 *  Printrboard - https://github.com/scwimbush/Printrboard-HID-Arduino-IDE-Support
 *    This is basically Teensyduino but with a bootloader that can handle image sizes
 *    larger than 64K.
 *
 *    Installation:
 *
 *       1. Go to the above URL, click on the "Clone or Download" button and then
 *          click on "Download ZIP" button.
 *       2. Unzip the file, find the "printrboard" directory and then copy it to the
 *          hardware directory in Arduino.  The Arduino hardware directory will probably
 *          be located in a path similar to this: C:\Program Files (x86)\Arduino\hardware.
 *       3. Restart Arduino.
 *       4. Select "Printrboard" from the 'Tools -> Boards' menu.
 *
 *  Teensyduino is the most popular option. Printrboard is used if your board doesn't have
 *  the Teensyduino bootloader on it.
 */

/**
 *  To burn the bootloader that comes with Printrboard:
 *
 *   1. Connect your programmer to the board.
 *   2. In the Arduino IDE select "Printrboard" and then select the programmer.
 *   3. In the Arduino IDE click on "burn bootloader". Don't worry about the "verify failed at 1F000" error message.
 *   4. The programmer is no longer needed. Remove it.
 */

 /**
  *  SILKSCREEN ERROR
  *
  *  The silkscreen for the endstops do NOT match the schematic.  The silkscreen SHOULD
  *  read (from left to right) X-STOP, Y-STOP, Z-STOP & E-STOP.  The silkscreen actually
  *  reads                     E-STOP, X-STOP, Y-STOP & Z-STOP.
  *
  *  The pin assignments in this file match the silkscreen.
  */

#if !defined(__AVR_AT90USB1286__) && !defined(__AVR_AT90USB1286P__)
  #error "Oops!  Make sure you have 'Teensy++ 2.0' or 'Printrboard' selected from the 'Tools -> Boards' menu."
#endif

#define BOARD_NAME         "Teensylu"

//
// Limit Switch definitions that match the SCHEMATIC
//
//#define  X_STOP_PIN              25   
//#define  Y_STOP_PIN              26   
//#define  Z_STOP_PIN              27   
//#define  E_STOP_PIN              36   


//
// Limit Switch definitions that match the SILKSCREEN
//
#define  X_STOP_PIN              26   
#define  Y_STOP_PIN              27   
#define  Z_STOP_PIN              36   
//#define  E_STOP_PIN              25   

//
// Steppers
//
#define  X_STEP_PIN              28   
#define  X_DIR_PIN               29   
#define  X_ENABLE_PIN            19   

#define  Y_STEP_PIN              30   
#define  Y_DIR_PIN               31   
#define  Y_ENABLE_PIN            18   

#define  Z_STEP_PIN              32   
#define  Z_DIR_PIN               33   
#define  Z_ENABLE_PIN            17   

#define  E0_STEP_PIN             34   
#define  E0_DIR_PIN              35   
#define  E0_ENABLE_PIN           13   

//
// Temperature Sensors
//
#define  TEMP_0_PIN               7   
#define  TEMP_BED_PIN             6   

//
// Heaters / Fans
//
#define  HEATER_0_PIN            15   
#define  HEATER_BED_PIN          14   

#ifndef FAN_PIN
  #define  FAN_PIN               16   
#endif

//
// Misc. Functions
//
#define  SDSS                    20   
#define  CASE_LIGHT_PIN           0   

//
// LCD / Controller
//
#if ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL)

  #define BEEPER_PIN            -1

  #if ENABLED(LCD_I2C_PANELOLU2)
    #define  BTN_EN1              3   
    #define  BTN_EN2              2   
    #define  BTN_ENC             41   
    #define  SDSS                38   
  #endif

  #define SD_DETECT_PIN         -1

#endif // ULTRA_LCD && NEWPANEL

//
// M3/M4/M5 - Spindle/Laser Control
//
#define  SPINDLE_LASER_PWM_PIN    24   
#define  SPINDLE_LASER_ENABLE_PIN 39   
#define  SPINDLE_DIR_PIN          40   
