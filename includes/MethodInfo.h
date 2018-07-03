/** @file MethodInfo.h
 *  @brief ...
 */
#ifndef JVM_CPP_METHODINFO_H
#define JVM_CPP_METHODINFO_H

#include "JavaClass.h"
#include "AttributeInfo.h"


/**
 * @brief ...
 **/
class MethodInfo {
public:
  // CONSTANT_UTf8, special name (<init> or <clinit>) or a simple name
  u2 name_index;
  u2 access_flag;
  // CONSTANT_UTf8, method valid descriptor
  u2 descriptor_index;
  // number of method attributes
  u2 attributes_count;
  // JVM implementation should ignore in silence each attribute unrecognized
  AttributeInfo *attributes;

  void read(JavaClass, FILE*);
  std::string test_methods_flags(u2);
  MethodInfo * find_main(JavaClass);
};

#endif
