BEGIN
COMMENT UPDATED LUNAR LANDER FROM KILOBAUD AUGUST 78;
DECIMAL F,V,D,B,C;
INTEGER A;
WRITE(TAB 8,"LUNAR LANDER MKII");
WRITE(TAB 8,"+++++++++++++++++");
WRITE(" ");
WRITE("WOULD YOU LIKE INSTRUCTIONS?");
WRITE("1=YES 0=NO");
READ(A);
IF A=1 THEN
  BEGIN
    WRITE("YOU HAVE 120 LBS OF FUEL");
    WRITE("YOU ARE APPROACHING THE LUNAR");
    WRITE("SURFACE AT 50 FT/SEC, AND");
    WRITE("ARE CURRENTLY 500 FT FROM");
    WRITE("THE SURFACE, TO CANCEL");
    WRITE("GRAVITY BURN 5 LB FUEL");
  END;
A:=1;
WHILE A=1 DO
BEGIN
WRITE("HAPPY LANDINGS!!!!");
F:= 120.0; V:=50.0; D:=500.0;
FUEL:WRITE("FUEL ", F);
WRITE("SPEED ",V);
WRITE("DISTANCE ",D);
INPUTBURN:WRITE("ENTER YOUR BURN");
READ(B);
IF B>F THEN GOTO INPUTBURN;
F:=F-B; C:=B-5.0; D:=D-V+C/2.0; V:=V-C;
IF D>0 THEN GO TO FUEL;
IF V>=5.0 THEN
  BEGIN
    WRITE("****!!!CRASH!!!****");
    WRITE("YOU HIT THE MOON AT ", V," FT/SEC");
  END
ELSE
  BEGIN
    WRITE("WELL DONE - YOU LANDED OK");
    WRITE("LANDING SPEED ",V," FT/SEC");
    END;
WRITE("DO YOU WANT ANOTHER TRY?");
WRITE("1=YES, 0=NO");
READ(A);
END;
WRITE("END");
END
