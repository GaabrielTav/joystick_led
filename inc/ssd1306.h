#ifndef SSD1306_H
#define SSD1306_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"

// Endereço I2C do display SSD1306
#define SSD1306_I2C_ADDRESS 0x3C

// Dimensões do display
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

// Inicializa o display SSD1306
void ssd1306_init();

// Limpa o display (preenche com pixels desligados)
void ssd1306_clear();

// Desenha um quadrado na posição (x, y) com largura e altura especificadas
void ssd1306_draw_square(uint8_t x, uint8_t y, uint8_t width, uint8_t height);

// Atualiza o display com o conteúdo do buffer
void ssd1306_update();

#endif // SSD1306_H