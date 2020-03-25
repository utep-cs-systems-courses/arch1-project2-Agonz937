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


void the_office(){ // d g d d g d F d  d F e g e e g c c c b a b g 
  short keys[3] = {593, 1582, 593};
  short i = 0;
  short *p;

  for (i; i < 3 ; i++){
    buzzer_set_period(keys[i]);
    __delay_cycles(4000000);
  }
  buzzer_set_period(0);
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}
