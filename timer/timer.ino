#define REGSET_BIT(REGNAME,REGBIT) REGNAME = REGNAME | (1<<REGBIT)
#define REGCLR_BIT(REGNAME,REGBIT) REGNAME = REGNAME & ~(1<<REGBIT)
// arduino nano using atmega368P runs at 16MHZ, for most codes there are no reason to change it\
   specially when doing just our hobbist stuff
#define F_CPU 16000000UL


void setup() 
{

  

}

void loop() 
{
  

}