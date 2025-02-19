#ifndef ADC_H
#define ADC_H

#include "pico/stdlib.h"

// Inicializa o ADC
void adc_init();

// Lê o valor do eixo X do joystick
uint16_t adc_read_x();

// Lê o valor do eixo Y do joystick
uint16_t adc_read_y();

#endif // ADC_H