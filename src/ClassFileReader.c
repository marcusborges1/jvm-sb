// #include "InterfaceReader.h"
// #include "FieldReader.h"
// #include "MethodReader.h"
#include "ConstantPoolReader.h"
#include "ClassFileReader.h"
#include "ReadBytes.h"


/*
 *  Checa se um .class é válido.
 *  Um .class válido deve conter um número hex mágico do tipo 0xCAFEBABE.
 *  @param magic_number ...
 *  @return ...
 */
bool check_valid_class_file(uint32_t magic_number) {
  return magic_number == 0xCAFEBABE;
}

/*
 *  Lê o arquivo .class.
 *  @param file_path ...
 *  @return ...
 */
JavaClass* read_class_file(char const* file_path) {
  // tenta abrir o arquivo .class
  FILE *file = fopen(file_path, "rb");

  // fecha o programa de leitor/exibidor caso o arquivo .class não exista
  if (file == NULL) {
    printf("File not found. Shutting down.\n");
    exit(1);
  }

  // aloca espaço na memória para informações a respeito do java .class
  JavaClass *class_file = (JavaClass *) malloc(sizeof(JavaClass));

  // realiza a leitura do número mágico que todo .class tem
  class_file->magic_number = read_4_bytes(file);

  // checa a validade deste número mágico em hexadecimal
  if (!check_valid_class_file(class_file->magic_number)) {
    // caso o .class for inválido então fecha o programa de leitor/exibido
    printf("ERROR: File .class invalid. Shutting down.\n");
    fclose(file);
    exit(1);
  }

  // realiza a leitura das versões no formato major.minor
  class_file->minor_version = read_2_bytes(file);
  class_file->major_version = read_2_bytes(file);

  // lê quantos constat_pool existem neste arquivo
  class_file->constant_pool_count = read_2_bytes(file);
  // lê as constant_pools do .class
  read_constant_pool(file, class_file);

  // class_file->access_flags = read_2_bytes(file);
  // class_file->this_class = read_2_bytes(file);
  // class_file->super_class = read_2_bytes(file);

  // class_file->interface_count = read_2_bytes(file);
  // read_interface(file, class_file);

  // class_file->field_count = read_2_bytes(file);
  // read_field(file, class_file);

  // class_file->methods_count = read_2_bytes(file);
  // read_methods(file, class_file);

  // fecha o arquivo .class que estava sendo lido
  fclose(file);

  return class_file;
}
