#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

typedef struct {
  uint32_t 	magic_number;
  uint16_t  minor_version;
  uint16_t  major_version;
} JavaClass;
