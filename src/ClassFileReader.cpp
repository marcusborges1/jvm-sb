/** @file ClassFileReader.cpp
 *  @brief Funções de leitura do arquivo ".class".
 *  @bug No know bugs.
 */
#include <iostream>
#include "ClassFileReader.h"
#include "ReadBytes.h"


/** @brief Faz a leitura sequencial do arquivo .Class indicado pelo parâmetro filename.
*  @param filename ...
*  @return JavaClass ...
*/
JavaClass ClassFileReader::read_class_file(std::string filename) {
    // tenta abrir o arquivo .class
    FILE *file = fopen(filename.c_str(), "rb");

    // fecha o programa de leitor/exibidor caso o arquivo .class não exista
    if (file == NULL) {
        printf("File not found. Shutting down.\n");
        exit(1);
    }

    JavaClass class_file;

    class_file.magic_number = read_4_bytes(file);
    // realiza a leitura das versões no formato major.minor
    class_file.minor_version =  read_2_bytes(file);
    class_file.major_version = read_2_bytes(file);

    class_file.constant_pool_count = read_2_bytes(file); // lê quantos constat_pool existem neste arquivo
    class_file.constant_pool = (CpInfo*)malloc((class_file.constant_pool_count-1)*sizeof(CpInfo));
    cpinfo->read(file, class_file);

    class_file.access_flags = read_2_bytes(file);
    class_file.this_class = read_2_bytes(file);
    class_file.super_class = read_2_bytes(file);

    class_file.interfaces_count = read_2_bytes(file);
    // class_file.interfaces = (InterfaceInfo*)malloc(class_file.interfaces_count * sizeof(InterfaceInfo));
    class_file.interfaces = (u2*)malloc(class_file.interfaces_count * sizeof(u2));
    read_interfaces(class_file, file);
    // interface_info->read(class_file, file);

    class_file.fields_count = read_2_bytes(file);
    class_file.fields = (FieldInfo*)malloc(class_file.fields_count * sizeof(FieldInfo));
    field_info->read(class_file, file);

    class_file.methods_count = read_2_bytes(file);
    class_file.methods = (MethodInfo*) malloc(class_file.methods_count * sizeof(MethodInfo));
    method_info->read(class_file, file);

    class_file.attributes_count = read_2_bytes(file);
    class_file.attributes = (AttributeInfo*)malloc(class_file.attributes_count * sizeof(AttributeInfo));
    attribute_info->read(class_file, file);

    return class_file;
}



/////tirar isso daqui quando arrumar o bug, ele ja existe no InterfacesInfo.cpp
void ClassFileReader::read_interfaces(JavaClass class_file, FILE* file){
  for (int i = 0; i < class_file.interfaces_count; i++)
      class_file.interfaces[i] = read_2_bytes(file);
}


