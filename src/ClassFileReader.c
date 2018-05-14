#include "ConstantPoolReader.h"
#include "InterfaceReader.h"
#include "FieldReader.h"
#include "MethodReader.h"
#include "ReadBytes.h"

JavaClass* read_class_file(char const* file_path) {
  FILE *file = fopen(file_path, "rb");

  if (file == NULL) {
    printf("File not found. Shutting down.\n");
    exit(1);
  }

  JavaClass *class_file = (JavaClass *) malloc(sizeof(JavaClass));
  class_file->magic_number = read_4_bytes(file);
  class_file->minor_version = read_2_bytes(file);
  class_file->major_version = read_2_bytes(file);

  class_file->constant_pool_count = read_2_bytes(file);
  read_constant_pool(file, class_file);

  class_file->access_flags = read_2_bytes(file);
  class_file->this_class = read_2_bytes(file);
  class_file->super_class = read_2_bytes(file);

  class_file->interface_count = read_2_bytes(file);
  read_interface(file, class_file);

  class_file->field_count = read_2_bytes(file);
  read_field(file, class_file);

  class_file->methods_count = read_2_bytes(file);
  read_methods(file, class_file);

  fclose(file);

  return class_file;
}
