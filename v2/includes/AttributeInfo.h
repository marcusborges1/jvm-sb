//
// Created by gabriel on 26/06/18.
//

#ifndef JVM_CPP_ATTRIBUTEINFO_H
#define JVM_CPP_ATTRIBUTEINFO_H


#include "JavaClass.h"

class ConstantValue{};
class Exception{
public:
    u2 number_of_exceptions;
    u2* exception_index_table;
};

class CodeException {
public:
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;
};

class CodeAttribute {
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    u1* code;

    u2 exception_table_length;
    CodeException* exception_table;

    u2 attributes_count;
    AttributeInfo* attributes;

    public:
        static CodeAttribute read(JavaClass, FILE*, AttributeInfo);
        static void print(JavaClass, AttributeInfo);
};

class AttributeInfo {
public:
    u2 attribute_name_index;
    u4 attribute_length;
    union {
        CodeAttribute code;
        ConstantValue constant_value;
        Exception execptions;
        u1* info;
    };

public:
    static void read(JavaClass, FILE*);
    static AttributeInfo get_attribute_info(FILE*, AttributeInfo, JavaClass);
    static void print(JavaClass);
    static void print_attribute_info(JavaClass, AttributeInfo);
};


#endif //JVM_CPP_ATTRIBUTEINFO_H
