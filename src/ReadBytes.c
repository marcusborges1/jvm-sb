#include "ReadBytes.h"

uint8_t read_1_byte(FILE* fp) {
  uint8_t bytes_read = getc(fp);
  return bytes_read;
}

uint16_t read_2_bytes(FILE* fp) {
  uint16_t bytes_read = getc(fp);
  bytes_read = (bytes_read << 8) | (getc(fp));
  return bytes_read;
}

uint32_t read_4_bytes(FILE* fp) {
  uint32_t bytes_read = getc(fp);
  bytes_read = (bytes_read << 8) | (getc(fp));
  bytes_read = (bytes_read << 8) | (getc(fp));
  bytes_read = (bytes_read << 8) | (getc(fp));
  return bytes_read;
}
