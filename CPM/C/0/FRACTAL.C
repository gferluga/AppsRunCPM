#include "math.h"

main()
{
  double CA, CB, A, B, T;
  int n, X, Y, i;

  for(Y=-12;Y<13;Y++)
  {
   for(X=-39;X<39;X++)
   {
     CA = X * 0.0458;
     CB = Y * 0.08333;
     A = CA;
     B = CB;
     i = 0;
     n = 0;
     while(i<15)
     {
       T = A*A - B*B + CA;
       B = 2*A*B + CB;
       A = T;
       if((A*A + B*B) > 4)
       {
         n = i + 48;
         if(i>9) n += 7;
         putchar(n);
         break;
       }
       i = i + 1;
     }
     if(n==0) putchar(' ');

   }
   puts("\r");
  }
}