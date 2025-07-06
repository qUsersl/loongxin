/*
 * buzzer.c
 *
 * created: 2025/4/2
 *  author: 
 */

#include "ls1x.h"
#include "config.h"
#include "gpio.h"
#include "ls1x_gpio.h"
#include "ls1x_latimer.h"

void Buzzer_on(void)
{
    gpio_write_pin(GPIO_PIN_63, 1);
}

void Buzzer_off(void)
{
    gpio_write_pin(GPIO_PIN_63, 0);
}



