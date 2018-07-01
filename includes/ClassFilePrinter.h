#ifndef CLASS_FILE_PRINTER_H
#define CLASS_FILE_PRINTER_H

#include <string>
#include "JavaClass.h"
#include "CpInfo.h"
#include "FieldInfo.h"
#include "MethodInfo.h"
#include "InterfaceInfo.h"
// #include "AttributeInfo.h"

class AttributeInfo;

class ClassFilePrinter {
public:
    CpInfo *cpinfo = new CpInfo();
    InterfaceInfo *interface_info = new InterfaceInfo();
    AttributeInfo *attribute_info = new AttributeInfo();

    std::string print_menu_choose_type_file();
    void print_general_info(JavaClass class_file, std::string filename);
    void print_interfaces(JavaClass class_file);
    void print_menu_exhibitor(JavaClass class_file);
    void print_constant_pool_info(JavaClass class_file);
    void print_attributes(JavaClass class_file, AttributeInfo *info);
};

#endif
