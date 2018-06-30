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
#include <CpInfo.h>
#include "../src/ClassFilePrinter.cpp"
#include "../includes/JavaClass.h"
#include "iostream"
#include "string"
#include "../src/ClassFileReader.cpp"
#include "CpInfo.h"

/** @brief Função principal do sistema leitor/exibidor.
 *  @return ...
 */

    int main() {
        // menu inicial
        const char *filename = ClassFilePrinter::print_menu_choose_type_file(); // passa o nome do arquivo .class como argumento para função de leitura
        JavaClass class_file = ClassFileReader::read_class_file(filename); // exibe os dados gerais do arquivo .class informado pelo usuário
        ClassFilePrinter::print_general_info(class_file); // menu de escolhas do exibidor
        CpInfo::print(class_file);
        ClassFilePrinter::print_interfaces(class_file);
        FieldInfo::print(class_file);
        MethodInfo::print(class_file);
        AttributeInfo::print(class_file);

        return 0;
    }