//
// Created by gabriel on 26/06/18.
//

#ifndef JVM_CPP_ATTRIBUTEINFO_H
#define JVM_CPP_ATTRIBUTEINFO_H


#include "JavaClass.h"

class AttributeInfo {
    u2 attribute_name_index;
    u4 attribute_length;
    u1* info;


public:
    static void read(JavaClass, FILE*);
    static void get_attribute_info(FILE*, AttributeInfo, JavaClass);
    void print(JavaClass);
    void print_attribute_info(JavaClass, AttributeInfo);
};


#endif //JVM_CPP_ATTRIBUTEINFO_H
