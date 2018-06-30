#ifndef CLASS_FILE_PRINTER_H
#define CLASS_FILE_PRINTER_H

#include <string>
#include "JavaClass.h"

class ClassFilePrinter {
public:
    CpInfo *cpinfo = new CpInfo();
    
    std::string print_menu_choose_type_file();
    void print_general_info(JavaClass class_file, std::string filename);
    void print_interfaces(JavaClass class_file);
};

#endif
