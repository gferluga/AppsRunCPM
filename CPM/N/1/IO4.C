/*****************************************************************************
 Copyright (c) 1984   All Rights Reserved		Eigenware Technologies

				     io4

RULES:

7.  Use fscanf to read ASCII formatted files written by fprintf.

    Note: arguments of fscanf must be pointers.

******************************************************************************/

#include "stdio.h"
#include "pdl.h"

main()
{
int x = 7;
int x2 = 0;
char a = 'a';
char a2 = '@';
long y = 1234567;
long y2 = 0;
float z = 123.4567;
float z2 = 0;


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
fprintf(fp,"%d%c%D%e", x, a, y, z);
fclose(fp);
printf("\n before read, data2 =  %d %c %D %e", x2, a2, y2, z2);
fp = fopen("num.dat", "r");             /*  creating num.dat      */
if (fp == 0) 
   {
   say(\n\r error on opening num.dat to read);
   exit(0);
   }
fscanf(fp,"%1d%1s%7ld%14e", &x2, &a2, &y2, &z2);
fclose(fp);
printf("\n  after read, data2 =  %d %c %D %e", x2, a2, y2, z2);
exit(0);
}
