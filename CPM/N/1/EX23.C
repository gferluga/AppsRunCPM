/**************************************************************************
 Copyright (c) 1984				     Eigenware Technologies
			command line flags

NOTE #1: C program convention is to begin arguments with "-", if they are
	 option flags.	Letters after the "-" may then be passed one at a
	 time to a parser for setting program parameters.

NOTE #2: A nice feature of this flag routine is that flags may be grouped in
	 any manner, e.g. all the following command lines will provide the
	 same results:
			  ex18 -x -y -z

			  ex18 -xyz

			  ex18 -z -xy

NOTE #3: For concept see Chapter 5.11, page 112-113.

****************************************************************************/

#include "heath.h"

int n;		 /* . . . . . . . . . . . . . . . . . . . .flag index */
int x, y, z;	/* . . . . . . . . . . . . . . . . . . . . . . flags */

main(argc,argv)
int argc;
char **argv;

{
     x = y = z = NO;   /* . . . . . . . . internal flag initialization */
     if (argc == 1) {
	  printf("Usage: ex20 -xyz  where x, y, and z are option flags\n");
	  printf("\n\tAlso flags must be lower case.\n");
	  exit(BEL);
     }

     for ( n = 1; n < argc; n++) {  /* . . . . .search for minus sign */
	  if( '-' == *argv[n] ) parser(argc,argv[n]);
     }

     if ( x )  printf("Flag x is YES\n");
     if ( y )  printf("Flag y is YES\n");
     if ( z )  printf("Flag z is YES\n");

     exit(0);
}    /*  end of main  */


int parser(ac,av)
int ac;
char *av;

{
     int arglen, i;
     int j;

     arglen = strlen(av);
     for( i = 1; i < arglen; i++) {
	  j = av[i];	  /* . . . . . . . . . . . . . convert to int  */
	  if( j == 'x' ) {
	       x = YES;
	       continue;  /* . . . . . . . . . . .Chapter 3.8, page 62 */
	  }
	  if( j == 'y' ) {
	       y = YES;
	       continue;
	  }
	  if( j == 'x' ) {
	       z = YES;
	       continue;
	  }
	  ERV;
	  printf(" FLAG %c NOT RECOGNIZED \n",av[i]);
	  XRV;
	  BEL;
      }
      return;
}	 /*  end of parser  */
 