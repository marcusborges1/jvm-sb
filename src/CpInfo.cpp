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

std::string CpInfo::get_utf8_string(CpInfo* cp_info, u2 index) {
    std::string string;
    int tag = cp_info[index].tag;
    switch (tag){
        case CONSTANT_Utf8:
            string = (char*)cp_info[index].UTF8.bytes;
            break;
        case CONSTANT_Class:
            string = CpInfo::get_utf8_string(cp_info, cp_info[index].Class.type_class_info-1);
            break;
        case CONSTANT_Fieldref:
            string = CpInfo::get_utf8_string(cp_info, cp_info[index].FieldRef.class_index-1);
            string += CpInfo::get_utf8_string(cp_info, cp_info[index].FieldRef.name_and_type_index-1);
            break;
        case CONSTANT_NameAndType:
            string = CpInfo::get_utf8_string(cp_info, cp_info[index].NameAndType.name_index-1);
            string += CpInfo::get_utf8_string(cp_info, cp_info[index].NameAndType.descriptor_index-1);
            break;
        case CONSTANT_Methodref:
            string = CpInfo::get_utf8_string(cp_info, cp_info[index].MethodRef.index-1);
            string += CpInfo::get_utf8_string(cp_info, cp_info[index].MethodRef.name_and_type-1);
            break;
        case CONSTANT_InterfaceMethodref:
            string = CpInfo::get_utf8_string(cp_info, cp_info[index].InterfaceMethodRef.index-1);
            string += CpInfo::get_utf8_string(cp_info, cp_info[index].InterfaceMethodRef.name_and_type-1);
            break;
        case CONSTANT_String:
            string = CpInfo::get_utf8_string(cp_info, cp_info[index].String.bytes-1);
            break;
        default:
            return "";
            break;
    }
    return string;
}

void CpInfo::print(JavaClass class_file){
    printf("constant pool size: %d", class_file.constant_pool_count);
    printf("\n\n----------------- Constant Pool Info:  -------------------- \n\n");
    for (int i = 0; i < class_file.constant_pool_count - 1; i++) {
        printf("cp info #%d\n", i);

        switch (class_file.constant_pool[i].tag){
            case CONSTANT_Integer:
                printf("CONSTANT_Integer_info:\n");
                printf("Valor: %d", class_file.constant_pool[i].Integer.bytes);
                break;
            case CONSTANT_Float :
                printf("CONSTANT_Float_info:\n");
                float valorFloat;
                memcpy(&valorFloat, &(class_file.constant_pool[i].Float.bytes), sizeof(float));
                printf("Float: %lf \n", valorFloat);
                break;
            case CONSTANT_Long :
                printf("CONSTANT_Long_info:\n");
                printf("  High: 0x%0x \n", class_file.constant_pool[i].Long.high_bytes);
                printf("  Low: 0x%0x \n", class_file.constant_pool[i].Long.low_bytes);
                long readedLongValue;
                memcpy(&readedLongValue, &(class_file.constant_pool[i].Long.high_bytes), sizeof(long));
                memcpy(&readedLongValue, &(class_file.constant_pool[i].Long.low_bytes), sizeof(long));
                printf("  Long value: %ld", readedLongValue);
                break;
            case CONSTANT_Double:
                printf("CONSTANT_Double_info:\n");
                printf("  High: 0x%0x \n", class_file.constant_pool[i].Double.high_bytes);
                printf("  Low: 0x%0x \n", class_file.constant_pool[i].Double.low_bytes);
                double readedDoubleValue;
                uint64_t aux;
                aux = ((uint64_t)class_file.constant_pool[i].Double.high_bytes << 32) | class_file.constant_pool[i].Double.low_bytes;
                memcpy(&readedDoubleValue, &(aux), sizeof(double));
                std::cout << "Double value: "<< readedDoubleValue << std::endl;
                break;
            case CONSTANT_Utf8:
                printf("CONSTANT_UTF8_info:\n");
                printf("Tamanho: %d - ", class_file.constant_pool[i].UTF8.size);
                printf("Valor: %s\n", class_file.constant_pool[i].UTF8.bytes);
                break;
            case CONSTANT_String:
                printf("CONSTANT_String_info:\n");
                std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.constant_pool[i].String.bytes -1) << std::endl;
                break;
            case CONSTANT_Class :
                printf("CONSTANT_Class_info:\n");
                std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.constant_pool[i].Class.type_class_info-1) << std::endl;
                break;
            case CONSTANT_Fieldref:
                printf("CONSTANT_Fieldref_info:\n");
                printf("Class index: ");
                std::cout << CpInfo::get_utf8_string(class_file.constant_pool,class_file.constant_pool[i].FieldRef.class_index-1) << std::endl;
                printf("Name and Type: ");
                std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.constant_pool[i].FieldRef.name_and_type_index-1) << std::endl;
                break;
            case CONSTANT_Methodref:
                printf("CONSTANT_Methodref_info:\n");
                printf("Index: ");
                std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.constant_pool[i].MethodRef.index-1) << std::endl;

                printf("Name and Type: ");
                std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.constant_pool[i].MethodRef.name_and_type-1) << std::endl;
                break;
            case CONSTANT_InterfaceMethodref:
                printf("CONSTANT_InterfaceMethodRef_info:\n");
                printf("Index: ");
                std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.constant_pool[i].InterfaceMethodRef.index-1) << std::endl;

                printf("Name and Type: ");
                std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.constant_pool[i].InterfaceMethodRef.name_and_type-1) << std::endl;
                break;
            case CONSTANT_NameAndType:
                printf("CONSTANT_NameAndType_info:\n");
                printf("Name index: ");
                std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.constant_pool[i].NameAndType.name_index-1) << std::endl;

                printf("Descriptor index: ");
                std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.constant_pool[i].NameAndType.descriptor_index-1) << std::endl;
                break;
            case CONSTANT_EmptySpace:
                printf("(Large numeric continued)\n");
                break;
        }
        printf("\n----------------------------\n");
    }
}
