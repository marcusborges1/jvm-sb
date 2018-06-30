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
#include "ClassFileReader.h"
// #include "CpInfo.h"
// #include "AttributeInfo.h"
// #include "FieldInfo.h"
// #include "MethodInfo.h"

/** @brief Função principal do sistema leitor/exibidor.
 *  @return ...
 */
int main() {
  ClassFileReader *reader = new ClassFileReader();
  ClassFilePrinter *printer = new ClassFilePrinter();
  // AttributeInfo *attributeinfo = new AttributeInfo();
  // MethodInfo *methodinfo = new MethodInfo();
  // FieldInfo *fieldinfo = new FieldInfo();
  // CpInfo *cpinfo = new CpInfo();

  std::string filename = printer->print_menu_choose_type_file();
  // passa o nome do arquivo .class como argumento para função de leitura
  JavaClass class_file = reader->read_class_file(filename);
  // exibe os dados gerais do arquivo .class informado pelo usuário
  printer->print_general_info(class_file, filename);
  // menu de escolhas do exibidor
  // cpinfo->print(class_file);
  // printer->print_interfaces(class_file);
  // fieldinfo->print(class_file);
  // methodinfo->print(class_file);
  // attributeinfo->print(class_file);

  return 0;
}
