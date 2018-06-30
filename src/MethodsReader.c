#include "FieldReader.h"
#include "AttributeInfoReader.h"
#include "ReadBytes.h"
#include "MethodReader.h"

/*  @brief Lê os métodos contidos no .class e os atributos desses métodos
 *  @param fp ponteiro pro arquivo .class
 *  @param class_file estrutura de dados do .class
 *  @return void
 */
 void read_methods(FILE* fp, JavaClass* class_file){
   int count;
   class_file->methods = (MethodInfo*) malloc(class_file->methods_count * sizeof(MethodInfo));

   for(int i = 0; i < class_file->methods_count; i++){
     MethodInfo *method = class_file->methods + i;

     method->access_flag = read_2_bytes(fp);
     method->name_index = read_2_bytes(fp);
     method->descriptor_index = read_2_bytes(fp);
     method->attributes_count = read_2_bytes(fp);

     method->attributes = (AttributeInfo*)malloc(method->attributes_count * sizeof(AttributeInfo));
     for (count = 0; count < method->attributes_count; ++count)
     {
         attribute_types_info(fp, class_file, method->attributes + count);
     }
   }

 }
