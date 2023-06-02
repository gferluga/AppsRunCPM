/*****************************************************************************
 Copyright (c) 1984					Eigenware Technologies
				     io6d				(CI86)

RULES:
		      
10.  Use a struct to compact the freads and fwrites.

NOTE: dump packed.dat and compare to a dump of bin.dat

NOTE: Structure initialization is external to main().

******************************************************************************/

#include "stdio.h"
#include "pdl.h"

FILE *fp, *fopen();

int num_elements_written = 0;
int num_elements_read = 0;

struct data_pack		/* a 13 byte structure	 */
   {
   int x;
   int a;
   char d;
   long y;
   float z;
   };

struct data_pack packed_data  = {7, 'a', 'd', 1234567, 123.4567};
struct data_pack packed_data2 = {0, '@', '$', 0,       0,      };

main()
{

fp = fopen("packed.dat", "rb");

if (fp != 0) 
   {
   say(\n\r packed.dat already exists);
   fclose(fp);
   exit(0);
   }

fp = fopen("packed.dat", "wb");  /*  creating packed.dat in binary mode   */
if (fp == 0) 
   {
   say(\n\r error on opening packed.dat to write);
   exit(0);
   }

num_elements_written = fwrite(&packed_data.x, 13, 1, fp);
printf("\n %d data_pack written to packed.dat", num_elements_written);
fclose(fp);

fp = fopen("packed.dat", "rb");
if (fp == 0) 
   {
   say(\n\r error on opening packed.dat to read);
   exit(0);
   }
printf("\n  before read, packed_data2.x =  %d ", packed_data2.x);
printf("\n  before read, packed_data2.a =  %c ", packed_data2.a);
printf("\n  before read, packed_data2.d =  %c ", packed_data2.d);
printf("\n  before read, packed_data2.y =  %D ", packed_data2.y);
printf("\n  before read, packed_data2.z =  %e ", packed_data2.z);

/*  now read the data back into packed_data2   */

num_elements_read = fread(&packed_data2.x, 13, 1, fp);

/*  and display it   */

printf("\n %d data_pack read from packed.dat", num_elements_read);
printf(";\n  after read, packed_data2.x =  %d ", packed_data2.x);
printf(";\n  after read, packed_data2.a =  %c ", packed_data2.a);
printf(";\n  after read, packed_data2.d =  %c ", packed_data2.d);
printf(";\n  after read, packed_data2.y =  %D ", packed_data2.y);
printf(";\n  after read, packed_data2.z =  %e ", packed_data2.z);
fclose(fp);
exit(0);
}
fp)