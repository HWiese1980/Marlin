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
 * ARCHIM2 pin assignment (pins_ARCHIM2.h)
 *
 * The Archim2 board requires Arduino Archim addons installed.
 * Add the following URL to Arduino IDE's Additional Board Manager URLs:
 * https://raw.githubusercontent.com/ultimachine/ArduinoAddons/master/package_ultimachine_index.json
 * In the Arduino IDE Board Manager search for Archim and install the package.
 * Change your target board to "Archim".
 *
 * Further information is provided by UltiMachine
 * https://github.com/ultimachine/Archim/wiki/Archim-v2.0
 * https://github.com/ultimachine/Archim/wiki
 *
 */

#ifndef __SAM3X8E__
  #error "Oops!  Make sure you have 'Archim' selected from the 'Tools -> Boards' menu."
#endif

//
// Items marked * have been altered from Archim v1.0
//

// TMC2130 Diag Pins (currently just for reference)
#define  X_DIAG_PIN         59   
#define  Y_DIAG_PIN         48   
#define  Z_DIAG_PIN         36   
#define  E0_DIAG_PIN        78   
#define  E1_DIAG_PIN        25   

//
// Limit Switches
//
// Only use Diag Pins when SENSORLESS_HOMING is enabled for the TMC2130 drivers.
// Otherwise use a physical endstop based configuration.

#if DISABLED(SENSORLESS_HOMING)
 #define  X_MIN_PIN          14   
 #define  X_MAX_PIN          32   
 #define  Y_MIN_PIN          29   
 #define  Y_MAX_PIN          15   
#else
  #if X_HOME_DIR == -1
    #define X_MIN_PIN      X_DIAG_PIN
    #define X_MAX_PIN      32
  #else
    #define X_MIN_PIN      14
    #define X_MAX_PIN      X_DIAG_PIN
  #endif

  #if Y_HOME_DIR == -1
    #define Y_MIN_PIN      Y_DIAG_PIN
    #define Y_MAX_PIN      15
  #else
    #define Y_MIN_PIN      29
    #define Y_MAX_PIN      Y_DIAG_PIN
  #endif
#endif

 #define  Z_MIN_PIN          31   
 #define  Z_MAX_PIN          30   

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  32
#endif

//
// Steppers
//
#define  X_STEP_PIN         38   
#define  X_DIR_PIN          37   
#define  X_ENABLE_PIN       41   
#ifndef X_CS_PIN
  #define  X_CS_PIN         39   
#endif

#define  Y_STEP_PIN         51   
#define  Y_DIR_PIN          92   
#define  Y_ENABLE_PIN       49   
#ifndef Y_CS_PIN
  #define  Y_CS_PIN         50   
#endif

#define  Z_STEP_PIN         46   
#define  Z_DIR_PIN          47   
#define  Z_ENABLE_PIN       44   
#ifndef Z_CS_PIN
  #define  Z_CS_PIN         45   
#endif

#define  E0_STEP_PIN       107   
#define  E0_DIR_PIN         96   
#define  E0_ENABLE_PIN     105   
#ifndef E0_CS_PIN
  #define  E0_CS_PIN       104   
#endif

#define  E1_STEP_PIN        22   
#define  E1_DIR_PIN         97   
#define  E1_ENABLE_PIN      18   
#ifndef E1_CS_PIN
  #define  E1_CS_PIN        19   
#endif

//
// Software SPI pins for TMC2130 stepper drivers.
// Required for the Archim2 board.
//
#if ENABLED(TMC_USE_SW_SPI)
  #define  TMC_SW_MOSI      28   
  #define  TMC_SW_MISO      26   
  #define  TMC_SW_SCK       27   
#endif

//
// Temperature Sensors
//
#define  TEMP_0_PIN         10   
#define  TEMP_1_PIN          9   
#define  TEMP_2_PIN          8   
#define  TEMP_BED_PIN       11   

//
// Heaters / Fans
//
#ifndef FAN_PIN
  #define  FAN_PIN           4   
#endif
#define  FAN1_PIN            5   

#define  HEATER_0_PIN        6   
#define  HEATER_1_PIN        7   
#define  HEATER_2_PIN        8   
#define  HEATER_BED_PIN      9   

//
// Misc. Functions
//
#define  SDSS               87   

//////////////////////////
// LCDs and Controllers //
//////////////////////////

#if ENABLED(ULTRA_LCD)
  #if ENABLED(NEWPANEL)
    #define  BEEPER_PIN     23   
    #define  LCD_PINS_RS    17   
    #define  LCD_PINS_ENABLE 24  
    #define  LCD_PINS_D4    69   
    #define  LCD_PINS_D5    54   
    #define  LCD_PINS_D6    68   
    #define  LCD_PINS_D7    34   

    #define  SD_DETECT_PIN   2   

    // Buttons on AUX-2
    #define  BTN_EN1        60   
    #define  BTN_EN2        13   
    #define  BTN_ENC        16   
  #endif  // NEWPANEL
#endif // ULTRA_LCD
