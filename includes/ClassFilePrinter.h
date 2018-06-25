#ifndef __CLASS_FILE_PRINTER_H__
#define __CLASS_FILE_PRINTER_H__

#include "JavaClassStructures.h"

char* print_menu_choose_type_file();

void print_general_info(JavaClass* class_file, char *filename);

void print_menu_exhibitor(JavaClass* class_file);

void print_constant_pool_info(JavaClass* class_file);

void get_UTF8_constant_pool(CpInfo *cp_info, u4 pos_info);

// void print_interfaces_info(JavaClass* class_file);
//
// void print_fields_info(JavaClass* class_file);
//
// char *test_methods_flags(u2 access_flag);
//
// void print_methods_info(JavaClass* class_file);
//
// void print_attributes_on_screen(JavaClass* class_file, AttributeInfo* info);


#endif //__CLASS_FILE_PRINTER_H__
