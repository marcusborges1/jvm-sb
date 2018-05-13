#ifndef __ATTRIBUTE_INFO_H__
#define __ATTRIBUTE_INFO_H__

#include "JavaClassStructures.h"

void read_attribute_info(FILE *fp, JavaClass* class_file,
												AttributeInfo *attributes);

#endif //__ATTRIBUTE_INFO_H__
