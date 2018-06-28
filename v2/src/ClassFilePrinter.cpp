/** @file ClassFilePrinter.c
 *  @brief Funções de impressão da interface do sistema e exibidor
 *    do arquivo ".class".
 *  @bug No know bugs.
 */


#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <JavaClass.h>
#include <iostream>


class ClassFilePrinter {

    public:
        /** @brief Mostra menu inicial para escolher tipo de arquivo java de teste.
        *  @return void
        */
        static char* print_menu_choose_type_file() {
            int option = 0;
            static char filename[30];

            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("\n\nLeitor/Exibidor: \n");
            printf("---------------------\n");

            printf("Insira qual tipo de arquivo java gostaria de testar:\n");
            printf("1. Hello\n");
            printf("2. Simulação de impressão\n");
            printf("3. Vetor unidimensional\n");
            printf("4. Vetor multidimensional\n");
            printf("5. Herança\n");
            printf("6. Reescrita\n");
            printf("7. Float\n");
            printf("0. Sair\n");
            scanf("%d", &option);

            switch (option) {
                case 1:
                    strcpy(filename, "../test/Hello.class");
                    break;
                case 2:
                    strcpy(filename, "test/PrintDemo.class");
                    break;
                case 3:
                    strcpy(filename, "test/ArrayUniDemo.class");
                    break;
                case 4:
                    strcpy(filename, "test/ArrayMultDemo.class");
                    break;
                case 5:
                    strcpy(filename, "test/InheritanceDemo.class");
                    break;
                case 6:
                    strcpy(filename, "test/RewriteDemo.class");
                    break;
                case 7:
                    strcpy(filename, "test/FloatDemo.class");
                    break;
                case 0:
                    printf("Até mais!\n");
                    exit(0);
                default:
                    printf("Opção não existe, tente novamente. Pressione enter...\n");
                    char command;
                    scanf("%c", &command);
                    while ((command = getchar()) != '\n' && command != EOF) { };
                    print_menu_choose_type_file();
            }

            return filename;
        }

        /** @brief Mostra informações básicas do Class File.
        *  @return void
        */
        static void print_general_info(JavaClass class_file){
            printf("Magic Number:         0x%0X\n", class_file.magic_number);
            printf("Minor Version:        %d\n", class_file.minor_version);
            printf("Major version:        %d\n", class_file.major_version);
        }

        static void print_interfaces(JavaClass class_file){
            printf("\n--------------- Interfaces Info ---------------\n");
           for (int i = 0; i < class_file.interfaces_count; i++) {
             printf("Interface: cp info #%d <", class_file.interfaces[i]);
             std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.interfaces[i]-1);
             printf("\n");
           }
        }





};