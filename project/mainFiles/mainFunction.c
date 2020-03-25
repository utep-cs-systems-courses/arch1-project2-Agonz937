#include <msp430.h>
#include "../timerLib/libTimer.h"
#include "buzzer.h"
#include "switches.h"

void main(){
  configureClocks();
  enableWDTInterrupts();
  switch_init();
  led_init();
  buzzer_init(); //Start buzzer

  or_sr(0x18);
}
