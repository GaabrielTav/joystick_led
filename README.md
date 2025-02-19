# README - Projeto Raspberry Pi Pico com SSD1306 e Interrupções

## **Visão Geral**
Este projeto utiliza a placa **Raspberry Pi Pico** para controlar **LEDs RGB, botões** e um **display OLED SSD1306 (128x64) via I2C**. A implementação inclui **interrupções**, **debouncing** e a **exibição gráfica da posição de um joystick**.

---

## **1. Interrupções (IRQ)**
As interrupções permitem capturar eventos de botões de forma eficiente, sem a necessidade de verificação constante no loop principal.

### **Configuração das Interrupções**
No arquivo `buttons.c`, os botões são configurados com interrupções para responder rapidamente aos eventos.

```c
#include "buttons.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"

void button_a_callback(uint gpio, uint32_t events) {
    static bool pwm_enabled = true;
    pwm_enabled = !pwm_enabled;
    pwm_set_enabled(pwm_gpio_to_slice_num(11), pwm_enabled);
    pwm_set_enabled(pwm_gpio_to_slice_num(13), pwm_enabled);
}

void button_joystick_callback(uint gpio, uint32_t events) {
    pwm_toggle_led_green();
}

void buttons_init() {
    gpio_init(5);
    gpio_set_dir(5, GPIO_IN);
    gpio_pull_up(5);

    gpio_init(22);
    gpio_set_dir(22, GPIO_IN);
    gpio_pull_up(22);

    gpio_set_irq_enabled_with_callback(5, GPIO_IRQ_EDGE_FALL, true, button_a_callback);
    gpio_set_irq_enabled_with_callback(22, GPIO_IRQ_EDGE_FALL, true, button_joystick_callback);
}
```

---

## **2. Debouncing**
O debouncing evita leituras falsas causadas por ruídos mecânicos nos botões.

### **Implementação**
Para implementar um debounce eficiente, adicionamos um atraso de 20ms nas funções de callback:

```c
void button_a_callback(uint gpio, uint32_t events) {
    static uint32_t last_time = 0;
    uint32_t now = time_us_32();
    if (now - last_time < 20000) return;
    last_time = now;

    static bool pwm_enabled = true;
    pwm_enabled = !pwm_enabled;
    pwm_set_enabled(pwm_gpio_to_slice_num(11), pwm_enabled);
    pwm_set_enabled(pwm_gpio_to_slice_num(13), pwm_enabled);
}
```

---

## **3. Uso do Display OLED SSD1306 (128x64)**
O display é utilizado para exibir um quadrado que representa a posição do joystick.

### **Código para Atualização do Display**

```c
void i2c_display_update_square(uint16_t x_value, uint16_t y_value) {
    uint8_t x = (x_value * 128) / 4095;
    uint8_t y = (y_value * 64) / 4095;

    ssd1306_clear();
    ssd1306_draw_square(x, y, 8, 8);
    ssd1306_update();
}
```

### **Inicialização do Display**
```c
void i2c_display_init() {
    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(14, GPIO_FUNC_I2C);
    gpio_set_function(15, GPIO_FUNC_I2C);
    gpio_pull_up(14);
    gpio_pull_up(15);
    ssd1306_init();
}
```

---

## **4. Estrutura do Projeto**
Organizamos o código de forma modular para facilitar a manutenção e a reutilização.

```
joystick_led/
--- CMakeLists.txt
--- src/
-------main.c
------- adc.c
------- pwm.c
-------i2c_display.c
-------buttons.c
--- inc/
-------adc.h
------- pwm.h
-------i2c_display.h
------- buttons.h
└── README.md


Cada módulo tem sua responsabilidade específica, garantindo um código organizado e modular.


## **5. Conclusão**
1. **Interrupções** garantem resposta rápida a eventos dos botões.
2. **Debouncing** elimina leituras falsas e melhora a precisão das entradas.
3. **O display OLED SSD1306** exibe graficamente a posição do joystick.
4. **Código modular** facilita a manutenção e expansão do projeto.



