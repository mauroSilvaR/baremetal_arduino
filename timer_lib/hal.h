#ifndef HAL_H
#define HAL_H

#include <stdint.h>

#define REGSETBIT(REGNAME,BIT)  REGNAME = REGNAME| (1<<BIT)
#define REGCLRBIT(REGNAME,BIT) REGNAME = REGNAME & ~(1<<REGBIT)



typedef union 
{
  // first union type
  struct{
    uint8_t BIT0:1;
    uint8_t BIT1:1;
    uint8_t BIT2:1;
    uint8_t BIT3:1;
    uint8_t BIT4:1;
    uint8_t BIT5:1;
    uint8_t BIT6:1;
    uint8_t BIT7:1;

  };
  uint8_t VALUE;

}REGISTER;


extern REGISTER DDR_B;   // Declaration of DDR_B

#endif // HAL_H

