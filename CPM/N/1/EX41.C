/*---------------------------------------------------------------------------\
| Copyright (c) 1984				      Eigenware Technologies |
|									     |
|			   Bit	Operators				     |
|									     |
\---------------------------------------------------------------------------*/

#include "stdio.h"
#include "more.c"

#define P(X) printf("X = %b\n", (X))
#define NL putchar('\n');

main()
{
   NL;
   printf("Bitwise AND operator:\n");
   P(1 & 1);
   P(0 & 1);
   P(1 & 0);
   P(0 & 0);
   NL;
   more(0);

   NL;
   printf("Bitwise OR operator:\n");
   P(1 | 1);
   P(0 | 1);
   P(1 | 0);
   P(0 | 0);
   NL;
   more(0);

   NL;
   printf("Bitwise XOR operator:\n");
   P(1 ^ 1);
   P(0 ^ 1);
   P(1 ^ 0);
   P(0 ^ 0);
   NL;
   more(0);

   NL;
   printf("Bitwise Complement operator:\n");
   P(~1);
   P(~0);
   NL;

   exit(0);
}
;
}
ator