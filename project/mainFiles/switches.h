#ifndef switches_included
#define switches_included

#define SW1 BIT0   /* switch1 is p1.0 */
#define SW2 BIT1   /* swtich2 is p1.1 */
#define SW3 BIT2   /* switch3 is p1.2 */
#define SW4 BIT3   /* switch4 is p1.3 */
#define SWITCHES (SW1|SW2|SW3|SW4) /* For all switches */

void switch_init();
void switch_interrupt_handler();

/* effectively boolean*/
extern char switch_state_changed;
extern char switch1_state_down, switch2_state_down;
extern char switch3_state_down, switch4_state_down;
extern char ledMode;  
#endif // included
