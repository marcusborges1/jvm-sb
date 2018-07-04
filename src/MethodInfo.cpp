/** @file MethodInfo.cpp
 *  @brief ...
 *  @bug No know bugs.
 */
#include <iostream>
#include "MethodInfo.h"
#include "ReadBytes.h"


/** @brief ...
 *  @param class_file ...
 *  @param MethodInfo*
 */
MethodInfo* MethodInfo::find_main(JavaClass class_file) {
  for (int i = 0; i < class_file.methods_count; i++) {
    MethodInfo *method = class_file.methods + i;
    std::string name = class_file.constant_pool->get_utf8_constant_pool(
                                                  class_file.constant_pool,
                                                  method->name_index-1);
    if (name == "main") {
      std::string desc = class_file.constant_pool->get_utf8_constant_pool(
                                                class_file.constant_pool,
                                                method->descriptor_index-1);
      if (desc == "([Ljava/lang/String;)V") return method;
    }
  }

  std::cout << "Class File inserido não possui método main." << std::endl;
  exit(1);
}

/** @brief ...
 *  @param class_file ...
 *  @param fp ...
 *  @return void
 */
void MethodInfo::read(JavaClass class_file, FILE * fp) {
  int i = 0, counter_method = 0;
  AttributeInfo *attributeinfo = new AttributeInfo();
  for (i = 0; i < class_file.methods_count; i++) {
   class_file.methods[i].access_flag = read_2_bytes(fp);
   class_file.methods[i].name_index = read_2_bytes(fp);
   class_file.methods[i].descriptor_index = read_2_bytes(fp);
   class_file.methods[i].attributes_count = read_2_bytes(fp);

    class_file.methods[i].attributes = (AttributeInfo*)malloc(
          class_file.methods[i].attributes_count * sizeof(AttributeInfo));
    for (counter_method = 0;
        counter_method < class_file.methods[i].attributes_count;
        counter_method++) {
        class_file.methods[i].attributes[counter_method] = attributeinfo->get_attribute_info(
        fp, class_file.methods[i].attributes[counter_method], class_file);
    }
  }
}

/** @brief ...
*  @param access_flag ...
*  @return string ...
*/
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
