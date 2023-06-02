/****************************************************************************
 Copyright (c) 1984				       Eigenware Technologies
				more.c

       A function for continuing or exiting to the operating systems

*****************************************************************************/

more(x)
int x;
{
   char answer;

   printf("\nDo you wish to CONTINUE (Y or N)? :");
   answer = bdos(1,0);
   if (answer == 'N' || answer == 'n') exit(0);
   printf("\n");
   return(0);
}





