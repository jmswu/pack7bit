#include <stdio.h>
#include <stdint.h>
#include "pack7bit.h"

/* print out raw data */
void debug_print(uint8_t *ptr);


int main(int argc, char **argv){
    uint8_t *hex_code = (uint8_t *)"123ABCDE";
    
    uint8_t packed_data[64] = {0};
    uint8_t unpacked_data[64] = {0};

    printf("string code   :%s\n", hex_code);
    debug_print(hex_code); 

    packArray8Byte(hex_code, packed_data);
    debug_print(packed_data);

    unpackArray7Byte(packed_data, unpacked_data);
    debug_print(unpacked_data);

    /* compare the origional hex code to the packed then unpacked data */
    printf("%s\n", memcmp(hex_code, unpacked_data, strlen((char *)hex_code)) == 0 ? "Match!" : "Not match!");

    for (size_t i = 0; i < 20; i++)
    {
        printf("len = %03d, ", i);
        packArray(hex_code, i, packed_data);
    }
    
    

    return 0;
}


void debug_print(uint8_t *ptr){
    printf("char raw:");
    for (int i = 0; i < strlen((const char *)ptr); i++)
        printf("%02X ", (uint8_t)ptr[i]);
    
    printf("\n"); 
}
