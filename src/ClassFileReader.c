/*
 *  Universidade de Brasília
 *  Instituto de Ciencias Exatas
 *  Departamento de Ciência da Computação
 *
 *  Software Básico - Turma A - 1/2018
 *
 *  Projeto JVM
 *
 *  Grupo ?:
 *      - Dayanne Fernandes da Cunha    13/0107191
 *      - Laís Mendes Gonçalves         11/0033647
 *
 *  Arquivo fonte principal "ClassFileReader.c"
 *  Executar com : make
 *
 *  Copyright © 2018 UnB. All rights reserved.
 */

#include "ConstantPoolReader.h"
#include "InterfaceReader.h"
#include "FieldReader.h"
#include "MethodReader.h"
#include "ReadBytes.h"

void read_class_file(char const* file_path);

int main(int argc, char const *argv[]) {
  read_class_file(argv[1]);
  return 0;
}

void read_class_file(char const* file_path) {
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

  printf("Magic Number: 0x%0X\n", class_file->magic_number);
  printf("Minor Version: %d\n", class_file->minor_version);
  printf("Major version: %d\n", class_file->major_version);
  printf("Contanst pool count: %d\n", class_file->constant_pool_count);
  printf("Interface count: %d\n", class_file->interface_count);
  printf("Field count: %d\n", class_file->field_count);
  printf("Methods count: %d\n", class_file->methods_count);

  fclose(file);
}
