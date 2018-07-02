#include <iostream>
#include "MethodInfo.h"
#include "ReadBytes.h"


void MethodInfo::read(JavaClass class_file, FILE * fp) {
    int i = 0, contador_method =0;
    AttributeInfo *attributeinfo = new AttributeInfo();
    for(i = 0; i < class_file.methods_count; i++){

       class_file.methods[i].access_flag = read_2_bytes(fp);
       class_file.methods[i].name_index = read_2_bytes(fp);
       class_file.methods[i].descriptor_index = read_2_bytes(fp);
       class_file.methods[i].attributes_count = read_2_bytes(fp);

        class_file.methods[i].attributes = (AttributeInfo*)malloc(class_file.methods[i].attributes_count * sizeof(AttributeInfo));
        for (contador_method = 0; contador_method < class_file.methods[i].attributes_count; contador_method++){
            class_file.methods[i].attributes[contador_method] = attributeinfo->get_attribute_info(fp, class_file.methods[i].attributes[contador_method], class_file);
        }
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
