/** @file AttributeInfo.cpp
 *  @brief Leitura dos atributos do arquivo .class
 *  @bug No know bugs.
 */
#include <iostream>
#include "Instruction.h"
#include "AttributeInfo.h"
#include "ReadBytes.h"


/** @brief ...
 *  @param class_file ...
 *  @param fp ...
 *  @param attribute_info ...
 *  @return ...
 */
ConstantValueAttribute ConstantValueAttribute::read(JavaClass class_file,
                                                FILE * fp,
                                                AttributeInfo attribute_info) {
    // attribute_info.constant_value.attribute_name_index = read_2_bytes(fp);
    // attribute_info.constant_value.attribute_length = read_4_bytes(fp);
    attribute_info.constant_value.constantvalue_index = read_2_bytes(fp);
    return  attribute_info.constant_value;
}

/** @brief ...
 *  @param class_file ...
 *  @param fp ...
 *  @param attribute_info ...
 *  @return ...
 */
CodeAttribute CodeAttribute::read(JavaClass class_file, FILE* fp,
                                  AttributeInfo attribute_info) {
    AttributeInfo *attributeinfo = new AttributeInfo();
    attribute_info.code.max_stack = read_2_bytes(fp);
    attribute_info.code.max_locals = read_2_bytes(fp);
    attribute_info.code.code_length = read_4_bytes(fp);
    attribute_info.code.code = (u1*)malloc(
                                  sizeof(u1)*attribute_info.code.code_length);

    for (int i = 0; (unsigned)i < attribute_info.code.code_length; i++) {
        attribute_info.code.code[i] = read_1_byte(fp);
    }
    printf("\n");

    attribute_info.code.exception_table_length = read_2_bytes(fp);
    attribute_info.code.exception_table = (CodeException*)malloc(
            sizeof(CodeException)*attribute_info.code.exception_table_length);
    for (int j = 0; j < attribute_info.code.exception_table_length; j++) {
        attribute_info.code.exception_table[j].start_pc = read_2_bytes(fp);
        attribute_info.code.exception_table[j].end_pc = read_2_bytes(fp);
        attribute_info.code.exception_table[j].handler_pc = read_2_bytes(fp);
        attribute_info.code.exception_table[j].catch_type = read_2_bytes(fp);
    }

    attribute_info.code.attributes_count = read_2_bytes(fp);
    attribute_info.code.attributes = (AttributeInfo*)malloc(
                    sizeof(AttributeInfo)*attribute_info.code.attributes_count);

    for (int k = 0; k < attribute_info.code.attributes_count; k++)
        attribute_info.code.attributes[k] = attributeinfo->get_attribute_info(
                            fp, attribute_info.code.attributes[k], class_file);

    return attribute_info.code;
}

/** @brief Lê o atributo LOCAL VARIABLE
 *  @param class_file ...
 *  @param attribute_struct ...
 *  @return ...
 */
LocalVariableTableAttribute LocalVariableTableAttribute::read(FILE *class_file,
                                              AttributeInfo attribute_struct) {
    int i;
    LocalVariableTableDataAttribute *info_data = new LocalVariableTableDataAttribute();
    LocalVariableTableAttribute info_local_variable_table;

    info_local_variable_table.local_variable_table_length = read_2_bytes(
                                                                  class_file);

    info_local_variable_table.table_data = (
              LocalVariableTableDataAttribute*)malloc(
                info_local_variable_table.local_variable_table_length * sizeof(
              LocalVariableTableDataAttribute));

    for (i = 0;
        i < attribute_struct.local_variable_table.local_variable_table_length;
        i++)
        info_local_variable_table.table_data[i] = info_data->read(class_file,
                                                            attribute_struct);

    return info_local_variable_table;
}

/** @brief Lê o atributo LOCAL VARIABLE
 *  @param class_file ...
 *  @param attribute_struct ...
 *  @return ...
 */
LocalVariableTableDataAttribute LocalVariableTableDataAttribute::read(
                                              FILE *class_file,
                                              AttributeInfo attribute_struct) {
    LocalVariableTableDataAttribute info_local_variable;

    info_local_variable.start_pc = read_2_bytes(class_file);
    info_local_variable.length = read_2_bytes(class_file);
    info_local_variable.name_index = read_2_bytes(class_file);
    info_local_variable.descriptor_index = read_2_bytes(class_file);
    info_local_variable.index = read_2_bytes(class_file);


    return info_local_variable;
}

/** @brief Lê o atributo LINE NUMBER
 *  @param class_file ...
 *  @param attribute_struct ...
 *  @return ...
 */
LineNumberTableAttribute LineNumberTableAttribute::read(FILE *class_file,
                                              AttributeInfo attribute_struct) {
    int i;

    LineNumberTableDataAttribute *info_data = new LineNumberTableDataAttribute();
    LineNumberTableAttribute info_line_number_table;

    info_line_number_table.line_number_table_length = read_2_bytes(
                                                                class_file);

    info_line_number_table.table = (LineNumberTableDataAttribute*)malloc(
                      info_line_number_table.line_number_table_length * sizeof(
                                                LineNumberTableDataAttribute));

    for (i = 0; i < info_line_number_table.line_number_table_length; i++)
        info_line_number_table.table[i] = info_data->read(class_file,
                                                          attribute_struct);

    return info_line_number_table;
}

