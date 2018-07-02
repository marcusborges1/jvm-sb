#include <iostream>
#include "Instruction.h"
#include "AttributeInfo.h"
#include "ReadBytes.h"


ConstantValueAttribute ConstantValueAttribute::read(JavaClass class_file, FILE * fp, AttributeInfo attribute_info) 
{
    printf("ENTREI AQUI\n");
    // attribute_info.constant_value.attribute_name_index = read_2_bytes(fp);
    // printf("CONSTANT_NAME-->>%d\n", attribute_info.constant_value.attribute_name_index);
    // attribute_info.constant_value.attribute_length = read_4_bytes(fp);
    // printf("CONSTANT_LENGTH-->>%d\n", attribute_info.constant_value.attribute_length);
    attribute_info.constant_value.constantvalue_index = read_2_bytes(fp);
    printf("CONSTANT_INDEX-->>%d\n",attribute_info.constant_value.constantvalue_index);
    return  attribute_info.constant_value;
}

// void ConstantValueAttribute::print(JavaClass class_file, AttributeInfo attribute_info) {
//   CpInfo *cpinfo = new CpInfo();
//     std::cout << "\tname: " << cpinfo->get_utf8_constant_pool(class_file.constant_pool, attribute_info.constant_value.attribute_name_index) << std::endl; // isso ou -1?
//     std::cout << "\tlength: " << attribute_info.constant_value.attribute_length << std::endl;
//     std::cout << "\tvalue: " << cpinfo->get_utf8_constant_pool(class_file.constant_pool, attribute_info.constant_value.constantvalue_index) << std::endl;
// }

CodeAttribute CodeAttribute::read(JavaClass class_file, FILE* fp, AttributeInfo attribute_info){
    AttributeInfo *attributeinfo = new AttributeInfo();
//    read_2_bytes(fp); // READING 2 BYTES LESS AT THIS POINT. WHY?
    attribute_info.code.max_stack = read_2_bytes(fp);
    attribute_info.code.max_locals = read_2_bytes(fp);
    attribute_info.code.code_length = read_4_bytes(fp);
    attribute_info.code.code = (u1*)malloc(sizeof(u1)*attribute_info.code.code_length);

    for (int i = 0; (unsigned)i < attribute_info.code.code_length; i++) {
        attribute_info.code.code[i] = read_1_byte(fp);
    }
    printf("\n");

    attribute_info.code.exception_table_length = read_2_bytes(fp);
    attribute_info.code.exception_table = (CodeException*)malloc(sizeof(CodeException)*attribute_info.code.exception_table_length);
    for (int j = 0; j < attribute_info.code.exception_table_length; j++) {
        attribute_info.code.exception_table[j].start_pc = read_2_bytes(fp);
        attribute_info.code.exception_table[j].end_pc = read_2_bytes(fp);
        attribute_info.code.exception_table[j].handler_pc = read_2_bytes(fp);
        attribute_info.code.exception_table[j].catch_type = read_2_bytes(fp);
    }

    attribute_info.code.attributes_count = read_2_bytes(fp);
    attribute_info.code.attributes = (AttributeInfo*)malloc(sizeof(AttributeInfo)*attribute_info.code.attributes_count);
    for (int k = 0; k < attribute_info.code.attributes_count; k++) {
        attribute_info.code.attributes[k] = attributeinfo->get_attribute_info(fp, attribute_info.code.attributes[k], class_file);
    }

    return attribute_info.code;
}


//////le o atributo LOCAL VARIABLE
LocalVariableTableAttribute LocalVariableTableAttribute::read(FILE *arquivo_class, AttributeInfo attribute_struct)
{
    int i;
    LocalVariableTableDataAttribute *info_data = new LocalVariableTableDataAttribute();
    LocalVariableTableAttribute info_local_variable_table;

    info_local_variable_table.local_variable_table_length = read_2_bytes(arquivo_class);

    info_local_variable_table.table_data = (LocalVariableTableDataAttribute*)malloc(info_local_variable_table.local_variable_table_length * sizeof(LocalVariableTableDataAttribute));
    for (i = 0; i < attribute_struct.local_variable_table.local_variable_table_length; i++)
    {
        info_local_variable_table.table_data[i] = info_data->read(arquivo_class, attribute_struct);
    }

    return info_local_variable_table;
}

//////le o atributo LOCAL VARIABLE
LocalVariableTableDataAttribute LocalVariableTableDataAttribute::read(FILE *arquivo_class, AttributeInfo attribute_struct)
{
    LocalVariableTableDataAttribute info_local_variable;

    info_local_variable.start_pc = read_2_bytes(arquivo_class);
    info_local_variable.length = read_2_bytes(arquivo_class);
    info_local_variable.name_index = read_2_bytes(arquivo_class);
    info_local_variable.descriptor_index = read_2_bytes(arquivo_class);
    info_local_variable.index = read_2_bytes(arquivo_class);


    return info_local_variable;
}



