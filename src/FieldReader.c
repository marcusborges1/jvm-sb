#include "FieldReader.h"
#include "ReadBytes.h"

void read_field(FILE *fp, JavaClass* class_file) {
  class_file->fields = (FieldInfo*)malloc(class_file->field_count * sizeof(FieldInfo));

  for (int j = 0; j < class_file->field_count; j++) {
      FieldInfo *field = class_file->fields + j;

      field->access_flag = read_2_bytes(file);
      field->name_index = read_2_bytes(file);
      field->descriptor_index = read_2_bytes(file);
      field->atributes_count = read_2_bytes(file);

      field->attributes = (AttributeInfo*)malloc(field->atributes_count*sizeof(AttributeInfo));
      for (int i = 0; i < field->atributes_count; ++i) {
          attributeInfoReader(file, class_file, field->attributes + i);
      }
  }
}
