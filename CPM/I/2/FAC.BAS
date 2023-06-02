	Rem This function finds X!
	Function fac(i=real)=real
	  If i=0 then i=1 else i=fac(i-1)*i
	End =i

	Var x=real
0Loop	Input x
	Print fac(x)
	Goto 0Loop
	End
