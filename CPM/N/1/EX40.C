/**************************************************************************
 Copyright (c) 1984				     Eigenware Technologies

		       Array of Structure of Arrays

NOTE: #1: For concept refer to page 123, chapter 6.3 of K & R.

NOTE: #2:  Modify and expand: Declare a pointer for the array-of-structure.
	   Add a loop-until-done with appropriate pointer arithmetic.  Add
	   sorting,  file I/O,	etc.,  and you may have a  good mail label
	   program.  Better add some "bullet-proofing" on data input  from
	   the console.

**************************************************************************/

#define  MAXLEN    35	 /* . . . . . . . . . .  normal length of labels */
#define  LIST_SIZE  2	 /* . . . . . . . number of names with addresses */

#include "stdio.h"	/* . . .  required for getchar used by getline.c */
#include "getstrg.c"

struct namelist {
	 char name[MAXLEN];
	 char addr[MAXLEN];
	 char city[MAXLEN - 8];  /* on same line as state and zip */
         char state[MAXLEN - 32]; /* allow only two characters for state */
         char zip[MAXLEN - 29];     /* . . . . .  five char's for zip code */
} mail[LIST_SIZE], *pmail;


main()
{
   int i, j;
   char answer, strg[MAXLEN + 1], *pt;
   char *getstrg(); /* . .  declare that function is returning a pointer */

   extern struct namelist mail[];
   extern struct namelist *pmail;

/* . . . . . . . . . . . . . . . . . . . . . . add start loop-until here */

   i =0;
   pmail = &mail[i];
   answer = 'Y';

   printf("\n\nEnter Full Name (e.g. Mr. Joe Smith): ");
   pt = getstrg(strg);
   for(j = 0; *pt != '\0'; j++)
               pmail->name[j] = *pt++;

   printf("\nEnter Street Address (e.g. 1809 Kilobyte Drive): ");
   pt = getstrg(strg);
   for(j = 0; *pt != '\0'; j++)
               pmail->addr[j] = *pt++;

   printf("\nEnter City (e.g. Ceeville): ");
   pt = getstrg(strg);
   for(j = 0; *pt != '\0'; j++)
               pmail->city[j] = *pt++;


   printf("\nEnter State (two letters - e.g. CA): ");
   pt = getstrg(strg);
   for(j = 0; *pt != '\0'; j++)
               pmail->state[j] = *pt++;

   printf("\nEnter Zip Code (five digits): ");
   pt = getstrg(strg);
   for(j = 0; *pt != '\0'; j++)
               pmail->zip[j] = *pt++;

   /* . . . . . . . Add capability to make corrections before going on for */
   /*               next name and address.                                 */


   printf("\n\n\n\tDo you wish to view the last address? ");
   if ((answer = bdos(1,0)) == 'N' || answer == 'n') exit(0);
                                 /* rather than exit loop for next address */

   maillabel(pmail);

   exit(0);
}

maillabel(plabel)   /* print mailing labels */
struct namelist *plabel;
{
   printf("\n\n");
   printf("\t%s\n", plabel->name);
   printf("\t%s\n", plabel->addr);
   printf("\t%s, %s  %s", plabel->city, plabel->state, plabel->zip);
   printf("\n\n");

   return(0);
}
   return(0);
}
city, plabel->state, plabel->zip);
   printf("\n\n");

   re