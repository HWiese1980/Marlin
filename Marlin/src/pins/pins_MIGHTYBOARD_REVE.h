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
 * Mightyboard Rev.E pin assignments
 */

/**
 *
 * This is a starting-point to support the Makerbot Replicator series of 3D printers.
 * It's not functional because Marlin has limited support for some features.
 * Marlin will need the following augmentations before it will be supportable:
 *
 *   - Support for two or more MAX6675 thermocouples
 *   - Support for multiple i2c buses to control the MCP4018 digital pots
 *   - Support for one additional unidirectional SPI bus, to read the thermocouples
 *   - Support for an RGB LED that may work differently from BLINKM
 *
 * The MCP4018 requires separate I2C buses because it has a fixed address (0x2F << 1 = 0x5E)
 * The thermocouples share the same SCK and DO pins, with their own CS pins.
 * The controller interface port connects to a 3-wire shift-register display controller
 *
 */

/**
 * Rev B  2 JAN 2017
 *
 *  Added pin definitions for:
 *    M3, M4 & M5 spindle control commands
 *    case light
 *
 *  Corrected pin assignment for MOSFET_B_PIN pin. Changed it from 9 to 11.  The port
 *  number (B5) agrees with the schematic but B5 is assigned to logical pin 11.
 */

#if !defined(__AVR_ATmega1280__) && !defined(__AVR_ATmega2560__)
  #error "Oops! Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu."
#endif

#define DEFAULT_MACHINE_NAME    "MB Replicator"
#define BOARD_NAME              "Mightyboard"

//
// Servos
//
#define  SERVO0_PIN         36   
#define  SERVO1_PIN         37   
#define  SERVO2_PIN         40   
#define  SERVO3_PIN         41   

//
// Limit Switches
//
#define  X_MIN_PIN          49   
#define  X_MAX_PIN          48   
#define  Y_MIN_PIN          47   
#define  Y_MAX_PIN          46   
#define  Z_MIN_PIN          43   
#define  Z_MAX_PIN          42   

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  42
#endif

//
// Steppers
//
#define  X_STEP_PIN         55   
#define  X_DIR_PIN          54   
#define  X_ENABLE_PIN       56   

#define  Y_STEP_PIN         59   
#define  Y_DIR_PIN          58   
#define  Y_ENABLE_PIN       60   

#define  Z_STEP_PIN         63   
#define  Z_DIR_PIN          62   
#define  Z_ENABLE_PIN       64   

#define  E0_STEP_PIN        25   
#define  E0_DIR_PIN         24   
#define  E0_ENABLE_PIN      26   

#define  E1_STEP_PIN        29   
#define  E1_DIR_PIN         28   
#define  E1_ENABLE_PIN      39   

//
// I2C Digipots - MCP4018
// Address 5E (2F << 1)
// Set from 0 - 127 with stop bit.
// (Ex. 3F << 1 | 1)
//
#define  DIGIPOTS_I2C_SCL    76   
#define  DIGIPOTS_I2C_SDA_X  57   
#define  DIGIPOTS_I2C_SDA_Y  61   
#define  DIGIPOTS_I2C_SDA_Z  65   
#define  DIGIPOTS_I2C_SDA_E0 27   
#define  DIGIPOTS_I2C_SDA_E1 77   
#define  DIGIPOT_I2C_ADDRESS_A 0x2F   

//
// Temperature Sensors
//
#define  TEMP_BED_PIN        15   

// SPI for Max6675 or Max31855 Thermocouple
// Uses a separate SPI bus
//
//  3 E5 DO (SO)
//  5 E3 CS1
//  2 E4 CS2
// 78 E2 SCK
//
#define  THERMO_SCK_PIN     78   
#define  THERMO_DO_PIN       3   
#define  THERMO_CS1          5   
#define  THERMO_CS2          2   

#define MAX6675_SS         THERMO_CS1
#define MAX6675_SCK_PIN    THERMO_SCK_PIN
#define MAX6675_DO_PIN     THERMO_DO_PIN
//
// Augmentation for auto-assigning plugs
//
// Two thermocouple connectors allows for either
// 2 extruders or 1 extruder and a heated bed.
// With no heated bed, an additional 24V fan is possible.
//
#define  MOSFET_A_PIN        6   
#define  MOSFET_B_PIN       11   
#define  MOSFET_C_PIN       45   
#define  MOSFET_D_PIN       44   

#if HOTENDS > 1
  #if TEMP_SENSOR_BED
    #define IS_EEB
  #else
    #define IS_EEF
  #endif
#elif TEMP_SENSOR_BED
  #define IS_EFB
#else
  #define IS_EFF
#endif

//
// Heaters / Fans (24V)
//
#define HEATER_0_PIN     MOSFET_A_PIN

#if ENABLED(IS_EFB)                            // Hotend, Fan, Bed
  #define HEATER_BED_PIN   MOSFET_C_PIN
#elif ENABLED(IS_EEF)                          // Hotend, Hotend, Fan
  #define HEATER_1_PIN     MOSFET_B_PIN
#elif ENABLED(IS_EEB)                          // Hotend, Hotend, Bed
  #define HEATER_1_PIN     MOSFET_B_PIN
  #define HEATER_BED_PIN   MOSFET_C_PIN
#elif ENABLED(IS_EFF)                          // Hotend, Fan, Fan
  #define FAN1_PIN         MOSFET_C_PIN
#endif

