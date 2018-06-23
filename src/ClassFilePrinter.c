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


  if(!(strcmp("Code", stringValue))){
    printAttributeCode(class_file, info->code);
  }
  else{
    printf("didnt enter\n" );
  }
}

void printAttributeCode(JavaClass *class_file, AttrCode *code){
    printf("Max stack: %d\n", code->max_stack);
    printf("Max locals: %d\n", code->max_locals);
    printf("Code Length: %d\n", code->code_length);

    printf("Code: \n");
    printMethodInstructions(class_file, code);

    printf("Exceptions Length: %d\n", code->exceptions_table_length);
    for (int i = 0; i < code->exceptions_table_length; ++i) {
        if(i==0)
            printf("Exceptions:\n\n");
        AttrCodeException *code_exception = code->exceptions + i;

        printf("Start PC: %d\n", code_exception->start_pc);
        printf("End PC: %d\n", code_exception->end_pc);
        printf("Handler PC: %d\n", code_exception->handler_pc);
        printf("Catch Type: ");
        get_UTF8_constant_pool(class_file->contant_pool, code_exception->catch_type-1);
    }

    printf("Code Attributes count: %d\n", code->attr_counts);
    for (int j = 0; j < code->attr_counts; j++) {
        if(j==0)
            printf("Attributes:\n\n");
        printAttributesOnScreen(class_file, code->attributes+j);
    }
}

void printMethodInstructions(JavaClass *class_file, AttrCode *attrCode) {
    Instruction instructions[256];
    initVectorDecodificatorInstructions(instructions);
    // printf("passed\n");
    for (int k = 0; k < attrCode->code_length; k++){
        uint8_t opcode = attrCode->code[k];
        Instruction opcodeInstruct = instructions[opcode];
        k = printInstruction(class_file, attrCode, k, opcodeInstruct);
        printf("passed print instruction\n");
    }
    printf("passed\n");
    printf("\n\n");
}

int printInstruction(JavaClass *class_file, AttrCode *attrCode, int k, Instruction opcodeInstruct) {
    // std::cout << "\n" << k << ": " << opcodeInstruct.instructionName;
    printf("entered print instruction\n"   );
    int j;
    for (j = 0; j < opcodeInstruct.bytes; j++) {
        k++;
        uint8_t opData = attrCode->code[k];
        if (opData != 0 && opcodeInstruct.index_constant_pool) {
            printf(" #%d ", opData);
            CpInfo cpInfo = class_file->contant_pool[opData - 1];
            switch(cpInfo.tag){
                case CONSTANT_NameAndType:
                    get_UTF8_constant_pool(class_file->contant_pool, cpInfo.NameAndType.name_index - 1);
                    get_UTF8_constant_pool(class_file->contant_pool, cpInfo.NameAndType.descriptor_index - 1);
                    break;
                case CONSTANT_Fieldref:
                    get_UTF8_constant_pool(class_file->contant_pool, cpInfo.FieldRef.class_index- 1);
                    get_UTF8_constant_pool(class_file->contant_pool, cpInfo.FieldRef.name_and_type_index- 1);
                    break;
                case CONSTANT_Methodref:
                    get_UTF8_constant_pool(class_file->contant_pool, cpInfo.MethodRef.index- 1);
                    get_UTF8_constant_pool(class_file->contant_pool, cpInfo.MethodRef.name_and_type- 1);
                    break;
                case CONSTANT_InterfaceMethodref:
                    get_UTF8_constant_pool(class_file->contant_pool, cpInfo.InterfaceMethodRef.index- 1);
                    get_UTF8_constant_pool(class_file->contant_pool, cpInfo.MethodRef.name_and_type- 1);
                    break;
                default:
                    get_UTF8_constant_pool(class_file->contant_pool, opData - 1);
                    break;
            }
        }
    }
    return k;
}


