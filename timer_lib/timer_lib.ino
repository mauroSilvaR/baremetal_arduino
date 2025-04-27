#include "hal.h"

void setup() {

  REGSETBIT(DDRB,5);
  // put your setup code here, to run once:

}

void loop() 
{

  DDR_B.BIT0 = 1;
  DDR_B.VALUE = 7;


}

