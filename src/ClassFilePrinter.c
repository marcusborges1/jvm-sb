#include "ClassFilePrinter.h"
#include <string.h>

char * get_UTF8_constant_pool(CpInfo *cp_info, uint16_t pos_info) {
  static char string_value[10000];
  int tag = cp_info[pos_info].tag;

  switch (tag){
    case CONSTANT_Utf8:
      strcpy(string_value, (char*)cp_info[pos_info].UTF8.bytes);
      break;
    case CONSTANT_Class:
      strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].Class.type_class_info-1));
      break;
    case CONSTANT_Fieldref:
      strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].FieldRef.class_index-1));
      strcat(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].FieldRef.name_and_type_index-1));
      break;
    case CONSTANT_NameAndType:
      strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].NameAndType.name_index-1));
      strcat(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].NameAndType.descriptor_index-1));
      break;
    case CONSTANT_Methodref:
      strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].MethodRef.index-1));
      strcat(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].MethodRef.name_and_type-1));
      break;
    case CONSTANT_InterfaceMethodref:
      strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].InterfaceMethodRef.index-1));
      strcat(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].InterfaceMethodRef.name_and_type-1));
      break;
    case CONSTANT_String:
      strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].String.bytes-1));
      break;
    default:
      break;
  }
  return string_value;
}

void print_formatted_class_file(JavaClass* class_file) {
  printf("Magic Number: 0x%0X\n", class_file->magic_number);
  printf("Minor Version: %d\n", class_file->minor_version);
  printf("Major version: %d\n", class_file->major_version);
  printf("Contanst pool count: %d\n", class_file->constant_pool_count);
  printf("Interface count: %d\n", class_file->interface_count);
  printf("Field count: %d\n", class_file->field_count);
  printf("Methods count: %d\n", class_file->methods_count);
}

void print_menu_options() {
  printf("Opcoes:\n");
  printf("1 - Constant Pool\n");
  printf("2 - Interfaces\n");
  printf("3 - Fields\n");
  printf("4 - Methods\n");
  printf("-1 - Sair\n");
  printf(">> ");
}

void print_constant_pool_info(JavaClass* class_file) {
  float float_value;
  long long_value;
  double double_value;
  uint64_t aux;

  printf("\n\nConstant Pool Info: \n\n");
  for (int i = 0; i < class_file->constant_pool_count-1; i++) {
    CpInfo* cp_info = class_file->contant_pool+i;

    printf("count: %d - ", i + 1);
    switch (cp_info->tag) {
      case CONSTANT_Integer:
        printf("Integer: \n");
        printf("Valor: %d\n", cp_info->Integer.bytes);
        break;
      case CONSTANT_Float:
        memcpy(&float_value, &(cp_info->Float.bytes), sizeof(float));
        printf("Float: %lf\n", float_value);
        break;
      case CONSTANT_Long:
        printf("Long:\n");
        printf("\tHigh: 0x%0x\n", cp_info->Long.high_bytes);
        printf("\tLow: 0x%0x\n", cp_info->Long.low_bytes);
        memcpy(&long_value, &(cp_info->Long.high_bytes), sizeof(long));
        memcpy(&long_value, &(cp_info->Long.low_bytes), sizeof(long));
        printf("\tLong Value: %ld\n", long_value);
        break;
      case CONSTANT_Double:
        aux = ((uint64_t)cp_info->Double.high_bytes << 32 | cp_info->Double.low_bytes);
        memcpy(&double_value, &(aux), sizeof(double));
        printf("Double:\n");
        printf("\tHigh: 0x%0x\n", cp_info->Double.high_bytes);
        printf("\tLow: 0x%0x\n", cp_info->Double.low_bytes);
        printf("\tDouble Value: %lf\n", double_value);
        break;
      case CONSTANT_Utf8:
        printf("UTF8\n");
        printf("Tamanho: %d - ", cp_info->UTF8.size);
        printf("Valor: %s\n", cp_info->UTF8.bytes);
        break;
      case CONSTANT_String:
        printf("String\n");
        printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->String.bytes-1));
        break;
      case CONSTANT_Class :
        printf("Class\n");
        printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->Class.type_class_info-1));
        break;
      case CONSTANT_Fieldref:
        printf("FieldRef\n");
        printf("Class index: ");
        printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->FieldRef.class_index-1));
        printf("Name and Type: ");
        printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->FieldRef.name_and_type_index-1));
        break;
      case CONSTANT_Methodref:
        printf("MethodRef: \n");
        printf("Index: ");
        printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->MethodRef.index-1));
        printf("Name and Type: ");
        printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->MethodRef.name_and_type-1));
        break;
      case CONSTANT_InterfaceMethodref:
        printf("InterfaceMethodRef: \n");
        printf("Index: ");
        printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->InterfaceMethodRef.index-1));
        printf("Name and Type: ");
        printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->InterfaceMethodRef.name_and_type-1));
        break;
      case CONSTANT_NameAndType:
        printf("NameAndType: \n");
        printf("Name index: ");
        printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->NameAndType.name_index-1));
        printf("Descriptor index: ");
        printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->NameAndType.descriptor_index-1));
        break;
      case CONSTANT_EmptySpace:
        printf("(Large numeric continued)\n");
        break;
    }
    printf("\n");
  }
}

void print_interfaces_info(JavaClass* class_file){
    printf("\nInterfaces Info\n");

    for (int i = 0; i < class_file->interface_count; i++) {
        printf("Interface: cp info #%d <", class_file->interfaces[i]);
        printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, class_file->interfaces[i]-1));
        printf("\n");
    }
}

void print_info_on_screen(JavaClass* class_file) {
  int option = 0;

  printf("\n\nLeitor/Exibidor: \n");

  while(option != -1) {
    print_formatted_class_file(class_file);
    print_menu_options();
    scanf("%d", &option);

    switch (option) {
      case -1:
        option = -1;
        printf("Saindo do Leitor/Exibidor");
        break;
      case 1:
        print_constant_pool_info(class_file);
        break;
      case 2:
        print_interfaces_info(class_file);
        break;
    }

  }

}
