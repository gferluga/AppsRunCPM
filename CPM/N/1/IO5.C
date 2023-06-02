/*****************************************************************************
 Copyright (c) 1984  All Rights Reserved		Eigenware Technologies

				     io5

RULES:

8.  Use fwrite to write data to binary files.
	
9.  Use fread to read data from binary files.

NOTE: dump bin.dat and compare to a dump of num.dat

******************************************************************************/

#include "stdio.h"
#include "pdl.h"

main()
{
int x = 7;
int x2 = 0;
int a = 'a';
int a2 = '@';
char d = 'd';
char d2 = '$';
long y = 1234567;
long y2 = 0;
float z = 123.4567;
float z2 = 0;
int num_elements_written = 0;
int number_elements_read = 0;

FILE *fp, *fopen();
fp = fopen("bin.dat", "rb");

if (fp != 0) 
   {
   say(\n\r bin.dat already exists);
   fclose(fp);
   exit(0);
   }

fp = fopen("bin.dat", "wb");       /*  creating bin.dat in binary mode      */
if (fp == 0) 
   {
   say(\n\r error on opening bin.dat to write);
   exit(0);
   }

num_elements_written = fwrite(&x, 2, 1, fp);
printf("\n %d integer written to bin.dat", num_elements_written);
num_elements_written = fwrite(&a, 2, 1, fp);
printf("\n %d integer written to bin.dat", num_elements_written);
num_elements_written = fwrite(&d, 1, 1, fp);
printf("\n %d character written to bin.dat", num_elements_written);
num_elements_written = fwrite(&y, 4, 1, fp);
printf("\n %d long integer written to bin.dat", num_elements_written);
num_elements_written = fwrite(&z, 4, 1, fp);
printf("\n %d float written to bin.dat", num_elements_written);
fclose(fp);

fp = fopen("bin.dat", "rb");
if (fp == 0) 
   {
   say(\n\r error on opening bin.dat to read);
   exit(0);
   }
printf("\n  before read, x2 =  %d ", x2);
printf("\n  before read, a2 =  %c ", a2);
printf("\n  before read, d2 =  %c ", d2);
printf("\n  before read, y2 =  %D ", y2);
printf("\n  before read, z2 =  %e ", z2);
num_elements_read = fread(&x2, 2, 1, fp);
printf("\n %d integer read from bin.dat", num_elements_read);
printf(";  after read, x2 =  %d ", x2);
num_elements_read = fread(&a2, 2, 1, fp);
printf("\n %d integer read from bin.dat", num_elements_read);
printf(";  after read, a2 =  %c ", a2);
num_elements_read = fread(&d2, 1, 1, fp);
printf("\n %d character read from bin.dat", num_elements_read);
printf(";  after read, d2 =  %c ", d2);
num_elements_read = fread(&y2, 4, 1, fp);
printf("\n %d long integer read from bin.dat", num_elements_read);
printf(";  after read, y2 =  %D ", y2);
num_elements_read = fread(&z2, 4, 1, fp);
printf("\n %d float read from bin.dat", num_elements_read);
printf("; after read, z2 =  %e \n", z2);
num_elements_read = fread(&z2, 4, 1, fp);
printf("\n %d float read from bin.dat", num_elements_read);
fclose(fp);
exit(0);
}
