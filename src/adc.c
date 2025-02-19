#include "adc.h"
#include "hardware/adc.h"

void adc_init() {
    adc_init();
    adc_gpio_init(26);  // Eixo X
    adc_gpio_init(27);  // Eixo Y
}

uint16_t adc_read_x() {
    adc_select_input(0);  // Canal 0 (GPIO 26)
    return adc_read();
}

uint16_t adc_read_y() {
    adc_select_input(1);  // Canal 1 (GPIO 27)
    return adc_read();
}