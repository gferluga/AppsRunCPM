/***********************************************************************
 Copyright (c) 1984				  Eigenware Technologies

     Data entry from console (stdin) using the function getline(s)

***********************************************************************/

#define MAXLEN 80
/*#include "stdio.h" comment out for Aztec */
/*#include "getline.c" comment out for Aztec */

main()
{
   char strg[MAXLEN + 1];
   char *getline();
   extern double atof();

   printf("\n\t\t\033pA DEMONSTRATION OF THE GETLINE FUNCTION\n\033q");

/* to input a string */
   printf("\n\tEnter a one line sentence: ");
   printf("\n\nSentence = %s\n", getline(strg));

/* to input an integer */
   printf("\n\tEnter a decimal integer, less than 32,767: ");
   printf("\nInteger = %d\n", atoi(getline(strg)));

/* to input a real number */
   printf("\n\tEnter a real number: ");
   printf("\nNumber = %f\n", atof(getline(strg)));

   exit(0);
}
