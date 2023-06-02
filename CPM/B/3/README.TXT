This folder contains the source code of M80 by cirsovius.de

When I began to write assembler programs running CP/M PLUS (3.0) I used the 8080 assembler RMAC the first time. Later I purchased MBASIC (interpreter) and BASCOM (compiler) by Microsoft. This package contained the following assembler utilities
. M80:		The assembler handling 8080 as well as Z80 mnemonics
. L80:		The linker
. LIB80:	The librarian
. CREF80:	The cross-reference program
In conjunction with CREF80 the M80 was also able to generate cross-references, just like XREF for MAC or RMAC by Digital Research. Most often I used the M80 but to link programs I used LINK by Digital Research. LINK but not L80 allowed to create RSX modules. Also I used LIB by Digital Research as librarian because this one supports indexed .REL files (.IRL files). Also the L80 processed data in memory only leading to problems linking large programs (LINK was able to swap out data to disk). This was realized by Microsoft launching LD80.

Whenever an assembler project was finished I made a final listing to be filed properly. But Murphey is present so a short period after filing an unexpected error occured. It was fixed and a new listing printed without incrementing the version number of the project. Some times ago at least two different listings did exist but with same version number — which ever could be the right one? 
Fortunately I found an article concerning the insertion date and time into an M80 listing. It worked upon an RSX which inserts a time stamp — date and time as well as RSX handling works properly running CP/M PLUS. Unfortunately the published RSX did not run. Therefore I decided to disassemble the assembler to insert new functions.

I expanded M80 by the following new functions:

 . Write symbols only into the .PRN file, option /Y
 . Insert date and time into the .PRN file, option /D
 . Write errors into an log file, option /E
 . Print warnings only not the complete error messages, option /W
 . Set all symbols to global, option /G
 . Set all unknown symbols to external, option /U
 . Execute linker automatically if any found creating .COM file, option /B
 . Be verbose and tell files currently being processed, option /V
 . Suppress output for directive .PRINTX, option /Q
 . Default is now Z80 so options /Z and /I are reversed

If the assembler is invoked by M80 -M it will be loaded into memory for processing multiple files without restarting the M80

If any of the modules is modified the assembler must be built again e.g. invoking Digital Research's linker by LINK M80NEW=M80KERN,M80VER,M80DATE,M80IO,M80CMD.
