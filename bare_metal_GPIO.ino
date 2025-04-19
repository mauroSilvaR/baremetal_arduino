/*
Following are some details extracted from the AVR ATMEGA328P datasheet

The DDxn bit in the DDRx register selects the direction of this pin. If DDxn is written logic one, Pxn is configured as an output
pin. If DDxn is written logic zero, Pxn is configured as an input pin. 

If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated. To switch the
pull-up resistor off, PORTxn has to be written logic zero or the pin has to be configured as an output pin. The port pins are
tri-stated when reset condition becomes active, even if no clocks are running
If PORTxn is written logic one when the pin is configured as an output pin, the port pin is driven high (one). If PORTxn is
written logic zero when the pin is configured as an output pin, the port pin is driven low (zero).

Writing a logic one to PINxn toggles the value of PORTxn, independent on the value of DDRxn. Note that the SBI instruction
can be used to toggle one single bit in a port

SO basically 
DDxn -- Direction(input output
PORTxn --  if its an input it activates or deactivaates the pullup resistor, if an output it controls toggin high or low of the pin.
PINxn -- write to the pin independent of the state of the pin
*/

// get REG and OR it with 1 "pushed" "REGBIT" times to the right (this sets a bit)
#define REGSET_BIT(REGNAME,REGBIT) REGNAME = REGNAME | (1<<REGBIT)
// get REGNAME and AND it with the inverse of 1 pushed REGBIT times to the right, this clears a bit \
                                                (remember the inverse goes for all bits on register)
#define REGCLR_BIT(REGNAME,REGBIT) REGNAME = REGNAME & ~(1<<REGBIT)

#define LED_SET REGSET_BIT(PORTB,5)
#define LED_CLR REGCLR_BIT(PORTB,5)

// arduino nano using atmega368P runs at 16MHZ, for most codes there are no reason to change it\
   specially when doing just our hobbist stuff
#define F_CPU 16000000UL

void setup(void)
{
  // Bit 5 of portb Is the pin for the LED, lets set it to be an output by setting the bit
  REGSET_BIT(DDRB,5);
}


void loop(void)
{
  LED_SET;
  delay(200);
  LED_CLR;
  delay(200);

}


