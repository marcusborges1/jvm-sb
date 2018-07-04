#include "InstructionsFunc.h"
#include "Interpreter.h"
#include "CpInfo.h"
#include <sstream>

namespace patch {
  template < typename T > std::string to_string( const T& n ) {
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
  }
}

/** @brief Não faz nada, só incrementa pc.
 * param *curr_frame ponteiro para o frame atual
 * @return void
 */
void nop(Frame *curr_frame) {
  curr_frame->pc++;
}

/** @brief Coloca na pilha de operandos uma constante do tamanho de uma word.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void ldc(Frame *curr_frame) {
  Operand *op = (Operand*)malloc(sizeof(Operand));
  curr_frame->pc++;

  u1 index = curr_frame->method_code.code[curr_frame->pc];

  CpInfo &cpinfo = curr_frame->constant_pool_reference[index-1];
  op->tag = cpinfo.tag;
  switch (op->tag) {
    case CONSTANT_Integer:
        op->type_int = cpinfo.Integer.bytes;
        break;
    case CONSTANT_Float:
        op->type_float = cpinfo.Float.bytes;
        break;
    case CONSTANT_String: {
        std::string utf8_s = cpinfo.get_utf8_constant_pool(
                                          curr_frame->constant_pool_reference,
                                          cpinfo.String.bytes-1);
        op->type_string = new std::string(utf8_s); }
        break;
    case CONSTANT_Class:
        break;
    default:
        // Constant_Method_Handle
        // Constant_Method_Ref
        break;
    }
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Guarda referência do object ou array do operando na variável local 1.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void astore_1(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *op = curr_frame->pop_operand();
  curr_frame->local_variables_array.at(1) = op;
}

/** @brief ...
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_1(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 1;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra o valor NULL na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void aconst_null(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_EmptySpace;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_m1(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = -1;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_0(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 0;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_2(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 2;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_3(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 3;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_4(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 4;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_5(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 5;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief ...
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void getfield(Frame *curr_frame) {
  u1 byte1 = curr_frame->method_code.code[curr_frame->pc++];
  u1 byte2 = curr_frame->method_code.code[curr_frame->pc++];

  u2 index = (byte1<<8) | byte2;

  CpInfo field_ref = curr_frame->constant_pool_reference[index-1];
  CpInfo name_and_type = curr_frame->constant_pool_reference[
                                  field_ref.FieldRef.name_and_type_index-1];

  std::string class_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(
        curr_frame->constant_pool_reference, field_ref.FieldRef.class_index-1);
  std::string field_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(
    curr_frame->constant_pool_reference, name_and_type.NameAndType.name_index-1);

  curr_frame->operand_stack.pop();

  // curr_frame->push_operand(classVariable);
}

/**
 * @brief Recebe um campo estático a partir de uma classe.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void getstatic(Frame *curr_frame) {
    curr_frame->pc++;

    u2 index = curr_frame->method_code.code[curr_frame->pc++];
    index = (index << 8) + curr_frame->method_code.code[curr_frame->pc++];

    CpInfo &field_info = curr_frame->constant_pool_reference[index-1];
    CpInfo &name_and_type = curr_frame->constant_pool_reference[
                                  field_info.FieldRef.name_and_type_index-1];
    std::string class_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(
      curr_frame->constant_pool_reference, field_info.FieldRef.class_index-1);

    if (class_name == "java/lang/System") {
        // se for a classe System (default java) não coloca na pilha
        return;
    }

    JavaClass class_info = get_class_info_and_load_not_exists(class_name);
    std::string var_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(
                                      class_info.constant_pool,
                                      name_and_type.NameAndType.name_index-1);

    Operand *static_field = get_static_field_of_class(class_name, var_name);

    curr_frame->push_operand(static_field);
}

/** @brief Coloca na pilha de operandos a variável da posição 0 do vetor de
 *          variáveis locais.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void aload_0(Frame *curr_frame) {
    curr_frame->pc++;
    curr_frame->push_operand(curr_frame->local_variables_array.at(0));
}

/** @brief Coloca na pilha de operandos a variável da posição 1 do vetor de
 *          variáveis locais.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void aload_1(Frame *curr_frame) {
    curr_frame->pc++;
    curr_frame->push_operand(curr_frame->local_variables_array.at(1));
}

/** @brief Coloca na pilha de operandos a variável da posição 2 do vetor de
 *          variáveis locais.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void aload_2(Frame *curr_frame) {
    curr_frame->pc++;
    curr_frame->push_operand(curr_frame->local_variables_array.at(2));
}

/** @brief Coloca na pilha de operandos a variável da posição 3 do vetor de
 *          variáveis locais.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void aload_3(Frame *curr_frame) {
    curr_frame->pc++;
    curr_frame->push_operand(curr_frame->local_variables_array.at(3));
}

/**
 * @brief Invoca instância de método baseado na classe.
 * @param *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void invokevirtual(Frame *curr_frame) {
    curr_frame->pc++;

    u2 index = curr_frame->method_code.code[curr_frame->pc] << 16;
    index += curr_frame->method_code.code[++curr_frame->pc];

    curr_frame->pc++;

    CpInfo &method_ref = curr_frame->constant_pool_reference[index-1];
    CpInfo &name_and_type = curr_frame->constant_pool_reference[
                                        method_ref.MethodRef.name_and_type-1];

    std::string class_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(
                                            curr_frame->constant_pool_reference,
                                            method_ref.MethodRef.index-1);
    std::string method_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(
                                      curr_frame->constant_pool_reference,
                                      name_and_type.NameAndType.name_index-1);
    std::string method_desc = curr_frame->constant_pool_reference->get_utf8_constant_pool(
                                curr_frame->constant_pool_reference,
                                name_and_type.NameAndType.descriptor_index-1);

    if (strstr(class_name.c_str(), "java/")) {
        if (class_name == "java/io/PrintStream" &&
            (method_name == "println" || method_name == "print")) {
            if (method_desc != "()V") {
                Operand *op = curr_frame->pop_operand();

                switch(op->tag) {
                    case CONSTANT_Byte:
                        std::cout <<(int) op->type_byte;
                        break;
                    case CONSTANT_Char:
                        std::cout << (char) op->type_char;
                        break;
                    case CONSTANT_Short:
                        std::cout << (short)op->type_short;
                        break;
                    case CONSTANT_Boolean:
                        std::cout << (bool) op->type_bool;
                        break;
                    case CONSTANT_String:
                        std::cout << *op->type_string;
                        break;
                    case CONSTANT_Integer:
                        std::cout << (int32_t)op->type_int;
                        break;
                    case CONSTANT_Float:
                        float float_v;
                        memcpy(&float_v, &op->type_float, sizeof(float));
                        printf("%f", float_v);
                        break;
                    case CONSTANT_Long:
                        std::cout <<(long) op->type_long;
                        break;
                    case CONSTANT_Double:
                        double double_v;
                        memcpy(&double_v, &op->type_double, sizeof(double));
                        printf("%.15lf", double_v);
                        break;
                    case CONSTANT_EmptySpace:
                        printf("null");
                        break;
                    case CONSTANT_Class: {
                        ClassInstance *c_instance = op->c_instance;
                        JavaClass info_class = c_instance->info_class;
                        std::string t_class_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(
                                          info_class.constant_pool,
                                          info_class.this_class-1);
                        std::cout << t_class_name << "@" << c_instance;
                    }
                        break;
                }
                if (method_name == "println") {
                    printf("\n");
                }
            }
        } else if (class_name == "java/lang/String" &&
                  method_name == "length") {
            Operand *str_ref = curr_frame->pop_operand();

            Operand *str_len = (Operand*)malloc(sizeof(Operand));
            str_len->tag = CONSTANT_Integer;
            str_len->type_int = str_ref->type_string->size();
            curr_frame->push_operand(str_len);

        } else if (class_name == "java/lang/StringBuilder" &&
                  method_name == "append") {
            Operand *t_append = curr_frame->pop_operand();
            Operand *str_append = copy_operand(curr_frame->pop_operand());

            switch (t_append->tag) {
                case CONSTANT_String:
                    *str_append->type_string += (*t_append->type_string);
                    break;
                case CONSTANT_Integer:
                    *str_append->type_string += (
                                        patch::to_string(t_append->type_int));
                    break;
                case CONSTANT_Long:
                    *str_append->type_string += (
                                        patch::to_string(t_append->type_long));
                    break;
                case CONSTANT_Float:
                    *str_append->type_string += (
                                      patch::to_string(t_append->type_float));
                    break;
                case CONSTANT_Double:
                    *str_append->type_string += (
                                      patch::to_string(t_append->type_double));
                    break;
                case CONSTANT_Short:
                    *str_append->type_string += (
                                        patch::to_string(t_append->type_short));
                    break;
                case CONSTANT_Char:
                    *str_append->type_string += (
                                        patch::to_string(t_append->type_char));
                    break;
                case CONSTANT_Byte:
                    *str_append->type_string += (
                                        patch::to_string(t_append->type_byte));
                    break;
                case CONSTANT_Boolean:
                    if (t_append->type_bool == 0)
                        *str_append->type_string += "false";
                    else
                        *str_append->type_string += "true";
                    break;
                case CONSTANT_Class:
                    // @TODO colocar enderec
                    *str_append->type_string += *t_append->c_instance->name_class+"@";
                    break;
                case CONSTANT_Array:
                    *str_append->type_string += "Array[]";
                    break;
            }
            curr_frame->push_operand(str_append);
        } else if (class_name == "java/lang/StringBuilder") {
            // ignorando o toString;
            return;
        }
    } else {
        int qtde_arg = 0;
        u2 counter = 1;

        while (method_desc[counter] != ')') {
            char found_type = method_desc[counter];
            if (found_type == 'L') { // tipo é um objeto
                qtde_arg++;
                while (method_desc[++counter] != ';');

            } else if (found_type == '[') { // tipo é um array?
                qtde_arg++;
                while (method_desc[++counter] == '[');

                if (method_desc[counter] == 'L')
                    while (method_desc[++counter] != ';');
            } else qtde_arg++;
            counter++;
        }
        std::vector<Operand*> args;

        for (int i = 0; i < qtde_arg; ++i) {
            Operand *arg = curr_frame->pop_operand();
            args.insert(args.begin(), arg);
            if (arg->tag == CONSTANT_Double || arg->tag == CONSTANT_Long)
                args.insert(args.begin()+1, check_string_create_type("P"));
        }

        Operand *current_class = curr_frame->pop_operand();
        args.insert(args.begin(), current_class);

        ClassInstance *c_instance = current_class->c_instance;

        MethodInfo *method_info = find_method(c_instance->info_class,
                                            method_name, method_desc);
        Frame *new_frame = new Frame(method_info,
                                    c_instance->info_class.constant_pool);

        for (int j = 0; (unsigned)j < args.size(); ++j)
            new_frame->local_variables_array.at(j) = args.at(j);

        push_frame(new_frame);
    }
}

/**
* @brief Invoca o método de instância, e trata da inicialiação da superclasse
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void invokespecial(Frame *curr_frame) {
	//incrementa pc
	curr_frame->pc++;

	u2 index_method = curr_frame->method_code.code[curr_frame->pc];
	index_method = (index_method << 8) + curr_frame->method_code.code[
                                                          ++curr_frame->pc];

	CpInfo &ref_method = curr_frame->constant_pool_reference[index_method-1];
	CpInfo &name_and_type = curr_frame->constant_pool_reference[
                                      ref_method.MethodRef.name_and_type-1];

	std::string class_name = ref_method.get_utf8_constant_pool(
          curr_frame->constant_pool_reference, ref_method.MethodRef.index -1);
	std::string method_name = ref_method.get_utf8_constant_pool(
                                    curr_frame->constant_pool_reference,
                                    name_and_type.NameAndType.name_index - 1);
	std::string method_descriptor = ref_method.get_utf8_constant_pool(
                                curr_frame->constant_pool_reference,
                                name_and_type.NameAndType.descriptor_index -1);

  //incrementa pc
	curr_frame->pc++;

	if ( ((class_name == "java/lang/Object" || class_name == "java/lang/String")
      && method_name == "<init>") ||
		(class_name == "java/lang/StringBuilder" && method_name == "<init>")) {
		if (class_name == "java/lang/String" ||
        class_name == "java/lang/StringBuilder") {
			curr_frame->pop_operand();
		}
		else if (method_name == "<init>") {
			Operand *variable_class = curr_frame->local_variables_array.at(0);
			load_class_var(variable_class->c_instance);
		}
		return;

    } else if (class_name.find("java/") != std::string::npos) {
        printf("Classe java nao implementada.");
        getchar();
        exit(1); // caso seja algum outro tipo de classe java nao implementada
    } else {
        int count_args = 0;
        u2 counter = 1;

        while (method_descriptor[counter] != ')') {
            char created_type = method_descriptor[counter];
            if (created_type == 'L') { // tipo é um objeto
                count_args++;
                while (method_descriptor[++counter] != ';');
            } else if (created_type == '[') {
                count_args++;
                while (method_descriptor[++counter] == '[');
                if (method_descriptor[counter] == 'L')
                    while (method_descriptor[++counter] != ';');
            } else count_args++;
            counter++;
        }
        std::vector<Operand*> arguments;

        for (int i = 0; i < count_args; ++i) {
            Operand *argument = curr_frame->pop_operand();
            arguments.insert(arguments.begin(), argument);
            if (argument->tag == CONSTANT_Double ||
                argument->tag == CONSTANT_Long) {
                arguments.insert(arguments.begin()+1,
                                check_string_create_type("P"));
            }
        }

        Operand *current_class = curr_frame->pop_operand();
        arguments.insert(arguments.begin(), current_class);

        ClassInstance *reference_class = current_class->c_instance;

        MethodInfo *method_info_found = find_method(reference_class->info_class,
                                              method_name, method_descriptor);
        Frame *new_frame = new Frame(method_info_found,
                                    reference_class->info_class.constant_pool);

        for (int j = 0; (unsigned)j < arguments.size(); ++j)
            new_frame->local_variables_array.at(j) = arguments.at(j);

        push_frame(new_frame);
    }
}

/**
* @brief Retorna void de uma instrução.
* @param *curr_frame ponteiro para o frame atual
* @return void
*/
void void_return(Frame *curr_frame){
    curr_frame->pc++;
    pop_frame();
}

