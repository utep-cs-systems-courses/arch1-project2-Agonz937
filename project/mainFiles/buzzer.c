#include <msp430.h>
#include "../timerLib/libTimer.h"
#include "buzzer.h"

void buzzer_init(){
  timerAUpmode(); /* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6; /* enable output to speaker (P2.6) */
}


void random_noise1(){ // d g d d g d F d  d F e g e e g c c c b a b g 
  short keys[5] = {593, 1582, 593, 1000, 20000};
  short i = 0;

  while (i < 5){
    buzzer_set_period(keys[i]);
    __delay_cycles(4000000);
    ++i;
  }
  buzzer_set_period(0);
}

void random_noise2(){
  short keys[5] = {5000, 2400, 3000, 1000, 500};
  short i = 0;

  while (i < 5){
    buzzer_set_period(keys[i]);
    __delay_cycles(4000000);
    ++i;
  }
  buzzer_set_period(0);
}

void random_noise3(){
  short keys[5] = {800,1800,2800,38000,4800};
  short i = 0;

  while (i < 5){
    buzzer_set_period(keys[i]);
    __delay_cycles(4000000);
    ++i;
  }
  buzzer_set_period(0);
}

void random_noise4(){
  short keys[5] = {900,1900,2900,3900,4900};
  short i = 0;

  while (i < 5){
    buzzer_set_period(keys[i]);
    __delay_cycles(4000000);
    ++i;
  }
  buzzer_set_period(0);
}


void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}
