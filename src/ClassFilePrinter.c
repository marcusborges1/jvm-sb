#include "ClassFilePrinter.h"

void print_formatted_class_file(JavaClass* class_file) {
  printf("Magic Number: 0x%0X\n", class_file->magic_number);
  printf("Minor Version: %d\n", class_file->minor_version);
  printf("Major version: %d\n", class_file->major_version);
  printf("Contanst pool count: %d\n", class_file->constant_pool_count);
  printf("Interface count: %d\n", class_file->interface_count);
  printf("Field count: %d\n", class_file->field_count);
  printf("Methods count: %d\n", class_file->methods_count);
}
