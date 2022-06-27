#include "MemTest.h"

#define NREAD 4 /* for REFRESH test */

const u64 Patterns[]=
{
 0x0000000000000000ULL,
 0xFFFFFFFFFFFFFFFFULL,
 0x5555555555555555ULL,
 0xAAAAAAAAAAAAAAAAULL,
 0x1111111111111111ULL,
 0x2222222222222222ULL,
 0x4444444444444444ULL,
 0x8888888888888888ULL,
 0x3333333333333333ULL,
 0x6666666666666666ULL,
 0x9999999999999999ULL,
 0xCCCCCCCCCCCCCCCCULL,
 0x7777777777777777ULL,
 0xBBBBBBBBBBBBBBBBULL,
 0xDDDDDDDDDDDDDDDDULL,
 0xEEEEEEEEEEEEEEEEULL,
};

u32 Seed;

u32 Random32(void)
{
 register u32 c=0x21;
 register u32 a=Seed;
 register u32 b;
 m0:
 b=a;
 a+=a;
 if(a>b) goto m1;
 a^=0xC5;
 m1:
 c--;
 if(c) goto m0;
 Seed=a;
 return Seed;
}

u8 TestSDRAM8(void)
{
 register u32 i,j,k;

 IO u8 *sdram8=(IO u8*)SDRAM_BASE;

 UART0_puts("8 bit Pattern Test 1...\n");
 //Pattern Test 1
 for(i=0;i<SDRAM_VOLUME/sizeof(u8);i++)sdram8[i]=(u8)(Patterns[i&0xF]&0x00000000000000FF);
 for(k=0;k<NREAD;k++)for(i=0;i<SDRAM_VOLUME/sizeof(u8);i++)if(sdram8[i]!=((u8)(Patterns[i&0xF]&0x00000000000000FF)))return 0;

 UART0_puts("8 bit Pattern Test 2...\n");
 //Pattern Test 2
 for(j=0;j<16;j++)
 {
  for(i=0;i<SDRAM_VOLUME/sizeof(u8);i++)sdram8[i]=(u8)(Patterns[j]&0x00000000000000FF);
  for(k=0;k<NREAD;k++)for(i=0;i<SDRAM_VOLUME/sizeof(u8);i++)if(sdram8[i]!=((u8)(Patterns[j]&0x00000000000000FF)))return 0;
 }

 UART0_puts("8 bit Random Test...\n");
 //Random Test
 Seed=0x7FFFFFFF;
 for(i=0;i<SDRAM_VOLUME/sizeof(u8);i++)sdram8[i]=(u8)(Random32()&0x000000FF);
 for(k=0;k<NREAD;k++)
 {
  Seed=0x7FFFFFFF;
  for(i=0;i<SDRAM_VOLUME/sizeof(u8);i++)if(sdram8[i]!=((u8)(Random32()&0x000000FF)))return 0;
 }
 
 return 1;
}

u8 TestSDRAM16(void)
{
 register u32 i,j,k;

 IO u16 *sdram16=(IO u16*)SDRAM_BASE;

 UART0_puts("16 bit Pattern Test 1...\n");
 //Pattern Test 1
 for(i=0;i<SDRAM_VOLUME/sizeof(u16);i++)sdram16[i]=(u16)(Patterns[i&0xF]&0x000000000000FFFF);
 for(k=0;k<NREAD;k++)for(i=0;i<SDRAM_VOLUME/sizeof(u16);i++)if(sdram16[i]!=((u16)(Patterns[i&0xF]&0x000000000000FFFF)))return 0;

 UART0_puts("16 bit Pattern Test 2...\n");
 //Pattern Test 2
 for(j=0;j<16;j++)
 {
  for(i=0;i<SDRAM_VOLUME/sizeof(u16);i++)sdram16[i]=(u16)(Patterns[j]&0x000000000000FFFF);
  for(k=0;k<NREAD;k++)for(i=0;i<SDRAM_VOLUME/sizeof(u16);i++)if(sdram16[i]!=((u16)(Patterns[j]&0x000000000000FFFF)))return 0;
 }

 UART0_puts("16 bit Random Test...\n");
 //Random Test
 Seed=0x7FFFFFFF;
 for(i=0;i<SDRAM_VOLUME/sizeof(u16);i++)sdram16[i]=(u16)(Random32()&0x0000FFFF);
 for(k=0;k<NREAD;k++)
 {
  Seed=0x7FFFFFFF;
  for(i=0;i<SDRAM_VOLUME/sizeof(u16);i++)if(sdram16[i]!=((u16)(Random32()&0x0000FFFF)))return 0;
 }
 
 return 1;
}

