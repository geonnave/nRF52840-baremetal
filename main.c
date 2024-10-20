#include <stdint.h>
#include "leds.h"

int main(void) {
    init_leds();

    while (1) {
        blink_leds(500000);
    }
}
