#include <stdio.h>

#include "hardware/gpio.h"
#include "pico/stdlib.h"

#define LED_BUILTIN 25

int main() {
    stdio_init_all();

    gpio_init(LED_BUILTIN);
    gpio_set_dir(LED_BUILTIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_BUILTIN, 1);
        sleep_ms(1000);
        gpio_put(LED_BUILTIN, 0);
        sleep_ms(1000);
    }
}