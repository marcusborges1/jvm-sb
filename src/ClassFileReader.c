#include "../includes/JavaClassStructures.h"

JavaClass* read_class_file(char const* file_path);
void read_constant_pool(FILE *fp, JavaClass* class_file);

uint8_t read_1_byte(FILE* fp);
uint16_t read_2_bytes(FILE* fp);
uint32_t read_4_bytes(FILE* fp);

int main(int argc, char const *argv[]) {
  read_class_file(argv[1]);
  return 0;
}

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

  printf("Magic Number: 0x%0X\n", class_file->magic_number);
  printf("Minor Version: %d\n", class_file->minor_version);
  printf("Major version: %d\n", class_file->major_version);
  printf("Contanst pool count: %d\n", class_file->constant_pool_count);
}

void read_constant_pool(FILE *fp, JavaClass* class_file) {
  class_file->contant_pool = (CpInfo *) malloc((class_file->constant_pool_count - 1) * sizeof(CpInfo));
  int i;

  for (i = 0; i < class_file->constant_pool_count - 1; i++) {
    CpInfo *cp_info = class_file->contant_pool + i;
    cp_info->tag = read_1_byte(fp);

    switch (cp_info->tag) {
      case CONSTANT_Class:
        cp_info->Class.type_class_info = read_2_bytes(fp);
        break;
      case CONSTANT_Fieldref:
        cp_info->FieldRef.class_index = read_2_bytes(fp);
        cp_info->FieldRef.name_and_type_index = read_2_bytes(fp);
        break;
      case CONSTANT_Methodref:
        cp_info->MethodRef.index = read_2_bytes(fp);
        cp_info->MethodRef.name_and_type = read_2_bytes(fp);
        break;
      case CONSTANT_InterfaceMethodref:
        cp_info->InterfaceMethodRef.index = read_2_bytes(fp);
        cp_info->InterfaceMethodRef.name_and_type = read_2_bytes(fp);
        break;
      case CONSTANT_String:
        cp_info->String.bytes = read_2_bytes(fp);
        break;
      case CONSTANT_Integer:
        cp_info->Integer.bytes = read_4_bytes(fp);
        break;
      case CONSTANT_Float:
        cp_info->Float.bytes = read_4_bytes(fp);
        break;
      case CONSTANT_Long:
        cp_info->Long.high_bytes = read_4_bytes(fp);
        cp_info->Long.low_bytes = read_4_bytes(fp);
        break;
      case CONSTANT_Double:
        cp_info->Double.high_bytes = read_4_bytes(fp);
        cp_info->Double.low_bytes = read_4_bytes(fp);
        break;
      case CONSTANT_NameAndType:
        cp_info->NameAndType.name_index = read_2_bytes(fp);
        cp_info->NameAndType.descriptor_index = read_2_bytes(fp);
        break;
      case CONSTANT_Utf8:
        cp_info->UTF8.size = read_2_bytes(fp);
        cp_info->UTF8.bytes = (uint8_t *) malloc((cp_info->UTF8.size + 1) * sizeof(uint8_t));
        fread(cp_info->UTF8.bytes, 1, cp_info->UTF8.size, fp);
        cp_info->UTF8.bytes[cp_info->UTF8.size] = '\0';
    }
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
