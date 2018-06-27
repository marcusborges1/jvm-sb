#include "AttributeInfoReader.h"
#include "ClassFilePrinter.h"
#include "ReadBytes.h"
#include <string.h>

// void read_attribute_info(FILE *fp, JavaClass* class_file, AttributeInfo *attributes);
//
// void read_attr_code(FILE* fp, JavaClass* class_file, AttributeInfo* attributes) {
// 	attributes->code = (AttrCode*)malloc(sizeof(AttrCode));
// 	attributes->code->max_stack = read_2_bytes(fp);
// 	attributes->code->max_locals = read_2_bytes(fp);
//
// 	attributes->code->code_length = read_4_bytes(fp);
// 	attributes->code->code = (uint8_t*)malloc(attributes->code->code_length*sizeof(uint8_t));
// 	for (int k = 0; k < attributes->code->code_length; ++k) {
// 			attributes->code->code[k] = read_1_byte(fp);
// 	}
//
// 	attributes->code->exceptions_table_length = read_2_bytes(fp);
// 	attributes->code->exceptions = (AttrCodeException*)malloc(attributes->code->exceptions_table_length*sizeof(AttrCodeException));
// 	for (int i = 0; i < attributes->code->exceptions_table_length; i++) {
// 			AttrCodeException *exception = attributes->code->exceptions + i;
// 			exception->start_pc = read_2_bytes(fp);
// 			exception->end_pc = read_2_bytes(fp);
// 			exception->handler_pc = read_2_bytes(fp);
// 			exception->catch_type = read_2_bytes(fp);
// 	}
//
// 	attributes->code->attr_counts = read_2_bytes(fp);
// 	attributes->code->attributes = (AttributeInfo*)malloc(attributes->code->attr_counts*sizeof(AttributeInfo));
// 	for (int j = 0; j < attributes->code->attr_counts; j++) {
// 			AttributeInfo *info = attributes->code->attributes + j;
// 			read_attribute_info(fp, class_file, info);
// 	}
// }

void read_attribute_info(FILE *fp, JavaClass* class_file) {
	// int i;
	//
	// if (class_file->field_count == 0) {
	// 	return;
	// }
	//
	// class_file->fields = (FieldInfo *) malloc(sizeof(FieldInfo) * class_file->field_count);
	// for (i = 0; i < class_file->field_count; i++) {
	// 	class_file->fields[i].access_flags = read_2_bytes(fp);
	// 	class_file->fields[i].name_index = read_2_bytes(fp);
	// 	class_file->fields[i].descriptor_index = read_2_bytes(fp);
	// 	class_file->fields[i].attributes_count = read_2_bytes(fp);
	// }
}