#ifndef FAN_PIN
  #if ENABLED(IS_EFB) || ENABLED(IS_EFF)       // Hotend, Fan, Bed or Hotend, Fan, Fan
    #define FAN_PIN        MOSFET_B_PIN
  #elif ENABLED(IS_EEF) || ENABLED(IS_SF)      // Hotend, Hotend, Fan or Spindle, Fan
    #define FAN_PIN        MOSFET_C_PIN
  #else
    #define FAN_PIN        MOSFET_D_PIN
  #endif
#endif

//
// Extruder Auto Fan Pins
//
#define  ORIG_E0_AUTO_FAN_PIN  7   
#define  ORIG_E1_AUTO_FAN_PIN 12   

//
// Misc. Functions
//
#define  LED_PIN            13   
#define  CUTOFF_RESET_PIN   16   
#define  CUTOFF_TEST_PIN    17   
#define  CASE_LIGHT_PIN     44   

//
// LCD / Controller
//
#ifdef REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

  #define  LCD_PINS_RS      33   
  #define  LCD_PINS_ENABLE  72   
  #define  LCD_PINS_D4      35   
  #define  LCD_PINS_D5      32   
  #define  LCD_PINS_D6      34   
  #define  LCD_PINS_D7      31   

  #define  BTN_EN2          75   
  #define  BTN_EN1          73   
  //STOP button connected as KILL_PIN
  #define  KILL_PIN         14   
  //KILL - not connected

  #define  BEEPER_PIN        8   

  #define  BTN_CENTER       15   
  #define BTN_ENC          BTN_CENTER

  //on board leds
  #define  STAT_LED_RED_LED  SERVO0_PIN   
  #define  STAT_LED_BLUE_PIN SERVO1_PIN   

#else
  // Replicator uses a 3-wire SR controller with HD44780
  // For now, pretend it's the SAV
  //

  #define SAV_3DLCD
  #define  SR_DATA_PIN      34   
  #define  SR_CLK_PIN       35   
  #define  SR_STROBE_PIN    33   

  #define  BTN_UP           75   
  #define  BTN_DOWN         73   
  #define  BTN_LEFT         72   
  #define  BTN_RIGHT        14   
  #define  BTN_CENTER       15   
  #define BTN_ENC          BTN_CENTER

  #define  BEEPER_PIN        4   

  #define  STAT_LED_RED_PIN  32   
  #define  STAT_LED_BLUE_PIN 31   

#endif

//
// SD Card
//
#define  SDSS               53   
#define  SD_DETECT_PIN       9   

#define MAX_PIN             THERMO_SCK_PIN

//
// M3/M4/M5 - Spindle/Laser Control
//
#define  SPINDLE_LASER_ENABLE_PIN 66   
#define  SPINDLE_LASER_PWM_PIN     8   
#define  SPINDLE_DIR_PIN          67   


// Check if all pins are defined in mega/pins_arduino.h
#include <Arduino.h>
static_assert(NUM_DIGITAL_PINS > MAX_PIN, "add missing pins to [arduino dir]/hardware/arduino/avr/variants/mega/pins_arduino.h based on fastio.h"
                                          "to digital_pin_to_port_PGM, digital_pin_to_bit_mask_PGM, digital_pin_to_timer_PGM, NUM_DIGITAL_PINS, see below");

/* in [arduino dir]/hardware/arduino/avr/variants/mega/pins_arduino.h
change:
#define NUM_DIGITAL_PINS            70
to:
#define NUM_DIGITAL_PINS            80

to digital_pin_to_port_PGM add at the end:
const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
....
        PG      , // PG 4 ** 70 **
        PG      , // PG 3 ** 71 **
        PJ      , // PJ 2 ** 72 **
        PJ      , // PJ 3 ** 73 **
        PJ      , // PJ 7 ** 74 **
        PJ      , // PJ 4 ** 75 **
        PJ      , // PJ 5 ** 76 **
        PJ      , // PJ 6 ** 77 **
        PE      , // PE 2 ** 78 **
        PE      , // PE 6 ** 79 **
};

to digital_pin_to_bit_mask_PGM  add at the end:
const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
....
        _BV( 4 )        , // PG 4 ** 70 **
        _BV( 3 )        , // PG 3 ** 71 **
        _BV( 2 )        , // PJ 2 ** 72 **
        _BV( 3 )        , // PJ 3 ** 73 **
        _BV( 7 )        , // PJ 7 ** 74 **
        _BV( 4 )        , // PJ 4 ** 75 **
        _BV( 5 )        , // PJ 5 ** 76 **
        _BV( 6 )        , // PJ 6 ** 77 **
        _BV( 2 )        , // PE 2 ** 78 **
        _BV( 6 )        , // PE 6 ** 79 **
};

to digital_pin_to_timer_PGM add at the end:
const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
....
        NOT_ON_TIMER    , // PG 4 ** 70 **
        NOT_ON_TIMER    , // PG 3 ** 71 **
        NOT_ON_TIMER    , // PJ 2 ** 72 **
        NOT_ON_TIMER    , // PJ 3 ** 73 **
        NOT_ON_TIMER    , // PJ 7 ** 74 **
        NOT_ON_TIMER    , // PJ 4 ** 75 **
        NOT_ON_TIMER    , // PJ 5 ** 76 **
        NOT_ON_TIMER    , // PJ 6 ** 77 **
        NOT_ON_TIMER    , // PE 2 ** 78 **
        NOT_ON_TIMER    , // PE 6 ** 79 **
};
*/
