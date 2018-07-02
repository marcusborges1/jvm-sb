/** @file AttributeInfo.h
 *  @brief ...
 */
#ifndef JVM_CPP_ATTRIBUTEINFO_H
#define JVM_CPP_ATTRIBUTEINFO_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include "JavaClass.h"
#include "CpInfo.h"


/**
 * @brief ...
 **/
class ConstantValueAttribute{
    public:
        // u2 attribute_name_index;
        // u4 attribute_length;
        u2 constantvalue_index;

        ConstantValueAttribute read(JavaClass,FILE*, AttributeInfo);
};

/**
 * @brief ...
 **/
class Exception{
public:
    u2 number_exceptions;
    u2 *exception_index_table;

    Exception read(FILE*, AttributeInfo);
};

/**
 * @brief ...
 **/
class CodeException {
public:
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;
};

/**
 * @brief ...
 **/
class CodeAttribute {
public:
  u2 max_stack;
  u2 max_locals;
  u4 code_length;
  u1* code;

  u2 exception_table_length;
  CodeException* exception_table;

  u2 attributes_count;
  AttributeInfo* attributes;

  CodeAttribute read(JavaClass, FILE*, AttributeInfo);
};

/**
 * @brief ...
 **/
class InnerClassDataAttribute {
public:
  u2 inner_class_info_index;
  u2 outer_class_info_index;
  u2 inner_name_index;
  u2 inner_class_access_flag;

  InnerClassDataAttribute read(FILE*, AttributeInfo);

};

/**
 * @brief ...
 **/
class InnerClassAttribute {
public:
  u2 number_of_classes;
  InnerClassDataAttribute *inner_class_data;

  InnerClassAttribute read(FILE*, AttributeInfo);
};

/**
 * @brief ...
 **/
class SourceFileAttribute {
public:
  u2 source_file_index;

  SourceFileAttribute read(FILE*, AttributeInfo);
};

/**
 * @brief ...
 **/
class LineNumberTableDataAttribute {
public:
  u2 start_pc;
  u2 line_pc;

  LineNumberTableDataAttribute read(FILE*, AttributeInfo);
};

/**
 * @brief ...
 **/
class LineNumberTableAttribute {
public:
  u2 line_number_table_length;
  LineNumberTableDataAttribute *table;

  LineNumberTableAttribute read(FILE*, AttributeInfo);
};

/**
 * @brief ...
 **/
class LocalVariableTableDataAttribute {
public:
  u2 start_pc;
  u2 length;
  u2 name_index;
  u2 descriptor_index;
  u2 index;

  LocalVariableTableDataAttribute read(FILE*, AttributeInfo);
};

/**
 * @brief ...
 **/
class LocalVariableTableAttribute {
public:
  u2 local_variable_table_length;
  LocalVariableTableDataAttribute *table_data;

  LocalVariableTableAttribute read(FILE*, AttributeInfo);
};

/**
 * @brief ...
 **/
class AttributeInfo {
public:
  CpInfo *cpinfo = new CpInfo();
  CodeAttribute *code_info = new CodeAttribute();
  ConstantValueAttribute *constant_info = new ConstantValueAttribute();
  Exception *exp_info = new Exception();
  InnerClassAttribute *inner_info = new InnerClassAttribute();
  SourceFileAttribute *source_info = new SourceFileAttribute();
  LineNumberTableAttribute *line_number_info = new LineNumberTableAttribute();
  LocalVariableTableAttribute *local_info = new LocalVariableTableAttribute();

  u2 attribute_name_index;
  u4 attribute_length;
  union {
      CodeAttribute code;
      ConstantValueAttribute constant_value;
      Exception execptions;
      InnerClassAttribute inner_class;
      SourceFileAttribute source_file;
      LineNumberTableAttribute line_number_table;
      LocalVariableTableAttribute local_variable_table;
      u1* info;
  };

  void read(JavaClass, FILE*);
  AttributeInfo get_attribute_info(FILE*, AttributeInfo, JavaClass);
};

#endif
