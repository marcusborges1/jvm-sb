#ifndef __CONSTANT_POOL_H__
#define __CONSTANT_POOL_H__

#include "JavaClassStructures.h"

uint8_t read_1_byte(FILE* fp);
uint16_t read_2_bytes(FILE* fp);
uint32_t read_4_bytes(FILE* fp);

void read_constant_pool(FILE *fp, JavaClass* class_file);

#endif //__CONSTANT_POOL_H__
