/*************************************************************************
 Copyright (c) 1964				    Eigenware Technologies

	       bakword.c  -  pointers and address arithmetic

NOTE #1: A function to reverse letters within a word, for several words
	 within a string,  and leaving the word at the same position in
	 the string.

NOTE #2: For concept see chapter 5.2, p 93 of K & R.

*************************************************************************/

char *bak_word(ps)
char *ps;
{
   char c, temp;
   char *pt1; /*  . . . . . . . . pointer for first character of word	*/
   char *pt2; /*  . . . . . . . . pointer for last  character of word	*/
   char *px2; /*  . . . . . . . . . . . . . . temporary pointer 	*/

   c = ' ';
   pt2 = ps;

   for(;;) {
      pt1 = pt2;

/* . . . . . . . find address and subscript for first character of word */

      while ((c = *pt1++)==' ') { /* . . . . . . . . . .  skip white space */
      }
      --pt1;
      if (c == '\0') return(ps);

/* . . . . . . .  find address and subscript for last charater of word */

      pt2 = pt1;
      while ((c = *++pt2) != ' ' && c != '\0') {
      }

/* . . . . . . . . . . . .  reverse order of the letters for this word */
      --pt1;
      px2 = pt2;
      while (++pt1 < --px2) {
	 temp = ps[pt1-ps];
	 ps[pt1-ps] = *px2;
	 ps[px2-ps] = temp;
      }
   }
} /* end of function bak_word */

main()
{
   char *ps;  /*  . . . . . . . . pointer for first character of string */

/* . . . . . . . . . . . . . . . . . . . . . . . . . .initialize string */

   ps = " 123456789  TOP DAD \0";
   printf("%s\n", ps); /* . . . . . . . . . . print out original string */

   ps = bak_word(ps);
   printf("%s\n", ps); /*  . . . . . . . . . . print out the new string */

exit(0);
}
t(0);
}
*�V� �Ë��������� ������Ë��$;����r�B��R+Ӌ�Zñ��W�=���s