#ifndef CLASS_FILE_READER_H
#define CLASS_FILE_READER_H

#include <string>
#include "JavaClass.h"
#include "CpInfo.h"
#include "FieldInfo.h"
#include "MethodInfo.h"
#include "AttributeInfo.h"
#include "InterfaceInfo.h"


class ClassFileReader {
public:
  CpInfo *cpinfo = new CpInfo();
  FieldInfo *field_info = new FieldInfo();
  MethodInfo *method_info = new MethodInfo();
  AttributeInfo *attribute_info = new AttributeInfo();
  InterfaceInfo *interface_info = new InterfaceInfo();

  JavaClass read_class_file(std::string filename);
};

#endif
