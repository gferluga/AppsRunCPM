/*****************************************************************************
 Copyright (c) 1984   All Rights Reserved		Eigenware Technologies

				     io2

RULES:

4.  Check for file already exists before opening to write by first opening
    to read.

5.  Opening a file to write will create a new file if none exists, delete
    an existing file, if any.

******************************************************************************/

#include "stdio.h"
#include "pdl.h"

main()
{
int x = 7;
char a = 'a';
long y = 1234567;
float z = 123.4567;

FILE *fp, *fopen();
fp = fopen("num.dat", "r");

if (fp != 0) 
   {
   say(\n\r num.dat already exists);
   fclose(fp);
   exit(0);
   }
fp = fopen("num.dat", "w");             /*  creating num.dat      */
if (fp == 0) 
   {
   say(\n\r error on opening num.dat to write);
   exit(0);
   }
fprintf(fp, "%d %c %D %e", x, a, y, z);
fclose(fp);
exit(0);
}
��� � ����#��� �:s� �u����n��
�i���<$t�AQ����Y��