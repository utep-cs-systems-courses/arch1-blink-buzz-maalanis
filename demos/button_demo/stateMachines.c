#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "led.h"

char power=1;

char sound_on()		/* always toggle! */
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

char sound_off()	/* only toggle green if red is on!  */
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
  if(blink_mode==0)
    {
  if(power)
    {
      sound_on();
    } else {
    sound_off();
  }
    }
  if(blink_mode==1)
    {
      state_advance_flip();
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
void state_advance_flip()
{
  static char led = 0;
  if (led)
    {
      green_on = 1;
      red_on = 0;
      color = 1;
      led = 0;
    } else {
    green_on = 0;
    red_on = 1;
    led = 1;
    color = 0;
  }
  switch_state_changed = 1;
  led_changed =1;
  led_update();
}


