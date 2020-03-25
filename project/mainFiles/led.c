#include <msp430.h>
#include "led.h"
#include "stateMachines.h"

static char pwm_count = 0;
static char redVal[] = {0, LED_RED}, greenVal[] = {0,LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  led_changed = 1;
  led_update();
}

void led_update(){
  if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on]; 

    P1OUT &= (0xff^LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags; // set bits for on leds
    led_changed = 0;
  }
}

void change_lights(){
  if(red_on != new_red_on || green_on != new_green_on){
    red_on = new_red_on;
    green_on = new_green_on;
    led_changed = 1; 
  }
}
void toggle_red(){
  new_red_on = 1;
  new_green_on = 0;
  change_lights();
}

void toggle_green(){
  new_red_on = 0;
  new_green_on = 1;
  change_lights();
}

void dim_green(){
  pwm_count = (pwm_count + 1) & 3;
  new_red_on = 0;
  new_green_on = (pwm_count < 1);
  change_lights();
}

void dim_red(){
  pwm_count = (pwm_count + 1) & 3;
  new_red_on = (pwm_count < 1);
  new_green_on = 0;
  change_lights();
}

void dim_both(){
  pwm_count = (pwm_count + 1) & 3;
  new_red_on = (pwm_count < 1);
  new_green_on = (pwm_count < 1);
  change_lights();
}


