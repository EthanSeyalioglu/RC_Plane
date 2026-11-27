#ifndef __JOYSTICKS_H
#define __JOYSTICKS_H

#include <stdint.h>

#define JOYSTICK_ADC_COUNT  3


typedef enum {
    THROTTLE,
    ROLL,
    PITCH
} plane_control_t;

typedef struct {
    uint16_t throttle;
    uint16_t roll;
    uint16_t pitch;
} plane_ctrls_pckt_t;


void joysticks_adc_dma_start(void);
void joysticks_get(plane_ctrls_pckt_t* controls);


#endif