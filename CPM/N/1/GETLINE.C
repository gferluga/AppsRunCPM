/**********************************************************************
 Copyright (c) 1984				 Eigenware Technologies

			      getline.c

	a subprogram for data entry with line feed appended

***********************************************************************/

char *getline(s)
char s[];
{
   int i;

   for(i = 0; i < MAXLEN; i++) {
	s[i] = getchar();
	if (s[i] == '\n') break;
   }
   if(i < MAXLEN) ++i;
   s[i] = '\0';
   return(s);
}


rn(s);
}


�� �� � P�F�^�P�v�V