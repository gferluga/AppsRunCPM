/************************************************************************
 Copyright (c) 1984				   Eigenware Technologies
				bit_shft()

Shift bits n-positions, in an unsigned integer, to the left or right if
n is positive or negative, respectively.

*************************************************************************/

unsigned int bit_shft(x, n)
   unsigned int x;
   short n;
{
   if (n < 0 ) return( x >> -n );

   return( x << n );

}








}





ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