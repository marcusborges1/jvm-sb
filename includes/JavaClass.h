/** @file JavaClass.h
 *  @brief Estruturas de dados de um arquivo ".class".
 */
#ifndef JAVA_CLASS_H
#define JAVA_CLASS_H

#include <cstdint>

// uint64_t : unsigned integer type with width of exactly 64
#define u8 uint64_t
// uint32_t : unsigned integer type with width of exactly 32
#define u4 uint32_t
// uint16_t : unsigned integer type with width of exactly 16
#define u2 uint16_t
// uint8_t : unsigned integer type with width of exactly 8
#define u1 uint8_t

#define CONSTANT_Boolean  90
#define CONSTANT_Byte     91
#define CONSTANT_Char     92
#define CONSTANT_Short    93
#define CONSTANT_Array    94

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

// atype for newarray
#define T_BOOLEAN 0x4
#define T_CHAR    0x5
#define T_FLOAT	  0x6
#define T_DOUBLE	0x7
#define T_BYTE    0x8
#define T_SHORT	  0x9
#define T_INT     0x10
#define T_LONG    0x11

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

class CpInfo;
class FieldInfo;
class MethodInfo;
class AttributeInfo;
class InterfaceInfo;

/**
 * @brief ...
 **/
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

#endif
