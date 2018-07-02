/** @file FieldInfo.h
 *  @brief ...
 *  @bug No know bugs.
 */
#ifndef JVM_CPP_FIELDINFO_H
#define JVM_CPP_FIELDINFO_H

#include "JavaClass.h"
#include "AttributeInfo.h"


/**
 * @brief ...
 **/
class FieldInfo {
	public:
    u2  access_flag; // CONSTANT_UTf8, field name
    u2  name_index; // CONSTANT_UTf8, field valid descriptor
    u2  descriptor_index; // number of field attributes
		// JVM implementation should ignore in silence each attribute unrecognized
    u2  atributes_count;
    AttributeInfo  *attributes;

    void static read(JavaClass, FILE*);
};

#endif
