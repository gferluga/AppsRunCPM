/**********************************************************************
 Copyright (c) 1984				 Eigenware Technologies
			      getstrg.c

	    a subprogram for data entry from the console
		      (without the linefeed)

***********************************************************************/

char *getstrg(s)
char s[];
{
   int i;

   for(i = 0; i < MAXLEN; i++) {
	s[i] = getchar();
	if (s[i] == '\n') {
	      s[i] = '\0';     /* . . . . . . . .remove the linefeed */
	      break;
	}
   }
   if(i < MAXLEN) ++i;
   s[i] = '\0';
   return(s);
}
 return(s);
}
еееееееееееееееееееееееееееееееееееееееееееееее