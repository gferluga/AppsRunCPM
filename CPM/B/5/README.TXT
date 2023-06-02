This folder contains the source code of DASM by cirsovius.de

The tool DASM reconstructs assembler sources from binary CP/M .COM files. Read the quotation from the original file:

	;	DASM is a TDL/ZILOG Disassembler derived from Dave Barker's
	; ZZSOURCE and Ward Christensen's RESOURCE by Richard Conn.  Refer to
	; the documentation on RESOURCE and the built-in HELP data for information
	; on the commands used for DASM.  A Help file is also being planned for DASM.

DASM creates mnemonics for the Z80 CPU. In fact using the ZILOG module for pure Z80 ZILOG notation and using the TDL module for extended 8080 notation. The tool RESOURCE mentioned above was able to create „straight" 8080 code.

DASM creates three control files:
	1. CTL: This file determines program code or data (as byte-, word-, string or reserved memory). This is the most important file working with DASM because it controls the sequence of the source file. DASM supports a simple automatic detection of ASCII characters. Unfortunately many Z80-instructions lay within ASCII character range (e.g. E = 0x45 = LD B,L) so in practice characters may be found within code, making no sense.
	2. SYM: This file contains symbols. Either defined by the user or by DASM automatically. The latter in the form Lxxxx, where „xxxx reperesents the 16 bit address of the symbol. Because the linker also creates a .SYM file writing symbols I changed it into .SMB.
	3. CMT: This file holds comments assigned to addresses which may be very useful. E.g. you may assign a description to a subroutine.

In a normal cycle all of the above files were created. Maybe files had be be edited awhile. The assembler file was created in conclusion.

The original version of DASM managed the available TPA memory in a static way, i.e. for the control table, the symbols, comments as well as for the .COM file. Static means constant which may be far away from real demands. One of the first modifications I made was to manage the memory dynamically. Step 2 was to load currently only one record — 128 bytes — from the .COM file. This means there is more room for the tables. 
Another expansion was to request the current state of the program counter while executing the commands (A, B and L) by typing the character '?'. This may be a useful help analysing large programs. 
A last expansion affects the load address for .COM files: the command Vaaaa allows any address for loading it (defaults to 0100).

The program is compiled from two parts:

	. The mnemonic independent kernel — DASMKRN
	. The mnemonic dependent part — DASM8080 or DASMZ80

The kernel is always required while the program's function is determined by the mnemonic dependent part. Compiling the ZILOG version requires the following command sequence if using the Microsoft M80 package:
	M80 =DASMZ80 /Z		Assembles the kernel
	M80 =DASMKRN /Z		Assembles the ZILOG part
	L80 DASMZ80,DASMKRN,DASM/N/E	Builds the file DASM.COM
