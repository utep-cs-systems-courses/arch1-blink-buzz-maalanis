#ifndef switches_included
#define switches_included

#define SW1 BIT3		/* switch1 is p1.3 */
#define SWITCHES SW1		/* only 1 switch on this board */
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4 )
void switch_init();
void switch_interrupt_handler();

void do_button1(char p2val);
void do_button2(char p2val);
void do_button3(char p2val);
void do_button3(char p2val);
void do_button4(char p2val);

extern char switch_state_down, switch_state_changed, color; /* effectively boolean */

#endif // included
