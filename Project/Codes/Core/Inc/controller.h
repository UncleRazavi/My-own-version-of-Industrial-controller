#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "main.h"

typedef enum
{
    MODE_AUTO = 0,
    MODE_MANUAL
} ControllerMode_t;

typedef struct
{
    float temperature;
    float humidity;

    float temp_setpoint;
    float hysteresis;

    uint8_t heater_on;
    uint8_t cooler_on;
    uint8_t gas_on;
    uint8_t alarm_on;

    ControllerMode_t mode;

} Controller_t;

void Controller_Init(Controller_t *ctrl);

void Controller_UpdateSensors(Controller_t *ctrl);

void Controller_ProcessLogic(Controller_t *ctrl);

void Controller_ApplyOutputs(Controller_t *ctrl);

#endif
