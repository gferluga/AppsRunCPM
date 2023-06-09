10 '	ENCODE.BAS Version 1.00 (c) Copyright 1985 by Merlin R. Null
20 '	To create pseudo compiled dBASE II .CMD files.
30 '	This program may not be sold seperately or as part of any collection"
40 '	of programs without the written permission of the author:
50 '	Merlin R. Null, P.O. Box 9422, N. Hollywood, CA 91609, (818)762-1429
60 DEFINT A-Z
70 DIM TOKEN$(67),WORDLEN(67)
80 ON ERROR GOTO 1850	'Used mostly to detect incorrect filename
90 WIDTH LPRINT 255
100 BL$=CHR$(7)
110 OPEN "I",#1,"CLS.DAT"
120 WHILE NOT EOF(1)
130   LINE INPUT #1, A$
140   A=VAL(A$)
150   CLS$=CLS$+CHR$(A)
160 WEND
170 CLOSE #1
180 FOR I=1 TO 67
190   READ TOKEN$(I),WORDLEN(I)
200 NEXT I
210 PRINT CLS$:PRINT
220 PRINT TAB(10)"ENCODE  -  Version 1.00     1-6-85"
230 PRINT STRING$(4,10)
240 PRINT"Option: 	N		No console display of input file"
250 PRINT
260 PRINT"Examples:	B:FOO.SRC N	No console display"
270 PRINT"		FOO.SRC		Output to file with console display"
280 PRINT"		A:		Displays directory of A:"
290 PRINT"		?		Read the Help file"
300 PRINT"		<RET>		Redisplays this screen"
310 PRINT STRING$(4,10)
320 PRINT
330 LINE INPUT"Filename.SRC or Drive:? ";NF$
340 NFLEN=0:CONOFF=0:OPTFLAG=0:FULLNAME$=""
350 IF NF$="" THEN 210			'Redisplay start screen
360 IF NF$="?" THEN OPEN "I",#1,"ENCODE.HLP" ELSE 490
370   PRINT CLS$
380   FOR LINES=1 TO 20
390     IF EOF(1) THEN 440 ELSE LINE INPUT #1,HELP$
400     PRINT HELP$
410   NEXT LINES
420   PRINT
430   PRINT TAB(7)"<Press any key to continue reading help file>"
440   PRINT TAB(12)"Press <ESC> to return to DB-Fast ";
450   FINISHED$=INPUT$(1)
460   IF FINISHED$<>CHR$(27) THEN 370
470   CLOSE #1
480   GOTO 210
490 FOR I=1 TO LEN(NF$)		'Convert lower to upper case & detect options
500   BYTE$=MID$(NF$,I,1)
510   IF ASC(BYTE$)>96 AND ASC(BYTE$)<123 THEN BYTE$=CHR$(ASC(BYTE$)-32)
520   FULLNAME$=FULLNAME$+BYTE$
530   IF BYTE$=" " THEN OPTFLAG=-1		'Flag start of options
540   IF NOT OPTFLAG THEN 560
550   IF BYTE$="N" THEN CONOFF=-1		'Detect console off
560   IF NFLEN THEN 580
570   IF BYTE$="." THEN NFLEN=I+3		'Find filename length
580 NEXT I
590 IF NFLEN>3 THEN FULLNAME$=LEFT$(FULLNAME$,NFLEN)'Drop option from filename
600 IF MID$(FULLNAME$,2,1)=";" THEN MID$(FULLNAME$,2,1)=":" 'ZCPR like (A;)
610 IF LEN(FULLNAME$)=2 AND MID$(FULLNAME$,2,1)=":" THEN PRINT CLS$ ELSE 660
620   DIR$=FULLNAME$+"*.*"
630   PRINT"Directory of drive ";FULLNAME$
640   FILES DIR$
650   GOTO 320
660 IF RIGHT$(FULLNAME$,3)<>"SRC" THEN PRINT CLS$;STRING$(5,10) ELSE 690
670   PRINT BL$;FULLNAME$;" must have the extension .SRC - try again."
680   GOTO 320
690 FILENAME$=LEFT$(FULLNAME$,NFLEN-3)
700 TMPNAME$=FILENAME$+"TMP"
710 CMDNAME$=FILENAME$+"CMD"
720 OLDNAME$=FILENAME$+"OLD"
730 OPEN "I",#1,CMDNAME$	'See if <filename>.CMD exists
740 CLOSE #1			'Close, if found. Else error trap gets it
750 PRINT CLS$;STRING$(7,10);BL$
760 PRINT TAB(20)"[]=========[]"
770 PRINT TAB(20)"[] WARNING []"
780 PRINT TAB(20)"[]=========[]"
790 PRINT:PRINT
800 PRINT CMDNAME$;" already exists!  If you ansewer NO, the old ";CMDNAME$
810 PRINT"will be renamed to ";OLDNAME$
820 PRINT:PRINT
830 PRINT"Do you wish to overwrite ";CMDNAME$;" (Yes/No/Quit)";
840 INPUT OVERWRITE$
850 IF LEFT$(OVERWRITE$,1)="Y" OR LEFT$(OVERWRITE$,1)="y" THEN 920
860 IF LEFT$(OVERWRITE$,1)="Q" OR LEFT$(OVERWRITE$,1)="q" THEN 1510
870 IF LEFT$(OVERWRITE$,1)<>"N" AND LEFT$(OVERWRITE$,1)<>"n" THEN 750
880 RENAMECMD=-1
890 OPEN "I",#2,OLDNAME$	'See if <filename>.OLD exists.
900 CLOSE #2			'Close, if found. Else error trap gets it
910 ERASEOLD=-1			'Flag to kill <filename>.OLD
920 OPEN "I",#3,FULLNAME$
930 OPEN "O",#1,TMPNAME$
940 IF CONOFF THEN PRINT:PRINT"	<No console output>" ELSE PRINT CLS$
950 PRINT
960 PRINT"    ^S to Pause  -  ^C to Abort"
970 PRINT
980 WHILE NOT EOF(3)
990   LINES=LINES+1
1000   LINE INPUT #3,TEXT$
1010   TEMP$=TEXT$:START=0:BLANK=0
1020   TEXTLEN=LEN(TEXT$)
1030   FOR CHAR=1 TO TEXTLEN
1040     IF CHAR-BLANK>8 THEN CHAR=TEXTLEN
1050     CHARVAL=ASC(MID$(TEMP$,CHAR,1))
1060     IF START THEN 1090
1070     IF CHARVAL=32 OR CHARVAL=9 THEN BLANK=BLANK+1 ELSE START=CHAR
1080     IF CHARVAL<123 AND CHARVAL>96 THEN MID$(TEMP$,CHAR,1)=CHR$(CHARVAL-32)
1090   NEXT CHAR
1100   IF TEXT=1 THEN PRN$=TEXT$ ELSE 1130
1110   IF MID$(TEMP$,1+BLANK,4)="ENDT" THEN TEXT=0
1120   GOTO 1380
1130   IF MID$(TEXT$,1+BLANK,1)="*" THEN 1400
1140   IF MID$(TEXT$,1+BLANK,1)="&" THEN PRN$=TEXT$:GOTO 1380
1150   PRN$="":FOUND=0
1160   IF MID$(TEMP$,1+BLANK,4)="GOTO" THEN PRN$=PRN$+CHR$(160) ELSE 1190
1170     LENGTH=4
1180     GOTO 1310
1190   IF MID$(TEMP$,1+BLANK,8)="DO WHILE" THEN PRN$=PRN$+CHR$(136) ELSE 1220
1200     LENGTH=8
1210     GOTO 1310
1220   IF MID$(TEMP$,1+BLANK,7)="DO CASE" THEN PRN$=PRN$+CHR$(137) ELSE 1250
1230     LENGTH=7
1240     GOTO 1310
1250   FOR TOKEN=1 TO 67
1260     IF MID$(TEMP$,1+BLANK,WORDLEN(TOKEN))=TOKEN$(TOKEN) THEN
         PRN$=PRN$+CHR$(TOKEN+127):LENGTH=WORDLEN(TOKEN):FOUND=TOKEN:TOKEN=67
