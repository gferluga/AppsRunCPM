/**************************************************************************
 Copyright (c) 1984				     Eigenware Technologies
			       page, for NEC

This program displays any file on the screen.  Unlike the CP/M type command, 
however, it pages the file onto the screen in 25 line chunks.  Control 
characters are printed in yellow and non-ASCII characters in red.  Binary 
files can be displayed but terminate when a control z is read.	Help is 
available.  A wordstar option resets bit 7 and displays the original ASCII
character in red.  

NOTE: make appropriate modifications for Heath/Zenith or whatever.

****************************************************************************/

#include "stdio.h"
#include "nec.h"    /* . . . . . . . . .  replace this file as appropriate */
#include "pdl.h"

FILE *fopen(), *fp; /* . . . declare global; use in both main and function */
int blank_screen = 0;

int new_page()
{
   unsigned int c;
   if  ( kbd_char == abort )
     {
	 fclose(fp);
	 cyan_exit(aborted page);
     }
   home; erase; blank_screen = 1; cyan;
   return(0);
} /* . . . . . . end of newpage() */

main(argc, argv)
int argc;
char *argv[];
{
unsigned int c;
unsigned int line_count = 0;
register int wordstar = 0;
int no_h, no_w = 1;

if ((argv[1][0] == '-' && argv[1][1] == 'h') || \
    (argv[2][0] == '-' && argv[2][1] == 'h'))
   {
   nl;
   red;    say(\t\t non-ASCII characters are red\n\r);
   yellow; say(\t\t control characters are yellow\n\r);
   cyan;   say(\t\t text is cyan\n\r);
   cyan;   say(\t\t type control c to exit\n\r);
   cyan;   say(\t\t or type any key to continue\n\n\r);
   cyan;   say(\t\t options are:\n\r);
   cyan;   say(\t\t\t -h displays this message\n\r);
   cyan;   say(\t\t\t -w resets bit seven and displays character in red\n\n\r);
   white;  wait;
   no_h = 0;
   }
if ((argv[1][0] == '-' && argv[1][1] == 'w') || \
    (argv[2][0] == '-' && argv[2][1] == 'w'))  
   {
   wordstar = 1;
   no_w = 0;
   }
if (argc != 2 && (no_h) && (no_w))
   {
   red; say(usage: ); yellow; say(page [-h] [-w] filename.ext);
   bell; cyan; exit(0);
   }
if ((fp = fopen(argv[(argc -1)], "r")) == 0)
   {
   if (argv[argc - 1][0] == '-')
      {
      nl; red; say(usage: ); yellow; say(page [-h] [-w] filename.ext );
      bell; cyan; exit(0);
      }
   else
      {
      red; printf("%s cannot be opened\n", argv[(argc-1)]);
      bell; cyan; exit(0);
      }
   }
erase; home; cursor_off; status_off; cyan;

while ((c= getc(fp)) != EOF)
      {
      blank_screen = 0;
      if (c == '\n')                            /*  count the lines           */
         {
	 if (++line_count == 25) line_count = new_page();
         }
      if (c < ' ' && c != '\n' && c != '\t')  /*  it's a control character  */
	 {yellow; putchar(c + '@'); cyan;}
      else if (c > '~')                       /*  it's non-ASCII            */
	      {
  	      if (wordstar == 1)
		  c -= '\200';                /*  set bit seven to zero     */
              {red; putchar(c); cyan;}
	      }
      else                                    /*  it's normal text          */
         {
	 if (c != '\t')                       /*  it's not a tab                */
	    {putchar(c);}
	 else
  	    say(        );                    /*  8 blanks for a tab        */
	 }
      }
fclose(fp);
if (blank_screen == 0) bdos(1,0);
cyan_exit(finis page);
}  /* end of main */
 of main */
���^:��r@����� ��P�x:��u@Z"���s�@����� �Έ��������������������� ��Ƃ