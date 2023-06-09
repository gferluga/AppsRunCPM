/************************************************************************
 Copyright (c) 1984				   Eigenware Technologies

			 do {.....} while loop

		Copyright (c) 1983  Eigenware Technologies

NOTE #1: See K&R, chapter 3.6, pages 59-60.

NOTE #2: First output of string is improperly terminated.  Experiment
	 by entering  less than  10 characters,  with  uninititalized
	 character array.

	 Second output is properly terminated by replacing the 0 with
	 a null.

************************************************************************/

main()
{
/* . . . . . . . . . . . . . . . . . . . . . . . . .declare auto variables */

    int j;
    char c, s[10];

/* . . . . . . . . . . . . . . . . . . . . . . . . . . . .declare pointers */

    char *title_1, *title_2, *title_3, *prompt, *mssg;

/* . . . . . . . . . . . . . .initialize auto variable and assign pointers */

    j = 0;
    title_1  = "\n\033p DEMONSTRATE do { . . . . } while loop \033q\n";
    title_2  = "\n\033p DEMONSTRATE improper string termination \033q\n";
    title_3  = "\n\033p DEMONSTRATE proper string termination \033q\n";
    prompt   = "Enter 10 or less characters; the last character being '0'\n";
    mssg     = "\nEnd of input detected.\n\n";

/* . . . . . . . . . . . . . . . . . . .program expressions and statements */

    printf(title_1);
    printf(prompt);
    do {
       c = bdos(1,0); /* . . . . . . . . . . . . . . . . get the character */
       s[j] = c; /* . . . . . . . . . . . . . . put it at end of the array */
       j++; /*	. . . . . . . . . . . . .increment pointer to end of array */
    }  while((c != '0') & (j <= 10));

    printf(mssg);


     /*  . . . . . . . . . . . . . . . . . incorrect termination of string */

    printf(title_2);
    printf("%s\n",s);

     /*  . . . . . . . . . . . . . . . . . . correct termination of string */

    printf(title_3);
    s[--j] = '\0';
    printf("%s\n",s);

    exit(0);
}
it(0);
}
�F΍v���F̸ �F�� P�v��4� ^�� ^