#include <string.h>

#include "AttributeReader.h"



//Função para ler o .class e armazenar a leitura de atributos na struct JavaClass
void read_attributes(FILE *arquivo_class, JavaClass *class_struct)
{
	int contador_atributos;

	//lendo quantos atributos tem no .class
	class_struct->attributes_count = read_2_bytes(arquivo_class);
	//alocando espaço para cada tipo de atributo
	class_struct->attributes = (AttributeInfo *) malloc (class_struct->attributes_count * sizeof(AttributeInfo));

	//preenchendo a struct com os atributos do .class
	for (contador_atributos = 0; contador_atributos < class_struct->attributes_count; contador_atributos++)
	{
		attribute_types_info(arquivo_class, class_struct, class_struct->attributes + contador_atributos);
	}
}


////class file 45.3
void attribute_types_info(FILE *arquivo_class, JavaClass *class_struct, AttributeInfo *attribute_struct)
{
	char *attribute_type;
	int i;

	attribute_struct->attribute_name_index = read_2_bytes(arquivo_class);
	attribute_struct->attribute_length = read_4_bytes(arquivo_class);

	attribute_type = get_utf8_from_cp(class_struct->contant_pool, attribute_struct->attribute_name_index - 1);


	if (strcmp (attribute_type, "Code") == 0)
	{
		attribute_type_code(arquivo_class, class_struct, attribute_struct);
	}
	else if (strcmp (attribute_type, "ConstantValue") == 0)
	{
		attribute_struct->constant_value = (attribute_constant_value*)malloc(sizeof(attribute_constant_value));
		attribute_struct->constant_value->value_index = read_2_bytes(arquivo_class);
	}
	else if (strcmp (attribute_type, "Exceptions") == 0)
	{
		attribute_type_exception(arquivo_class, attribute_struct);
	}
	else if (strcmp (attribute_type, "InnerClasses") == 0)
	{
		attribute_type_inner_classes(arquivo_class, attribute_struct);
	}
	else if (strcmp (attribute_type, "Synthetic") == 0)
	{
		//não fazer nada
	}
	else if (strcmp (attribute_type, "SourceFile") == 0)
	{
		attribute_struct->source_file = (attribute_source_file*)malloc(sizeof(attribute_source_file));
		attribute_struct->source_file->source_file_index = read_2_bytes(arquivo_class);
	}
	else if (strcmp (attribute_type, "LineNumberTable") == 0)
	{
		attribute_type_line_number_table(arquivo_class, attribute_struct);
	}
	else if (strcmp (attribute_type, "LocalVariableTable") == 0)
	{
		attribute_type_local_variable(arquivo_class, attribute_struct);

	}
	else
	{
		////ignora silenciosamente os outros atributos
		attribute_struct->info = (u1*)malloc(attribute_struct->attribute_length * sizeof(u1));

		for (i = 0; i < attribute_struct->attribute_length; i++)
		{
			attribute_struct->info[i] = read_1_byte(arquivo_class);
		}
	}
	
}


//////le o atributo LOCAL VARIABLE
void attribute_type_local_variable(FILE *arquivo_class, AttributeInfo *attribute_struct)
{
	int i;

	attribute_struct->local_variable_table = (attribute_local_variable_table*)malloc(sizeof(attribute_local_variable_table));
	attribute_struct->local_variable_table->local_variable_table_length = read_2_bytes(arquivo_class);

	attribute_struct->local_variable_table->table_data = (attribute_local_variable_table_data*)malloc(attribute_struct->local_variable_table->local_variable_table_length * sizeof(attribute_local_variable_table_data));

	for (i = 0; i < attribute_struct->local_variable_table->local_variable_table_length; i++)
	{
		attribute_local_variable_table_data *info_local_variable = &attribute_struct->local_variable_table->table_data[i];
		info_local_variable->start_pc = read_2_bytes(arquivo_class);
		info_local_variable->length = read_2_bytes(arquivo_class);
		info_local_variable->name_index = read_2_bytes(arquivo_class);
		info_local_variable->descriptor_index = read_2_bytes(arquivo_class);
		info_local_variable->index = read_2_bytes(arquivo_class);
	}
}


//////le o atributo LINE NUMBER
void attribute_type_line_number_table(FILE *arquivo_class, AttributeInfo *attribute_struct)
{
	int i;

	attribute_struct->line_number_table = (attribute_line_number_table*)malloc(sizeof(attribute_line_number_table));
	attribute_struct->line_number_table->line_number_table_length = read_2_bytes(arquivo_class);

	attribute_struct->line_number_table->table = (attribute_line_number_table_data*)malloc(sizeof(attribute_line_number_table_data));

	for (i = 0; i < attribute_struct->line_number_table->line_number_table_length; i++)
	{
		attribute_line_number_table_data *info_line_number = &attribute_struct->line_number_table->table[i];
		info_line_number->start_pc = read_2_bytes(arquivo_class);
		info_line_number->line_pc = read_2_bytes(arquivo_class);	
	}
}



