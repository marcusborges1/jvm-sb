/** @file ReadBytes.h
 *  @brief ...
 */
#ifndef READ_BYTES_H
#define READ_BYTES_H

/** @cond */
#include <cstdint>
#include <iostream>
/** @endcond */

uint8_t read_1_byte(FILE* fp);
uint16_t read_2_bytes(FILE* fp);
uint32_t read_4_bytes(FILE* fp);

#endif
