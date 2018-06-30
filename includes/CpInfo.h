#ifndef JVM_CPP_CONSTANTPOOLINFO_H
#define JVM_CPP_CONSTANTPOOLINFO_H

#include <cstdio>
#include <string>
#include "JavaClass.h"

/**
 * @brief Estrutura de Classe para unidade da Constant Pool.
 **/
class CpInfo {

public:
    u2 tag;

    union {
        // class or interface representation
        struct {
            u2 type_class_info;
        } Class;

        // field representation
        struct {
            u2 class_index;
            u2 name_and_type_index;
        } FieldRef;

        // field or method without the class or interface which belongs
        struct {
            u2 name_index;
            u2 descriptor_index;
        } NameAndType;

        // constant string, unicode included
        struct {
            u2 size;
            // not allowed zero values or value between the interval 0xf0 to 0xff,
            // that means, [240, 255]
            u1 *bytes;
        } UTF8;

        // method representation
        struct {
            u2 index;
            u2 name_and_type;
        } MethodRef;

        // interface method representation
        struct {
            u2 index;
            u2 name_and_type;
        } InterfaceMethodRef;

        // constant object string
        struct {
            u2 bytes;
        } String;

        // integer constant of 4 bytes (big-endian)
        struct {
            u4 bytes;
        } Integer;

        // float constant of 4 bytes (big-endian, IEEE-754)
        struct {
            u4 bytes;
        } Float;

        // integer constant of 8 bytes (big-endian), occupies 2 indexes
        // in constant_pool table
        struct {
            u4 high_bytes;
            u4 low_bytes;
        } Long;

        // float constant of 8 bytes (big-endian, IEEE-754), occupies
        // 2 indexes in constant_pool table
        struct {
            u4 high_bytes;
            u4 low_bytes;
        } Double;

    };

    void read(FILE*, JavaClass);
    void print(JavaClass);
};


#endif //JVM_CPP_CONSTANTPOOLINFO_H
