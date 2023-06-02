/*************************************************************************
 Copyright (c) 1984				    Eigenware Technologies
			     bit_rot()

     Rotate bits, in an integer, to the left or right, n-positions.

		   if n is positive rotate left
		   if n is negative rotate right

**************************************************************************/

bit_rot(x, n)
int x;
int n;
{
   int result, bits;

   if  (n == 0 || n == 16 || n == -16) return(x);

   if (n > 0) result = x << n | ( x >> (16 - n) );

   else result = x >> -n | ( x << (16 + n) );

   return(result);
}
eturn(result);
}
PÓà‰†ú÷X±