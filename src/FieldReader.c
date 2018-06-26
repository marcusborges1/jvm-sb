#include "FieldReader.h"
#include "AttributeInfoReader.h"
#include "ReadBytes.h"

void read_field(FILE *fp, JavaClass* class_file) {
  int i, j;
  int fields_count = class_file->field_count;

  if (class_file->field_count == 0) {
    return;
  }

  class_file->fields = (FieldInfo *) malloc(sizeof(FieldInfo) * fields_count);
  for (i = 0; i < fields_count; i++) {
    class_file->fields[i].access_flag = read_2_bytes(fp);
    class_file->fields[i].name_index = read_2_bytes(fp);
    class_file->fields[i].descriptor_index = read_2_bytes(fp);
    class_file->fields[i].atributes_count = read_2_bytes(fp);
    class_file->fields[i].attributes = (AttributeInfo *) malloc(sizeof(AttributeInfo) * class_file->fields[i].atributes_count);

    for (j = 0; j < class_file->fields[i].atributes_count; j++) {
      class_file->fields[i].attributes->attribute_name_index = read_2_bytes(fp);
      class_file->fields[i].attributes->attribute_length = read_4_bytes(fp);
      class_file->fields[i].attributes->constant_value->value_index = read_2_bytes(fp);
    }
  }
}
