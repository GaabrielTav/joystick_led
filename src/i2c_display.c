#include "i2c_display.h"
#include "hardware/i2c.h"
#include "ssd1306.h"

void i2c_display_init() {
    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(14, GPIO_FUNC_I2C);
    gpio_set_function(15, GPIO_FUNC_I2C);
    gpio_pull_up(14);
    gpio_pull_up(15);

    ssd1306_init();
}

void i2c_display_update_square(uint16_t x_value, uint16_t y_value) {
    // Converte os valores do joystick para coordenadas do display
    uint8_t x = (x_value * 128) / 4095;
    uint8_t y = (y_value * 64) / 4095;

    // Desenha o quadrado na nova posição
    ssd1306_clear();
    ssd1306_draw_square(x, y, 8, 8);
    ssd1306_update();
}