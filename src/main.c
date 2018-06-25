/*
 *  Universidade de Brasília
 *  Instituto de Ciencias Exatas
 *  Departamento de Ciência da Computação
 *
 *  Software Básico - Turma A - 1/2018
 *
 *  Projeto JVM
 *
 *  Grupo ?:
 *      - Dayanne Fernandes da Cunha        13/0107191
 *      - Laís Mendes Gonçalves             11/0033647
 *      - Marcus Vinícius da Silva Borges   13/0032891
 *
 *  Arquivo fonte principal "ClassFileReader.c"
 *  Executar com : make
 *
 *  Copyright © 2018 UnB. All rights reserved.
 */
 #include "ClassFileReader.h"
 #include "ClassFilePrinter.h"


/*
 *  Função principal do sistema leitor/exibidor.
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
