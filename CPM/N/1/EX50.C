/***********************************************************************
 Copyright (c) 1984				  Eigenware Technologies

      Let's turn on the color of the H/Z100 computer system

***********************************************************************/

#define reset bdos(9,"\033z$")	 /* . . . power-up configuration */

#include "stdio.h"
#include "clear.c"
#include "color.c"

struct color_list
	{
	char black;
	char blue;
	char red;
	char magenta;
	char green;
	char cyan;
	char yellow;
	char white;
	};

struct color_list color = {'0', '1', '2', '3', '4', '5', '6', '7'};

main()
{
      cls();
      clr(color.red, color.white);
      printf("\n\nThis line will be printed in red");
      printf(" on a white background.");

      printf("\n\nPRESS ANY KEY TO EXIT: ");
      bdos(1,0);
      exit(reset);
}
his line will be printed in red");
    