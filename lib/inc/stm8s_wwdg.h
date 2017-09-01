/**
  ******************************************************************************
  * @file    stm8s_wwdg.h
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all functions prototype and macros for the wwdg peripheral.
  * @Date:   2016-03-29 14:06:05
  * @Last Modified by:   nhantt
  * @Last Modified time: 2017-03-21 23:07:13
   ******************************************************************************
*/

#ifndef __STM8S_WWDG_H
#define __STM8S_WWDG_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/* values of the window register. */
#define IS_WWDG_WINDOWLIMITVALUE_OK(WindowLimitValue) ((WindowLimitValue) <= 0x7F)

/* values of the counter register. */
#define IS_WWDG_COUNTERVALUE_OK(CounterValue) ((CounterValue) <= 0x7F)

/*WWDG_Exported_Functions */

void WWDG_Init(uint8_t Counter, uint8_t WindowValue);
void WWDG_SetCounter(uint8_t Counter);
uint8_t WWDG_GetCounter(void);
void WWDG_SWReset(void);
void WWDG_SetWindowValue(uint8_t WindowValue);


#endif /* __STM8S_WWDG_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
