/** @file ReadBytes.c
 *  @brief Leitor de bytes de um arquivo ".class".
 *  @bug No know bugs.
 */
#include "ReadBytes.h"


/** @brief Lê 1 byte.
 *  @param fp ...
 *  @return uint8_t ...
 */
uint8_t read_1_byte(FILE* fp) {
  uint8_t bytes_read = getc(fp);
  return bytes_read;
}

/** @brief Lê 2 bytes.
 *  @param fp ...
 *  @return uint16_t ...
 */
uint16_t read_2_bytes(FILE* fp) {
  uint16_t bytes_read = getc(fp);
  bytes_read = (bytes_read << 8) | (getc(fp));
  return bytes_read;
}

/** @brief Lê 4 bytes.
 *  @param fp ...
 *  @return uint32_t ...
 */
uint32_t read_4_bytes(FILE* fp) {
  uint32_t bytes_read = getc(fp);
  bytes_read = (bytes_read << 8) | (getc(fp));
  bytes_read = (bytes_read << 8) | (getc(fp));
  bytes_read = (bytes_read << 8) | (getc(fp));
  return bytes_read;
}
