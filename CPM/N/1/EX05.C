/********************************************************************
 Copyright (c) 1984			       Eigenware Technologies

		      #define Constructions

   NOTE #1: For concept, chapter 1.4 and 4.11 of K&R.

   NOTE #2: See heath.h file for a more complete list of useful
	    macros.

   NOTE #3: Use of #define provide inline code via substitution as
	    opposed to	callable functions.    Their use result in
	    fast run-times, and very readable source code.

   BUG: The last 'r' in character is not printed on the screen!!!
	This is an odd bug.

*********************************************************************/

/*#include "stdio.h"	    . . . . . . . required for putchar() */

#define begin { 	    /* . . . . . . . . . use symbolic names */
#define end   }
#define BELL putchar('\07')
#define NL  putchar('\n')
#define CLS printf("\033E")
#define INKEY bdos(1,0)
#define PRINT(MSSG) printf("MSSG") /* . . . . . . argument in macro */

main()
begin
   CLS;
   NL;
   BELL;
   PRINT(Type any character to ring the bell again: );
   INKEY;
   BELL;
   NL;
end
