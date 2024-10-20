#include "leds.h"

static uint8_t led_pins[] = {LED_PIN_2, LED_PIN_4, LED_PIN_3, LED_PIN_1};
static size_t led_pins_size = sizeof(led_pins) / sizeof(led_pins[0]);

static void delay(volatile uint32_t duration) {
    while (duration--);
}

void init_leds() {
    for (int i = 0; i < led_pins_size; i++) {
        GPIO_DIR |= (1 << led_pins[i]);
    }
}

void blink_leds(uint32_t duration) {
    for (int i = 0; i < led_pins_size; i++) {
        GPIO_OUTCLR = (1 << led_pins[i]);
        delay(duration);
        GPIO_OUTSET = (1 << led_pins[i]);
    }
}
