#define CC_NO_MUL    // To exclude MULTIPLICATION code.
#define CC_NO_DIV    // To exclude DIVISION & MODULUS code.
#define CC_NO_SWITCH // To exclude SWITCH code.
#define CC_NO_ARGS   // To exclude ARGC & ARGV code.

#include <mescc.h>
#include <conio.h>

main(argc, argv)
int argc, argv[];
{
  puts("Hello World!\n");
}
