/** @file main.cpp
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
 *  Comandos para leitor/exibidor : -e nomedoarquivo.class
 *  Comandos para jvm : -j nomedoarquivo.class
 *
 *  @author Dayanne Fernandes da Cunha        13/0107191
 *  @author Laís Mendes Gonçalves             11/0033647
 *  @author Marcus Vinícius da Silva Borges   13/0032891
 *  @author Leonardo de Almeida               15/0135491
 *  @author Gabriel Almeida Campos            15/0009887
 *
 *  @bug No know bugs.
 */
#include "ClassFilePrinter.h"
#include "ClassFileReader.h"
#include "Interpreter.h"
#include <string>


/** @brief Função principal do sistema leitor/exibidor e JVM.
 *  @return int que notifica saída com sucesso do sistema
 */
int main(int argc, char* argv[]) {
  // mostra menu inicial de interface com usuário
  ClassFilePrinter *printer = new ClassFilePrinter();
  ClassFileReader *reader = new ClassFileReader();
  Interpreter *interpreter = new Interpreter();
  JavaClass class_file;

  if (argc != 3) std::cout << "Comando incorreto!\n"
              << "Comando para leitor/exibidor : -e nomedoarquivo.class\n"
              << "Comando para jvm : -j nomedoarquivo.class\n";
  else {
    std::string cmd = argv[1], filename = argv[2];
    if (cmd == "-e") {
      class_file = reader->read_class_file(filename);
      printer->print_general_info(class_file, filename);
      printer->print_constant_pool_info(class_file);
      printer->print_interfaces(class_file);
      printer->print_fields_info(class_file);
      printer->print_method(class_file);
      printer->print_attributes_methods(class_file);
      std::cout << std::endl;
    } else if (cmd == "-j") {
      class_file = reader->read_class_file(filename);
      printf("Interpretando...\n");
      interpreter->current_path_folder = "test";
      interpreter->execute(class_file);
    }
  }

  return 0;
}
