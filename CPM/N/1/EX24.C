/************************************************************************
 Copyright (c) 1984				   Eigenware Technologies

	       point.c	-  pointers and address arithmetic

NOTE:  For concept see chapter 5.2, p 93 of K & R.

*************************************************************************/

char c;
int i, j, k;
char *ps;  /* . . . . . . . . . . pointer for first character of string */
char *pw1; /* . . . . . . . . . . pointer for first character of word	*/
char *pw2; /* . . . . . . . . . . pointer for last  character of word	*/

main()
{
   i = 0;  /* . . . . . . . . . . subscript for first character of word */
   j = 0;  /* . . . . . . . . . . subscript for last  character of word */
   c = ' ';

/* . . . . . . . . . . . . . . . . . . . initialize string and pointers */

   ps = " 123456789 \0";
   pw1 = pw2 = ps;
   printf("\n\n%s\n", ps); /* . . . . . . . . . . print out original string */
   printf("\nps = %d, pw1 = %d\n", ps, pw1);

/* . . . . . . . find address and subscript for first character of word */

   while ((c = *pw1++)==' ') { /* . . . . . . . . . .  skip white space */
   }
   c = *--pw1;
   i = pw1-ps;
   printf("\npw1 = %d, i = %d, c = %c", pw1, i, c);
   if (c == '\0') exit(0);

/* . . . . find last charater of word */

   j = i;
   pw2 = pw1;
   while ((c = *++pw2) != ' ' && c != '\0') {
   }
   c = *--pw2;
   j = pw2-ps;
   printf("\npw2 = %d, j = %d, c = %c", pw2, j, c);
   exit(0);
}
   exit(0);
}
c s d D x X u U o O b B f e