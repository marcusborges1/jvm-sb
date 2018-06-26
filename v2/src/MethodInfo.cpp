//
// Created by gabriel on 26/06/18.
//

#include <iostream>
#include "MethodInfo.h"
#include "ClassFileReader.cpp"

void MethodInfo::read(JavaClass class_file, FILE * fp) {


    for(int i = 0; i < class_file.methods_count; i++){

       class_file.methods[i].access_flag = ClassFileReader::read_2_bytes(fp);
       class_file.methods[i].name_index = ClassFileReader::read_2_bytes(fp);
       class_file.methods[i].descriptor_index = ClassFileReader::read_2_bytes(fp);
       class_file.methods[i].attributes_count = ClassFileReader::read_2_bytes(fp);

//       class_file.methods[i].attributes = (AttributeInfo*)malloc(method->attributes_count * sizeof(AttributeInfo));
//        for (int j = 0; j <class_file.methods[i].attributes_count; j++)
//            read_attribute_info(fp, class_file,class_file.methods[i].attributes + j);
    }
}

void MethodInfo::print(JavaClass class_file) {
    printf(" ------------- Methods Info:  -------------\n");
    for(int i = 0; i < class_file.methods_count; i++) {
        printf("\nMETHOD INFO[%d]\n", i);
        printf("Access Flag: 0x%04x ", class_file.methods[i].access_flag);
        std::cout <<  MethodInfo::test_methods_flags(class_file.methods[i].access_flag) << "\n";


        printf("Name Index: cp info #%d ",class_file.methods[i].name_index);
        CpInfo::get_utf8_string(class_file.constant_pool, class_file.methods[i].name_index -1);
        printf("\n");

        printf("Descriptor Index: cp info #%d ",class_file.methods[i].descriptor_index);
        CpInfo::get_utf8_string(class_file.constant_pool, class_file.methods[i].descriptor_index - 1);
        printf("\n");

//        printf("Attributes Count: %d\n",class_file.methods[i].attributes_count);
//        printf("Attributes: \n");
//        for (int j = 0; j < class_file.methods[i].attributes_count; j++){
//            printf("\nATTRIBUTE[%d]\n", j);
//            AttributeInfo* info = class_file.methods[i].attributes +j;
//            print_attributes_on_screen(class_file, info);
//        }
        printf("\n");
    }

}

 std::string MethodInfo::test_methods_flags(u2 access_flag) {
   std::string string;

   if(access_flag & ACC_PUBLIC) {
       string = "public";
   }

   if(access_flag & ACC_PRIVATE) {
    string = "private";
   }
   if(access_flag & ACC_PROTECTED) {
       string = "protected";
   }
   if(access_flag & ACC_STATIC) {
       string = "static";
   }
   if(access_flag & ACC_FINAL) {
       string = "final";
   }
   if(access_flag & ACC_SYNCRONIZED) {
       string = "syncronized";
   }
   if(access_flag & ACC_NATIVE) {
       string = "native";
   }
   if(access_flag & ACC_ABSTRACT) {
       string = "abstract";
   }
   if(access_flag & ACC_STRICT) {
     string = "strict";
   }
   return string;
 }

