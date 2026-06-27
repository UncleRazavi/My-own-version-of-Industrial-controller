#include "controller.h"
#include "adc.h"

extern ADC_HandleTypeDef hadc1;

static uint16_t Read_Temp_ADC()
{
    HAL_ADC_Start(&hadc1);

    HAL_ADC_PollForConversion(&hadc1,10);

    uint16_t value = HAL_ADC_GetValue(&hadc1);

    HAL_ADC_Stop(&hadc1);

    return value;
}

static float ADC_To_Temperature(uint16_t adc)
{
    float voltage = (adc * 3.3f) / 4095.0f;

    return voltage * 100.0f;
}

void Controller_Init(Controller_t *ctrl)
{

    ctrl->temperature = 0;

    ctrl->humidity = 0;

    ctrl->temp_setpoint = 30;

    ctrl->hysteresis = 2;

    ctrl->heater_on = 0;

    ctrl->cooler_on = 0;

    ctrl->gas_on = 0;

    ctrl->alarm_on = 0;

    ctrl->mode = MODE_AUTO;
}

void Controller_UpdateSensors(Controller_t *ctrl)
{

    uint16_t adc = Read_Temp_ADC();

    ctrl->temperature = ADC_To_Temperature(adc);

}

void Controller_ProcessLogic(Controller_t *ctrl)
{

    if(ctrl->mode == MODE_AUTO)
    {

        if(ctrl->temperature > ctrl->temp_setpoint + ctrl->hysteresis)
        {
            ctrl->cooler_on = 1;
            ctrl->heater_on = 0;
        }

        else if(ctrl->temperature < ctrl->temp_setpoint - ctrl->hysteresis)
        {
            ctrl->heater_on = 1;
            ctrl->cooler_on = 0;
        }

        else
        {
            ctrl->heater_on = 0;
            ctrl->cooler_on = 0;
        }

        ctrl->gas_on = ctrl->heater_on;
    }

    if(ctrl->temperature > 60)
    {
        ctrl->alarm_on = 1;
    }
}

void Controller_ApplyOutputs(Controller_t *ctrl)
{

    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,
        ctrl->cooler_on ? GPIO_PIN_SET : GPIO_PIN_RESET);

    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,
        ctrl->heater_on ? GPIO_PIN_SET : GPIO_PIN_RESET);

    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,
        ctrl->gas_on ? GPIO_PIN_SET : GPIO_PIN_RESET);

    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,
        ctrl->cooler_on ? GPIO_PIN_SET : GPIO_PIN_RESET);

}
