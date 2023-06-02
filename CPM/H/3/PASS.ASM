; * * WARNING * WARNING * WARNING * WARNING * WARNING * WARNING * *

;  Please do not try to use external functions
;  unless you are familiar with assembly language.
;
;  IMPORTANT: Externals must be written in assembly language.
;
;  The following example addes two integer numbers.
;
;
code   segment
       assume   cs:code
pass   proc     near

       push     bp            ; SAVE ENVIRONMENT
       mov      bp,sp

       mov      ax,[bp+4]     ; GET PARAMETER 1
       add      ax,[bp+6]     ; GET PARAMETER 2
                              ; GIVES THE RESULT
       mov      sp,bp         ; RESTORE ENVIRONMENT
       pop      bp
       ret      4

pass   endp
code   ends
       end

; Now exit to PC-DOS and type:
;   >ASM PASS
;   >LINK PASS
;   >EXE2BIN PASS.EXE PASS.COM
;
; Ignore minor errors from ASM and LINK.
;  The above external procedure is only an example.  You
;  can achieve the same result in Turbo-Pascal:
;
;  function pass(varX, varY:integer):interger;
;  begin
;     pass := varX + varY;
;  end;
