/** @file ClassFilePrinter.cpp
 *  @brief Funções de impressão da interface do sistema e exibidor
 *    do arquivo ".class".
 *  @bug No know bugs.
 */
/** @cond */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
 /** @endcond */
#include "ClassFilePrinter.h"
#include "ClassFileReader.h"
#include "Interpreter.h"
#include "Instruction.h"
#include "ReadBytes.h"
#include "InstCode.h"


/** @brief Mostra menu de escolhas entre leitor/exibidor e JVM
 *  @param class_file ponteiro com as informações lidas do .class
 *  @return void
 */
void ClassFilePrinter::print_menu_init() {
  ClassFileReader *reader = new ClassFileReader();
  Interpreter *interpreter = new Interpreter();
  JavaClass class_file;
  std::string filename;
  int option = 0;

  printf("\n\nO que deseja executar:\n");
  printf("1. Leitor/Exibidor\n");
  printf("2. JVM\n");
  printf("0. Sair\n");
  scanf("%d", &option);

  switch (option) {
    case 1:
      if (DEBUG) std::cout << "get filename\n";
      // escolhe o tipo de arquivo que deseja ler/exibir
      filename = print_menu_choose_type_file("Leitor/Exibidor");
      if (DEBUG) std::cout << "filename : " << filename << std::endl;
      // passa o nome do arquivo .class como argumento para função de leitura
      class_file = reader->read_class_file(filename);
      // exibe os dados gerais do arquivo .class informado pelo usuário
      print_general_info(class_file, filename);
      // menu de escolhas do exibidor
      print_menu_exhibitor(class_file);
      break;
    case 2:
      // escolhe o tipo de arquivo que deseja executar
      filename = print_menu_choose_type_file("JVM");
      // passa o nome do arquivo .class como argumento para função de leitura
      class_file = reader->read_class_file(filename);
      printf("Interpretando...\n");
      interpreter->current_path_folder = "test";
      interpreter->execute(class_file);
      break;
    case 0:
      printf("Até mais!\n");
      exit(0);
    default:
      printf("Opção não existe, tente novamente. Pressione enter...\n");
      char command;
      scanf("%c", &command);
      while ((command = getchar()) != '\n' && command != EOF) { };
      print_menu_init();
  }
}


/** @brief Mostra menu inicial para escolher tipo de arquivo java de teste.
*  @return ...
*/
std::string ClassFilePrinter::print_menu_choose_type_file(std::string title) {
  int option = 0;
  std::string filename;

  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
  std::cout << "\n\n" << title << "\n";
  printf("---------------------\n");

  printf("Insira qual tipo de arquivo java gostaria de testar:\n");
  printf("1. Testar novo arquivo\n");
  printf("2. String\n");
  printf("3. Simulação de impressão\n");
  printf("4. Vetor unidimensional\n");
  printf("5. Vetor multidimensional\n");
  printf("6. Herança\n");
  printf("7. Reescrita\n");
  printf("8. Float\n");
  printf("9. Interface\n");
  printf("10. Inteiro\n");
  printf("11. Polimorfismo\n");
  printf("12. Double\n");
  printf("13. Static\n");
  printf("14. Atributo de instancia\n");
  printf("15. Atributo de classe\n");
  printf("16. Metodos Dinamicos\n");
  printf("17. Attributos\n");
  printf("18. Long\n");
  printf("19. Classe Abstrata\n");
  printf("20. Geral\n");
  printf("21. vetor2-java6\n");
  printf("22. vetor ladeira\n");
  printf("23. Goto\n");
  printf("24. Class x Nome do Arquivo\n");
  printf("25. Short\n");
  printf("0. Sair\n");
  scanf("%d", &option);

  switch (option) {
    case 1:
      std::cout << "Nome do arquivo: ";
      std::cin >> filename;
      filename = "test/"+filename;
      break;
    case 2:
      filename = "test/StringDemo.class";
      break;
    case 3:
      filename = "test/PrintDemo.class";
      break;
    case 4:
      filename = "test/ArrayUniDemo.class";
      break;
    case 5:
      filename = "test/ArrayMultDemo.class";
      break;
    case 6:
      filename = "test/SuperClassInheritanceDemo.class";
      break;
    case 7:
      filename = "test/RewriteDemo.class";
      break;
    case 8:
      filename = "test/FloatDemo.class";
      break;
    case 9:
      filename = "test/InterfaceDemo.class";
      break;
    case 10:
      filename = "test/IntegerDemo.class";
      break;
    case 11:
      filename = "test/PolDemo.class";
      break;
    case 12:
      filename = "test/DoubleDemo.class";
      break;
    case 13:
      filename = "test/MethodStaticDemo.class";
      break;
    case 14:
      filename = "test/AttributeInstDemo.class";
      break;
    case 15:
      filename = "test/AttributeClassDemo.class";
      break;
    case 16:
      filename = "test/MethodDynamicDemo.class";
      break;
    case 17:
      filename = "test/AttributesDemo.class";
      break;
    case 18:
      filename = "test/LongDemo.class";
      break;
    case 19:
      filename = "test/AbstractClassDemo.class";
      break;
    case 20:
      filename = "test/a.class";
      break;
    case 21:
      filename = "test/vetor2-java6.class";
      break;
    case 22:
      filename = "test/vetor.class";
      break;
    case 23:
      filename = "test/Goto.class";
    case 24:
      filename = "test/UmNome.class";
    case 25:
      filename = "test/ShortDemo.class";
      break;
    case 0:
      printf("Até mais!\n");
      exit(0);
    default:
      printf("Opção não existe, tente novamente. Pressione enter...\n");
      char command;
      scanf("%c", &command);
      while ((command = getchar()) != '\n' && command != EOF) { };
      print_menu_choose_type_file(title);
  }

  return filename;
}

