/*****************************************************************************
 Copyright (c) 1984    All Rights Reserved		Eigenware Technologies

				     io3

RULES:

6.  to write a binary file open it in mode "wb".

    note: this gives an unexpected output file.

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
fp = fopen("num.dat", "wb");             /*  creating num.dat      */
if (fp == 0) 
   {
   say(\n\r error on opening num.dat to write);
   exit(0);
   }
fprintf(fp, "%d %c %D %e", x, a, y, z);
fclose(fp);
exit(0);
}
