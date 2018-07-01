// uint64_t : unsigned integer type with width of exactly 64
#include <cstdint>
// #include "CpInfo.h"
// #include "InterfaceInfo.h"
// #include "FieldInfo.h"
// #include "MethodInfo.h"
// #include "ClassFilePrinter.h"
// #include "AttributeInfo.h"


#define u8 uint64_t
// uint32_t : unsigned integer type with width of exactly 32
#define u4 uint32_t
// uint16_t : unsigned integer type with width of exactly 16
#define u2 uint16_t
// uint8_t : unsigned integer type with width of exactly 8
#define u1 uint8_t

#define anewarray 189
#define checkcast 192
#define getfield 180
#define getstatic 178
#define instanceof 193
#define invokedynamic 186
#define invokeinterface 185
#define invokespecial 183
#define invokestatic 184
#define invokevirtual 182
#define ldc_w 19
#define ldc2_w 20
#define multianewarray 197
#define NEW 187
#define putfield 181
#define putstatic 179

#define GOTO 167
#define if_acmpeq 165
#define if_acmpne 166
#define if_icmpeq 159
#define if_icmpne 160
#define if_icmplt 161
#define if_icmpge 162
#define if_icmpgt 163
#define if_icmple 164
#define iifeq 153
#define ifne 154
#define iflt 155
#define ifge 156
#define ifgt 157
#define ifle 158
#define ifnonull 199
#define ifnull 198
#define jsr 168



#define CONSTANT_Class                7
#define CONSTANT_Fieldref             9
#define CONSTANT_Methodref           10
#define CONSTANT_InterfaceMethodref  11
#define CONSTANT_String               8
#define CONSTANT_Integer              3
#define CONSTANT_Float                4
#define CONSTANT_Long                 5
#define CONSTANT_Double               6
#define CONSTANT_NameAndType         12
#define CONSTANT_Utf8                 1
#define CONSTANT_EmptySpace           0

// access flags
// public declaration, can be accessed outside the package
#define ACC_PUBLIC      0x0001
// private declaration, restrict context to class definition
#define ACC_PRIVATE     0x0002
// protected declaration, can be used on class and subclasses
#define ACC_PROTECTED   0x0004
// static declaration, class variable, not instance variable
#define ACC_STATIC      0x0008
// final declaration, cannot have subclass
#define ACC_FINAL       0x0010
// syncronized, requires a monitor before be executed (thread)
#define ACC_SYNCRONIZED 0x0020
// native, implemented in language not in Java (C, C++, Assembly)
#define ACC_NATIVE      0x0100
// volatile declaration, cannot be in cache
#define ACC_VOLATILE    0x0040
// transient declaration, cannot be read or write from an object persistent
// manager
#define ACC_TRANSIENT   0x0080
// calls superclass methods through invoke special instruction
#define ACC_SUPER       0x0020
// interface, not a class
#define ACC_INTERFACE   0x0200
// abstract declaration, cannot be instantiated
#define ACC_ABSTRACT    0x0400
// strictfp, float point mode FP-strict (not normalized)
#define ACC_STRICT      0x0800


#ifndef JVM_CPP_JAVACLASS_H
#define JVM_CPP_JAVACLASS_H

class CpInfo;
class FieldInfo;
class MethodInfo;
class AttributeInfo;
class InterfaceInfo;


class JavaClass{
    public:
        u4 magic_number;
        u2  minor_version;
        u2  major_version;
        // format version M.m, defined by Sun

        u2 constant_pool_count; // Quantidade de elementos CpInfo
        CpInfo* constant_pool; // Ponteiro para início do vetor de CpInfo

        u2  access_flags;
        u2 this_class;
        u2 super_class;
        u2 interfaces_count;
        InterfaceInfo *interfaces;
        u2  fields_count;
        FieldInfo* fields;
        u2  methods_count;
        MethodInfo  *methods;
        u2  attributes_count;
        AttributeInfo  *attributes;
};


#endif //JVM_CPP_JAVACLASS_H
