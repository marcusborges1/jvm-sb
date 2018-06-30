#ifndef CLASS_FILE_READER_H
#define CLASS_FILE_READER_H

#include <string>
#include "JavaClass.h"
#include "CpInfo.h"
#include "FieldInfo.h"
#include "MethodInfo.h"
#include "AttributeInfo.h"

class ClassFileReader {
public:
  CpInfo *cpinfo = new CpInfo();
  FieldInfo *field_info = new FieldInfo();
  MethodInfo *method_info = new MethodInfo();
  AttributeInfo *attribute_info = new AttributeInfo();

  JavaClass read_class_file(std::string filename);
  void print_menu_exhibitor(JavaClass* class_file);
  void read_interfaces(JavaClass class_file, FILE* file);
};

#endif
