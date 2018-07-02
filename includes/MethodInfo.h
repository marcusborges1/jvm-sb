/** @file MethodInfo.h
 *  @brief ...
 */
#ifndef JVM_CPP_METHODINFO_H
#define JVM_CPP_METHODINFO_H

#include "JavaClass.h"
#include "AttributeInfo.h"

class MethodInfo {
    // CONSTANT_UTf8, special name (<init> or <clinit>) or a simple name
    // CONSTANT_UTf8, method valid descriptor
    // number of method attributes

public:
    u2 name_index;
    u2 access_flag;
    u2 descriptor_index;
    u2  attributes_count; // JVM implementation should ignore in silence each attribute unrecognized
    AttributeInfo *attributes;

    void read(JavaClass, FILE*);
    std::string test_methods_flags(u2);
};

#endif
