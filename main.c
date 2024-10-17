#include <stdint.h>
#include "main.h"

// =================================== main ===================================

int main(void) {
    init_leds();

    while (1) {
        blink_leds(500000);
    }
}

// ============================================================================

// ================================ blink leds ================================

void delay(volatile uint32_t duration) {
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
// ============================================================================
