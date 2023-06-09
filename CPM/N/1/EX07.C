/**************************************************************************
 Copyright (c) 1984				     Eigenware Technologies

		 if and if-else constructions, exit(),

   NOTE #1: When there are no arguments, use bdos 9 rather than printf.
	    Be careful, bdos 9 may not left justify.

   NOTE #2: The exit() can be placed anywhere in the program.
	    If an exit() is ecncountered the program will terminate,
	    otherwise, it will stop when it runs off the end of main().

   NOTE #3: The goto is for lazy programmers and us old FORTRANERS.

***************************************************************************/

#define YES 1	  /* . . . . . . . . . .Symbolic constants can be defined */
#define NO  0

main()
{
    static char answer = 1;

    demo:

    bdos(9,"\n\033p DEMONSTRATE if-else \033q$");

    if (YES) printf("\n\nYES: This sentence will be printed.\n");
    if (NO) printf(" Eh! \n");
    if (answer == YES) printf("YES: This second sentence will be printed\n");

    bdos(9,"\n\n\n$");

    printf("Do you wish to continue (Y or N)? ");
    answer = bdos(1,0);
    if (answer == 'Y' || answer == 'y') answer = YES;
    else answer = NO;

/* If an exit(0) is encountered the program will terminated,
   otherwise it will stop when it runs off the end of main. */

    if (answer != YES) exit(0);
    else printf("\n\nYES: \033p DEMONSTRATE THE GOTO STATEMENT \033q\n");
    goto demo;

}
 demo;

}
n#2\n");

}

�F��F �C ��� c s d D x X u U o O b B f e