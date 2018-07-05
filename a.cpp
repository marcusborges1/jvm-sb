//Faltam 4 instruções no final

//
// Created by vitor on 04/11/2017.
//

#include <cmath>
#include "../include/VetorInstrucoes.h"
#include "../include/Interpreter.h"
#include "../include/ClassStructure.h"
#include "../include/Frame.h"

void insertMultiArray(std::stack<int> counter, std::string className, Types *aux);

/** @brief Atualiza o ponteiro de instrução
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void nop(Frame *currentFrame){
    currentFrame->currentPc++;
}

/** @brief Dá push na referência do object null para a pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void aconst_null(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* type = (Types*)malloc(sizeof(Types));
    type->tag = CONSTANT_NULL;
    currentFrame->pushOperand(type);
}

/** @brief Dá push em um inteiro de valor -1 dentro da pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iconst_m1(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *inteiro = criaTipoAPartirString("I");
    inteiro->tpInt = -1;
    currentFrame->pushOperand(inteiro);
}

/** @brief Dá push em uma constante inteira de valor 0 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iconst_0(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Integer;
    types->tpInt = 0;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante inteira de valor 1 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iconst_1(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Integer;
    types->tpInt = 1;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante inteira de valor 2 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iconst_2(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Integer;
    types->tpInt = 2;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante inteira de valor 3 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iconst_3(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Integer;
    types->tpInt = 3;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante inteira de valor 4 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iconst_4(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Integer;
    types->tpInt = 4;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante inteira de valor 5 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iconst_5(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Integer;
    types->tpInt = 5;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante long int de valor 0 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lconst_0(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Long;
    types->tpLong = 0;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante long int de valor 1 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lconst_1(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Long;
    types->tpLong = 1;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante de precisão simples de valor 0.0 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fconst_0(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Float;

    float value = 0.0;
    uint32_t floatValue;
    memcpy(&floatValue, &value, sizeof(uint32_t));
    types->tpFloat = floatValue;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante de precisão simples de valor 1.0 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fconst_1(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Float;

    float value = 1.0;
    uint32_t floatValue;
    memcpy(&floatValue, &value, sizeof(uint32_t));
    types->tpFloat = floatValue;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante de precisão simples de valor 2.0 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fconst_2(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Float;

    float value = 2.0;
    uint32_t floatValue;
    memcpy(&floatValue, &value, sizeof(uint32_t));
    types->tpFloat = floatValue;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante de precisão dupla de valor 0.0 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dconst_0(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Double;

    double value = 0.0;
    uint64_t doubleValue;
    memcpy(&doubleValue, &value, sizeof(uint64_t));
    memcpy(&doubleValue, &value, sizeof(uint64_t));
    types->tpDouble = doubleValue;
    currentFrame->pushOperand(types);
}

/** @brief Dá push em uma constante de precisão dupla de valor 1.0 dentro da pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dconst_1(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* types = (Types*)malloc(sizeof(Types));
    types->tag = CONSTANT_Double;

    double value = 1.0;
    uint64_t doubleValue;
    memcpy(&doubleValue, &value, sizeof(uint64_t));
    types->tpDouble = doubleValue;
    currentFrame->pushOperand(types);
}

//Continua

/** @brief Extende um número de 8 bits com sinal para um de 32 e coloca na pilha. O sinal também é extendido.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void bipush(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t byte = currentFrame->code[currentFrame->currentPc++];

    Types* type = (Types*)malloc(sizeof(Types));
    type->tag = CONSTANT_Integer;
    type->tpInt =(int8_t) byte;

    currentFrame->pushOperand(type);
}

/** @brief Extende um número de 16 bits com sinal para um de 32 e coloca na pilha. O sinal também é extendido.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/

void sipush(Frame *currentFrame){
    currentFrame->currentPc++;
    uint8_t byte1 = currentFrame->code[currentFrame->currentPc++];
    uint8_t byte2 = currentFrame->code[currentFrame->currentPc++];

    uint16_t result;

    result = (byte1 << 8) + byte2;

    Types *type = criaTipoAPartirString("I");
    type->tpInt = (int16_t)result;

    currentFrame->pushOperand(type);

}

/** @brief Dá push em uma constante do tamanho de uma word na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/

void ldc(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t index = currentFrame->code[currentFrame->currentPc];

    CpInfo &constantPoolItem = currentFrame->constantPool[index-1];
    Types *type = (Types*)malloc(sizeof(Types));
    type->tag = constantPoolItem.tag;
    switch(type->tag){
        case CONSTANT_Integer:
            type->tpInt = constantPoolItem.Integer.intBytes;
            break;
        case CONSTANT_Float:
            type->tpFloat = constantPoolItem.Float.floatBytes;
            break;
        case CONSTANT_String: {
            std::string basic_string = getUTF8StringFromConstantPool(currentFrame->constantPool, constantPoolItem.String.stringBytes-1);
            type->tpString = new std::string(basic_string);
        }   break;
        case CONSTANT_Class:
            break;
        default:
            // Constant_Method_Handle
            // Constant_Method_Ref
            break;
    }
    currentFrame->pushOperand(type);
    currentFrame->currentPc++;
}

/** @brief Dá push em uma constante do tamanho de uma word na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/

void ldc_w(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t index1 = currentFrame->code[currentFrame->currentPc++];
    uint8_t index2 = currentFrame->code[currentFrame->currentPc++];

    uint16_t index = (index1 << 8) + index2;

    CpInfo *cpInfo = currentFrame->constantPool + index - 1;
    Types* types;

    switch(cpInfo->tag){
        case CONSTANT_Integer:
            types = (Types*)malloc(sizeof(Types));
            types->tag = CONSTANT_Integer;
            types->tpInt = cpInfo->Integer.intBytes;
            break;
        case CONSTANT_Float:
            types = (Types*)malloc(sizeof(Types));
            types->tag = CONSTANT_Float;
            types->tpFloat = cpInfo->Float.floatBytes;
            break;
        case CONSTANT_Class:
            //TODO
            break;
        case CONSTANT_String:{
            types = (Types*)malloc(sizeof(Types));
            types->tag = CONSTANT_String;
            std::string string = getUTF8StringFromConstantPool(currentFrame->constantPool, cpInfo->String.stringBytes-1);
            types->tpString = new std::string(string);
            break;
        }
        default:
            //TODO
            break; //methodRef e methodHandle não implementados
    }

    currentFrame->pushOperand(types);

}

/** @brief Dá push em uma constante do tamanho de duas words na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void ldc2_w(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t index1 = currentFrame->code[currentFrame->currentPc++];
    uint8_t index2 = currentFrame->code[currentFrame->currentPc++];

    uint16_t index = (index1 << 8) + index2;

    CpInfo *cpInfo = currentFrame->constantPool + index - 1;
    Types* types;

    if (cpInfo->tag == CONSTANT_Double) { // double
        types = (Types*)malloc(sizeof(Types));
        types->tag = CONSTANT_Double;
        types->tpDouble = cpInfo->Double.doubleHighBytes;
        types->tpDouble = (types->tpDouble << 32) + cpInfo->Double.doubleLowBytes;
    }
    else {
        types = (Types*)malloc(sizeof(Types));
        types->tag = CONSTANT_Long;
        types->tpLong = cpInfo->Long.longHighBytes;
        types->tpLong =(types->tpLong << 32) + cpInfo->Long.longLowBytes;
    }
    currentFrame->pushOperand(types);
}


/** @brief Dá push em um valor de inteiro de uma variável local para a pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iload(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t index = currentFrame->code[currentFrame->currentPc++];
    currentFrame->pushOperand(currentFrame->localVariables.at(index));
}

/** @brief Dá push em um valor de long int de uma variável local para a pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lload(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t index = currentFrame->code[currentFrame->currentPc++];
    currentFrame->pushOperand(currentFrame->localVariables.at(index));
}

/** @brief Dá push em um valor de precisão simples de uma variável local para a pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fload(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t index = currentFrame->code[currentFrame->currentPc++];
    currentFrame->pushOperand(currentFrame->localVariables.at(index));
}

/** @brief Dá push em um valor de preciso dupla de uma variável local para a pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dload(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t index = currentFrame->code[currentFrame->currentPc++];
    currentFrame->pushOperand(currentFrame->localVariables.at(index));
}

/** @brief Recupera a referência de um object de uma variável local para a pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void aload(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t index = currentFrame->code[currentFrame->currentPc++];
    currentFrame->pushOperand(currentFrame->localVariables.at(index));
}

/** @brief Recupera um valor de precisão simples da variável local 0 e insere-a na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iload_0(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* value = copyType(currentFrame->localVariables.at(0));
    currentFrame->pushOperand(value);
}

/** @brief Recupera um valor de precisão simples da variável local 1 e insere-a na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iload_1(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* value = copyType(currentFrame->localVariables.at(1));
    currentFrame->pushOperand(value);
}

/** @brief Recupera um valor de precisão simples da variável local 2 e insere-a na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iload_2(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* value = copyType(currentFrame->localVariables.at(2));
    currentFrame->pushOperand(value);
}

/** @brief Recupera um valor de precisão simples da variável local 3 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iload_3(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* value = copyType(currentFrame->localVariables.at(3));
    currentFrame->pushOperand(value);
}

/** @brief Recupera o valor de um long int do tamanho de duas words salvo nas variáveis locais 0 e 1 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lload_0(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(0));
}

/** @brief Recupera o valor de um long int do tamanho de duas words salvo nas variáveis locais 1 e 2 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lload_1(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(1));
}

/** @brief Recupera o valor de um long int do tamanho de duas words salvo nas variáveis locais 2 e 3 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lload_2(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(2));
}

/** @brief Recupera o valor de um long int do tamanho de duas words salvo nas variáveis locais 3 e 4 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lload_3(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(3));
}

/** @brief Recupera o valor de um float de precisão simples do tamanho de uma word salvo na variável local 0 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fload_0(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(0));
}

/** @brief Recupera o valor de um float de precisão simples do tamanho de uma word salvo na variável local 1 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fload_1(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(1));
}

/** @brief Recupera o valor de um float de precisão simples do tamanho de uma word salvo na variável local 2 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fload_2(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(2));
}

/** @brief Recupera o valor de um float de precisão simples do tamanho de uma word salvo na variável local 3 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fload_3(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(3));
}

/** @brief Recupera o valor de um float de precisão dupla do tamanho de duas words salvo nas variáveis locais 0 e 1 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dload_0(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(0));
}

/** @brief Recupera o valor de um float de precisão dupla do tamanho de duas words salvo nas variáveis locais 1 e 2 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dload_1(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(1));
}

/** @brief Recupera o valor de um float de precisão dupla do tamanho de duas words salvo nas variáveis locais 2 e 3 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dload_2(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(2));
}

/** @brief Recupera o valor de um float de precisão dupla do tamanho de duas words salvo nas variáveis locais 3 e 4 e insere-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dload_3(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(3));
}

/** @brief Recupera a referência a um object armazenado na variável local 0 e armazena-a na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void aload_0(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(0));
}

/** @brief Recupera a referência a um object armazenado na variável local 1 e armazena-a na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void aload_1(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(1));
}

/** @brief Recupera a referência a um object armazenado na variável local 2 e armazena-a na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void aload_2(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(2));
}

/** @brief Recupera a referência a um object armazenado na variável local 3 e armazena-a na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void aload_3(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->pushOperand(currentFrame->localVariables.at(3));
}

/** @brief Recupera uma entrada de um array de inteiros e coloca-a na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iaload(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* index = currentFrame->popOperand();
    Types* array = currentFrame->popOperand();
    Types* integerLoadedFromArray = array->arrayType->array->at(index->tpInt);
    currentFrame->pushOperand(integerLoadedFromArray);
}

/** @brief Recupera um long int de um array de long int e coloca-o na pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void laload(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* index = currentFrame->popOperand();
    Types* array = currentFrame->popOperand();
    currentFrame->pushOperand(array->arrayType->array->at(index->tpInt));
}

/** @brief Retorna uma entrada de um array de floats e coloca-a na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void faload(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* index = currentFrame->popOperand();
    Types* array = currentFrame->popOperand();
    currentFrame->pushOperand(array->arrayType->array->at(index->tpInt));
}

/** @brief Retorna uma entrada de um array de doubles e coloca-a na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void daload(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* index = currentFrame->popOperand();
    Types* array = currentFrame->popOperand();

    currentFrame->pushOperand(array->arrayType->array->at(index->tpInt));
}

/** @brief Recupera uma referência de um object de um array de objects e coloca-a na pilha.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void aaload(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* index = currentFrame->popOperand();
    Types* array = currentFrame->popOperand();

    Types *arrayCarregado = array->arrayType->array->at(index->tpInt);
    currentFrame->pushOperand(arrayCarregado);
}


/** @brief Retorna um byte de um array de bytes, expande-o para um inteiro e coloca-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void baload(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* index = currentFrame->popOperand();
    Types* array = currentFrame->popOperand();
    currentFrame->pushOperand(array->arrayType->array->at(index->tpInt));
}

/** @brief Retorna um caracter de um array de caracteres e coloca-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void caload(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* index = currentFrame->popOperand();
    Types* array = currentFrame->popOperand();
    currentFrame->pushOperand(array->arrayType->array->at(index->tpInt));
}

/** @brief Retorna um short de um array de shorts e coloca-o na pilha de operandos.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void saload(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* index = currentFrame->popOperand();
    Types* array = currentFrame->popOperand();

    currentFrame->pushOperand(array->arrayType->array->at(index->tpInt));
}

/** @brief Dá um pop no int do tamanho de uma word no topo da pilha e o armazena em uma variável local.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void istore(Frame *currentFrame){
    currentFrame->currentPc++;
    uint8_t index = currentFrame->code[currentFrame->currentPc++];

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(index) = value;
}

/** @brief Dá um pop no long int do tamanho de duas words no topo da pilha e o armazena em uma variável local.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lstore(Frame *currentFrame){
    currentFrame->currentPc++;
    uint8_t index = currentFrame->code[currentFrame->currentPc++];

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(index) = value;
}

/** @brief Dá um pop no float de precisão simples no topo da pilha e o armazena em uma variável local.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fstore(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t index = currentFrame->code[currentFrame->currentPc++];

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(index) = value;
}

/** @brief Dá um pop no float de precisão dupla do tamanho de duas words no topo da pilha e o armazena em uma variável local.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dstore(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t index = currentFrame->code[currentFrame->currentPc++];
    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(index) = value;
}

/** @brief Dá um pop no objectref, ou seja, na referência ao object ou ao array, que está no topo da pilha e o armazena em uma variável local.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void astore(Frame *currentFrame){
    currentFrame->currentPc++;

    uint8_t index = currentFrame->code[currentFrame->currentPc++];

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(index) = value;
}

/** @brief Dá um pop no int do tamanho de uma word no topo da pilha e o armazena na variável local 0.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void istore_0(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(0) = value;
}

/** @brief Dá um pop no int do tamanho de uma word no topo da pilha e o armazena ma variável local 1.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void istore_1(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(1) = value;
}

/** @brief Dá um pop no int do tamanho de uma word no topo da pilha e o armazena ma variável local 2.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void istore_2(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(2) = value;
}

/** @brief Dá um pop no int do tamanho de uma word no topo da pilha e o armazena ma variável local 4.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void istore_3(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(3) = value;
}

/** @brief Dá um pop no long int do tamanho de duas words no topo da pilha e o armazena nas variáveis locais 0 e 1.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lstore_0(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(0) = value;
}

/** @brief Dá um pop no long int do tamanho de duas words no topo da pilha e o armazena nas variáveis locais 1 e 2.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lstore_1(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(1) = value;
}

/** @brief Dá um pop no long int do tamanho de duas words no topo da pilha e o armazena nas variáveis locais 2 e 3.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lstore_2(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(2) = value;
}

/** @brief Dá um pop no long int do tamanho de duas words no topo da pilha e o armazena nas variáveis locais 3 e 4.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lstore_3(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(3) = value;
}

/** @brief Dá um pop no float de precisão simples no topo da pilha e o armazena na variável local 0.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fstore_0(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(0) = value;
}

/** @brief Dá um pop no float de precisão simples no topo da pilha e o armazena na variável local 1.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fstore_1(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(1) = value;
}

/** @brief Dá um pop no float de precisão simples no topo da pilha e o armazena na variável local 2.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fstore_2(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(2) = value;
}

/** @brief Dá um pop no float de precisão simples no topo da pilha e o armazena na variável local 3.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fstore_3(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(3) = value;
}

/** @brief Dá um pop no float de precisão dupla do tamanho de duas words no topo da pilha e o armazena nas variáveis locais 0 e 1.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dstore_0(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(0) = value;
}

/** @brief Dá um pop no float de precisão dupla do tamanho de duas words no topo da pilha e o armazena nas variáveis locais 1 e 2.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dstore_1(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(1) = value;
}

/** @brief Dá um pop no float de precisão dupla do tamanho de duas words no topo da pilha e o armazena nas variáveis locais 2 e 3.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dstore_2(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(2) = value;
}

/** @brief Dá um pop no float de precisão dupla do tamanho de duas words no topo da pilha e o armazena nas variáveis locais 3 e 4.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dstore_3(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    currentFrame->localVariables.at(3) = value;
}

/** @brief Dá um pop no objectref, ou seja, na referência ao object ou ao array, que está no topo da pilha e o armazena na variável local 0.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void astore_0(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *operando = currentFrame->popOperand();
    currentFrame->localVariables.at(0) = operando;
}

/** @brief Dá um pop no objectref, ou seja, na referência ao object ou ao array, que está no topo da pilha e o armazena na variável local 1.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void astore_1(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *operando = currentFrame->popOperand();
    currentFrame->localVariables.at(1) = operando;
}

/** @brief Dá um pop no objectref, ou seja, na referência ao object ou ao array, que está no topo da pilha e o armazena na variável local 2.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void astore_2(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *operando = currentFrame->popOperand();
    currentFrame->localVariables.at(2) = operando;
}

/** @brief Dá um pop no objectref, ou seja, na referência ao object ou ao array, que está no topo da pilha e o armazena na variável local 3.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void astore_3(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *operando = currentFrame->popOperand();
    currentFrame->localVariables.at(3) = operando;
}

/** @brief Pega um int da pilha de operandos e armazena-o em um array de inteiros.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void iastore(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    Types* index = currentFrame->popOperand();

    Types *array = currentFrame->popOperand();

    Types *elementoDoArray = array->arrayType->array->at(index->tpInt);
    elementoDoArray->tpInt = value->tpInt;
}

/** @brief Pega um long int da pilha de operandos e armazena-o em um array de long ints.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void lastore(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    Types* index = currentFrame->popOperand();

    Types *array = currentFrame->popOperand();

    array->arrayType->array->at(index->tpInt)->tpLong = value->tpLong;
}

/** @brief Pega um float da pilha de operandos e armazena-o em um array de floats de precisão simples.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void fastore(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    Types* index = currentFrame->popOperand();

    Types *array = currentFrame->popOperand();

    array->arrayType->array->at(index->tpInt)->tpFloat = value->tpFloat;
}

/** @brief Pega um double da pilha de operandos e armazena-o em um array de floats de precisão dupla.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void dastore(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    Types* index = currentFrame->popOperand();

    Types *array = currentFrame->popOperand();

    array->arrayType->array->at(index->tpInt)->tpDouble = value->tpDouble;
}

/** @brief Armazena uma referência a um object em um array de objectos
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void aastore(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    Types* index = currentFrame->popOperand();

    Types *array = currentFrame->popOperand();

    array->arrayType->array->at(index->tpInt)->arrayType = value->arrayType;
}

/** @brief Pega um inteiro de 32 bits da pilha de operandos, trunca-o para um byte de 8 bits com sinal e o armazena em um array de bytes.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void bastore(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    Types* index = currentFrame->popOperand();

    Types *array = currentFrame->popOperand();

    array->arrayType->array->at(index->tpInt)->tpBoolean = value->tpBoolean;
}

/** @brief Dá um pop em um int de 32 bits da pilha, trunca-o para um valor de 16 bits sem sinal e o armazena em um array de caracteres.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void castore(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    Types* index = currentFrame->popOperand();

    Types *array = currentFrame->popOperand();

    array->arrayType->array->at(index->tpInt)->tpChar = value->tpChar;
}

/** @brief Pega um int da pilha de operandos, trunca-o para um short de 16 bits com sinal e armazena-o em um array de shorts.
@param Frame *currentFrame ponteiro que aponta para o frame atual
@return void
*/
void sastore(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    Types* index = currentFrame->popOperand();

    Types *array = currentFrame->popOperand();
    Types *small = criaTipoAPartirString("S");
    small->tpShort = (uint16_t)value->tpInt;

    array->arrayType->array->at(index->tpInt)->tpShort = small->tpShort;

    //TODO teste!
}