/** @brief Mostra informações básicas do Class File.
*  @param class_file ponteiro com as informações lidas do .class
*  @param filename ...
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
  std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
  class_file.constant_pool[(class_file.this_class)-1].Class.type_class_info-1)
  << " >";
  printf("\nSuper class:          cp_info #%d < ", class_file.super_class);
  std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
  class_file.constant_pool[(class_file.super_class)-1].Class.type_class_info-1)
  << " >";
  printf("\nInterface count:      %d\n", class_file.interfaces_count);
  printf("Field count:            %d\n", class_file.fields_count);
  printf("Methods count:          %d\n", class_file.methods_count);
  printf("Attributes count:       %d\n", class_file.attributes_count);
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
      print_interfaces(class_file);
      break;
    case 3:
      print_fields_info(class_file);
      break;
    case 4:
      print_method(class_file);
      break;
    case 5:
      print_attributes_methods(class_file);
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

/** @brief Mostra as interfaces contidas no .class
 *  @param class_file
 *  @return void
 */
void ClassFilePrinter::print_interfaces(JavaClass class_file){
  std::cout << std::endl << "--------------- Interfaces Info ---------------"<< std::endl;

  for (int i = 0; i < class_file.interfaces_count; i++)
  {
    std::cout << "Interfaces"<< std::endl;

    std::cout << "\tInterface #"<< std::dec << class_file.interfaces[i].interface_table;
    std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                                    (class_file.interfaces->interface_table +i)-1)<< std::endl;
    printf("\n");
  }
}

/*  @brief Mostra os fields contidos no .class
 *  @param class_file ...
 *  @return void
 */
void ClassFilePrinter::print_fields_info(JavaClass class_file) {
  int i, j;
  std::cout << "\n------------- Methods Info:  -------------\n";
  std::cout << "Member count: " << class_file.fields_count << std::endl;

  if (class_file.fields_count != 0) {
    for (i = 0; i < class_file.fields_count; i++) {
      printf("FIELDS_INFO[%d]\n", i);
      printf("\tName:             cp_info_#%d ",
            class_file.fields[i].name_index);
      std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                                          class_file.fields[i].name_index - 1)
                                          << std::endl;
      printf("\tDescriptor:       cp_info_#%d ",
            class_file.fields[i].descriptor_index);
      std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                                    class_file.fields[i].descriptor_index - 1)
                                    << std::endl;

      printf("\tAccess Flag:      0x%04x ",
            class_file.fields[i].access_flag);
      printf("%d\n", class_file.fields[i].access_flag);

      printf("\tAttributes count: %d        \n\n",
            class_file.fields[i].atributes_count);

      FieldInfo info_fields = class_file.fields[i];

      //TODO:IMPLEMENTAR O ATRIBUTOS DO FIELDS
      for (j = 0; j < info_fields.atributes_count; j++) {
        this->print_attributes_methods(class_file, info_fields.attributes[j]);
      }
    }
  }
}

