/*************************************************************************

      filter program to find control characters in an ASCII file.

	     Copyright (c)  1984  Eigenware Technologies

NOTE #1: Control characters are identified with the prefix "^"
	 and reverse video.

NOTE #2: For concept refer to K&R, chapter 7.6, page 151.

NOTE #3: fp is the pointer to the file and fopen returns this pointer.

***************************************************************************/

#include "stdio.h"
#include "heath.h"

main(argc, argv)
int argc;
char *argv[];
{
   FILE *fopen(), *fp;

   int c; /* . . . declared int to recognized EOF = -1 */

   printf("\nCopyright (c)  1984  Eigenware Technologies\n");
   if (argc != 2) {
	printf("\n\033pUSAGE:\033q  A>EX24 filename <CR>");
	BEL;
	exit(0);
   }
   if ((fp =fopen(argv[1], "r")) == 0) {
	printf("%s failed to open\n", argv[1]);
	BEL;
	exit(0);
   }
   while ((c= getc(fp)) != EOF && c != AEOF) {
      if (c < ' ' && c != '\n') {
	   ERV;
	   putchar('^');
	   putchar(c + '@');
	   XRV;
      }
      else putchar(c);
   }
   fclose(fp);
   exit(0);
}

   exit(0);
}

� �4X���v��t�v��t	X^;�� �v��t	�v��tX��@ P�v��tX^#��u� ���P� �F�PX��]Ë�]��ɋv�t