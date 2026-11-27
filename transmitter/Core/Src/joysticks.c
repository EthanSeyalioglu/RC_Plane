#include "joysticks.h"
#include "adc.h"
#include "stm32f4xx_hal_adc.h"

static volatile uint16_t joysticks_buf[JOYSTICK_ADC_COUNT];


void joysticks_adc_dma_start(void)
{
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*) joysticks_buf, JOYSTICK_ADC_COUNT);
}

void joysticks_get(plane_ctrls_pckt_t* controls)
{
    controls->throttle = joysticks_buf[THROTTLE];
    controls->roll = joysticks_buf[ROLL];
    controls->pitch = joysticks_buf[PITCH];
}