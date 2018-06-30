/** @file ClassFilePrinter.c
 *  @brief Funções de impressão da interface do sistema e exibidor
 *    do arquivo ".class".
 *  @bug No know bugs.
 */
#include "ClassFilePrinter.h"
#include <string.h>


/** @brief Mostra menu inicial para escolher tipo de arquivo java de teste.
 *  @return void
 */
char* print_menu_choose_type_file() {
  int option = 0;
  static char filename[30];

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
  printf("16. Attributes\n");
  printf("0. Sair\n");
  scanf("%d", &option);

  switch (option) {
    case 1:
      strcpy(filename, "test/StringDemo.class");
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
    case 8:
      strcpy(filename, "test/InterfaceDemo.class");
      break;
    case 9:
      strcpy(filename, "test/Inteiro.class");
      break;
    case 10:
      strcpy(filename, "test/Polimorfismo.class");
      break;
    case 11:
      strcpy(filename, "test/DoubleDemo.class");
      break;
    case 12:
      strcpy(filename, "test/Static.class");
      break;
    case 13:
      strcpy(filename, "test/Atributo_Instancia.class");
      break;
    case 14:
      strcpy(filename, "test/Atributo_Classe.class");
      break;
    case 15:
      strcpy(filename, "test/GFG.class");
      break;
    case 16:
      strcpy(filename, "test/AttributesDemo.class");
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

/** @brief Mostra informações gerais do arquivo .class.
 *  @param class_file ponteiro com as informações lidas do .class
 *  @return void
 */
void print_general_info(JavaClass* class_file, char *filename) {
  printf("Filename:             %s\n", filename);
  printf("Magic Number:         0x%0X\n", class_file->magic_number);
  printf("Minor Version:        %d\n", class_file->minor_version);
  printf("Major version:        %d\n", class_file->major_version);
  printf("Contanst pool count:  %d\n", class_file->constant_pool_count);
  printf("Access flags:         0x%.4x\n", class_file->access_flags);
  printf("This class:           cp_info #%d < ", class_file->this_class);
  // get_UTF8_constant_pool(class_file->contant_pool,
      // class_file->contant_pool[(class_file->this_class)-1].Class.name_index-1);
  printf("\nSuper class:          cp_info #%d < ", class_file->super_class);
  // get_UTF8_constant_pool(class_file->contant_pool,
      // class_file->contant_pool[(class_file->super_class)-1].Class.name_index-1);
  // printf("\nInterface count: %d\n", class_file->interface_count);
  // printf("Field count: %d\n", class_file->field_count);
  // printf("Methods count: %d\n", class_file->methods_count);
}

/** @brief Mostra menu de escolhas do exibidor do arquivo .class.
 *  @param class_file ponteiro com as informações lidas do .class
 *  @return void
 */
void print_menu_exhibitor(JavaClass* class_file) {
  int option = 0;

  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("Que estrutura de dados deseja imprimir do arquivo .class:\n");
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
      print_interfaces_info(class_file);
      break;
    case 3:
      print_fields_info(class_file);
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
void print_constant_pool_info(JavaClass* class_file) {
  float float_value;
  long long_value;

  printf("\n\nConstant Pool Info: \n\n");
  for (int i = 0; i < class_file->constant_pool_count-1; i++) {
    CpInfo* cp_info = class_file->contant_pool+i;

    printf("\nCP_INFO[%d]\n", i + 1);

    // formato de cada entrada é indicado pelo byte tag
    switch (cp_info->tag) {
      // caso tag seja 1
      case CONSTANT_Utf8:
        printf("UTF8\n");
        printf("Tamanho: %d - ", cp_info->UTF8.size);
        printf("Valor: %s\n", cp_info->UTF8.bytes);
        break;
      // caso tag seja 3
      case CONSTANT_Integer:
        // representa o valor da constante int, em big-endian
        printf("Integer: %d\n", cp_info->Integer.bytes);
        break;
      // caso tag seja 4
      case CONSTANT_Float:
        memcpy(&float_value, &(cp_info->Float.bytes), sizeof(float));
        // representa o valor da constante float, em big-endian, no formato
        // IEEE-754
        printf("Float: %lf\n", float_value);
        break;
      // caso tag seja 5
      case CONSTANT_Long:
        // representa uma constante inteira de 8 bytes em big-endian
        printf("Long:\n");
        // unsigned
        printf("\tHigh: 0x%0x\n", cp_info->Long.high_bytes);
        printf("\tLow: 0x%0x\n", cp_info->Long.low_bytes);
        memcpy(&long_value, &(cp_info->Long.high_bytes), sizeof(long));
        memcpy(&long_value, &(cp_info->Long.low_bytes), sizeof(long));
        // ((long) high_bytes << 32) + low_bytes
        printf("\tLong Value: %ld\n", long_value);
        break;
      // caso tag seja 6
      case CONSTANT_Double:
        printf("Double:\n");
        printf("\tHigh: 0x%0x\n", cp_info->Double.high_bytes);
        printf("\tLow: 0x%0x\n", cp_info->Double.low_bytes);
        u8 aux;
        // representa uma constante de ponto flutuante de 8 bytes em big-endian
        // no formato IEEE-754
        aux = ((u8)cp_info->Double.high_bytes << 32) | cp_info->Double.low_bytes;
        double double_value;
        memcpy(&double_value, &aux, sizeof(double));
        // (long bits) = ((long) high_bytes << 32) + low_bytes;
        printf("\tDouble Value: %lf\n", double_value);
        break;
      // caso tag seja 7
      case CONSTANT_Class :
        printf("Class: ");
        // exibe nome de uma classe ou interface
        get_UTF8_constant_pool(class_file->contant_pool,
                              cp_info->Class.name_index - 1);
        break;
      // caso tag seja 8
      case CONSTANT_String:
        printf("String: ");
        // representa sequência de caracteres com a qual o objeto String será
        // iniciado
        get_UTF8_constant_pool(class_file->contant_pool,
                              cp_info->String.bytes-1);
        break;
      // caso tag seja 9
      case CONSTANT_Fieldref:
        printf("FieldRef\n");
        printf("Class index: ");
        // representa nome completo da classe ou interface que contem
        // a declaração desse field
        get_UTF8_constant_pool(class_file->contant_pool,
                              cp_info->FieldRef.class_index-1);
        printf("\nName and Type: ");
        // representa um field ou método sem indicar classe ou interface
        // a que pertence
        get_UTF8_constant_pool(class_file->contant_pool,
                              cp_info->FieldRef.name_and_type_index-1);
        break;
      // caso tag seja 10
      case CONSTANT_Methodref:
        // representa um método
        printf("MethodRef: \n");
        printf("Index: ");
        // representa nome completo classe que contem a declaração desse método
        get_UTF8_constant_pool(class_file->contant_pool,
                              cp_info->MethodRef.index-1);
        printf("\nName and Type: ");
        // indica nome e descritor do método
        get_UTF8_constant_pool(class_file->contant_pool,
                              cp_info->MethodRef.name_and_type-1);
        break;
      // caso tag seja 11
      case CONSTANT_InterfaceMethodref:
        printf("InterfaceMethodRef: \n");
        printf("Index: ");
        // representa nome completo da interface que contem a declaração desse
        // método
        get_UTF8_constant_pool(class_file->contant_pool,
                              cp_info->InterfaceMethodRef.index-1);
        printf("\nName and Type: ");
        // indica nome e descritor do método
        get_UTF8_constant_pool(class_file->contant_pool,
                              cp_info->InterfaceMethodRef.name_and_type-1);
        break;
      // caso tag seja 12
      case CONSTANT_NameAndType:
        printf("NameAndType: \n");
        printf("Name index: ");
        get_UTF8_constant_pool(class_file->contant_pool,
                              cp_info->NameAndType.name_index-1);
        printf("\nDescriptor index: ");
        get_UTF8_constant_pool(class_file->contant_pool,
                              cp_info->NameAndType.descriptor_index-1);
        break;
      case CONSTANT_EmptySpace:
        printf("Large numeric continued / empty item");
        break;
      default:
        printf("Tag %d. Wrong tag number. Shutting down.\n", cp_info->tag);
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
void get_UTF8_constant_pool(CpInfo *cp_info, u4 pos_info) {
  u1 tag = cp_info[pos_info].tag;

  switch (tag) {
    // caso tag seja 1
    case CONSTANT_Utf8:
      // representa valores strings constantes, inclusive unicode
      // UTF8.length indica o número de bytes no array bytes
      // UTF8.bytes contêm os bytes da string
      // @TODO checar se nenhum byte tem valor 0 ou está no intervalo
      //  0xf0 ou 0xff, i.e. [240, 255]
      printf("%s", (char*)cp_info[pos_info].UTF8.bytes);
      break;
    case CONSTANT_Class:
      get_UTF8_constant_pool(cp_info,
                            cp_info[pos_info].Class.name_index - 1);
      break;
    case CONSTANT_Fieldref:
      get_UTF8_constant_pool(cp_info,
                            cp_info[pos_info].FieldRef.class_index-1);
      get_UTF8_constant_pool(cp_info,
                            cp_info[pos_info].FieldRef.name_and_type_index-1);
      break;
    // caso tag seja 12
    case CONSTANT_NameAndType:
      // representa um nome simples de field ou método ou ainda o nome do
      // método especial <init>
      get_UTF8_constant_pool(cp_info,
                            cp_info[pos_info].NameAndType.name_index-1);
      // representa um descritor válido de field ou de método
      get_UTF8_constant_pool(cp_info,
                            cp_info[pos_info].NameAndType.descriptor_index-1);
      break;
    case CONSTANT_Methodref:
      get_UTF8_constant_pool(cp_info,
                            cp_info[pos_info].MethodRef.index-1);
      get_UTF8_constant_pool(cp_info,
                            cp_info[pos_info].MethodRef.name_and_type-1);
      break;
    case CONSTANT_InterfaceMethodref:
      get_UTF8_constant_pool(cp_info,
                            cp_info[pos_info].InterfaceMethodRef.index-1);
      get_UTF8_constant_pool(cp_info,
                        cp_info[pos_info].InterfaceMethodRef.name_and_type-1);
      break;
    case CONSTANT_String:
      get_UTF8_constant_pool(cp_info, cp_info[pos_info].String.bytes-1);
      break;
    default:
      printf("Tag %d. Wrong tag number. Shutting down.\n", tag);
      exit(1);
  }
}

/** @brief Printa as interfaces contidas no .class
 *  @param class_file
 *  @return void
 */
void print_interfaces_info(JavaClass* class_file) {
  int i;

  if (class_file->interface_count != 0) {
    for(i = 0; i < class_file->interface_count; i++) {
      int index = class_file->contant_pool[class_file->interfaces[i] - 1].Class.name_index;

      printf("\tInterface %d:     cp_info_#%d   %d", i, class_file->interfaces[i], index);
      // READ UTF 8
      printf("\n");
    }
  }
}

/*  @brief Printa os fields contidos no .class
 *  @param class_file
 *  @return void
 */
void print_fields_info(JavaClass* class_file) {
  int i, j;

  if (class_file->field_count != 0) {
    for (i = 0; i < class_file->field_count; i++) {
      printf("\tName:             cp_info_#%d \n", class_file->fields[i].name_index);
      printf("\tDescriptor:       cp_info_#%d \n", class_file->fields[i].descriptor_index);
      printf("\tAccess Flag:      0x%04X      \n", class_file->fields[i].access_flag);
      printf("\tAttributes count: %d        \n\n", class_file->fields[i].atributes_count);

      for (j = 0; j < class_file->fields[i].atributes_count; j++) {
        printf("\tGeneric Info\n");
        printf("\t\tattribute_name_index:     cp_info_#%d\n", class_file->fields[i].attributes->attribute_name_index);
        printf("\t\tattribute_length:         %u        \n\n", class_file->fields[i].attributes->attribute_length);
        printf("\tSpecific Info:\n");
        printf("\t\tconstant_value_index:     cp_info_#%d\n", class_file->fields[i].attributes->constant_value_index - 1);
        printf("\n\n\n");
      }
    }
  }
}

//
// void print_fields_info(JavaClass* class_file) {
//   printf("\nField Info: \n");
//
//   for (int i = 0; i < class_file->field_count; i++){
//     FieldInfo *field = class_file->fields + i;
//     printf("Name: cp info #%d ", field->name_index);
//     printf("<<");
//
//     get_UTF8_constant_pool(class_file->contant_pool, field->name_index - 1);
//     // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, field->name_index - 1));
//
//     printf("Descriptor: cp info #%d ", field->descriptor_index);
//     // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, field->descriptor_index - 1));
//     get_UTF8_constant_pool(class_file->contant_pool, field->descriptor_index - 1);
//
//     printf("Access Flag: 0x%04x ", field->access_flag);
//     printf("%d\n", field->access_flag);
//   }
// }
//
// // void print_attributes(JavaClass* class_file, AttributeInfo* attr) {
// // }
//
// char *test_methods_flags(u2 access_flag) {
//   static char string_value[10000];
//   strcpy(string_value, "");
//
//   if(access_flag & ACC_PUBLIC) {
//     strcat(string_value, "public ");
//   }
//   if(access_flag & ACC_PRIVATE) {
//     strcat(string_value, "private ");
//   }
//   if(access_flag & ACC_PROTECTED) {
//     strcat(string_value, "protected ");
//   }
//   if(access_flag & ACC_STATIC) {
//     strcat(string_value, "static ");
//   }
//   if(access_flag & ACC_FINAL) {
//     strcat(string_value, "final ");
//   }
//   if(access_flag & ACC_SYNCRONIZED) {
//     strcat(string_value, "syncronized ");
//   }
//   if(access_flag & ACC_NATIVE) {
//     strcat(string_value, "native ");
//   }
//   if(access_flag & ACC_ABSTRACT) {
//     strcat(string_value, "abstract ");
//   }
//   if(access_flag & ACC_STRICT) {
//     strcat(string_value, "strict ");
//   }
//   return string_value;
// }

// void print_methods_info(JavaClass* class_file) {
//   printf(" ------------- Methods Info:  -------------\n");
//   for(int i = 0; i < class_file->methods_count; i++) {
//     printf("\nMETHOD INFO[%d]\n", i);
//     MethodInfo* cp = class_file->methods+i;
//     printf("Access Flag: 0x%04x ", cp->access_flag);
//     printf("%s\n", test_methods_flags(cp->access_flag));
//
// //  READER TA QUEBRADO
//     printf("Name Index: cp info #%d ",cp->name_index);
//     get_UTF8_constant_pool(class_file->contant_pool, cp->name_index -1);
//     printf("\n");
//
//     printf("Descriptor Index: cp info #%d ",cp->descriptor_index);
//     get_UTF8_constant_pool(class_file->contant_pool, cp->descriptor_index - 1);
//     printf("\n");
//
//     printf("Attributes Count: %d\n",cp->attributes_count);
//     printf("Attributes: \n");
//     for (int j = 0; j < cp->attributes_count; j++){
//       printf("\nATTRIBUTE[%d]\n", j);
//       AttributeInfo* info = cp->attributes +j;
//       print_attributes_on_screen(class_file, info);
//     }
//     printf("\n");
//   }
// }

// void print_attributes_on_screen(JavaClass* class_file, AttributeInfo* info) {
//   char stringValue[100];
//   printf("attribute_name_index: cp info #%d ", info->attribute_name_index);
//   get_UTF8_constant_pool(class_file->contant_pool, info->attribute_name_index - 1);
//   printf("attribute length: %d\n", info->attribute_length) ;
//   strcpy(stringValue, class_file->contant_pool[(info->attribute_name_index)- 1].UTF8.bytes);
//   printf("%s\n", stringValue);
//
//   if(!(strcmp("Code", stringValue))){
//       // TO IMPLEMENT
//     // printAttributeCode(class_file, info->code);
//   }
//   else printf("didnt enter\n" );
// }
//
