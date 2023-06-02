This folder contains the source code of SID/ZSID by cirsovius.de

A very important tool developing assembler programs is a debugger. The standard debugger for CP/M 2.x was the DDT (Dynamic Debugging Tool). CP/M 3.x was shipped withe the advanced version, called SID (Symbolic Instruction Debugger). There also did exist an unofficial version of SID handling Z80 mnemonics — the ZSID (Z80-SID). 
Running on the Joyce there did exist a problem referring to the interrupt vector. So I decided to disassemble the original ZSID. I eliminated some bugs in the source and made some slight modifications.

New commands are:

Command	Action
B	Find byte or string series
O	Other bank select than TPA bank 1
Q	Quit debugger (instead quit by ^C)

Suggested by the disassembler DASM the module for the commands L (List assembler code) and A (Assemble) may be selected either for the 8080 or Z80 CPU.
Debuggers — such as the programs to be examined — are .COM files which must also be loaded into memory starting at location 0100H. After loading the debugger it must be moved into top of memory to allow the program to be examined to be loaded into 0100H.
Usually program interrupts will be performed by breakpoints. In fact using the 8080 resp. Z80 it is the RST opcode. This leads to an conflict running on the JOYCE: This machine runs in interrupt mode 1 using address 038H to be entered if an interrupt occurs. ZSID used RST 7 for the breakpoint — that is the same address 0038h!

Two utilites may be combined with SID as well as with ZSID which must be loaded additionally.

1. HIST.UTL creates a histogram (bar graph) showing the relative frequency of execution of code within selected program segments of the test program. The HIST utility allows you to monitor those sections of code that execute most frequently.
2. TRACE.UTL obtains a backtrace of the instructions that led to a particular breakpoint address in a program under test. You can collect the addresses of up to 256 instructions between pass points in U or T modes.
