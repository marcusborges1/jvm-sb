#ifndef CLASS_FILE_READER_H
#define CLASS_FILE_READER_H

#include <string>
#include "JavaClass.h"
#include "CpInfo.h"

class ClassFileReader {
public:
  CpInfo *cpinfo = new CpInfo();
  JavaClass read_class_file(std::string filename);
  void read_interfaces(JavaClass class_file, FILE* file);
};

#endif
