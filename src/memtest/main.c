#include "Type.h"

#include "LowLevel.h"
#include "UART.h"
#include "PIO.h"
#include "delay.h"

#include "MemTest.h"

void main(void)
{
 LowLevel_Init();

 UART0_puts("\nT113-s3\n");

 UART0_puts("Start Test DDR...\n");

 if(TestSDRAM8())if(TestSDRAM16())if(TestSDRAM32())if(TestSDRAM64())UART0_puts("Test OK! :)\n");
 else                                                               UART0_puts("Test Fail! :(\n");

 Loop:

 ToggleLED();
 mdelay(100);

 goto Loop;
}
