/*------------------------------------------------------------------------\
|									  |
|				 click.c				  |
|									  |
|    A function to turn-off and turn-on the key-click feature of the	  |
|    H/Z100 computer.							  |
|									  |
|    NOTE #1: Refer to page B-17 of your Z100 User's Manual.		  |
|									  |
|    NOTE #2: If k = NO (FALSE) the key click is turned off.		  |
|									  |
\------------------------------------------------------------------------*/

click(k)
int k;
{
if (k) bdos(9,"\033y2$"); else bdos(9,"\033x2$");

return(k);
}








 				  |
|									  |
\----------------