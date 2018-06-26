//
// Created by gabriel on 26/06/18.
//

#ifndef JVM_CPP_METHODINFO_H
#define JVM_CPP_METHODINFO_H


#include "JavaClass.h"

class MethodInfo {
    // CONSTANT_UTf8, special name (<init> or <clinit>) or a simple name
    // CONSTANT_UTf8, method valid descriptor
    // number of method attributes
    u2  attributes_count; // JVM implementation should ignore in silence each attribute unrecognized
//    AttributeInfo  *attributes;

public:
    static void read(JavaClass, FILE*);
    static std::string test_methods_flags(u2);

    u2 name_index;
    u2 access_flag;
    u2 descriptor_index;

    static void print(JavaClass);
};


#endif //JVM_CPP_METHODINFO_H
