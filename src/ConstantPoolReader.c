/** @file ConstantPoolReader.c
 *  @brief Leitor da estrutura "constant_pool" de um arquivo ".class".
 *  @bug No know bugs.
 */
#include "ConstantPoolReader.h"
#include "ReadBytes.h"

/** @brief Lê as constant_pools do arquivo .class na estrutura de dados
 *    do sistema.
 *  @param fp ...
 *  @param class_file ...
 *  @return void
 */
void read_constant_pool(FILE *fp, JavaClass* class_file) {
  class_file->contant_pool = (CpInfo*)malloc(
                          (class_file->constant_pool_count-1)*sizeof(CpInfo));
  int i;

  for (i = 0; i < class_file->constant_pool_count - 1; i++) {
    CpInfo *cp_info = class_file->contant_pool + i;

    cp_info->tag = read_1_byte(fp);
    switch (cp_info->tag) {
      case CONSTANT_Class:
        cp_info->Class.type_class_info = read_2_bytes(fp);
        break;
      case CONSTANT_Fieldref:
        cp_info->FieldRef.class_index = read_2_bytes(fp);
        cp_info->FieldRef.name_and_type_index = read_2_bytes(fp);
        break;
      case CONSTANT_Methodref:
        cp_info->MethodRef.index = read_2_bytes(fp);
        cp_info->MethodRef.name_and_type = read_2_bytes(fp);
        break;
      case CONSTANT_InterfaceMethodref:
        cp_info->InterfaceMethodRef.index = read_2_bytes(fp);
        cp_info->InterfaceMethodRef.name_and_type = read_2_bytes(fp);
        break;
      case CONSTANT_String:
        cp_info->String.bytes = read_2_bytes(fp);
        break;
      case CONSTANT_Integer:
        cp_info->Integer.bytes = read_4_bytes(fp);
        break;
      case CONSTANT_Float:
        cp_info->Float.bytes = read_4_bytes(fp);
        break;
      case CONSTANT_Long:
        cp_info->Long.high_bytes = read_4_bytes(fp);
        cp_info->Long.low_bytes = read_4_bytes(fp);
        i++;
        break;
      case CONSTANT_Double:
        cp_info->Double.high_bytes = read_4_bytes(fp);
        cp_info->Double.low_bytes = read_4_bytes(fp);
        i++;
        break;
      case CONSTANT_NameAndType:
        cp_info->NameAndType.name_index = read_2_bytes(fp);
        cp_info->NameAndType.descriptor_index = read_2_bytes(fp);
        break;
      case CONSTANT_Utf8:
        cp_info->UTF8.size = read_2_bytes(fp);
        cp_info->UTF8.bytes = (u1*) malloc((cp_info->UTF8.size+1)*sizeof(u1));
        fread(cp_info->UTF8.bytes, 1, cp_info->UTF8.size, fp);
        cp_info->UTF8.bytes[cp_info->UTF8.size] = '\0';
        break;
    }
  }
}