/** @brief Mostra os métodos contidos no .class
 *  @param class_file
 *  @return void
 */
void ClassFilePrinter::print_method(JavaClass class_file) {
  int counter_attr = 0, counter_method = 0;
  printf(" ------------- Methods Info:  -------------\n");

  for (counter_method = 0; counter_method < class_file.methods_count; counter_method++) {
    printf("\nMETHOD INFO[%d]\n", counter_method);
    MethodInfo* cp = class_file.methods+counter_method;

    printf("Name Index: cp info #%d ",cp->name_index);
    std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                                                cp->name_index -1)
                                                << std::endl;

    printf("Descriptor Index: cp info #%d ",cp->descriptor_index);
    std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                                              cp->descriptor_index - 1)
                                              << std::endl;

    printf("Access Flag: 0x%04x\n", cp->access_flag);

    printf("Attributes Count: %d\n",cp->attributes_count);
    printf("\nATTRIBUTES:\n");
    for (counter_attr = 0; counter_attr < cp->attributes_count; counter_attr++) {
      printf("\nATTRIBUTE[%d]\n", counter_attr);
      print_attributes_methods(class_file, cp->attributes[counter_attr]);
    }
    printf("\n");
  }
}

/** @brief Mostra os atributos contidos no .class
 *  @param class_file ...
 *  @return void
 */
void ClassFilePrinter::print_attributes_methods(JavaClass class_file) {
  std::cout << "\n------------- Attributtes Info -------------" << std::endl;

  printf("attribute_name_index: cp info #%d ",
        class_file.attributes[0].attribute_name_index);
  std::string attribute_type = cpinfo->get_utf8_constant_pool(
                            class_file.constant_pool,
                            class_file.attributes->attribute_name_index - 1);
  std::cout << attribute_type << std::endl;

  printf("attribute length: %d\n", class_file.attributes->attribute_length) ;

  if(!attribute_type.compare("Code")) {
    print_attr_code(class_file, class_file.attributes->code);
  }
  else if(attribute_type == "ConstantValue"){
    print_attr_constant_value(class_file,
                              class_file.attributes->constant_value);
  }
  else if (!attribute_type.compare("LineNumberTable"))   {
    print_attr_number_table(class_file,
                            class_file.attributes->line_number_table);
  }
  else if (!attribute_type.compare("SourceFile")) {
    print_attr_source_file(class_file,
                          class_file.attributes->source_file);
  }
}

/** @brief Mostra os atributos dentro de métodos contidos no .class
 *  @param class_file ...
 *  @param attribute_info ...
 *  @return void
 */
void ClassFilePrinter::print_attributes_methods(JavaClass class_file,
                                                AttributeInfo attribute_info) {
  std::cout << "\n------------- Attributtes Info -------------" << std::endl;

  printf("attribute_name_index: cp info #%d ",
        attribute_info.attribute_name_index);
  std::string attribute_type = cpinfo->get_utf8_constant_pool(
                                      class_file.constant_pool,
                                      attribute_info.attribute_name_index - 1);
  std::cout << attribute_type << std::endl;

  printf("attribute length: %d\n", attribute_info.attribute_length) ;

  if (!attribute_type.compare("Code"))   {
    print_attr_code(class_file, attribute_info.code);
  }
  else if (attribute_type == "ConstantValue") {
    print_attr_constant_value(class_file, attribute_info.constant_value);
  }
  else if (!attribute_type.compare("LineNumberTable")) {
    print_attr_number_table(class_file, attribute_info.line_number_table);
  }
  else if (!attribute_type.compare("SourceFile")) {
    print_attr_source_file(class_file, attribute_info.source_file);
  }
}

