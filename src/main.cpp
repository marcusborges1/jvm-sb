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
 *
 *  @author Dayanne Fernandes da Cunha        13/0107191
 *  @author Laís Mendes Gonçalves             11/0033647
 *  @author Marcus Vinícius da Silva Borges   13/0032891
 *  @author
 *  @author
 *
 *  @bug No know bugs.
 */
#include <string>
#include "ClassFilePrinter.h"


/** @brief Função principal do sistema leitor/exibidor e JVM.
 *  @return int que notifica saída com sucesso do sistema
 */
int main() {
  ClassFilePrinter *printer = new ClassFilePrinter();
  printer->print_menu_init();

  return 0;
}
