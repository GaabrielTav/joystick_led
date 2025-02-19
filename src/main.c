#include "stdlib.h"
#include "adc.h"
#include "pwm.h"
#include "i2c_display.h"
#include "buttons.h"

int main() {
    stdio_init_all();

    // Inicializa os módulos
    adc_init();
    pwm_init();
    i2c_display_init();
    buttons_init();

    while (true) {
        // Lê os valores do joystick
        uint16_t x_value = adc_read_x();
        uint16_t y_value = adc_read_y();

        // Ajusta o brilho dos LEDs RGB
        pwm_set_led_red(x_value);
        pwm_set_led_blue(y_value);

        // Atualiza a posição do quadrado no display
        i2c_display_update_square(x_value, y_value);

        // Verifica o estado dos botões
        buttons_check();
    }

    return 0;
}