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

void read_class_file(char const* file_path);
void read_interfaces(FILE *fp, JavaClass* class_file);

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
  class_file->interfaces_count = read_2_bytes(file);
  read_interfaces(file, class_file);

  printf("Magic Number: 0x%0X\n", class_file->magic_number);
  printf("Minor Version: %d\n", class_file->minor_version);
  printf("Major version: %d\n", class_file->major_version);
  printf("Contanst pool count: %d\n", class_file->constant_pool_count);

  fclose(file);
}

void read_interfaces(FILE *fp, JavaClass* class_file) {
  class_file->interfaces = (uint16_t*) malloc(class_file->interfaces_count * sizeof(uint16_t));
  for (size_t i = 0; i < class_file->interfaces_count; i++) {
    class_file->interfaces[i] = read_2_bytes(fp);
  }
}

uint8_t read_1_byte(FILE* fp) {
  uint8_t bytes_read = getc(fp);
  return bytes_read;
}

uint16_t read_2_bytes(FILE* fp) {
  uint16_t bytes_read = getc(fp);
  bytes_read = (bytes_read << 8) | (getc(fp));
  return bytes_read;
}

uint32_t read_4_bytes(FILE* fp) {
  uint32_t bytes_read = getc(fp);
  bytes_read = (bytes_read << 8) | (getc(fp));
  bytes_read = (bytes_read << 8) | (getc(fp));
  bytes_read = (bytes_read << 8) | (getc(fp));
  return bytes_read;
}
