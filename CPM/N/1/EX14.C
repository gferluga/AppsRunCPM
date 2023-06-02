/****************************************************************************
 Copyright (c)	1984				       Eigenware Technologies

		 Examples of while, forever, scanf, and exit

NOTE: See pages 9, 147, and 154 for while, forever, scanf and exit.

*****************************************************************************/

/*#define puts printf comment out for Aztec */

main()
{
  int i;
  char *title;
  char *prompt;

  title = "\nExamples of 'while', 'forever', 'scanf', and 'exit'\n";
  prompt = "\n\nTo exit enter 0, else enter a single digit 1 through 9: ";

  puts(title);

  for (;;) {  /* . . . . . . . . . . . . . . . . . . . . . a forever loop */
    puts(prompt);
    scanf("%d", &i);  /* . . scanf arguements must be pointers, hence '&' */

    if( i == 0 )  exit(0);  /* . . . . . . . . . . . . . . . . early exit */
    else {
       while ( i != 0 ) {
	  printf("i = %d  ",i);
	  i--;
       } /* . . . . . . . . . . . . . . . . . . . . . . .  end of while   */
    } /* . . . . . . . . . . . . . . . . . . . . . . . . . end of else	  */
  } /* . . . . . . . . . . . . . . . . . . . . . . . . . . end of forever */
} /* . . . . . . . . . . . . . . . . . . . . . . . . . . . end of program */
