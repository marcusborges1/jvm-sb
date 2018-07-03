#include "stdlib.h"
#include "stdio.h"
#include <stdint.h>
#include <string.h>
#include <inttypes.h>


int main(int argc, char const *argv[]) {

  float f = 0;
  uint32_t fbits = 0x4426AAA0;

  memcpy(&f, &fbits, sizeof(f));
  printf("%f\n", f);
  return 0;
}
