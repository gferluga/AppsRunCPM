/*****************************************************************************

	   function for addressing cursor on Heath/Zenith System

		Copyright (c) 1984 by Eigenware Technologies

NOTE: This function is a useful addition to your library.

*****************************************************************************/

#ifdef C80
#include "printf.c"
#endif

#define void int
#define CLS bdos(9,"\033E$")

main()
{
     int i, j;	/* . . . . . . . . . . . . . . . . . coordinates for cursor */
     i = 12;	/* . . . . . . . . . . . . . . . inititalize auto variables */
     j = 40;

     CLS;
     puts("Locate Cursor at Center of Screen:");
     locate(i, j);   /* . . . . . . . . . .  call function to locate cursor */
     printf("+ Hello at (%d, %d)", i, j);

     exit(0);
}


void locate(row,column)  /* void declares a function to return no arguments */
int row,column; 	 /* . . . . . . . . . . . declare input parameters  */

{
      printf("\033Y%c%c",row + 31, column + 31);
      return;
}

#ifdef C80
#include "stdlib.c"
#endif
lib.c"
#endif
�v܁ ��v���!DD�F�F��u� � P�v�X�V�F�^