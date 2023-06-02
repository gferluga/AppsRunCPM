/***********************************************************************
 Copyright (c) 1984				  Eigenware Technologies

	    type/var.c	-  automatic and static variables

  NOTE:  The for-loop makes sequential calls to the function in which
	 the  two different types of variables (auto and static)  are
	 incremented.	The auto variable forgets its value from  the
	 previous call, always being re-initialized to zero. However,
	 the static variable retains its value from the previous call
	 hence, on each call its incrementation is cummulative.

************************************************************************/

/*#include "stdio.h"	comment out for Aztec*/

main()
{
   int i;

   putchar('\n');

   for(i = 0; i < 3; i++) type_var();

} /* main */

type_var()
{
   int auto_var = 0;
   static int static_var = 0;

   printf("\tautomatic variable = %d", auto_var++);

   printf(",  static variable = %d\n", static_var++);

} /* end of type_var */
