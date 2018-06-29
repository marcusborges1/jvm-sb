//
// Created by gabriel on 26/06/18.
//

#include <iostream>
#include <Instruction.h>
#include "AttributeInfo.h"
#include "ClassFileReader.cpp"

CodeAttribute CodeAttribute::read(JavaClass class_file, FILE* fp, AttributeInfo attribute_info){
//    ClassFileReader::read_2_bytes(fp); // READING 2 BYTES LESS AT THIS POINT. WHY?
    attribute_info.code.max_stack = ClassFileReader::read_2_bytes(fp);
    attribute_info.code.max_locals = ClassFileReader::read_2_bytes(fp);
    attribute_info.code.code_length = ClassFileReader::read_4_bytes(fp);
    attribute_info.code.code = (u1*)malloc(sizeof(u1)*attribute_info.code.code_length);
//    printf("CODE:\n");
    for (int i = 0; i < attribute_info.code.code_length; i++) {
        attribute_info.code.code[i] = ClassFileReader::read_1_byte(fp);
    }
    printf("\n");

    attribute_info.code.exception_table_length = ClassFileReader::read_2_bytes(fp);
    attribute_info.code.exception_table = (CodeException*)malloc(sizeof(CodeException)*attribute_info.code.exception_table_length);
    for (int j = 0; j < attribute_info.code.exception_table_length; j++) {
        attribute_info.code.exception_table[j].start_pc = ClassFileReader::read_2_bytes(fp);
        attribute_info.code.exception_table[j].end_pc = ClassFileReader::read_2_bytes(fp);
        attribute_info.code.exception_table[j].handler_pc = ClassFileReader::read_2_bytes(fp);
        attribute_info.code.exception_table[j].catch_type = ClassFileReader::read_2_bytes(fp);
    }

    attribute_info.code.attributes_count = ClassFileReader::read_2_bytes(fp);
    attribute_info.code.attributes = (AttributeInfo*)malloc(sizeof(AttributeInfo)*attribute_info.code.attributes_count);
    for (int k = 0; k < attribute_info.code.attributes_count; k++) {
        attribute_info.code.attributes[k] = AttributeInfo::get_attribute_info(fp, attribute_info.code.attributes[k], class_file);
    }

    return attribute_info.code;
}

void CodeAttribute::print(JavaClass class_file, AttributeInfo attribute) {

    printf("Max stack: %d\n", attribute.code.max_stack);
    printf("Max locals: %d\n",attribute.code.max_locals);
    printf("Code Length: %d\n", attribute.code.code_length);
    Instruction instructions[256];
    Instruction::setup_instructions(instructions);
    printf("Code: \n");
    for (int i = 0; i < attribute.code.code_length; i++) {
        u1 op_code = attribute.code.code[i];
        std::cout << "\t"<< i << ": " << instructions[op_code].name;
        for (int j = 0; j < instructions[op_code].bytes; j++) {
            i++;
            if (op_code == anewarray || op_code == checkcast || op_code == getfield || op_code == getstatic || op_code == instanceof || op_code == invokespecial || op_code == invokestatic || op_code == invokevirtual || op_code == ldc_w || op_code == ldc2_w || op_code == NEW || op_code == putfield || op_code == putstatic){
//                u2 index = attribute.code.code[j] << 8 ;
                u1 byte1 = attribute.code.code[i];
                u1 byte2 = attribute.code.code[i+1];
                u2 index = (byte1<<8)|byte2;
                std::cout << " " << CpInfo::get_utf8_string(class_file.constant_pool, index - 1);
                j++;
//                i++;
            }
            else {

                printf(" %x ", attribute.code.code[j]);
            }
        }
        std::cout << std::endl;
    }

    printf("\n");
//    printMethodInstructions(class_file, code);

//    printf("Exceptions Length: %d\n", attribute.code.exception_table_length);
//    printf("Exceptions:\n\n");
//    for (int i = 0; i < attribute.code.exception_table_length; i++) {
//        printf("Start PC: %d\n", attribute.code.exception_table[i].start_pc);
//        printf("End PC: %d\n", attribute.code.exception_table[i].end_pc);
//        printf("Handler PC: %d\n", attribute.code.exception_table[i].handler_pc);
//        printf("Catch Type: ");
//        std::cout << CpInfo::get_utf8_string(class_file.constant_pool, attribute.code.exception_table[i].catch_type-1) << std::endl;
//    }
//
//    printf("Code Attributes count: %d\n", attribute.code.attributes_count);
//    printf("Attributes:\n\n");
//    for (int j = 0; j < attribute.code.attributes_count; j++) {
//        AttributeInfo::print_attribute_info(class_file, attribute.code.attributes[j]);
//    }
}

void AttributeInfo::read(JavaClass class_file, FILE *fp) {
    for (int i = 0; i < class_file.attributes_count ; i++) {
        class_file.attributes[i] = AttributeInfo::get_attribute_info(fp, class_file.attributes[i], class_file);
    }

}

AttributeInfo AttributeInfo::get_attribute_info(FILE *fp, AttributeInfo attribute_info, JavaClass class_file) {
    attribute_info.attribute_name_index = ClassFileReader::read_2_bytes(fp);
    ClassFileReader::read_2_bytes(fp);
    attribute_info.attribute_length = ClassFileReader::read_2_bytes(fp);
    std::string attribute_name = CpInfo::get_utf8_string(class_file.constant_pool, attribute_info.attribute_name_index - 1);

    std::cout << "Attribute name:" << attribute_name << "\n";
    std::cout << "Attribute length:" << attribute_info.attribute_length<< '\n';

//
    if(attribute_name == "Code"){
        attribute_info.code = CodeAttribute::read(class_file, fp, attribute_info);
        return attribute_info;
    }

    else {

        attribute_info.info = (u1*)malloc(sizeof(u1)*attribute_info.attribute_length);
        for (int j = 0; j < attribute_info.attribute_length; j++) {
            attribute_info.info[j] = ClassFileReader::read_1_byte(fp);
        }
    }

    return attribute_info;
}

void AttributeInfo::print(JavaClass class_file){
    std::cout << " ----------------- Attributes ---------------" << std::endl;
    printf("attribute count: %d\n", class_file.attributes_count);

    for (int j = 0; j < class_file.attributes_count; j++) {
        std::cout << "attribute #" << j << ": ";
        AttributeInfo::print_attribute_info(class_file, class_file.attributes[j]);
    }

}

void AttributeInfo::print_attribute_info(JavaClass class_file, AttributeInfo attribute_info) {
    std::string a_name = CpInfo::get_utf8_string(class_file.constant_pool,attribute_info.attribute_name_index - 1);
    std::cout << a_name << std::endl;
    std::cout << "attribute length: " << attribute_info.attribute_length << std::endl;

    if(a_name == "Code"){
        CodeAttribute::print(class_file, attribute_info);
    }

}