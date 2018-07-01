/** @file ClassFilePrinter.c
 *  @brief Funções de impressão da interface do sistema e exibidor
 *    do arquivo ".class".
 *  @bug No know bugs.
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "ClassFilePrinter.h"
#include "JavaClass.h"
#include "ReadBytes.h"

/** @brief Mostra menu inicial para escolher tipo de arquivo java de teste.
*  @return void
*/
std::string ClassFilePrinter::print_menu_choose_type_file() {
  int option = 0;
  std::string filename;

  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\n\nLeitor/Exibidor: \n");
  printf("---------------------\n");

  printf("Insira qual tipo de arquivo java gostaria de testar:\n");
  printf("1. String\n");
  printf("2. Simulação de impressão\n");
  printf("3. Vetor unidimensional\n");
  printf("4. Vetor multidimensional\n");
  printf("5. Herança\n");
  printf("6. Reescrita\n");
  printf("7. Float\n");
  printf("8. Interface\n");
  printf("9. Inteiro\n");
  printf("10. Polimorfismo\n");
  printf("11. Double\n");
  printf("12. Static\n");
  printf("13. Atributo de instancia\n");
  printf("14. Atributo de classe\n");
  printf("15. Metodos Dinamicos\n");
  printf("16. Attributos\n");
  printf("0. Sair\n");
  scanf("%d", &option);

  switch (option) {
    case 1:
      filename = "test/StringDemo.class";
      break;
    case 2:
      filename = "test/PrintDemo.class";
      break;
    case 3:
      filename = "test/ArrayUniDemo.class";
      break;
    case 4:
      filename = "test/ArrayMultDemo.class";
      break;
    case 5:
      filename = "test/InheritanceDemo.class";
      break;
    case 6:
      filename = "test/RewriteDemo.class";
      break;
    case 7:
      filename = "test/FloatDemo.class";
      break;
    case 8:
      filename = "test/InterfaceDemo.class";
      break;
    case 9:
      filename = "test/IntegerDemo.class";
      break;
    case 10:
      filename = "test/PolDemo.class";
      break;
    case 11:
      filename = "test/DoubleDemo.class";
      break;
    case 12:
      filename = "test/MethodStaticDemo.class";
      break;
    case 13:
      filename = "test/AttributeInstDemo.class";
      break;
    case 14:
      filename = "test/AttributeClassDemo.class";
      break;
    case 15:
      filename = "test/MethodDynamicDemo.class";
      break;
    case 16:
      filename = "test/AttributesDemo.class";
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
void ClassFilePrinter::print_general_info(JavaClass class_file,
                                          std::string filename) {
  std::cout << "Filename:             " << filename << std::endl;
  printf("Magic Number:         0x%0X\n", class_file.magic_number);
  printf("Minor Version:        %d\n", class_file.minor_version);
  printf("Major version:        %d\n", class_file.major_version);
  printf("Contanst pool count:  %d\n", class_file.constant_pool_count);
  printf("Access flags:         0x%.4x\n", class_file.access_flags);
  printf("This class:           cp_info #%d < ", class_file.this_class);
  std::cout << get_utf8_constant_pool(class_file.constant_pool,
  class_file.constant_pool[(class_file.this_class)-1].Class.type_class_info-1)
  << " >";
  printf("\nSuper class:          cp_info #%d < ", class_file.super_class);
  std::cout << get_utf8_constant_pool(class_file.constant_pool,
  class_file.constant_pool[(class_file.super_class)-1].Class.type_class_info-1)
  << " >";
  printf("\nInterface count: %d\n", class_file.interfaces_count);
  printf("Field count: %d\n", class_file.fields_count);
  printf("Methods count: %d\n", class_file.methods_count);
  printf("Attributes count: %d\n", class_file.attributes_count);
}

void ClassFilePrinter::print_interfaces(JavaClass class_file){

  printf("\n--------------- Interfaces Info ---------------\n");
  for (int i = 0; i < class_file.interfaces_count; i++) {
    printf("Interface: cp info #%d <", class_file.interfaces[i]);
    std::cout << get_utf8_constant_pool(class_file.constant_pool,
                                    class_file.interfaces[i]-1);
    printf("\n");
  }
}

/** @brief Mostra menu de escolhas do exibidor do arquivo .class.
 *  @param class_file ponteiro com as informações lidas do .class
 *  @return void
 */
void ClassFilePrinter::print_menu_exhibitor(JavaClass class_file) {
  int option = 0;

  printf("\n\nQue estrutura de dados deseja imprimir do arquivo .class:\n");
  printf("1. Constant Pool\n");
  printf("2. Interface\n");
  printf("3. Fields\n");
  printf("4. Methods\n");
  printf("5. Attributes\n");
  printf("0. Sair\n");
  scanf("%d", &option);

  switch (option) {
    case 1:
      // exibe informações das constant_pools
      print_constant_pool_info(class_file);
      break;
    case 2:
      // exibe as interfaces implementadas pela classe
      // print_interfaces_info(class_file);
      break;
    case 3:
      // print_fields_info(class_file);
      break;
    case 4:
      printf("Não implementado");
      break;
    case 5:
      printf("Não implementado");
      break;
    case 0:
      printf("Até mais!\n");
      exit(0);
    default:
      printf("Opção não existe, tente novamente. Pressione enter...\n");
      char command;
      scanf("%c", &command);
      while ((command = getchar()) != '\n' && command != EOF) { };
      print_menu_exhibitor(class_file);
  }
}

/** @brief Mostra informações das constant_pools.
 *  Tabela de estruturas representando string, nomes de classes ou interfaces,
 *  nomes de campos, etc.
 *  @param class_file ponteiro com as informações lidas do .class
 *  @return void
 */
void ClassFilePrinter::print_constant_pool_info(JavaClass class_file) {
  printf("\n\nConstant Pool Info: \n\n");
  for (int i = 0; i < class_file.constant_pool_count-1; i++) {

    printf("\nCP_INFO[%d]\n", i + 1);

    // formato de cada entrada é indicado pelo byte tag
    switch (class_file.constant_pool[i].tag) {
      // caso tag seja 1
      case CONSTANT_Utf8:
        printf("CONSTANT_UTF8_info\n");
        printf("Tamanho: %d - ", class_file.constant_pool[i].UTF8.size);
        printf("Valor: %s\n", class_file.constant_pool[i].UTF8.bytes);
        break;
      // caso tag seja 3
      case CONSTANT_Integer:
        // representa o valor da constante int, em big-endian
        printf("CONSTANT_Integer_info:\n");
        printf("Valor: %d\n", class_file.constant_pool[i].Integer.bytes);
        break;
      // caso tag seja 4
      case CONSTANT_Float:
        printf("CONSTANT_Float_info:\n");
        float valor_f;
        memcpy(&valor_f, &(class_file.constant_pool[i].Float.bytes),
              sizeof(float));
        // representa o valor da constante float, em big-endian, no formato
        // IEEE-754
        printf("Float: %lf\n", valor_f);
        break;
      // caso tag seja 5
      case CONSTANT_Long:
        printf("CONSTANT_Long_info:\n");
        // representa uma constante inteira de 8 bytes em big-endian
        // unsigned
        printf("\tHigh: 0x%0x\n", class_file.constant_pool[i].Long.high_bytes);
        printf("\tLow: 0x%0x\n", class_file.constant_pool[i].Long.low_bytes);
        long read_long_value;
        memcpy(&read_long_value, &(class_file.constant_pool[i].Long.high_bytes),
              sizeof(long));
        memcpy(&read_long_value, &(class_file.constant_pool[i].Long.low_bytes),
              sizeof(long));
        // ((long) high_bytes << 32) + low_bytes
        printf("\tLong Value: %ld\n", read_long_value);
        break;
      // caso tag seja 6
      case CONSTANT_Double:
        printf("CONSTANT_Double_info:\n");
        printf("\tHigh: 0x%0x\n", class_file.constant_pool[i].Double.high_bytes);
        printf("\tLow: 0x%0x\n", class_file.constant_pool[i].Double.low_bytes);
        double read_double_value;
        u8 aux;
        // representa uma constante de ponto flutuante de 8 bytes em big-endian
        // no formato IEEE-754
        aux = ((u8)class_file.constant_pool[i].Double.high_bytes << 32) | class_file.constant_pool[i].Double.low_bytes;
        memcpy(&read_double_value, &aux, sizeof(double));
        // (long bits) = ((long) high_bytes << 32) + low_bytes;
        printf("\tDouble Value: %lf\n", read_double_value);
        break;
      // caso tag seja 7
      case CONSTANT_Class :
        printf("CONSTANT_Class_info:\n");
        // exibe nome de uma classe ou interface
        std::cout << get_utf8_constant_pool(class_file.constant_pool,
                            class_file.constant_pool[i].Class.type_class_info - 1);
      break;
      // caso tag seja 8
      case CONSTANT_String:
        printf("String: ");
        // representa sequência de caracteres com a qual o objeto String será
        // iniciado
        get_utf8_constant_pool(class_file.constant_pool,
                              class_file.constant_pool[i].String.bytes-1);
        break;
      // caso tag seja 9
      case CONSTANT_Fieldref:
        printf("CONSTANT_Fieldref_info:\n");
        printf("Class index: ");
        // representa nome completo da classe ou interface que contem
        // a declaração desse field
        get_utf8_constant_pool(class_file.constant_pool,
                          class_file.constant_pool[i].FieldRef.class_index-1);
        printf("\nName and Type: ");
        // representa um field ou método sem indicar classe ou interface
        // a que pertence
        get_utf8_constant_pool(class_file.constant_pool,
                  class_file.constant_pool[i].FieldRef.name_and_type_index-1);
        break;
      // caso tag seja 10
      case CONSTANT_Methodref:
        printf("CONSTANT_Methodref_info:\n");
        // representa um método
        printf("Index: ");
        // representa nome completo classe que contem a declaração desse método
        std::cout << get_utf8_constant_pool(class_file.constant_pool,
                              class_file.constant_pool[i].MethodRef.index-1);
        printf("\nName and Type: ");
        // indica nome e descritor do método
        std::cout << get_utf8_constant_pool(class_file.constant_pool,
                        class_file.constant_pool[i].MethodRef.name_and_type-1);
        break;
      // caso tag seja 11
      case CONSTANT_InterfaceMethodref:
        printf("InterfaceMethodRef: \n");
        printf("Index: ");
        // representa nome completo da interface que contem a declaração desse
        // método
        std::cout << get_utf8_constant_pool(class_file.constant_pool,
                      class_file.constant_pool[i].InterfaceMethodRef.index-1);
        printf("\nName and Type: ");
        // indica nome e descritor do método
        std::cout << get_utf8_constant_pool(class_file.constant_pool,
              class_file.constant_pool[i].InterfaceMethodRef.name_and_type-1);
        break;
      // caso tag seja 12
      case CONSTANT_NameAndType:
        printf("CONSTANT_NameAndType_info:\n");
        printf("Name index: ");
        std::cout << get_utf8_constant_pool(class_file.constant_pool,
                        class_file.constant_pool[i].NameAndType.name_index-1);
        printf("\nDescriptor index: ");
        std::cout << get_utf8_constant_pool(class_file.constant_pool,
                  class_file.constant_pool[i].NameAndType.descriptor_index-1);
        break;
      case CONSTANT_EmptySpace:
        printf("Large numeric continued / empty item");
        break;
      default:
        printf("Tag %d. Wrong tag number. Shutting down.\n",
                class_file.constant_pool[i].tag);
        exit(1);
    }
    printf("\n");
  }
}

/** @brief Mostra nome no formato UTF8.
 *  @param cp_info ...
 *  @param pos_info ...
 *  @return void
 */
std::string ClassFilePrinter::get_utf8_constant_pool(CpInfo *cp_info, u2 pos_info) {
  std::string utf8_const;
  u2 tag = cp_info[pos_info].tag;

  switch (tag) {
    // caso tag seja 1
    case CONSTANT_Utf8:
      // representa valores strings constantes, inclusive unicode
      // UTF8.length indica o número de bytes no array bytes
      // UTF8.bytes contêm os bytes da string
      // @TODO checar se nenhum byte tem valor 0 ou está no intervalo
      //  0xf0 ou 0xff, i.e. [240, 255]
      utf8_const = (char*)cp_info[pos_info].UTF8.bytes;
      break;
    case CONSTANT_Class:
      utf8_const = get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].Class.type_class_info - 1);
      break;
    case CONSTANT_Fieldref:
      utf8_const = get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].FieldRef.class_index-1);
      utf8_const += get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].FieldRef.name_and_type_index-1);
      break;
    // caso tag seja 12
    case CONSTANT_NameAndType:
      // representa um nome simples de field ou método ou ainda o nome do
      // método especial <init>
      utf8_const = get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].NameAndType.name_index-1);
      // representa um descritor válido de field ou de método
      utf8_const += get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].NameAndType.descriptor_index-1);
      break;
    case CONSTANT_Methodref:
      utf8_const = get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].MethodRef.index-1);
      utf8_const += get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].MethodRef.name_and_type-1);
      break;
    case CONSTANT_InterfaceMethodref:
      utf8_const = get_utf8_constant_pool(cp_info,
                            cp_info[pos_info].InterfaceMethodRef.index-1);
      utf8_const += get_utf8_constant_pool(cp_info,
                        cp_info[pos_info].InterfaceMethodRef.name_and_type-1);
      break;
    case CONSTANT_String:
      get_utf8_constant_pool(cp_info, cp_info[pos_info].String.bytes-1);
      break;
    default:
      printf("Tag %d. Wrong tag number. Shutting down.\n", tag);
      exit(1);
  }

  return utf8_const;
}

