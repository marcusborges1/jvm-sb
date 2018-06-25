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
 #include "ClassFileReader.h"
 #include "ClassFilePrinter.h"


/** @brief Função principal do sistema leitor/exibidor.
 *  @return ...
 */
int main() {
  // menu inicial 
  char *filename = print_menu_choose_type_file();
  // passa o nome do arquivo .class como argumento para função de leitura
  JavaClass* class_file = read_class_file(filename);
  // exibe os dados gerais do arquivo .class informado pelo usuário
  print_general_info(class_file, filename);
  // menu de escolhas do exibidor
  print_menu_exhibitor(class_file);
  return 0;
}
