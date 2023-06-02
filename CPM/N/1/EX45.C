/***********************************************************************
 Copyright (c) 1984				  Eigenware Technologies

			    Bit Shifting

NOTE #1: The value is doubled for each position bits are shifted left
	 and halved for each position shifted right.

NOTE #2: Refer to page 45 of K & R.

************************************************************************/

#define P(F,X) printf("X = %F", (X))

#include "bit-shft.c"

main()
{
   printf("\n\n");
   P(b\t,bit_shft(200,1));
   P(b\n,bit_shft(200,3));

   P(d\t\t,bit_shft(200,1));
   P(d\n\n,bit_shft(200,3));

   P(b\t,bit_shft(200,-1));
   P(b\n,bit_shft(200,-3));

   P(d\t\t,bit_shft(200,-1));
   P(d\n,bit_shft(200,-3));

   exit(0);
}
  exit(0);
}
shft(200,-3))