/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2017 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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
 *  Rev B  2 JUN 2017
 *
 *  Converted to Arduino pin numbering
 */

/**
 *  There are two Arduino IDE extensions that are compatible with this board
 *  and with the mainstream Marlin software.
 *
 *  Teensyduino - http://www.pjrc.com/teensy/teensyduino.html
 *    Select Teensy++ 2.0 in Arduino IDE from the 'Tools -> Boards' menu
 *
 *    Installation instructions are at the above URL.  Don't bother loading the
 *    libraries - they are not used with the Marlin software.
 *
 *  Printrboard - https://github.com/scwimbush/Printrboard-HID-Arduino-IDE-Support
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

#ifndef __AVR_AT90USB1286__
  #error "Oops!  Make sure you have 'Teensy++ 2.0' or 'Printrboard' selected from the 'Tools -> Boards' menu."
#endif

#define DEFAULT_MACHINE_NAME    "SAV MkI"
#define  DEFAULT_SOURCE_CODE_URL "https:
#define BOARD_NAME              "SAV MkI"

//
// Servos
//
#define  SERVO0_PIN         39   

//
// Limit Switches
//
#define  X_STOP_PIN         25   
#define  Y_STOP_PIN         26   
//#define  Z_STOP_PIN         27   
#define  Z_STOP_PIN         36   
//#define  E_STOP_PIN         36   

//
// Steppers
//
#define  X_STEP_PIN         28   
#define  X_DIR_PIN          29   
#define  X_ENABLE_PIN       19   

#define  Y_STEP_PIN         30   
#define  Y_DIR_PIN          31   
#define  Y_ENABLE_PIN       18   

#define  Z_STEP_PIN         32   
#define  Z_DIR_PIN          33   
#define  Z_ENABLE_PIN       17   

#define  E0_STEP_PIN        34   
#define  E0_DIR_PIN         35   
#define  E0_ENABLE_PIN      13   

//
// Temperature Sensors
//
#define  TEMP_0_PIN          7   
#define  TEMP_BED_PIN        6   

//
// Heaters / Fans
//
#define  HEATER_0_PIN       15   
#define  HEATER_BED_PIN     14   

#ifndef FAN_PIN
  #define  FAN_PIN          16   
#endif

//
// Misc. Functions
//
#define  SDSS               20   

// Extension header pin mapping
// ----------------------------
//  SCL (I2C)-D0    A0 (An), IO
//  SDA (I2C)-D1    A1 (An), IO
//  RX1-D2          A2 (An), IO
//  TX1-D3          A3 (An), IO
//  PWM-D24         A4 (An), IO
//  5V              GND
//  12V             GND
#define  EXT_AUX_SCL_D0      0   
#define  EXT_AUX_SDA_D1      1   
#define  EXT_AUX_RX1_D2      2   
#define  EXT_AUX_TX1_D3      3   
#define  EXT_AUX_PWM_D24    24   
#define  EXT_AUX_A0          0   
#define  EXT_AUX_A0_IO      38   
#define  EXT_AUX_A1          1   
#define  EXT_AUX_A1_IO      39   
#define  EXT_AUX_A2          2   
#define  EXT_AUX_A2_IO      40   
#define  EXT_AUX_A3          3   
#define  EXT_AUX_A3_IO      41   
#define  EXT_AUX_A4          4   
#define  EXT_AUX_A4_IO      42   

//
// LCD / Controller
//
#define BEEPER_PIN         -1
#define LCD_PINS_RS        -1
#define LCD_PINS_ENABLE    -1

#if ENABLED(SAV_3DLCD)
  // For LCD SHIFT register LCD
  #define SR_DATA_PIN      EXT_AUX_SDA_D1
  #define SR_CLK_PIN       EXT_AUX_SCL_D0
#endif

#if ENABLED(SAV_3DLCD) || ENABLED(SAV_3DGLCD)

  #define BTN_EN1          EXT_AUX_A1_IO
  #define BTN_EN2          EXT_AUX_A0_IO
  #define BTN_ENC          EXT_AUX_PWM_D24

  #define KILL_PIN         EXT_AUX_A2_IO
  #define HOME_PIN         EXT_AUX_A4_IO

#else // Use the expansion header for spindle control

  //
  // M3/M4/M5 - Spindle/Laser Control
  //
  #define  SPINDLE_LASER_PWM_PIN    24   
  #define  SPINDLE_LASER_ENABLE_PIN 39   
  #define  SPINDLE_DIR_PIN          40   

  #define  CASE_LIGHT_PIN            0   

#endif
