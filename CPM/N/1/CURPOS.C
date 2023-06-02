/*************************************************************************
CURPOS.C

Cursor position program for heath/zenith 89 & 100
WMA
**************************************************************************/

curpos(line, column)
int line, column;
{
   printf("\033Y");
   putchar(line + 31);
   putchar(column + 31);
}
