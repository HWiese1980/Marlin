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
 *  Teensyduino -  https://www.pjrc.com/teensy/teensyduino.html
 *  Installation - https://www.pjrc.com/teensy/td_download.html
 *
 *    Select Teensy++ 2.0 in Arduino IDE from the 'Tools -> Boards' menu
 *
 *    Note: With Teensyduino extension, the Arduino IDE will report 130048 bytes of program storage space available,
 *    but there is actually only 122880 bytes due to the larger DFU bootloader shipped by default on all Printrboard RevF.
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
 *  Teensyduino is the most popular and easiest option.
 */

/**
 *  To burn the bootloader that comes with Printrboard HID extension:
 *
 *   1. Connect your programmer to the board.
 *   2. In the Arduino IDE select "Printrboard" and then select the programmer.
 *   3. In the Arduino IDE click on "burn bootloader". Don't worry about the "verify failed at 1F000" error message.
 *   4. The programmer is no longer needed. Remove it.
 */

#ifndef __AVR_AT90USB1286__
  #error "Oops!  Make sure you have 'Teensy++ 2.0' or 'Printrboard' selected from the 'Tools -> Boards' menu."
#endif

#ifndef USBCON
  #error "USBCON should be defined by the platform for this board."
#endif

#define BOARD_NAME         "Printrboard Rev.F"
// Disable JTAG pins so EXP1 pins work correctly
// (Its pins are used for the Extrudrboard and filament sensor, for example).
#define DISABLE_JTAG

/**
 * Note that REV F6 of the Printrboard stole the A HOTEND pin and
 * reassigned it to a second fan for the extruder heater.  It's
 * recommended that you swap the A and B outputs on the Extrudrboard
 * so EXTRUDERS=2 will still work on F6, using B for E1/HEATER_1/TEMP_1.
 * See https://printrbot.zendesk.com/hc/en-us/articles/115003072346
 *
 * If you have REV F6 you probably also want to set E0_AUTO_FAN_PIN
 * to PRINTRBOARD_F6_HEATER_FAN_PIN (44).
 *
 * Define NO_EXTRUDRBOARD if you don't have an EXTRUDRBOARD and wish to
 * reassign different functions to EXP1.
 *
 * Define NO_EXTRUDRBOARD_OUTPUT_SWAP if you have a REV F5 or lower and
 * want to use EXTRUDRBOARD A for E1 and EXTRUDRBOARD B for E2.
 */
//#define NO_EXTRUDRBOARD
//#define NO_EXTRUDRBOARD_OUTPUT_SWAP

//
// Limit Switches
//
#define  X_STOP_PIN         47   
#define  Y_STOP_PIN         24   
#define  Z_STOP_PIN         36   

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

#if DISABLED(NO_EXTRUDRBOARD)
#if DISABLED(NO_EXTRUDRBOARD_OUTPUT_SWAP)
  #define  E1_STEP_PIN      25   
  #define  E1_DIR_PIN       37   
  #define  E1_ENABLE_PIN    42   

  #define  E2_STEP_PIN       2   
  #define  E2_DIR_PIN        3   
  #define  E2_ENABLE_PIN    43   
#else
  #define  E1_STEP_PIN       2   
  #define  E1_DIR_PIN        3   
  #define  E1_ENABLE_PIN    43   

  #define  E2_STEP_PIN      25   
  #define  E2_DIR_PIN       37   
  #define  E2_ENABLE_PIN    42   
#endif
#endif // NO_EXTRUDRBOARD

// Enable control of stepper motor currents with the I2C based MCP4728 DAC used on Printrboard REVF
#define DAC_STEPPER_CURRENT

// Set default drive strength percents if not already defined - X, Y, Z, E axis
#ifndef DAC_MOTOR_CURRENT_DEFAULT
  #define DAC_MOTOR_CURRENT_DEFAULT { 70, 70, 50, 70 }
#endif

// Number of channels available for DAC
#define DAC_STEPPER_ORDER { 3, 2, 1, 0 }

#define DAC_STEPPER_SENSE    0.11
#define DAC_STEPPER_ADDRESS  0
#define DAC_STEPPER_MAX   3520
#define  DAC_STEPPER_VREF     1   
#define DAC_STEPPER_GAIN     0
#define DAC_OR_ADDRESS    0x00

