#include "FieldReader.h"
#include "AttributeInfoReader.h"
#include "ReadBytes.h"

void read_methods(FILE* fp, JavaClass* class_file){
  class_file->methods = (MethodInfo*) malloc(class_file->methods_count * sizeof(MethodInfo));

  for(int i = 0; i < class_file->methods_count; i++){
    MethodInfo *method = class_file->methods + i;

    method->access_flag = read_2_bytes(fp);
    method->name_index = read_2_bytes(fp);
    method->descriptor_index = read_2_bytes(fp);
    method->attributes_count = read_2_bytes(fp);

    method->attributes = (AttributeInfo*)malloc(method->attributes_count * sizeof(AttributeInfo));
    for (int j = 0; j < method->attributes_count; j++)
        read_attribute_info(fp, class_file, method->attributes + j);
  }

}
