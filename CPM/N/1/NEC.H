/*****************************************************************************
 Copyright (c) 1984					Eigenware Technologies
			       console.h

	       Preprocessor definitions for NEC APC console

******************************************************************************/

#define bell		 bdos(2,'\007')
#define home		 bdos(2,'\036')       /* Home Cursor		    */
#define cursor_left	 bdos(2,'\010')   
#define cursor_down	 bdos(2,'\012')   
#define cursor_up	 bdos(2,'\013')   
#define cursor_right	 bdos(2,'\014')   
#define cursor_return	 bdos(2,'\015')   /* Cursor Return to Left Margin   */
#define clear_screen	 bdos(2,'\032')   
#define cursor_on	 bdos(9,"\033[5>L$") 
#define cursor_off	 bdos(9,"\033[5>H$") 
#define cursor_up(y)	 bdos(9,"\033[yA$") 
#define cursor_down(y)	 bdos(9,"\033[yB$") 
#define cursor_right(x)  bdos(9,"\033[xC$")
#define cursor_left(x)	 bdos(9,"\033[xD$")
#define erase		 bdos(9,"\033[2J$")
#define erase_to_end	 bdos(9,"\033[0J$")   /* Erase to End of Screen    */
#define erase_to_cursor  bdos(9,"\033[1J$")   /* Erase from Home to Cursor */
#define erase_to_EOL	 bdos(9,"\033[0K$")    /* Erase to End of Line	   */
#define erase_from_SOL	 bdos(9,"\033[1K$")    /* Erase Beginning of Line  */
#define erase_line	 bdos(9,"\033[2K$")  
#define overbar 	 bdos(9,"\033[2m$")  
#define overline	 bdos(9,"\033[3m$")  
#define underline	 bdos(9,"\033[4m$")  
#define default_video	 bdos(9,"\033[1m$")  
#define black		 bdos(9,"\033[16m$")	
#define red		 bdos(9,"\033[17m$")	
#define reverse_red	 bdos(9,"\033[7;17m$")
#define blink_red	 bdos(9,"\033[5;17m$")
#define blue		 bdos(9,"\033[18m$")	
#define reverse_blue	 bdos(9,"\033[7;18m$")
#define magenta 	 bdos(9,"\033[19m$")	
#define reverse_magenta  bdos(9,"\033[7;19m$")
#define green		 bdos(9,"\033[20m$")	
#define reverse_green	 bdos(9,"\033[7;20m$")
#define yellow		 bdos(9,"\033[21m$")	
#define reverse_yellow	 bdos(9,"\033[7;21m$")
#define blink_yellow	 bdos(9,"\033[5;21m$")
#define cyan		 bdos(9,"\033[22m$")	
#define reverse_cyan	 bdos(9,"\033[7;22m$")
#define white		 bdos(9,"\033[23m$")	
#define reverse_white	 bdos(9,"\033[7;23m$")
#define blink_white	 bdos(9,"\033[5;23m$")
#define alt_char	 bdos(9,"\033(1$")  /* APC Alt Character Mode	   */
#define default_char	 bdos(9,"\033(0$")  /* APC Default Character Mode  */
#define status_off	 bdos(9,"\033[1>H$")  /* Status Line Off	   */
#define status_on	 bdos(9,"\033[1>L$")  /* Status Line On 	   */
#define click_off	 bdos(9,"\033[2>H$")	/* Key Click Off	   */
#define click_on	 bdos(9,"\033[2>L$")	/* Key Click On 	   */
#define kbd_off 	 bdos(9,"\033[7>H$")	/* Keyboard Off 	   */
#define kbd_on		 bdos(9,"\033[7>L$")	/* Keyboard On		   */
#define cyan_exit(x) cyan;home;erase;status_on;cursor_on;say(x);exit(0)

 
);exit(0)

 










<�u(���T�3��P��>� u����t�����v��Z�����"����S�����[u�����rg�"