#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#define CONSTANT_Class  7
#define CONSTANT_Fieldref  9
#define CONSTANT_Methodref  10
#define CONSTANT_InterfaceMethodref  11
#define CONSTANT_String 8
#define CONSTANT_Integer 3
#define CONSTANT_Float 4
#define CONSTANT_Long 5
#define CONSTANT_Double 6
#define CONSTANT_NameAndType  12
#define CONSTANT_Utf8 1

typedef struct {
  uint8_t  tag;

  union {
    struct {
      uint16_t type_class_info;
    } Class;

    struct {
      uint16_t class_index;
      uint16_t name_and_type_index;
    } FieldRef;

    struct {
      uint16_t index;
      uint16_t name_and_type;
    } MethodRef;

    struct {
      uint16_t index;
      uint16_t name_and_type;
    } InterfaceMethodRef;

    struct {
      uint16_t bytes;
    } String;

    struct {
      uint32_t bytes;
    } Integer;

    struct {
      uint32_t bytes;
    } Float;

    struct {
      uint32_t high_bytes;
      uint32_t low_bytes;
    } Long;

    struct {
      uint32_t high_bytes;
      uint32_t low_bytes;
    } Double;

    struct {
      uint16_t name_index;
      uint16_t descriptor_index;
    } NameAndType;

    struct {
      uint16_t size;
      uint8_t  *bytes;
    } UTF8;
  };
} CpInfo;

typedef struct {
  uint32_t 	magic_number;
  uint16_t  minor_version;
  uint16_t  major_version;
  uint16_t  constant_pool_count;
  CpInfo*   contant_pool;
} JavaClass;
