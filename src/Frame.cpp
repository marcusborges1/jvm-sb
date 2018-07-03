/** @file Frame.cpp
 *  @brief Inicia o Frame de execução com vetor de variáveis locais, operandos,
 *        contador de programa e ponteiro para pool de constantes.
 *  @bug No know bugs.
 */
#include "Frame.h"
#include "MethodInfo.h"
#include "AttributeInfo.h"
#include "Instruction.h"


/** @brief Construtor do Frame.
*   Constrói o Frame com as informações gerais da classe
*   (constant_pool_reference), informações de método (method_info),
*   código do método (method_code), inica PC com 0 e dimensiona o vetor de
*   variáveis locais.
*  @param *method ponteiro para informações do método
*  @param *cp_info ponteiro para a pool de constantes
*/
Frame::Frame(MethodInfo* method, CpInfo* cp_info) {
  constant_pool_reference = cp_info;
  method_info = method;
  pc = 0;

  // coleta código do método
  for (int i = 0; i < method_info->attributes_count; i++) {
      AttributeInfo* attr = method_info->attributes + i;
      std::string string_c = cp_info->get_utf8_constant_pool(cp_info,
                                                attr->attribute_name_index-1);
      if (string_c == "Code") method_code = attr->code;
  }

  local_variables_array.resize(method_code.max_locals);
}