/** @brief Lê o atributo LINE NUMBER
 *  @param class_file ...
 *  @param attribute_struct ...
 *  @return ...
 */
LineNumberTableDataAttribute LineNumberTableDataAttribute::read(
                                              FILE *class_file,
                                              AttributeInfo attribute_struct) {
    LineNumberTableDataAttribute info_line_number_table_data;

    info_line_number_table_data.start_pc = read_2_bytes(class_file);
    info_line_number_table_data.line_pc = read_2_bytes(class_file);

    return info_line_number_table_data;
}

/** @brief ...
 *  @param class_file ...
 *  @param attribute_struct ...
 *  @return ...
 */
InnerClassAttribute InnerClassAttribute::read(FILE *class_file,
                                              AttributeInfo attribute_struct) {
    int i;

    InnerClassDataAttribute *info_data = new InnerClassDataAttribute();
    InnerClassAttribute info_inner_class;

    info_inner_class.number_of_classes = read_2_bytes(class_file);

    info_inner_class.inner_class_data = (InnerClassDataAttribute*)malloc(
        info_inner_class.number_of_classes * sizeof(InnerClassDataAttribute));

    for (i = 0; i < info_inner_class.number_of_classes; i++)
        info_inner_class.inner_class_data[i] = info_data->read(
                                                class_file, attribute_struct);

    return info_inner_class;
}

/** @brief ...
 *  @param class_file ...
 *  @param attribute_struct ...
 *  @return ...
 */
InnerClassDataAttribute InnerClassDataAttribute::read(FILE *class_file,
                                            AttributeInfo attribute_struct) {
    InnerClassDataAttribute info_inner_class_data;

    info_inner_class_data.inner_class_info_index = read_2_bytes(class_file);
    info_inner_class_data.outer_class_info_index = read_2_bytes(class_file);
    info_inner_class_data.inner_name_index = read_2_bytes(class_file);
    info_inner_class_data.inner_class_access_flag = read_2_bytes(class_file);

    return info_inner_class_data;
}

/** @brief ...
 *  @param class_file ...
 *  @param attribute_struct ...
 *  @return ...
 */
Exception Exception::read(FILE *class_file, AttributeInfo attribute_struct) {
    int i;

    Exception info_exception;

    info_exception.number_exceptions = read_2_bytes(class_file);

    for (i = 0; i < info_exception.number_exceptions; i++)
        info_exception.exception_index_table[i] = read_2_bytes(class_file);

    return info_exception;
}

/** @brief ...
 *  @param class_file ...
 *  @param attribute_struct ...
 *  @return ...
 */
SourceFileAttribute SourceFileAttribute::read(FILE *class_file,
                                            AttributeInfo attribute_struct) {
    SourceFileAttribute info_source_file;

    info_source_file.source_file_index = read_2_bytes(class_file);

    return info_source_file;
}

/** @brief ...
 *  @param class_file ...
 *  @param fp ...
 *  @return ...
 */
void AttributeInfo::read(JavaClass class_file, FILE *fp) {
    for (int i = 0; i < class_file.attributes_count ; i++)
        class_file.attributes[i] = this->get_attribute_info(fp,
                                        class_file.attributes[i], class_file);
}

/** @brief ...
 *  @param fp ...
 *  @param attribute_info ...
 *  @param class_file ...
 *  @return ...
 */
AttributeInfo AttributeInfo::get_attribute_info(FILE *fp,
                                                AttributeInfo attribute_info,
                                                JavaClass class_file) {

    attribute_info.attribute_name_index = read_2_bytes(fp);
    attribute_info.attribute_length = read_4_bytes(fp);
    std::string attribute_name = cpinfo->get_utf8_constant_pool(
          class_file.constant_pool, attribute_info.attribute_name_index - 1);

    if (attribute_name == "Code") {
        attribute_info.code = code_info->read(class_file, fp, attribute_info);
        return attribute_info;
    }
    else if (attribute_name == "ConstantValue") {
        attribute_info.constant_value = constant_info->read(class_file, fp,
                                                            attribute_info);
    }
    else if (attribute_name == "Exceptions") {
        attribute_info.execptions = exp_info->read(fp, attribute_info);
    }
    else if (attribute_name =="InnerClasses") {
        attribute_info.inner_class = inner_info->read(fp, attribute_info);
    }
    else if (attribute_name == "Synthetic") {
        // não fazer nada
    }
    else if (attribute_name =="SourceFile") {
        attribute_info.source_file = source_info->read(fp, attribute_info);
    }
    else if (attribute_name == "LineNumberTable") {
        attribute_info.line_number_table = line_number_info->read(fp,
                                                              attribute_info);
    }
    else if (attribute_name == "LocalVariableTable") {
        attribute_info.local_variable_table = local_info->read(fp,
                                                              attribute_info);
    }
    else {
        //ignora silenciosamente os outros atributos
        for (int j = 0; (unsigned)j < attribute_info.attribute_length; j++) {
            attribute_info.info[j] = read_1_byte(fp);
        }
    }

    return attribute_info;
}
