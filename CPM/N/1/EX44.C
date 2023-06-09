/*------------------------------------------------------------------------\
| Copyright (c) 1984				   Eigenware Technologies |
|									  |
|				KEY CLICK				  |
|									  |
|	An example to demonstrate turning the H/Z 100 key click 	  |
|	feature on and off.						  |
|									  |
|	NOTE: This program may be modified and used in the ZDOS 	  |
|	autoexec file.......... if you wish to always  turn off 	  |
|	the key click.	 Alternatively, you might use the func- 	  |
|	tion click() to turn off the key click when your appli- 	  |
|	cation program	initializes  and then  turn on	the key 	  |
|	click upon exiting the program. 				  |
|									  |
\------------------------------------------------------------------------*/

#define MAXLEN 80   /* . . . required for getline() */

#define YES 1	    /* . . . . required for click() */
#define NO  0

#include "stdio.h"
#include "click.c"
#include "getline.c"

main()
{
   int key;
   char test[MAXLEN];
   int click();
   char *getline();

/* . . . . . . . . . . . . . . . . . . . . . . . . Try the key click off */

   key = click(NO);

   if (key) printf("\n\t\t\tTHE KEY CLICK IS TURNED ON\n");
   else printf("\n\t\t\tTHE KEY CLICK IS TURNED OFF\n");

   printf("\nEnter a one line sentence: ");
   getline(test);

/* . . . . . . . . . . . . . . . . . . . . . . . .  Try the key click on */

   key = click(YES);

   if (key) printf("\n\t\t\tTHE KEY CLICK IS TURNED ON\n");
   else printf("\n\t\t\tTHE KEY CLICK IS TURNED OFF\n");

   printf("\nEnter a one line sentence: ");
   getline(test);

   exit(0);
}
;
}
 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 