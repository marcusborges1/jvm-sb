/** @file ClassFileReader.h
 *  @brief Protótipos das funções de impressão da interface do sistema e
 *    exibidor do arquivo ".class".
 */
#ifndef __CLASS_FILE_PRINTER_H__
#define __CLASS_FILE_PRINTER_H__

#include "JavaClassStructures.h"

char* print_menu_choose_type_file();

void print_general_info(JavaClass* class_file, char *filename);

void print_menu_exhibitor(JavaClass* class_file);

void print_constant_pool_info(JavaClass* class_file);

void print_interfaces_info(JavaClass* class_file);

void get_UTF8_constant_pool(CpInfo *cp_info, u4 pos_info);

#endif