/** Dá pop na word no topo da pilha e descarta-a.
 * @brief
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void pop(Frame *currentFrame){
    currentFrame->currentPc++;
    currentFrame->popOperand();
}

/** Dá pop nas duas words no topo da pilha (por exemplo, dois ints) ou em um item do tamanho de duas words (por exemplo, um long int) e descarta-a(s).
 * @brief
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void pop2(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *operand = currentFrame->popOperand();

    if(operand->tag != CONSTANT_Long && operand->tag != CONSTANT_Double)
        currentFrame->popOperand();
}

/**
 * @brief Faz uma cópia extra do item de uma word que está no topo da pilha e o adiciona ao topo da pilha.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void dup(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *type = currentFrame->popOperand();
    Types *copia1 = copyType(type);
    Types *copia2 = copyType(type);

    currentFrame->pushOperand(copia1);
    currentFrame->pushOperand(copia2);
}

/**
 * @brief Duplica o item do tamanho de uma word no topo da pilha e insere-o depois do segundo elemento da pilha.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void dup_x1(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* value = currentFrame->popOperand();
    Types* value2 = currentFrame->popOperand();
    if (value->tag == CONSTANT_Double || value->tag == CONSTANT_Long || value2->tag == CONSTANT_Double || value2->tag == CONSTANT_Long) {
        currentFrame->pushOperand(value2);
        currentFrame->pushOperand(value);
    }
    else {
        Types* tipo = copyType(value);
        currentFrame->pushOperand(tipo);
        currentFrame->pushOperand(value2);
        currentFrame->pushOperand(value);
    }
}

/**
 * @brief Duplica o item do tamanho de uma word no topo da pilha e insere-o depois do terceiro elemento da pilha
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void dup_x2(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* value = currentFrame->popOperand();
    Types* value2 = currentFrame->popOperand();

    if (value->tag != CONSTANT_Double && value->tag != CONSTANT_Long) {
        if (value2->tag == CONSTANT_Double || value2->tag == CONSTANT_Long) {
            Types* tipo = copyType(value);
            currentFrame->pushOperand(tipo);
            currentFrame->pushOperand(value2);
            currentFrame->pushOperand(value);

        }
        else {
            Types* value3 = currentFrame->popOperand();
            if (value3->tag != CONSTANT_Double && value3->tag != CONSTANT_Long) {
                Types* tipo = copyType(value);
                currentFrame->pushOperand(tipo);
                currentFrame->pushOperand(value3);
                currentFrame->pushOperand(value2);
                currentFrame->pushOperand(value);
            }
        }
    }
}

/**
 * @brief Faz uma cópia extra de dois itens do tamanho de uma word ou do item do tamanho de duas words que está no topo da pilha e o(s) adiciona ao topo da pilha.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void dup2(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* value1 = currentFrame->popOperand();
    if (value1->tag != CONSTANT_Double && value1->tag != CONSTANT_Long) {
        Types* value2 = currentFrame->popOperand();

        Types* tipo1 = copyType(value1);
        Types* tipo2 = copyType(value2);

        currentFrame->pushOperand(tipo2);
        currentFrame->pushOperand(tipo1);

        currentFrame->pushOperand(value2);
        currentFrame->pushOperand(value1);

    }
    else {
        Types* tipo = copyType(value1);
        currentFrame->pushOperand(tipo);
        currentFrame->pushOperand(value1);
    }
}

/**
 * @brief Duplica o item do tamanho de duas words e o inserte a duplicata antes do item de uma word que estava na pilha. Também pode duplicar dois itens do tamanho de uma word e inseri-los antes do terceito item do tamanho de uma word.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void dup2_x1(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* value1 = currentFrame->popOperand();
    Types* value2 = currentFrame->popOperand();

    if (value1->tag != CONSTANT_Double && value1->tag != CONSTANT_Long) {
        Types* value3 = currentFrame->popOperand();

        Types* tipo1 = copyType(value1);
        Types* tipo2 = copyType(value2);

        currentFrame->pushOperand(tipo2);
        currentFrame->pushOperand(tipo1);

        currentFrame->pushOperand(value3);

        currentFrame->pushOperand(value2);
        currentFrame->pushOperand(value1);
    }
    else {
        Types* tipo1 = copyType(value1);

        currentFrame->pushOperand(tipo1);
        currentFrame->pushOperand(value2);
        currentFrame->pushOperand(value1);
    }
}

/**
 * @brief Duplica o item do tamanho de duas words do topo da pilha e insere a duplicata antes do item anterior do tamanho de duas words. Também pode duplicar dois itens do tamanho de uma word e inseri-los antes do terceiro elemento do terceiro item do tamanho de duas words ou depois do quarto elemento do tamanho de uma word.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void dup2_x2(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* value1 = currentFrame->popOperand();
    Types* value2 = currentFrame->popOperand();

    Types* tipo1 = copyType(value1);
    if (value1->tag != CONSTANT_Double && value1->tag != CONSTANT_Long && value2->tag != CONSTANT_Double && value2->tag != CONSTANT_Long) {
        Types* value3 = currentFrame->popOperand();

        Types* tipo2 = copyType(value2);

        if (value3->tag != CONSTANT_Double && value3->tag != CONSTANT_Long) {
            Types* value4 = currentFrame->popOperand();


            currentFrame->pushOperand(tipo2);
            currentFrame->pushOperand(tipo1);

            currentFrame->pushOperand(value4);
            currentFrame->pushOperand(value3);

            currentFrame->pushOperand(value2);
            currentFrame->pushOperand(value1);
        }
        else {

            currentFrame->pushOperand(tipo2);
            currentFrame->pushOperand(tipo1);

            currentFrame->pushOperand(value3);
            currentFrame->pushOperand(value2);
            currentFrame->pushOperand(value1);
        }
    }
    else {

        if (value2->tag == CONSTANT_Double || value2->tag == CONSTANT_Long) {
            currentFrame->pushOperand(tipo1);
            currentFrame->pushOperand(value2);
            currentFrame->pushOperand(value1);
        }
        else {
            Types* value3 = currentFrame->popOperand();

            currentFrame->pushOperand(tipo1);
            currentFrame->pushOperand(value3);
            currentFrame->pushOperand(value2);
            currentFrame->pushOperand(value1);
        }

    }

}

/**
 * @brief Troca os dois elementos do tamanho de uma word no topo da pilha de posição.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void swap(Frame *currentFrame){
    currentFrame->currentPc++;
    Types* value1 = currentFrame->popOperand();
    Types* value2 = currentFrame->popOperand();
    currentFrame->pushOperand(value1);
    currentFrame->pushOperand(value2);
}

/**
 * @brief Calcula a adição entre dois valores int do topo da pilha e coloca na pilha o resultado.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void iadd(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Integer;
    result->tpInt = operand1->tpInt+operand2->tpInt;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a adição entre dois valores long do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ladd(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Long;
    result->tpLong = operand1->tpLong+operand2->tpLong;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a adição entre dois valores float do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void fadd(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    float float1, float2;
    memcpy(&float1, &operand1->tpFloat, sizeof(float));
    memcpy(&float2, &operand2->tpFloat, sizeof(float));
    float1 += float2;

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Float;
    memcpy(&result->tpFloat, &float1, sizeof(uint32_t));

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a adição entre dois valores double do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void dadd(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    double double1, double2;
    memcpy(&double1, &operand1->tpDouble, sizeof(double));
    memcpy(&double2, &operand2->tpDouble, sizeof(double));
    double1 += double2;

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Double;
    memcpy(&result->tpDouble, &double1, sizeof(uint64_t));

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a subtração entre dois valores int do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void isub(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Integer;
    result->tpInt = operand2->tpInt-operand1->tpInt;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a subtração entre dois valores long do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void lsub(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *operand2 = currentFrame->popOperand();
    Types *operand1 = currentFrame->popOperand();

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Long;
    result->tpLong = operand1->tpLong-operand2->tpLong;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a subtração entre dois valores float do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void fsub(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    float float1, float2;
    memcpy(&float1, &operand1->tpFloat, sizeof(float));
    memcpy(&float2, &operand2->tpFloat, sizeof(float));
    float2 -= float1;

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Float;
    memcpy(&result->tpFloat, &float2, sizeof(uint32_t));

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a subtração entre dois valores double do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void dsub(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    double double1, double2;
    memcpy(&double1, &operand1->tpDouble, sizeof(double));
    memcpy(&double2, &operand2->tpDouble, sizeof(double));
    double2 -= double1;

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Double;
    memcpy(&result->tpDouble, &double2, sizeof(uint64_t));

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a multiplicação entre dois valores int do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void imul(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Integer;
    result->tpInt = (operand1->tpInt) * (operand2->tpInt);

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a multiplicação entre dois valores long do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lmul(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Long;
    result->tpLong = (operand1->tpLong) * (operand2->tpLong);

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a multiplicação entre dois valores float do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void fmul(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    float float1, float2;
    memcpy(&float1, &operand1->tpFloat, sizeof(float));
    memcpy(&float2, &operand2->tpFloat, sizeof(float));
    float2 *= float1;

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Float;
    memcpy(&result->tpFloat, &float2, sizeof(uint32_t));

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a multiplicação entre dois valores double do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void dmul(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    double double1, double2;
    memcpy(&double1, &operand1->tpDouble, sizeof(double));
    memcpy(&double2, &operand2->tpDouble, sizeof(double));
    double2 *= double1;

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Double;
    memcpy(&result->tpDouble, &double2, sizeof(uint64_t));

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a divisão entre dois valores int do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void idiv(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Integer;
    result->tpInt = (operand2->tpInt) / (operand1->tpInt);

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a divisão entre dois valores long do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ldiv(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Long;
    result->tpLong = (operand2->tpLong) / (operand1->tpLong);

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a divisão entre dois valores float do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void fdiv(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    float float1, float2;
    memcpy(&float1, &operand1->tpFloat, sizeof(float));
    memcpy(&float2, &operand2->tpFloat, sizeof(float));
    float2 /= float1;

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Float;
    memcpy(&result->tpFloat, &float2, sizeof(uint32_t));

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula a divisão entre dois valores double do topo da pilha e coloca na pilha o resultado
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ddiv(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    double double1, double2;
    memcpy(&double1, &operand1->tpDouble, sizeof(double));
    memcpy(&double2, &operand2->tpDouble, sizeof(double));
    double2 /= double1;

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Double;
    memcpy(&result->tpDouble, &double2, sizeof(uint64_t));

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o resto da divisão entre dois ints
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void irem(Frame *currentFrame){
    uint32_t dividendo, divisor, iResto;

    currentFrame->currentPc++;
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    divisor = operand1->tpInt;
    dividendo = operand2->tpInt;

    iResto = (int32_t)dividendo - (dividendo / divisor) * divisor;

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Integer;
    result->tpInt = iResto;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o resto da divisão entre dois longs
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lrem(Frame *currentFrame){
    uint64_t dividendo, divisor, lResto;

    currentFrame->currentPc++;
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    divisor = operand1->tpInt;
    dividendo = operand2->tpInt;

    lResto = dividendo - (dividendo / divisor) * divisor;

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Long;
    result->tpInt = lResto;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o resto da divisão entre dois floats
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void frem(Frame *currentFrame){
    float dividendo, divisor, fResto;

    currentFrame->currentPc++;
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    memcpy(&divisor, &operand1->tpFloat, sizeof(float));
    memcpy(÷ndo, &operand2->tpFloat, sizeof(float));

    fResto = std::fmod(dividendo, divisor);

    Types *result = (Types*)malloc(sizeof(Types));
    result->tag = CONSTANT_Float;
    memcpy(&result->tpFloat, &fResto, sizeof(uint32_t));
    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o resto da divisão entre dois doubles
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void drem(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    double arg1, arg2, result;
    memcpy(&arg1, &value1->tpDouble, sizeof(double));
    memcpy(&arg2, &value2->tpDouble, sizeof(double));
    result = std::fmod(arg2, arg1);

    Types *valorFinal = criaTipoAPartirString("D");
    memcpy(&valorFinal->tpDouble, &result, sizeof(uint64_t));
    currentFrame->pushOperand(valorFinal);
}

/**
 * @brief Calcula o valor negativo do int
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ineg(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *value1 = currentFrame->popOperand();

    Types *result = criaTipoAPartirString("I");
    result->tpInt = -(int32_t)value1->tpInt;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor negativo do long
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lneg(Frame *currentFrame){
    int64_t lvalue1, lresult;
    currentFrame->currentPc++;
    Types *value1 = currentFrame->popOperand();


    lvalue1 = value1->tpLong;

    lresult = -lvalue1;

    Types *result = criaTipoAPartirString("J");
    result->tpLong = lresult;
    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor negativo do float
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void fneg(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *floatValue = currentFrame->popOperand();

    float valorANegar;
    memcpy(&valorANegar, &floatValue->tpFloat, sizeof(float));
    valorANegar = -valorANegar;

    Types *salvarFloat = criaTipoAPartirString("F");
    memcpy(&salvarFloat->tpFloat, &valorANegar, sizeof(uint32_t));
    currentFrame->pushOperand(salvarFloat);
}

/**
 * @brief Calcula o valor negativo do double
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void dneg(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *doubleValue = currentFrame->popOperand();

    double valorANegar;
    memcpy(&valorANegar, &doubleValue->tpDouble, sizeof(double));
    valorANegar = -valorANegar;

    Types *salvarDouble = criaTipoAPartirString("D");
    memcpy(&salvarDouble->tpDouble, &valorANegar, sizeof(uint64_t));
    currentFrame->pushOperand(salvarDouble);
}

/**
 * @brief Calcula o valor do shift left lógico do int
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ishl(Frame *currentFrame){
    uint32_t ivalue1, ivalue2, iresult;

    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    ivalue1 = value1->tpInt;
    ivalue2 = value2->tpInt;

    ivalue2 &= 0x0000001f;

    iresult = ivalue1 << ivalue2;

    Types* result = criaTipoAPartirString("I");

    result->tpInt = iresult;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor do shift left lógico do long
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lshl(Frame *currentFrame){
    int64_t lvalue1, lresult;
    uint64_t lvalue2;
    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    lvalue1 = value1->tpLong;
    lvalue2 = value2->tpLong;

    lvalue2 &= 0x0000003f;

    lresult = lvalue1 << lvalue2;

    Types* result = criaTipoAPartirString("J");

    result->tpLong = lresult;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor do shift left lógico do int
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ishr(Frame *currentFrame){
    uint32_t ivalue1, ivalue2, iresult;

    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    ivalue1 = value1->tpInt;
    ivalue2 = value2->tpInt;


    iresult = (int32_t)(ivalue1 / pow(2, ivalue2));

    Types* result = criaTipoAPartirString("I");

    result->tpInt = iresult;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor do shift right lógico do long
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lshr(Frame *currentFrame){
    int64_t lvalue1, lresult;
    uint64_t lvalue2;
    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    lvalue1 = value1->tpLong;
    lvalue2 = value2->tpLong;


    lresult = (int64_t)(lvalue1 / pow(2, lvalue2 & 0x3f));

    Types* result = criaTipoAPartirString("J");

    result->tpLong = (uint64_t)lresult;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor do unsigned shift right lógico do int
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void iushr(Frame *currentFrame){
    uint32_t ivalue1, ivalue2, iresult;

    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    ivalue1 = value1->tpInt;
    ivalue2 = value2->tpInt;

    ivalue2 &= 0x0000001f;

    iresult = ivalue1 >> ivalue2;

    Types* result = criaTipoAPartirString("I");

    result->tpInt = iresult;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor do unsigned shift right lógico do long
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lushr(Frame *currentFrame){
    int64_t lvalue1, lresult;
    uint64_t lvalue2;
    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    lvalue1 = value1->tpLong;
    lvalue2 = value2->tpLong;

    lvalue2 &= 0x0000003f;

    lresult = lvalue1 >> lvalue2;

    Types* result = criaTipoAPartirString("J");

    result->tpLong = lresult;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor da operação logica or entre ints
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void iand(Frame *currentFrame){
    int32_t ivalue1, ivalue2, iresult;

    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    ivalue1 = value1->tpInt;
    ivalue2 = value2->tpInt;

    iresult = ivalue1 & ivalue2;

    Types* result = criaTipoAPartirString("I");

    result->tpInt = (uint32_t)iresult;

    currentFrame->pushOperand(result);

}

/**
 * @brief Calcula o valor da operação logica and entre longs
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void land(Frame *currentFrame){
    int64_t lvalue1, lvalue2, lresult;

    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    lvalue1 = value1->tpLong;
    lvalue2 = value2->tpLong;

    lresult = lvalue1 & lvalue2;

    Types* result = criaTipoAPartirString("J");

    result->tpLong = (uint64_t)lresult;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor da operação logica or entre ints
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ior(Frame *currentFrame){
    int32_t ivalue1, ivalue2, iresult;

    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    ivalue1 = value1->tpInt;
    ivalue2 = value2->tpInt;

    iresult = ivalue1 | ivalue2;

    Types* result = criaTipoAPartirString("I");

    result->tpInt = (uint32_t)iresult;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor da operação logica or entre longs
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lor(Frame *currentFrame){
    int64_t lvalue1, lvalue2, lresult;

    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    lvalue1 = value1->tpLong;
    lvalue2 = value2->tpLong;

    lresult = lvalue1 | lvalue2;

    Types* result = criaTipoAPartirString("J");

    result->tpLong = (uint64_t)lresult;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor da operação logica xor entre ints
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ixor(Frame *currentFrame){
    int32_t ivalue1, ivalue2, iresult;

    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    ivalue1 = value1->tpInt;
    ivalue2 = value2->tpInt;

    iresult = ivalue1 ^ ivalue2;

    Types* result = criaTipoAPartirString("I");

    result->tpInt = (uint32_t)iresult;

    currentFrame->pushOperand(result);
}

/**
 * @brief Calcula o valor da operação logica xor entre longs
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lxor(Frame *currentFrame){
    int64_t lvalue1, lvalue2, lresult;

    currentFrame->currentPc++;

    Types *value1 = currentFrame->popOperand();
    Types *value2 = currentFrame->popOperand();

    lvalue1 = value1->tpLong;
    lvalue2 = value2->tpLong;

    lresult = lvalue1 ^ lvalue2;

    Types* result = criaTipoAPartirString("J");

    result->tpLong = (uint64_t)lresult;

    currentFrame->pushOperand(result);
}

/**
 * @brief Incrementa uma variável local em uma constante
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void iinc(Frame *currentFrame){
    uint8_t index = currentFrame->code[++currentFrame->currentPc];
    uint8_t constante = currentFrame->code[++currentFrame->currentPc];
    int valorVariavel = (int) currentFrame->localVariables.at(index)->tpInt;
    valorVariavel += (int8_t) constante;
    currentFrame->currentPc++;
    currentFrame->localVariables.at(index)->tpInt = valorVariavel;
}

/**
 * @brief Função converte int para long -  valor no topo da pilha de operandos deve ser do tipo int. O resultado da conversão é colocado na pilha de operandos
 * @param Frame *currentFrame frame atual
 * @return void
 */

