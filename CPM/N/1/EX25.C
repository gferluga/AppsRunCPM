/************************************************************************
 Copyright (c) 1984				   Eigenware Technologies

     Swapping Array Elements:  -  pointers and address arithmetic

NOTE #1: An extension to point.c for swapping elements within an array.

NOTE #2:  For concept see chapter 5.2, p 93 of K & R.

*************************************************************************/

char c, temp;
int i, j, k;
char *ps;  /* . . . . . . . . . . pointer for first character of string */
char *pt1; /* . . . . . . . . . . pointer for first character of word	*/
char *pt2; /* . . . . . . . . . . pointer for last  character of word	*/

main()
{
   i = 0;  /* . . . . . . . . . . subscript for first character of word */
   j = 0;  /* . . . . . . . . . . subscript for last  character of word */
   c = ' ';

/* . . . . . . . . . . . . . . . . . . . initialize string and pointers */

   ps = " 123456789 \0";
   pt1 = pt2 = ps;
   printf("%s\n", ps); /* . . . . . . . . . . print out original string */

/* . . . . . . . find address and subscript for first character of word */

   while ((c = *pt1++)==' ') { /* . . . . . . . . . .  skip white space */
   }
   --pt1;
   i = pt1-ps;
   if (c == '\0') exit(0);

/* . . . . . . .  find address and subscript for last charater of word */

   j = i;
   pt2 = pt1;
   while ((c = *++pt2) != ' ' && c != '\0') {
   }
   j = pt2-ps;

/* . . . . . . . . . . . .  reverse order of the letters for this word */
   --pt1;
   while (++pt1 < --pt2) {
      temp = ps[pt1-ps];
      ps[pt1-ps] = *pt2;
      ps[pt2-ps] = temp;
   }
   printf("\n\n%s", ps);
   exit(0);
}
   exit(0);
}
 �������P�ڊ�N����6"�O�����G<u2�P��ڠN�ù� �*2�C���Q��� ��Y�á ����$Ë 