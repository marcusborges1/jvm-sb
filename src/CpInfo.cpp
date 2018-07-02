/** @file CpInfo.cpp
 *  @brief ...
 *  @bug No know bugs.
 */
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "ReadBytes.h"
#include "CpInfo.h"


/** @brief ...
*  @param fp ...
*  @param class_file ...
*  @return void
*/
void CpInfo::read(FILE * fp, JavaClass class_file) {
    for (int i = 0; i < class_file.constant_pool_count -1  ; i++) {
      class_file.constant_pool[i].tag = read_1_byte(fp);

      switch (class_file.constant_pool[i].tag) {
          case CONSTANT_Class:
              class_file.constant_pool[i].Class.type_class_info = read_2_bytes(fp);
              break;
          case CONSTANT_Fieldref:
              class_file.constant_pool[i].FieldRef.class_index = read_2_bytes(fp);
              class_file.constant_pool[i].FieldRef.name_and_type_index = read_2_bytes(fp);
              break;
          case CONSTANT_Methodref:
              class_file.constant_pool[i].MethodRef.index = read_2_bytes(fp);
              class_file.constant_pool[i].MethodRef.name_and_type = read_2_bytes(fp);
              break;
          case CONSTANT_InterfaceMethodref:
              class_file.constant_pool[i].InterfaceMethodRef.index = read_2_bytes(fp);
              class_file.constant_pool[i].InterfaceMethodRef.name_and_type = read_2_bytes(fp);
              break;
          case CONSTANT_String:
              class_file.constant_pool[i].String.bytes = read_2_bytes(fp);
              break;
          case CONSTANT_Integer:
              class_file.constant_pool[i].Integer.bytes = read_4_bytes(fp);
              break;
          case CONSTANT_Float:
              class_file.constant_pool[i].Float.bytes = read_4_bytes(fp);
              break;
          case CONSTANT_Long:
              class_file.constant_pool[i].Long.high_bytes = read_4_bytes(fp);
              class_file.constant_pool[i].Long.low_bytes = read_4_bytes(fp);
              i++;
              break;
          case CONSTANT_Double:
              class_file.constant_pool[i].Double.high_bytes = read_4_bytes(fp);
              class_file.constant_pool[i].Double.low_bytes = read_4_bytes(fp);
              i++;
              break;
          case CONSTANT_NameAndType:
              class_file.constant_pool[i].NameAndType.name_index = read_2_bytes(fp);
              class_file.constant_pool[i].NameAndType.descriptor_index = read_2_bytes(fp);
              break;
          case CONSTANT_Utf8:
              class_file.constant_pool[i].UTF8.size = read_2_bytes(fp);
              class_file.constant_pool[i].UTF8.bytes = (u1*) calloc(
                      (class_file.constant_pool[i].UTF8.size) +1, sizeof(u1));
              fread(class_file.constant_pool[i].UTF8.bytes, 1,
                    class_file.constant_pool[i].UTF8.size, fp);
              class_file.constant_pool[i].UTF8.bytes[
                                  class_file.constant_pool[i].UTF8.size] = '\0';
              break;
        }
    }
};

/** @brief Mostra nome no formato UTF8.
 *  @param cp_info ...
 *  @param pos_info ...
 *  @return ...
 */
std::string CpInfo::get_utf8_constant_pool(CpInfo *cp_info, u2 pos_info) {
  std::string utf8_const;
  u2 tag = cp_info[pos_info].tag;

  switch (tag) {
    // caso tag seja 1
    case CONSTANT_Utf8:
      // representa valores strings constantes, inclusive unicode
      // UTF8.length indica o número de bytes no array bytes
      // UTF8.bytes contêm os bytes da string
      // @TODO checar se nenhum byte tem valor 0 ou está no intervalo
      //  0xf0 ou 0xff, i.e. [240, 255]
      utf8_const = (char*)cp_info[pos_info].UTF8.bytes;
      break;
    case CONSTANT_Class:
      utf8_const = get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].Class.type_class_info - 1);
      break;
    case CONSTANT_Fieldref:
      utf8_const = get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].FieldRef.class_index-1);
      utf8_const += get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].FieldRef.name_and_type_index-1);
      break;
    // caso tag seja 12
    case CONSTANT_NameAndType:
      // representa um nome simples de field ou método ou ainda o nome do
      // método especial <init>
      utf8_const = get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].NameAndType.name_index-1);
      // representa um descritor válido de field ou de método
      utf8_const += get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].NameAndType.descriptor_index-1);
      break;
    case CONSTANT_Methodref:
      utf8_const = get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].MethodRef.index-1);
      utf8_const += get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].MethodRef.name_and_type-1);
      break;
    case CONSTANT_InterfaceMethodref:
      utf8_const = get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].InterfaceMethodRef.index-1);
      utf8_const += get_utf8_constant_pool(cp_info,
                        cp_info[pos_info].InterfaceMethodRef.name_and_type-1);
      break;
    case CONSTANT_String:
      utf8_const += get_utf8_constant_pool(cp_info,
                                          cp_info[pos_info].String.bytes-1);
      break;
    default:
      printf("Tag %d. Wrong tag number. Shutting down.\n", tag);
      exit(1);
  }
  return utf8_const;
}
