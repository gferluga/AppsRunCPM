/*=======================================================================
  Copyright (c) 1984				   Eigenware Technologies

	       Let's Modify The Video Control Register

    NOTE: Refer to page 4.31 of your Heath/Zenith Technical Manual

========================================================================*/


#include "stdio.h"

main()
{


   extern unsigned char inportb();
   extern unsigned char outportb();
   unsigned char byte;

   printf("\nVRAM cannot be accessed:\n\n");

   outportb(0xd8, 0xf8);

   byte = inportb(0xd8);
   printf("\t\tVideo I/O port = %b\n", byte);

   printf("\n\nEnable VRAM for access:\n\n");

   outportb(0xd8, byte&0x7f);

   byte = inportb(0xd8);
   printf("\t\tVideo I/O port = %b\n", byte);

   exit(0);
}
   exit(0);
}
 à
�u�$t��<u�<t2������à
�uQ���YQ��YQ�>� t��Y���<t�< s��