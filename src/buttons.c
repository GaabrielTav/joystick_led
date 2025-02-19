#include "buttons.h"
#include "hardware/gpio.h"
#include "pwm.h"

void buttons_init() {
    gpio_init(5);  // Botão A
    gpio_set_dir(5, GPIO_IN);
    gpio_pull_up(5);

    gpio_init(22);  // Botão do joystick
    gpio_set_dir(22, GPIO_IN);
    gpio_pull_up(22);

    gpio_set_irq_enabled_with_callback(5, GPIO_IRQ_EDGE_FALL, true, button_a_callback);
    gpio_set_irq_enabled_with_callback(22, GPIO_IRQ_EDGE_FALL, true, button_joystick_callback);
}

void button_a_callback(uint gpio, uint32_t events) {
    static bool pwm_enabled = true;
    pwm_enabled = !pwm_enabled;
    pwm_set_enabled(pwm_gpio_to_slice_num(11), pwm_enabled);
    pwm_set_enabled(pwm_gpio_to_slice_num(13), pwm_enabled);
}

void button_joystick_callback(uint gpio, uint32_t events) {
    pwm_toggle_led_green();
}