/****************************************************************************
 Copyright (c) 1984				       Eigenware Technologies
								       (CI86)
			  Initializing strutures

NOTE #1: For concept see page 120, chapter 6.1, K & R.

NOTE #2: Automatic variables cannot be initialized.

*****************************************************************************/

struct clock
      {
	 char noon;
	 int hour;
	 int min;
	 int sec;
      };

main()

/* . . . . . . . . . . . . . . . . . . . declare variable, and assign values */

{

   static struct clock time = {'A', 11, 48, 59};

/* . . . . . . . . . . . . . . . . . . .display values inside the structure */

   printf("\n\tThe time is %d:%d:%d %c.M.", time.hour, time.min,
							 time.sec, time.noon);

   exit(0);
}
�$t��<u�<t2������à
�uQ���YQ��YQ�>� t��Y���<t�< s��ruct clock
      {
	 char noon;
	 int hour;
	 int min;
	 int sec;
      };

main()

/* . . . . . . . . . . . . . . . .