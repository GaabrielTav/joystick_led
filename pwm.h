#ifndef PWM_H
#define PWM_H

#include "pico/stdlib.h"

// Inicializa o PWM para os LEDs RGB
void pwm_init();

// Ajusta o brilho do LED Vermelho com base no valor do eixo X
void pwm_set_led_red(uint16_t value);

// Ajusta o brilho do LED Azul com base no valor do eixo Y
void pwm_set_led_blue(uint16_t value);

// Alterna o estado do LED Verde
void pwm_toggle_led_green();

#endif // PWM_H