1270   NEXT TOKEN
1280   IF FOUND=3 OR FOUND=5 OR FOUND=8 THEN 1380
1290   IF TEXT=0 AND FOUND=62 THEN TEXT=1
1300   IF FOUND<1 THEN 1560
1310   BEGIN=BLANK+LENGTH+1
1320   FOR BYTE=BEGIN TO TEXTLEN
1330     CHARVAL=ASC(MID$(TEXT$,BYTE,1))
1340     IF CHARVAL>128 THEN 1680
1350     IF BYTE=BEGIN AND CHARVAL=32 OR BYTE=BEGIN AND CHARVAL=9 THEN 1370
1360     PRN$=PRN$+CHR$(ASC(MID$(TEXT$,BYTE,1))XOR 255)
1370   NEXT BYTE
1380   IF NOT CONOFF THEN PRINT TEXT$
1390   PRINT #1, PRN$
1400   QUIT$=INKEY$:IF QUIT$<>"" THEN GOSUB 1800
1410 WEND
1420 CLOSE
1430 PRINT
1440 IF ERASEOLD THEN KILL OLDNAME$ ELSE 1460
1450   PRINT"Erasing ";OLDNAME$
1460 IF RENAMECMD THEN NAME CMDNAME$ AS OLDNAME$ ELSE 1480
1470   PRINT"Changing ";CMDNAME$;" to ";OLDNAME$
1480 IF OVERWRITE$="Y" OR OVERWRITE$="y" THEN KILL CMDNAME$ ELSE 1500
1490   PRINT"Erasing ";CMDNAME$
1500 NAME TMPNAME$ AS CMDNAME$:PRINT"Changing ";TMPNAME$;" to ";CMDNAME$
1510 PRINT
1520 INPUT"Are you finished";ANS$
1530 IF LEFT$(ANS$,1)<>"Y" AND LEFT$(ANS$,1)<>"y" THEN CLEAR:GOTO 60
1540 END
1550 CLOSE
1560 PRINT BL$
1570 PRINT"[]==============[] This file contains incorrect syntax for a";BL$
1580 PRINT"[]   ABORTING   [] dBASE II .CMD file.  All lines not between"
1590 PRINT"[]==============[] TEXT and ENDTEXT must begin with a reserved"
1600 PRINT"                   word , '*' (remark) or '&' (macro character)
1610 PRINT
1620 PRINT"The error was found on line";LINES;"of ";FULLNAME$;", it reads:"
1630 PRINT
1640 PRINT "'";TEXT$;"'"
1650 PRINT
1660 KILL TMPNAME$
1670 GOTO 1540
1680 CLOSE
1690 PRINT BL$
1700 PRINT"****ABORTING**** This file contains characters with the 8th bit set!"
1710 PRINT BL$
1720 PRINT"The error was in line";LINES;"of ";FULLNAME$;", it reads:"
1730 PRINT
1740 PRINT"'";TEXT$;"'"
1750 KILL TMPNAME$
1760 PRINT
1770 GOTO 1540
1780 '	The ^C and ^S handling only works with BASCOM, not the interpreter.
1790 PRINT
1800 IF QUIT$=CHR$(3) THEN CLOSE ELSE 1830
1810   PRINT BL$;"****ABORTING**** ^C entered from keyboard.  No files changed"
1820   GOTO 1540
1830 IF QUIT$=CHR$(19) THEN WHILE INKEY$="":WEND
1840 RETURN
1850 IF ERR=53 AND ERL=920 THEN CLOSE #3 ELSE 1890
1860   PRINT CLS$;STRING$(5,10)
1870   PRINT CHR$(34);FULLNAME$;CHR$(34);" not found - try again.";BL$
1880   RESUME 320
1890 IF ERR=53 AND ERL=730 THEN CLOSE #1:RESUME 920
1900 IF ERR=53 AND ERL=890 THEN CLOSE #2:RESUME 920
1910 IF ERR=53 AND ERL=110 THEN CLOSE #1 ELSE 1960
1920   PRINT STRING$(10,10)
1930   PRINT BL$;"CLS.DAT not found.  Please run CLEARSET to generate it.";BL$
1940   PRINT STRING$(10,10)
1950   RESUME 1540
1960 IF ERR=53 AND ERL=360 THEN PRINT CLS$;STRING$(5,10); ELSE 1990
1970   PRINT BL$;"The Help file, ENCODE.HLP, is not on this disk!";BL$
1980   RESUME 320
1990 IF ERR=64 AND ERL=730 THEN CLOSE ELSE 2030
2000   PRINT CLS$;STRING$(5,10)
2010   PRINT BL$;CHR$(34);FULLNAME$;CHR$(34);" is a bad file name - try again."
2020   RESUME 320
2030 ON ERROR GOTO 0
2040 DATA "IF",2,"ELSE",4,"ENDIF",5,"DO",2,"ENDDO",5,"CASE",4,"OTHERWISE",9
2050 DATA "ENDCASE",7,"DO WHILE",8,"DO CASE",7,"STORE",5,"?",1,"RELEASE",7
2060 DATA "RETURN",6,"SELECT",6,"@",1,"ACCEPT",6,"APPEND",6,"BROWSE",6,"CALL",4
2070 DATA "CANCEL",6,"CHANGE",6,"CLEAR",5,"COPY",4,"COUNT",5,"CREATE",6
2080 DATA "DELETE",6,"DISPLAY",7,"CONTINUE",8,"EDIT",4,"EJECT",5,"ERASE",5
2090 DATA "GO",2,"FIND",4,"HELP",4,"INDEX",5,"INPUT",5,"INSERT",6,"JOIN",4
2100 DATA "LIST",4,"LOAD",4,"LOCATE",6,"LOOP",4,"MODIFY",6,"PACK",4,"POKE",4
2110 DATA "QUIT",4,"READ",4,"RECALL",6,"REINDEX",7,"REMARK",6,"RENAME",6
2120 DATA "REPLACE",7,"REPORT",6,"RESET",5,"RESTORE",7,"SAVE",4,"SET",3
2130 DATA "SKIP",4,"SORT",4,"SUM",3,"TEXT",4,"TOTAL",5,"UNLOCK",6,"UPDATE",6
2140 DATA "USE",3,"WAIT",4
