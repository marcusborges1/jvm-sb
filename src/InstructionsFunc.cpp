#include "InstructionsFunc.h"


/** @brief ...
@param Frame *currentFrame ponteiro para o frame atual
@return void
*/
void nop(Frame *curr_frame){
    curr_frame->pc++;
}

void fsub(Frame *curr_frame){
  float f1, f2, f3;
  u4 a1,a2,a3;

  // Get First Argument
  a2 = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();
  // Get second Argument
  a1 = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();
  // convert u4 to float
  memcpy(&f2, &a2, sizeof(f2));
  memcpy(&f1, &a1, sizeof(f1));
  f3 = f1 - f2;
  // convert float to u4
  memcpy(&a3, &f3, sizeof(a3));
  curr_frame->operand_stack.push(a3);

  curr_frame->pc++;
}

void getfield(Frame *curr_frame){
  
}





/** @brief Coloca na pilha de operandos a variável da posição 0 do vetor de variáveis locais
@param Frame *currentFrame ponteiro para o frame atual
@return void
*/
void aload_0(Frame *curr_frame)
{
	//incrementa pc
	curr_frame->pc++;
	//coloca variável na pilha
	curr_frame->operand_stack.push(curr_frame->local_variables_array.at(0));
}


void invokespecial(Frame *curr_frame)
{
	//incrementa pc
	curr_frame->pc++;

	u2 index_method = curr_frame->method_code.code[curr_frame->pc];
	index_method = (index_method << 8) + curr_frame->method_code.code[curr_frame->pc + 1];

	CpInfo &ref_method = curr_frame->constant_pool_reference[index_method - 1];
	CpInfo &name_and_type = curr_frame->constant_pool_reference[ref_method.MethodRef.name_and_type - 1];

	std::string class_name = ref_method->get_utf8_constant_pool(curr_frame->constant_pool_reference, ref_method.MethodRef.index -1);
	std::string method_name = ref_method->get_utf8_constant_pool(curr_frame->constant_pool_reference, name_and_type.NameAndType.name_index - 1);
	std::string method_descriptor = ref_method->get_utf8_constant_pool(curr_frame->constant_pool_reference, name_and_type.NameAndType.descriptor_index -1);

	curr_frame->pc++;

	if (((class_name == "java/lang/Object") || (class_name == "java/lang/String") && (method_name == "<init>")) ||
		((class_name == "java/lang/StringBuilder") && (method_name == "<init>")))
	{
		if ((class_name == "java/lang/String") || (class_name == "java/lang/StringBuilder"))
		{
					curr_frame->operand_stack.pop();
		}
		else if (method_name == "<init>")
		{
			u4 variable_class = curr_frame->local_variables_array.at(0);
			
		}
	}


}





