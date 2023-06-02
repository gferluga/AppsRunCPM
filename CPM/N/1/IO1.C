/*****************************************************************************
 Copyright (c) 1984  All Rights Reserved		Eigenware Technologies

				     io1

RULES:

1.  Always declare two pointers to type FILE.

    e.g., FILE *fp, *fopen();

2.  Open a file before read or write using fopen(string1,string2);

	 string1 is a literal, i.e., "name.ext" or a string variable
	 string2 is a literal for the mode, e.g., "w", 'r', "a", ...  

3.  Must assign a value to the file pointer (in this case, fp), and then use 
the pointer in subsequent references to the file.

    fp = fopen("name.ext", "r");  --to open the file to read.
    fclose(fp); 		  --to close the file.


*****************************************************************************/

#include "stdio.h"
#include "pdl.h"

main()
{
int x = 4;
int y = 5;
int z = 6;
FILE *fp, *fopen();
fp = fopen("num.dat", "w");
if(fp == 0) say(\n\r error on opening num.dat);
fprintf(fp, "%d%d%d",x,y,z);
fclose(fp);
exit(0);
}
