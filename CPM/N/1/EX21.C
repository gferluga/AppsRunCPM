/*********************************************************************
 Copyright (c) 1984				Eigenware Technologies

		  pointers, Lvalules, and Rvalules

**********************************************************************/

#include "stdio.h" /* . . . . . . . . . . . . . required for putchar */

#define CLS bdos(9,"\033E$")
#define BELL putchar('\07')

main(argc,argv)
int argc;
char **argv;
{
  int number, *pointer;

  if( argc!=2 ) {
    printf("Usage: ex18 number\nwhere 0 < number < 32000\n\n");
    exit(BELL);
  }

  number = atoi(argv[1]);
  pointer = &number;
  CLS;
  printf("	 pointer	     number\n");
  printf("\033F 	 `     `	     `	  |\033G\n");
  printf("\033F 	 `     `	     `	  |\033G\n");
  printf("   Lvalue   Rvalue	 Lvalue  Rvalue\n");
  printf("\033F 	 `     `	     `	  |\033G\n");
  printf("\033F 	 `     `	     `	  |\033G\n");
  printf("     %u   %u	%u   %d\n",&pointer,pointer,&number,number);
  printf("\033F 	       `	     `\033G\n");
  printf("\033F 	       eaaaaaaaaaaaaad\033G\n");
  printf("	      *pointer = %d",*pointer);
  printf("\n\n\033pPOINTER\033q:");
  printf("\n\nLvalue of pointer = address of pointer\n");
  printf("Rvalue of pointer = address of number");
  printf(" and value of the pointer\n");
  printf("\n\n\033pNUMBER\033q:");
  printf("\n\nLvalue of the number = address of number\n");
  printf("Rvalue of number = value of number\n");
  exit();
}
);
}
� �Fܸ �F�3��F��Z �F�Fܸ �F�3��F��F �C ��� c s d D x X u U o O b B f e