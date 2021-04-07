#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"
char switch_state_down, switch_state_changed; /* effectively boolean */
char blink_mode = 0;
char color =0;

//char do_button1(p2val);
static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  
   P1IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down = (p2val & SW1) ? 0 : do_button1(p2val); /* 0 when SW1 is up */
  switch_state_down = (p2val & SW2) ? : do_button2(p2val);
  switch_state_down = (p2val & SW3) ? : do_button3(p2val);
  switch_state_down = (p2val & SW4) ? : do_button4(p2val);
  switch_state_changed = 1;
  /*if(SW1)
    {
      do_button1(p2val);
    } else if(SW2){
    do_button2(p2val);
  }
  switch_state_down = (p2val & SW1) ? 0 : 1; /*0 when SW1 is up*/
  //led_update();
}
  char
  do_button1(char p2val)
  {
    switch_state_down= (p2val & SW1) ? 0 : 1;
    switch_state_changed = 1;
    color^=1;
    led_update();
    return 1;
    
  }
  char
  do_button2(char p2val)
  {
    power = 1;
    blink_mode =0;
    enableWDTInterrupts();
    return 1;
  }
  char
  do_button3(char p2val)
  {
    blink_mode ^= 1;
    enableWDTInterrupts();
    return 1;
  }
  char
  do_button4(char p2val)
  {
    power = 0;
    enableWDTInterrupts();
    
    
    return 1;
  }
