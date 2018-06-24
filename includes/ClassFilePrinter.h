#ifndef __CLASS_FILE_PRINTER_H__
#define __CLASS_FILE_PRINTER_H__

#include "JavaClassStructures.h"
#include <string.h>

void print_formatted_class_file(JavaClass* class_file);
void get_UTF8_constant_pool(CpInfo *cp_info, uint32_t pos_info);

#endif //__CLASS_FILE_PRINTER_H__
