/* DECODE.C by Ross Presser
   Decrypts a psuedo-compiled dBASE II .CMD file.
   The decrypted command file will be pretty printed as follows:

IF A=B
   statement
ELSE
   statement
ENDIF
DO WHILE A=B
   statement
ENDDO
DO cmdfile
DO CASE
   CASE A=B
      statement
   CASE C=D
      statement
   CASE e=F
      statement
   OTHERWISE
      statement
ENDCASE

all indentations are three spaces; all verbs are in capitals

--------------

   Usage: DECODE <infile.cmd >outfile.CMD

--------------
   Construction with BDS C:

   cc decode
   l2 decode dio

*/


#include <bdscio.h>
#include <dio.h>

#define NCMDS 0x42		/* Number of dBASE command verbs */

char *cmds[NCMDS];		/* table of command verbs */
int c,indent,i;

main(argc,argv) int argc; char *argv[];
{
/* Initialize dio (i/o redirection) and the table of cmd verb strings */
	dioinit(&argc,argv);
	cmdinit(); indent=0;

/* main processing loop
   If the first char is > 128, decrypt the line, otherwise echo it
*/
	while((c=getchar())!=EOF && c!=26) {


/* if < 128, don't attempt to decrypt */
		if (c<0x80) {
			putchar(c);
		} else {

/* This switch stmt & the following one cause the file to be pretty-printed */
			switch (c-0x80) {
				case 7: indent -= 3;
				case 1: case 2: case 4: 
				 case 5: case 6: indent -= 3;
				}
			for(i=indent;i--;putchar(' ')) ;
			switch(c-0x80) {
				case 9: indent +=3;
				case 0: case 1: case 3: case 5: 
				case 6: case 8: case 9: indent += 3;
	 			}

/* print the cmd verb */
			puts(cmds[c-0x80]);
			putchar(' ');

			}
/* decrypt (or just print out) the rest of the line */
		while((c=getchar())!='\n')
			putchar(c>127 ? 255-c : c);
		putchar('\n');
		}

/* flush output files before exiting */
	dioflush();
}


/* This command table was discovered by tracing dBASE as it executed
   an encoded file.  The indices (0 thru 0x42) point into a jump table
   which is located in DBASEOVR.COM.  When the interpreter discovers a
   line beginning with a char > 128, it subtracts 128 and points into
   this jump table. */

cmdinit()
{
cmds[0x00]="IF";	cmds[0x01]="ELSE";	cmds[0x02]="ENDIF";
cmds[0x03]="DO";	cmds[0x04]="ENDDO";	cmds[0x05]="CASE";
cmds[0x06]="OTHERWISE";	cmds[0x07]="ENDCASE";	cmds[0x08]="DO WHILE";
cmds[0x09]="DO CASE";	cmds[0x0a]="STORE";	cmds[0x0b]="?";
cmds[0x0c]="RELEASE";	cmds[0x0d]="RETURN";	cmds[0x0e]="SELECT";	
cmds[0x0f]="@";		cmds[0x10]="ACCEPT";	cmds[0x11]="APPEND";
cmds[0x12]="BROWSE";	cmds[0x13]="CALL";	cmds[0x14]="CANCEL";
cmds[0x15]="CHANGE";	cmds[0x16]="CLEAR";	cmds[0x17]="COPY";
cmds[0x18]="COUNT";	cmds[0x19]="CREATE";	cmds[0x1a]="DELETE";
cmds[0x1b]="DISPLAY";	cmds[0x1c]="CONTINUE";	cmds[0x1d]="EDIT";
cmds[0x1e]="EJECT";	cmds[0x1f]="ERASE";	cmds[0x20]="GO";
cmds[0x21]="FIND";	cmds[0x22]="HELP";	cmds[0x23]="INDEX";
cmds[0x24]="INPUT";	cmds[0x25]="INSERT";	cmds[0x26]="JOIN";
cmds[0x27]="LIST";	cmds[0x28]="LOAD";	cmds[0x29]="LOCATE";
cmds[0x2a]="LOOP";	cmds[0x2b]="MODIFY";	cmds[0x2c]="PACK";
cmds[0x2d]="POKE";	cmds[0x2e]="QUIT";	cmds[0x2f]="READ";
cmds[0x30]="RECALL";	cmds[0x31]="REINDEX";	cmds[0x32]="REMARK";
cmds[0x33]="RENAME";	cmds[0x34]="REPLACE";	cmds[0x35]="REPORT";
cmds[0x36]="RESET";	cmds[0x37]="RESTORE";	cmds[0x38]="SAVE";
cmds[0x39]="SET";	cmds[0x3a]="SKIP";	cmds[0x3b]="SORT";
cmds[0x3c]="SUM";	cmds[0x3d]="TEXT";	cmds[0x3e]="TOTAL";
cmds[0x3f]="UNLOCK";	cmds[0x40]="UPDATE";	cmds[0x41]="USE";
cmds[0x42]="WAIT";
}
