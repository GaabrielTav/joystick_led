#ifndef BUTTONS_H
#define BUTTONS_H

#include "pico/stdlib.h"

// Inicializa os botões e configura as interrupções
void buttons_init();

// Callback para o botão A (ativa/desativa os LEDs PWM)
void button_a_callback(uint gpio, uint32_t events);

// Callback para o botão do joystick (alterna o LED Verde)
void button_joystick_callback(uint gpio, uint32_t events);

#endif // BUTTONS_H