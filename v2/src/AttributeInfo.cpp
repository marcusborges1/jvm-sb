//
// Created by gabriel on 26/06/18.
//

#include <iostream>
#include "AttributeInfo.h"
#include "ClassFileReader.cpp"

void AttributeInfo::read(JavaClass class_file, FILE *fp) {
    for (int i = 0; i < class_file.attributes_count ; i++) {
        AttributeInfo::get_attribute_info(fp, class_file.attributes[i], class_file);
    }

}

void AttributeInfo::get_attribute_info(FILE *fp, AttributeInfo attribute_info, JavaClass class_file) {
    attribute_info.attribute_name_index = ClassFileReader::read_2_bytes(fp);
    attribute_info.attribute_length = ClassFileReader::read_2_bytes(fp);
    std::cout << "attribute name: " << CpInfo::get_utf8_string(class_file.constant_pool, attribute_info.attribute_name_index - 1) << "\n" ;

    attribute_info.info = (u1*)malloc(sizeof(u1)*attribute_info.attribute_length);
    for (int j = 0; j < attribute_info.attribute_length; j++) {
        attribute_info.info[j] = ClassFileReader::read_1_byte(fp);
        attribute_info.info[j] = j; // just for tests
    }
}

void AttributeInfo::print(JavaClass class_file){

}

void AttributeInfo::print_attribute_info(JavaClass class_file, AttributeInfo attr_info) {
    
}