#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

static char pwm_count = 0;

void state_advance(){

  switch(switch_state_changed){
  case 1: toggle_red(); break;
  case 2: toggle_green(); break;
  case 3: dim_red(); break;
  case 4: dim_green(); break;
  }

  
}



