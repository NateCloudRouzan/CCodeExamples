// -------------------------------------------------------------------------------------
// filename: InterlockControl.v
//
//Description:This program works as the interlock control C code. It connects our console 
//			To our hardware system and will will control LEDs
//			For arriving Departing Signals we wait for input from the board and then
//			They are confirmed via the console
//
//Author: Nate Cloud-Rouzan
// -------------------------------------------------------------------------------------

#include "sys/alt_stdio.h"
#include <unistd.h>

#define arriving (short *) 0x9080
#define departing (short *) 0x9070
#define pressurize (short *) 0x9060
#define depressurize (short *) 0x9050
#define inner_door (short *) 0x9040
#define outer_door (short *) 0x9030
#define switches (volatile short *) 0x9020
#define keys (short *) 0x9010
#define leds (volatile short *) 0x9000

void arrive_depart();

int main()
{ 
  alt_putstr("Hello from Nios II!\n");

  *arriving = 0;
  *departing = 0;
  *pressurize = 0;
  *depressurize = 0;
  volatile int i;

  while (1) {
	  short arrive;
	  short depart;
	  //Stay within this while loop while waiting for signal 
	  while (!(((arrive = *switches & 1) || (depart = *switches & 2)) && (*switches & 3) != 3)) {}
	  //if arriving signal from board has been sent enter loop
	  if (arrive) {
		  alt_putstr("arriving\n");
		  while(alt_getchar() != 'a') {}
		  *arriving = 1;
		  for (i = 0; i < 10000000; i++) {}
		  *arriving = 0;
		  
	//if recieved a departing signal from board enter loop  
	  } else if (depart) {
		  alt_putstr("departing\n");
		  while(alt_getchar() != 'd') {}
		  *departing = 1;
		  for (i = 0; i < 10000000; i++) {}
		  *departing = 0;
	  } else {
		  continue;
	  }
	  arrive_depart();
  }
  return 0;
}

//This function is active once the bathysphere has arrived or departed 
void arrive_depart() {
	volatile int i;
	usleep(3000000);
	alt_putstr("Interlock control\n");
	//Control interlock from the console via char commands
	while ((*leds & 1) || (*leds & 2) || (*leds & 16) || (*leds & 12)) {
	  char input = (char) alt_getchar();
	  if (input == 'p') {
		  *pressurize = 1;
		  for (i = 0; i < 10000000; i++) {}
		  *pressurize = 0;
	  } else if (input == 'e') {
		  *depressurize = 1;
		  for (i = 0; i < 10000000; i++) {}
		  *depressurize = 0;
	  } else if (input == 'o') {
		  *outer_door = 1 - *outer_door;
	  } else if (input == 'i') {
		  *inner_door = 1 - *inner_door;
	  }
	  usleep(1000000);
	}
}
