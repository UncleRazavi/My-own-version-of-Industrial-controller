#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

#include "lcd.h"
#include "buttons.h"
#include "controller.h"


#define COOLER_Pin GPIO_PIN_4
#define COOLER_GPIO_Port GPIOA

#define HEATER_Pin GPIO_PIN_5
#define HEATER_GPIO_Port GPIOA

#define GAS_Pin GPIO_PIN_6
#define GAS_GPIO_Port GPIOA

#define COOLER_CTRL_Pin GPIO_PIN_7
#define COOLER_CTRL_GPIO_Port GPIOA

#define FAN_DIR_Pin GPIO_PIN_3
#define FAN_DIR_GPIO_Port GPIOB

/* LCD */

#define LCD_RS_Pin GPIO_PIN_0
#define LCD_RS_GPIO_Port GPIOC

#define LCD_RW_Pin GPIO_PIN_1
#define LCD_RW_GPIO_Port GPIOC

#define LCD_EN_Pin GPIO_PIN_2
#define LCD_EN_GPIO_Port GPIOC

#define LCD_D4_Pin GPIO_PIN_8
#define LCD_D4_GPIO_Port GPIOB

#define LCD_D5_Pin GPIO_PIN_9
#define LCD_D5_GPIO_Port GPIOB

#define LCD_D6_Pin GPIO_PIN_10
#define LCD_D6_GPIO_Port GPIOB

#define LCD_D7_Pin GPIO_PIN_11
#define LCD_D7_GPIO_Port GPIOB

/* Buttons */

#define BTN_AUTO_MAN_Pin GPIO_PIN_0
#define BTN_AUTO_MAN_GPIO_Port GPIOB

#define BTN_START_SET_Pin GPIO_PIN_1
#define BTN_START_SET_GPIO_Port GPIOB

#define BTN_SET_Pin GPIO_PIN_2
#define BTN_SET_GPIO_Port GPIOB

#define BTN_RESET_Pin GPIO_PIN_4
#define BTN_RESET_GPIO_Port GPIOB

#define BTN_AUTO_Pin GPIO_PIN_5
#define BTN_AUTO_GPIO_Port GPIOB

#define BTN_MANUAL_Pin GPIO_PIN_6
#define BTN_MANUAL_GPIO_Port GPIOB

#define BTN_ALARM_Pin GPIO_PIN_7
#define BTN_ALARM_GPIO_Port GPIOB

#ifdef __cplusplus
}
#endif

#endif
