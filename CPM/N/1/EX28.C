/**************************************************************************
 Copyright (c) 1984				     Eigenware Technologies

			 a simple "type" program

NOTE: This program displays an ASCII file on the screen, like the CP/M
      type command.  Unlike the type command, however, it pages the
      file onto the screen in 20 line chunks.

****************************************************************************/

#include "stdio.h"
#include "heath.h"

FILE *fopen(), *fp; /* . . . declare global; use in both main and function */

int newpage()
{
   char answ;
   answ = 'Y';
   printf("\n\n\t\t\033pDO YOU WISH TO CONTINUE?\033q (Y OR N) ");
   CURSON;
   if ((answ = bdos(1,0)) == 'N' || answ == 'n') {
	 fclose(fp);
	 CLS;
	 CUH;
	 exit(CURSON);
   }
   CURSOFF;
   EEL; /* . . . . . . . . .  . erase entire line */
   return(0);
} /* . . . . . . end of newpage() */

main(argc, argv)
int argc;
char *argv[];
{
   int ln, c; /* . . . declared int to recognized EOF = -1 */
   ln = c = 0;

   printf("\nCopyright (c)  1983  Eigenware Technologies\n");
   if (argc != 2) {
	printf("\n\033pUSAGE:\033q  A>EX25 filename <CR>");
	BEL;
	exit(0);
   }
   if ((fp = fopen(argv[1], "r")) == NO) {
	printf("%s cannot be found\n", argv[1]);
	BEL;
	exit(0);
   }
   CURSOFF;
   while ((c= getc(fp)) != EOF && c != AEOF) {
      if (c=='\n') {
	 if (++ln == 20) ln = newpage();
      }
      putchar(c);
   }
   fclose(fp);
   exit(CURSON);
} /* end of main */
of main */
e