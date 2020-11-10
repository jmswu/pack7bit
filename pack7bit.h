#ifndef PACK7BIT_H_
#define PACK7BIT_H_

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* number of bit of the input data encoded in */
#define ENCODED_BIT_LEN         (7U)

/* \brief   Pack 7-bit data array into 8-bit data array
 * \param   uint8_t *input  - 7-bit coded input, must be 8 bytes long
 * \param   uint8_t *output - 8-bit coded output, must be 7 bytes long
 */
void packArray8Byte(uint8_t *input, uint8_t *output);

/* \brief   Unpack 8-bit data array into 7-bit data array
 * \param   uint8_t *input  - 8-bit coded input, must be 7 bytes long
 * \param   uint8_t *output - 7-bit coded output, must be 8 bytes long
 */
void unpackArray7Byte(uint8_t *input, uint8_t *output);




#endif