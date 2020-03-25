#ifndef led_included
#define  led_included

#include <msp430.h>

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)
#define PWM_COUNT 0

void led_init();		/* initialize LEDs */
void led_update();		/* update leds */
void toggle_red();              /* to display red lights */
void toggle_green();            /* to display green lights */
void dim_green();               /* to display dim red light */
void dim_red();                 /* to display dim green light */
void dim_both();                /* to dim both lights */
void change_lights();

// these are boolean flags
extern unsigned char leds_changed, green_led_state, red_led_state;

// to change lights
char new_red_on, new_green_on;
unsigned char red_on, green_on, led_changed;
static char pwm_count;
#endif
