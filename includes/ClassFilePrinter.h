#ifndef CLASS_FILE_PRINTER_H
#define CLASS_FILE_PRINTER_H

#include <string>
#include "JavaClass.h"


class ClassFilePrinter {
public:
    CpInfo *cpinfo = new CpInfo();
    InterfaceInfo *interface_info = new InterfaceInfo();

    std::string print_menu_choose_type_file();
    void print_general_info(JavaClass class_file, std::string filename);
    void print_interfaces(JavaClass class_file);
    void print_menu_exhibitor(JavaClass class_file);
    void print_constant_pool_info(JavaClass class_file);
    std::string get_utf8_constant_pool(CpInfo *cp_info, u2 pos_info);
};

#endif
