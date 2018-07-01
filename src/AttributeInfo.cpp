#include <iostream>
#include "Instruction.h"
#include "AttributeInfo.h"
#include "ReadBytes.h"


ConstantValueAttribute ConstantValueAttribute::read(JavaClass class_file, FILE * fp, AttributeInfo attribute_info) {
    attribute_info.constant_value.attribute_name_index = read_2_bytes(fp);
    attribute_info.constant_value.attribute_length = read_4_bytes(fp);
    attribute_info.constant_value.constantvalue_index = read_2_bytes(fp);
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
        class_file.attributes[i] = get_attribute_info(fp, class_file.attributes[i], class_file);
    }

}

AttributeInfo AttributeInfo::get_attribute_info(FILE *fp, AttributeInfo attribute_info, JavaClass class_file) {
    attribute_info.attribute_name_index = read_2_bytes(fp);
    // read_2_bytes(fp);
    attribute_info.attribute_length = read_4_bytes(fp);
    std::string attribute_name = cpinfo->get_utf8_constant_pool(class_file.constant_pool, attribute_info.attribute_name_index - 1);

    if(attribute_name == "Code"){
        attribute_info.code = CodeAttribute::read(class_file, fp, attribute_info);
        return attribute_info;
    }

    if(attribute_name == "ConstantValue"){
        attribute_info.constant_value = ConstantValueAttribute::read(class_file, fp, attribute_info);
    }

    else {

        attribute_info.info = (u1*)malloc(sizeof(u1)*attribute_info.attribute_length);

        for (int j = 0; (unsigned)j < attribute_info.attribute_length; j++) {
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
