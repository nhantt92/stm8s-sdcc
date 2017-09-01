/*
  ******************************************************************************
  * @file    stm8s_rst.h
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all functions prototypes and macros for the rst peripheral.
  * @Last Modified by:   nhantt
  * @Last Modified time: 2017-03-22 23:07:13
  ******************************************************************************
*/
#ifndef __STM8S_RST_H
#define __STM8S_RST_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

typedef enum {
  RST_FLAG_EMCF    = (uint8_t)0x10, /*!< EMC reset flag */
  RST_FLAG_SWIMF   = (uint8_t)0x08, /*!< SWIM reset flag */
  RST_FLAG_ILLOPF  = (uint8_t)0x04, /*!< Illigal opcode reset flag */
  RST_FLAG_IWDGF   = (uint8_t)0x02, /*!< Independent watchdog reset flag */
  RST_FLAG_WWDGF   = (uint8_t)0x01  /*!< Window watchdog reset flag */
}RST_Flag_TypeDef;

/* Macro used by the assert function to check the different RST flags.*/
#define IS_RST_FLAG_OK(FLAG) (((FLAG) == RST_FLAG_EMCF) || \
                              ((FLAG) == RST_FLAG_SWIMF)  ||\
                              ((FLAG) == RST_FLAG_ILLOPF) ||\
                              ((FLAG) == RST_FLAG_IWDGF)  ||\
                              ((FLAG) == RST_FLAG_WWDGF

/*RST_Exported_functions*/
FlagStatus RST_GetFlagStatus(RST_Flag_TypeDef RST_Flag);
void RST_ClearFlag(RST_Flag_TypeDef RST_Flag);

#endif /* __STM8S_RST_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
