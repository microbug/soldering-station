/**
 * Original version: MIT license, by Nikita Bulaev, 2017.
 * This library version has been modified to use the blocking HAL_Delay function
 * instead of FreeRTOS.
 */

#ifndef LCD_HD44780_I2C_H
#define LCD_HD44780_I2C_H 120

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l0xx_hal.h"

#define LCD_BIT_RS                 ((uint8_t)0x01U)
#define LCD_BIT_RW                 ((uint8_t)0x02U)
#define LCD_BIT_E                  ((uint8_t)0x04U)
#define LCD_BIT_BACKIGHT_ON        ((uint8_t)0x08U)
#define LCD_BIT_BACKIGHT_OFF       ((uint8_t)0x00U)

#define LCD_MODE_4BITS             ((uint8_t)0x02U)
#define LCD_BIT_1LINE              ((uint8_t)0x00U)
#define LCD_BIT_2LINE              ((uint8_t)0x08U)
#define LCD_BIT_4LINE              LCD_BIT_2LINE
#define LCD_BIT_5x8DOTS            ((uint8_t)0x00U)
#define LCD_BIT_5x10DOTS           ((uint8_t)0x04U)
#define LCD_BIT_SETCGRAMADDR       ((uint8_t)0x40U)
#define LCD_BIT_SETDDRAMADDR       ((uint8_t)0x80U)

#define LCD_BIT_DISPLAY_CONTROL    ((uint8_t)0x08U)
#define LCD_BIT_DISPLAY_ON         ((uint8_t)0x04U)
#define LCD_BIT_CURSOR_ON          ((uint8_t)0x02U)
#define LCD_BIT_CURSOR_OFF         ((uint8_t)0x00U)
#define LCD_BIT_BLINK_ON           ((uint8_t)0x01U)
#define LCD_BIT_BLINK_OFF          ((uint8_t)0x00U)

#define LCD_BIT_DISP_CLEAR         ((uint8_t)0x01U)
#define LCD_BIT_CURSOR_HOME        ((uint8_t)0x02U)

#define LCD_BIT_ENTRY_MODE         ((uint8_t)0x04U)
#define LCD_BIT_CURSOR_DIR_RIGHT   ((uint8_t)0x02U)
#define LCD_BIT_CURSOR_DIR_LEFT    ((uint8_t)0x00U)
#define LCD_BIT_DISPLAY_SHIFT      ((uint8_t)0x01U)

// TODO: Update commands with this defines
#define LCD_BIT_CURSOR_SHIFT_MODE  ((uint8_t)0x10U)
#define LCD_BIT_CURSOR_DISP_SHIFT  ((uint8_t)0x08U)
#define LCD_BIT_CURSOR_MOVE        ((uint8_t)0x00U)
#define LCD_BIT_CURSOR_SHIFT_DIR_R ((uint8_t)0x40U)
#define LCD_BIT_CURSOR_SHIFT_DIR_L ((uint8_t)0x00U)


/* Function defines */
#define lcdBacklightOn()           lcdBacklight(LCD_BIT_BACKIGHT_ON)
#define lcdBacklightOff()          lcdBacklight(LCD_BIT_BACKIGHT_OFF)
#define lcdAutoscrollOn()          lcdCommand(LCD_DISPLAY_SHIFT, LCD_PARAM_SET)
#define lcdAutoscrollOff()         lcdCommand(LCD_DISPLAY_SHIFT, LCD_PARAM_UNSET)
#define lcdDisplayClear()          lcdCommand(LCD_CLEAR, LCD_PARAM_SET)
#define lcdDisplayOn()             lcdCommand(LCD_DISPLAY, LCD_PARAM_SET)
#define lcdDisplayOff()            lcdCommand(LCD_DISPLAY, LCD_PARAM_UNSET)
#define lcdCursorOn()              lcdCommand(LCD_CURSOR, LCD_PARAM_SET)
#define lcdCursorOff()             lcdCommand(LCD_CURSOR, LCD_PARAM_UNSET)
#define lcdBlinkOn()               lcdCommand(LCD_CURSOR_BLINK, LCD_PARAM_SET)
#define lcdBlinkOff()              lcdCommand(LCD_CURSOR_BLINK, LCD_PARAM_UNSET)
#define lcdCursorDirToRight()      lcdCommand(LCD_CURSOR_DIR_RIGHT, LCD_PARAM_SET)
#define lcdCursorDirToLeft()       lcdCommand(LCD_CURSOR_DIR_LEFT, LCD_PARAM_SET)
#define lcdCursorHome()            lcdCommand(LCD_CURSOR_HOME, LCD_PARAM_SET)


typedef struct {
    I2C_HandleTypeDef * hi2c;  // I2C Struct
    uint8_t lines;             // Lines of the display
    uint8_t columns;           // Columns
    uint8_t address;           // I2C address shifted left by 1
    uint8_t backlight;         // Backlight
    uint8_t modeBits;          // Display on/off control bits
    uint8_t entryBits;         // Entry mode set bits
} LCDParams;

typedef enum {
    LCD_PARAM_UNSET = 0,
    LCD_PARAM_SET
} LCDParamsActions;

typedef enum {
    LCD_BACKLIGHT = 0,
    LCD_DISPLAY,
    LCD_CLEAR,
    LCD_CURSOR,
    LCD_CURSOR_BLINK,
    LCD_CURSOR_HOME,
    LCD_CURSOR_DIR_LEFT,
    LCD_CURSOR_DIR_RIGHT,
    LCD_DISPLAY_SHIFT
} LCDCommands;


void lcdInit(I2C_HandleTypeDef *hi2c, uint8_t address, uint8_t lines, uint8_t rows);
void lcdCommand(LCDCommands command, LCDParamsActions action);
void lcdBacklight(uint8_t command);
void lcdSetCursorPosition(uint8_t line, uint8_t row);
void lcdPrintStr(char * data);
void lcdPrintChar(uint8_t data);
void lcdLoadCustomChar(uint8_t cell, uint8_t * charMap);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif
