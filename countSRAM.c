#define mem_address 0x00000000
#define i_o_value 0x00000000
#define oe 0x0000000
#define we 0x0000000
#define ce 0x0000000
#define hex 0x0000000

#include <Windows.h>

/ -------------------------------------------------------------------------------------
// filename: countSRAM.c
//
//Description:This function writes incrementing binary values to each address in memory 
//			This function then reads all of this data which will print in decrementing data
//
//Author: Nate Cloud-Rouzan
// -------------------------------------------------------------------------------------

int main() {
    int start = 127;
    *ce = 0;
    *oe = 1;
    *we = 1;
    for (int i = 0; i <= start; i++) {
        *(mem_address) = i;
        *(i_o_value) = start - i;
        *we = 0;
        sleep(500);
        *we = 1;
    }

    for (int i = 0; i <= start; i+++) {
        *mem_address = i;
        *oe = 0;
        *hex = *(i_o_value);
        sleep(500);
        *oe = 1;
    }
}