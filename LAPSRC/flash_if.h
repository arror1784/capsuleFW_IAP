/**
  ******************************************************************************
  * @file    STM32F4xx_IAP/inc/flash_if.h 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    10-October-2011
  * @brief   This file provides all the headers of the flash_if functions.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FLASH_IF_H
#define __FLASH_IF_H

/* Includes ------------------------------------------------------------------*/
#ifdef USE_HAL_DRIVER
  #include "stm32f4xx_hal.h"
  #include "stm32f4xx_hal_flash.h"
#else
  #include "stm32f4xx.h"
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Base address of the Flash sectors */
#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbyte */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base @ of Sector 1, 16 Kbyte */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base @ of Sector 2, 16 Kbyte */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base @ of Sector 3, 16 Kbyte */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbyte */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbyte */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base @ of Sector 6, 128 Kbyte */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base @ of Sector 7, 128 Kbyte */
#define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000) /* Base @ of Sector 8, 128 Kbyte */
#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base @ of Sector 9, 128 Kbyte */
#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbyte */
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbyte */

/* End of the Flash address */
#if defined(STM32F401xE) || defined(STM32F411xE) || defined(STM32F446xx)
  #define USER_FLASH_END_ADDRESS        0x0807FFFF
#else
  #define USER_FLASH_END_ADDRESS        0x080FFFFF
#endif

#define MAIN_FLASH_END_ADDRESS        	0x0803FFFF
#define BACKUP_FlASH_END_ADDRESS		0x0807FFFF

/* Define the user application size */
#define USER_FLASH_SIZE   (USER_FLASH_END_ADDRESS - APPLICATION_ADDRESS + 1)

#define MAIN_FLASH_SIZE   (MAIN_FLASH_END_ADDRESS - MAIN_APPLICATION_ADDRESS + 1)
#define BACKUP_FLASH_SUZE (BACKUP_FlASH_END_ADDRESS - BACKUP_APPLICATION_ADDRESS + 1)

/* Define the address from where user application will be loaded.
   Note: the 1st sector 0x08000000-0x08003FFF is reserved for the IAP code */
#define APPLICATION_ADDRESS   (uint32_t)0x08004000 

#define MAIN_APPLICATION_ADDRESS   						(uint32_t)0x08004000
#define LAST_MAIN_APPLICATION_ADDRESS_FLASH_SECTOR_NN 	FLASH_SECTOR_5

#define BACKUP_APPLICATION_ADDRESS 						(uint32_t)0x08040000
#define LAST_BACKUP_APPLICATION_ADDRESS_FLASH_SECTOR_NN FLASH_SECTOR_7

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void FLASH_If_Init(void);
uint32_t FLASH_If_Erase(uint32_t StartSector);
uint32_t FLASH_If_Write(__IO uint32_t* FlashAddress, uint32_t* Data, uint32_t DataLength);
uint16_t FLASH_If_GetWriteProtectionStatus(void);
uint32_t FLASH_If_DisableWriteProtection(void);

uint32_t FLASH_If_BACKUP_Erase(uint32_t StartSector);
uint32_t FLASH_If_MAIN_Erase(uint32_t StartSector);
/* added by jrkim ------------------------------------------------------------*/
//
// Flash sector���� ������ ����
// stm32f4xx_hal_flash_ex.h ����
//
#ifdef USE_HAL_DRIVER
#if defined(STM32F401xE) || defined(STM32F411xE) || defined(STM32F446xx)
  #define LAST_FLASH_SECTOR_NN    FLASH_SECTOR_7
#elif defined(STM32F401xC)
  #define LAST_FLASH_SECTOR_NN    FLASH_SECTOR_5
#elif defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx)|| defined(STM32F439xx) ||\
    defined(STM32F469xx) || defined(STM32F479xx)
  #define LAST_FLASH_SECTOR_NN    FLASH_SECTOR_23
#elif defined(STM32F410Tx) || defined(STM32F410Cx) || defined(STM32F410Rx)
  #define LAST_FLASH_SECTOR_NN    FLASH_SECTOR_4
#else
  #define LAST_FLASH_SECTOR_NN    FLASH_SECTOR_11
#endif
#endif

#endif  /* __FLASH_IF_H */

/*******************(C)COPYRIGHT 2011 STMicroelectronics *****END OF FILE******/