/** @brief Mostra os atributos Code dentro de métodos
 *  @param class_file ...
 *  @param info_code ...
 *  @return void
 */
void ClassFilePrinter::print_attr_code(JavaClass class_file,
                                      CodeAttribute info_code) {
  printf("Max stack: %d\n", info_code.max_stack);
  printf("Max locals: %d\n", info_code.max_locals);
  printf("Code length: %d\n", info_code.code_length);
  printf("Exception table length: %d\n", info_code.exception_table_length);

  printf("Code: \n");
  print_instructions(class_file, info_code);

  printf("Attributes count: %d\n", info_code.attributes_count);
  for (int i = 0; i < info_code.attributes_count; ++i) {
    print_attributes_methods(class_file, info_code.attributes[i]);
  }
}

/** @brief Mostra cada instruções do .class
 *  @param class_file ...
 *  @param info_code ...
 *  @return void
 */
void ClassFilePrinter::print_instructions(JavaClass class_file,
                                          CodeAttribute info_code) {
  Instruction instructions[256];
  Instruction::setup_instructions(instructions);

  for (int i = 0; (unsigned)i < info_code.code_length; i++) {

    // printf("\nCode Lenght: %d\n\n", info_code.code_length);
    int op_code = (int)info_code.code[i];
    // printf("\nDEBUG: op code: %d \n", op_code);
    std::cout << "\t"<< i << ": " << instructions[op_code].name;
    for (int j = 0; (unsigned)j < instructions[op_code].bytes; j++) {
        ++i;
        if (op_code == ldc) {
          u1 index = info_code.code[i];
          u2 index_utf8 = 0x00|index;
          std::cout << " #" << (int)index << " "
                    << class_file.constant_pool->get_utf8_constant_pool(
                                    class_file.constant_pool, index_utf8-1);
          j++;
        }
        else if (op_code == newarray) {
          printf(" %x", info_code.code[j]);
          switch (info_code.code[j]) {
            case T_BOOLEAN: std::cout << " (bool)"; break;
            case T_CHAR : std::cout << " (char)"; break;
            case T_FLOAT : std::cout << " (float)"; break;
            case T_DOUBLE : std::cout << " (double)"; break;
            case T_BYTE : std::cout << " (byte)"; break;
            case T_SHORT : std::cout << " (short)"; break;
            case T_INT : std::cout << " (int)"; break;
            case T_LONG : std::cout << " (long)"; break;
          }
          j++;
        }
        else if (op_code == multianewarray) {
          u1 byte1 = info_code.code[i];
          u1 byte2 = info_code.code[i+1];
          u1 dim = info_code.code[i+2];
          u2 index = (byte1<<8)|byte2;
          std::string str = class_file.constant_pool->get_utf8_constant_pool(
                          class_file.constant_pool, index-1);
          if (!str.empty()) {
            std::cout << " #" << index << " " << str;
            std::cout << " dim " << (int)dim;
          }
          j++;
        }
        else if (op_code == anewarray || op_code == checkcast ||
            op_code == getfield || op_code == getstatic ||
            op_code == instanceof || op_code == invokespecial ||
            op_code == invokestatic || op_code == invokevirtual ||
            op_code == ldc_w || op_code == ldc2_w || op_code == NEW ||
            op_code == putfield || op_code == putstatic) {

            u1 byte1 = info_code.code[i];
            u1 byte2 = info_code.code[i+1];
            u2 index = (byte1<<8)|byte2;
            std::cout << " #" << index << " "
                      << class_file.constant_pool->get_utf8_constant_pool(
                                      class_file.constant_pool, index-1);

            i++;
            j++;
        }
        else if (op_code == GOTO || op_code == if_acmpeq ||
                op_code == if_acmpne || op_code == if_icmpeq ||
                op_code == if_icmpne || op_code == if_icmplt ||
                op_code == if_icmpge || op_code == if_icmpgt ||
                op_code == if_icmple || op_code == iifeq ||
                op_code == ifne || op_code == iflt || op_code == ifge ||
                op_code == ifgt || op_code == ifle || op_code == ifnonull ||
                op_code == ifnull || op_code == jsr) {
            u1 branchbyte1 = info_code.code[i];
            u1 branchbyte2 = info_code.code[i+1];
            u2 address = (branchbyte1 << 8) | branchbyte2;
            printf(" %08X ", address);
            i++;
            j++;
        }

        else printf(" %x ", info_code.code[j]);
    }
    std::cout << std::endl;
  }
  printf("\n");
}

