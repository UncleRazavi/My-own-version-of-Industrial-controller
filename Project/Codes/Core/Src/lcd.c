#include "lcd.h"

static void LCD_Enable()
{
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_SET);

    HAL_Delay(1);

    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);

    HAL_Delay(1);
}

static void LCD_Send4(uint8_t data)
{

    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,(data&1));

    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,(data&2));

    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,(data&4));

    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,(data&8));

    LCD_Enable();
}

static void LCD_Command(uint8_t cmd)
{

    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);

    LCD_Send4(cmd>>4);

    LCD_Send4(cmd&0x0F);

}

static void LCD_Data(uint8_t data)
{

    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);

    LCD_Send4(data>>4);

    LCD_Send4(data&0x0F);

}

void LCD_Init()
{

    HAL_Delay(50);

    LCD_Send4(0x03);

    HAL_Delay(5);

    LCD_Send4(0x03);

    HAL_Delay(5);

    LCD_Send4(0x03);

    LCD_Send4(0x02);

    LCD_Command(0x28);

    LCD_Command(0x0C);

    LCD_Command(0x06);

    LCD_Command(0x01);

}

void LCD_Clear()
{
    LCD_Command(0x01);

    HAL_Delay(2);
}

void LCD_SetCursor(uint8_t row,uint8_t col)
{

    uint8_t addr;

    if(row==0)
        addr=0x80+col;
    else
        addr=0xC0+col;

    LCD_Command(addr);
}

void LCD_Print(char *str)
{

    while(*str)
    {
        LCD_Data(*str++);

    }

}
