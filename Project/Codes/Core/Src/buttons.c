#include "buttons.h"

static uint8_t Button_Read(GPIO_TypeDef *port,uint16_t pin)
{

    if(HAL_GPIO_ReadPin(port,pin)==GPIO_PIN_RESET)
    {
        HAL_Delay(20);

        if(HAL_GPIO_ReadPin(port,pin)==GPIO_PIN_RESET)
        {
            while(HAL_GPIO_ReadPin(port,pin)==GPIO_PIN_RESET);

            return 1;
        }
    }

    return 0;
}

void Buttons_Process(Controller_t *ctrl)
{

    if(Button_Read(GPIOB,GPIO_PIN_0))
    {
        if(ctrl->mode == MODE_AUTO)
            ctrl->mode = MODE_MANUAL;
        else
            ctrl->mode = MODE_AUTO;
    }

    if(Button_Read(GPIOB,GPIO_PIN_5))
    {
        ctrl->mode = MODE_AUTO;
    }

    if(Button_Read(GPIOB,GPIO_PIN_6))
    {
        ctrl->mode = MODE_MANUAL;
    }

    if(Button_Read(GPIOB,GPIO_PIN_7))
    {
        ctrl->alarm_on = !ctrl->alarm_on;
    }

    if(Button_Read(GPIOB,GPIO_PIN_3))
    {
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
    }

}
