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
 *  @param argc ...
 *  @param argv ...
 *  @return ...
 */
int main(int argc, char const *argv[]) {
  // passa o nome do arquivo .class como argumento para função de leitura
  JavaClass* class_file = read_class_file(argv[1]);
  // exibe os dados gerais do arquivo .class informado pelo usuário
  print_general_info(class_file);
  // exibe informações das constant_pools
  print_constant_pool_info(class_file);
  return 0;
}
