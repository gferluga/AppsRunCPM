/*************************************************************************
 Copyright (c) 1984				    Eigenware Technologies

	    ** scanf, if-else, +=, in a forever-loop **

		Stop this program with a control-c

**************************************************************************/

main()
{
  float x = 0, p_sum = 0, n_sum = 0;

  printf("\t\t\033pDEMONSTRATE IF-ELSE CONSTRUCT AND FOREVER-LOOP\033q\n");

  for (;;) {	/* . . . . . . . . . . . . . . . . . . . .a forever loop */
     printf("\nEnter number: ");
     scanf("%f", &x);		/* . . . . . . . . . use scanf for input */

			       /* . . . . . . . . . . .if-else construct */
     if (x > 0 ) p_sum += x;
     else n_sum += x;	       /* . . . . . . . .  ( n_sum = n_sum + x ) */

     printf("p_sum = %f,  n_sum = %f", p_sum, n_sum);
  }
}
n_sum);
  }
}
 P�v��^;�t� � P�v��tX^#��u� �v�� 