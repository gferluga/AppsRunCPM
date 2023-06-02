/*************************************************************************

                Let's look at the Z/H-100 Video I/O port.

**************************************************************************/

#define P(F,X)  printf("X = %F", (X))

#include "getbits.c"

main()
{
   extern unsigned char inportb();
   unsigned int video_port;
   unsigned char byte;

   char *D7_1, *D6_1, *D5_1, *D4_1, *D3_1, *D2_1, *D1_1, *D0_1;
   char *D7_0, *D6_0, *D5_0, *D4_0, *D3_0, *D2_0, *D1_0, *D0_0;

/* . . . . . . . . . . . . . . . . . . . . . . . . . . . CPU ACCESS CONTROL */

D7_1 = "VRAM is turned off";
D7_0 = "VRAM is ENABLED";
D6_1 = "When data is written into any color, it is also written into BLUE.";
D6_0 = "Data can be written into BLUE, only if BLUE is accessed.";
D5_1 = "When data is written into any color, it is also written into GREEN.";
D5_0 = "Data can be written into GREEN, only if GREEN is accessed.";
D4_1 = "When data is written into any color, it is also written into RED.";
D4_0 = "Data can be written into RED, only if RED is accessed.";

/* . . . . . . . . . . . . . . . . . . . . . . . . . VIDEO DISPLAY CONTROL */

	     D3_1 = "Enabled planes will appear bright.";
	     D3_0 = "Data from VRAM are displayed.";
	     D2_1 = "Blue plane is turned off.";
	     D2_0 = "Blue plane is enabled.";
	     D1_1 = "Green plane is turned off.";
	     D1_0 = "Green plane is enabled.";
	     D0_1 = "Red plane is turned off.";
	     D0_0 = "Red plane is enabled.";

/* . . . . . . . . . . . . . . . . read the byte at Video 68A21 I/O port */

   video_port = 0xD8;
   byte = inportb(video_port);
   P(b\n\n,byte);

/* . . . . . . . . . . . . . . . . .translate Video Display Control Bits */

   if ( getbits(byte,7,1) == 1 ) printf("%s\n\n", D7_1);
   else printf("%s\n\n",D7_0);

   if ( getbits(byte,6,1) == 1 ) printf("%s\n\n", D6_1);
   else printf("%s\n\n",D6_0);

   if ( getbits(byte,5,1) == 1 ) printf("%s\n\n", D5_1);
   else printf("%s\n\n",D5_0);

   if ( getbits(byte,4,1) == 1 ) printf("%s\n\n", D4_1);
   else printf("%s\n\n",D4_0);

   if ( getbits(byte,3,1) == 1 ) printf("%s\n\n", D3_1);
   else printf("%s\n\n",D3_0);

   if ( getbits(byte,2,1) == 1 ) printf("%s\n\n", D2_1);
   else printf("%s\n\n",D2_0);

   if ( getbits(byte,1,1) == 1 ) printf("%s\n\n", D1_1);
   else printf("%s\n\n",D1_0);

   if ( getbits(byte,0,1) == 1 ) printf("%s\n\n", D0_1);
   else printf("%s\n\n",D0_0);

   exit(0);
}
;
   else printf("%s\n\n",D0_0);

   exit(0or previous line and start next line
   with line number and brace levels
*/
	 err_out(b_err);
	 printf("%d.%d.%d.%d:", ln, b[2], b[1], b[0]);
      }
      if (c == '[' || c == ']' || c == '(' || c == ')' ||
		c == '{' || c == '}') brc_ch(c, b, b_err);
   }
   fclose(fp);
   if (b[0] != 0) {
      printf("\n\nThere were %d mismatches for []-braces.\n", fabs(b[0]));
      if (b[0] > 0) printf("Missing right brace(s): \033p]\033q.\n");
      else printf("Missing left brace(s): \033p[\033q.\n");