//////le o atributo LINE NUMBER
LineNumberTableAttribute LineNumberTableAttribute::read(FILE *arquivo_class, AttributeInfo attribute_struct)
{
    int i;

    LineNumberTableDataAttribute *info_data = new LineNumberTableDataAttribute();
    LineNumberTableAttribute info_line_number_table;

    printf("-------------LINE_TABLE-----------\n");

    info_line_number_table.line_number_table_length = read_2_bytes(arquivo_class);
    printf("LINE_TABLE_LENGTH --->%d\n", info_line_number_table.line_number_table_length);

    info_line_number_table.table = (LineNumberTableDataAttribute*)malloc(info_line_number_table.line_number_table_length * sizeof(LineNumberTableDataAttribute));
    for (i = 0; i < info_line_number_table.line_number_table_length; i++)
    {
        info_line_number_table.table[i] = info_data->read(arquivo_class, attribute_struct);
        
        printf("START_PC---->%d\n", info_line_number_table.table[i].start_pc);
        printf("LINE_PC---->%d\n", info_line_number_table.table[i].line_pc);  
    }

    printf("---------------------------------------LT\n");

    return info_line_number_table;
}


//////le o atributo LINE NUMBER
LineNumberTableDataAttribute LineNumberTableDataAttribute::read(FILE *arquivo_class, AttributeInfo attribute_struct)
{
    LineNumberTableDataAttribute info_line_number_table_data;

    info_line_number_table_data.start_pc = read_2_bytes(arquivo_class);
    info_line_number_table_data.line_pc = read_2_bytes(arquivo_class);

    return info_line_number_table_data;
}



InnerClassAttribute InnerClassAttribute::read(FILE *arquivo_class, AttributeInfo attribute_struct)
{
    int i;

    InnerClassDataAttribute *info_data = new InnerClassDataAttribute();
    InnerClassAttribute info_inner_class;

    info_inner_class.number_of_classes = read_2_bytes(arquivo_class);

    info_inner_class.inner_class_data = (InnerClassDataAttribute*)malloc(info_inner_class.number_of_classes * sizeof(InnerClassDataAttribute));
    for (i = 0; i < info_inner_class.number_of_classes; i++)
    {
        info_inner_class.inner_class_data[i] = info_data->read(arquivo_class, attribute_struct);
    }

    return info_inner_class;
}


InnerClassDataAttribute InnerClassDataAttribute::read(FILE *arquivo_class, AttributeInfo attribute_struct)
{
    InnerClassDataAttribute info_inner_class_data;

    info_inner_class_data.inner_class_info_index = read_2_bytes(arquivo_class);
    info_inner_class_data.outer_class_info_index = read_2_bytes(arquivo_class);
    info_inner_class_data.inner_name_index = read_2_bytes(arquivo_class);
    info_inner_class_data.inner_class_access_flag = read_2_bytes(arquivo_class);

    return info_inner_class_data;
}



Exception Exception::read(FILE *arquivo_class, AttributeInfo attribute_struct)
{
    int i;

    Exception info_exception;

    info_exception.number_exceptions = read_2_bytes(arquivo_class);

    for (i = 0; i < info_exception.number_exceptions; i++)
    {
        info_exception.exception_index_table[i] = read_2_bytes(arquivo_class);
    }

    return info_exception;
}




SourceFileAttribute SourceFileAttribute::read(FILE *arquivo_class, AttributeInfo attribute_struct)
{
    SourceFileAttribute info_source_file;
    
    info_source_file.source_file_index = read_2_bytes(arquivo_class);
    
    return info_source_file;
}






