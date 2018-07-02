/** @file FieldInfo.cpp
 *  @brief ...
 *  @bug No know bugs.
 */
#include <iostream>
#include "FieldInfo.h"
#include "ReadBytes.h"


/** @brief ...
*  @param class_file ...
*  @param fp ...
*  @return void
*/
void FieldInfo::read(JavaClass class_file, FILE * fp) {
  AttributeInfo *attributeinfo = new AttributeInfo();
  for (int i = 0; i < class_file.fields_count; i++) {
    // printf("FIELDS--->>%d\n", class_file.fields_count);
    class_file.fields[i].access_flag = read_2_bytes(fp);
    // printf("FLAGS--->>%d\n", class_file.fields[i].access_flag);
    class_file.fields[i].name_index = read_2_bytes(fp);
    // printf("NAME_INDEX--->>%d\n", class_file.fields[i].name_index);
    class_file.fields[i].descriptor_index = read_2_bytes(fp);
    // printf("DESCR_INDEX--->>%d\n", class_file.fields[i].descriptor_index);
    class_file.fields[i].atributes_count = read_2_bytes(fp);
    // printf("ATR_COUNT--->>%d\n", class_file.fields[i].atributes_count);

    class_file.fields[i].attributes = (AttributeInfo*)malloc(class_file.fields[i].atributes_count*sizeof(AttributeInfo));
    for (int j = 0;  j < class_file.fields[i].atributes_count; j++)
        attributeinfo->get_attribute_info(fp, class_file.fields[i].attributes[j], class_file);
  }
}
