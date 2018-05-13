#include "FieldReader.h"
#include "AttributeReader.h"
#include "ReadBytes.h"

void read_field(FILE *fp, JavaClass* class_file) {
  class_file->fields = (FieldInfo*)malloc(class_file->field_count * sizeof(FieldInfo));

  for (int j = 0; j < class_file->field_count; j++) {
      FieldInfo *field = class_file->fields + j;

      field->access_flag = read_2_bytes(fp);
      field->name_index = read_2_bytes(fp);
      field->descriptor_index = read_2_bytes(fp);
      field->atributes_count = read_2_bytes(fp);

      field->attributes = (AttributeInfo*)malloc(field->atributes_count*sizeof(AttributeInfo));
      for (int i = 0; i < field->atributes_count; ++i)
          attribute_types_info(fp, class_file, field->attributes + i);
  }
}
