/** @file ReadBytes.h
 *  @brief Protótipos das funções do leitor de bytes de um arquivo ".class".
 */
#ifndef __READ_BYTES_H__
#define __READ_BYTES_H__

#include <stdio.h>
#include <stdint.h>

uint8_t read_1_byte(FILE* fp);
uint16_t read_2_bytes(FILE* fp);
uint32_t read_4_bytes(FILE* fp);

#endif
