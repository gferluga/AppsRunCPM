/*************************************************************************

			   do { } while, AEOF
			       and #ifdef

		 Copyright (c) 1984 Eigenware Technologies

NOTE #1: AEOF = control-Z is CP/M and ZDOS compatible end of file marker.

NOTE #2: If you have not noticed by now, the preprocessor is useful for
	 conversions and portability between compilers.  To compile using
	 BDS-C, simply replace CI86 in the #define expression with BDSC.
	 Similarly, replace CI86 with C80 to compile with C/80.

NOTE #3: You might wish to construct a file ci-bds.h, or whatever, for
	 your library, and #include whenever you need it.

BUGS: Need a null at end of string, i.e. s[--i] = '\0'

**************************************************************************/

#define CI86 1
#define MAXLEN 80

#ifdef CI86
#define AEOF 0x1A
#define puts printf
#endif

#ifdef BDSC
#define AEOF CPMEOF
#endif

#ifdef C80
#include "printf.c"
#define puts printf
#define AEOF 0x1A
#endif

main()
{
    int i;
    char c, *prompt, s[MAXLEN + 1];

#ifdef C80
    extern char Cmode;
    Cmode = 0;
#endif

    prompt = "Enter less than 80 characters, quiting with crtl-z\n";

    puts(prompt);
    do {
       c = bdos(1,0);	/* . . . . . get a character from standard input */
       s[i] = c;
       printf(",  Decimal value = %d", c);
       printf(",  Octal value = %o", c)  ;
       printf(",  Hex value = %x\n", c)  ;
       i++;		/* . . . . .  increment pointer to end of string */
    }  while( c != AEOF );  /* . . . . . . . . . . .  end loop on ctrl z */

    puts("\nEnd of input.\n\n");
    printf("%s\n",s);
    exit(0);
}
#ifdef C80
#include "stdlib.c" /* required for bdos */
#endif
ed for bdos */
#endif
��Ѓ��F��u� �F��