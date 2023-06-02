10 '	CLEARSET.BAS (C) Copyright 1985 by Merlin R. Null
20 CRLF$=CHR$(13)+CHR$(10):BL$=CHR$(7)
30 DEFINT A-Z
40 PRINT STRING$(10,10)
50 PRINT TAB(11)"ClearSet	Version 1.00	1-6-85"
60 PRINT
70 PRINT"Set clear screen sequence for a number of MBASIC and compiled"
80 PRINT"MBASIC programs.
90 PRINT STRING$(5,10)
100 PRINT"1. ADM-3A, Televideo 912	(Kaypro, Osborne)"
110 PRINT"2. ADM-31, Televideo 950"
120 PRINT"3. Hazeltine 1500"
130 PRINT"4. STM Pied Piper		(Combination of Hazeltine 1500 and ";
    "ADM-3A)"
140 PRINT"5. DEC VT52			(Telcon Zorba)"
150 PRINT"6. Custom installation"
160 PRINT"7. I don't know. Use scrolling."
170 PRINT"8. Exit without changing TERM.DAT"
180 PRINT:PRINT
190 INPUT"Type of terminal (1-7)";TYPE
200 IF TYPE <1 OR TYPE >8 OR TYPE<>INT(TYPE) THEN 40
210 ON TYPE GOSUB 270,290,310,330,350,370,580,260
220 OPEN "O",#1,"CLS.DAT"
230 PRINT #1,PRN$
240 CLOSE
250 PRINT:PRINT:PRINT"CLS.DAT Written."
260 END
270 PRN$="26"
280 RETURN
290 PRN$="27"+CRLF$+"42"
300 RETURN
310 PRN$="126"+CRLF$+"28"
320 RETURN
330 PRN$="126"+CRLF$+"28"+CRLF$+"26"
340 RETURN
350 PRN$="27"+CRLF$+"69"
360 RETURN
370 PRINT STRING$(17,10)
380 PRINT"Enter your clear screen sequence in ASCII decimal numbers."
390 PRINT"Enter <return> to end sequence."
400 PRINT
410 PRINT"Example: for ^Z enter 26"
420 PRINT
430 FOR I=1 TO 24
440   PRINT"Clear screen sequence character number";I;"? ";
450   LINE INPUT;A$
460   IF I=1 AND A$="" THEN 260
470   IF I>1 AND A$="" THEN 570
480   FOR BYTE=1 TO LEN(A$)
490     IF ASC(MID$(A$,BYTE,1))<48 OR ASC(MID$(A$,BYTE,1))>57 THEN PRINT ELSE
        520
500     PRINT BL$;"   ** Whole decimal numbers only **";BL$
510     GOTO 440
520   NEXT BYTE
530   IF VAL(A$)>127 THEN PRINT BL$;"  ** Number is out of ASCII range **";
      BL$:GOTO 440
540   IF I>1 THEN PRN$=PRN$+CRLF$
550   PRN$=PRN$+A$
560 NEXT I
570 RETURN
580 PRINT STRING$(12,10)
590 INPUT"How many blank lines do you want for scrolling";SCROLL
600 IF SCROLL>24 THEN SCROLL=24
610 IF SCROLL<1 THEN SCROLL=1
620 FOR BLANK=1 TO SCROLL
630   IF BLANK>1 THEN PRN$=PRN$+CRLF$
640   PRN$=PRN$+"10"
650 NEXT BLANK
660 RETURN