u8 TestSDRAM32(void)
{
 register u32 i,j,k;

 IO u32 *sdram32=(IO u32*)SDRAM_BASE;

 UART0_puts("32 bit Pattern Test 1...\n");
 //Pattern Test 1
 for(i=0;i<SDRAM_VOLUME/sizeof(u32);i++)sdram32[i]=(u32)(Patterns[i&0xF]&0x00000000FFFFFFFF);
 for(k=0;k<NREAD;k++)for(i=0;i<SDRAM_VOLUME/sizeof(u32);i++)if(sdram32[i]!=((u32)(Patterns[i&0xF]&0x00000000FFFFFFFF)))return 0;

 UART0_puts("32 bit Pattern Test 2...\n");
 //Pattern Test 2
 for(j=0;j<16;j++)
 {
  for(i=0;i<SDRAM_VOLUME/sizeof(u32);i++)sdram32[i]=(u32)(Patterns[j]&0x00000000FFFFFFFF);
  for(k=0;k<NREAD;k++)for(i=0;i<SDRAM_VOLUME/sizeof(u32);i++)if(sdram32[i]!=((u32)(Patterns[j]&0x00000000FFFFFFFF)))return 0;
 }

 UART0_puts("32 bit Random Test...\n");
 //Random Test
 Seed=0x7FFFFFFF;
 for(i=0;i<SDRAM_VOLUME/sizeof(u32);i++)sdram32[i]=Random32();
 for(k=0;k<NREAD;k++)
 {
  Seed=0x7FFFFFFF;
  for(i=0;i<SDRAM_VOLUME/sizeof(u32);i++)if(sdram32[i]!=Random32())return 0;
 }

 return 1;
}

u8 TestSDRAM64(void)
{
 register u32 i,j,k;

 IO u64 *sdram64=(IO u64*)SDRAM_BASE;

 UART0_puts("64 bit Pattern Test 1...\n");
 //Pattern Test 1
 for(i=0;i<SDRAM_VOLUME/sizeof(u64);i++)sdram64[i]=Patterns[i&0xF];
 for(k=0;k<NREAD;k++)for(i=0;i<SDRAM_VOLUME/sizeof(u64);i++)if(sdram64[i]!=Patterns[i&0xF])return 0;

 UART0_puts("64 bit Pattern Test 2...\n");
 //Pattern Test 2
 for(j=0;j<16;j++)
 {
  for(i=0;i<SDRAM_VOLUME/sizeof(u64);i++)sdram64[i]=Patterns[j];
  for(k=0;k<NREAD;k++)for(i=0;i<SDRAM_VOLUME/sizeof(u64);i++)if(sdram64[i]!=Patterns[j])return 0;
 }

 UART0_puts("64 bit Random Test...\n");
 //Random Test
 Seed=0x7FFFFFFF;
 for(i=0;i<SDRAM_VOLUME/sizeof(u64);i++)sdram64[i]=(((u64)Random32())<<32)|((u64)Random32());
 for(k=0;k<NREAD;k++)
 {
  Seed=0x7FFFFFFF;
  for(i=0;i<SDRAM_VOLUME/sizeof(u64);i++)if(sdram64[i]!=((((u64)Random32())<<32)|((u64)Random32())))return 0;
 }

 return 1;
}