void i2l(Frame *currentFrame){
    int valorPilha;
    Types *intType = currentFrame->popOperand();
	memcpy(&valorPilha, &intType->tpInt, sizeof(int32_t));

    long valorConvertido = (long)valorPilha;
    Types *longConvertidoType = criaTipoAPartirString("J");
    memcpy(&longConvertidoType->tpLong, &valorConvertido, sizeof(uint64_t));

    currentFrame->currentPc++;
	currentFrame->pushOperand(longConvertidoType);
}

/**
 * @brief Converte de int para float
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void i2f(Frame *currentFrame){
    int valorPilha;
    Types *intType = currentFrame->popOperand();
	memcpy(&valorPilha, &intType->tpInt, sizeof(int32_t));

    float valorConvertido = (float)valorPilha;
    Types *floatConvertidoType = criaTipoAPartirString("F");
    memcpy(&floatConvertidoType->tpFloat, &valorConvertido, sizeof(uint32_t));

    currentFrame->currentPc++;
    currentFrame->pushOperand(floatConvertidoType);
}

/**
 * @brief Converte de int para double
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void i2d(Frame *currentFrame){
    int valorPilha;
    Types *intType = currentFrame->popOperand();
	memcpy(&valorPilha, &intType->tpInt, sizeof(int32_t));

    double valorConvertido = (double)valorPilha;
    Types *doubleConvertidoType = criaTipoAPartirString("D");
    memcpy(&doubleConvertidoType->tpDouble, &valorConvertido, sizeof(uint64_t));

    currentFrame->currentPc++;
    currentFrame->pushOperand(doubleConvertidoType);
}

/**
 * @brief Converte de long int para int
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void l2i(Frame *currentFrame){
    long valorPilha;
    Types *longType = currentFrame->popOperand();
	memcpy(&valorPilha, &longType->tpLong, sizeof(int64_t));

    int valorConvertido = (int)valorPilha;
    Types *intConvertidoType = criaTipoAPartirString("I");
    memcpy(&intConvertidoType->tpInt, &valorConvertido, sizeof(uint32_t));

    currentFrame->currentPc++;
    currentFrame->pushOperand(intConvertidoType);
}

/**
 * @brief Converte de long int para float
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void l2f(Frame *currentFrame){
    long valorPilha;
    Types *longType = currentFrame->popOperand();
	memcpy(&valorPilha, &longType->tpLong, sizeof(int64_t));

    float valorConvertido = (float)valorPilha;
    Types *floatConvertidoType = criaTipoAPartirString("F");
    memcpy(&floatConvertidoType->tpFloat, &valorConvertido, sizeof(uint32_t));

    currentFrame->currentPc++;
    currentFrame->pushOperand(floatConvertidoType);
}

/**
 * @brief Converte de long int para double
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void l2d(Frame *currentFrame){
    long valorPilha;
    Types *longType = currentFrame->popOperand();
	memcpy(&valorPilha, &longType->tpLong, sizeof(int64_t));

    double valorConvertido = (double)valorPilha;
    Types *doubleConvertidoType = criaTipoAPartirString("D");
    memcpy(&doubleConvertidoType->tpDouble, &valorConvertido, sizeof(uint64_t));

    currentFrame->currentPc++;
    currentFrame->pushOperand(doubleConvertidoType);
}

/**
 * @brief Converte de float para int
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void f2i(Frame *currentFrame){
    float valorPilha;
    Types *floatType = currentFrame->popOperand();
	memcpy(&valorPilha, &floatType->tpFloat, sizeof(int32_t));

    int valorConvertido = (int)valorPilha;
    Types *intConvertidoType = criaTipoAPartirString("I");
    memcpy(&intConvertidoType->tpInt, &valorConvertido, sizeof(uint32_t));

    currentFrame->currentPc++;
    currentFrame->pushOperand(intConvertidoType);
}

/**
 * @brief Converte de float para long int
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void f2l(Frame *currentFrame){
    float valorPilha;
    Types *floatType = currentFrame->popOperand();
	memcpy(&valorPilha, &floatType->tpFloat, sizeof(int32_t));

    long valorConvertido = (long)valorPilha;
    Types *longConvertidoType = criaTipoAPartirString("J");
    memcpy(&longConvertidoType->tpLong, &valorConvertido, sizeof(uint64_t));

    currentFrame->currentPc++;
    currentFrame->pushOperand(longConvertidoType);
}

/**
 * @brief Converte de float para double
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void f2d(Frame *currentFrame){
    float valorPilha;
    Types *floatType = currentFrame->popOperand();
	memcpy(&valorPilha, &floatType->tpFloat, sizeof(int32_t));

    double valorConvertido = (double)valorPilha;
    Types *doubleConvertidoType = criaTipoAPartirString("D");
    memcpy(&doubleConvertidoType->tpDouble, &valorConvertido, sizeof(uint64_t));

    currentFrame->currentPc++;
    currentFrame->pushOperand(doubleConvertidoType);
}

/**
 * @brief Converte de double para int
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void d2i(Frame *currentFrame){
    double valorPilha;
    Types *doubleType = currentFrame->popOperand();
	memcpy(&valorPilha, &doubleType->tpDouble, sizeof(int64_t));

    int valorConvertido = (int)valorPilha;
    Types *intConvertidoType = criaTipoAPartirString("I");
    memcpy(&intConvertidoType->tpInt, &valorConvertido, sizeof(uint32_t));

    currentFrame->currentPc++;
    currentFrame->pushOperand(intConvertidoType);
}

/**
 * @brief Converte de double para long int
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void d2l(Frame *currentFrame){
    double valorPilha;
    Types *doubleType = currentFrame->popOperand();
	memcpy(&valorPilha, &doubleType->tpDouble, sizeof(int64_t));

    long valorConvertido = (long)valorPilha;
    Types *longConvertidoType = criaTipoAPartirString("J");
    memcpy(&longConvertidoType->tpLong, &valorConvertido, sizeof(uint32_t));

    currentFrame->currentPc++;
    currentFrame->pushOperand(longConvertidoType);
}

/**
 * @brief Converte double para float
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */
void d2f(Frame *currentFrame){
    double valorPilha;
    Types *doubleType = currentFrame->popOperand();
    memcpy(&valorPilha, &doubleType->tpDouble, sizeof(double));

    float valorConvertido = (float)valorPilha;
    Types *floatConvertidoType = criaTipoAPartirString("F");
    memcpy(&floatConvertidoType->tpFloat, &valorConvertido, sizeof(uint32_t));

    currentFrame->currentPc++;
    currentFrame->pushOperand(floatConvertidoType);
}

