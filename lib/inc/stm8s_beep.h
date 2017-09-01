/**
  ******************************************************************************
  * @file    stm8s_beep.h
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all functions prototype and macros for the beep peripheral.
  * @Date:   2016-03-29 14:06:05
  * @Last Modified by:   nhantt
  * @Last Modified time: 2017-03-21 23:07:13
   ******************************************************************************
*/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8S_BEEP_H
#define __STM8S_BEEP_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/*BEEP Frequency selection*/
typedef enum {
  BEEP_FREQUENCY_1KHZ = (uint8_t)0x00,  /*!< Beep signal output frequency equals to 1 KHz */
  BEEP_FREQUENCY_2KHZ = (uint8_t)0x40,  /*!< Beep signal output frequency equals to 2 KHz */
  BEEP_FREQUENCY_4KHZ = (uint8_t)0x80   /*!< Beep signal output frequency equals to 4 KHz */
} BEEP_Frequency_TypeDef;

/* BEEP_Exported_Constants */

#define BEEP_CALIBRATION_DEFAULT ((uint8_t)0x0B) /*!< Default value when calibration is not done */

#define LSI_FREQUENCY_MIN ((uint32_t)110000) /*!< LSI minimum value in Hertz */
#define LSI_FREQUENCY_MAX ((uint32_t)150000) /*!< LSI maximum value in Hertz */

/* Macro used by the assert function to check the different functions parameters.*/

/* Macro used by the assert function to check the BEEP frequencies.*/
#define IS_BEEP_FREQUENCY_OK(FREQ) \
  (((FREQ) == BEEP_FREQUENCY_1KHZ) || \
   ((FREQ) == BEEP_FREQUENCY_2KHZ) || \
   ((FREQ) == BEEP_FREQUENCY_4KHZ))

/* Macro used by the assert function to check the LSI frequency (in Hz).*/
#define IS_LSI_FREQUENCY_OK(FREQ) \
  (((FREQ) >= LSI_FREQUENCY_MIN) && \
   ((FREQ) <= LSI_FREQUENCY_MAX))

/* BEEP_Exported_Functions */

void BEEP_DeInit(void);
void BEEP_Init(BEEP_Frequency_TypeDef BEEP_Frequency);
void BEEP_Cmd(FunctionalState NewState);
void BEEP_LSICalibrationConfig(uint32_t LSIFreqHz);

#endif /* __STM8S_BEEP_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
