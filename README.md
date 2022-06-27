# t113-ddr-decompiled

Decompiled DDR memory init for Allwinner Tech T113-s3 SoC.

Author: Rep Stosw <repstosw2018@gmail.com>
27.06.2022

---

src/t113_ddr_decompiled.c :

This file was made from disassembled and decompiled \tina-t113\lichee\brandy-2.0\spl-pub\board\t113\libsun8iw20p1_fes.a
IDA Pro 7.5 SP3 + Hex-Rays decompiler

Just add in your code:

extern void sys_dram_init(void);

and use it :)

---

src/memtest :

MemTest.c / MemTest.h - my memory test
main.c - example

---

output :

test.113 - binary for T113-s3 chip (DDR memory init + memory test)

load.bat - BAT-script for xfel (for load binary)

---

![t113-memtest](https://user-images.githubusercontent.com/88702500/175852531-85f646aa-53fd-48ec-8a53-08b3863b236d.png)
