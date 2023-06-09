/************************************************************************
 Copyright (c) 1984				   Eigenware Technologies
			      Rotating Bits


NOTE: The binary numbers do not print a "0" for the most significant bits.
      As an exercise with getbits, you can easily include a function that
      will print a "0" for the MSB's.

*************************************************************************/

#define P(F,X)	printf("X = %F", (X))

#include "bit-rot.c"
#include "more.c"

main()
{
   int i;

   P(b\n,bit_rot(32768,16));
   P(b\n,bit_rot(32768,-16));
   P(b\n,bit_rot(32768,1));
   P(b\n,bit_rot(32768,-1));
   P(b\n,bit_rot(32768,0));

   printf("\n\n");
   more(0);
   printf("\n\n");

   for (i = 0; i < 8; i++) {
      P(b\n,bit_rot(183,i));
      P(b\n,bit_rot(183,-i));
   }
   exit(0);
}

   exit(0);
}
�m	��P�< m	�^��w�P�m