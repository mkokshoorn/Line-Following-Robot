/* led.h 
 *
 * Header File for led.c
 *
 * Created: 29/06/2012 
 * Author: Matt Kokshoorn
 *
 */ 

#define YELLOW 0
#define RED 6
#define GREEN 7

void led_init(void);

void led_toggle(int led);

void led_on(int led);

void led_off(int led);

void test_led(void);