/** @brief Mostra os atributos ConstantValue dentro de métodos
 *  @param class_file ...
 *  @param info_constant ...
 *  @return void
 */
void ClassFilePrinter::print_attr_constant_value(JavaClass class_file,
                                        ConstantValueAttribute info_constant) {
  printf("Constant value index: %d\n", info_constant.constantvalue_index);
}

/** @brief Mostra os atributos LineNumberTable dentro de métodos
 *  @param class_file ...
 *  @param info_number_table ...
 *  @return void
 */
void ClassFilePrinter::print_attr_number_table(JavaClass class_file,
                                  LineNumberTableAttribute info_number_table) {
  int count_number_table;

  printf("Line number table length: %d\n",
        info_number_table.line_number_table_length);
  for (count_number_table = 0;
      count_number_table < info_number_table.line_number_table_length;
      count_number_table++) {
    printf("Start PC: %d\n",
          info_number_table.table[count_number_table].start_pc);
    printf("Line Number: %d\n",
          info_number_table.table[count_number_table].line_pc);
  }
}

/** @brief Mostra os atributos SourceFile dentro de métodos
 *  @param class_file ...
 *  @param info_code ...
 *  @return void
 */
void ClassFilePrinter::print_attr_source_file(JavaClass class_file,
                                              SourceFileAttribute info_code) {
  printf("Sourcefile index: cp info #%d ", info_code.source_file_index);
  std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                                            info_code.source_file_index - 1);
}

/** @brief Mostra informações das constant_pools.
 *  Tabela de estruturas representando string, nomes de classes ou interfaces,
 *  nomes de campos, etc.
 *  @param class_file ponteiro com as informações lidas do .class
 *  @return void
 */
