/*************************************************************************
 Copyright (c) 1984				    Eigenware Technologies

		      WC.c - word count and redirected IO

  NOTE #1: See K&R, Chapters 1 and 7.2, pages 18 and 144, respectively.

  NOTE #2: USAGE: ex28 <filename

**************************************************************************/

#define puts printf  /* . . . . . . . . . . . . . .conversion from BDS-C */
#include "stdio.h"
#include "heath.h"
#include "locate.c"

main()
{
    int c, nl, nw, nc, inword;

    inword = NO;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
	++nc;
	if (c == '\n')
	     ++nl;
	if (c == ' ' || c == '\n' || c == '\t')
	     inword = NO;
	else if (inword == NO) {
	     inword = YES;
	     ++nw;
	}
    }
    CLS;
    locate(10, 30);
    printf("%d lines", nl);
    locate(12, 30);
    printf("%d words", nw);
    locate(14, 30);
    printf("%d characters", nc);
    CUH;
    exit();
}
it();
}
 */
int b[3] = {0,