/****************************************************************************

	  bell.c - ring bell facility using bdos function #2
		   &  print  message  using bdos function #9

Copyright (c) 1984	Eigenware Technologies

NOTE #1:  For usage of bdos calls see CP/M manuals.

NOTE #2: A $ is a delimiter for end of string in CP/M bdos function #9.

NOTE #3: 007 is ASCII character code for the BELL.

NOTE #4: 033p and 033q are the Heath/Zenith escape sequences to enter
	 reverse video and exit reverse video, respectively.

NOTE #5: This is a useful utility.  Rename it BELL, and use it to
	 terminate long batch jobs.

*****************************************************************************/

main()
{
   bdos(2,'\007');
   bdos(9,"\n\t\t\033pIF THERE WERE NO ERRORS YOUR PROGRAM SHOULD RUN\033q$");
}
q$");
}
 �
 P�v��^;�t� � P�v��tX^#��u� �v�� 