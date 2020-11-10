#include "pack7bit.h"

/* \brief   Pack two 7-bit data into one 8-bit data
 * \param   uint8_t first   - first byte to be packed
 * \param   uint8_t second  - second byte to be packed
 * \param   uint8_t index   - index of the packed data      
 */ 
uint8_t packOneByte(uint8_t first, uint8_t second, uint8_t index);

/* \brief   Extract a number of bit from a byte
 *          extractFromMSB() extract data from starting from MSB
 *          extractFromLSB() extract data from starting from LSB
 * \param   uint8_t input   - data to extract bit from
 * \param   uint8_t num     - number of bit to extract from, must be 0 - 7
 */
uint8_t extractFromMSB(uint8_t input, uint8_t num);
uint8_t extractFromLSB(uint8_t input, uint8_t num);

void packArray8Byte(uint8_t *input, uint8_t *output){
    for (size_t i = 0; i < 7; i++)
    {
        output[i] = packOneByte(input[i], input[i+1], i);
    }
}

void unpackArray7Byte(uint8_t *input, uint8_t *output){

    for (size_t i = 0; i < 8; i++)
    {
        uint8_t msb_num = i % 8;
        uint8_t lsb_num = ENCODED_BIT_LEN - msb_num;
        uint8_t offset = 0;

        if (i == 0){
            output[i] |= extractFromLSB(input[i - offset], lsb_num) << msb_num;
        }
        else
        {
            if (msb_num == 0) offset++;
            output[i] |= extractFromLSB(input[i - offset], lsb_num) << msb_num;
            output[i] |= extractFromMSB(input[i - offset - 1], msb_num);
        }
    }
}

uint8_t packOneByte(uint8_t first, uint8_t second, uint8_t index){
    
    uint8_t retval = 0;

    /* turn inputs into 7-bit data */
    first = first & 0x7F;
    second = second & 0x7F;

    uint8_t shift_first = index % ENCODED_BIT_LEN;
    uint8_t shift_second = ENCODED_BIT_LEN - shift_first;

    /* put packet data */
    retval = (first >> shift_first) | (second << shift_second);

    return retval;
}

uint8_t extractFromMSB(uint8_t input, uint8_t num){
    return input >> (8 - num);
}

uint8_t extractFromLSB(uint8_t input, uint8_t num){
    uint8_t mask = 0xFF;
    return input & (~(mask << num));
}
