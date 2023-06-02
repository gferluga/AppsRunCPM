d*-------------------------------------------------------------------------\
| Copyright (c) 1984				    Eigenware Technologies |
|									   |
|				 Bitwise				   |
|									   |
|NOTE #1 Octal values are indicated by the leading zero; octal numbers are |
|	 used when working with bit strings, because it is easy to convert |
|	 between binary and octal.					   |
|									   |
|NOTE #2 Expressions are evaluated according to order of precedence as	   |
|	 follows:							   |
|			1) ~						   |
|			2) <<  >>					   |
|			3) &						   |
|			4) ^						   |
|			5) |						   |
|									   |
|NOTE #3 Refer to pages 49 and 190 of K & R, for concept.		   |
|									   |
\-------------------------------------------------------------------------*/
		
#define NL putchar('\n')

#define PR1(X) printf("X = %o\t\t",(X))
#define PR2(X) printf("X = %o\n",(X))

#include "stdio.h"
#include "more.c"

main()
{
        NL;
        printf("\tDemonstration of Bitwise operators\n");
        NL;
	PR1( 02 & 01);
	PR2( 03 | 02 & 01);
	PR1( 03 | 02);
	PR2( 01 & 03 | 02);
	PR1( 02 & 03);
	PR2(01 & (03 | 02));
	NL;
	more(0);
	NL;
	PR1( 03 | 02 ^ 01 );		   
	PR2( 03 | 02 & ~ 01 );
	PR1( 03 | 02 & 01 );
	PR2( 03 ^ 02 & 01 );
	NL;
	more(0);
	NL;
	PR1( 015 & 015 );
	PR2( 007 & 015 );
	NL;
	more(0);
	NL;
	PR1( 2 << 1 );
	PR2( 2 >> 1 );
	exit(0);
}
;
}
---