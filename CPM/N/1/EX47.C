/*--------------------------------------------------------------------------
  Copyright (c) 1984				      Eigenware Technologies

			       Bit Fields

  NOTE #1: Very useful and handy facility supported by C86; not supported
	   by many other microcomputer C compilers.

  NOTE #2: This is an efficient way to pack information.

  NOTE #3: A special syntax is used:

				fieldname:n

	   where fieldname is the name assigned to a field of bits, and
	   the number of bits in the field is n.

---------------------------------------------------------------------------*/

#define P(F,X) printf("X = %F\n", (X))

struct bit_packing {
   unsigned int flag_1:1;  /* . . . . assign one bit to field named flag_1 */
   unsigned int flag_2:1;
   unsigned int flag_3:1;
   unsigned int item_1:5;  /* . . . assign five bits to field named item_1 */
   unsigned int item_2:8;  /* . . . . . . . . .assign eight bits to item_2 */
} ;

main()
{
/* . . . . . . . . . . . . . . . . . . . . . .declare variable called data */

	struct bit_packing data;

/*  . . . . . . . . . . . assign values to members of variable called data */

	data.flag_1 = 1;
	data.flag_2 = 0;
	data.flag_3 = 1;
	data.item_1 = 25;
	data.item_2 = 'A';

/* . . . . . . . . . . . . . . . . . . . . . . . . . . . . . print results */

	P(b, data.flag_1);
	P(b, data.flag_2);
	P(b, data.flag_3);
	P(b, data.item_1);
	P(b, data.item_2);

   exit(0);
}


   exit(0);
}
�F��v�����F�F�)F�F�F��T��F�F��F��F�  �F���N�;�wc