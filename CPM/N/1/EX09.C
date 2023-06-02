/***************************************************************************
 Copyright (c) 1984				      Eigenware Technologies

			    STRING CONSTANTS

NOTE #1:  Is a register variable faster than an auto variable.	Use a stop
	  watch  to time  this program.    Record the time  from the first
	  "START TIME"	meassage  to the "STOP TIME" message.

NOTE #2:  BUG: The printf(mssg) statement makes the test I/O bound.
	       Replace this statement with another that uses the
	       register variable.

NOTE #3:  See pp 99-100 of K&R for assigning a pointer to string of
	  characters.

NOTE #4:  You may wish to repeat this test for static variables.  Another
	  test could be bdos 9 versus printf.

****************************************************************************/

#define CLS   bdos(9,"\033E$")
#define BEL   bdos(2,'\007')
#define INKEY bdos(1,0)
#define BIG   1000

main()
{
   int i;	     /* . . . . . . . . . . . . .index using auto variable */
   register int j;   /* . . . . . . . . . . .index using register variable */
   char *mssg;	     /* . . . . . . . . . . declare pointers to characters */
   char *ready;

/*    The next two statements assign pointers to strings of characters	  */

   mssg = "Please be patient, a stop message will appear on clear screen\n";
   ready = "Press any key when ready\n";

   printf(ready);
   INKEY;
   BEL;
   CLS;
   printf("\t\t\033p START TIME FOR AUTO \033q\n\n");
   for (i = 0; i < BIG; i++) printf(mssg);  /* . . . . . . . I/O bound */
   BEL;
   CLS;
   printf("\t\t\033p STOP TIME FOR AUTO \033q\n\n");

   printf(ready);
   INKEY;
   BEL;
   CLS;
   printf("\t\t\033p START TIME FOR REGISTER \033q\n\n");
   for (j = 0; j < 1000; j++) printf(mssg);	/* . . . . . I/O bound */
   BEL;
   CLS;
   printf("\t\t\033p STOP TIME FOR REGISTER \033q\n\n");
   exit(0);
}
 exit(0);
}
ÿÿÿÿÿÿÿÿ