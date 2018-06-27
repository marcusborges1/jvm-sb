#include "FieldReader.h"
#include "AttributeInfoReader.h"
#include "ReadBytes.h"

/*  @brief Lê os métodos contidos no .class e os atributos desses métodos
 *  @param fp ponteiro pro arquivo .class
 *  @param class_file estrutura de dados do .class
 *  @return void
 */
// void read_methods(FILE* fp, JavaClass* class_file) {
//   u2 name_index;
//   u4 attributes_count;
//   u8 temp_attribute, temp_method_length;
//   int i, j, k;
//
//   // Se a existir métodos no Classfile, senão não faz nada
//   if (class_file->methods_count != 0) {
//     class_file->methods = (MethodInfo *) malloc(class_file->methods_count * sizeof(MethodInfo));
//     MethodInfo * method_info = class_file->methods;
//
//     for (i = 0; i < class_file->methods_count; method_info++, i++) {
//       method_info->access_flags = read_2_bytes(fp);
//       method_info->name_index = read_2_bytes(fp);
//       method_info->descriptor_index = read_2_bytes(fp);
//       method_info->attributes_count = read_2_bytes(fp);
//
//       for (j = 0; j < method_info->attributes_count; j++) {
//         name_index = read_2_bytes(fp);
//         attributes_count = read_4_bytes(fp);
//
//         if (strcmp((char *) class_file->constant_pool[name_index - 1].UTF8.bytes, "Code") == 0) {
//           method_info->code_attributes = (CodeAttribute *) malloc(sizeof(CodeAttribute));
//           read_code_attributes(fp, &(method_info->code_attributes), name_index, attributes_count);
//         } else if (strcmp((char *) class_file->constant_pool[name_index - 1].UTF8.bytes, "Exceptions") == 0) {
//           method_info->exceptions_attributes = (ExceptionsAttribute *) malloc(sizeof(ExceptionsAttribute));
//           read_exception_attributes(fp, &(method_info->code_attributes), name_index, attributes_count);
//         }
//       }
//     }
//   }
// }

/*  @brief Lê o código (mnemônicos) de um método e os armazena nas devidas
 *  posições da estrutura CodeAttribute.
 *
 *  @param fp ponteiro pro arquivo .class aberto para leitura
 *  @param code_attributes pointeiro para uma estrurua CodeAttribute
 *  @param name_index do método cujas instruções serão lidas
 *  @param attributes_count quantidade de atributos do método
 *  @return void
 */
// void read_code_attributes(FILE* fp, CodeAttribute** code_attributes, u2 name_index, u4 attributes_count) {
//     int current_file_position = (int) ftell(fp);
//
//     (*ccode_attributes)->attribute_name_index = name_index;
//     (*code_attributes)->attribute_length = attributes_count;
//     (*code_attributes)->max_stack = read_2_bytes(fp);
//     (*code_attributes)->max_locals = read_2_bytes(fp);
//     (*code_attributes)->code_length = le4Bytes(fp);
//
//
//     (*code_attributes)->exceptions_table_length = le2Bytes(fp);
//     (*code_attributes)->exceptions = (ExceptionTable*) malloc((*code_attributes)->exceptions_table_length * sizeof(ExceptionTable));
//     for (i = 0; i < (*code_attributes)->exceptions_table_length; i++) {
//         (*code_attributes)->exception_table[i].start_pc = read_2_bytes(fp);
//         (*code_attributes)->exception_table[i].end_pc = read_2_bytes(fp);
//         (*code_attributes)->exception_table[i].catch_type = read_2_bytes(fp);
//     }
//
//     (*code_attributes)->attributes_count = le2Bytes(fp);
//     (*code_attributes)->attributes = (AttributeInfo*) malloc ((*code_attributes)->attributes_count * sizeof(AttributeInfo));
//
//     while (ftell(fp) - current_file_position < (u4)((*code_attributes)->attribute_length))
//       read_1_byte(fp);
// }
