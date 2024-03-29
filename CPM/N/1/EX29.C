/**************************************************************************

	snakeoil.c  -  filter progam, an example of file I/O

	    Copyright (c) 1984 by Eigenware Technologies

A simple filter to convert document type files to non-document type
files.	 This is accomplished by clearing BIT #7 (MSB) of all char-
acters and blocking all control characters, except horizontal tab,
line feed,  form feed and carriage return (HEX 09, 0A, 0C and 0D).

APPLICATIONS:
	  (1) Condition downloaded files from Micronet for editing.
	  (2) Convert Wordstar document files to non-document files.
	  (3) Transfer of files between different editors and word
	      processors.
	  (4) File conditioning for different compilers.

NOTE: To test this program use file test.dat on disk. Save the
      backup copy, because this program should "destroy" it.

***************************************************************************/

#include "stdio.h"
#include "heath.h"
#include "locate.c"

#define VERSION bdos(9,"Ver H.0000$")
#define YES	1
#define NO	0
#define SP	'\040'
#define BEL	putchar('\007')
#define US	31
#define HT	9
#define LF	10
#define FF	12
#define CR	13

backup(s,temp)
char *s;
char *temp;
{
	int i, j;
	char *t;
	t = ".BAK";
	i = j = 0;

	while (s[i] != '.' && i<11 && s[i] != '\0') {
	   temp[i] = s[i];
	   i++;
	}
	do temp[i++] = t[j++];
	while (t[j] != '\0');
	temp[i] = '\0';
	unlink(temp); /* . . . . . . if you don't, you may be surprised */
	if(rename(s,temp) < NO) {
	   BEL;
	   printf("A backup file cannot be created\n");
	   exit(CURSON);
	}
	return(0);
} /* end of function backup */

main(argc, argv)
int argc;
char *argv[];
{
   FILE *fopen(), *fp1, *fp2;

   char *temp;	/*  . . . . . . . . . . . . . . . . backup filename */
   int ln;	/*  . . . . . . . . . . . . . . . . . . line number */
   int c;	/* declare as int so that "getc" will recognize EOF */
   char answ;
   ln = 0;

/* Instructions for user and some pretty screen friendliness */

   CURSOFF;
   CLS;
   locate(23,17);
   bdos(9,"Copyright (C) 1984 by EIGENWARE TECHNOLOGIES$");
   locate(2,34);
   printf("\033p SNAKEOIL \033q");
   locate(3,34);
   VERSION;
   if (argc != 2) {
      printf("\n\033pUSAGE:\033q A>EX26 FILENAME<CR>\n");
      BEL; exit(CURSON);
   }

/* create backup file */

   temp = "B:DUMMMMY.BAK";
   backup(argv[1],temp);

/* open files, error checks and messages */

   if ((fp1 = fopen(temp, "r")) == NO) {
       printf("Cannot open a backup file\n");
       BEL;
       rename(temp, argv[1]);
       exit(CURSON);
   }
   if ((fp2 = fopen(argv[1], "w")) == NO) {
	printf("Cannot create a filtered file");
	BEL;
	exit(CURSON);
   }
/* Add more checks and messages as desired, e.g. if file already
   exists, should you overwrite?
*/

/* Now let's get the job done */

   printf("\n\n\t\t A backup file %s has been created.", temp);
   while ((c = getc(fp1)) != EOF && c != AEOF) {
	   if (c > US || c == HT || c == LF || c == FF || c == CR) {
	      if( c == LF ) {
		 locate(9,18);
		 printf("Lines through number \033p%d\033q", ++ln);
		 printf(" have been processed.");
	      }
	      c = c & 0177;
	      if (putc(c,fp2) == NO) {
		  printf("Write error; disk may be full\n");
		  BEL;
		  exit(CURSON);
	      }
	   }
   }
   putc(AEOF,fp2); /* . . make sure a ^Z is appended to output file */
   fclose(fp1);
   fclose(fp2);
   answ = 'N';
   printf("\n\n\n\t\t	 A  \033pnew\033q %s has been created.", argv[1]);
   printf("\n\n\t\t Do you wish to \033perase\033q %s (Y or N)? ", temp);
   CURSON;
   answ = bdos(1,0);
   if (answ == 'Y' || answ == 'y') unlink(temp);
   BEL;
   exit(CURSON);
} /* end of main */
* end of main */
X^#��u� � P�v�t��  �� ^;�t