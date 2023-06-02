/**************************************************************************
 Copyright (c) 1984				     Eigenware Technologies

   area.c    a program to calculate area of a polygon
	     with right angle corners, e.g.

	     ._______________.
	     |		     |	  ._____.
	     |		     |____|	|
	     |				|	    +y
	     |	       n = 14		|	     |
	     |	 .__.			|	     |
	     +___|  |	  ._____________|    -x <----+-----> +x
	    /	    |_____|			     |
	 (0,0)					     |
						    -y
where n = # of sides.

NOTE: This is a useful program for real estate agents.	They always seem to
      have a difficult time  determining  square footage,  and conveniently
      come up with the wrong answer.

***************************************************************************/

#define MAXLEN 20
#include "heath.h"

double abs(number)
double number;
{
	return(number < 0 ? -number : number);	/* if-then-else idiom */
}

char *getline(s)
char s[];
{
   int i;

   for(i = 0; i < MAXLEN; i++) {
	s[i] = getchar();
	if (s[i] == '\n') break;
   }
   if(i < MAXLEN) ++i;
   s[i] = '\0';
   return(s);
}

main()
{
   int i, n;
   char *getline();
   char strg[MAXLEN + 1];
   float dx = 0, dy = 0;
   float last_x = 0, last_y = 0, area = 0;
   float x_err = 0, y_err = 0, x = 0, y = 0;
   float psum_x = 0, nsum_x = 0, psum_y = 0, nsum_y = 0;
   extern double atof();

/******************* . . . instructions for operating program */
   bdos(9,"\033E$");
   printf("\t\t\033pHOUSE AREA CALCULATION PROGRAM\033q\n");
   printf("\n\t\Copyright (c) 1984  Eigenvalue Technologies\n");
   printf("\nDo you wish instructions? ");
   getline(strg);
   if(strg[0] == 'Y' || strg[0] == 'y') {
      bdos(9,"\033E$");
      bdos(9,"INSTRUCTIONS:$");
      printf("\nOne useful application of this program is the calculation of");
      printf("\nthe area of a house.  You only need to walk around the house,");
      printf("\nmeasuring the length of each sequential straight line segment");
      printf("\nbounding the house, noting whether the direction is forward");
      printf("\n(up), backward (down), or left and right for each respective");
      printf("\nsegment.  In fact, if there is one side (segment) that is");
      printf("\ndifficult to measure, consider it as the last segment on");
      printf("\nthe boundary, and the program will calculate it for you.\n");
      printf("\nFirst, count the total number of sides (vertical and hori-");
      printf("\nzontal segments) around the periphery.	This should be an ");
      printf("\neven number.  Now, start at a corner (one of the vertices)");
      printf("\nand enter the length of the each segment as you move around");
      printf("\nthe planform periphery.  Count the length as plus if the");
      printf("\ndirection is up or to the right, as you go around the plan-");
      printf("\nform.  Otherwise enter a minus sign on the length, when the");
      printf("\ndirection is down or to the left.\n");
      printf("\nType any character when ready: ");
      bdos(1,0);
      putchar('\07');
   }

/***************************** . . clear screen & initialize */
   bdos(9,"\033E$");
   printf("\nEnter number of sides: ");
   n = atoi(getline(strg));
   i = n - 1;
   putchar('\n');

/*************** . . collect measurements in the forever-loop */
   for (;;) {

/*************************************** . . do vertical side */

      printf("\t\tEnter Side #%d: ", n - i);
      dy = atof(getline(strg));
      y = last_y + dy;

/* . . . . . . . . . . . . . . . sum of sides for error check */
      if (dy < 0) nsum_y += dy;
      else psum_y += dy;
/* . . . . . . . . . . . . . . . . increment area calculation */
      area = area + (last_x + x) * (last_y - y);
      last_y = y;
      if (--i <= 0) break;


/*********************************** . . do horizontal sides */

      printf("\t\tEnter Side #%d: ", n - i);
      dx = atof(getline(strg));
      x = last_x + dx;

/* . . . . . . . . . . . . . . .sum of sides for error check */
      if (dx > 0) psum_x += dx;
      else nsum_x += dx;

/* . . . . . . . . . . . . . . . increment area calculation */
      area = area + (last_x + x) * (last_y - y);
      last_x = x;
      putchar('\n');
      if (--i <= 0) break;
   }
   putchar('\n');

/****************************** . . complete area calculation */
   area = area + (last_x * last_y);
   printf("\t\tArea = %0.2f\n", area/2);

/******************************* . . calculate possible error */
   dx = 0;
   bdos(9,"\nTo estimate error, enter last side: $");
   dx = atof(getline(strg));
   if (dx != 0) {
   x = last_x + dx;
   if (dx > 0) psum_x += dx;
   else nsum_x += dx;
/* . . . . . . . . . . . . . . . calculate measurement errors */
   x_err = abs(psum_x + nsum_x);
   y_err = abs(psum_y + nsum_y);
   printf("\nCumulative error in horizontal side measurements = +/- ");
   printf("%0.2f", x_err);
   printf("\nCumulative error in  veritcal  side measurements = +/- ");
   printf("%0.2f", y_err);

/* . . . . . . . . . . .calculate possible error in area estimate */
/*
   The following algorithm should be replaced with one that is more
   statistically accurate.
*/
   area = (x_err * (psum_y - nsum_y)) + (y_err * (psum_x - nsum_x));
   printf("\n\nEstimate of error in Area = +/- %0.2f\n", area/2);
   }
   else {
      x_err = -(psum_x + nsum_x);
      printf("\nCalculated length of last side is %0.2f\n", x_err);
   }
   exit(0);
}
