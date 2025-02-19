#include "inc/pwm.h"
#include "hardware/pwm.h"
#include "hardware/pwm.h"

void pwm_init() {
    gpio_set_function(11, GPIO_FUNC_PWM);  // LED Vermelho
    gpio_set_function(12, GPIO_FUNC_PWM);  // LED Verde
    gpio_set_function(13, GPIO_FUNC_PWM);  // LED Azul

    pwm_set_wrap(pwm_gpio_to_slice_num(11), 4095);
    pwm_set_wrap(pwm_gpio_to_slice_num(12), 4095);
    pwm_set_wrap(pwm_gpio_to_slice_num(13), 4095);

    pwm_set_enabled(pwm_gpio_to_slice_num(11), true);
    pwm_set_enabled(pwm_gpio_to_slice_num(12), true);
    pwm_set_enabled(pwm_gpio_to_slice_num(13), true);
}

void pwm_set_led_red(uint16_t value) {
    pwm_set_gpio_level(11, value);
}

void pwm_set_led_blue(uint16_t value) {
    pwm_set_gpio_level(13, value);
}

void pwm_toggle_led_green() {
    static bool led_green_state = false;
    led_green_state = !led_green_state;
    pwm_set_gpio_level(12, led_green_state ? 4095 : 0);
}