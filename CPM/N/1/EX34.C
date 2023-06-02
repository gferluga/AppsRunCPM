/***********************************************************************
 Copyright (c) 1984				 Eigenware Technologies

		  "tohex" with some error checking

NOTE #1: Expand this program to include conversions in both directions,
	 e.g. decimal to hex and hex to decimal.

NOTE #2: Expand this program to include conversions between all the
	 numbering systems, including octal and binary.

***********************************************************************/

#include "heath.h"
#define puts printf

main(argc,argv)
int argc;
char **argv;

{
   char num[80];
   int i;

/* check for correct number of arguments */

   if( argc != 2) {
       puts("\n\t\t\033pUSAGE:\033q  A>EX29 DECIMAL\n");
       exit(0);
   }

/* check for character type */

   strcat(argv[1],"\0");
   strcpy(num, argv[1]);
   for( i = 0; i < strlen(num); i++) {
      if( !isdigit(num[i]) )  {
	 printf("\n\t\t%s contains a non-digit character, %c.\n",num, num[i]);
	 printf("\n\t\tIt's HEX value is %x.", num[i]);
	 exit(BEL);
      }
   }



   printf("\n\t\t%x\n",atoi(num) );
   exit(0);
}
  exit(0);
}
 errors */

