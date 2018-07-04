/** @file Frame.cpp
 *  @brief Inicia o Frame de execução com vetor de variáveis locais, operandos,
 *        contador de programa e ponteiro para pool de constantes.
 *  @bug No know bugs.
 */
#include "Frame.h"
#include "MethodInfo.h"
#include "AttributeInfo.h"
#include "Instruction.h"
#include "InstructionsFunc.h"


void (*func[256])(Frame *curr_frame);

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

void Frame::execute_frame() {
  // coleta o primeiro opcode
  // u1 op_code = method_code.code[pc];
  // substituir pelo op_code
  func[0](this);
}





/** @brief Inicia vetor de funções das instruções assembly.
*  @return void
*/
void Frame::setup_instructions_func(){
    func[0] = nop;
    // func[1] = aconst_null;
    // func[2] = iconst_m1;
    // func[3] = iconst_0;
    // func[4] = iconst_1;
    // func[5] = iconst_2;
    // func[6] = iconst_3;
    // func[7] = iconst_4;
    // func[8] = iconst_5;
    // func[9] = lconst_0;
    // func[10] = lconst_1;
    // func[11] = fconst_0;
    // func[12] = fconst_1;
    // func[13] = fconst_2;
    // func[14] = dconst_0;
    // func[15] = dconst_1;
    // func[16] = bipush;
    // func[17] = sipush;
    // func[18] = ldc;
    // func[19] = ldc_w;
    // func[20] = ldc2_w;
    // func[21] = iload;
    // func[22] = lload;
    // func[23] = fload;
    // func[24] = dload;
    // func[25] = aload;
    // func[26] = iload_0;
    // func[27] = iload_1;
    // func[28] = iload_2;
    // func[29] = iload_3;
    // func[30] = lload_0;
    // func[31] = lload_1;
    // func[32] = lload_2;
    // func[33] = lload_3;
    // func[34] = fload_0;
    // func[35] = fload_1;
    // func[36] = fload_2;
    // func[37] = fload_3;
    // func[38] = dload_0;
    // func[39] = dload_1;
    // func[40] = dload_2;
    // func[41] = dload_3;
    // func[42] = aload_0;
    // func[43] = aload_1;
    // func[44] = aload_2;
    // func[45] = aload_3;
    // func[46] = iaload;
    // func[47] = laload;
    // func[48] = faload;
    // func[49] = daload;
    // func[50] = aaload;
    // func[51] = baload;
    // func[52] = caload;
    // func[53] = saload;
    // func[54] = istore;
    // func[55] = lstore;
    // func[56] = fstore;
    // func[57] = dstore;
    // func[58] = astore;
    // func[59] = istore_0;
    // func[60] = istore_1;
    // func[61] = istore_2;
    // func[62] = istore_3;
    // func[63] = lstore_0;
    // func[64] = lstore_1;
    // func[65] = lstore_2;
    // func[66] = lstore_3;
    // func[67] = fstore_0;
    // func[68] = fstore_1;
    // func[69] = fstore_2;
    // func[70] = fstore_3;
    // func[71] = dstore_0;
    // func[72] = dstore_1;
    // func[73] = dstore_2;
    // func[74] = dstore_3;
    // func[75] = astore_0;
    // func[76] = astore_1;
    // func[77] = astore_2;
    // func[78] = astore_3;
    // func[79] = iastore;
    // func[80] = lastore;
    // func[81] = fastore;
    // func[82] = dastore;
    // func[83] = aastore;
    // func[84] = bastore;
    // func[85] = castore;
    // func[86] = sastore;
    // func[87] = pop;
    // func[88] = pop2;
    // func[89] = dup;
    // func[90] = dup_x1;
    // func[91] = dup_x2;
    // func[92] = dup2;
    // func[93] = dup2_x1;
    // func[94] = dup2_x2;
    // func[95] = swap;
    // func[96] = iadd;
    // func[97] = ladd;
    // func[98] = fadd;
    // func[99] = dadd;
    // func[100] = isub;
    // func[101] = lsub;
    // func[102] = fsub;
    // func[103] = dsub;
    // func[104] = imul;
    // func[105] = lmul;
    // func[106] = fmul;
    // func[107] = dmul;
    // func[108] = idiv;
    // func[109] = ldiv;
    // func[110] = fdiv;
    // func[111] = ddiv;
    // func[112] = irem;
    // func[113] = lrem;
    // func[114] = frem;
    // func[115] = drem;
    // func[116] = ineg;
    // func[117] = lneg;
    // func[118] = fneg;
    // func[119] = dneg;
    // func[120] = ishl;
    // func[121] = lshl;
    // func[122] = ishr;
    // func[123] = lshr;
    // func[124] = iushr;
    // func[125] = lushr;
    // func[126] = iand;
    // func[127] = land;
    // func[128] = ior;
    // func[129] = lor;
    // func[130] = ixor;
    // func[131] = lxor;
    // func[132] = iinc;
    // func[133] = i2l;
    // func[134] = i2f;
    // func[135] = i2d;
    // func[136] = l2i;
    // func[137] = l2f;
    // func[138] = l2d;
    // func[139] = f2i;
    // func[140] = f2l;
    // func[141] = f2d;
    // func[142] = d2i;
    // func[143] = d2l;
    // func[144] = d2f;
    // func[145] = i2b;
    // func[146] = i2c;
    // func[147] = i2s;
    // func[148] = lcmp;
    // func[149] = fcmpl;
    // func[150] = fcmpg;
    // func[151] = dcmpl;
    // func[152] = dcmpg;
    // func[153] = ifeq;
    // func[154] = ifne;
    // func[155] = iflt;
    // func[156] = ifge;
    // func[157] = ifgt;
    // func[158] = ifle;
    // func[159] = if_icmpeq;
    // func[160] = if_icmpne;
    // func[161] = if_icmplt;
    // func[162] = if_icmpge;
    // func[163] = if_icmpgt;
    // func[164] = if_icmple;
    // func[165] = if_acmpeq;
    // func[166] = if_acmpne;
    // func[167] = ins_goto;
    // func[168] = jsr;
    // func[169] = ret;
    // func[170] = tableswitch;
    // func[171] = lookupswitch;
    // func[172] = ireturn;
    // func[173] = lreturn;
    // func[174] = freturn;
    // func[175] = dreturn;
    // func[176] = areturn;
    // func[177] = void_return;
    // func[178] = getstatic;
    // func[179] = putstatic;
    // func[180] = getfield;
    // func[181] = putfield;
    // func[182] = invokevirtual;
    // func[183] = invokespecial;
    // func[184] = invokestatic;
    // func[185] = invokeinterface;
    //
    // func[187] = new_obj;
    // func[188] = newarray;
    // func[189] = anewarray;
    // func[190] = arraylength;
    //
    // func[192] = checkcast;
    // func[193] = instanceof;
    //
    //
    // func[196] = wide;
    // func[197] = multianewarray;
    // func[198] = ifnull;
    // func[199] = ifnonnull;
    // func[200] = goto_w;
    // func[201] = jsr_w;
}



