
10  INTEGER X,Y
20  STRING A$
30  OPEN 0,1,"SEEKTEST"
40  DELETE 1
45  CLOSE 1
50  OPEN 2,1,"SEEKTEST"
60   IF  ERR THEN  PRINT ERR$: STOP 
70  FIELD 2,X,9,A$
80  FOR X=0 TO 25
90   A$=CONCAT$("--DATA--",CHR$(65 + X))
100  PUT 
110  PRINT "WRITING ";X;" ";A$
120  NEXT X
END
,A$
80  FOR X=0 TO 25
90   A$=CONCAT$("--DATA--",CHR$(65 + X))
100  PUT 
110  PRINT "WRI