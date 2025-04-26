/**
 *  timer0.hpp
 * @brief Timer0 abstraction for AVR (ATmega328P) - CTC mode support
 * 
 * Simple timer configuration usage. Setting basic registers and defining a delay. 
 * uses timer0 as 8-bit timer and  logs a simple digital clock to the serial
 * the clock is limited to 10 hours
 * 
 * @author Mauro
 * @date 2025-04-26
 * @version 0.1
 * 
 * @copyright
 * MIT License
 * 
 */

#define REGSET_BIT(REGNAME,REGBIT) REGNAME = REGNAME | (1<<REGBIT)
#define REGCLR_BIT(REGNAME,REGBIT) REGNAME = REGNAME & ~(1<<REGBIT)
// arduino nano using atmega368P runs at 16MHZ, for most codes there are no reason to change it\
   specially when doing just our hobbist stuff
#define F_CPU 16000000UL

//just some global variable to help us reach seconds delay, not precise, but fine for now
int var_global = 0;

//BONUS!!!!!
/*
* creating a simple "TIME LOG" on uart with current time
*/
void log_time();


void setup_timer0_ctc(void)
{
    // Set CTC mode: WGM02:0 = 010 -> CTC (TOP = OCR0A)
    TCCR0A = (1 << WGM01);      // WGM01 = 1, WGM00 = 0
    TCCR0B = (1 << CS02) | (1 << CS00); // Prescaler = 1024, WGM02 = 0
   

    // Set compare value for desired delay (tweak as needed)
    OCR0A = 156; // ~10ms at 16MHz / 1024

    // Enable Compare Match A interrupt
    TIMSK0 = (1 << OCIE0A);
}

void setup_led_pin(void)
{
   REGSET_BIT(DDRB,5); // Set PB5 as output
}

void setup() 
{
   Serial.begin(19200);
   setup_led_pin();
   setup_timer0_ctc();

   sei(); // Enable global interrupts
}

void loop() 
{
   // do nothing on loop, let timer work via interrupt

}



// Interrupt Service Routine for Timer0 Compare Match A
ISR(TIMER0_COMPA_vect)
{
   var_global++;
   /*63 makes for roughly a one second delay
    * 1024 prescaler gives us 64uS per tick, 156 in OCR0A gives us approx. 9,98ms
    * so 100 gives us 0,998ms which is close enough for 1 second for now
    */
   if(var_global>100)
   {
      log_time();
      var_global = 0;
   }
   
}


//BONUS!!!!!
/*
* creating a simple "TIME LOG" on uart with current time
*/
void log_time()
{
   static int hours;
   static int minutes;
   static int seconds;
   char buffer[15];
   sprintf(buffer,"%#2dh:%#2dm:%#2ds\n",hours,minutes,seconds);
   Serial.println(buffer);

   seconds++;

   if(seconds>60)
   {
      minutes++;
      seconds = 0;
   }
   if(minutes>60)
   {
      hours++;
      minutes = 0;
   }

   //just a limit in hours count, but this is optional
   if(hours>10)
   {
      hours = 0;
      minutes = 0;
      seconds = 0;
   }

}


