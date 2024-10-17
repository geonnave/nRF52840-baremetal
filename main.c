#include <stdint.h>

#define GPIO_BASE        0x50000000U
#define GPIO_OUT         (*(volatile unsigned int *)(GPIO_BASE + 0x504))  // GPIO output register
#define GPIO_OUTSET      (*(volatile unsigned int *)(GPIO_BASE + 0x508))  // GPIO output set register
#define GPIO_OUTCLR      (*(volatile unsigned int *)(GPIO_BASE + 0x50C))  // GPIO output clear register
#define GPIO_DIR         (*(volatile unsigned int *)(GPIO_BASE + 0x514))  // GPIO direction register

#define LED_PIN          13  // LED1 on nRF52840 DK (P0.13)

void delay(volatile uint32_t duration) {
    while (duration--);
}

int main(void) {
    // Set LED_PIN (P0.13) as output
    GPIO_DIR |= (1 << LED_PIN);

    while (1) {
        // Turn the LED on
        GPIO_OUTCLR = (1 << LED_PIN);  // Clear bit to turn on (assuming active-low LED)
        delay(1000000);

        // Turn the LED off
        GPIO_OUTSET = (1 << LED_PIN);  // Set bit to turn off
        delay(1000000);
    }

    for (;;);
}
