/******************************************************************************
 Copyright (c) 1984					 Eigenware Technologies

	     A function to calculate the factorial of an integer

******************************************************************************/

factorial(n)
int n;
{
   int solution;

   if (n == 0) solution = 1;
   else solution = n * factorial(n-1);

   return(solution);
}















ееееееееееееееееееееееееееееееееееееееееееееееееееееееееееееееее