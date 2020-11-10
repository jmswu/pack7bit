#include <stdio.h>
#include <stdint.h>
#include "pack7bit.h"

void debug_print(uint8_t *ptr);


int main(int argc, char **argv){
    uint8_t *hex_code = (uint8_t *)"12345678";
    
    uint8_t packed_data[64] = {0};
    uint8_t unpacked_data[64] = {0};

    printf("string code   :%s\n", hex_code);
    debug_print(hex_code); 

    packArray(hex_code, packed_data);
    debug_print(packed_data);

    unpackArray(packed_data, unpacked_data);
    debug_print(unpacked_data);

    return 0;
}


void debug_print(uint8_t *ptr){
    printf("7 bit char raw:");
    for (int i = 0; i < strlen((const char *)ptr); i++)
        printf("%02X ", (uint8_t)ptr[i]);
    
    printf("\n"); 
}
