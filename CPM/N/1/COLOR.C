/****************************************************************************
 Copyright (c)					       Eigenware Technologies

   A function to set the foreground and background colors on the H/Z100

****************************************************************************/

clr(f,b)
char f,b;
{
   bdos(9,"\033m$");
   putchar(f);
   putchar(b);
   return(0);
}
