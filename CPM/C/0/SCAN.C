#include "cpm.h"

char scancode[16];

char GetScanCode(void){
 char i = 0;

   memset(&scancode[0], 0, sizeof(scancode)); 
   while (scancode[0] == 0) scancode[0] = bdos(6, 0xFF);
   while (scancode[i] != 0) scancode[++i] = bdos(6, 0xFF);

  return i;
}

main(){
  char scancode_size, i;
  puts("Scancode v.1\nPress a key for input scancode from BDOS(6, 0xFF), ENTER - quit test");
  
   do{
     scancode_size = GetScanCode();

     printf("scancode size = %d, value = ", scancode_size);
     for(i=0;i < scancode_size;i++) printf("%01x:", scancode[i]);
     puts("\x8 ");
   } while(scancode[0] != 0x0D);
}
