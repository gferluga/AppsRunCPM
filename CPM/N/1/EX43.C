/*-----------------------------------------------------------------------*\
| Copyright (c) 1984				   Eigenware Technologies |
|									  |
|			       getbits					  |
|									  |
|		      Refer to file: getbits.c				  |
|									  |
|		NOTE: For concept see page 45 of K & R. 		  |
|									  |
\*-----------------------------------------------------------------------*/

#include "stdio.h"

#define NL	 putchar('\n')
#define PR(F,X)  printf("X = %F\n", (X))

#include "more.c"
#include "getbits.c"

main()
{
   NL;
   PR(b,170);
   PR(b,getbits(170,5,5));
   PR(b,getbits(170,5,4));
   PR(b,getbits(170,5,3));
   PR(b,getbits(170,5,2));
   PR(b,getbits(170,5,1));
   PR(b,getbits(170,5,0));
   NL;
   more(0);
   NL;
   PR(b,2730);
   PR(b,getbits(2730,11,1));
   PR(b,getbits(2730,10,1));
   PR(b,getbits(2730,9,1));
   PR(b,getbits(2730,8,1));
   PR(b,getbits(2730,7,1));
   PR(b,getbits(2730,6,1));
   PR(b,getbits(2730,5,1));
   PR(b,getbits(2730,4,1));
   PR(b,getbits(2730,3,1));
   PR(b,getbits(2730,2,1));
   PR(b,getbits(2730,1,1));
   PR(b,getbits(2730,0,1));
   NL;
   more(0);
   NL;
   PR(b,'A');
   NL;
   PR(b,getbits('A',7,1));
   PR(b,getbits('A',6,1));
   PR(b,getbits('A',5,1));
   PR(b,getbits('A',4,1));
   PR(b,getbits('A',3,1));
   PR(b,getbits('A',2,1));
   PR(b,getbits('A',1,1));
   PR(b,getbits('A',0,1));
   NL;
}
;
}
(���ډA�*���*����,�2����8�J��
�t� ��
����	3��&�ËR��	��E��	
�t߻�o������R�W�R