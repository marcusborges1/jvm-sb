/** @file main.c
 *  @brief Arquivo inicial do programa leitor/exibidor.
 *
 *  Universidade de Brasília
 *
 *  Instituto de Ciencias Exatas
 *
 *  Departamento de Ciência da Computação
 *
 *  Software Básico - Turma A - 1/2018
 *
 *  Projeto JVM
 *
 *  Executar com : make
 *
 *  @author Dayanne Fernandes da Cunha        13/0107191
 *  @author Laís Mendes Gonçalves             11/0033647
 *  @author Marcus Vinícius da Silva Borges   13/0032891
 *  @bug No know bugs.
 */
#include <iostream>
#include <string>

#include "ClassFilePrinter.h"
// #include "ClassFileReader.h"
#include "JavaClass.h"
#include "CpInfo.h"

/** @brief Função principal do sistema leitor/exibidor.
 *  @return ...
 */
int main() {
    ClassFilePrinter *printer = new ClassFilePrinter();
    // ClassFileReader *reader = new ClassFileReader();

    // passa o nome do arquivo .class como argumento para função de leitura
    std::string filename = printer->print_menu_choose_type_file();
    // exibe os dados gerais do arquivo .class informado pelo usuário
    // JavaClass class_file = reader->read_class_file(filename);
    // // menu de escolhas do exibidor
    // printer->print_general_info(class_file);
    // CpInfo::print(class_file);
    // printer->print_interfaces(class_file);
    // FieldInfo::print(class_file);
    // MethodInfo::print(class_file);
    // AttributeInfo::print(class_file);

    return 0;
}
