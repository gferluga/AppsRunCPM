(***********************************************************************)
(*                                                                     *)
(*        Write to a string (sprintf) Example Program                  *)
(*                                                                     *)
(*          (C) Copyright 1986  Borland International                  *)
(*                                                                     *)
(***********************************************************************)

MODULE strtexts.
FROM SYSTEM IMPORT ADR;
FROM TEXTS IMPORT TEXT, EOL, ConnectDriver, OpenText, CloseText;
FROM STRINGS IMPORT CAPS;

EXCEPTION InternalError;

VAR
  s: ARRAY TEXT OF POINTER TO ARRAY [0..65535] OF CHAR;
  p, h : ARRAY TEXT OF CARDINAL;

PROCEDURE strdriver( t: TEXT; VAR ch: CHAR );
BEGIN
  IF ch = EOL THEN ch := 0C END;
  IF p[t] <= h[t] THEN s[t]^[p[t]] := ch; INC(p[t]) END;
  IF ch = 0C THEN CloseText(t) END;
END strdriver;

PROCEDURE ConnectString( VAR t: TEXT; VAR a: ARRAY OF CHAR );
BEGIN
  ConnectDriver( t, strdriver );
  a := ""; s[t] := ADR(a); h[t] := HIGH(a); p[t] := 0;
END ConnectString;

VAR fn, fn1, msg : ARRAY [0..79] OF CHAR;
    t1, t2, t3: TEXT;
BEGIN
  WRITE("Filename ?>"); READLN(fn);
  ConnectString(t1,fn1);
  WRITELN(t1,"C:",fn,".MCD"); CAPS(fn1);
  IF NOT OpenText(t2,fn1) THEN
    ConnectString(t3,msg); WRITELN(t3,fn1, " not found");
    RAISE InternalError, msg;
  ELSE
    ConnectString(t3,msg); WRITELN(t3,fn1, " was found.");
  END;
  WRITELN(msg);
END strtexts.
                          SHELL   2�FILES   ��
TERMINALU�COMLINE 