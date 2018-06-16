#ifndef __JAVA_CLASS_STRUCTS_H__
#define __JAVA_CLASS_STRUCTS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// constants tags
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
#define CONSTANT_EmptySpace          13

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

// uint32_t : typedef unsigned int
#define u4 uint32_t
// uint16_t : typedef unsigned short
#define u2 uint16_t
// uint8_t : typedef unsigned char
#define u1 uint8_t

// constant pool information
typedef struct {
  u1 tag;

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
} CpInfo;

typedef struct {
    // CONSTANT_UTf8, attribute name
    u2  attribute_name_index;
    // attribute size in bytes
    u4  attribute_length;
    u1  *info;
} AttributeInfo;

typedef struct {
    u2  access_flag;
    // CONSTANT_UTf8, field name
    u2  name_index;
    // CONSTANT_UTf8, field valid descriptor
    u2  descriptor_index;
    // number of field attributes
    u2  atributes_count;
    // JVM implementation should ignore in silence each attribute unrecognized
    AttributeInfo  *attributes;
} FieldInfo;

typedef struct {
    u2  access_flag;
    // CONSTANT_UTf8, special name (<init> or <clinit>) or a simple name
    u2  name_index;
    // CONSTANT_UTf8, method valid descriptor
    u2  descriptor_index;
    // number of method attributes
    u2  attributes_count;
    // JVM implementation should ignore in silence each attribute unrecognized
    AttributeInfo  *attributes;
} MethodInfo;

typedef struct {
  // class signature : 0xCAFEBABE
  u4 	magic_number;
  u2  minor_version;
  // format version M.m, defined by Sun
  u2  major_version;
  // number of entries in constant pool + 1 table
  // 1 <= constant pool index < constant_pool_count
  u2  constant_pool_count;
  // constant pool structure table
  CpInfo  *contant_pool;
  // bits mask about access permissions and class properties or interface
  u2  access_flags;
  // valid index from constant pool table, points to CONSTANT_Class,
  // class or interface
  u2  this_class;
  // valid index from constant pool table, points to CONSTANT_Class
  // direct super class, zero if the class is not derivated
  u2  super_class;
  // interface number of entries
  // 0 <= interfaces index < interfaces_count
  u2  interface_count;
  // valid index from constant pool table, points to CONSTANT_Class,
  // interface that is a direct superinterface of the class or the interface
  u2 *interfaces;
  // number of class variables or instance variables
  u2  field_count;
  // each field belongs to the field_intro structure
  // there are no fields inherited from superclasses or super interfaces
  FieldInfo *fields;
  // method_info number of entries
  u2  methods_count;
  // each field belongs to the method_info structure
  // there are no fields inherited from superclasses or super interfaces
  MethodInfo  *methods;
  // attributes_info number of entries
  u2  attributes_count;
  // each field belongs to the attributes_info structure
  // JVM implementation should ignore in silence each attribute unrecognized
  AttributeInfo  *attributes;
} JavaClass;

#endif //__JAVA_CLASS_STRUCTS_H__
