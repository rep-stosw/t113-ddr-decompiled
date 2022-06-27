#ifndef _MEMTEST_H_
#define _MEMTEST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Type.h"

#define USE_UART

#ifdef USE_UART

#include "UART.h"

#else

#define UART0_puts

#endif

#define SDRAM_BASE 0x40000000

#define SDRAM_VOLUME (127UL*1024UL*1024UL) //за вычетом 1 МБ на MMU

u8 TestSDRAM8(void);
u8 TestSDRAM16(void);
u8 TestSDRAM32(void);
u8 TestSDRAM64(void);

#ifdef __cplusplus
}
#endif

#endif
