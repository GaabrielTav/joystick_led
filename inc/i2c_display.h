#ifndef I2C_DISPLAY_H
#define I2C_DISPLAY_H

#include "pico/stdlib.h"

// Inicializa o display SSD1306 via I2C
void i2c_display_init();

// Atualiza a posição do quadrado no display com base nos valores do joystick
void i2c_display_update_square(uint16_t x_value, uint16_t y_value);

#endif // I2C_DISPLAY_H