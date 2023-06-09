%							%
POINT: FALSE $
PUTD('PRTMATH2, GETD('PRTMATH)) $
%							%
%	now redefine the PRTMATH function		%
%							%
FUNCTION PRTMATH1 (EX1,RBP,LBP,PRTSPACE,
    % Local: %  EX2, EX3),
  WHEN NUMBER(EX1) AND (POSITIVE(POINT) OR ZERO(POINT)),
    EX2: DEN(EX1),
    EX1: NUM(EX1),
    PRTSPACE: FALSE,
  BLOCK
    WHEN NEGATIVE(EX1),
      BLOCK
        WHEN LBP > 130,
          PRTSPACE: TRUE,
          PRINT (LPAR) EXIT,
      ENDBLOCK,
      PRINT('-),
      EX1: -EX1 EXIT,
  ENDBLOCK,
  EX1: DIVIDE(EX1,EX2)
  PRINT(FIRST (EX1)),
  PRINT ('.)
  EX3: POINT,
  LOOP
    WHEN ZERO(EX3) EXIT,
    WHEN ZERO(SECOND(EX1)) EXIT,
    EX1: DIVIDE (TIMES (SECOND (EX1), RADIX()), EX2),
    EX3: DIFFERENCE (EX3, 1),
    PRTDIG (FIRST(EX1)),
  ENDLOOP,
  WHEN PRTSPACE, PRINT (RPAR) EXIT EXIT,
PRTMATH2 (EX1, RBP, LBP, PRTSPACE)
ENDFUN $
%							%
%							%
FUNCTION PRTMATH (W,X,Y,Z)
  WHEN NUMBER(W), PRTMATH1 (W,X,Y,Z), "" EXIT,
PRTMATH2 (W,X,Y,Z), ""
ENDFUN $
%							%
%							%
FUNCTION PRTDIG (EX1),
  WHEN LENGTH (EX1) EQ 1, PRINT (EX1), EXIT,
  PRINT (SECOND (EXPLODE (EX1))),
ENDFUN $
%							%
%	this float function for inputting floating	%
%	numbers doesn't work correctly --		%
%	3.01 is read as 3.1				%
%							%
FUNCTION FLOAT(EX1, EX2)
  EX1 + EX2/RADIX()^LENGTH (EX2)
  ENDFUN $
PROPERTY LBP, ".", 190 $
PROPERTY INFIX, ., COND (
  WHEN INTEGER (EX1) AND INTEGER(SCAN)
    FLOAT(EX1, SCAN, SCAN()) EXIT
  WHEN SYNTAX() EXIT ) $
%							%
%	this logapx(x) function finds an approximation	%
%	to LN(x) using N terms of a series expansion	%
%	best to use with the floating point package	%
%							%
FUNCTION LOGAPX (X, N, Z, TOTAL, CTR),
  TOTAL: CTR: 0,
  Z: (X-1)/(X+1),
  X: Z^2,
  LOOP
    TOTAL: TOTAL + Z/(2*CTR+2),
    WHEN CTR=N, 2*TOTAL EXIT,
    Z: Z*X,
    CTR: CTR+1,
  ENDLOOP,
ENDFUN $
%							%
%							%
STOP() $
RDS () $
                                                                                                                     