#include "ClassFilePrinter.h"
#include <string.h>

void get_UTF8_constant_pool(CpInfo *cp_info, uint32_t pos_info) {
  // static char string_value[10000];
  int tag = cp_info[pos_info].tag;

  switch (tag){
    case CONSTANT_Utf8:
      printf("%s\n", (char*)cp_info[pos_info].UTF8.bytes);
      // strcpy(string_value, (char*)cp_info[pos_info].UTF8.bytes);
      break;
    case CONSTANT_Class:
      get_UTF8_constant_pool(cp_info, cp_info[pos_info].Class.type_class_info-1);
      // strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].Class.type_class_info-1));
      break;
    case CONSTANT_Fieldref:
      get_UTF8_constant_pool(cp_info, cp_info[pos_info].FieldRef.class_index-1);
      // strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].FieldRef.class_index-1));
      get_UTF8_constant_pool(cp_info, cp_info[pos_info].FieldRef.name_and_type_index-1);
      // strcat(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].FieldRef.name_and_type_index-1));
      break;
    case CONSTANT_NameAndType:
      get_UTF8_constant_pool(cp_info, cp_info[pos_info].NameAndType.name_index-1);
      // strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].NameAndType.name_index-1));
      get_UTF8_constant_pool(cp_info, cp_info[pos_info].NameAndType.descriptor_index-1);
      // strcat(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].NameAndType.descriptor_index-1));
      break;
    case CONSTANT_Methodref:
      get_UTF8_constant_pool(cp_info, cp_info[pos_info].MethodRef.index-1);
      // strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].MethodRef.index-1));
      get_UTF8_constant_pool(cp_info, cp_info[pos_info].MethodRef.name_and_type-1);
      // strcat(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].MethodRef.name_and_type-1));
      break;
    case CONSTANT_InterfaceMethodref:
      get_UTF8_constant_pool(cp_info, cp_info[pos_info].InterfaceMethodRef.index-1);
      // strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].InterfaceMethodRef.index-1));
      get_UTF8_constant_pool(cp_info, cp_info[pos_info].InterfaceMethodRef.name_and_type-1);
      // strcat(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].InterfaceMethodRef.name_and_type-1));
      break;
    case CONSTANT_String:
      get_UTF8_constant_pool(cp_info, cp_info[pos_info].String.bytes-1);
      // strcpy(string_value, get_UTF8_constant_pool(cp_info, cp_info[pos_info].String.bytes-1));
      break;
    default:
      break;
  }
  // return string_value;
}

void print_formatted_class_file(JavaClass* class_file) {
  printf("Magic Number: 0x%0X\n", class_file->magic_number);
  printf("Minor Version: %d\n", class_file->minor_version);
  printf("Major version: %d\n", class_file->major_version);
  printf("Contanst pool count: %d\n", class_file->constant_pool_count);
  printf("Interface count: %d\n", class_file->interface_count);
  printf("Field count: %d\n", class_file->field_count);
  printf("Methods count: %d\n", class_file->methods_count);
}

void print_menu_options() {
  printf("Opcoes:\n");
  printf("1 - Constant Pool\n");
  printf("2 - Interfaces\n");
  printf("3 - Fields\n");
  printf("4 - Methods\n");
  printf("-1 - Sair\n");
  printf(">> ");
}

