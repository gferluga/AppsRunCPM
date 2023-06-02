/***********************************************************************
CLEAR25.C

Clears the 25th line of the Heath/Zenity 89 & 100

************************************************************************/

#include "heath.h"
#include "curpos.c"

main()
{
	register int i;

	CURSOFF;
	SCP;
	ENABLE25;
	curpos(25,1);
	EOL;
	RCP;
	exit(CURSON);
}
