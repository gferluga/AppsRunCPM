/***********************************************************************
 Copyright (c) 1984				  Eigenware Technologies

	       bell.c - print a message using puts
		 & ring the bell using putchar()

For concept, chapter 1.5 and 2.3 of K&R.

************************************************************************/

main()
{
  puts("THE JOY OF C");
  puts("THE JOY OF C");     /* . . . . . . . . puts appends a newline */
  puts("THE JOY OF C");
  puts("THE JOY OF C");

  putchar("\n");

  printf("THE JOY OF C; "); /* . . . printf does not append a newline */
  printf("THE JOY OF C; ");
  printf("THE JOY OF C; ");

  putchar('\007');

}
