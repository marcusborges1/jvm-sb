#include <iostream>
#include "FieldInfo.h"
#include "ReadBytes.h"


void FieldInfo::read(JavaClass class_file, FILE * fp) {
  AttributeInfo *attributeinfo = new AttributeInfo();
  for (int i = 0; i < class_file.fields_count; i++) {
    class_file.fields[i].access_flag = read_2_bytes(fp);
    class_file.fields[i].name_index = read_2_bytes(fp);
    class_file.fields[i].descriptor_index = read_2_bytes(fp);
    class_file.fields[i].atributes_count = read_2_bytes(fp);

    class_file.fields[i].attributes = (AttributeInfo*)malloc(class_file.fields[i].atributes_count*sizeof(AttributeInfo));
    for (int j = 0;  j < class_file.fields[i].atributes_count; j++)
        attributeinfo->get_attribute_info(fp, class_file.fields[i].attributes[j], class_file);
  }
}

void FieldInfo::print(JavaClass class_file) {
  CpInfo *cpinfo = new CpInfo();
  printf("\n----------------- Field Info:  ----------------------- \n");

  for (int i = 0; i < class_file.fields_count; i++){
      printf("Name: cp info #%d ", class_file.fields[i].name_index);
      printf("<<");

      std::cout << cpinfo->get_utf8_string(class_file.constant_pool, class_file.fields[i].name_index - 1);

      printf("Descriptor: cp info #%d ", class_file.fields[i].descriptor_index);
      std::cout << cpinfo->get_utf8_string(class_file.constant_pool, class_file.fields[i].descriptor_index - 1);

      printf("Access Flag: 0x%04x ", class_file.fields[i].access_flag);
      printf("%d\n", class_file.fields[i].access_flag);
  }

}
