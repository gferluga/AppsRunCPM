/********************************************************************
 Copyright (c) 1984			       Eigenware Technologies

		recursin.c  - a function that calls itself

  NOTE: Recursive functions are supported  in C.  Calculation  of the
	factorial  is the  traditional	demonstration  of a recursive
	algortithm.

*********************************************************************/

#include "stdio.h"  /* . . . . . . . . . . . required for putchar() */
#define N 5  /* . . . . . . . .  calculate factorial of this number */

main()
{
   int i;

   putchar('\n');
   for (i = 0; i <= N; ++i)
	printf("%10d! = %d\n", i, factorial(i));
}

factorial(n)
int n;
{
   int solution;

   if (n == 0) solution = 1;
   else solution = n * factorial(n-1);

   return(solution);
}
turn(solution);
}
�F썆\��F���� �F� �F��9 � �F� �F��* � �F�
 �F�� � �F� �