/** @file ClassFileReader.h
 *  @brief Protótipos das funções de leitura do arquivo ".class".
 */
#ifndef __CLASS_FILE_READER_H__
#define __CLASS_FILE_READER_H__

#include "JavaClassStructures.h"
#include <stdbool.h>

bool check_valid_class_file(uint32_t magic_number);
JavaClass* read_class_file(char const* file_path);

#endif
