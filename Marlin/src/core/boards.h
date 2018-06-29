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

#ifndef BOARDS_H
#define BOARDS_H

#define BOARD_UNKNOWN -1

//
// RAMPS 1.3 / 1.4 - ATmega1280, ATmega2560
//

#define  BOARD_RAMPS_OLD         3     

#define  BOARD_RAMPS_13_EFB      33    
#define  BOARD_RAMPS_13_EEB      34    
#define  BOARD_RAMPS_13_EFF      35    
#define  BOARD_RAMPS_13_EEF      36    
#define  BOARD_RAMPS_13_SF       38    

#define  BOARD_RAMPS_14_EFB      43    
#define  BOARD_RAMPS_14_EEB      44    
#define  BOARD_RAMPS_14_EFF      45    
#define  BOARD_RAMPS_14_EEF      46    
#define  BOARD_RAMPS_14_SF       48    

#define  BOARD_RAMPS_PLUS_EFB   143    
#define  BOARD_RAMPS_PLUS_EEB   144    
#define  BOARD_RAMPS_PLUS_EFF   145    
#define  BOARD_RAMPS_PLUS_EEF   146    
#define  BOARD_RAMPS_PLUS_SF    148    

//
// RAMPS Derivatives - ATmega1280, ATmega2560
//

#define  BOARD_3DRAG             77    
#define  BOARD_K8200             78    
#define  BOARD_K8400             79    
#define  BOARD_BAM_DICE          401   
#define  BOARD_BAM_DICE_DUE      402   
#define  BOARD_MKS_BASE          40    
#define  BOARD_MKS_BASE_15       405   
#define  BOARD_MKS_BASE_HEROIC   41    
#define  BOARD_MKS_GEN_13        47    
#define  BOARD_MKS_GEN_L         53    
#define  BOARD_ZRIB_V20          504   
#define  BOARD_FELIX2            37    
#define  BOARD_RIGIDBOARD        42    
#define  BOARD_RIGIDBOARD_V2     52    
#define  BOARD_SAINSMART_2IN1    49    
#define  BOARD_ULTIMAKER         7     
#define  BOARD_ULTIMAKER_OLD     71    
#define  BOARD_AZTEEG_X3         67    
#define  BOARD_AZTEEG_X3_PRO     68    
#define  BOARD_ULTIMAIN_2        72    
#define  BOARD_RUMBA             80    
#define  BOARD_BQ_ZUM_MEGA_3D    503   
#define  BOARD_MAKEBOARD_MINI    431   
#define  BOARD_TRIGORILLA_13     343   
#define  BOARD_TRIGORILLA_14     443   
#define  BOARD_RAMPS_ENDER_4     243   

//
// Other ATmega1280, ATmega2560
//

#define  BOARD_CNCONTROLS_11     111   
#define  BOARD_CNCONTROLS_12     112   
#define  BOARD_CHEAPTRONIC       2     
#define  BOARD_CHEAPTRONIC_V2    21    
#define  BOARD_MIGHTYBOARD_REVE  200   
#define  BOARD_MEGATRONICS       70    
#define  BOARD_MEGATRONICS_2     701   
#define  BOARD_MEGATRONICS_3     703   
#define  BOARD_MEGATRONICS_31    704   
#define  BOARD_RAMBO             301   
#define  BOARD_MINIRAMBO         302   
#define  BOARD_MINIRAMBO_10A     303   
#define  BOARD_EINSY_RAMBO       304   
#define  BOARD_EINSY_RETRO       305   
#define  BOARD_ELEFU_3           21    
#define  BOARD_LEAPFROG          999   
#define  BOARD_MEGACONTROLLER    310   
#define  BOARD_SCOOVO_X9H        321   
#define  BOARD_GT2560_REV_A      74    
#define  BOARD_GT2560_REV_A_PLUS 75    

//
// ATmega1281, ATmega2561
//

#define  BOARD_MINITRONICS       702   
#define  BOARD_SILVER_GATE       25    

//
// Sanguinololu and Derivatives - ATmega644P, ATmega1284P
//

#define  BOARD_SANGUINOLOLU_11   6     
#define  BOARD_SANGUINOLOLU_12   62    
#define  BOARD_MELZI             63    
#define  BOARD_MELZI_MAKR3D      66    
#define  BOARD_MELZI_CREALITY    89    
#define  BOARD_MELZI_MALYAN      92    
#define  BOARD_MELZI_TRONXY      505   
#define  BOARD_STB_11            64    
#define  BOARD_AZTEEG_X1         65    
#define  BOARD_ANET_10           69    

