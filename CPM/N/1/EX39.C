/****************************************************************************
 Copyright (c) 1984				       Eigenware Technologies

			  strutures and functions		       (CI86)

NOTE #1: For concept see page 121, chapter 6.2, K & R.

NOTE #2: Structures cannot be passed to functions, so use pointers.

NOTE #3: Structures are a neat way to bundle all the different data types
	 together that need to be passed to a function.  Then the passing
	 is done very efficiently with only one pointer.

NOTE #4: This is not an accurate clock.

NOTE #5: Modify this prgoram, adding the locate function to preclude
	 scrolling on the screen.

*****************************************************************************/

#include "stdio.h"
#include "locate.c"

struct clock
      {
	 char noon;
	 int hour;
	 int min;
	 int sec;
      } time, *ptime; /* . . make ptime a pointer to this type of structure */

main()
{
   ptime = &time; /* . . . . . . . . . . . . . . initialize pointer to time */

   ptime->noon = 'A';
   ptime->hour = 11;
   ptime->min = 48;
   ptime->sec = 59;
   cls();
   for(;;) {
      locate(12,30);
      printf("\n\tThe time is %d:%d:%d %c.M.", time.hour, time.min,
						     time.sec, time.noon);
      update(ptime);
   }
   EXIT(0);
}

update(pt)
struct clock *pt;
{

   if(pt->sec++ == 60) {  /* . . . . increment after */
      pt->sec = 0;
      if(++pt->min == 60) { /* . . . . . . . or increment before */
	 pt->min = 0;


	 if(++pt->hour == 12) {
	    if(pt->noon == 'P') pt->noon = 'A';
	    else pt->noon = 'P';
	 }
	 if(pt->hour == 13) pt->hour =1;
      }
   }
   return(0);
}
d %c.M.", time.hour, time.min,
						     time.sec, time.noon);
      update(ptime);
   }
}

update(pt)
str