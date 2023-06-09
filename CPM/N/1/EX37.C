/****************************************************************************
 Copyright (c) 1984				       Eigenware Technologies
								       (CI86)
			   pointers to strutures

NOTE #1: For concept see page 121, chapter 6.2, K & R.

NOTE #2: Notation `time->' and `(*time).' are equivalent.

*****************************************************************************/

main()
{
   struct clock
      {
	 char noon;
	 int hour;
	 int min;
	 int sec;
      }

/* . . . . . . . .  declare time as a pointer to the stucture of type clock */

   struct clock *time;

/* . . . . . . . . . . . .  assign values to the members of structure clock */

   time->noon = 'A';
   time->hour = 10;
   time->min = 30;
   time->sec = 59;

/* . . . . . . . . . . . . . . . . . . .display values inside the strucutre */

   printf("\n\tThe time is %d:%d:%d %c.M.", time->hour, (*time).min,
						     time->sec, (*time).noon);

   exit(0);
}









                                    