//
// Temperature Sensors
//
#define  TEMP_0_PIN          1   
#define  TEMP_BED_PIN        0   

#if DISABLED(NO_EXTRUDRBOARD)
#if DISABLED(NO_EXTRUDRBOARD_OUTPUT_SWAP)
  #define  TEMP_1_PIN        2   
  #define  TEMP_2_PIN        3   
#else
  #define  TEMP_1_PIN        3   
  #define  TEMP_2_PIN        2   
#endif
#endif

//
// Heaters / Fans
//
#define  HEATER_0_PIN       15   
#define  HEATER_BED_PIN     14   

#if DISABLED(NO_EXTRUDRBOARD)
#if DISABLED(NO_EXTRUDRBOARD_OUTPUT_SWAP)
  #define  HEATER_1_PIN     44   
  #define  HEATER_2_PIN     45   
#else
  #define  HEATER_1_PIN     45   
  #define  HEATER_2_PIN     44   
#endif
#endif

#ifndef FAN_PIN
  #define  FAN_PIN          16   
#endif

//
// LCD / Controller
//
//#define USE_INTERNAL_SD

#if ENABLED(ULTRA_LCD)
  #define  LCD_PINS_RS       9   
  #define  LCD_PINS_ENABLE   8   
  #define  LCD_PINS_D4       7   
  #define  LCD_PINS_D5       6   
  #define  LCD_PINS_D6       5   
  #define  LCD_PINS_D7       4   

  #if ENABLED(VIKI2) || ENABLED(miniVIKI)

    #define  BEEPER_PIN      8   
    #define  DOGLCD_A0      40   
    #define  DOGLCD_CS      41   
    #define LCD_SCREEN_ROT_180

    #define  BTN_EN1         2   
    #define  BTN_EN2         3   
    #define  BTN_ENC        45   

    #define  SDSS            3   

    #define  STAT_LED_RED_PIN  12   
    #define  STAT_LED_BLUE_PIN 10   

  #elif ENABLED(MINIPANEL)

    #if DISABLED(USE_INTERNAL_SD)
      //      PIN       FASTIO PIN#  ATUSB90 PIN# Teensy2.0++ PIN#  Printrboard RevF Conn.   MKSLCD12864 PIN#
      #define  SDSS          11   
      #define  SD_DETECT_PIN  9   
    #endif

    //      PIN       FASTIO PIN#  ATUSB90 PIN# Teensy2.0++ PIN#  Printrboard RevF Conn.   MKSLCD12864 PIN#
    #define  DOGLCD_A0       4   
    #define  DOGLCD_CS       5   
    #define  BTN_ENC         6   
    #define  BEEPER_PIN      7   
    #define  KILL_PIN        8   
    #define  BTN_EN1        10   
    #define  BTN_EN2        12   
    //#define  LCD_BACKLIGHT_PIN 43   
    //#define  SCK          21   
    //#define  MOSI         22   
    //#define  MISO         23   

    // increase delays
    #ifndef ST7920_DELAY_1
      #define ST7920_DELAY_1 DELAY_NS(313)
    #endif
    #ifndef ST7920_DELAY_2
      #define ST7920_DELAY_2 DELAY_NS(313)
    #endif
    #ifndef ST7920_DELAY_3
      #define ST7920_DELAY_3 DELAY_NS(313)
    #endif

  #else

    #define  BTN_EN1        10   
    #define  BTN_EN2        11   
    #define  BTN_ENC        12   

  #endif

#endif

//
// Misc. Functions
//
//      PIN       FASTIO PIN#  ATUSB90 PIN# Teensy2.0++ PIN#  Printrboard RevF Conn.
#ifndef SDSS
  #define  SDSS             20   
#endif

/**
 * This is EXP1-2, which is also the TEMP_A_PIN for the Extrudrboard.
 * If using w/ Extrudrboard, cut off pin 2 on the Extrudrboard male
 * connector to ensure this is disconnected from the A THERM pullups.
 * You probably want to set EXTRUDERS=2 and swap the Extrudrboard outputs,
 * which will let you use Channel B on the Extrudrboard as E1.
 */
#ifndef FILWIDTH_PIN
  #define  FILWIDTH_PIN      2   
#endif
