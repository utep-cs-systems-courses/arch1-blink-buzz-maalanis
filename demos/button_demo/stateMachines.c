#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"

extern char power=1;

char toggle_red()		/* always toggle! */
{
  static char sound = 0;

  switch (sound) {
  case 0:
    buzzer_set_period(1000);
    sound = 1;
    break;
  case 1:
    buzzer_set_period(2000);
    sound = 2;
    break;
  case 2:
    buzzer_set_period(2500);
    sound = 3;
    break;
  case 3:
    buzzer_set_period(3000);
    sound = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  /*
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
  */
  buzzer_set_period(0);
  return 1;
}


void state_advance()		/* alternate between toggling red & green */
{
  if(power)
    {
      toggle_red();
    } else {
    toggle_green();
  }
  
  /*
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
  */
  //toggle_red();
}



