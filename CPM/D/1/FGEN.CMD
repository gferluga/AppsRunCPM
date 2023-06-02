CLEAR 
SET ESCAPE OFF
SET TALK OFF
STORE "Your Name" TO yourname
STORE ".CMD" TO extension
ERASE 
@ 2, 0 SAY "(VIEW, ADD, EDIT, & PACK)    G E N E R A T O R"
@ 2,72 SAY DATE()
@ 3, 0 SAY "========================================"
@ 3,40 SAY "========================================"
ACCEPT "Enter DATABASE filename " TO infile
STORE !( TRIM(infile) ) +"." TO infile
STORE $(infile,1,@(".",infile)-1) TO infile
DO CASE 
   CASE infile = " "
      ERASE 
      SET TALK ON
      SET ESCAPE ON
      CLEAR 
      RETURN 
   CASE .NOT. FILE(infile+".DBF")
      ? "*** FILE DOES NOT EXIST"
      SET TALK ON
      SET ESCAPE ON
      CLEAR 
      RETURN 
ENDCASE 
IF ":" $ infile
   STORE $(infile,3,2) TO filesystem
ELSE 
   STORE $(infile,1,2) TO filesystem
ENDIF 
ACCEPT "Enter INDEX filename " TO indexname
STORE !( TRIM(indexname) ) +"." TO indexname
STORE $(indexname,1,@(".",indexname)-1) TO indexname
IF indexname = " "
   ? "*** MUST ENTER AN INDEX FILENAME"
   CLEAR 
   SET TALK ON
   SET ESCAPE ON
   RETURN 
ENDIF 
ACCEPT "Enter index keyfield " TO keyfield
STORE !( TRIM(keyfield) ) TO keyfield
USE &infile
IF 0 = TEST(&keyfield)
   ? "*** INVALID KEY FIELD"
   CLEAR 
   SET TALK ON
   SET ESCAPE ON
   RETURN 
ENDIF 
STORE &keyfield TO keyvalue
@ 8,0 SAY " "
SET BELL OFF
IF .NOT. FILE(indexname+".NDX")
   STORE " " TO select
   @ $+1,0 SAY "INDEX FILE DOES NOT EXIST.   Create it? (Y/N) "           GET select PICTURE "!"
   READ NOUPDATE
   @ $+1,0 SAY " "
   IF select <> "Y"
      CLEAR 
      SET TALK ON
      SET ESCAPE ON
      RETURN 
   ENDIF 
   @ $+1,0 SAY "Creating index file... "
   INDEX ON &keyfield TO &indexname
ENDIF 
IF ":" $ infile
   STORE $(infile,3,1) + " " TO expanded
   STORE 4 TO pos
ELSE 
   STORE $(infile,1,1) + " " TO expanded
   STORE 2 TO pos
ENDIF 
DO WHILE pos <= LEN(infile)
   STORE expanded + $(infile,pos,1) + " " TO expanded
   STORE pos + 1 TO pos
