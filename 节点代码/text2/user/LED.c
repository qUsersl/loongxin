/*
 * LED.c
 *
 * created: 2025/3/31
 *  author: 
 */

#include "ls1x.h"
#include "config.h"
#include "ls1x_gpio.h"
#include "ls1x_latimer.h"


void LED_on(void)
{
    gpio_write_pin(GPIO_PIN_14, 1);
    gpio_write_pin(GPIO_PIN_20, 0);
}

void LED_off(void)
{
    gpio_write_pin(GPIO_PIN_14, 0);
    gpio_write_pin(GPIO_PIN_20, 1);
}

