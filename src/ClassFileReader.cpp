/** @file ClassFileReader.cpp
 *  @brief Funções de leitura do arquivo ".class".
 *  @bug No know bugs.
 */
/** @cond */
#include <iostream>
/** @endcond */
#include "ClassFileReader.h"
#include "ReadBytes.h"


/** @brief Faz a leitura sequencial do arquivo .class indicado pelo parâmetro
*     filename.
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
    // if(class_file.magic_number != 0xCAFEBABE){
    //     printf("Arquivo .class invalido. \n");
    //     printf("Encerrando programa. \n");
    //     exit(1);
    // }
    // realiza a leitura das versões no formato major.minor
    class_file.minor_version = read_2_bytes(file);
    class_file.major_version = read_2_bytes(file);
    // if (class_file.major_version > 51){
    //     printf( "Arquivo com versão invalida.\n");
    //     printf("Encerrando programa. \n");
    //     exit(1);
    // }

    // lê quantos constat_pool existem neste arquivo
    class_file.constant_pool_count = read_2_bytes(file);
    class_file.constant_pool = (CpInfo*)malloc(
                          (class_file.constant_pool_count-1)*sizeof(CpInfo));
    cpinfo->read(file, class_file);
    if (DEBUG) std::cout << "cp info read\n";

    class_file.access_flags = read_2_bytes(file);
    class_file.this_class = read_2_bytes(file);

    // Lê o nome da classe no CP e converte pra String
    std::string class_name = class_file.constant_pool->get_utf8_constant_pool(
                                                  class_file.constant_pool,
                                                  class_file.this_class - 1);
    // Adiciona a extensão '.class' ao nome da classe
    class_name += ".class";
    // Se o nome do arquivo é diferente do nome da classe
    if (filename.find(class_name) == std::string::npos) {
      printf("O nome do arquivo não é imcompátivel com o da classe. \n");
      exit(1);
    }

    class_file.super_class = read_2_bytes(file);

    class_file.interfaces_count = read_2_bytes(file);
    class_file.interfaces = (InterfaceInfo*)malloc(
                          class_file.interfaces_count * sizeof(InterfaceInfo));
    interface_info->read(class_file, file);
    if (DEBUG) std::cout << "interface read\n";

    class_file.fields_count = read_2_bytes(file);
    class_file.fields = (FieldInfo*)malloc(
                                  class_file.fields_count * sizeof(FieldInfo));
    field_info->read(class_file, file);
    if (DEBUG) std::cout << "field read\n";

    class_file.methods_count = read_2_bytes(file);
    if (DEBUG) std::cout << "\nmethods count " << class_file.methods_count << std::endl;
    class_file.methods = (MethodInfo*) malloc(
                                class_file.methods_count * sizeof(MethodInfo));
    method_info->read(class_file, file);
    if (DEBUG) std::cout << "method read\n";

    class_file.attributes_count = read_2_bytes(file);
    class_file.attributes = (AttributeInfo*)malloc(
                          class_file.attributes_count * sizeof(AttributeInfo));
    attribute_info->read(class_file, file);
    if (DEBUG) std::cout << "attribute read\n";

    return class_file;
}