/**
 * @brief Converte int para byte
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void i2b(Frame *currentFrame){
    int valorPilha;
    Types *intType = currentFrame->popOperand();
    memcpy(&valorPilha, &intType->tpInt, sizeof(int32_t));

    int8_t valorConvertido = (int8_t)valorPilha;
	Types *byteConvertidoType = criaTipoAPartirString("B");
    byteConvertidoType->tpByte = (int32_t)valorConvertido;

    currentFrame->currentPc++;
    currentFrame->pushOperand(byteConvertidoType);
}

/**
 * @brief Converte int para char
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void i2c(Frame *currentFrame){
    currentFrame->currentPc++;

    int valorPilha;
    Types *intType = currentFrame->popOperand();
    memcpy(&valorPilha, &intType->tpInt, sizeof(int32_t));

    char valorConvertido = (char)valorPilha;
	Types *charConvertidoType = criaTipoAPartirString("C");
    memcpy(&charConvertidoType->tpByte, &valorConvertido, sizeof(uint32_t));

    currentFrame->pushOperand(charConvertidoType);
}

/**
 * @brief Converte int para short int.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void i2s(Frame *currentFrame){
    currentFrame->currentPc++;

    int valorPilha;
    Types *intType = currentFrame->popOperand();
    memcpy(&valorPilha, &intType->tpInt, sizeof(int32_t));

    short valorConvertido = (short)valorPilha;
	Types *shortConvertidoType = criaTipoAPartirString("S");
    memcpy(&shortConvertidoType->tpByte, &valorConvertido, sizeof(uint32_t));

    currentFrame->pushOperand(shortConvertidoType);
}

/**
 * @brief Tira dois long ints da pilha e os compara. Se valor 1 > valor 2, 1 vai para a pilha de operandos. Se valor 1 == valor 2, 0 vai para a pilha de operandos. Se valor 1 < valor 2, -1 vai para a pilha de operandos
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lcmp(Frame *currentFrame){
    long valorPilha1;
    long valorPilha2;
    Types *longType1 = currentFrame->popOperand();
    Types *longType2 = currentFrame->popOperand();
	memcpy(&valorPilha1, &longType1->tpLong, sizeof(int64_t));
	memcpy(&valorPilha2, &longType2->tpLong, sizeof(int64_t));

    Types *resultado = criaTipoAPartirString("I");

    if(std::isnan(valorPilha1) || std::isnan(valorPilha2)) {
        resultado->tpInt = -1;
    }
    if (valorPilha1 > valorPilha2) {
        resultado->tpInt = 1;
    }
    else if (valorPilha1 < valorPilha2) {
        resultado->tpInt = -1;
    }
    else if (valorPilha1 == valorPilha2) {
        resultado->tpInt = 0;
    }

    currentFrame->currentPc++;
    currentFrame->pushOperand(resultado);
}

/**
 * @brief Tira dois floats de precisão simples da pilha e os compara em busca do menor. Se valor 1 > valor 2, 1 vai para a pilha de operandos. Se valor 1 == valor 2, 0 vai para a pilha de operandos. Se valor 1 < valor 2, -1 vai para a pilha de operandos. Se valor 1 ou valor 2 é Nan, -1 vai para pilha de operandos
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void fcmpl(Frame *currentFrame){
    float valorPilha1;
    float valorPilha2;
    Types *floatType1 = currentFrame->popOperand();
    Types *floatType2 = currentFrame->popOperand();
	memcpy(&valorPilha1, &floatType1->tpFloat, sizeof(int32_t));
	memcpy(&valorPilha2, &floatType2->tpFloat, sizeof(int32_t));

    Types *resultado = criaTipoAPartirString("I");

    if(std::isnan(valorPilha1) || std::isnan(valorPilha2)) {
        resultado->tpInt = -1;
    }
    if (valorPilha1 > valorPilha2) {
        resultado->tpInt = 1;
    }
    else if (valorPilha1 < valorPilha2) {
        resultado->tpInt = -1;
    }
    else if (valorPilha1 == valorPilha2) {
        resultado->tpInt = 0;
    }

    currentFrame->currentPc++;
    currentFrame->pushOperand(resultado);
}

/**
 * @brief Tira dois floats de precisão simples da pilha e os compara em busca do menor. Se valor 1 > valor 2, 1 vai para a pilha de operandos. Se valor 1 == valor 2, 0 vai para a pilha de operandos. Se valor 1 < valor 2, -1 vai para a pilha de operandos. Se valor 1 ou valor 2 é Nan, 1 vai para pilha de operandos
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void fcmpg(Frame *currentFrame){
    float valorPilha1;
    float valorPilha2;
    Types *floatType1 = currentFrame->popOperand();
    Types *floatType2 = currentFrame->popOperand();
	memcpy(&valorPilha1, &floatType1->tpFloat, sizeof(int32_t));
	memcpy(&valorPilha2, &floatType2->tpFloat, sizeof(int32_t));

    Types *resultado = criaTipoAPartirString("I");

    if(std::isnan(valorPilha1) || std::isnan(valorPilha2)) {
        resultado->tpInt = 1;
    }
    if (valorPilha1 > valorPilha2) {
        resultado->tpInt = 1;
    }
    else if (valorPilha1 < valorPilha2) {
        resultado->tpInt = -1;
    }
    else if (valorPilha1 == valorPilha2) {
        resultado->tpInt = 0;
    }

    currentFrame->currentPc++;
    currentFrame->pushOperand(resultado);
}

/**
 * @brief Tira dois floats de precisão dupla (double) da pilha e os compara em busca do menor. Se valor 1 > valor 2, 1 vai para a pilha de operandos. Se valor 1 == valor 2, 0 vai para a pilha de operandos. Se valor 1 < valor 2, -1 vai para a pilha de operandos.. Se valor 1 ou valor 2 é Nan, -1 vai para pilha de operandos
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void dcmpl(Frame *currentFrame){
    double valorPilha1;
    double valorPilha2;
    Types *doubleType1 = currentFrame->popOperand();
    Types *doubleType2 = currentFrame->popOperand();
	memcpy(&valorPilha1, &doubleType1->tpDouble, sizeof(int64_t));
	memcpy(&valorPilha2, &doubleType2->tpDouble, sizeof(int64_t));

    Types *resultado = criaTipoAPartirString("I");

    if(std::isnan(valorPilha1) || std::isnan(valorPilha2)) {
        resultado->tpInt = -1;
    }
    if (valorPilha1 > valorPilha2) {
        resultado->tpInt = 1;
    }
    else if (valorPilha1 < valorPilha2) {
        resultado->tpInt = -1;
    }
    else if (valorPilha1 == valorPilha2) {
        resultado->tpInt = 0;
    }

    currentFrame->currentPc++;
    currentFrame->pushOperand(resultado);
}

/**
 * @brief Tira dois floats de precisão dupla (double) e os compara em busca do maior. Se valor 1 > valor 2, 1 vai para a pilha de operandos. Se valor 1 == valor 2, 0 vai para a pilha de operandos. Se valor 1 < valor 2, -1 vai para a pilha de operandos. Se valor 1 ou valor 2 é Nan, 1 vai para pilha de operandos
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void dcmpg(Frame *currentFrame){
    double valorPilha1;
    double valorPilha2;
    Types *doubleType1 = currentFrame->popOperand();
    Types *doubleType2 = currentFrame->popOperand();
	memcpy(&valorPilha1, &doubleType1->tpDouble, sizeof(int64_t));
	memcpy(&valorPilha2, &doubleType2->tpDouble, sizeof(int64_t));

    Types *resultado = criaTipoAPartirString("I");

    if(std::isnan(valorPilha1) || std::isnan(valorPilha2)) {
        resultado->tpInt = 1;
    }
    if (valorPilha1 > valorPilha2) {
        resultado->tpInt = 1;
    }
    else if (valorPilha1 < valorPilha2) {
        resultado->tpInt = -1;
    }
    else if (valorPilha1 == valorPilha2) {
        resultado->tpInt = 0;
    }

    currentFrame->currentPc++;
    currentFrame->pushOperand(resultado);
}

/**
 * @brief Compara se valor igual a (equal) zero. Se for, vai para instrução no branch offset
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ifeq(Frame *currentFrame){
    Types *operand = currentFrame->popOperand();
    int32_t valueOperand = operand->tpInt;

    if (valueOperand == 0){
        int16_t deslocamento;
        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];
        currentFrame->currentPc += deslocamento;
    } else {
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Compara se valor é diferente de (not equal) zero. Se for, vai para instrução no branch offset
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ifne(Frame *currentFrame){
    Types *operand = currentFrame->popOperand();
    int32_t valueOperand = operand->tpInt;

    if (valueOperand != 0){
        int16_t deslocamento;
        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];
        currentFrame->currentPc += deslocamento;
    } else {
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Compara se valor é menor ou igual a (less equal than) zero. Se for, vai para instrução no branch offset
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ifle(Frame *currentFrame){
    Types *operand = currentFrame->popOperand();
    int32_t valueOperand = operand->tpInt;

    if (valueOperand <= 0){
        int16_t deslocamento;
        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];
        currentFrame->currentPc += deslocamento;
    } else {
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Compara se valor é menor que (less than) zero. Se for, vai para instrução no branch offset
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void iflt(Frame *currentFrame){
    Types *operand = currentFrame->popOperand();
    int32_t valueOperand = operand->tpInt;

    if (valueOperand < 0){
        int16_t deslocamento;
        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];
        currentFrame->currentPc += deslocamento;
    } else {
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Compara se valor é maior ou igual a (greater equal than) zero. Se for, vai para instrução no branch offset
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ifge(Frame *currentFrame){
    Types *operand = currentFrame->popOperand();
    int32_t valueOperand = operand->tpInt;

    if (valueOperand >= 0){
        int16_t deslocamento;
        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];
        currentFrame->currentPc += deslocamento;
    } else {
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Compara se valor é maior que (greater than) zero. Se for, vai para instrução no branch offset
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ifgt(Frame *currentFrame){
    Types *operand = currentFrame->popOperand();
    int32_t valueOperand = operand->tpInt;

    if (valueOperand > 0){
        int16_t deslocamento;
        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];
        currentFrame->currentPc += deslocamento;
    } else {
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Compara valor1 igual a (equal) valor2. Se for, realizar salto
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void if_icmpeq(Frame *currentFrame){
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    int32_t valueOperand1 = operand1->tpInt;
    int32_t valueOperand2 = operand2->tpInt;

    if(valueOperand2 == valueOperand1){
        int16_t deslocamento;

        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];

        currentFrame->currentPc += deslocamento;
    }else{
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Compara valor1 diferente de (not equal) valor2. Se for, realizar salto
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void if_icmpne(Frame *currentFrame){
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    int32_t valueOperand1 = operand1->tpInt;
    int32_t valueOperand2 = operand2->tpInt;

    if(valueOperand2 != valueOperand1){
        int16_t deslocamento;

        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];

        currentFrame->currentPc += deslocamento;
    }else{
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Compara valor1 menor que (less than) valor2. Se for, realizar salto
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void if_icmplt(Frame *currentFrame){
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    int32_t valueOperand1 = operand1->tpInt;
    int32_t valueOperand2 = operand2->tpInt;

    if(valueOperand2 < valueOperand1){
        int16_t deslocamento;

        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];

        currentFrame->currentPc += deslocamento;
    }else{
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Compara valor1 maior ou igual que (greater equals than) valor2. Se for, realizar salto
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void if_icmpge(Frame *currentFrame){
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    int32_t valueOperand1 = operand1->tpInt;
    int32_t valueOperand2 = operand2->tpInt;

    if(valueOperand2 >= valueOperand1){
        int16_t deslocamento;

        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];

        currentFrame->currentPc += deslocamento;
    }else{
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Compara valor1 maior que (greater than) valor2. Se for, realizar salto
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void if_icmpgt(Frame *currentFrame){
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    int32_t valueOperand1 = operand1->tpInt;
    int32_t valueOperand2 = operand2->tpInt;

    if(valueOperand2 > valueOperand1){
        int16_t deslocamento;

        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];

        currentFrame->currentPc += deslocamento;
    }else{
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Compara valor1 menor igual que (less equal than) valor2. Se for, realizar salto
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void if_icmple(Frame *currentFrame){
    Types *operand1 = currentFrame->popOperand();
    Types *operand2 = currentFrame->popOperand();

    int32_t valueOperand1 = operand1->tpInt;
    int32_t valueOperand2 = operand2->tpInt;

    if(valueOperand2 <= valueOperand1){
        int16_t deslocamento;

        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];

        currentFrame->currentPc += deslocamento;
    }else{
        currentFrame->currentPc += 3;
    }
}

/**
 * @brief Compara valores de referência. Se forem iguais, realizar salto
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void if_acmpeq(Frame *currentFrame){
    Types* value2, *value1;
    int16_t branch = currentFrame->code[currentFrame->currentPc + 1];
    branch = (branch << 8) + currentFrame->code[currentFrame->currentPc + 2];

    value2 = currentFrame->popOperand();
    value1 = currentFrame->popOperand();

    if (value2->classInstance == value1->classInstance) {
        currentFrame->currentPc += branch;
    }
    else{
        currentFrame->currentPc += 3;
    }
}

/**
 * @brief Compara valores de referência. Se forem diferentes, realizar salto
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void if_acmpne(Frame *currentFrame){
    Types* value2, *value1;


    int16_t branch = currentFrame->code[currentFrame->currentPc + 1];
    branch = (branch << 8) + (currentFrame->code[currentFrame->currentPc + 2]);

    value2 = currentFrame->popOperand();
    value1 = currentFrame->popOperand();

    if (value2->classInstance != value1->classInstance) {
        currentFrame->currentPc += branch;
    }
    else{
        currentFrame->currentPc += 3;
    }
}

/**
 * @brief branch se a referência é null
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ifnull(Frame *currentFrame){
    Types *operand = currentFrame->popOperand();
    int32_t valueOperand = operand->tpInt;

    if (!valueOperand){
        int16_t deslocamento;
        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];
        currentFrame->currentPc += deslocamento;
    } else {
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief branch se a referência não é null
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ifnonnull(Frame *currentFrame){
    Types *operand = currentFrame->popOperand();
    int32_t valueOperand = operand->tpInt;

    if (valueOperand){
        int16_t deslocamento;
        deslocamento = currentFrame->code[currentFrame->currentPc + 1];
        deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];
        currentFrame->currentPc += deslocamento;
    } else {
        currentFrame->currentPc +=3;
    }
}

/**
 * @brief Realiza salto para um certo offset.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ins_goto(Frame *currentFrame){
    int16_t offset = currentFrame->code[currentFrame->currentPc+1];
    offset = (offset << 8) + currentFrame->code[currentFrame->currentPc+2];
    currentFrame->currentPc +=offset;
}

/**
 * @brief Realiza o salto para um certo offset e coloca endereço de retorno na pilha.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void jsr(Frame *currentFrame){
    /*
    Types* address = criaTipoAPartirString("RA");
    address->returnAddress = currentFrame->currentPc + 3;
    currentFrame->pushOperand(address);

    int16_t deslocamento;
    deslocamento = currentFrame->code[currentFrame->currentPc + 1];
    deslocamento = (deslocamento << 8 ) | currentFrame->code[currentFrame->currentPc + 2];
    currentFrame->currentPc += deslocamento;
     */
}

