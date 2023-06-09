%							%
%	CUBIC solves cubic equasions of the form	%
%		y^3 + p*y^2 + q*y + r = 0		%
%							%
FUNCTION CUBIC(EXPR,Y,X,A,B,A1,B1,P,Q,Z)
    R: EVSUB(EXPR,Y,0),
    Q: EVSUB(DIF(EXPR,Y),Y,0),
    P: EVSUB(DIF(DIF(EXPR,Y),Y),Y,0),
    Z: DIF(DIF(DIF(EXPR,Y),Y),Y)
    WHEN (NOT (Z=1)) AND (NOT (ZERO(Z))),
       CUBIC(EXPR/Z,Y) EXIT
    A: (3*Q-P^2)/3   B: (2*P^3-9*P*Q+27*R)/27
    A1: CUB(-B/2+SQR(B^2/4+A^3/27))
    B1: CUB(-B/2-SQR(B^2/4+A^3/27))
    PRINT("ROOT 1 =") PRTMATH(A1+B1), NEWLINE(),
    PRINT("ROOT 2 =")
       PRTMATH(-(A1+B1)/2+(A1-B1)/2*SQR(-3)), NEWLINE(),
    PRINT("ROOT 3 =")
       PRTMATH(-(A1+B1)/2-(A1-B1)/2*SQR(-3)), NEWLINE(),
ENDFUN $
%							%
%	SQR finds the square root in muMath form	%
%							%
FUNCTION SQR(X),
  X^(1/2)
ENDFUN $
%							%
%	CUB finds the cube root in muMath form		%
%							%
FUNCTION CUB(X)
  X^(1/3)
ENDFUN $
%							%
%							%
STOP() $
RDS() $
                                                                                  