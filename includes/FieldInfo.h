#ifndef JVM_CPP_FIELDINFO_H
#define JVM_CPP_FIELDINFO_H


#include "JavaClass.h"
#include "AttributeInfo.h"

class FieldInfo {
    u2  access_flag; // CONSTANT_UTf8, field name
    u2  name_index; // CONSTANT_UTf8, field valid descriptor
    u2  descriptor_index; // number of field attributes
    u2  atributes_count; // JVM implementation should ignore in silence each attribute unrecognized
    AttributeInfo  *attributes;

public:
    void static read(JavaClass, FILE*);

    void static print(JavaClass);
};


#endif //JVM_CPP_FIELDINFO_H