/**
 * @brief Continua execução a partir de um endereço encontrado em uma variável local.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ret(Frame *currentFrame){
    /*
    uint16_t index = (uint8_t)currentFrame->code[currentFrame->currentPc + 1];

    currentFrame->currentPc = currentFrame->localVariables.at(index)->returnAddress;
     */
}

/**
 * @brief Acessa tabela de salto por chave e realizar salto.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void tableswitch(Frame *currentFrame){
    uint32_t dftByte = 0;
    uint32_t byteL = 0;
    uint32_t byteH = 0;
    uint32_t *jpOffset;
    uint32_t index;
    Types *value1 = currentFrame->popOperand();
    index = value1->tpInt;
    uint32_t strt = currentFrame->currentPc;
    currentFrame->currentPc++;

    while (currentFrame->currentPc % 4 != 0) {
        currentFrame->currentPc++;
    }

    dftByte = currentFrame->code[currentFrame->currentPc++];
    dftByte = (dftByte << 8) + currentFrame->code[currentFrame->currentPc++];
    dftByte = (dftByte << 8) + currentFrame->code[currentFrame->currentPc++];
    dftByte = (dftByte << 8) + currentFrame->code[currentFrame->currentPc++];

    byteL = currentFrame->code[currentFrame->currentPc++];
    byteL = (byteL << 8) + currentFrame->code[currentFrame->currentPc++];
    byteL = (byteL << 8) + currentFrame->code[currentFrame->currentPc++];
    byteL = (byteL << 8) + currentFrame->code[currentFrame->currentPc++];

    byteH = currentFrame->code[currentFrame->currentPc++];
    byteH = (byteH << 8) + currentFrame->code[currentFrame->currentPc++];
    byteH = (byteH << 8) + currentFrame->code[currentFrame->currentPc++];
    byteH = (byteH << 8) + currentFrame->code[currentFrame->currentPc++];

    jpOffset = (uint32_t*)malloc((byteH - byteL + 1) * sizeof(uint32_t));

    for (int i = 0; i < (int)(byteH - byteL + 1); i++) {
        jpOffset[i] = currentFrame->code[currentFrame->currentPc++];
        jpOffset[i] = (jpOffset[i] << 8) + currentFrame->code[currentFrame->currentPc++];
        jpOffset[i] = (jpOffset[i] << 8) + currentFrame->code[currentFrame->currentPc++];
        jpOffset[i] = (jpOffset[i] << 8) + currentFrame->code[currentFrame->currentPc++];
    }

    if ((int32_t)index < (int32_t)byteL || (int32_t)index >(int32_t)byteH) {
        currentFrame->currentPc = strt + (int32_t)dftByte;
    }
    else {
        currentFrame->currentPc = strt + (int32_t)jpOffset[index - byteL];
    }
}

/**
 * @brief Acessa tabela de salto por chave e realizar salto.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lookupswitch(Frame *currentFrame){
    uint32_t dftByte = 0;
    uint32_t nPares = 0;
    uint32_t *jpKeys;
    uint32_t *jpOffset;
    uint32_t key;
    uint32_t strt = currentFrame->currentPc;

    Types *value1 = currentFrame->popOperand();
    key = value1->tpInt;
    currentFrame->currentPc++;

    while (currentFrame->currentPc % 4 != 0) {
        currentFrame->currentPc++;
    }

    dftByte = currentFrame->code[currentFrame->currentPc++];
    dftByte = (dftByte << 8) + currentFrame->code[currentFrame->currentPc++];
    dftByte = (dftByte << 8) + currentFrame->code[currentFrame->currentPc++];
    dftByte = (dftByte << 8) + currentFrame->code[currentFrame->currentPc++];

    nPares = currentFrame->code[currentFrame->currentPc++];
    nPares = (nPares << 8) + currentFrame->code[currentFrame->currentPc++];
    nPares = (nPares << 8) + currentFrame->code[currentFrame->currentPc++];
    nPares = (nPares << 8) + currentFrame->code[currentFrame->currentPc++];

    jpKeys = (uint32_t*)malloc(nPares * sizeof(uint32_t));
    jpOffset = (uint32_t*)malloc(nPares * sizeof(uint32_t));
    for (int i = 0; i < (int)nPares; i++) {
        jpKeys[i] = currentFrame->code[currentFrame->currentPc++];
        jpKeys[i] = (jpKeys[i] << 8) + currentFrame->code[currentFrame->currentPc++];
        jpKeys[i] = (jpKeys[i] << 8) + currentFrame->code[currentFrame->currentPc++];
        jpKeys[i] = (jpKeys[i] << 8) + currentFrame->code[currentFrame->currentPc++];

        jpOffset[i] = currentFrame->code[currentFrame->currentPc++];
        jpOffset[i] = (jpOffset[i] << 8) + currentFrame->code[currentFrame->currentPc++];
        jpOffset[i] = (jpOffset[i] << 8) + currentFrame->code[currentFrame->currentPc++];
        jpOffset[i] = (jpOffset[i] << 8) + currentFrame->code[currentFrame->currentPc++];
    }

    int i;
    for (i = 0; i < (int)nPares; ++i) {
        if (jpKeys[i] == key) {
            currentFrame->currentPc = strt + jpOffset[i];
            break;
        }
    }
    if (i == nPares)
        currentFrame->currentPc = strt + dftByte;
}

/**
 * @brief Retorna int de um método.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void ireturn(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *integer = currentFrame->popOperand();
    Interpreter::getSingleton()->popFrame();
    Frame *calledFrame = Interpreter::getSingleton()->topFrame();
    calledFrame->pushOperand(integer);
}

/**
 * @brief Retorna long int de um método.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void lreturn(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *longValue = currentFrame->popOperand();
    Interpreter::getSingleton()->popFrame();
    Frame *calledFrame = Interpreter::getSingleton()->topFrame();
    calledFrame->pushOperand(longValue);
}

/**
 * @brief Retorna float de um método.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void freturn(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *floatValue = currentFrame->popOperand();
    Interpreter::getSingleton()->popFrame();
    Frame *calledFrame = Interpreter::getSingleton()->topFrame();
    calledFrame->pushOperand(floatValue);
}

/**
 * @brief Retorna double de um método.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void dreturn(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *doubleValue = currentFrame->popOperand();
    Interpreter::getSingleton()->popFrame();
    Frame *calledFrame = Interpreter::getSingleton()->topFrame();
    calledFrame->pushOperand(doubleValue);
}

/**
 * @brief Retorna objeto de um método.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void areturn(Frame *currentFrame){
    currentFrame->currentPc++;
    Types *object = currentFrame->popOperand();
    Interpreter::getSingleton()->popFrame();
    Frame *calledFrame = Interpreter::getSingleton()->topFrame();
    calledFrame->pushOperand(object);
}

/**
 * @brief Retorna void de um método.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void void_return(Frame *currentFrame){
    currentFrame->currentPc++;
    Interpreter::getSingleton()->popFrame();
}

/**
 * @brief Recebe um campo estático a partir de uma classe.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void getstatic(Frame *currentFrame){
    currentFrame->currentPc++;

    uint16_t index = currentFrame->code[currentFrame->currentPc++];
    index = (index << 8) +currentFrame->code[currentFrame->currentPc++];

    CpInfo &fieldInfo = currentFrame->constantPool[index - 1];
    CpInfo &nameAndType = currentFrame->constantPool[fieldInfo.FieldRef.nameAndTypeIndex - 1];
    std::string className = getUTF8StringFromConstantPool(currentFrame->constantPool, fieldInfo.FieldRef.classIndex-1);

    if(className == "java/lang/System"){
        //se for a classe System (default java) não coloca na pilha
        return;
    }

    JavaClassFormat *classInfo = Interpreter::getSingleton()->getClassInfoAndLoadIfNotExists(className);
    std::string varName = getUTF8StringFromConstantPool(classInfo->constantPool, nameAndType.NameAndType.nameIndex - 1);

    Types *staticField = Interpreter::getSingleton()->getStaticFieldOfClass(className, varName);

    currentFrame->pushOperand(staticField);
}

void putstatic(Frame *currentFrame){
    currentFrame->currentPc++;

    uint16_t index = currentFrame->code[currentFrame->currentPc++];
    index = (index<<8) + currentFrame->code[currentFrame->currentPc++];
    CpInfo fieldReference = currentFrame->constantPool[index - 1];

    CpInfo nameAndType = currentFrame->constantPool[fieldReference.FieldRef.nameAndTypeIndex - 1];

    std::string className = getUTF8StringFromConstantPool(currentFrame->constantPool, fieldReference.FieldRef.classIndex - 1);
    std::string varName = getUTF8StringFromConstantPool(currentFrame->constantPool, nameAndType.NameAndType.nameIndex - 1);

    Types *varOperand = currentFrame->popOperand();

    ClassInstance *staticClass = Interpreter::getSingleton()->getStaticClasse(className);
    Types *staticVariable = staticClass->classFields->at(varName);

    switch (staticVariable->tag){
        case CONSTANT_Integer:
            staticVariable->tpInt = varOperand->tpInt;
            break;
        case CONSTANT_Long:
            staticVariable->tpLong = varOperand->tpLong;
            break;
        case CONSTANT_Boolean:
            staticVariable->tpBoolean = varOperand->tpBoolean;
            break;
        case CONSTANT_Char:
            staticVariable->tpChar = varOperand->tpChar;
            break;
        case CONSTANT_Short:
            staticVariable->tpShort = varOperand->tpShort;
            break;
        case CONSTANT_Byte:
            staticVariable->tpByte = varOperand->tpByte;
            break;
        case CONSTANT_Float:
            staticVariable->tpFloat = varOperand->tpFloat;
            break;
        case CONSTANT_Double:
            staticVariable->tpDouble = varOperand->tpDouble;
            break;
        case CONSTANT_String:
            staticVariable->tpString = varOperand->tpString;
            break;
        case CONSTANT_Class:
            staticVariable->classInstance = varOperand->classInstance;
            break;
        case CONSTANT_Array:
            staticVariable->arrayType = varOperand->arrayType;
            break;
    }
}
void getfield(Frame *currentFrame){
    currentFrame->currentPc++;

    uint16_t index = currentFrame->code[currentFrame->currentPc++];
    index = (index<<8) + currentFrame->code[currentFrame->currentPc++];
    CpInfo fieldReference = currentFrame->constantPool[index - 1];

    CpInfo nameAndType = currentFrame->constantPool[fieldReference.FieldRef.nameAndTypeIndex - 1];

    std::string className = getUTF8StringFromConstantPool(currentFrame->constantPool, fieldReference.FieldRef.classIndex - 1);

    std::string varName = getUTF8StringFromConstantPool(currentFrame->constantPool, nameAndType.NameAndType.nameIndex - 1);

    Types *classInstance = currentFrame->popOperand();

    Types *classVariable = classInstance->classInstance->classFields->at(varName);

    currentFrame->pushOperand(classVariable);
}
void putfield(Frame *currentFrame){
    currentFrame->currentPc++;

    uint16_t index = currentFrame->code[currentFrame->currentPc++];
    index = (index<<8) + currentFrame->code[currentFrame->currentPc++];
    CpInfo fieldReference = currentFrame->constantPool[index - 1];

    CpInfo nameAndType = currentFrame->constantPool[fieldReference.FieldRef.nameAndTypeIndex - 1];

    std::string className = getUTF8StringFromConstantPool(currentFrame->constantPool, fieldReference.FieldRef.classIndex - 1);
    std::string varName = getUTF8StringFromConstantPool(currentFrame->constantPool, nameAndType.NameAndType.nameIndex - 1);

    Types *varOperand = currentFrame->popOperand();
    Types *classInstance = currentFrame->popOperand();

    Types *classVariable = classInstance->classInstance->classFields->at(varName);

    switch (varOperand->tag){
        case CONSTANT_Integer:
            classVariable->tpInt = varOperand->tpInt;
            break;
        case CONSTANT_Long:
            classVariable->tpLong = varOperand->tpLong;
            break;
        case CONSTANT_Boolean:
            classVariable->tpBoolean = varOperand->tpBoolean;
            break;
        case CONSTANT_Char:
            classVariable->tpChar = varOperand->tpChar;
            break;
        case CONSTANT_Short:
            classVariable->tpShort = varOperand->tpShort;
            break;
        case CONSTANT_Byte:
            classVariable->tpByte = varOperand->tpByte;
            break;
        case CONSTANT_Float:
            classVariable->tpFloat = varOperand->tpFloat;
            break;
        case CONSTANT_Double:
            classVariable->tpDouble = varOperand->tpDouble;
            break;
        case CONSTANT_String:
            classVariable->tpString = varOperand->tpString;
            break;
        case CONSTANT_Class:
            classVariable->classInstance = varOperand->classInstance;
            break;
        case CONSTANT_Array:
            classVariable->arrayType = varOperand->arrayType;
            break;
    }
}

/**
 * @brief Invoca método despachar baseado na classe.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void invokevirtual(Frame *currentFrame){
    currentFrame->currentPc++;

    uint16_t index = currentFrame->code[currentFrame->currentPc] << 16;
    index += currentFrame->code[++currentFrame->currentPc];

    currentFrame->currentPc++;

    CpInfo &methodRef = currentFrame->constantPool[index - 1];
    CpInfo &nameAndType = currentFrame->constantPool[methodRef.MethodRef.nameAndType - 1];

    std::string className = getUTF8StringFromConstantPool(currentFrame->constantPool, methodRef.MethodRef.index - 1);
    std::string methodName = getUTF8StringFromConstantPool(currentFrame->constantPool, nameAndType.NameAndType.nameIndex-1);
    std::string methodDeor = getUTF8StringFromConstantPool(currentFrame->constantPool, nameAndType.NameAndType.deorIndex-1);

    if(strstr(className.c_str(), "java/")){
        if(className == "java/io/PrintStream" && (methodName == "println" || methodName == "print")){
            if(methodDeor != "()V"){
                Types *pTypes = currentFrame->popOperand();

                switch(pTypes->tag){
                    case CONSTANT_Byte:
                        std::cout <<(int) pTypes->tpByte;
                        break;
                    case CONSTANT_Char:
                        std::cout << (char) pTypes->tpChar;
                        break;
                    case CONSTANT_Short:
                        std::cout << (short)pTypes->tpShort;
                        break;
                    case CONSTANT_Boolean:
                        std::cout << (bool) pTypes->tpBoolean;
                        break;
                    case CONSTANT_String:
                        std::cout << *pTypes->tpString;
                        break;
                    case CONSTANT_Integer:
                        std::cout << (int32_t)pTypes->tpInt;
                        break;
                    case CONSTANT_Float:
                        float floatValue;
                        memcpy(&floatValue, &pTypes->tpFloat, sizeof(float));
                        printf("%f", floatValue);
                        break;
                    case CONSTANT_Long:
                        std::cout <<(long) pTypes->tpLong;
                        break;
                    case CONSTANT_Double:
                        double printValue;
                        memcpy(&printValue, &pTypes->tpDouble, sizeof(double));
                        printf("%.15lf", printValue);
                        break;
                    case CONSTANT_NULL:
                        printf("null");
                        break;
                    case CONSTANT_Class: {
                        ClassInstance *classInstance = pTypes->classInstance;
                        JavaClassFormat *classInfo = classInstance->classInfo;
                        std::string thisClassName = getUTF8StringFromConstantPool(classInfo->constantPool, classInfo->thisClass - 1);
                        std::cout << thisClassName <<"@"<<classInstance;
                    }
                        break;
                }
                if(methodName == "println"){
                    printf("\n");
                }
            }
        } else if(className == "java/lang/String" && methodName == "length"){
            Types *stringReference = currentFrame->popOperand();

            Types *stringLength = (Types*)malloc(sizeof(Types));
            stringLength->tag = CONSTANT_Integer;
            stringLength->tpInt = stringReference->tpString->size();
            currentFrame->pushOperand(stringLength);
        } else if(className == "java/lang/StringBuilder" && methodName == "append"){
            Types *typeToAppend = currentFrame->popOperand();
            Types *stringToBeAppended = copyType(currentFrame->popOperand());

            switch (typeToAppend->tag){
                case CONSTANT_String:
                    *stringToBeAppended->tpString +=(*typeToAppend->tpString);
                    break;
                case CONSTANT_Integer:
                    *stringToBeAppended->tpString +=(std::to_string(typeToAppend->tpInt));
                    break;
                case CONSTANT_Long:
                    *stringToBeAppended->tpString +=(std::to_string(typeToAppend->tpLong));
                    break;
                case CONSTANT_Float:
                    *stringToBeAppended->tpString +=(std::to_string(typeToAppend->tpFloat));
                    break;
                case CONSTANT_Double:
                    *stringToBeAppended->tpString +=(std::to_string(typeToAppend->tpDouble));
                    break;
                case CONSTANT_Short:
                    *stringToBeAppended->tpString +=(std::to_string(typeToAppend->tpShort));
                    break;
                case CONSTANT_Char:
                    *stringToBeAppended->tpString +=(std::to_string(typeToAppend->tpChar));
                    break;
                case CONSTANT_Byte:
                    *stringToBeAppended->tpString +=(std::to_string(typeToAppend->tpByte));
                    break;
                case CONSTANT_Boolean:
                    if(typeToAppend->tpBoolean == 0)
                        *stringToBeAppended->tpString +="false";
                    else
                        *stringToBeAppended->tpString +="true";
                    break;
                case CONSTANT_Class:
                    *stringToBeAppended->tpString += *typeToAppend->classInstance->className+"@"; // TODO colocar endereco
                    break;
                case CONSTANT_Array:
                    *stringToBeAppended->tpString +="Array[]";
                    break;
            }
            currentFrame->pushOperand(stringToBeAppended);
        } else if(className == "java/lang/StringBuilder"){
            // ignorando o toString;
            return;
        }
    }else{
        int qtdArgumentos = 0;
        uint16_t contador = 1;
        while(methodDeor[contador] != ')'){
            char foundedType = methodDeor[contador];
            if(foundedType == 'L'){ // tipo é um objeto
                qtdArgumentos++;
                while(methodDeor[++contador] != ';');
            }else if(foundedType == '['){ // tipo é um array?
                qtdArgumentos++;
                while(methodDeor[++contador] == '[');
                if(methodDeor[contador] == 'L')
                    while(methodDeor[++contador] != ';');
            }else{
                qtdArgumentos++;
            }
            contador++;
        }
        std::vector<Types*> argumentos;

        for (int i = 0; i < qtdArgumentos; ++i) {
            Types *argumento = currentFrame->popOperand();
            argumentos.insert(argumentos.begin(), argumento);
            if(argumento->tag == CONSTANT_Double || argumento->tag == CONSTANT_Long){
                argumentos.insert(argumentos.begin()+1, criaTipoAPartirString("P"));
            }
        }

        Types *actualClass = currentFrame->popOperand();
        argumentos.insert(argumentos.begin(), actualClass);

        ClassInstance *classReferencce = actualClass->classInstance;

        MethodInfo *methodInfoFinded = findMethod(classReferencce->classInfo, methodName, methodDeor);
        Frame *newFrame = new Frame(methodInfoFinded, classReferencce->classInfo);

        for (int j = 0; j < argumentos.size(); ++j) {
            newFrame->localVariables.at(j) = argumentos.at(j);
        }

        Interpreter::getSingleton()->pushFrame(newFrame);
    }
}

/**
 * @brief Invoca método com tratamento especial para superclass private e métodos de incialização de instância.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void invokespecial(Frame *currentFrame){
    currentFrame->currentPc++;

    uint16_t methodIndex = currentFrame->code[currentFrame->currentPc];
    methodIndex = (methodIndex << 8) + currentFrame->code[++currentFrame->currentPc];

    CpInfo &methodRef = currentFrame->constantPool[methodIndex - 1];
    CpInfo &nameAndType = currentFrame->constantPool[methodRef.MethodRef.nameAndType - 1];

    std::string className = getUTF8StringFromConstantPool(currentFrame->constantPool, methodRef.MethodRef.index - 1);
    std::string methodName = getUTF8StringFromConstantPool(currentFrame->constantPool, nameAndType.NameAndType.nameIndex-1);
    std::string methodDeor = getUTF8StringFromConstantPool(currentFrame->constantPool, nameAndType.NameAndType.deorIndex-1);

    currentFrame->currentPc++;
    if( ((className == "java/lang/Object" || className == "java/lang/String") && methodName == "<init>")
       || (className == "java/lang/StringBuilder" && methodName == "<init>")){
        if(className == "java/lang/String" || className == "java/lang/StringBuilder") {
            currentFrame->popOperand(); // remove a string que colocou na pilha de operandos
        }
        else if(methodName == "<init>"){
            Types *classVariable = currentFrame->localVariables.at(0);
            Interpreter::getSingleton()->carregaVariaveisClasse(classVariable->classInstance);
        }
//        if(className == "java/lang/Object" && methodName == "toString"){
//            Types *classVariable = currentFrame->localVariables.at(0);
//            std::string thisClassName = getUTF8StringFromConstantPool(classVariable->classInstance->classInfo->constantPool, classVariable->classInstance->classInfo->thisClass - 1);
//            std::cout << thisClassName <<"@"<<classVariable << std::endl;
//        }
        return;
    } else if(className.find("java/") != std::string::npos){
        printf("Classe java nao implementada.");
        getchar();
        exit(1); // caso seja algum outro tipo de classe java nao implementada
    } else{
        int qtdArgumentos = 0;
        uint16_t contador = 1;
        while(methodDeor[contador] != ')'){
            char foundedType = methodDeor[contador];
            if(foundedType == 'L'){ // tipo é um objeto
                qtdArgumentos++;
                while(methodDeor[++contador] != ';');
            }else if(foundedType == '['){ // tipo é um array?
                qtdArgumentos++;
                while(methodDeor[++contador] == '[');
                if(methodDeor[contador] == 'L')
                    while(methodDeor[++contador] != ';');
            }else{
                qtdArgumentos++;
            }
            contador++;
        }
        std::vector<Types*> argumentos;

        for (int i = 0; i < qtdArgumentos; ++i) {
            Types *argumento = currentFrame->popOperand();
            argumentos.insert(argumentos.begin(), argumento);
            if(argumento->tag == CONSTANT_Double || argumento->tag == CONSTANT_Long){
                argumentos.insert(argumentos.begin()+1, criaTipoAPartirString("P"));
            }
        }

        Types *actualClass = currentFrame->popOperand();
        argumentos.insert(argumentos.begin(), actualClass);

        ClassInstance *classReferencce = actualClass->classInstance;

        MethodInfo *methodInfoFinded = findMethod(classReferencce->classInfo, methodName, methodDeor);
        Frame *newFrame = new Frame(methodInfoFinded, classReferencce->classInfo);

        for (int j = 0; j < argumentos.size(); ++j) {
            newFrame->localVariables.at(j) = argumentos.at(j);
        }

        Interpreter::getSingleton()->pushFrame(newFrame);
    }
}

/**
 * @brief Invoca um método estático de uma classe.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void invokestatic(Frame *currentFrame){
    currentFrame->currentPc++;

    uint16_t methodIndex = currentFrame->code[currentFrame->currentPc++];
    methodIndex = (methodIndex << 8) + currentFrame->code[currentFrame->currentPc++];

    CpInfo &methodInfo = currentFrame->constantPool[methodIndex - 1];

    CpInfo &classInfo = currentFrame->constantPool[methodInfo.MethodRef.index - 1];
    std::string className = getUTF8StringFromConstantPool(currentFrame->constantPool, classInfo.Class.typeClassInfo - 1);

    CpInfo &nameAndType = currentFrame->constantPool[methodInfo.MethodRef.nameAndType - 1];
    std::string methodName = getUTF8StringFromConstantPool(currentFrame->constantPool, nameAndType.NameAndType.nameIndex - 1);
    std::string methodDeor = getUTF8StringFromConstantPool(currentFrame->constantPool, nameAndType.NameAndType.deorIndex - 1);

    if(className == "java/lang/Object" && methodName == "registerNatives"){
//        metodo nativo nao suportado.
        return;
    }else if(className.find("java/") != std::string::npos){
        printf("Classe Java não implementada.");
        getchar();
        exit(1); // caso seja algum outro tipo de classe java nao implementada
    }
    // calcula quantos argumentos o metodo tem
    int qtdArgumentos = 0;
    uint16_t contador = 1;
    while(methodDeor[contador] != ')'){
        char foundedType = methodDeor[contador];
        if(foundedType == 'L'){ // tipo é um objeto
            qtdArgumentos++;
            while(methodDeor[++contador] != ';');
        }else if(foundedType == '['){ // tipo é um array?
            qtdArgumentos++;
            while(methodDeor[++contador] == '[');
            if(methodDeor[contador] == 'L')
                while(methodDeor[++contador] != ';');
        }else{
            qtdArgumentos++;
        }
        contador++;
    }
    std::vector<Types*> argumentos;

    for (int i = 0; i < qtdArgumentos; ++i) {
        Types *argumento = currentFrame->popOperand();
        argumentos.insert(argumentos.begin(), argumento);
        if(argumento->tag == CONSTANT_Double || argumento->tag == CONSTANT_Long){
            argumentos.insert(argumentos.begin()+1, criaTipoAPartirString("P"));
        }
    }

    ClassInstance *classReferencce = Interpreter::getSingleton()->getStaticClasse(className);

    MethodInfo *methodInfoFinded = findMethod(classReferencce->classInfo, methodName, methodDeor);
    Frame *newFrame = new Frame(methodInfoFinded, classReferencce->classInfo);

    for (int j = 0; j < argumentos.size(); ++j) {
        newFrame->localVariables.at(j) = argumentos.at(j);
    }

    Interpreter::getSingleton()->pushFrame(newFrame);
}
void invokeinterface(Frame *currentFrame){
    currentFrame->currentPc++;

    uint16_t methodIndex = currentFrame->code[currentFrame->currentPc++];
    methodIndex = (methodIndex << 8) + currentFrame->code[currentFrame->currentPc++];

    CpInfo &methodInfo = currentFrame->constantPool[methodIndex - 1];

    CpInfo &classInfo = currentFrame->constantPool[methodInfo.MethodRef.index - 1];
    std::string className = getUTF8StringFromConstantPool(currentFrame->constantPool, classInfo.Class.typeClassInfo - 1);

    CpInfo &nameAndType = currentFrame->constantPool[methodInfo.MethodRef.nameAndType - 1];
    std::string methodName = getUTF8StringFromConstantPool(currentFrame->constantPool, nameAndType.NameAndType.nameIndex - 1);
    std::string methodDeor = getUTF8StringFromConstantPool(currentFrame->constantPool, nameAndType.NameAndType.deorIndex - 1);


    printf("qualquer coisa");
}

/**
 * @brief Cria novo array podendo ser de todos os possíveis tipos.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void new_obj(Frame *currentFrame){
    currentFrame->currentPc++;
    uint16_t index = currentFrame->code[currentFrame->currentPc];
    index = (index << 8)+currentFrame->code[++currentFrame->currentPc];

    CpInfo &classInfo = currentFrame->constantPool[index - 1];
    std::string string = getUTF8StringFromConstantPool(currentFrame->constantPool, classInfo.Class.typeClassInfo - 1);

    currentFrame->currentPc++;
    if(string == "java/lang/StringBuilder"){
        Types* stringBuilder = (Types*)malloc(sizeof(Types));
        stringBuilder->tag = CONSTANT_String;
        stringBuilder->tpString = new std::string("");
        currentFrame->pushOperand(stringBuilder);
    }else{
        Types *objectInstance = criaTipoAPartirString("L" + string);
        if (objectInstance->classInstance->className == NULL){ // TODO tratamento de exceção
            std::cout << "Error while loading class: " << string<<std::endl;
            exit(5);
        }
        currentFrame->pushOperand(objectInstance);
    }
}

/**
 * @brief Cria novo array podendo ser de todos os possíveis tipos.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void newarray(Frame *currentFrame){
    currentFrame->currentPc++;

    Types* value = currentFrame->popOperand();
    uint32_t index = value->tpInt;

    Types *tipo = criaTipoAPartirString("["); ///inicia um novo tipo do tipo array

    uint8_t type = currentFrame->code[currentFrame->currentPc++];
    // TODO entender como funciona o type e pq ele nao usa o msm valor da CP
    switch(type){
        case 4: //CONSTANT_Boolean
            for (int i = 0; i<(int)index; i++) {
                tipo->arrayType->array->emplace_back(criaTipoAPartirString("Z"));
            }
            break;
        case 5: //CONSTANT_Char
            for (int i = 0; i<(int)index; i++) {
                tipo->arrayType->array->emplace_back(criaTipoAPartirString("C"));
            }
            break;
        case 6: //CONSTANT_Float
            for (int i = 0; i<(int)index; i++) {
                tipo->arrayType->array->emplace_back(criaTipoAPartirString("F"));
            }
            break;
        case 7: //CONSTANT_Double
            for (int i = 0; i<(int)index; i++) {
                tipo->arrayType->array->emplace_back(criaTipoAPartirString("D"));
            }
            break;
        case 8: //CONSTANT_Byte
            for (int i = 0; i<(int)index; i++) {
                tipo->arrayType->array->emplace_back(criaTipoAPartirString("B"));
            }
            break;
        case 9: //CONSTANT_Short
            for (int i = 0; i<(int)index; i++) {
                tipo->arrayType->array->emplace_back(criaTipoAPartirString("S"));
            }
            break;
        case 10: //CONSTANT_Integer
            for (int i = 0; i<(int)index; i++) {
                tipo->arrayType->array->emplace_back(criaTipoAPartirString("I"));
            }
            break;
        case 11: //CONSTANT_Long
            for (int i = 0; i<(int)index; i++) {
                tipo->arrayType->array->emplace_back(criaTipoAPartirString("J"));
            }
            break;
    }

    currentFrame->pushOperand(tipo);
}

/**
 * @brief Cria novo objeto array.
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void anewarray(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *value = currentFrame->popOperand();
    uint32_t counter = value->tpInt;

    uint16_t indexH = (currentFrame->code[currentFrame->currentPc++]);
    uint16_t indexL = (currentFrame->code[currentFrame->currentPc++]);
    uint16_t index = (indexH << 8) | indexL;

    uint8_t tag = currentFrame->constantPool[index - 1].tag;

    uint16_t classNameRef = currentFrame->constantPool[index - 1].Class.typeClassInfo;

    std::string className = getUTF8StringFromConstantPool(currentFrame->constantPool, classNameRef - 1);

    //TODO Class instance
}

/**
 * @brief Gera o tamanho de um array
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void arraylength(Frame *currentFrame){
    currentFrame->currentPc++;

    Types *array = currentFrame->popOperand();

    Types *tamanho = criaTipoAPartirString("I");
    tamanho->tpInt = array->arrayType->array->size();
    currentFrame->pushOperand(tamanho);
}

/**
 * @brief Checa se o objeto é de um dado tipo
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void checkcast(Frame *currentFrame){

}

/**
 * @brief Determina se o objeto é de um dado tipo
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void instanceof(Frame *currentFrame){}

/**
 * @brief Estende índice de variável local variable com bytes adicionais
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void wide(Frame *currentFrame){}

/**
 * @brief Cria arrays multidimencionais de todos os possíveis tipos.
 * @param std::stack<int> counter contador
 * @param std::string className nome da classe
 * @param Types *aux ponteiro auxiliar de tipos
 * @return void
 */