ENDDO 
STORE TRIM(expanded) TO expanded
@ $+1,0 SAY "Getting field names..."
COPY STRUCTURE EXTENDED TO &infile..$$$
USE &infile..$$$
STORE 0 TO lastline
DO WHILE .NOT. EOF .AND. (# <= 14)
   STORE 2 TO counter
   STORE $(Field:name,1,1) TO field:save
   DO WHILE counter <= 10
      STORE $(Field:name,counter,1) TO char
      IF char >= "A" .AND. char <= "Z"
         STORE CHR( RANK(char)+32 ) TO char
      ENDIF 
      STORE field:save + char TO field:save
      STORE counter + 1 TO counter
   ENDDO 
   REPLACE Field:name WITH field:save
   STORE lastline + 1 TO lastline
   SKIP 
ENDDO 
STORE lastline + 6 TO lastline
GO TOP
@ $+2,0 SAY "Check for existing filenames..."
STORE " " TO select
STORE 1 TO counter
DO WHILE counter <= 8
   STORE TRIM( $("MAIN FRAMEGETS SOME EDIT PACK POSN LOCAT",         (counter-1)*5+1,5) ) TO word
   STORE filesystem + "-" + word + extension TO filename
   IF FILE( filename )
      @ $+1,0 SAY ["]+filename+["]
      @ $,15 SAY "ALREADY EXISTS."
      @ $,34 SAY "Delete it? (Y/N) "             GET select PICTURE "!"
      READ 
      IF select <> "Y"
         @ $+1,0 SAY " "
         SET BELL ON
         SET TALK ON
         SET ESCAPE ON
         CLEAR 
         RETURN 
      ENDIF 
   ENDIF 
   STORE counter + 1 TO counter
ENDDO 
SET BELL ON
SET RAW ON
ERASE 
STORE filesystem + "-MAIN" + extension TO outfile
SET ALTERNATE TO &outfile
SET ALTERNATE ON
? [* Program..: ]+outfile
? [* Author...: ]+yourname
? [* Date.....: ]+DATE()
? [* Notice...: Copyright (c) 19]+$(DATE(),7,2)+[, ]+yourname+                [, All Rights Reserved]
? [* Reserved.: select, selectnum, editchoice, poschoice,]
? [*            error, findkey, expression, string, is:eof]
? [*            clearline, addchoice, is:some, lastrecord]
? [*]
? [SET TALK OFF]
? [SET BELL OFF]
? [SET COLON OFF]
? [* ---Use blanks to clear-to-end-of-line.]
? [STORE $(STR(0,81),1,80) TO clearline]
? 
? [DO WHILE T]
? 
? [ERASE]
? [@  1, 0 SAY "========================================"]
? [@  1,40 SAY "========================================"]
? [@  2, 0 SAY "||"]
STORE expanded + "    M A I N    M E N U" TO heading
STORE (80-LEN(heading))/2 TO col
? [@  2,] + STR(col,2) + [ SAY "] + heading + ["]
? [@  2,78 SAY "||"]
? [@  3, 0 SAY "========================================"]
? [@  3,40 SAY "========================================"]
STORE 4 TO counter
DO WHILE counter <= 11
   ? [@ ] + STR(counter,2) + [, 0 SAY "||"]
   ? [@ ] + STR(counter,2) + [,78 SAY "||"]
   STORE counter+1 TO counter
ENDDO 
? [@ 12, 0 SAY "========================================"]
? [@ 12,40 SAY "========================================"]
? [@  5,35 SAY " 0. exit"]
? [@  6,35 SAY " 1. view"]
? [@  7,35 SAY " 2. add"]
? [@  8,35 SAY " 3. edit"]
? [@  9,35 SAY " 4. pack"]
? [STORE 5 TO selectnum]
? [DO WHILE selectnum < 0 .OR. selectnum > 4]
? [   STORE " " TO select]
? [   @ 12,33 SAY " select : : "]
? [   @ 12,42 GET select PICTURE "#"]
? [   READ]
? [   STORE VAL(select) TO selectnum]
? [ENDDO]
? 
? [DO CASE]
? [   CASE selectnum= 0]
? [      CLEAR]
? [      SET COLON ON]
? [      SET BELL ON]
? [      SET TALK ON]
? [      RETURN]
? [   CASE selectnum= 1]
? [   *  DO view]
? [      USE ]+infile+[ INDEX ]+indexname
? [      ERASE]
? [      @ 1, 0 SAY "V I E W    ]+expanded+["]
? [      @ 1,72 SAY DATE()]
? [      DO ] + filesystem + [-frame]
? [      IF # = 0]
? [         * ---The data file is empty.]
? [         STORE " " TO select]
? [         @ ]+STR(lastline+1,2)+[,0 SAY "EMPTY DATA FILE"]
? [         @ ]+STR(lastline+2,2)+[,0 ]+                  [SAY "Strike any key to continue...";]
? [                GET select]
? [         READ NOUPDATE]
? [      ELSE]
? [         * ---The data file contains records.]
? [         DO ] + filesystem + [-gets]
? [         CLEAR GETS]
? [         STORE "X" TO poschoice]
? [         DO WHILE poschoice <> " "]
? [            DO ] + filesystem + [-posn]
? [         ENDDO]
? [      ENDIF]
? [      USE]
? [   CASE selectnum= 2]
? [   *  DO add]
? [      USE ]+infile+[ INDEX ]+indexname
? [      COPY STRUCTURE TO ]+infile+[.add]
? [      SELECT SECONDARY]
? [      USE ]+infile+[.add]
? [      ERASE]
? [      @ 1, 0 SAY "A D D    ]+expanded+["]
? [      @ 1,72 SAY DATE()]
? [      DO ] + filesystem + [-frame]
? [      @ ]+STR(lastline+1,2)+[,0 ]+            [SAY "Press <control-W> to exit"]
IF TYPE(keyvalue) = "C"
   ? [      STORE "X" TO addchoice]
   ? [      DO WHILE addchoice <> " "]
   ? [         APPEND BLANK]
   ? [         DO ] + filesystem + [-gets]
   ? [         READ]
   ? [         CLEAR GETS]
   ? [         * ---] + keyfield + [ cannot be blank.]
   ? [         STORE TRIM( ] + keyfield + [ ) TO addchoice]
   ? [      ENDDO]
ELSE 
   ? [      STORE 9 TO addchoice]
   ? [      DO WHILE addchoice <> 0]
   ? [         APPEND BLANK]
   ? [         DO ] + filesystem + [-gets]
   ? [         READ]
   ? [         CLEAR GETS]
   ? [         * ---] + keyfield + [ cannot be zero.]
   ? [         STORE ] + keyfield + [ TO addchoice]
   ? [      ENDDO]
ENDIF 
? [      DELETE]
? [      USE]
? [      SELECT PRIMARY]
? [      APPEND FROM ]+infile+[.add]
? [      USE]
? [   CASE selectnum= 3]
? [   *  DO edit]
? [      USE ]+infile+[ INDEX ]+indexname
? [      ERASE]
? [      @ 1, 0 SAY "E D I T    ]+expanded+["]
? [      @ 1,72 SAY DATE()]
? [      DO ] + filesystem + [-frame]
? [      IF # = 0]
? [         * ---The data file is empty.]
? [         STORE " " TO select]
? [         @ ]+STR(lastline+1,2)+[,0 SAY "EMPTY DATA FILE"]
? [         @ ]+STR(lastline+2,2)+[,0 ]+                  [SAY "Strike any key to continue...";]
? [                GET select]
? [         READ NOUPDATE]
? [      ELSE]
? [         * ---The data file contains records.]
? [         DO ] + filesystem + [-gets]
? [         CLEAR GETS]
? [         DO ] + filesystem + [-edit]
? [      ENDIF]
? [      USE]
? [   CASE selectnum= 4]
? [   *  DO pack]
? [      DO ] + filesystem + [-pack]
? [ENDCASE]
? 
? [ENDDO T]
? [* EOF: ] + outfile
? 
SET ALTERNATE OFF
ERASE 
STORE filesystem + "-FRAME" + extension TO outfile
SET ALTERNATE TO &outfile
SET ALTERNATE ON
? [* Program..: ]+outfile
? [* Author...: ]+yourname
? [* Date.....: ]+DATE()
? [* Notice...: Copyright (c) 19]+$(DATE(),7,2)+[, ]+yourname+                [, All Rights Reserved]
? [*]
? [@  2, 0 SAY "----------------------------------------"]
? [@  2,40 SAY "----------------------------------------"]
GO TOP
STORE 4 TO counter
DO WHILE .NOT. EOF .AND. counter-3 <= 14
   ? [@ ]+STR(counter,2)+[, 0 SAY "]+     $(TRIM(Field:name)+".........",1,10)+[:"]
   STORE counter + 1 TO counter
   SKIP 
ENDDO 
? [@ ]+STR(lastline,2)+[, 0 ]+  [SAY "----------------------------------------"]
? [@ ]+STR(lastline,2)+[,40 ]+  [SAY "----------------------------------------"]
? [RETURN]
? [* EOF: ] + outfile
? 
SET ALTERNATE OFF
ERASE 
STORE filesystem + "-GETS" + extension TO outfile
SET ALTERNATE TO &outfile
SET ALTERNATE ON
? [* Program..: ]+outfile
? [* Author...: ]+yourname
? [* Date.....: ]+DATE()
? [* Notice...: Copyright (c) 19]+$(DATE(),7,2)+[, ]+yourname+                [, All Rights Reserved]
? [*]
? [IF *]
? [   @ 1,55 SAY "DELETED"]
? [ELSE]
? [   @ 1,55 SAY "       "]
? [ENDIF]
GO TOP
STORE 4 TO counter
DO WHILE .NOT. EOF .AND. counter-3 <= 14
   ? [@ ]+STR(counter,2)+[,11 GET ]+Field:name
   STORE counter + 1 TO counter
   SKIP 
ENDDO 
? [RETURN]
? [* EOF: ] + outfile
? 
SET ALTERNATE OFF
ERASE 
STORE filesystem + "-SOME" + extension TO outfile
SET ALTERNATE TO &outfile
SET ALTERNATE ON
? [* Program..: ]+outfile
? [* Author...: ]+yourname
? [* Date.....: ]+DATE()
? [* Notice...: Copyright (c) 19]+$(DATE(),7,2)+[, ]+yourname+                [, All Rights Reserved]
? [*]
? [IF *]
? [   @ 1,55 SAY "DELETED"]
? [ELSE]
? [   @ 1,55 SAY "       "]
? [ENDIF]
GO TOP
STORE 4 TO counter
DO WHILE .NOT. EOF .AND. counter-3 <= 14
   IF !( TRIM(Field:name) ) $ keyfield
      ? [@ ]+STR(counter,2)+[,11 SAY ]+Field:name
   ELSE 
      ? [@ ]+STR(counter,2)+[,11 GET ]+Field:name
   ENDIF 
   STORE counter + 1 TO counter
   SKIP 
ENDDO 
? [RETURN]
? [* EOF: ] + outfile
? 
SET ALTERNATE OFF
ERASE 
STORE filesystem + "-EDIT" + extension TO outfile
SET ALTERNATE TO &outfile
SET ALTERNATE ON
? [* Program..: ]+outfile
? [* Author...: ]+yourname
? [* Date.....: ]+DATE()
? [* Notice...: Copyright (c) 19]+$(DATE(),7,2)+[, ]+yourname+                [, All Rights Reserved]
? [*]
? [DO WHILE T]
? [   STORE " " TO editchoice]
? [   @ ]+STR(lastline+1,2)+[,0 ]+            [SAY "COMMAND: (E)dit, (D)elete, (U)ndelete, "+;]
? [              "(C)ontinue, (P)osition ";]
? [          GET editchoice PICTURE "!"]
? [   READ NOUPDATE]
? [   CLEAR GETS]
? [   @ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [   DO CASE]
? [      CASE editchoice = " "]
? [      * ---Exit.]
? [         RETURN]
? [      CASE editchoice = "P"]
? [      * ---(P)osition]
? [         STORE "X" TO poschoice]
? [         DO WHILE poschoice <> " "]
? [            DO ] + filesystem + [-posn]
? [         ENDDO]
? [      CASE editchoice = "D"]
? [      * ---(D)elete]
? [         DELETE]
? [         @ 1,55 SAY "DELETED"]
? [      CASE editchoice = "U"]
? [      * ---(U)ndelete]
? [         RECALL]
? [         @ 1,55 SAY "       "]
? [      CASE editchoice = "E"]
? [      * ---(E)dit]
? [         @ ]+STR(lastline+1,2)+[,0 ]+               [SAY "Press <control-W> to exit"]
? [         IF # <> 0]
? [            DO ] + filesystem + [-some]
? [            READ]
? [         ENDIF]
? [      CASE editchoice = "C"]
? [      * ---(C)ontinue to the next record.]
? [         STORE # TO lastrecord] 
? [         CONTINUE]
? [         * ---Check for END-OF-FILE.]
? [         IF .NOT. EOF]
? [            DO ] + filesystem + [-gets]
? [            CLEAR GETS]
? [         ELSE]
? [            * ---EOF encountered.]
? [            GOTO lastrecord]
? [            @ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [            @ ]+STR(lastline+1,2)+[,0 ]+                  [SAY "END-OF-FILE encountered"]
? [            STORE " " TO select]
? [            @ ]+STR(lastline+2,2)+[,0 ]+                     [SAY "Strike any key to continue...";]
? [                   GET select]
? [            READ NOUPDATE]
? [            @ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [            @ ]+STR(lastline+2,2)+[,0 SAY clearline]
? [         ENDIF]
? [   ENDCASE]
? [ENDDO]
? [* EOF: ] + outfile
? 
SET ALTERNATE OFF
ERASE 
STORE filesystem + "-PACK" + extension TO outfile
SET ALTERNATE TO &outfile
SET ALTERNATE ON
? [* Program..: ]+outfile
? [* Author...: ]+yourname
? [* Date.....: ]+DATE()
? [* Notice...: Copyright (c) 19]+$(DATE(),7,2)+[, ]+yourname+                [, All Rights Reserved]
? [*]
? [ERASE]
? [@ 2, 0 SAY "P A C K    ]+expanded+["]
? [@ 2,72 SAY DATE()]
? [@ 3, 0 SAY "========================================"]
? [@ 3,40 SAY "========================================"]
? [STORE "NO " TO select]
? '@ 5,0 SAY "PACK the entire file? [YES/NO] ";'
? [      GET select PICTURE "!!!"]
? [READ NOUPDATE]
? [IF select <> "YES"]
? [   RETURN]
? [ENDIF]
? [@ 6,0 SAY "]+infile+[.OLD will be your backup data file."]
? [IF FILE( "] + infile + [.OLD" )]
? [   STORE " " TO select]
? [   @ $+1,0 SAY "Delete the old backup file? (Y/N) ";]
? [           GET select PICTURE "!"]
? [   READ NOUPDATE]
? [   IF select <> "Y"]
? [      RETURN]
? [   ENDIF]
? [   DELETE FILE ]+infile+[.OLD]
? [ENDIF]
? [USE]
? [RENAME ]+infile+[.DBF TO ]+infile+[.OLD]
? [@ $+1,0 SAY " "]
? [*]
? [USE ] + infile + [.OLD]
? [SET TALK ON]
? [SET ECHO ON]
? [COPY TO ] + infile
? [USE]
? [USE ]+infile
? [* ---Recreate index file.]
? [INDEX ON ]+keyfield+[ TO ]+indexname
? [USE]
? [SET ECHO OFF]
? [SET TALK OFF]
? [STORE " " TO select]
? [@ 22,0 SAY clearline]
? [@ 22,0 SAY "Strike any key to continue...";]
? [       GET select]
? [READ NOUPDATE]
? [RETURN]
? [* EOF: ] + outfile
? 
SET ALTERNATE OFF
ERASE 
STORE filesystem + "-POSN" + extension TO outfile
SET ALTERNATE TO &outfile
SET ALTERNATE ON
? [* Program..: ]+outfile
? [* Author...: ]+yourname
? [* Date.....: ]+DATE()
? [* Notice...: Copyright (c) 19]+$(DATE(),7,2)+[, ]+yourname+                [, All Rights Reserved]
? [*]
? [STORE " " TO poschoice]
? [@ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [@ ]+STR(lastline+1,2)+      [,0 SAY "COMMAND: (D)isplay, (F)ind, "+;]
? [           "(L)ocate, (C)ontinue, (S)kip ";]
? [       GET poschoice PICTURE "!"]
? [READ NOUPDATE]
? [CLEAR GETS]
? [@ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [IF .NOT. (poschoice $ "DFLCS")]
? [   RETURN]
? [ENDIF]
? [IF poschoice = "F"]
? [   * ---(F)ind]
? [   @ ]+STR(lastline,2)+[,0 SAY "-"]
? [   ACCEPT "Enter ]+keyfield+[ " TO findkey]
? [   @ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [   STORE TRIM(findkey) TO findkey]
? [   IF findkey = " "]
? [      RETURN]
? [   ENDIF]
? [   STORE # TO lastrecord]
? [   FIND &findkey]
? [   IF (# <> 0)]
? [      DO ] + filesystem + [-gets]
? [      CLEAR GETS]
? [   ELSE]
? [      * ---NO FIND.]
? [      GOTO lastrecord]
? [      @ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [      @ ]+STR(lastline+1,2)+            [,0 SAY '"'+findkey+'"'+" not in index"]
? [      STORE " " TO select]
? [      @ ]+STR(lastline+2,2)+            [,0 SAY "Strike any key to continue...";]
? [             GET select]
? [      READ NOUPDATE]
? [      @ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [      @ ]+STR(lastline+2,2)+[,0 SAY clearline]
? [   ENDIF]
? [ELSE]
? [   * ---(S)kip, (C)ontinue, (D)isplay, or (L)ocate]
? [   STORE # TO lastrecord]
? [   DO CASE]
? [      CASE poschoice = "S"]
? [      * ---(S)kip.]
? [         SKIP]
? [      CASE poschoice = "C"]
? [      * ---(C)ontinue.]
? [         CONTINUE]
? [      OTHERWISE]
? [      * ---(D)isplay or (L)ocate]
? [         DO ] + filesystem + [-locat]
? [         IF expression = " "]
? [            RETURN]
? [         ENDIF]
? [         IF poschoice = "D"]
? [            IF string = " "]
? [               RETURN]
? [            ENDIF]
? [            DO ] + filesystem + [-frame]
? [         ENDIF]
? [   ENDCASE]
? [   * ---Check for END-OF-FILE.]
? [   IF .NOT. EOF]
? [      DO ] + filesystem + [-gets]
? [      CLEAR GETS]
? [   ELSE]
? [      * ---EOF encountered.]
? [      GOTO lastrecord]
? [      @ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [      @ ]+STR(lastline+1,2)+[,0 SAY "END-OF-FILE encountered"]
? [      STORE " " TO select]
? [      @ ]+STR(lastline+2,2)+            [,0 SAY "Strike any key to continue...";]
? [             GET select]
? [      READ NOUPDATE]
? [      @ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [      @ ]+STR(lastline+2,2)+[,0 SAY clearline]
? [   ENDIF]
? [ENDIF]
? [RETURN]
? [* EOF: ] + outfile
? 
ERASE 
STORE filesystem + "-LOCAT" + extension TO outfile
SET ALTERNATE TO &outfile
SET ALTERNATE ON
? [* Program..: ]+outfile
? [* Author...: ]+yourname
? [* Date.....: ]+DATE()
? [* Notice...: Copyright (c) 19]+$(DATE(),7,2)+[, ]+yourname+                [, All Rights Reserved]
? [*]
? [STORE " " TO expression,string]
? [* ---LOCATE section.]
? [DO WHILE expression = " "]
? [   @ ]+STR(lastline-1,2)+[,0 SAY 'EXAMPLE :STATE="CA"']
? [   @ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [   *]
? [   @ ]+STR(lastline,2)+[,0 SAY "-"]
? [   ACCEPT "Enter LOCATE expression " TO expression]
? [   @ ]+STR(lastline-1,2)+[,0 SAY clearline]
? [   STORE TRIM(expression) TO expression]
? [   DO CASE]
? [      CASE expression = " "]
? [      * ---Exit.]
? [         RETURN]
? [      CASE 0 = TEST(&expression)]
? [      * ---INVALID EXPRESSION.]
? [         @ ]+STR(lastline+2,2)+[,0 SAY clearline]
? [         STORE " " TO select]
? [         @ ]+STR(lastline+2,2)+               [,0 SAY "INVALID EXPRESSION: "+;]
? [                    "Strike any key to continue... ";]
? [                GET select]
? [         READ NOUPDATE]
? [         @ ]+STR(lastline+2,2)+[,0 SAY clearline]
? [         STORE " " TO expression]
? [      OTHERWISE]
? [      * ---LOCATE the record.]
? [         LOCATE FOR &expression]
? [   ENDCASE]
? [ENDDO]
? [IF poschoice = "L"]
? [   * ---Return to calling program ]+           [if only the LOCATE was desired.]
? [   RETURN]
? [ENDIF]
? [*]
? [* ---DISPLAY section.]
? [STORE " " TO string]
? [DO WHILE string = " "]
? [   @ ]+STR(lastline-1,2)+         [,0 SAY "EXAMPLE :NAME+ADDRESS"]
? [   @ ]+STR(lastline+1,2)+[,0 SAY "E"]
? [   ACCEPT "Enter DISPLAY string " TO string]
? [   @ ]+STR(lastline-1,2)+[,0 SAY clearline]
? [   STORE TRIM(string) TO string]
? [   DO CASE]
? [      CASE string = " "]
? [      * ---Exit.]
? [         @ ]+STR(lastline+1,2)+[,0 SAY clearline]
? [         @ ]+STR(lastline+2,2)+[,0 SAY clearline]
? [         RETURN]
? [      CASE 0 = TEST(&string)]
? [      * ---INVALID EXPRESSION.]
? [         @ ]+STR(lastline+2,2)+[,0 SAY clearline]
? [         STORE " " TO select]
? [         @ ]+STR(lastline+2,2)+               [,0 SAY "INVALID DISPLAY EXPRESSION: "+;]
? [                    "Strike any key to continue... ";]
? [                GET select]
? [         READ NOUPDATE]
? [         @ ]+STR(lastline+2,2)+[,0 SAY clearline]
? [         STORE " " TO string]
? [   ENDCASE]
? [ENDDO]
? [* ---Now, DISPLAY the expression.]
? [STORE F TO is:eof,is:some]
? [DO WHILE .NOT. is:eof]
? [   * ---The following set of dBASE II commands are to ]
? [   * ---clear-to-end-of-screen.  If you have an IBM-PC,]
? [   * ---you can replace these commands with the single]
? [   * ---command,  @ 4,0 ERASE]
? [   *]
STORE 4 TO row
DO WHILE row <= 22
   ? [   @ ]+STR(row,2)+[,0 SAY clearline]
   STORE row + 1 TO row
ENDDO 
? [   @ 20, 0 SAY "----------------------------------------"]
? [   @ 20,40 SAY "----------------------------------------"]
? [   STORE 4 TO row]
? [   DO WHILE .NOT. EOF .AND. row-3 <= 15]
? [      STORE T TO is:some]
? [      @ row,0 SAY ]+[&]+[string]
? [      STORE row + 1 TO row]
? [      CONTINUE]
? [   ENDDO]
? [   * ---A logical memory variable is used to detect the]
? [   * ---end-of-file.  The EOF function cannot be used since]
? [   * ---it is reset by the READ statement below.]
? [   STORE EOF TO is:eof]
? [   IF .NOT. is:some]
? [      * ---No matching records.]
? [      @ 4,0 SAY "*** NO MATCHING RECORDS ***"]
? [   ENDIF]
? [   STORE " " TO select]
? [   @ 21,0 SAY "Strike any key to continue... ";]
? [          GET select]
? [   READ NOUPDATE]
? [   @ 21,0 SAY clearline]
? [ENDDO]
? [* ---The following set of dBASE II commands are to ]
? [* ---clear-to-end-of-screen.  If you have an IBM-PC,]
? [* ---you can replace these commands with the single]
? [* ---command,  @ 4,0 ERASE]
? [*]
STORE 4 TO row
DO WHILE row <= 22
   ? [@ ]+STR(row,2)+[,0 SAY clearline]
   STORE row + 1 TO row
ENDDO 
? [GO TOP]
? [RETURN]
? [* EOF: ] + outfile
? 
SET ALTERNATE OFF
SET ALTERNATE TO
USE 
DELETE FILE &infile..$$$
ERASE 
? [TO START  "]+infile+["  SYSTEM, TYPE THE FOLLOWING:]
? [.]
? [.]
? [. DO ]+filesystem+[-MAIN]
? [.]
CLEAR 
SET RAW OFF
SET TALK ON
SET ESCAPE ON
RETURN 
nction can