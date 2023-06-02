/***********************************************************************
 Copyright (c) 1984				  Eigenware Technologies

		  #include for special Heath codes

NOTE #1: bdos function #9 does not left justify, however with cursor
	 addressing this is not necessary.

NOTE #2: Examine the file heath.h; you may wish to add other functions,
	 delete some, and perhaps rearrange the file into several files.

************************************************************************/

/*Include "stdio.h"	comment out for Aztec */
#include "heath.h"
#include "locate.c"

main()
{
	register int i;

	CURSOFF;
	CLS;
	locate(1,31);
	ERV;
	PRINT( W. M Adney SCREEN CONTROL program);
	XRV;
	locate(12,40);
	PRINT(+ (12, 40));
	for(i = 0; i < 12; i++) CUL;
	SCP;
	ENABLE25;
	locate(25,30);
	ERV;
	PRINT(This is the 25th line.);
	XRV;
	RCP;
	CUD;
	PRINT(reset);
	CUH;
	exit(CURSON);
}
