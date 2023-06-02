	REM USED TO "PLAY" WITH RANDOM DISK FILES
	var x,y=integer
	var xdata=integer
	files r(256)
	if size("JUNK")=0 then create "JUNK"
	open #0;"JUNK"
0	input "SEQ ON=0 OFF=1";x
	if x=0 then record.sequential on
	if x=1 then record.sequential off
	input "0=READ 1=WRITE";x
	input "RECORD #";y
	if x=1 then begin
	   input "DATA=";xdata
	   write #0,y; xdata
	   end
	if x=0 then begin
	   read #0,y; xdata
	   print "DATA=";xdata
	   end
	goto 0

