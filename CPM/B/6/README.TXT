This folder contains the source code of Turbo Pascal by cirsovius.de

A commercial program was available in the days of MS-DOS 2.11 which did eliminate needless routines from a compiled program created by TURBO PASCAL. This decreased the .COM file accordingly because the entire Run Time Library is linked into any compiled program. I planned to perform this for CP/M, too. But it led to disassembling of the complete compiler. I also added some new functions as well as procedures. But not only because of these reasons but also due to some missing functions in the CP/M implementation of TURBO PASCAL I started disassembling. E.g. the function „APPEND" was missing which was easy to code. The JOYCE allowed to find out the current cursor position (WHEREX, WHEREY) easily. Also I like the DU: specification describing files. At last I rewrote the editor for best utilisation of the JOYCE keyboard.

After assembling the modules a new version of the compiler will be generated using the CP/M PLUS linker by:

	LINK TPnew=TR,TM,TEN,TC,TI[A]

-----------------------------------------------------------------------------------------------------------

The usual way to compile a program is:

	1. Create the source using an editor
	2. Create the object codes invoking the compiler
	3. Create the executable program using a linker and the Run Time Library

As is well-known TURBO PASCAL is written as a development system made of the following modules:

	1. Run Time Library
	2. Menu
	3. Editor
	4. Compiler

Therefore only one program is needed - instead of the three ones listed above. 

I assembled a new compiler version to be invoked by a CP/M command line, using the modules Run Time Library and Compiler. For it I wrote a module which serves as an interface between CP/M and the real compiler. This version of TURBO PASCAL does not allow running programs in memory but only generating .COM or .CHN files. 
Invoke it as follows:

	TURBOCOM SOURCE_file{.PAS} {/Start_address} {/End_address} {/H}}

The options are defined as follows:

	Option	/Saaaa	defines a start address
	Option	/Eaaaa	defines an end address
	Option	/H	selects a chain file

