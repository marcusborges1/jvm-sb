#ifndef __ATTRIBUTE_INFO_H__
#define __ATTRIBUTE_INFO_H__

#include "JavaClassStructures.h"

void read_attributes(FILE *arquivo_class, JavaClass *class_struct);

void attribute_types_info(FILE *arquivo_class, JavaClass *class_struct,
                          AttributeInfo *attribute_struct);

void attribute_type_local_variable(FILE *arquivo_class,
                                  AttributeInfo *attribute_struct);

void attribute_type_line_number_table(FILE *arquivo_class,
                                      AttributeInfo *attribute_struct);

void attribute_type_inner_classes(FILE *arquivo_class,
                                  AttributeInfo *attribute_struct);

void attribute_type_exception(FILE *arquivo_class,
                            AttributeInfo *attribute_struct);

void attribute_type_code(FILE *arquivo_class, JavaClass *class_struct,
                        AttributeInfo *attribute_struct);

char* get_utf8_from_cp(CpInfo *cp, u2 info_index);

#endif //__ATTRIBUTE_INFO_H__
