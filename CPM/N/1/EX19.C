/*************************************************************************
 Copyright (c) 1984				    Eigenware Technologies
			 command line arguments

NOTE #1: Chapter 5.11, pages 110-114

NOTE #2: Enter lower case on command line, and CP/M will return upper case.

**************************************************************************/

main(argc,argv)
int argc;	/* . . . . . . . . . . . . declare arguments */
char **argv;
{
       int i;

/* . . . . . . . make sure proper amount of arguments are on command line */

       if (argc < 2) printf("\nUSAGE: ex16 arg_1 arg_2 . . . . . . arg_n\n");

/* . . . . . . . . . . . . . . . . . . . . . . output appropriate response */

       for (i = 1; i < argc;  i++) {
	    printf("argument %d is %s\n",i,argv[i]);
       }
       exit(0);
}
 exit(0);
}
��� �F� �F��9 � �F� �F��* � �F�
 �F�� � �F� �