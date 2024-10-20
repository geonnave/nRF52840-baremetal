#ifndef LED_H
#define LED_H

#include <stdint.h>
#include <stddef.h>

#define GPIO_BASE        0x50000000U
#define GPIO_OUT         (*(volatile unsigned int *)(GPIO_BASE + 0x504))  // GPIO output register
#define GPIO_OUTSET      (*(volatile unsigned int *)(GPIO_BASE + 0x508))  // GPIO output set register
#define GPIO_OUTCLR      (*(volatile unsigned int *)(GPIO_BASE + 0x50C))  // GPIO output clear register
#define GPIO_DIR         (*(volatile unsigned int *)(GPIO_BASE + 0x514))  // GPIO direction register

#define LED_PIN_1 13
#define LED_PIN_2 14
#define LED_PIN_3 15
#define LED_PIN_4 16

void init_leds();
void blink_leds();

#endif // LED_H