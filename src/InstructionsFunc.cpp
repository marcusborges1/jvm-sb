/** @file InstructionsFunc.cpp
 *  @brief ...
 *  @bug No know bugs.
 */
#include "InstructionsFunc.h"
#include "Interpreter.h"
#include "CpInfo.h"
/** @cond */
#include <sstream>
#include <cmath>
/** @endcond */

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
void fload(Frame *curr_frame) {
  u1 index = curr_frame->method_code.code[curr_frame->pc++];
  curr_frame->operand_stack.push(curr_frame->local_variables_array[index]);
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
 * @brief Empilha float indicado no indice index do array de variáveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lload(Frame *curr_frame) {
  int index = curr_frame->method_code.code[curr_frame->pc++];
  curr_frame->operand_stack.push(curr_frame->local_variables_array[index]);
  curr_frame->pc++;
}


/**
 * @brief empilha double  indicado no indice 0 do array de variaveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dload_0(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[0]);
  curr_frame->pc++;
}

/**
 * @brief empilha double  indicado no indice 1 do array de variaveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dload_1(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[1]);
  curr_frame->pc++;
}

/**
 * @brief empilha double  indicado no indice 2 do array de variaveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dload_2(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[2]);
  curr_frame->pc++;
}

/**
 * @brief empilha double  indicado no indice 3 do array de variaveis locais na pilha de operandos
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dload_3(Frame *curr_frame) {
  curr_frame->operand_stack.push(curr_frame->local_variables_array[3]);
  curr_frame->pc++;
}

/**
 * @brief Armazena valor double da pilha de operandos no array de variaveis locais no indice index
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dstore(Frame* curr_frame) {
  u1 index = curr_frame->method_code.code[curr_frame->pc++];
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[index] = op;
  curr_frame->pc++;
}

/**
 * @brief Armazena valor double da pilha de operandos no array de variaveis locais no indice 0
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dstore_0(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[0] = op;
  curr_frame->pc++;
}


/**
 * @brief Armazena valor double da pilha de operandos no array de variaveis locais no indice 1
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dstore_1(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[1] = op;
  curr_frame->pc++;
}

/**
 * @brief Armazena valor double da pilha de operandos no array de variaveis locais no indice 2
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dstore_2(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[2] = op;
  curr_frame->pc++;
}

/**
 * @brief Armazena valor double da pilha de operandos no array de variaveis locais no indice 3
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dstore_3(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[3] = op;
  curr_frame->pc++;
}

/**
 * @brief Armazena float do topo da pilha de operandos no array de variaveis locais
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
 void fstore(Frame* curr_frame) {
   u1 index = curr_frame->method_code.code[curr_frame->pc++];
   Operand *op = curr_frame->operand_stack.top();
   curr_frame->operand_stack.pop();

   curr_frame->local_variables_array[index] = op;
   curr_frame->pc++;
 }


 /**
 * @brief Armazena float do topo da pilha de operandos no array de variaveis locais no indice 0
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
 void fstore_0(Frame* curr_frame) {
   Operand *op = curr_frame->operand_stack.top();
   curr_frame->operand_stack.pop();

   curr_frame->local_variables_array[0] = op;
   curr_frame->pc++;
 }

 /**
  * @brief Armazena float do topo da pilha de operandos no array de variaveis locais no indice 1
  * @param Frame *curr_frame Ponteiro para o frame atual
  * @return void
  */
 void fstore_1(Frame* curr_frame) {
   Operand *op = curr_frame->operand_stack.top();
   curr_frame->operand_stack.pop();

   curr_frame->local_variables_array[1] = op;
   curr_frame->pc++;
 }

 /**
  * @brief Armazena float do topo da pilha de operandos no array de variaveis locais no indice 2
  * @param Frame *curr_frame Ponteiro para o frame atual
  * @return void
  */
 void fstore_2(Frame* curr_frame) {
   Operand *op = curr_frame->operand_stack.top();
   curr_frame->operand_stack.pop();

   curr_frame->local_variables_array[2] = op;
   curr_frame->pc++;
 }

 /**
  * @brief Armazena float do topo da pilha de operandos no array de variaveis locais no indice 3
  * @param Frame *curr_frame Ponteiro para o frame atual
  * @return void
  */
 void fstore_3(Frame* curr_frame) {
   Operand *op = curr_frame->operand_stack.top();
   curr_frame->operand_stack.pop();

   curr_frame->local_variables_array[3] = op;
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
 * @brief Soma do tipo double. Retira os dois operando do topo da pilha, soma-os e coloca o resultado
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

/**
 * @brief Subtração do tipo inteiro. Retira os dois operando do topo da pilha, subtraí-os e coloca o
 * resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void isub(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Integer;
  result->type_long = operand_1->type_long - operand_2->type_long;

  curr_frame->push_operand(result);
}

/**
 * @brief Subtração do tipo long. Retira os dois operando do topo da pilha, subtraí-os e coloca o
 * resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lsub(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Long;
  result->type_long = operand_1->type_long - operand_2->type_long;

  curr_frame->push_operand(result);
}

/**
 * @brief Subtração do tipo float. Retira os dois operando do topo da pilha, subtraí-os e coloca o
 * resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fsub(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  float value_1, value_2;
  memcpy(&value_1, &operand_1->type_float, sizeof(float));
  memcpy(&value_2, &operand_2->type_float, sizeof(float));
  value_2 -= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Float;
  memcpy(&result->type_float, &value_2, sizeof(u4));

  curr_frame->push_operand(result);
}


/**
 * @brief Subtração do tipo double. Retira os dois operando do topo da pilha, subtraí-os e coloca o
 * resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dsub(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  double value_1, value_2;
  memcpy(&value_1, &operand_1->type_float, sizeof(double));
  memcpy(&value_2, &operand_2->type_float, sizeof(double));
  value_2 -= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Double;
  memcpy(&result->type_double, &value_2, sizeof(u8));

  curr_frame->push_operand(result);
}

/**
 * @brief Multiplicação de inteiros. Retira os dois operando do topo da pilha, multiplica-os
 * e coloca o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void imul(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Integer;
  result->type_int = (operand_1->type_int) * (operand_2->type_int);

  curr_frame->push_operand(result);
}

/**
 * @brief Multiplicação de long. Retira os dois operando do topo da pilha, multiplica-os
 * e coloca o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lmul(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Long;
  result->type_long = (operand_1->type_long) * (operand_2->type_long);

  curr_frame->push_operand(result);
}

/**
 * @brief Multiplicação de float. Retira os dois operando do topo da pilha, multiplica-os
 * e coloca o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fmul(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  float value_1, value_2;
  memcpy(&value_1, &operand_1->type_float, sizeof(float));
  memcpy(&value_2, &operand_2->type_float, sizeof(float));
  value_2 *= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Float;
  memcpy(&result->type_float, &value_2, sizeof(u4));

  curr_frame->push_operand(result);
}

/**
 * @brief Multiplicação de double. Retira os dois operando do topo da pilha, multiplica-os
 * e coloca o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dmul(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  double value_1, value_2;
  memcpy(&value_1, &operand_1->type_double, sizeof(double));
  memcpy(&value_2, &operand_2->type_double, sizeof(double));
  value_2 *= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Double;
  memcpy(&result->type_double, &value_2, sizeof(u8));

  curr_frame->push_operand(result);
}

/**
 * @brief Divisão de inteiro. Retira os dois operandos do topo da pilha, divide-os
 * e coloca o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void idiv(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Integer;
  result->type_int = (operand_2->type_int) / (operand_1->type_int);

  curr_frame->push_operand(result);
}

/**
 * @brief Divisão de long. Retira os dois operandos do topo da pilha, divide-os
 * e coloca o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ldiv(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Long;
  result->type_long = (operand_2->type_long) / (operand_1->type_long);

  curr_frame->push_operand(result);
}

/**
 * @brief Divisão de float. Retira os dois operandos do topo da pilha, divide-os
 * e coloca o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fdiv(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  float value_1, value_2;
  memcpy(&value_1, &operand_1->type_float, sizeof(float));
  memcpy(&value_2, &operand_2->type_float, sizeof(float));
  value_2 /= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Float;
  memcpy(&result->type_float, &value_2, sizeof(u4));

  curr_frame->push_operand(result);
}

/**
 * @brief Divisão de double. Retira os dois operandos do topo da pilha, divide-os
 * e coloca o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ddiv(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  double value_1, value_2;
  memcpy(&value_1, &operand_1->type_double, sizeof(double));
  memcpy(&value_2, &operand_2->type_double, sizeof(double));
  value_2 /= value_1;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Double;
  memcpy(&result->type_double, &value_2, sizeof(u8));

  curr_frame->push_operand(result);
}

/*
* @brief Armazena long do topo da pilha de operandos no array de variaveis locais no indice index
* @param Frame *curr_frame Ponteiro para o frame atual
* @return void
*/
void lstore(Frame* curr_frame) {
  u1 index = curr_frame->method_code.code[curr_frame->pc++];
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[index] = op;
  curr_frame->pc++;
}

/**
* @brief Armazena float do topo da pilha de operandos no array de variaveis locais no indice 0
* @param Frame *curr_frame Ponteiro para o frame atual
* @return void
*/
void lstore_0(Frame* curr_frame) {
 Operand *op = curr_frame->operand_stack.top();
 curr_frame->operand_stack.pop();

 curr_frame->local_variables_array[0] = op;
 curr_frame->pc++;
}

/**
* @brief Armazena float do topo da pilha de operandos no array de variaveis locais no indice 1
* @param Frame *curr_frame Ponteiro para o frame atual
* @return void
*/
void lstore_1(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[1] = op;
  curr_frame->pc++;
}

/**
* @brief Armazena float do topo da pilha de operandos no array de variaveis locais no indice 2
* @param Frame *curr_frame Ponteiro para o frame atual
* @return void
*/
void lstore_2(Frame* curr_frame) {
 Operand *op = curr_frame->operand_stack.top();
 curr_frame->operand_stack.pop();

 curr_frame->local_variables_array[2] = op;
 curr_frame->pc++;
}

/**
* @brief Armazena float do topo da pilha de operandos no array de variaveis locais no indice 3
* @param Frame *curr_frame Ponteiro para o frame atual
* @return void
*/
void lstore_3(Frame* curr_frame) {
  Operand *op = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();

  curr_frame->local_variables_array[3] = op;
  curr_frame->pc++;
}

/**
 * @brief Calcula o resto da divisão entre dois inteiros. Retira os dois operandos do topo da pilha,
 * calcula o resto da divisão e coloca no topo.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void irem(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u4 divider = operand_1->type_int;
  u4 dividend = operand_2->type_int;

  u4 i_remainder = (u4) dividend - (dividend / divider) * divider;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Integer;
  result->type_int = i_remainder;

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o resto da divisão entre dois long. Retira os dois operandos do topo da pilha,
 * calcula o resto da divisão e coloca no topo.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lrem(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u8 divider = operand_1->type_int;
  u8 dividend = operand_2->type_int;

  u8 l_remainder = dividend - (dividend / divider) * divider;

  Operand *result = (Operand *) malloc(sizeof(Operand));
  result->tag = CONSTANT_Long;
  result->type_int = l_remainder;

  curr_frame->push_operand(result);
}

// <<<<<<< HEAD
// =======
//   curr_frame->push_operand(result);
// }

/**
 * @brief Calcula o resto da divisão entre dois double. Retira os dois operandos do topo da pilha,
 * calcula o resto da divisão e coloca no topo.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void drem(Frame *curr_frame) {
  double dividend, divisor, f_remainder;

  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  memcpy(&divisor, &operand_1->type_double, sizeof(double));
  memcpy(&dividend, &operand_2->type_double, sizeof(double));
  f_remainder = std::fmod(dividend, divisor);

  Operand *result = check_string_create_type("D");
  memcpy(&result->type_double, &f_remainder, sizeof(u8));
  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor negativo de int. Retira o operando do topo da pilha, nega o valor do
 * operando e o salva o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ineg(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand = curr_frame->pop_operand();
  Operand *result = check_string_create_type("I");
  result->type_int = -(u4)operand->type_int;

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor negativo de long. Retira o operando do topo da pilha, nega o valor do
 * operando e o salva o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lneg(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand = curr_frame->pop_operand();
  u8 l_value = operand->type_long;
  u8 l_result = -l_value;

  Operand *result = check_string_create_type("J");
  result->type_long = l_result;

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor negativo de float. Retira o operando do topo da pilha, nega o valor do
 * operando e o salva o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void fneg(Frame *curr_frame) {
  float f_value;

  curr_frame->pc++;

  Operand *operand = curr_frame->pop_operand();
  memcpy(&f_value, &operand->type_float, sizeof(float));
  f_value = -f_value;

  Operand *result = check_string_create_type("F");
  memcpy(&result->type_float, &f_value, sizeof(u4));

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor negativo de double. Retira o operando do topo da pilha, nega o valor do
 * operando e o salva o resultado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void dneg(Frame *curr_frame) {
  double d_value;
  curr_frame->pc++;

  Operand *operand = curr_frame->pop_operand();
  memcpy(&d_value, &operand->type_double, sizeof(double));
  d_value = -d_value;

  Operand *result = check_string_create_type("D");
  memcpy(&result->type_double, &d_value, sizeof(u8));

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor do shift left lógico para inteiro. Retira dois operandos do topo da pilha
 * e faz o shift left do primeiro operando por s posições, onde s são os 5 bits menos significativos
 * do segundo operando. O resultado é colocado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ishl(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u4 i_value_1 = operand_1->type_int;
  u4 i_value_2 = operand_2->type_int;

  i_value_2 &= 0x0000001f;

  u4 i_result = i_value_1 << i_value_2;
  Operand *result = check_string_create_type("I");

  result->type_int = i_result;

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor do shift left lógico para long. Retira dois operandos do topo da pilha
 * e faz o shift left do primeiro operando por s posições, onde s são os 5 bits menos significativos
 * do segundo operando. O resultado é colocado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lshl(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u8 l_value_1 = operand_1->type_long;
  u8 l_value_2 = operand_2->type_long;

  l_value_2 &= 0x0000003f;

  u8 l_result = l_value_1 << l_value_2;

  Operand *result = check_string_create_type("J");

  result->type_long = l_result;

  curr_frame->push_operand(result);
}

/**
 * @brief Calcula o valor do shift right lógico para inteiro. Retira dois operandos do topo da pilha
 * e faz o shift right do primeiro operando por s posições, onde s são os 5 bits menos significativos
 * do segundo operando. O resultado é colocado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void ishr(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u4 l_value_1 = operand_1->type_int;
  u4 l_value_2 = operand_2->type_int;

  u4 l_result = (u4) (l_value_1 / pow(2, l_value_2));

  Operand *result = check_string_create_type("I");
  result->type_int = l_result;

  curr_frame->push_operand(result);
}

/**
 * @brief Salta para outro endereço caso  parametro 1 for maior ou igual ao parametro 2
 * @param Frame *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */

void if_icmpge(Frame *curr_frame){
    Operand *op1 = curr_frame->pop_operand();
    Operand *op2 = curr_frame->pop_operand();

    u4 value_param2 = op1->type_int;
    u4 value_param1 = op2->type_int;

    if(value_param1 >= value_param2){
        u2 jump;

        jump = curr_frame->method_code.code[curr_frame->pc + 1];
        jump = (jump << 8 ) | curr_frame->method_code.code[curr_frame->pc + 2];

        curr_frame->pc += jump;
    }else{
        curr_frame->pc +=3;
    }
}

/**
 * @brief Calcula o valor do shift right lógico para long. Retira dois operandos do topo da pilha
 * e faz o shift right do primeiro operando por s posições, onde s são os 5 bits menos significativos
 * do segundo operando. O resultado é colocado no topo da pilha.
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void lshr(Frame *curr_frame) {
  curr_frame->pc++;

  Operand *operand_1 = curr_frame->pop_operand();
  Operand *operand_2 = curr_frame->pop_operand();

  u8 l_value_1 = operand_1->type_long;
  u8 l_value_2 = operand_2->type_long;
  u8 l_result = (u8) (l_value_1 / pow(2, l_value_2 & 0x3f));

  Operand *result = check_string_create_type("J");
  result->type_long = (u8) l_result;

  curr_frame->push_operand(result);
}

/*
* @brief Armazena um inteiro no array de variaveis locais no valor indicado pelo indice
* @param Frame *curr_frame Ponteiro para o frame atual
* @return void
*/
void istore(Frame *curr_frame) {
   u1 index = curr_frame->method_code.code[curr_frame->pc++];
   Operand *value = curr_frame->pop_operand();
   curr_frame->local_variables_array.at(index) = value;

   curr_frame->pc++;
 }

/**
 * @brief Armazena um inteiro no array de variaveis locais no indice 0
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void istore_0(Frame *curr_frame) {
    Operand *value = curr_frame->pop_operand();
    curr_frame->local_variables_array.at(0) = value;

    curr_frame->pc++;
}

/**
 * @brief Armazena um inteiro no array de variaveis locais no indice 1
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void istore_1(Frame *curr_frame) {
    Operand *value = curr_frame->pop_operand();
    curr_frame->local_variables_array.at(1) = value;

    curr_frame->pc++;
}

/**
 * @brief Armazena um inteiro no array de variaveis locais no indice 2
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void istore_2(Frame *curr_frame) {
    Operand *value = curr_frame->pop_operand();
    curr_frame->local_variables_array.at(2) = value;

    curr_frame->pc++;
}

/**
 * @brief Armazena um inteiro no array de variaveis locais no indice 0
 * @param Frame *curr_frame Ponteiro para o frame atual
 * @return void
 */
void istore_3(Frame *curr_frame) {
    Operand *value = curr_frame->pop_operand();
    curr_frame->local_variables_array.at(3) = value;

    curr_frame->pc++;
}






/** Resgata o valor do topo da pilha (que deve ser int), covnerte para long e salva na pilha de operandos
 * @brief Resgata o valor do topo da pilha (que deve ser int), covnerte para long e salva na pilha de operandos
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */

void i2l(Frame *curr_frame){
    int value_op;
    Operand *op_int = curr_frame->pop_operand();
    memcpy(&value_op, &op_int->type_int, sizeof(int32_t));

    long value_long = (long)value_op;
    Operand *value_converted = check_string_create_type("J");
    memcpy(&value_converted->type_long, &value_long, sizeof(uint64_t));

    curr_frame->pc++;
    curr_frame->push_operand(value_converted);
}




/**
 * @brief Função para saltar para um certo offset.
 * @param Frame *curr_frame ponteiro que para o frame atual
 * @return void
 */
void ins_goto(Frame *curr_frame){
    int16_t offset = curr_frame->method_code.code[curr_frame->pc+1];
    offset = (offset << 8) + curr_frame->method_code.code[curr_frame->pc+2];
    curr_frame->pc +=offset;
}





/**
 * @brief Invoca um método estático de uma classe.
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */

void invokestatic(Frame *curr_frame){
    curr_frame->pc++;

    u2 method_index = curr_frame->method_code.code[curr_frame->pc++];
    method_index = (method_index << 8) + curr_frame->method_code.code[curr_frame->pc++];

    CpInfo &method_info = curr_frame->constant_pool_reference[method_index - 1];

    CpInfo &class_info = curr_frame->constant_pool_reference[method_info.MethodRef.index - 1];
    std::string class_name = class_info.get_utf8_constant_pool(curr_frame->constant_pool_reference, class_info.Class.type_class_info - 1);

    CpInfo &name_and_type = curr_frame->constant_pool_reference[method_info.MethodRef.name_and_type - 1];
    std::string method_name = name_and_type.get_utf8_constant_pool(curr_frame->constant_pool_reference, name_and_type.NameAndType.name_index - 1);
    std::string method_descriptor = name_and_type.get_utf8_constant_pool(curr_frame->constant_pool_reference, name_and_type.NameAndType.descriptor_index - 1);

    if(class_name == "java/lang/Object" && method_name == "registerNatives"){
    //não suporta metodo nativo
        return;
    }else if(class_name.find("java/") != std::string::npos)
    {
        // caso seja algum outro tipo de classe java nao implementada
        printf("Classe Java não implementada.");
        getchar();
        exit(1);
    }
    // calcula quantos argumentos o metodo tem
    int count_arguments = 0;
    uint16_t counter = 1;
    while(method_descriptor[counter] != ')')
    {
        char find_type = method_descriptor[counter];
        if(find_type == 'L')
        { // tipo é um objeto
            count_arguments++;
            while(method_descriptor[++counter] != ';');
        }else if(find_type == '[')
        { // tipo é um array
            count_arguments++;
            while(method_descriptor[++counter] == '[');
            if(method_descriptor[counter] == 'L')
                while(method_descriptor[++counter] != ';');
        }else
        {
            count_arguments++;
        }
        counter++;
    }
    std::vector<Operand*> arguments;

    for (int i = 0; i < count_arguments; ++i) {
        Operand *argument = curr_frame->pop_operand();
        arguments.insert(arguments.begin(), argument);
        if(argument->tag == CONSTANT_Double || argument->tag == CONSTANT_Long){
            arguments.insert(arguments.begin()+1, check_string_create_type("P"));
        }
    }

    ClassInstance *class_instance = get_static_class(class_name);

    MethodInfo *method_finded = find_method(class_instance->info_class, method_name, method_descriptor);
    Frame *new_frame = new Frame(method_finded, class_instance->info_class.constant_pool);

    for (int j = 0; (unsigned)j < arguments.size(); ++j) {
        new_frame->local_variables_array.at(j) = arguments.at(j);
    }

    push_frame(new_frame);
}



















/**
 * @brief Retorna long int de um método.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lreturn(Frame *curr_frame){
    curr_frame->pc++;
    Operand *long_value = curr_frame->pop_operand();
    pop_frame();
    Frame *past_frame = top_frame();
    past_frame->push_operand(long_value);
}









/**
 * @brief Cria novo array podendo ser de qualquer tipo.
 * @param Frame *curr_frame ponteiro que aponta para o frame atual
 * @return void
 */
void new_obj(Frame *curr_frame){
    curr_frame->pc++;
    u2 index = curr_frame->method_code.code[curr_frame->pc];
    index = (index << 8)+curr_frame->method_code.code[++curr_frame->pc];

    CpInfo &class_info = curr_frame->constant_pool_reference[index - 1];
    std::string utf8_constant = class_info.get_utf8_constant_pool(curr_frame->constant_pool_reference, class_info.Class.type_class_info - 1);

    curr_frame->pc++;
    if(utf8_constant == "java/lang/StringBuilder"){
        Operand* string_builder = (Operand*)malloc(sizeof(Operand));
        string_builder->tag = CONSTANT_String;
        string_builder->type_string = new std::string("");
        curr_frame->push_operand(string_builder);
    }else{
        Operand *instance = check_string_create_type("L" + utf8_constant);
        if (instance->c_instance->name_class == NULL){
            std::cout << "Error while loading class: " << utf8_constant<<std::endl;
            exit(5);
        }
        curr_frame->push_operand(instance);
    }
}







/**
 * @brief Faz uma cópia do item que está no topo da pilha e o adiciona ao topo da pilha.
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup(Frame *curr_frame){
    curr_frame->pc++;

    Operand *op = curr_frame->pop_operand();
    Operand *copy_1 = copy_operand(op);
    Operand *copy_2 = copy_operand(op);

    curr_frame->push_operand(copy_1);
    curr_frame->push_operand(copy_2);
}

/**
 * @brief Converte de float para double
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void f2d(Frame *curr_frame) {
    float float_value;
    Operand *float_type = curr_frame->pop_operand();
    memcpy(&float_value, &float_type->type_float, sizeof(u4));

    double double_value = (double)float_value;
    Operand *new_double = check_string_create_type("D");
    memcpy(&new_double->type_double, &double_value, sizeof(u8));

    curr_frame->push_operand(new_double);
    curr_frame->pc++;
}

/**
 * @brief Converte de float para inteiro
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void f2i(Frame *curr_frame) {
    float float_value;
    Operand *float_type = curr_frame->pop_operand();
    memcpy(&float_value, &float_type->type_float, sizeof(u4));

    int int_value = (int)float_value;
    Operand *new_int = check_string_create_type("I");
    memcpy(&new_int->type_int, &int_value, sizeof(u8));

    curr_frame->push_operand(new_int);
    curr_frame->pc++;
}

/**
 * @brief Converte um long para double
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void l2d(Frame *curr_frame) {
    long stack_value;
    Operand *long_type = curr_frame->pop_operand();
    memcpy(&stack_value, &long_type->type_long, sizeof(u8));

    double new_value = (double) stack_value;
    Operand *new_double = check_string_create_type("D");
    memcpy(&new_double->type_double, &new_value, sizeof(u8));

    curr_frame->push_operand(new_double);
    curr_frame->pc++;
}

/**
 * @brief Converte um long para float
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void l2f(Frame *curr_frame) {
    long stack_value;
    Operand *long_type = curr_frame->pop_operand();
    memcpy(&stack_value, &long_type->type_long, sizeof(u8));

    float new_value = (float) stack_value;
    Operand *new_float = check_string_create_type("D");
    memcpy(&new_float->type_float, &new_value, sizeof(u4));

    curr_frame->push_operand(new_float);
    curr_frame->pc++;
}

/**
 * @brief Converte um long para int
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void l2i(Frame *curr_frame) {
    long stack_value;
    Operand *long_type = curr_frame->pop_operand();
    memcpy(&stack_value, &long_type->type_long, sizeof(u8));

    int new_value = (int) stack_value;
    Operand *new_int = check_string_create_type("D");
    memcpy(&new_int->type_int, &new_value, sizeof(u4));

    curr_frame->push_operand(new_int);
    curr_frame->pc++;
}


void iand(Frame *curr_frame) {
    u4 ivalue1, ivalue2, iresult;

    curr_frame->pc++;

    Operand *value1 = curr_frame->pop_operand();
    Operand *value2 = curr_frame->pop_operand();

    ivalue1 = value1->type_int;
    ivalue2 = value2->type_int;

    iresult = ivalue1 & ivalue2;

    Operand *result = check_string_create_type("I");

    result->type_int = (u4)iresult;

    curr_frame->push_operand(result);
}

/**
 * @brief Converte de double para int
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void d2i(Frame *curr_frame) {
    double stack_value;
    Operand *double_type = curr_frame->pop_operand();
	memcpy(&stack_value, &double_type->type_double, sizeof(int64_t));

    int int_value = (int)stack_value;
    Operand *new_int = check_string_create_type("I");
    memcpy(&new_int->type_int, &int_value, sizeof(u4));

    curr_frame->push_operand(new_int);
    curr_frame->pc++;
}

/**
 * @brief Converte de double para long
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void d2l(Frame *curr_frame) {
    double stack_value;
    Operand *double_type = curr_frame->pop_operand();
	memcpy(&stack_value, &double_type->type_double, sizeof(int64_t));

    long long_value = (long)stack_value;
    Operand *new_long = check_string_create_type("J");
    memcpy(&new_long->type_long, &long_value, sizeof(u8));

    curr_frame->push_operand(new_long);
    curr_frame->pc++;
}

/**
 * @brief Converte double para float
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void d2f(Frame *curr_frame) {
    double stack_value;
    Operand *double_type = curr_frame->pop_operand();
	memcpy(&stack_value, &double_type->type_double, sizeof(int64_t));

    float float_value = (float)stack_value;
    Operand *new_float = check_string_create_type("F");
    memcpy(&new_float->type_float, &float_value, sizeof(u4));

    curr_frame->push_operand(new_float);
    curr_frame->pc++;
}


void putfield(Frame *curr_frame){
    curr_frame->pc++;

    uint16_t index = curr_frame->method_code.code[curr_frame->pc++];
    index = (index<<8) + curr_frame->method_code.code[curr_frame->pc++];
    CpInfo field_reference = curr_frame->constant_pool_reference[index - 1];

    CpInfo name_and_type = curr_frame->constant_pool_reference[field_reference.FieldRef.name_and_type_index - 1];

    std::string class_name = name_and_type.get_utf8_constant_pool(curr_frame->constant_pool_reference, field_reference.FieldRef.class_index - 1);
    std::string var_name = name_and_type.get_utf8_constant_pool(curr_frame->constant_pool_reference, name_and_type.NameAndType.name_index - 1);

    Operand *var_operand = curr_frame->pop_operand();
    Operand *class_instance = curr_frame->pop_operand();

    Operand *class_variable = class_instance->c_instance->fields_class->at(var_name);

    switch (var_operand->tag){
        case CONSTANT_Integer:
            class_variable->type_int = var_operand->type_int;
            break;
        case CONSTANT_Long:
            class_variable->type_long = var_operand->type_long;
            break;
        case CONSTANT_Boolean:
            class_variable->type_bool = var_operand->type_bool;
            break;
        case CONSTANT_Char:
            class_variable->type_char = var_operand->type_char;
            break;
        case CONSTANT_Short:
            class_variable->type_short = var_operand->type_short;
            break;
        case CONSTANT_Byte:
            class_variable->type_byte = var_operand->type_byte;
            break;
        case CONSTANT_Float:
            class_variable->type_float = var_operand->type_float;
            break;
        case CONSTANT_Double:
            class_variable->type_double = var_operand->type_double;
            break;
        case CONSTANT_String:
            class_variable->type_string = var_operand->type_string;
            break;
        case CONSTANT_Class:
            class_variable->c_instance = var_operand->c_instance;
            break;
        case CONSTANT_Array:
            class_variable->array_type = var_operand->array_type;
            break;
    }
}

/**
 * @brief Realiza a operacao de OR entre dois operandos e empilha o resultado
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void ior(Frame *curr_frame) {
    int32_t ivalue1, ivalue2, iresult;

    curr_frame->pc++;

    Operand *value1 = curr_frame->pop_operand();
    Operand *value2 = curr_frame->pop_operand();

    ivalue1 = value1->type_int;
    ivalue2 = value2->type_int;

    iresult = ivalue1 | ivalue2;

    Operand* result = check_string_create_type("I");

    result->type_int = (u4)iresult;

    curr_frame->push_operand(result);
}





/** @brief Retira o topo da pilha e armazena na variavel local de posição 2.
@param Frame *curr_frame ponteiro para o frame atual
@return void
*/
void astore_2(Frame *curr_frame){
    curr_frame->pc++;
    Operand *op = curr_frame->pop_operand();
    curr_frame->local_variables_array.at(2) = op;
}

/** @brief Retira o topo da pilha e armazena na variavel local de posição 3.
@param Frame *currentFrame ponteiro para o frame atual
@return void
*/
void astore_3(Frame *curr_frame){
    curr_frame->pc++;
    Operand *op = curr_frame->pop_operand();
    curr_frame->local_variables_array.at(3) = op;
}






/** @brief Dá push de uma word na pilha de operandos.
@param Frame *curr_frame ponteiro que aponta para o frame atual
@return void
*/
void ldc_w(Frame *curr_frame){
    curr_frame->pc++;

    u1 index_1 = curr_frame->method_code.code[curr_frame->pc++];
    u1 index_2 = curr_frame->method_code.code[curr_frame->pc++];

    u2 index = (index_1 << 8) + index_2;

    CpInfo *cp_info = curr_frame->constant_pool_reference + index - 1;
    Operand* operands = nullptr;

    switch(cp_info->tag){
        case CONSTANT_Integer:
            operands = (Operand*)malloc(sizeof(Operand));
            operands->tag = CONSTANT_Integer;
            operands->type_int = cp_info->Integer.bytes;
            break;
        case CONSTANT_Float:
            operands = (Operand*)malloc(sizeof(Operand));
            operands->tag = CONSTANT_Float;
            operands->type_float = cp_info->Float.bytes;
            break;
        case CONSTANT_Class:
            //TODO
            printf("TODO");
            break;
        case CONSTANT_String:{
            operands = (Operand*)malloc(sizeof(Operand));
            operands->tag = CONSTANT_String;
            std::string utf8_cp = cp_info->get_utf8_constant_pool(curr_frame->constant_pool_reference, cp_info->String.bytes-1);
            operands->type_string = new std::string(utf8_cp);
            break;
        }
        default:
            //TODO
            printf("TODO");
            break; //methodRef e methodHandle não implementados
    }

    curr_frame->push_operand(operands);

}

/** @brief Dá push em duas words na pilha de operandos.
@param Frame *curr_frame ponteiro que aponta para o frame atual
@return void
*/
void ldc2_w(Frame *curr_frame){
    curr_frame->pc++;

    u1 index_1 = curr_frame->method_code.code[curr_frame->pc++];
    u1 index_2 = curr_frame->method_code.code[curr_frame->pc++];

    uint16_t index = (index_1 << 8) + index_2;

    CpInfo *cp_info = curr_frame->constant_pool_reference + index - 1;
    Operand* operands;

    if (cp_info->tag == CONSTANT_Double) { // double
        operands = (Operand*)malloc(sizeof(Operand));
        operands->tag = CONSTANT_Double;
        operands->type_double = cp_info->Double.high_bytes;
        operands->type_double = (operands->type_double << 32) + cp_info->Double.low_bytes;
    }
    else {
        operands = (Operand*)malloc(sizeof(Operand));
        operands->tag = CONSTANT_Long;
        operands->type_long = cp_info->Long.high_bytes;
        operands->type_long =(operands->type_long << 32) + cp_info->Long.low_bytes;
    }
    curr_frame->push_operand(operands);
}








/** @brief Invoca a interface do método.
@param Frame *curr_frame ponteiro que aponta para o frame atual
@return void
*/
void invokeinterface(Frame *curr_frame){
    curr_frame->pc++;

    uint16_t method_index = curr_frame->method_code.code[curr_frame->pc++];
    method_index = (method_index << 8) + curr_frame->method_code.code[curr_frame->pc++];

    CpInfo &method_info = curr_frame->constant_pool_reference[method_index - 1];

    CpInfo &class_info = curr_frame->constant_pool_reference[method_info.MethodRef.index - 1];
    std::string class_name = class_info.get_utf8_constant_pool(curr_frame->constant_pool_reference, class_info.Class.type_class_info - 1);

    CpInfo &name_and_type = curr_frame->constant_pool_reference[method_info.MethodRef.name_and_type - 1];
    std::string method_name = class_info.get_utf8_constant_pool(curr_frame->constant_pool_reference, name_and_type.NameAndType.name_index - 1);
    std::string method_descriptor = class_info.get_utf8_constant_pool(curr_frame->constant_pool_reference, name_and_type.NameAndType.descriptor_index - 1);
}









/**
 * @brief Retorna int de um método.
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */

void ireturn(Frame *curr_frame){
    curr_frame->pc++;
    Operand *integer = curr_frame->pop_operand();
    pop_frame();
    Frame *called_frame = top_frame();
    called_frame->push_operand(integer);
}


/**
 * @brief Retorna float de um método.
 * @param Frame *curr_frame ponteiro o frame atual
 * @return void
 */

void freturn(Frame *curr_frame){
    curr_frame->pc++;
    Operand *float_value = curr_frame->pop_operand();
    pop_frame();
    Frame *called_frame = top_frame();
    called_frame->push_operand(float_value);
}

/**
 * @brief Retorna double de um método.
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */

void dreturn(Frame *curr_frame){
    curr_frame->pc++;
    Operand *double_value = curr_frame->pop_operand();
    pop_frame();
    Frame *called_frame = top_frame();
    called_frame->push_operand(double_value);
}

/**
 * @brief Retorna objeto de um método.
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */

void areturn(Frame *curr_frame){
    curr_frame->pc++;
    Operand *object = curr_frame->pop_operand();
    pop_frame();
    Frame *called_frame = top_frame();
    called_frame->push_operand(object);
}

/**
 * @brief Duplica o item no topo da pilha e pusha depois do segundo elemento da pilha.
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup_x1(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *value = curr_frame->pop_operand();
    Operand *value2 = curr_frame->pop_operand();
    if (value->tag == CONSTANT_Double || value->tag == CONSTANT_Long || value2->tag == CONSTANT_Double || value2->tag == CONSTANT_Long) {
        curr_frame->push_operand(value2);
        curr_frame->push_operand(value);
    } else {
        Operand *tipo = copy_operand(value);
        curr_frame->push_operand(tipo);
        curr_frame->push_operand(value2);
        curr_frame->push_operand(value);
    }
}

/**
 * @brief Duplica o item no topo da pilha e pusha depois do terceiro elemento da pilha
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup_x2(Frame *curr_frame) {
    curr_frame->pc++;
    Operand* value = curr_frame->pop_operand();
    Operand* value2 = curr_frame->pop_operand();

    if (value->tag != CONSTANT_Double && value->tag != CONSTANT_Long) {
        if (value2->tag == CONSTANT_Double || value2->tag == CONSTANT_Long) {
            Operand* tipo = copy_operand(value);
            curr_frame->push_operand(tipo);
            curr_frame->push_operand(value2);
            curr_frame->push_operand(value);

        }
        else {
            Operand* value3 = curr_frame->pop_operand();
            if (value3->tag != CONSTANT_Double && value3->tag != CONSTANT_Long) {
                Operand* tipo = copy_operand(value);
                curr_frame->push_operand(tipo);
                curr_frame->push_operand(value3);
                curr_frame->push_operand(value2);
                curr_frame->push_operand(value);
            }
        }
    }
}

/**
 * @brief Faz uma cópia de dois itens que estao no topo da pilha e o(s) adiciona ao topo da pilha.
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup2(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *value1 = curr_frame->pop_operand();
    if (value1->tag != CONSTANT_Double && value1->tag != CONSTANT_Long) {
        Operand *value2 = curr_frame->pop_operand();

        Operand *tipo1 = copy_operand(value1);
        Operand *tipo2 = copy_operand(value2);

        curr_frame->push_operand(tipo2);
        curr_frame->push_operand(tipo1);

        curr_frame->push_operand(value2);
        curr_frame->push_operand(value1);

    } else {
        Operand *tipo = copy_operand(value1);
        curr_frame->push_operand(tipo);
        curr_frame->push_operand(value1);
    }
}

/**
 * @brief Duplica um ou dois valores da pilha de operandos e insere os valores duplicados na ordem original
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup2_x1(Frame *curr_frame) {
    curr_frame->pc++;
    Operand *value1 = curr_frame->pop_operand();
    Operand *value2 = curr_frame->pop_operand();

    if (value1->tag != CONSTANT_Double && value1->tag != CONSTANT_Long) {
        Operand* value3 = curr_frame->pop_operand();

        Operand *tipo1 = copy_operand(value1);
        Operand *tipo2 = copy_operand(value2);

        curr_frame->push_operand(tipo2);
        curr_frame->push_operand(tipo1);

        curr_frame->push_operand(value3);

        curr_frame->push_operand(value2);
        curr_frame->push_operand(value1);
    } else {
        Operand* tipo1 = copy_operand(value1);

        curr_frame->push_operand(tipo1);
        curr_frame->push_operand(value2);
        curr_frame->push_operand(value1);
    }
}

/**
 * @brief Duplica um ou dois operandos da pilha e insere os valores duplicados na ordem original
 * @param Frame *curr_frame ponteiro para o frame atual
 * @return void
 */
void dup2_x2(Frame *curr_frame) {
    curr_frame->pc++;
    Operand* value1 = curr_frame->pop_operand();
    Operand* value2 = curr_frame->pop_operand();

    Operand* tipo1 = copy_operand(value1);
    if (value1->tag != CONSTANT_Double && value1->tag != CONSTANT_Long && value2->tag != CONSTANT_Double && value2->tag != CONSTANT_Long) {
        Operand* value3 = curr_frame->pop_operand();

        Operand* tipo2 = copy_operand(value2);

        if (value3->tag != CONSTANT_Double && value3->tag != CONSTANT_Long) {
            Operand* value4 = curr_frame->pop_operand();


            curr_frame->push_operand(tipo2);
            curr_frame->push_operand(tipo1);

            curr_frame->push_operand(value4);
            curr_frame->push_operand(value3);

            curr_frame->push_operand(value2);
            curr_frame->push_operand(value1);
        } else {
            curr_frame->push_operand(tipo2);
            curr_frame->push_operand(tipo1);

            curr_frame->push_operand(value3);
            curr_frame->push_operand(value2);
            curr_frame->push_operand(value1);
        }
    }
    else {
        if (value2->tag == CONSTANT_Double || value2->tag == CONSTANT_Long) {
            curr_frame->push_operand(tipo1);
            curr_frame->push_operand(value2);
            curr_frame->push_operand(value1);
        }
        else {
            Operand* value3 = curr_frame->pop_operand();

            curr_frame->push_operand(tipo1);
            curr_frame->push_operand(value3);
            curr_frame->push_operand(value2);
            curr_frame->push_operand(value1);
        }

    }

}