void multianewarray(Frame *currentFrame){
    currentFrame->currentPc++;

    uint16_t indexH = (currentFrame->code[currentFrame->currentPc++]);
    uint16_t indexL = (currentFrame->code[currentFrame->currentPc++]);
    uint16_t index = (indexH << 8) | indexL;

    uint8_t dimension = currentFrame->code[currentFrame->currentPc++]; /// Acha o numero de dimensoes
    std::stack<int> counter;

    for (uint8_t i = 0; i<dimension; i++) {
        Types* value = currentFrame->popOperand();
        counter.push((int)value->tpInt); /// cria uma lista para armazenar os valores do tamanho das dimensões
    }

    uint16_t classNameRef = currentFrame->constantPool[index - 1].Class.typeClassInfo;
    std::string className = getUTF8StringFromConstantPool(currentFrame->constantPool, classNameRef - 1);
    std::string tpName;
    tpName = className.back();

    Types *aux = criaTipoAPartirString("[");

    insertMultiArray(counter, tpName, aux);

    currentFrame->pushOperand(aux);
}

/**
 * @brief branch sempre (index wide)
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void goto_w(Frame *currentFrame){}

/**
 * @brief jump para subrotina (index wide)
 * @param Frame *currentFrame ponteiro que aponta para o frame atual
 * @return void
 */

void jsr_w(Frame *currentFrame){}

/**
 * @brief Função insertMultiArray
 * @param std::stack<int> counter contador
 * @param std::string className nome da classe
 * @param Types *aux ponteiro auxiliar de tipos
 * @return void
 */

void insertMultiArray(std::stack<int> counter, std::string className, Types *aux) {
    int caux = counter.top();
    counter.pop();

    if (counter.size() == 0){
        for (int i = 0; i < caux; i++){
            aux->arrayType->array->emplace_back(criaTipoAPartirString(className));
        }
    }
    else{
        for (int i = 0; i < caux; i++){
            Types *aaux = criaTipoAPartirString("[");
            insertMultiArray(counter, className, aaux);
            aux->arrayType->array->emplace_back(aaux);
        }
    }
}
