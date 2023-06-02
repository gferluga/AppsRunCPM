This folder contains the source code of SLR Assembler by cirsovius.de

Even though I liked the Microsoft assembler M80 much it was pretty slow. In contrast to the M80 the SLR supports Z80 mnemonics "only" but ist very fast and even generates the Microsoft .REL format. As a curious person I took a look into the assembler using a debugger and found the code encrypted – also in the linker and librarian. A real challenge for disassembling them!

1.	A first look at the program shows meaningless code following some meaningful data locations.

	jp	l2459
; Locations 0103H - 01A5H are not coded data areas
l0103:
	db	'Z3ENV'
	db	1
	dw	0
	dw	0131h
	db	0
	db	80
	db	60
	db	0
	..	..
	..	..
; First coded area starts at 01A6H up to 245FH
l01a6:
;	ORIGINAL		DECRYPTED
;	--------		---------
	cp	h		; db	05eh
	add	a,(hl)		; db	13,'Extra Operand'
	adc	a,d
	inc	a
	ret	pe
	add	hl,sp
	jp	nz,9e10h
	jr	c,017bh
	add	hl,sp
	jp	nz,0c837h
	rst	38h		; db	-1
	..	..
	..	..
; Encoder starts at 2459H
l2459:
	ld	hl,l2460	; Load hided length
	ld	de,l01a6	; Load first start address
	call	l246d		; Encode
	ld	hl,l633f	; Same for second part
	ld	de,l2486
	call	l246d
	jr	l24c1		; Start assembler
l246d:
	or	a
	sbc	hl,de		; Calculate length
	srl	h		; Halve it
	rr	l
	ld	b,l		; Get low
	ld	c,h		; Get high
	jr	z,l2479
	inc	c
l2479:
	ex	de,hl
l247a:
	rrc	(hl)		; Build real code
	inc	hl
	rlc	(hl)
	inc	hl
	djnz	l247a
	dec	c
	jr	nz,l247a
	ret
; Second coded area starts at 2486H up to 633EH
l2486:
;	ORIGINAL		DECRYPTED
;	--------		---------
	ld	(hl),h		; ld	a,(6365H)
	or	d
	add	a,0dbh		; or	a
	sub	l		; jp	z,2905H
	add	a,d
	ld	d,d
	..	..
	..	..
; Assembler starts here after encoding
l24c1:
;	ORIGINAL		DECRYPTED
;	--------		---------
	or	0f6h		; ld	sp,(0006h)
	inc	bc
	nop
	dec	d		; ld	hl,(0109h)
	ld	(de),a
	add	a,b
	..	..
	..	..

The routine starting at 2459H decodes two program parts. After calculating the length of code both parts will be converted to correct code by shifting their bytes right and left alternately.

2.	A closer look at the code shows a security mechanism. Before writing data into a file a routine checks an expected checksum. If it is a wrong one, no data will be written to disc. The expected result will be found at address 01A6H — this is the first address found in the encrypted area.

;
; Write buffer(s) to disk if serial number is correct
;
l6076:
	push	hl
	push	bc
	push	de
;
; !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
; !!! The next code is dirty tricky. It checks the serial  !!!
; !!! number of the assembler and suspends execution if    !!!
; !!! no match found against expected one                  !!!
; !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
;
	ld	hl,1500h	; Nice, isn't it
	ld	a,0		; .. more nice
	or	a		; .. dtto.
	rra			; .. dtto.
	adc	hl,hl		; .. dtto.
	ld	b,6
l6084:
	add	a,(hl)
	inc	hl
	djnz	l6084
	ld	de,d7a0h	; Offset 01a6h-(2a00h+6)
	add	hl,de		; .. also nice.
	cp	(hl)
;
; !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
;
	pop	de
	pop	bc
	pop	hl
	ret	nz		; .. unexpected S/N, so break
	..	..		; Continue writing data
	..	..

Again programmed confusingly, the code checks the serial number.

	1. Load the address where the serial number — here SB3051 — is stored. But instead of 2A00H load the half address 1500H, which will then be doubled.
	2. Calculate the sum of the six character number.
	3. Calculate the address of the expected sum by adding a mysterious offset. Compare the calculated sum with the expected one.
	4. If no match found stop writing data to file.

The program itself does run normally whether or not a match occurs. But only if it matches an output file will be created.