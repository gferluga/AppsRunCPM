/************************************************************************
WMA		1-31-85
     heath.h - a preprocessor for Heath/Zenith H/Z-89 & H/Z-100

*************************************************************************/

#define BELL		putchar('\07')		/* Ring Bell		*/

/*			Cursor Movement		*/
#define CUL	printf("\033D")  	/* Move Cursor Left 	*/
#define CUR	printf("\033C")  	/* Move Cursor RIGHT	*/
#define CUP	printf("\033A")  	/* Move Curosr Up	*/
#define CUD	printf("\033B")  	/* Move Cursor Down 	*/
#define CUH	printf("\033H")  	/* Cursor Home		*/
#define CRI	printf("\033I")		/* Reverse Index 	*/

/*			Cursor Position Control		*/
#define CPSAVE		printf("\033j")  	/* Save Cursor Position	*/
#define CPREST		printf("\033k")  	/* Reset Cursor postion	*/

/*			Cursor Display		*/
#define CBLOCKN		printf("\033x4\033x;") 	/* Block Cursor - no blink */
#define CBLOCKB		printf("\033x4\033y;")	/* Block Cursor - blinking */
#define CUNDERN		printf("\033y4\033x;")	/* Underline - no blink	*/
#define CUNDERB		printf("\033y4\033y;")	/* Underline - blink	*/
#define CON		printf("\033y5") 	/* Turn Cursor on	*/
#define COFF		printf("\033x5") 	/* Turn Cursor off	*/

/*			Delete Functions	*/
/*	These functions delete the character (or line) that the		*/
/*	cursor is on and shift the characters left (or move lines	*/
/*	up and add a blank line on line 24).				*/
#define DCHAR	printf("\033N")		/* Delete Character	*/
#define DLINE	printf("\033M")		/* Delete Line		*/

/*			Erase Functions		*/
/*	These functions (except CLS) leave the cursor position alone	*/
#define CLS		printf("\033E")  /* Clear screen/home cursor 	*/
#define ERALINE		printf("\033l")  /* Erase Entire Line		*/
#define ERABOD		printf("\033b")  /* Erase Beginning of Display	*/
#define ERAEOD		printf("\033J")  /* Erase to End of Display	*/
#define ERABOL		printf("\033o")  /* Erase to Beginning of Line	*/
#define ERAEOL		printf("\033K")  /* Erase to End of Line	*/

/*			Insert Functions	*/
#define ICHAR		printf("\033@")	/* Insert Character Mode on	*/
#define ICHARX		printf("\033@")	/* Insert Character Mode off	*/
#define ILINE		printf("\033L)	/* Insert Line			*/

/*			Graphics Mode		*/
#define GMODE		printf("\033F")  	/* Enter Graphics Mode	*/
#define GMODEX		printf("\033G")  	/* Exit Graphics Mode	*/

/*			Keyboard Control	*/
#define KEYBX		printf("\033}")		/* Disable keyboard	*/
#define	KEYB		printf("\033{")		/* Enable keyboard	*/
#define CLICK		printf("\033y2")	/* Keyclick on (default)*/
#define CLICKX		printf("\033x2")  	/* Keyclick off	*/
#define EXPAN		printf("\033x?")	/* Key expansion on (default)*/
#define EXPANX		printf("\033y?")  	/* Key expansion off */
#define EVENT		printf("\033x@")	/* Event driven on (default)*/
#define EVENTX		printf("\033y@")  	/* Event driven off */
#define AUTOR		printf("\033x<")	/* Auto Repeat on (default)*/
#define AUTORX		printf("\033y<")  	/* Auto Repeat off */

/*			Keypad Control		*/
#define PADSFT		printf("\033x6")	/* Enter Keypad Shift 	*/
#define PADSFTX		printf("\033y6")	/* Exit Keypad Shift 	*/
#define PADALT		printf("\033x7") /* Enter Keypad Alternate Mode	*/
#define PADALTX		printf("\033y7") /* Exit Keypad Alternate Mode	*/
#define KEYSFT		printf("\033t")	/* Enter Keypad Shift 	*/
#define KEYSFTX		printf("\033u")	/* Exit Keypad Shift 	*/
#define KEYALT		printf("\033=")	/* Enter Keypad Alternate Mode	*/
#define KEYALTX		printf("\033>")	/* Exit Keypad Alternate Mode	*/

/*			Reset to Power Up 	*/
#define RESETIT		printf("\033z")		/* Reset to power up */

/*			Reverse Video Mode	*/
#define RVID		printf("\033p")  	/* Enter Reverse Video	*/
#define RVIDX		printf("\033q")  	/* Exit Reverse Video	*/

/*			Miscellaneous Screen control	*/
#define ALFCR		printf("\033x8")	/* Auto LF w/CR	*/
#define ACRLF		printf("\033x9")	/* Auto CR w/LF */
#define ALFCRX		printf("\033y8")	/* No auto LF w/CR */
#define ACRLFX		printf("\033y9")	/* No Auto CR w/LF */
#define HOLDCRT		printf("\033x3")	/* Enter hold screen	*/
#define HOLDCRTX	printf("\033y3")	/* Exit hold screen	*/

/*			25th line functions	*/
/*	Cursor position is saved on ENABLE_25	*/
/*	Cursor is returned to original position (saved by ENABLE_25)	*/
#define ENABLE25	printf("\033j\033x1")	/* Enable the 25th line	*/
#define DISABL25	printf("\033y1\033k")	/* Disable 25th line	*/
 
/*			Miscellaneous		*/
#define INKEY	  printf(1,0)	    /* CP/M Function Call #1		*/
#define PRINT(X)  printf("X")	    /* CP/M Function Call #9		*/
#define YES	  1		    /* TRUE				*/
#define NO	  0		    /* FALSE				*/
#define AEOF	  0x1A		    /* ASII EOF for CP/M compatibility	*/
#define MAXLEN	  80			/* Length of screen line	*/
/*#define void	  int		    void not supported		*/
