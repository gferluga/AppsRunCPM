/**************************************************************************
 Copyright (c) 1984				     Eigenware Technologies
			       structures			     (CI86)

    NOTE 1: Structures are for dealing with a collection of things, that
	    are all related, however, they may have different attributes.

    NOTE 2: For concept refer to page 119, K & R.

***************************************************************************/

main()
{

/* . . . . . . . . . . . . . . . . . .	define the structure called clock */
/* . . . . .  clock is the tag by which this structure will be referenced */

   struct clock
      {
	 char noon;
	 int hour;
	 int min;
	 int sec;
      };

/* . . . . . . . . . . .  define variable time to be of type struct clock */

   struct clock time;

/* . . . . . . . . . . . .  assign values to the members of variable time */

   time.noon = 'A';
   time.hour = 10;
   time.min = 30;
   time.sec = 59;

/* . . . . . . . . . . . . . . . . .  display values inside the structure */

   printf("The time is %d:%d:%d %c.M.", time.hour, time.min,
			time.sec, time.noon);

   EXIT(0);
}
è?ÿY[SQ
ítC&ŠþÍQSèüþ[YëíS 
Àt*¢è	ÿþu÷ë˜C&ˆþÅQSŠÈèÑþ[Y&Š<ŠÅu<uŒØŽÀémþ:Ásé,ÿ[&ˆ/±ŒØŽÀébþèþëDèÎ
ë?ŠÁþÀt	þct clock */

   struct clock time;

/* . . . . . . . . . . . .  assign values to the members of variable time */

   time.noon = 'A';
   time.hour = 10;
   time.min = 30;
   time.sec = 59;

/* . . . . . . . . . . . . . . . . .  display values in53 37 10 32 37 100 32 100 97 116 97 95 112 97 99 107 32 119 114 105 116 116 101 110 32 116 111 32 112 97 99 107 101 100 46 100 97 116 0
153 11 112 97 99 107 101 100 46 100 97 116 0
153 3 114 98 0
153 40 10 13 32 101 114 114 111 114 32 111 110 32 111 112 101 110 105 110 103 32 112 97 99 107 101 100 46 100 97 116 32 116 111 32 114 101 97 100 36 0
153 38 10 32 32 98 101 102 111 114 101 32 114 101 97 100 44 32 112 97 99 107 101 100 95 100 97 116 97 50 46 120 32 61 32 32 37 100 32 0
153 38 10 32 32 98 101 1