// /** @brief Printa as interfaces contidas no .class
//  *  @param class_file
//  *  @return void
//  */
// void ClassFilePrinter::print_interfaces_info(JavaClass class_file) {
//   int i;
//
//   if (class_file.interface_count != 0) {
//     for(i = 0; i < class_file.interface_count; i++) {
//       int index = class_file.constant_pool[class_file.interfaces[i] - 1].Class.type_class_info;
//
//       printf("\tInterface %d:     cp_info_#%d   %d", i, class_file.interfaces[i], index);
//       // READ UTF 8
//       printf("\n");
//     }
//   }
// }
//
// /*  @brief Printa os fields contidos no .class
//  *  @param class_file
//  *  @return void
//  */
// void ClassFilePrinter::print_fields_info(JavaClass class_file) {
//   int i, j;
//
//   if (class_file.field_count != 0) {
//     for (i = 0; i < class_file.field_count; i++) {
//       printf("\tName:             cp_info_#%d \n", class_file.fields[i].type_class_info);
//       printf("\tDescriptor:       cp_info_#%d \n", class_file.fields[i].descriptor_index);
//       printf("\tAccess Flag:      0x%04X      \n", class_file.fields[i].access_flag);
//       printf("\tAttributes count: %d        \n\n", class_file.fields[i].atributes_count);
//
//       for (j = 0; j < class_file.fields[i].atributes_count; j++) {
//         printf("\tGeneric Info\n");
//         printf("\t\tattribute_type_class_info:     cp_info_#%d\n", class_file.fields[i].attributes->attribute_type_class_info);
//         printf("\t\tattribute_length:         %u        \n\n", class_file.fields[i].attributes->attribute_length);
//         printf("\tSpecific Info:\n");
//         printf("\t\tconstant_value_index:     cp_info_#%d\n", class_file.fields[i].attributes->constant_value_index - 1);
//         printf("\n\n\n");
//       }
//     }
//   }
// }