/**
 * @brief Incrementa uma variavel local em uma constante
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iinc(Frame *curr_frame) {
    u1 index = curr_frame->method_code.code[curr_frame->pc++];
    u1 constant_value = curr_frame->method_code.code[curr_frame->pc++];
    curr_frame->local_variables_array.at(index) += constant_value;
    curr_frame->pc++;
}

/**
 * @brief Pusha um inteiro, indicado por um indice, na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iload(Frame *curr_frame) {
    u1 index = curr_frame->method_code.code[curr_frame->pc++];
    curr_frame->push_operand(curr_frame->local_variables_array.at(index));
    curr_frame->pc++;
}

/**
 * @brief Pusha o inteiro do indice 0 na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iload_0(Frame *curr_frame) {
    curr_frame->push_operand(curr_frame->local_variables_array.at(0));
    curr_frame->pc++;
}

/**
 * @brief Pusha o inteiro do indice 1 na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iload_1(Frame *curr_frame) {
    curr_frame->push_operand(curr_frame->local_variables_array.at(1));
    curr_frame->pc++;
}

/**
 * @brief Pusha o inteiro do indice 2 na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iload_2(Frame *curr_frame) {
    curr_frame->push_operand(curr_frame->local_variables_array.at(2));
    curr_frame->pc++;
}

/**
 * @brief Pusha o inteiro do indice 3 na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iload_3(Frame *curr_frame) {
    curr_frame->push_operand(curr_frame->local_variables_array.at(3));
    curr_frame->pc++;
}


/**
 * @brief Empilha a constante long 0 na pilha de opreandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lconst_0(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Long;
    op->type_long = 0;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;
}

/**
 * @brief Empilha a constante long 1 na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lconst_1(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Long;
    op->type_long = 1;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;
}

/**
 * @brief Empilha a constante float 0 na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fconst_0(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Float;
    op->type_long = 0.0;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;
}

/**
 * @brief Empilha a constante float 1 na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fconst_1(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Float;
    op->type_long = 1.0;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;
}

/**
 * @brief Empilha a constante float 0 na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fconst_2(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Float;
    op->type_long = 2.0;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;
}

/**
 * @brief Empilha a constante double 0 na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dconst_0(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Double;

    op->type_double = 0.0;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;
}

/**
 * @brief Empilha a constante double 1 na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dconst_1(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Double;

    op->type_double = 1.0;
    curr_frame->operand_stack.push(op);
    curr_frame->pc++;
}

/**
 * @brief Empilha int composto por byte de argumento na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void bipush(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    u1 byte = curr_frame->method_code.code[curr_frame->pc++];

    op->tag = CONSTANT_Integer;
    op->type_int = byte;
    curr_frame->operand_stack.push(op);

}

/**
 * @brief Empilha int composto por byte de argumento na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void sipush(Frame *curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    u1 byte = curr_frame->method_code.code[curr_frame->pc++];
    u1 byte2 = curr_frame->method_code.code[curr_frame->pc++];
    op->tag = CONSTANT_Integer;
    op->type_int = (byte<<8)|byte2;
    curr_frame->operand_stack.push(op);

}

/**
 * @brief Empilha long indicado no indice 0 do array de variáveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lload_0(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[0]);
  curr_frame->pc++;
}

/**
 * @brief Empilha long indicado no indice 1 do array de variáveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lload_1(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[1]);
  curr_frame->pc++;
}

/**
 * @brief Empilha long indicado no indice 2 do array de variáveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lload_2(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[2]);
  curr_frame->pc++;
}

/**
 * @brief Empilha long indicado no indice 3 do array de variáveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lload_3(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[3]);
  curr_frame->pc++;
}


/**
 * @brief Empilha float indicado no indice 0 do array de variáveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fload_0  (Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[0]);
  curr_frame->pc++;
}

/**
 * @brief Empilha float indicado no indice 1 do array de variáveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fload_1  (Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[1]);
  curr_frame->pc++;
}

/**
 * @brief Empilha float indicado no indice 2 do array de variáveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fload_2 (Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[2]);
  curr_frame->pc++;
}

/**
 * @brief Empilha float indicado no indice 3 do array de variáveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fload_3  (Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[3]);
  curr_frame->pc++;
}

/**
 * @brief Empilha float indicado no indice 3 do array de variáveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lload(Frame *curr_frame) {
  int index = curr_frame->method_code.code[curr_frame->pc++];
  curr_frame->operand_stack.push(curr_frame->local_variables_array[index]);
  curr_frame->pc++;
}

/**
 * @brief Cria novo array do tipo definido
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void newarray(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  u4 index = operand_1->type_int;

  Operand *operand_2 = check_string_create_type("[");
  u1 array_type = curr_frame->method_code.code[curr_frame->pc++];

  switch (array_type) {
    case CONSTANT_Boolean:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("Z"));
      }
      break;
    case CONSTANT_Char:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("C"));
      }
      break;
    case CONSTANT_Float:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("F"));
      }
      break;
    case CONSTANT_Double:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("D"));
      }
      break;
    case CONSTANT_Byte:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("B"));
      }
      break;
    case CONSTANT_Short:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("S"));
      }
      break;
    case CONSTANT_Integer:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("I"));
      }
      break;
    case CONSTANT_Long:
      for (int i = 0; i < (int) index; i++) {
        operand_2->array_type->array->emplace_back(check_string_create_type("J"));
      }
      break;
  }

  curr_frame->push_operand(operand_2);
}

/**
 * @brief Cria novo objeto array.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void anewarray(Frame *curr_frame) {}

/**
 * @brief Soma de inteiros. Retira os dois operando do topo da pilha, soma-os e coloca o resultado
 * no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void iadd(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));

  result->tag = CONSTANT_Integer;
  result->type_int = operand_1->type_int + operand_2->type_int;

  curr_frame->push_operand(result);
}

/**
 * @brief Soma do tipo long. Retira os dois operando do topo da pilha, soma-os e coloca o resultado
 * no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ladd(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Long;
  result->type_long = operand_1->type_long + operand_2->type_long;

  curr_frame->push_operand(result);
}

/**
 * @brief Soma do tipo float. Retira os dois operando do topo da pilha, soma-os e coloca o resultado
 * no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fadd(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  float value_1, value_2;
  memcpy(&value_1, &operand_1->type_float, sizeof(float));
  memcpy(&value_2, &operand_2->type_float, sizeof(float));
  value_1 += value_2;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Float;
  memcpy(&result->type_float, &value_1, sizeof(u4));

  curr_frame->push_operand(result);
}

/**
 * @brief Soma do tipo double Retira os dois operando do topo da pilha, soma-os e coloca o resultado
 * no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dadd(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  double value_1, value_2;
  memcpy(&value_1, &operand_1->type_double, sizeof(float));
  memcpy(&value_2, &operand_2->type_double, sizeof(float));
  value_1 += value_2;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Double;
  memcpy(&result->type_double, &value_1, sizeof(u8));

  curr_frame->push_operand(result);
}
