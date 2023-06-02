/*****************************************************************************
 Copyright (c) 1984					Eigenware Technologies
				  PDL.h

		  Preprocessor definitions for Ada PDL

*****************************************************************************/

#define wait	  bdos(9,"waiting for any key$");bdos(1,0)
#define say(X)	  bdos(9,"X$")		 /* Put String(X)		   */
#define say_alt(X) bdos(9,"\033(1(X)$"	 /* Type X from Alternate Char Set */
#define sub	  '\032'		 /* CP/M EOF (sub)		   */
#define nl	  bdos(9,"\015\012$")	 /* put CR, LF (newline)	   */
#define next_char (c = getchar())	 /* gets next char from stdin	   */
#define not_EOF  ((c = getchar())!=EOF)  /* used for while not EOF	   */
#define abort	  '\003'		 /* control c			   */
#define kbd_char  (c = bdos(1,0))	 /* get keyboard char to c	   */
#define repeat(N) for(i=0; i<=N; ++i)	 /* standard for loop		   */












keyboard char to c         */
#define repeat(N) for(i=0; i<=N; ++i)    /* standard for loop      