// void CodeAttribute::print(JavaClass class_file, AttributeInfo attribute) {
//
//     printf("Max stack: %d\n", attribute.code.max_stack);
//     printf("Max locals: %d\n",attribute.code.max_locals);
//     printf("Code Length: %d\n", attribute.code.code_length);
//     Instruction instructions[256];
//     Instruction::setup_instructions(instructions);
//     printf("Code: \n");
//     for (int i = 0; i < attribute.code.code_length; i++) {
//         u1 op_code = attribute.code.code[i];
//         std::cout << "\t"<< i << ": " << instructions[op_code].name;
//         for (int j = 0; j < instructions[op_code].bytes; j++) {
//             i++;
//             if (op_code == anewarray || op_code == checkcast || op_code == getfield || op_code == getstatic || op_code == instanceof || op_code == invokespecial || op_code == invokestatic || op_code == invokevirtual || op_code == ldc_w || op_code == ldc2_w || op_code == NEW || op_code == putfield || op_code == putstatic){
// //                u2 index = attribute.code.code[j] << 8 ;
//                 u1 byte1 = attribute.code.code[i];
//                 u1 byte2 = attribute.code.code[i+1];
//                 u2 index = (byte1<<8)|byte2;
//                 std::cout << " " << CpInfo::get_utf8_string(class_file.constant_pool, index - 1);
//                 j++;
// //                i++;
//             }
//
//             else if( op_code == GOTO || op_code == if_acmpeq || op_code == if_acmpne || op_code == if_icmpeq || op_code == if_icmpne || op_code == if_icmplt || op_code == if_icmpge || op_code == if_icmpgt || op_code == if_icmple || op_code == iifeq || op_code == ifne || op_code == iflt || op_code == ifge || op_code == ifgt || op_code == ifle || op_code == ifnonull || op_code == ifnull || op_code == jsr ) {
//                 u1 branchbyte1 = attribute.code.code[i];
//                 u1 branchbyte2 = attribute.code.code[i+1];
//                 u2 address = (branchbyte1 << 8) | branchbyte2;
//                 printf(" %08X ", address);
//             }
//
//             else if(op_code == goto_w || opcode == jsw_r) {
//                 u1 branchbyte1 = attribute.code.code[i];
//                 u1 branchbyte2 = attribute.code.code[i+1];
//                 u1 branchbyte3 = attribute.code.code[i+2];
//                 u1 branchbyte4 = attribute.code.code[i+3];
//                 u2 address = (branchbyte1 << 24) | (branchbyte2 << 16) | (branchbyte3 << 8) | branchbyte4);
//                 printf("%08X ", address);
//             }
//
//             else {
//
//                 printf(" %x ", attribute.code.code[j]);
//             }
//         }
//         std::cout << std::endl;
//     }
//
//     printf("\n");
// }

void AttributeInfo::read(JavaClass class_file, FILE *fp) {
    for (int i = 0; i < class_file.attributes_count ; i++) {
        class_file.attributes[i] = this->get_attribute_info(fp, class_file.attributes[i], class_file);
    }

}

AttributeInfo AttributeInfo::get_attribute_info(FILE *fp, AttributeInfo attribute_info, JavaClass class_file) 
{

    attribute_info.attribute_name_index = read_2_bytes(fp);
    printf("NAME_INDEX--->>%d\n", attribute_info.attribute_name_index);
    attribute_info.attribute_length = read_4_bytes(fp);
    std::string attribute_name = cpinfo->get_utf8_constant_pool(class_file.constant_pool, attribute_info.attribute_name_index - 1);
   
    printf("ATT_TYPE-->>%s\n", attribute_name.c_str());
   
    if(attribute_name == "Code"){
        attribute_info.code = code_info->read(class_file, fp, attribute_info);
        return attribute_info;
    }
    else if(attribute_name == "ConstantValue"){
        attribute_info.constant_value = constant_info->read(class_file, fp, attribute_info);
    }
    else if (attribute_name == "Exceptions")
    {
        attribute_info.execptions = exp_info->read(fp, attribute_info);
    }
    else if (attribute_name =="InnerClasses")
    {
        attribute_info.inner_class = inner_info->read(fp, attribute_info);
    }
    else if (attribute_name == "Synthetic")
    {
        //não fazer nada
    }
    else if (attribute_name =="SourceFile")
    {
        // attribute_info.source_file = (attribute_source_file*)malloc(sizeof(attribute_source_file));
        attribute_info.source_file = source_info->read(fp, attribute_info);
    }
    else if (attribute_name == "LineNumberTable")
    {
        attribute_info.line_number_table = line_number_info->read(fp, attribute_info);
    }
    else if (attribute_name == "LocalVariableTable")
    {
        attribute_info.local_variable_table = local_info->read(fp, attribute_info);

    }
    else 
    {
        //ignora silenciosamente os outros atributos
        // attribute_info.info = (u1*)malloc(sizeof(u1)*attribute_info.attribute_length);

        for (int j = 0; j < attribute_info.attribute_length; j++) {
            attribute_info.info[j] = read_1_byte(fp);
        }
    }

    return attribute_info;
}

// void AttributeInfo::print(JavaClass class_file){
//     std::cout << " ----------------- Attributes ---------------" << std::endl;
//     printf("attribute count: %d\n", class_file.attributes_count);
//
//     for (int j = 0; j < class_file.attributes_count; j++) {
//         std::cout << "attribute #" << j << ": ";
//         print_attribute_info(class_file, class_file.attributes[j]);
//     }
//
// }
//
// void AttributeInfo::print_attribute_info(JavaClass class_file, AttributeInfo attribute_info) {
//     std::string a_name = cpinfo->get_utf8_constant_pool(class_file.constant_pool,attribute_info.attribute_name_index - 1);
//     std::cout << a_name << std::endl;
//     std::cout << "attribute length: " << attribute_info.attribute_length << std::endl;
//
//     if(a_name == "Code"){
//         CodeAttribute::print(class_file, attribute_info);
//     }
//
// }