void print_constant_pool_info(JavaClass* class_file) {
  float float_value;
  long long_value;
  double double_value;
  uint64_t aux;

  printf("\n\nConstant Pool Info: \n\n");
  for (int i = 0; i < class_file->constant_pool_count-1; i++) {
    CpInfo* cp_info = class_file->contant_pool+i;

    printf("\nCP_INFO[%d]\n", i + 1);
    switch (cp_info->tag) {
      case CONSTANT_Integer:
        printf("Integer: \n");
        printf("Valor: %d\n", cp_info->Integer.bytes);
        break;
      case CONSTANT_Float:
        memcpy(&float_value, &(cp_info->Float.bytes), sizeof(float));
        printf("Float: %lf\n", float_value);
        break;
      case CONSTANT_Long:
        printf("Long:\n");
        printf("\tHigh: 0x%0x\n", cp_info->Long.high_bytes);
        printf("\tLow: 0x%0x\n", cp_info->Long.low_bytes);
        memcpy(&long_value, &(cp_info->Long.high_bytes), sizeof(long));
        memcpy(&long_value, &(cp_info->Long.low_bytes), sizeof(long));
        printf("\tLong Value: %ld\n", long_value);
        break;
      case CONSTANT_Double:
        aux = ((uint64_t)cp_info->Double.high_bytes << 32 | cp_info->Double.low_bytes);
        memcpy(&double_value, &(aux), sizeof(double));
        printf("Double:\n");
        printf("\tHigh: 0x%0x\n", cp_info->Double.high_bytes);
        printf("\tLow: 0x%0x\n", cp_info->Double.low_bytes);
        printf("\tDouble Value: %lf\n", double_value);
        break;
      case CONSTANT_Utf8:
        printf("UTF8\n");
        printf("Tamanho: %d - ", cp_info->UTF8.size);
        printf("Valor: %s\n", cp_info->UTF8.bytes);
        break;
      case CONSTANT_String:
        printf("String\n");
        // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->String.bytes-1));
        get_UTF8_constant_pool(class_file->contant_pool, cp_info->String.bytes-1);
        break;
      case CONSTANT_Class :
        printf("Class\n");
        // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->Class.type_class_info-1));
        get_UTF8_constant_pool(class_file->contant_pool, cp_info->Class.type_class_info-1);
        break;
      case CONSTANT_Fieldref:
        printf("FieldRef\n");
        printf("Class index: ");
        get_UTF8_constant_pool(class_file->contant_pool, cp_info->FieldRef.class_index-1);
        // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->FieldRef.class_index-1));
        printf("Name and Type: ");
        get_UTF8_constant_pool(class_file->contant_pool, cp_info->FieldRef.name_and_type_index-1);
        // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->FieldRef.name_and_type_index-1));
        break;
      case CONSTANT_Methodref:
        printf("MethodRef: \n");
        printf("Index: ");
        get_UTF8_constant_pool(class_file->contant_pool, cp_info->MethodRef.index-1);
        // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->MethodRef.index-1));
        printf("Name and Type: ");
        get_UTF8_constant_pool(class_file->contant_pool, cp_info->MethodRef.name_and_type-1);
        // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->MethodRef.name_and_type-1));
        break;
      case CONSTANT_InterfaceMethodref:
        printf("InterfaceMethodRef: \n");
        printf("Index: ");
        get_UTF8_constant_pool(class_file->contant_pool, cp_info->InterfaceMethodRef.index-1);
        // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->InterfaceMethodRef.index-1));
        printf("Name and Type: ");
        get_UTF8_constant_pool(class_file->contant_pool, cp_info->InterfaceMethodRef.name_and_type-1);
        // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->InterfaceMethodRef.name_and_type-1));
        break;
      case CONSTANT_NameAndType:
        printf("NameAndType: \n");
        printf("Name index: ");
        get_UTF8_constant_pool(class_file->contant_pool, cp_info->NameAndType.name_index-1);
        // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->NameAndType.name_index-1));
        printf("Descriptor index: ");
        get_UTF8_constant_pool(class_file->contant_pool, cp_info->NameAndType.descriptor_index-1);
        // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, cp_info->NameAndType.descriptor_index-1));
        break;
      case CONSTANT_EmptySpace:
        printf("(Large numeric continued)\n");
        break;
    }
    printf("\n");
  }
}

void print_interfaces_info(JavaClass* class_file){
  printf("\nInterfaces Info\n");

  for (int i = 0; i < class_file->interface_count; i++) {
    printf("Interface: cp info #%d <", class_file->interfaces[i]);
    get_UTF8_constant_pool(class_file->contant_pool, class_file->interfaces[i]-1);
    // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, class_file->interfaces[i]-1));
    printf("\n");
  }
}

void print_fields_info(JavaClass* class_file){
  printf("\nField Info: \n");

  for (int i = 0; i < class_file->field_count; i++){
    FieldInfo *field = class_file->fields + i;
    printf("Name: cp info #%d ", field->name_index);
    printf("<<");

    get_UTF8_constant_pool(class_file->contant_pool, field->name_index - 1);
    // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, field->name_index - 1));

    printf("Descriptor: cp info #%d ", field->descriptor_index);
    // printf("%s\n", get_UTF8_constant_pool(class_file->contant_pool, field->descriptor_index - 1));
    get_UTF8_constant_pool(class_file->contant_pool, field->descriptor_index - 1);

    printf("Access Flag: 0x%04x ", field->access_flag);
    printf("%d\n", field->access_flag);
  }
}

// void print_attributes(JavaClass* class_file, AttributeInfo* attr) {
// }

char * test_methods_flags(uint16_t access_flag) {
  static char string_value[10000];
  strcpy(string_value, "");

  if(access_flag & ACC_PUBLIC) {
    strcat(string_value, "public ");
  }
  if(access_flag & ACC_PRIVATE) {
    strcat(string_value, "private ");
  }
  if(access_flag & ACC_PROTECTED) {
    strcat(string_value, "protected ");
  }
  if(access_flag & ACC_STATIC) {
    strcat(string_value, "static ");
  }
  if(access_flag & ACC_FINAL) {
    strcat(string_value, "final ");
  }
  if(access_flag & ACC_SYNCRONIZED) {
    strcat(string_value, "syncronized ");
  }
  if(access_flag & ACC_NATIVE) {
    strcat(string_value, "native ");
  }
  if(access_flag & ACC_ABSTRACT) {
    strcat(string_value, "abstract ");
  }
  if(access_flag & ACC_STRICT) {
    strcat(string_value, "strict ");
  }
  return string_value;
}

