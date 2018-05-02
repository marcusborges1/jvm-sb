#ifndef __CONSTANT_POOL_H__
#define __CONSTANT_POOL_H__

#include "JavaClassStructures.h"

void read_constant_pool(FILE *fp, JavaClass* class_file);

#endif //__CONSTANT_POOL_H__
