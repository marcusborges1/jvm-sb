#include <cstdlib>
#include <iostream>
#include <cstring>
#include "ReadBytes.h"
#include "CpInfo.h"

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
              class_file.constant_pool[i].UTF8.bytes = (u1*) calloc((class_file.constant_pool[i].UTF8.size) +1, sizeof(u1));
              fread(class_file.constant_pool[i].UTF8.bytes, 1, class_file.constant_pool[i].UTF8.size, fp);
              class_file.constant_pool[i].UTF8.bytes[class_file.constant_pool[i].UTF8.size] = '\0';
              break;
        }
    }
};
