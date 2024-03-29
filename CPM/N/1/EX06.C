/************************************************************************
 Copyright (c) 1984				   Eigenware Technologies

		    Using BDOS functions #1 and #9

   NOTE #1: Same program as ex05.c with function #9 substituted for
	    printf() and function #2 for putchar().

   BUG: The last 'rrrrrr' in word 'character' does not print on console.
	It appears that only eight characters, maximum, per word are
	allowed.

   BUG FIX!! -- either compile with -i switch, e.g.  A:cc1 -i ex06,
		or break printf in two at the eigth character.
		Report to Computer Innovations for fix.

*************************************************************************/

#define begin {  /* . . . . . . . . . . . . . . . . . .just like PASCAL */
#define end   }
#define BELL bdos(2,'\07')  /* . . . . . . . .	all ZDOS function calls */
#define NL  bdos(2,'\n')
#define CLS bdos(9,"\033E$")
#define INKEY bdos(1,0)
#define PRINT(MSSG) bdos(9,"MSSG$")

main()
begin
   CLS;
   NL;
   PRINT(Typeeeeexxx any characterrrrrr to ring the bell: );
   INKEY;
   BELL;
   NL;
end
;
end
�t	X�P�v�tX��v�tX�u�� � P�v�tX5��^#