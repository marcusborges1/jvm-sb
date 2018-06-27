//
// Created by gabriel on 26/06/18.
//

#include <iostream>
#include "FieldInfo.h"
#include "ClassFileReader.cpp"

void FieldInfo::read(JavaClass class_file, FILE * fp) {

    for (int i = 0; i < class_file.fields_count; i++) {

        class_file.fields[i].access_flag = ClassFileReader::read_2_bytes(fp);
        class_file.fields[i].name_index = ClassFileReader::read_2_bytes(fp);
        class_file.fields[i].descriptor_index = ClassFileReader::read_2_bytes(fp);
        class_file.fields[i].atributes_count = ClassFileReader::read_2_bytes(fp);

//        class_file.fields[i].attributes = (AttributeInfo*)malloc(class_file.fields[i].atributes_count*sizeof(AttributeInfo));
//        for (int i = 0; i < class_file.fields[i].atributes_count; ++i)
//            read_attribute_info(fp, class_file, class_file.fields[i].attributes + i);
    }
}

void FieldInfo::print(JavaClass class_file) {
    printf("\n----------------- Field Info:  ----------------------- \n");

    for (int i = 0; i < class_file.fields_count; i++){
        printf("Name: cp info #%d ", class_file.fields[i].name_index);
        printf("<<");

        std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.fields[i].name_index - 1);

        printf("Descriptor: cp info #%d ", class_file.fields[i].descriptor_index);
        std::cout << CpInfo::get_utf8_string(class_file.constant_pool, class_file.fields[i].descriptor_index - 1);

        printf("Access Flag: 0x%04x ", class_file.fields[i].access_flag);
        printf("%d\n", class_file.fields[i].access_flag);
    }

}