//////le o atributo INNER CLASSES
void attribute_type_inner_classes(FILE *arquivo_class, AttributeInfo *attribute_struct)
{
	int i;

	attribute_struct->inner_class = (attribute_inner_class*)malloc(sizeof(attribute_inner_class));
	attribute_struct->inner_class->number_of_classes = read_2_bytes(arquivo_class);

	attribute_struct->inner_class->inner_class_data = (inner_class_data*)malloc(attribute_struct->inner_class->number_of_classes * sizeof(inner_class_data));

	for (i = 0; i < attribute_struct->inner_class->number_of_classes; i++)
	{
		inner_class_data *info_inner_class = &attribute_struct->inner_class->inner_class_data[i];
		info_inner_class->inner_class_info_index = read_2_bytes(arquivo_class);
		info_inner_class->outer_class_info_index = read_2_bytes(arquivo_class);
		info_inner_class->inner_name_index = read_2_bytes(arquivo_class);
		info_inner_class->inner_class_access_flag = read_2_bytes(arquivo_class);
	}
}



//////le o atributo CONSTANT VALUE
void attribute_type_exception(FILE *arquivo_class, AttributeInfo *attribute_struct)
{
	int i;

	attribute_struct->exception = (attribute_exception*)malloc(sizeof(attribute_exception));

	attribute_struct->exception->number_exceptions = read_2_bytes(arquivo_class);
	attribute_struct->exception->exception_index_table = (u2*)malloc(attribute_struct->exception->number_exceptions * sizeof(u2));

	for (i = 0; i < attribute_struct->exception->number_exceptions; i++)
	{
		attribute_struct->exception->exception_index_table[i] = read_2_bytes(arquivo_class);
	}
}


///Le os atributos do tipo CODE
void attribute_type_code(FILE *arquivo_class, JavaClass *class_struct, AttributeInfo *attribute_struct)
{
	int i, j, k;

	attribute_struct->code = (attribute_code *) malloc (sizeof(attribute_code));
	attribute_struct->code->max_stack = read_2_bytes(arquivo_class);
	attribute_struct->code->max_locals = read_2_bytes(arquivo_class);
	attribute_struct->code->code_length = read_4_bytes(arquivo_class);

	attribute_struct->code->code = (u1*)malloc(attribute_struct->code->code_length * sizeof(u1));

	for (i = 0; i < attribute_struct->code->code_length; i++)
	{
		attribute_struct->code->code[i] = read_1_byte(arquivo_class);
	}

	attribute_struct->code->exceptions_table_length = read_2_bytes(arquivo_class);
	attribute_struct->code->exceptions = (attribute_code_exception*)malloc(attribute_struct->code->exceptions_table_length * sizeof(attribute_code_exception));

	for (j = 0; j < attribute_struct->code->exceptions_table_length; j++)
	{
		attribute_code_exception *p_code_exception = &attribute_struct->code->exceptions[j];
		p_code_exception->start_pc = read_2_bytes(arquivo_class);
		p_code_exception->end_pc = read_2_bytes(arquivo_class);
		p_code_exception->handler_pc = read_2_bytes(arquivo_class);
		p_code_exception->catch_type = read_2_bytes(arquivo_class);
	}

	attribute_struct->code->attribute_count = read_2_bytes(arquivo_class);
	attribute_struct->code->attributes = (AttributeInfo*)malloc(attribute_struct->code->attribute_count * sizeof(AttributeInfo));

	for (k = 0; k < attribute_struct->code->attribute_count; k++)
	{
		AttributeInfo *attribute_info_code = &attribute_struct->code->attributes[k];
		attribute_types_info(arquivo_class, class_struct, attribute_info_code);
	}
}




char* get_utf8_from_cp(CpInfo *cp, u2 info_index)
{
	char *string;
	int tamanho_string;
	int tag = cp[info_index].tag;

	switch(tag)
	{
		case CONSTANT_Utf8:
			tamanho_string = strlen((char*)cp[info_index].UTF8.bytes);
			string = (char *) malloc(tamanho_string * sizeof(char));
			strcpy (string, ((char*)cp[info_index].UTF8.bytes));
			break;
		case CONSTANT_Class:
			string = get_utf8_from_cp(cp, (cp[info_index].Class.type_class_info)-1);
			break;
		case CONSTANT_Fieldref:
			string = get_utf8_from_cp(cp, (cp[info_index].FieldRef.class_index)-1);
			strcat(string, (get_utf8_from_cp(cp, (cp[info_index].FieldRef.name_and_type_index)-1)));
			break;
		case CONSTANT_NameAndType:
			string = get_utf8_from_cp(cp, (cp[info_index].NameAndType.name_index)-1);
			strcat(string, (get_utf8_from_cp(cp, (cp[info_index].NameAndType.descriptor_index)-1)));
			break;
		case CONSTANT_Methodref:
			string = get_utf8_from_cp(cp, (cp[info_index].MethodRef.index)-1);
			strcat(string, (get_utf8_from_cp(cp, (cp[info_index].MethodRef.name_and_type)-1)));
			break;
		case CONSTANT_InterfaceMethodref:
			string = get_utf8_from_cp(cp, (cp[info_index].InterfaceMethodRef.index)-1);
			strcat(string, (get_utf8_from_cp(cp, (cp[info_index].InterfaceMethodRef.name_and_type)-1)));
			break;
		///////TODO: talvez seja necessário fazer esse parametro...verificar
		// case CONSTANT_MethodHandle:
		case CONSTANT_String:
			string = get_utf8_from_cp(cp, (cp[info_index].String.bytes)-1);
			break;
		///////TODO: talvez seja necessário fazer esse parametro...verificar
		// case CONSTANT_MethodType:
		///////TODO: talvez seja necessário fazer esse parametro...verificar
		// case CONSTANT_InvokeDynamic:
	}

	return string;
}

