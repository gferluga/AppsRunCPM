/***************************************************************************
 Copyright (c) 1984				      Eigenware Technologies


   braces.c - filter program to check that all right braces "]", ")", "}"
	      match corresponding left braces "[", "(", "{".

   A check is also made for a nesting assumption that () and {} should not
   be within [] and {} should not be within ().


EXAMPLE:    .__________________ line #21.
	    |
	   21.2.1.0
	       | | |___( ) are closed.
	       | |____________________ one [ ] is open.
	       |______________________________________two { } are open.

*****************************************************************************/

#include "stdio.h"
#include "heath.h"

FILE *fopen(), *fp;

int i, c = 0;  /* . . . . . . declared int to recognized EOF = -1 */
int ln = 0;    /* . . . . . . . . . . . . . . . . . . line number */
int b[3] = {0,0,0}; /* level numbers for [], (), {}, respectively */
int b_err[3] = {0,0,0};  /* . . . . . . . count of nesting errors */

main(argc, argv)
int argc;
char *argv[];
{

   printf("\nCopyright (c)  1984  Eigenware Technologies\n");
   if (argc != 2) {
	printf("\n\033pUSAGE:\033q  A>EX27 filename <CR>");
	BEL;
	exit(0);
   }
   if ((fp = fopen(argv[1], "r")) == NO) {
	printf("%s failed to open\n", argv[1]);
	BEL;
	exit(0);
   }
   printf("1.0.0.0");
   while ((c= getc(fp)) != EOF && c != AEOF) {
      putchar(c);
      if (c == '\n') {
	 ++ln;

/* output nesting error status for previous line and start next line
   with line number and brace levels
*/
	 err_out(b_err);
	 printf("%d.%d.%d.%d:", ln, b[2], b[1], b[0]);
      }
      if (c == '[' || c == ']' || c == '(' || c == ')' ||
		c == '{' || c == '}') brc_ch(c, b, b_err);
   }
   fclose(fp);
   if (b[0] != 0) {
      printf("\n\nThere were %d mismatches for []-braces.\n", fabs(b[0]));
      if (b[0] > 0) printf("Missing right brace(s): \033p]\033q.\n");
      else printf("Missing left brace(s): \033p[\033q.\n");
   }
   if (b[1] != 0) {
      printf("\n\nThere were %d mismatches for ()-braces.\n", fabs(b[1]));
      if (b[0] > 0) printf("Missing right brace(s): \033p)\033q.\n");
      else printf("Missing left brace(s): \033p(\033q.\n");
   }
   if (b[2] != 0) {
      printf("\n\nThere were %d mismatches for {}-braces.\n", fabs(b[2]));
      if (b[0] > 0) printf("Missing right brace(s): \033p}\033q.\n");
      else printf("Missing left brace(s): \033p{\033q.\n");
   }
   exit(0);
}

/* brc_ch() - level count of braces and checks for improper nesting
	      of braces.
*/
void brc_ch(c, b, b_err)
int c, *b, *b_err;
{
   int i;
   switch (c) {
      case '[' :
	 ++b[0];
	 break;
      case ']' :
	 --b[0];
	 break;
      case '(' :
	 ++b[1];
	 if (b[0] > 0) b_err[0] = YES;
	 break;
      case ')' :
	 --b[1];
	 break;
      case '{' :
	 ++b[2];
	 if (b[1] > 0) b_err[1] = YES;
	 if (b[0] > 0) b_err[0] = YES;
	 break;
      case '}' :
	 --b[2];
   }
   for (i = 0; i < 3; i++) if (b[i] < 0) b_err[2] = YES;
   return(0);
} /* . . . . . . . . . . end of brc_ch */

void err_out(b_err)
int *b_err;
{
   if (b_err[0]) printf("\t\tNesting of [] may be improper\n");
   if (b_err[1]) printf("\t\tNesting of () may be improper\n");
   if (b_err[2]) printf("\t\tMissing left brace\n");
   b_err[0] = b_err[1] = b_err[2] = NO;
   return(0);
}

   return(0);
}