/**
* @brief Função que cria um ponteiro de Operand e o tipo é decidido pela string recebida
* @param std::string string que varia de acordo com o tipo
* @return Operand   novo ponteiro para Operand
*/

Operand *verifica_string_cria_tipo(std::string string_tipo){
    Operand *novo_tipo = (Operand*)malloc(sizeof(Operand));

    switch (string_tipo.c_str()[0]){
        case 'I':
            novo_tipo->tag = CONSTANT_Integer;
            novo_tipo->tpInt = 0;
            break;
        case 'F':
            novo_tipo->tag = CONSTANT_Float;
            novo_tipo->tpFloat = 0;
            break;
        case 'J':
            novo_tipo->tag = CONSTANT_Long;
            novo_tipo->tpLong = 0;
            break;
        case 'D':
            novo_tipo->tag = CONSTANT_Double;
            novo_tipo->tpDouble = 0;
            break;
        case 'Z':
            novo_tipo->tag = CONSTANT_Boolean;
            novo_tipo->tpBoolean = 0;
            break;
        case 'B':
            novo_tipo->tag = CONSTANT_Byte;
            novo_tipo->tpByte = 0;
            break;
        case 'C':
            novo_tipo->tag = CONSTANT_Char;
            novo_tipo->tpChar = 0;
            break;
        case 'S':
            novo_tipo->tag = CONSTANT_Short;
            novo_tipo->tpShort = 0;
            break;
        case '[':
            novo_tipo->tag = CONSTANT_Array;
            novo_tipo->arrayType = (ArrayType*)malloc(sizeof(ArrayType));
            novo_tipo->arrayType->array = new std::vector<Types*>();
            break;
        case 'P':
            novo_tipo->tag = CONSTANT_EmptySpace;
            break;
        case CONSTANT_String:
            novo_tipo->tag = CONSTANT_String;
            novo_tipo->tpString = new std::string("");
            break;
        case 'L':
            if(tipo == "Ljava/lang/String;"){
                novo_tipo->tag = CONSTANT_String;
                novo_tipo->tpString = new std::string("");
            }else{
                novo_tipo->tag = CONSTANT_Class;
                novo_tipo->classInstance = (ClassInstance*)malloc(sizeof(ClassInstance));

                std::string classRealName = tipo.substr(1, tipo.size());
                JavaClassFormat *classInfo = Interpreter::getSingleton()->getClassInfoAndLoadIfNotExists(classRealName);

                novo_tipo->classInstance->classInfo = classInfo;
                novo_tipo->classInstance->className =  new std::string(classRealName);

                Interpreter::getSingleton()->carregaVariaveisClasse(novoType->classInstance);
            }
            break;
    }
    return novo_tipo;
}

