#include     "cpm.h"

void main(){
    char Drive;
    short Init = 0;

    for(Drive = 0; Drive < 16; Drive++){
        if(bios(9, Drive, Init) != 0) {
            printf("drive %c:\n", Drive + 'A');
        }
    }
}
