/************************************************************************
 Copyright (c) 1984				   Eigenware Technologies

		  for loops and printf format conversions

*************************************************************************/

/*#define puts printf  comment out for Aztec. . . . conversion from BDS-C */

main()
{
    int number;
    char *title;
    char *heading;

    title = "Demonstrates 'for' loop and printf conversion\n";
    heading = "\noctal \t\tdecimal \t	 hexadecimal\n";

    puts(title);

    puts(heading);
    for( number = 0; number <= 15; number = number + 1 )
	printf("  %o \t\t   %d \t\t\t%x\n", number, number, number);

    puts(heading);
    for( number = 0x00; number < 0x10; number++)
	printf("  %o \t\t   %d \t\t\t%x\n", number, number, number);

    exit(0);
}