void ClassFilePrinter::print_constant_pool_info(JavaClass class_file) {
  std::cout << "\n\n------- Constant Pool -------\n\n";

  for (int i = 0; i < class_file.constant_pool_count-1; i++) {

    std::cout << "\nCP_INFO[" << std::dec << i+1 << "]" << std::endl;

    // formato de cada entrada é indicado pelo byte tag
    switch (class_file.constant_pool[i].tag) {
      // caso tag seja 1
      case CONSTANT_Utf8:
        std::cout << "CONSTANT_UTF8_info\n";
        std::cout << "\tLength:\t"<< std::dec << class_file.constant_pool[i].UTF8.size << std::endl;
        std::cout << "\tBytes:\t"<< class_file.constant_pool[i].UTF8.bytes << std::endl;
        break;
      // caso tag seja 3
      case CONSTANT_Integer:
        // representa o valor da constante int, em big-endian
        printf("CONSTANT_Integer\n");
        printf("Valor: %d\n", class_file.constant_pool[i].Integer.bytes);
        break;
      // caso tag seja 4
      case CONSTANT_Float:
        printf("CONSTANT_Float\n");
        float valor_f;
        memcpy(&valor_f, &(class_file.constant_pool[i].Float.bytes),
              sizeof(float));
        // representa o valor da constante float, em big-endian, no formato
        // IEEE-754
        printf("Float: %lf\n", valor_f);
        break;
      // caso tag seja 5
      case CONSTANT_Long:
        printf("CONSTANT_Long\n");
        // representa uma constante inteira de 8 bytes em big-endian
        // unsigned
        std::cout << "\tHigh:\t0x" << std::hex << class_file.constant_pool[i].Long.high_bytes << std::endl;
        // printf("\tHigh: 0x%0x\n", class_file.constant_pool[i].Long.high_bytes);
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
        printf("CONSTANT_Double\n");

        std::cout << "\tHigh:\t0x"<< std::hex << class_file.constant_pool[i].Double.high_bytes << std::endl;
        std::cout << "\tLow:\t0x"<< std::hex << class_file.constant_pool[i].Double.low_bytes << std::endl;

        double read_double_value;
        u8 aux;
        // representa uma constante de ponto flutuante de 8 bytes em big-endian
        // no formato IEEE-754
        aux = ((u8)class_file.constant_pool[i].Double.high_bytes << 32) | class_file.constant_pool[i].Double.low_bytes;
        memcpy(&read_double_value, &aux, sizeof(double));

        std::cout << "\tDouble Value:\t"<< read_double_value << std::endl;
        break;
      // caso tag seja 7
      case CONSTANT_Class :
        std::cout << "CONSTANT_Class_info" << std::endl;

        std::cout << "\tName index:\t#" << std::dec << class_file.constant_pool[i].Class.type_class_info << std::endl;
        // exibe nome de uma classe ou interface
        std::cout << "\tClass name:\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                            class_file.constant_pool[i].Class.type_class_info - 1) << std::endl;
      break;
      // caso tag seja 8
      case CONSTANT_String:
        std::cout << "CONSTANT_String" << std::endl;

        // representa sequência de caracteres com a qual o objeto String será
        // iniciado
        std::cout << "\tString:\t#" << std::dec << class_file.constant_pool[i].String.bytes;
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                              class_file.constant_pool[i].String.bytes-1) << std::endl;
        break;
      // caso tag seja 9
      case CONSTANT_Fieldref:
        std::cout << "CONSTANT_Fieldref" << std::endl;

        // representa nome completo da classe ou interface que contem
        // a declaração desse field
        std::cout << "\tClass index:\t#" << std::dec << class_file.constant_pool[i].FieldRef.class_index;
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                          class_file.constant_pool[i].FieldRef.class_index-1) << std::endl;

        // representa um field ou método sem indicar classe ou interface
        // a que pertence
        std::cout << "\tName and Type:\t#" << std::dec << class_file.constant_pool[i].FieldRef.name_and_type_index;
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                  class_file.constant_pool[i].FieldRef.name_and_type_index-1) << std::endl;
        break;
      // caso tag seja 10
      case CONSTANT_Methodref:
        std::cout << "CONSTANT_Methodref"<< std::endl;

        // representa um método
        std::cout << "\tClass index:\t#"<< class_file.constant_pool[i].MethodRef.index;
        // representa nome completo classe que contem a declaração desse método
        std::cout << " \t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                              class_file.constant_pool[i].MethodRef.index-1);
        std::cout << std::endl;


        std::cout << "\tName and Type:\t#"<< class_file.constant_pool[i].MethodRef.name_and_type;
        // indica nome e descritor do método
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                        class_file.constant_pool[i].MethodRef.name_and_type-1);
        std::cout << std::endl;
        break;
      // caso tag seja 11
      case CONSTANT_InterfaceMethodref:
        std::cout << "CONSTANT_InterfaceMethodref"<< std::endl;

        // representa nome completo da interface que contem a declaração desse
        // método
        std::cout << "Index:"<< std::endl;
        std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                      class_file.constant_pool[i].InterfaceMethodRef.index-1)<< std::endl;

        // indica nome e descritor do método
        std::cout << "Name and Type:"<< std::endl;
        std::cout << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
              class_file.constant_pool[i].InterfaceMethodRef.name_and_type-1);
        break;
      // caso tag seja 12
      case CONSTANT_NameAndType:
        std::cout << "CONSTANT_NameAndType:"<< std::endl;

        // printf("Name index: ");
        std::cout << "\tName:\t\t#"<< class_file.constant_pool[i].NameAndType.name_index;
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                        class_file.constant_pool[i].NameAndType.name_index-1) << std::endl;
        // printf("\nDescriptor index: ");
        std::cout << "\tDescriptor:\t#"<< class_file.constant_pool[i].NameAndType.descriptor_index;
        std::cout << "\t" << cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                  class_file.constant_pool[i].NameAndType.descriptor_index-1) << std::endl;
        break;
      case CONSTANT_EmptySpace:
        std::cout << "\tLarge numeric continued / empty item"<< std::endl;
        break;
      default:
        printf("Tag %d. Wrong tag number. Shutting down.\n",
                class_file.constant_pool[i].tag);
        exit(1);
    }
    printf("\n");
  }
}