void print_methods_info(JavaClass* class_file) {
  printf(" ------------- Methods Info:  -------------\n");
  for(int i = 0; i < class_file->methods_count; i++) {
    printf("\nMETHOD INFO[%d]\n", i);
    MethodInfo* cp = class_file->methods+i;
    printf("Access Flag: 0x%04x ", cp->access_flag);
    printf("%s\n", test_methods_flags(cp->access_flag));

//  READER TA QUEBRADO
    printf("Name Index: cp info #%d ",cp->name_index);
    get_UTF8_constant_pool(class_file->contant_pool, cp->name_index -1);
    printf("\n");

    printf("Descriptor Index: cp info #%d ",cp->descriptor_index);
    get_UTF8_constant_pool(class_file->contant_pool, cp->descriptor_index - 1);
    printf("\n");

    printf("Attributes Count: %d\n",cp->attributes_count);
    printf("Attributes: \n");
    for (int j = 0; j < cp->attributes_count; j++){
      printf("\nATTRIBUTE[%d]\n", j);
      AttributeInfo* info = cp->attributes +j;
      printAttributesOnScreen(class_file, info);
    }
    printf("\n");
  }
}

void printAttributesOnScreen(JavaClass* class_file, AttributeInfo* info) {
  char stringValue[100];
  printf("attribute_name_index: cp info #%d ", info->attribute_name_index);
  get_UTF8_constant_pool(class_file->contant_pool, info->attribute_name_index - 1);
  printf("attribute length: %d\n", info->attribute_length) ;
  strcpy(stringValue, class_file->contant_pool[(info->attribute_name_index)- 1].UTF8.bytes);
  printf("%s\n", stringValue);


  if(strcmp("Code", stringValue)){
    printAttributeCode(class_file, info->code);
  }
}

void printAttributeCode(JavaClass *class_file, AttrCode *code){
    printf("Max stack: %d\n", code->maxStack);
    printf("Max locals: %d\n", code->maxLocals);
    printf("Code Length: %d\n", code->codeLength);

    printf("Code: \n");
    printMethodInstructions(class_file, code);

    printf("Exceptions Length: %d\n", code->exceptionsTableLength);
    for (int i = 0; i < code->exceptionsTableLength; ++i) {
        if(i==0)
            printf("Exceptions:\n\n");
        AttrCodeExceptions *code_exception = code->exceptions + i;

        printf("Start PC: %d\n", code_exception->startPc);
        printf("End PC: %d\n", code_exception->endPc);
        printf("Handler PC: %d\n", code_exception->handlerPc);
        printf("Catch Type: ");
        getUTF8StringFromConstantPool(class_file->contant_pool, code_exception->catchType-1);
    }

    printf("Code Attributes count: %d\n", code->attrCounts);
    for (int j = 0; j < code->attrCounts; j++) {
        if(j==0)
            printf("Attributes:\n\n");
        printAttributesOnScreen(class_file, code->attributes+j);
    }
}

void printMethodInstructions(JavaClass *class_file, AttrCode *attrCode) {
    Instrucao instrucoes[QTD_INSTRUCTIONS];
    initVectorDecodificatorInstructions(instrucoes);

    for (int k = 0; k < attrCode->codeLength; k++){
        uint8_t opcode = attrCode->code[k];
        Instrucao opcodeInstruct = instrucoes[opcode];

        if(opcodeInstruct.instructionName == "tableswitch"){ //TODO
            std::cout << "\n" <<k << ": tableswitch" <<std::endl;
        } else if(opcodeInstruct.instructionName == "lookupswitch"){ //TODO
            std::cout << "\n" << k << ": lookupswitch" <<std::endl;
        } else{
            k = printInstruction(javaClassFile, attrCode, k, opcodeInstruct);
        }
    }
    printf("\n\n");
}


void print_info_on_screen(JavaClass* class_file) {
  int option = 0;

  printf("\n\nLeitor/Exibidor: \n");

  while(option != -1) {
    print_formatted_class_file(class_file);
    print_menu_options();
    scanf("%d", &option);

    switch (option) {
      case -1:
        option = -1;
        printf("Saindo do Leitor/Exibidor");
        break;
      case 1:
        print_constant_pool_info(class_file);
        break;
      case 2:
        print_interfaces_info(class_file);
        break;
      case 3:
        print_fields_info(class_file);
        break;
      case 4:
        print_methods_info(class_file);
        break;
    }

  }

}
