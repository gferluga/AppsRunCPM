/************************************************************************
 Copyright (c) 1984				   Eigenware Technologies

			get n bits from position p

NOTE: For concept see page 45, K & R.

*************************************************************************/


getbits(x, p, n)   /* . .  . . . . . . . . . get n bits from position p */
unsigned x, p, n;
{
	return((x >> (p+1-n)) & ~(~0 << n));
}


















ееееееееееееееееееееееееееееееееееееееееееееееееееееееее