void initVectorDecodificatorInstructions(Instruction *instructions) {
  instructions[0].name = "nop";
    instructions[0].bytes = 0;

    instructions[1].name = "aconst_null";
    instructions[1].bytes = 0;
    instructions[1].index_constant_pool = 0;

    instructions[2].name = "iconst_m1";
    instructions[2].bytes = 0;
    instructions[2].index_constant_pool = 0;

    instructions[3].name = "iconst_0";
    instructions[3].bytes = 0;
    instructions[3].index_constant_pool = 0;

    instructions[4].name = "iconst_1";
    instructions[4].bytes = 0;
    instructions[4].index_constant_pool = 0;

    instructions[5].name = "iconst_2";
    instructions[5].bytes = 0;
    instructions[5].index_constant_pool = 0;

    instructions[6].name = "iconst_3";
    instructions[6].bytes = 0;
    instructions[6].index_constant_pool = 0;

    instructions[7].name = "iconst_4";
    instructions[7].bytes = 0;
    instructions[7].index_constant_pool = 0;

    instructions[8].name = "iconst_5";
    instructions[8].bytes = 0;
    instructions[8].index_constant_pool = 0;

    instructions[9].name = "lconst_0";
    instructions[9].bytes = 0;
    instructions[9].index_constant_pool = 0;

    instructions[10].name = "lconst_1";
    instructions[10].bytes = 0;
    instructions[10].index_constant_pool = 0;

    instructions[11].name = "fconst_0";
    instructions[11].bytes = 0;
    instructions[11].index_constant_pool = 0;

    instructions[12].name = "fconst_1";
    instructions[12].bytes = 0;
    instructions[12].index_constant_pool = 0;

    instructions[13].name = "fconst_2";
    instructions[13].bytes = 0;
    instructions[13].index_constant_pool = 0;

    instructions[14].name = "dconst_0";
    instructions[14].bytes = 0;
    instructions[14].index_constant_pool = 0;

    instructions[15].name = "dconst_1";
    instructions[15].bytes = 0;
    instructions[15].index_constant_pool = 0;

    instructions[16].name = "bipush";
    instructions[16].bytes = 1;
    instructions[16].index_constant_pool = 0;

    instructions[17].name = "sipush";
    instructions[17].bytes = 2;
    instructions[17].index_constant_pool = 0;

    instructions[18].name = "ldc";
    instructions[18].bytes = 1;
    instructions[18].index_constant_pool = 1;

    instructions[19].name = "ldc_w";
    instructions[19].bytes = 2;
    instructions[19].index_constant_pool = 1;

    instructions[20].name = "ldc2_w";
    instructions[20].bytes = 2;
    instructions[20].index_constant_pool = 1;

    instructions[21].name = "iload";
    instructions[21].bytes = 1;
    instructions[21].index_constant_pool = 0;

    instructions[22].name = "lload";
    instructions[22].bytes = 1;
    instructions[22].index_constant_pool = 0;

    instructions[23].name = "fload";
    instructions[23].bytes = 1;
    instructions[23].index_constant_pool = 0;

    instructions[24].name = "dload";
    instructions[24].bytes = 1;
    instructions[24].index_constant_pool = 0;

    instructions[25].name = "aload";
    instructions[25].bytes = 1;
    instructions[25].index_constant_pool = 0;

    instructions[26].name = "iload_0";
    instructions[26].bytes = 0;
    instructions[26].index_constant_pool = 0;

    instructions[27].name = "iload_1";
    instructions[27].bytes = 0;
    instructions[27].index_constant_pool = 0;

    instructions[28].name = "iload_2";
    instructions[28].bytes = 0;
    instructions[28].index_constant_pool = 0;

    instructions[29].name = "iload_3";
    instructions[29].bytes = 0;
    instructions[29].index_constant_pool = 0;

    instructions[30].name = "lload_0";
    instructions[30].bytes = 0;
    instructions[30].index_constant_pool = 0;

    instructions[31].name = "lload_1";
    instructions[31].bytes = 0;
    instructions[31].index_constant_pool = 0;

    instructions[32].name = "lload_2";
    instructions[32].bytes = 0;
    instructions[32].index_constant_pool = 0;

    instructions[33].name = "lload_3";
    instructions[33].bytes = 0;
    instructions[33].index_constant_pool = 0;

    instructions[34].name = "fload_0";
    instructions[34].bytes = 0;
    instructions[34].index_constant_pool = 0;

    instructions[35].name = "fload_1";
    instructions[35].bytes = 0;
    instructions[35].index_constant_pool = 0;

    instructions[36].name = "fload_2";
    instructions[36].bytes = 0;
    instructions[36].index_constant_pool = 0;

    instructions[37].name = "fload_3";
    instructions[37].bytes = 0;
    instructions[37].index_constant_pool = 0;

    instructions[38].name = "dload_0";
    instructions[38].bytes = 0;
    instructions[38].index_constant_pool = 0;

    instructions[39].name = "dload_1";
    instructions[39].bytes = 0;
    instructions[39].index_constant_pool = 0;

    instructions[40].name = "dload_2";
    instructions[40].bytes = 0;
    instructions[40].index_constant_pool = 0;

    instructions[41].name = "dload_3";
    instructions[41].bytes = 0;
    instructions[41].index_constant_pool = 0;

    instructions[42].name = "aload_0";
    instructions[42].bytes = 0;
    instructions[42].index_constant_pool = 0;

    instructions[43].name = "aload_1";
    instructions[43].bytes = 0;
    instructions[43].index_constant_pool = 0;

    instructions[44].name = "aload_2";
    instructions[44].bytes = 0;
    instructions[40].index_constant_pool = 0;

    instructions[45].name = "aload_3";
    instructions[45].bytes = 0;
    instructions[45].index_constant_pool = 0;

    instructions[46].name = "iaload";
    instructions[46].bytes = 0;
    instructions[46].index_constant_pool = 0;

    instructions[47].name = "laload";
    instructions[47].bytes = 0;
    instructions[47].index_constant_pool = 0;

    instructions[48].name = "faload";
    instructions[48].bytes = 0;
    instructions[48].index_constant_pool = 0;

    instructions[49].name = "daload";
    instructions[49].bytes = 0;
    instructions[49].index_constant_pool = 0;

    instructions[50].name = "aaload";
    instructions[50].bytes = 0;
    instructions[50].index_constant_pool = 0;

    instructions[51].name = "baload";
    instructions[51].bytes = 0;
    instructions[51].index_constant_pool = 0;

    instructions[52].name = "caload";
    instructions[52].bytes = 0;
    instructions[52].index_constant_pool = 0;

    instructions[53].name = "saload";
    instructions[53].bytes = 0;
    instructions[53].index_constant_pool = 0;

    instructions[54].name = "istore";
    instructions[54].bytes = 1;
    instructions[54].index_constant_pool = 0;

    instructions[55].name = "lstore";
    instructions[55].bytes = 1;
    instructions[55].index_constant_pool = 0;

    instructions[56].name = "fstore";
    instructions[56].bytes = 1;
    instructions[56].index_constant_pool = 0;

    instructions[57].name = "dstore";
    instructions[57].bytes = 1;
    instructions[57].index_constant_pool = 0;

    instructions[58].name = "astore";
    instructions[58].bytes = 1;
    instructions[58].index_constant_pool = 0;

    instructions[59].name = "istore_0";
    instructions[59].bytes = 0;
    instructions[59].index_constant_pool = 0;

    instructions[60].name = "istore_1";
    instructions[60].bytes = 0;
    instructions[60].index_constant_pool = 0;

    instructions[61].name = "istore_2";
    instructions[61].bytes = 0;
    instructions[61].index_constant_pool = 0;

    instructions[62].name = "istore_3";
    instructions[62].bytes = 0;
    instructions[62].index_constant_pool = 0;

    instructions[63].name = "lstore_0";
    instructions[63].bytes = 0;
    instructions[63].index_constant_pool = 0;

    instructions[64].name = "lstore_1";
    instructions[64].bytes = 0;
    instructions[64].index_constant_pool = 0;

    instructions[65].name = "lstore_2";
    instructions[65].bytes = 0;
    instructions[65].index_constant_pool = 0;

    instructions[66].name = "lstore_3";
    instructions[66].bytes = 0;
    instructions[66].index_constant_pool = 0;

    instructions[67].name = "fstore_0";
    instructions[67].bytes = 0;
    instructions[67].index_constant_pool = 0;

    instructions[68].name = "fstore_1";
    instructions[68].bytes = 0;
    instructions[68].index_constant_pool = 0;

    instructions[69].name = "fstore_2";
    instructions[69].bytes = 0;
    instructions[69].index_constant_pool = 0;

    instructions[70].name = "fstore_3";
    instructions[70].bytes = 0;
    instructions[70].index_constant_pool = 0;

    instructions[71].name = "dstore_0";
    instructions[71].bytes = 0;
    instructions[71].index_constant_pool = 0;

    instructions[72].name = "dstore_1";
    instructions[72].bytes = 0;
    instructions[72].index_constant_pool = 0;

    instructions[73].name = "dstore_2";
    instructions[73].bytes = 0;
    instructions[73].index_constant_pool = 0;

    instructions[74].name = "dstore_3";
    instructions[74].bytes = 0;
    instructions[74].index_constant_pool = 0;

    instructions[75].name = "astore_0";
    instructions[75].bytes = 0;
    instructions[75].index_constant_pool = 0;

    instructions[76].name = "astore_1";
    instructions[76].bytes = 0;
    instructions[76].index_constant_pool = 0;

    instructions[77].name = "astore_2";
    instructions[77].bytes = 0;
    instructions[77].index_constant_pool = 0;

    instructions[78].name = "astore_3";
    instructions[78].bytes = 0;
    instructions[78].index_constant_pool = 0;

    instructions[79].name = "iastore";
    instructions[79].bytes = 0;
    instructions[79].index_constant_pool = 0;

    instructions[80].name = "lastore";
    instructions[80].bytes = 0;
    instructions[80].index_constant_pool = 0;

    instructions[81].name = "fastore";
    instructions[81].bytes = 0;
    instructions[81].index_constant_pool = 0;

    instructions[82].name = "dastore";
    instructions[82].bytes = 0;
    instructions[82].index_constant_pool = 0;

    instructions[83].name = "aastore";
    instructions[83].bytes = 0;
    instructions[83].index_constant_pool = 0;

    instructions[84].name = "bastore";
    instructions[84].bytes = 0;
    instructions[84].index_constant_pool = 0;

    instructions[85].name = "castore";
    instructions[85].bytes = 0;
    instructions[85].index_constant_pool = 0;

    instructions[86].name = "sastore";
    instructions[86].bytes = 0;
    instructions[86].index_constant_pool = 0;

    instructions[87].name = "pop";
    instructions[87].bytes = 0;
    instructions[87].index_constant_pool = 0;

    instructions[88].name = "pop2";
    instructions[88].bytes = 0;
    instructions[88].index_constant_pool = 0;

    instructions[89].name = "dup";
    instructions[89].bytes = 0;
    instructions[89].index_constant_pool = 0;

    instructions[90].name = "dup_x1";
    instructions[90].bytes = 0;
    instructions[90].index_constant_pool = 0;

    instructions[91].name = "dup_x2";
    instructions[91].bytes = 0;
    instructions[91].index_constant_pool = 0;

    instructions[92].name = "dup2";
    instructions[92].bytes = 0;
    instructions[92].index_constant_pool = 0;

    instructions[93].name = "dup2_x1";
    instructions[93].bytes = 0;
    instructions[93].index_constant_pool = 0;

    instructions[94].name = "dup2_x2";
    instructions[94].bytes = 0;
    instructions[94].index_constant_pool = 0;

    instructions[95].name = "swap";
    instructions[95].bytes = 0;
    instructions[95].index_constant_pool = 0;

    instructions[96].name = "iadd";
    instructions[96].bytes = 0;
    instructions[96].index_constant_pool = 0;

    instructions[97].name = "ladd";
    instructions[97].bytes = 0;
    instructions[97].index_constant_pool = 0;

    instructions[98].name = "fadd";
    instructions[98].bytes = 0;
    instructions[98].index_constant_pool = 0;

    instructions[99].name = "dadd";
    instructions[99].bytes = 0;
    instructions[99].index_constant_pool = 0;

    instructions[100].name = "isub";
    instructions[100].bytes = 0;
    instructions[100].index_constant_pool = 0;

    instructions[101].name = "lsub";
    instructions[101].bytes = 0;
    instructions[101].index_constant_pool = 0;

    instructions[102].name = "fsub";
    instructions[102].bytes = 0;
    instructions[102].index_constant_pool = 0;

    instructions[103].name = "dsub";
    instructions[103].bytes = 0;
    instructions[103].index_constant_pool = 0;

    instructions[104].name = "imul";
    instructions[104].bytes = 0;
    instructions[104].index_constant_pool = 0;

    instructions[105].name = "lmul";
    instructions[105].bytes = 0;
    instructions[105].index_constant_pool = 0;

    instructions[106].name = "fmul";
    instructions[106].bytes = 0;
    instructions[106].index_constant_pool = 0;

    instructions[107].name = "dmul";
    instructions[107].bytes = 0;
    instructions[107].index_constant_pool = 0;

    instructions[108].name = "idiv";
    instructions[108].bytes = 0;
    instructions[108].index_constant_pool = 0;

    instructions[109].name = "ldiv";
    instructions[109].bytes = 0;
    instructions[109].index_constant_pool = 0;

    instructions[110].name = "fdiv";
    instructions[110].bytes = 0;
    instructions[110].index_constant_pool = 0;

    instructions[111].name = "ddiv";
    instructions[111].bytes = 0;
    instructions[111].index_constant_pool = 0;

    instructions[112].name = "irem";
    instructions[112].bytes = 0;
    instructions[112].index_constant_pool = 0;

    instructions[113].name = "lrem";
    instructions[113].bytes = 0;
    instructions[113].index_constant_pool = 0;

    instructions[114].name = "frem";
    instructions[114].bytes = 0;
    instructions[114].index_constant_pool = 0;

    instructions[115].name = "drem";
    instructions[115].bytes = 0;
    instructions[115].index_constant_pool = 0;

    instructions[116].name = "ineg";
    instructions[116].bytes = 0;
    instructions[116].index_constant_pool = 0;

    instructions[117].name = "lneg";
    instructions[117].bytes = 0;
    instructions[117].index_constant_pool = 0;

    instructions[118].name = "fneg";
    instructions[118].bytes = 0;
    instructions[118].index_constant_pool = 0;

    instructions[119].name = "dneg";
    instructions[119].bytes = 0;
    instructions[119].index_constant_pool = 0;

    instructions[120].name = "ishl";
    instructions[120].bytes = 0;
    instructions[120].index_constant_pool = 0;

    instructions[121].name = "lshl";
    instructions[121].bytes = 0;
    instructions[121].index_constant_pool = 0;

    instructions[122].name = "ishr";
    instructions[122].bytes = 0;
    instructions[122].index_constant_pool = 0;

    instructions[123].name = "lshr";
    instructions[123].bytes = 0;
    instructions[123].index_constant_pool = 0;

    instructions[124].name = "iushr";
    instructions[124].bytes = 0;
    instructions[124].index_constant_pool = 0;

    instructions[125].name = "lushr";
    instructions[125].bytes = 0;
    instructions[125].index_constant_pool = 0;

    instructions[126].name = "iand";
    instructions[126].bytes = 0;
    instructions[126].index_constant_pool = 0;

    instructions[127].name = "land";
    instructions[127].bytes = 0;
    instructions[127].index_constant_pool = 0;

    instructions[128].name = "ior";
    instructions[128].bytes = 0;
    instructions[128].index_constant_pool = 0;

    instructions[129].name = "lor";
    instructions[129].bytes = 0;
    instructions[129].index_constant_pool = 0;

    instructions[130].name = "ixor";
    instructions[130].bytes = 0;
    instructions[130].index_constant_pool = 0;

    instructions[131].name = "lxor";
    instructions[131].bytes = 0;
    instructions[131].index_constant_pool = 0;

    instructions[132].name = "iinc";
    instructions[132].bytes = 2;
    instructions[132].index_constant_pool = 0;

    instructions[133].name = "i2l";
    instructions[133].bytes = 0;
    instructions[133].index_constant_pool = 0;

    instructions[134].name = "i2f";
    instructions[134].bytes = 0;
    instructions[134].index_constant_pool = 0;

    instructions[135].name = "i2d";
    instructions[135].bytes = 0;
    instructions[135].index_constant_pool = 0;

    instructions[136].name = "l2i";
    instructions[136].bytes = 0;
    instructions[136].index_constant_pool = 0;

    instructions[137].name = "l2f";
    instructions[137].bytes = 0;
    instructions[137].index_constant_pool = 0;

    instructions[138].name = "l2d";
    instructions[138].bytes = 0;
    instructions[138].index_constant_pool = 0;

    instructions[139].name = "f2i";
    instructions[139].bytes = 0;
    instructions[139].index_constant_pool = 0;

    instructions[140].name = "f2l";
    instructions[140].bytes = 0;
    instructions[140].index_constant_pool = 0;

    instructions[141].name = "f2d";
    instructions[141].bytes = 0;
    instructions[141].index_constant_pool = 0;

    instructions[142].name = "d2i";
    instructions[142].bytes = 0;
    instructions[142].index_constant_pool = 0;

    instructions[143].name = "d2l";
    instructions[143].bytes = 0;
    instructions[143].index_constant_pool = 0;

    instructions[144].name = "d2f";
    instructions[144].bytes = 0;
    instructions[144].index_constant_pool = 0;

    instructions[145].name = "i2b";
    instructions[145].bytes = 0;
    instructions[145].index_constant_pool = 0;

    instructions[146].name = "i2c";
    instructions[146].bytes = 0;
    instructions[146].index_constant_pool = 0;

    instructions[147].name = "i2s";
    instructions[147].bytes = 0;
    instructions[146].index_constant_pool = 0;

    instructions[148].name = "lcmp";
    instructions[148].bytes = 0;
    instructions[148].index_constant_pool = 0;

    instructions[149].name = "fcmpl";
    instructions[149].bytes = 0;
    instructions[149].index_constant_pool = 0;

    instructions[150].name = "fcmpg";
    instructions[150].bytes = 0;
    instructions[150].index_constant_pool = 0;

    instructions[151].name = "dcmpl";
    instructions[151].bytes = 0;
    instructions[151].index_constant_pool = 0;

    instructions[152].name = "dcmpg";
    instructions[152].bytes = 0;
    instructions[152].index_constant_pool = 0;

    instructions[153].name = "ifeq";
    instructions[153].bytes = 2;
    instructions[153].index_constant_pool = 0;

    instructions[154].name = "ifne";
    instructions[154].bytes = 2;
    instructions[154].index_constant_pool = 0;

    instructions[155].name = "iflt";
    instructions[155].bytes = 2;
    instructions[155].index_constant_pool = 0;

    instructions[156].name = "ifge";
    instructions[156].bytes = 2;
    instructions[156].index_constant_pool = 0;

    instructions[157].name = "ifgt";
    instructions[157].bytes = 2;
    instructions[157].index_constant_pool = 0;

    instructions[158].name = "ifle";
    instructions[158].bytes = 2;
    instructions[158].index_constant_pool = 0;

    instructions[159].name = "if_icmpeq";
    instructions[159].bytes = 2;
    instructions[159].index_constant_pool = 0;

    instructions[160].name = "if_icmpne";
    instructions[160].bytes = 2;
    instructions[160].index_constant_pool = 0;

    instructions[161].name = "if_icmplt";
    instructions[161].bytes = 2;
    instructions[161].index_constant_pool = 0;

    instructions[162].name = "if_icmpg2";
    instructions[162].bytes = 2;
    instructions[162].index_constant_pool = 0;

    instructions[163].name = "if_icmpgt";
    instructions[163].bytes = 2;
    instructions[163].index_constant_pool = 0;

    instructions[164].name = "if_icmple";
    instructions[164].bytes = 2;
    instructions[164].index_constant_pool = 0;

    instructions[165].name = "if_acmpeq";
    instructions[165].bytes = 2;
    instructions[165].index_constant_pool = 0;

    instructions[166].name = "if_acmpne";
    instructions[166].bytes = 2;
    instructions[166].index_constant_pool = 0;

    instructions[167].name = "goto";
    instructions[167].bytes = 2;
    instructions[167].index_constant_pool = 0;

    instructions[168].name = "jsr";
    instructions[168].bytes = 2;
    instructions[168].index_constant_pool = 0;

    instructions[169].name = "ret";
    instructions[169].bytes = 1;
    instructions[169].index_constant_pool = 0;

    instructions[170].name = "tableswitch";
    // instrução tem tamanho variável
    instructions[170].bytes = 34;
    instructions[170].index_constant_pool = 0;

    instructions[171].name = "lookupswitch";
    // instrução tem tamanho variável
    instructions[171].bytes = 26;
    instructions[171].index_constant_pool = 0;

    instructions[172].name = "ireturn";
    instructions[172].bytes = 0;
    instructions[172].index_constant_pool = 0;

    instructions[173].name = "lreturn";
    instructions[173].bytes = 0;
    instructions[173].index_constant_pool = 0;

    instructions[174].name = "freturn";
    instructions[174].bytes = 0;
    instructions[174].index_constant_pool = 0;

    instructions[175].name = "dreturn";
    instructions[175].bytes = 0;
    instructions[175].index_constant_pool = 0;

    instructions[176].name = "areturn";
    instructions[176].bytes = 0;
    instructions[176].index_constant_pool = 0;

    instructions[177].name = "return";
    instructions[177].bytes = 0;
    instructions[177].index_constant_pool = 0;

    instructions[178].name = "getstatic";
    instructions[178].bytes = 2;
    instructions[178].index_constant_pool = 1;

    instructions[179].name = "putstatic";
    instructions[179].bytes = 2;
    instructions[179].index_constant_pool = 1;

    instructions[180].name = "getfield";
    instructions[180].bytes = 2;
    instructions[180].index_constant_pool = 1;

    instructions[181].name = "putfield";
    instructions[181].bytes = 2;
    instructions[181].index_constant_pool = 1;

    instructions[182].name = "invokevirtual";
    instructions[182].bytes = 2;
    instructions[182].index_constant_pool = 1;

    instructions[183].name = "invokespecial";
    instructions[183].bytes = 2;
    instructions[183].index_constant_pool = 1;

    instructions[184].name = "invokestatic";
    instructions[184].bytes = 2;
    instructions[184].index_constant_pool = 1;

    instructions[185].name = "invokeinterface";
    instructions[185].bytes = 4;
    instructions[185].index_constant_pool = 1;

    instructions[186].name = "invokedynamic";
    instructions[186].bytes = 4;
    instructions[186].index_constant_pool = 1;

    instructions[187].name = "new";
    instructions[187].bytes = 2;
    instructions[187].index_constant_pool = 1;

    instructions[188].name = "newarray";
    instructions[188].bytes = 1;
    instructions[188].index_constant_pool = 0;

    instructions[189].name = "anewarray";
    instructions[189].bytes = 2;
    instructions[189].index_constant_pool = 1;

    instructions[190].name = "arraylength";
    instructions[190].bytes = 0;
    instructions[190].index_constant_pool = 0;

    instructions[191].name = "athrow";
    instructions[191].bytes = 0;
    instructions[191].index_constant_pool = 0;

    instructions[192].name = "checkcast";
    instructions[192].bytes = 2;
    instructions[192].index_constant_pool = 1;

    instructions[193].name = "instanceof";
    instructions[193].bytes = 2;
    instructions[193].index_constant_pool = 1;

    instructions[194].name = "monitorenter";
    instructions[194].bytes = 0;
    instructions[194].index_constant_pool = 0;

    instructions[195].name = "monitorexit";
    instructions[195].bytes = 0;
    instructions[195].index_constant_pool = 0;

    instructions[196].name = "wide";
    instructions[196].bytes = 3;
    instructions[196].index_constant_pool = 0;

    instructions[197].name = "multianewarray";
    instructions[197].bytes = 3;
    instructions[197].index_constant_pool = 1;

    instructions[198].name = "ifnull";
    instructions[198].bytes = 2;
    instructions[198].index_constant_pool = 0;

    instructions[199].name = "ifnonnull";
    instructions[199].bytes = 2;
    instructions[199].index_constant_pool = 0;

    instructions[200].name = "goto_w";
    instructions[200].bytes = 4;
    instructions[200].index_constant_pool = 0;

    instructions[201].name = "jsr_w";
    instructions[201].bytes = 4;
    instructions[201].index_constant_pool = 0;

    // reservados
    instructions[202].name = "breakpoint";
    instructions[200].bytes = 0;

    instructions[254].name = "impdep1";
    instructions[254].bytes = 0;

    instructions[255].name = "impdep2";
    instructions[255].bytes = 0;
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