//
// Other ATmega644P, ATmega644, ATmega1284P
//

#define  BOARD_GEN3_MONOLITHIC   22    
#define  BOARD_GEN3_PLUS         9     
#define  BOARD_GEN6              5     
#define  BOARD_GEN6_DELUXE       51    
#define  BOARD_GEN7_CUSTOM       10    
#define  BOARD_GEN7_12           11    
#define  BOARD_GEN7_13           12    
#define  BOARD_GEN7_14           13    
#define  BOARD_OMCA_A            90    
#define  BOARD_OMCA              91    
#define  BOARD_SETHI             20    

//
// Teensyduino - AT90USB1286, AT90USB1286P
//

#define  BOARD_TEENSYLU          8     
#define  BOARD_PRINTRBOARD       81    
#define  BOARD_PRINTRBOARD_REVF  811   
#define  BOARD_BRAINWAVE         82    
#define  BOARD_BRAINWAVE_PRO     85    
#define  BOARD_SAV_MKI           83    
#define  BOARD_TEENSY2           84    
#define  BOARD_5DPRINT           88    

//
// LPC1768 ARM Cortex M3
//

#define  BOARD_RAMPS_14_RE_ARM_EFB 1743  
#define  BOARD_RAMPS_14_RE_ARM_EEB 1744  
#define  BOARD_RAMPS_14_RE_ARM_EFF 1745  
#define  BOARD_RAMPS_14_RE_ARM_EEF 1746  
#define  BOARD_RAMPS_14_RE_ARM_SF  1748  
#define  BOARD_MKS_SBASE           1750  
#define  BOARD_AZSMZ_MINI          1751  
#define  BOARD_AZTEEG_X5_GT        1752  
#define  BOARD_BIQU_BQ111_A4       1753  
#define  BOARD_SELENA_COMPACT      1754  
#define  BOARD_COHESION3D_REMIX    1755  
#define  BOARD_COHESION3D_MINI     1756  

//
// SAM3X8E ARM Cortex M3
//

#define  BOARD_DUE3DOM          1411   
#define  BOARD_DUE3DOM_MINI     1412   
#define  BOARD_RADDS            1502   
#define  BOARD_RAMPS_FD_V1      1503   
#define  BOARD_RAMPS_FD_V2      1504   
#define  BOARD_RAMPS_SMART_EFB  1523   
#define  BOARD_RAMPS_SMART_EEB  1524   
#define  BOARD_RAMPS_SMART_EFF  1525   
#define  BOARD_RAMPS_SMART_EEF  1526   
#define  BOARD_RAMPS_SMART_SF   1528   
#define  BOARD_RAMPS_DUO_EFB    1533   
#define  BOARD_RAMPS_DUO_EEB    1534   
#define  BOARD_RAMPS_DUO_EFF    1535   
#define  BOARD_RAMPS_DUO_EEF    1536   
#define  BOARD_RAMPS_DUO_SF     1538   
#define  BOARD_RAMPS4DUE_EFB    1543   
#define  BOARD_RAMPS4DUE_EEB    1544   
#define  BOARD_RAMPS4DUE_EFF    1545   
#define  BOARD_RAMPS4DUE_EEF    1546   
#define  BOARD_RAMPS4DUE_SF     1548   
#define  BOARD_RURAMPS4D        1550   
#define  BOARD_ULTRATRONICS_PRO 1560   
#define  BOARD_ARCHIM2          1590   
#define  BOARD_ALLIGATOR        1602   

//
// STM32 ARM Cortex-M3
//

#define  BOARD_STM32F1R         1800   
#define  BOARD_MALYAN_M200      1801   
#define  BOARD_STM3R_MINI       1803   
#define  BOARD_GTM32_PRO_VB     1805   

//
// STM32 ARM Cortex-M4F
//

#define  BOARD_TEENSY35_36       841   
#define  BOARD_BEAST            1802   
#define  BOARD_STM32F4          1804   

//
// ARM Cortex M7
//

#define  BOARD_THE_BORG         1860   

//
// Espressif ESP32 WiFi
//
#define BOARD_ESP32            1900

#define MB(board) (defined(BOARD_##board) && MOTHERBOARD==BOARD_##board)

#endif // __BOARDS_H
