/**************************************************************************
 Copyright (c) 1984				     Eigenware Technologies

			for loops and printf conversion

NOTE #1: For concept, chapter 1.3 of K&R.

***************************************************************************/

/*#include "stdio.h" comment out for Aztec . . . .required for putchar() */

#define NL putchar('\n')

main()
{
    int i;
    char *title;

/*	 assign pointer to string of characters, in next statement	  */

    title = "\033p DEMONSTRATE FOR-LOOP AND CHARACTER CONVERSION \033q\n";

    printf(title);
    NL;
    for (i = 65; i < 91; i++) printf("%c", i);
    NL;
    for (i = 65; i < 91; ++i) printf("%c", i);
    NL;
    exit(0);
}
