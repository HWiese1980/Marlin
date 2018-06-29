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
 * MKS BASE v1.5 with A4982 stepper drivers and digital micro-stepping
 */

#include "pins_MKS_BASE.h"

/**
 * Microstepping pins
 */
#define  X_MS1_PIN            5   
#define  X_MS2_PIN            6   
#define  Y_MS1_PIN           59   
#define  Y_MS2_PIN           58   
#define  Z_MS1_PIN           22   
#define  Z_MS2_PIN           39   
#define  E0_MS1_PIN          63   
#define  E0_MS2_PIN          64   
#define  E1_MS1_PIN          57   
#define  E1_MS2_PIN           4   
