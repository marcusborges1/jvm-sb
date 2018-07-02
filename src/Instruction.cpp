#include "Instruction.h"

void Instruction::setup_instructions(Instruction* instructions) {
    instructions[0].name = "nop";
    instructions[0].bytes = 0;

    instructions[1].name = "aconst_null";
    instructions[1].bytes = 0;

    instructions[2].name = "iconst_m1";
    instructions[2].bytes = 0;

    instructions[3].name = "iconst_0";
    instructions[3].bytes = 0;

    instructions[4].name = "iconst_1";
    instructions[4].bytes = 0;

    instructions[5].name = "iconst_2";
    instructions[5].bytes = 0;

    instructions[6].name = "iconst_3";
    instructions[6].bytes = 0;

    instructions[7].name = "iconst_4";
    instructions[7].bytes = 0;

    instructions[8].name = "iconst_5";
    instructions[8].bytes = 0;

    instructions[9].name = "lconst_0";
    instructions[9].bytes = 0;

    instructions[10].name = "lconst_1";
    instructions[10].bytes = 0;

    instructions[11].name = "fconst_0";
    instructions[11].bytes = 0;

    instructions[12].name = "fconst_1";
    instructions[12].bytes = 0;

    instructions[13].name = "fconst_2";
    instructions[13].bytes = 0;

    instructions[14].name = "dconst_0";
    instructions[14].bytes = 0;

    instructions[15].name = "dconst_1";
    instructions[15].bytes = 0;

    instructions[16].name = "bipush";
    instructions[16].bytes = 1;

    instructions[17].name = "sipush";
    instructions[17].bytes = 2;

    instructions[18].name = "ldc";
    instructions[18].bytes = 1;

    instructions[19].name = "ldc_w";
    instructions[19].bytes = 2;

    instructions[20].name = "ldc2_w";
    instructions[20].bytes = 2;

    instructions[21].name = "iload";
    instructions[21].bytes = 1;

    instructions[22].name = "lload";
    instructions[22].bytes = 1;

    instructions[23].name = "fload";
    instructions[23].bytes = 1;

    instructions[24].name = "dload";
    instructions[24].bytes = 1;

    instructions[25].name = "aload";
    instructions[25].bytes = 1;

    instructions[26].name = "iload_0";
    instructions[26].bytes = 0;

    instructions[27].name = "iload_1";
    instructions[27].bytes = 0;

    instructions[28].name = "iload_2";
    instructions[28].bytes = 0;

    instructions[29].name = "iload_3";
    instructions[29].bytes = 0;

    instructions[30].name = "lload_0";
    instructions[30].bytes = 0;

    instructions[31].name = "lload_1";
    instructions[31].bytes = 0;

    instructions[32].name = "lload_2";
    instructions[32].bytes = 0;

    instructions[33].name = "lload_3";
    instructions[33].bytes = 0;

    instructions[34].name = "fload_0";
    instructions[34].bytes = 0;

    instructions[35].name = "fload_1";
    instructions[35].bytes = 0;

    instructions[36].name = "fload_2";
    instructions[36].bytes = 0;

    instructions[37].name = "fload_3";
    instructions[37].bytes = 0;

    instructions[38].name = "dload_0";
    instructions[38].bytes = 0;

    instructions[39].name = "dload_1";
    instructions[39].bytes = 0;

    instructions[40].name = "dload_2";
    instructions[40].bytes = 0;

    instructions[41].name = "dload_3";
    instructions[41].bytes = 0;

    instructions[42].name = "aload_0";
    instructions[42].bytes = 0;

    instructions[43].name = "aload_1";
    instructions[43].bytes = 0;

    instructions[44].name = "aload_2";
    instructions[44].bytes = 0;

    instructions[45].name = "aload_3";
    instructions[45].bytes = 0;

    instructions[46].name = "iaload";
    instructions[46].bytes = 0;

    instructions[47].name = "laload";
    instructions[47].bytes = 0;

    instructions[48].name = "faload";
    instructions[48].bytes = 0;

    instructions[49].name = "daload";
    instructions[49].bytes = 0;

    instructions[50].name = "aaload";
    instructions[50].bytes = 0;

    instructions[51].name = "baload";
    instructions[51].bytes = 0;

    instructions[52].name = "caload";
    instructions[52].bytes = 0;

    instructions[53].name = "saload";
    instructions[53].bytes = 0;

    instructions[54].name = "istore";
    instructions[54].bytes = 1;

    instructions[55].name = "lstore";
    instructions[55].bytes = 1;

    instructions[56].name = "fstore";
    instructions[56].bytes = 1;

    instructions[57].name = "dstore";
    instructions[57].bytes = 1;

    instructions[58].name = "astore";
    instructions[58].bytes = 1;

    instructions[59].name = "istore_0";
    instructions[59].bytes = 0;

    instructions[60].name = "istore_1";
    instructions[60].bytes = 0;

    instructions[61].name = "istore_2";
    instructions[61].bytes = 0;

    instructions[62].name = "istore_3";
    instructions[62].bytes = 0;

    instructions[63].name = "lstore_0";
    instructions[63].bytes = 0;

    instructions[64].name = "lstore_1";
    instructions[64].bytes = 0;

    instructions[65].name = "lstore_2";
    instructions[65].bytes = 0;

    instructions[66].name = "lstore_3";
    instructions[66].bytes = 0;

    instructions[67].name = "fstore_0";
    instructions[67].bytes = 0;

    instructions[68].name = "fstore_1";
    instructions[68].bytes = 0;

    instructions[69].name = "fstore_2";
    instructions[69].bytes = 0;

    instructions[70].name = "fstore_3";
    instructions[70].bytes = 0;

    instructions[71].name = "dstore_0";
    instructions[71].bytes = 0;

    instructions[72].name = "dstore_1";
    instructions[72].bytes = 0;

    instructions[73].name = "dstore_2";
    instructions[73].bytes = 0;

    instructions[74].name = "dstore_3";
    instructions[74].bytes = 0;

    instructions[75].name = "astore_0";
    instructions[75].bytes = 0;

    instructions[76].name = "astore_1";
    instructions[76].bytes = 0;

    instructions[77].name = "astore_2";
    instructions[77].bytes = 0;

    instructions[78].name = "astore_3";
    instructions[78].bytes = 0;

    instructions[79].name = "iastore";
    instructions[79].bytes = 0;

    instructions[80].name = "lastore";
    instructions[80].bytes = 0;

    instructions[81].name = "fastore";
    instructions[81].bytes = 0;

    instructions[82].name = "dastore";
    instructions[82].bytes = 0;

    instructions[83].name = "aastore";
    instructions[83].bytes = 0;

    instructions[84].name = "bastore";
    instructions[84].bytes = 0;

    instructions[85].name = "castore";
    instructions[85].bytes = 0;

    instructions[86].name = "sastore";
    instructions[86].bytes = 0;

    instructions[87].name = "pop";
    instructions[87].bytes = 0;

    instructions[88].name = "pop2";
    instructions[88].bytes = 0;

    instructions[89].name = "dup";
    instructions[89].bytes = 0;

    instructions[90].name = "dup_x1";
    instructions[90].bytes = 0;

    instructions[91].name = "dup_x2";
    instructions[91].bytes = 0;

    instructions[92].name = "dup2";
    instructions[92].bytes = 0;

    instructions[93].name = "dup2_x1";
    instructions[93].bytes = 0;

    instructions[94].name = "dup2_x2";
    instructions[94].bytes = 0;

    instructions[95].name = "swap";
    instructions[95].bytes = 0;

    instructions[96].name = "iadd";
    instructions[96].bytes = 0;

    instructions[97].name = "ladd";
    instructions[97].bytes = 0;

    instructions[98].name = "fadd";
    instructions[98].bytes = 0;

    instructions[99].name = "dadd";
    instructions[99].bytes = 0;

    instructions[100].name = "isub";
    instructions[100].bytes = 0;

    instructions[101].name = "lsub";
    instructions[101].bytes = 0;

    instructions[102].name = "fsub";
    instructions[102].bytes = 0;

    instructions[103].name = "dsub";
    instructions[103].bytes = 0;

    instructions[104].name = "imul";
    instructions[104].bytes = 0;

    instructions[105].name = "lmul";
    instructions[105].bytes = 0;

    instructions[106].name = "fmul";
    instructions[106].bytes = 0;

    instructions[107].name = "dmul";
    instructions[107].bytes = 0;

    instructions[108].name = "idiv";
    instructions[108].bytes = 0;

    instructions[109].name = "ldiv";
    instructions[109].bytes = 0;

    instructions[110].name = "fdiv";
    instructions[110].bytes = 0;

    instructions[111].name = "ddiv";
    instructions[111].bytes = 0;

    instructions[112].name = "irem";
    instructions[112].bytes = 0;

    instructions[113].name = "lrem";
    instructions[113].bytes = 0;

    instructions[114].name = "frem";
    instructions[114].bytes = 0;

    instructions[115].name = "drem";
    instructions[115].bytes = 0;

    instructions[116].name = "ineg";
    instructions[116].bytes = 0;

    instructions[117].name = "lneg";
    instructions[117].bytes = 0;

    instructions[118].name = "fneg";
    instructions[118].bytes = 0;

    instructions[119].name = "dneg";
    instructions[119].bytes = 0;

    instructions[120].name = "ishl";
    instructions[120].bytes = 0;

    instructions[121].name = "lshl";
    instructions[121].bytes = 0;

    instructions[122].name = "ishr";
    instructions[122].bytes = 0;

    instructions[123].name = "lshr";
    instructions[123].bytes = 0;

    instructions[124].name = "iushr";
    instructions[124].bytes = 0;

    instructions[125].name = "lushr";
    instructions[125].bytes = 0;

    instructions[126].name = "iand";
    instructions[126].bytes = 0;

    instructions[127].name = "land";
    instructions[127].bytes = 0;

    instructions[128].name = "ior";
    instructions[128].bytes = 0;

    instructions[129].name = "lor";
    instructions[129].bytes = 0;

    instructions[130].name = "ixor";
    instructions[130].bytes = 0;

    instructions[131].name = "lxor";
    instructions[131].bytes = 0;

    instructions[132].name = "iinc";
    instructions[132].bytes = 2;

    instructions[133].name = "i2l";
    instructions[133].bytes = 0;

    instructions[134].name = "i2f";
    instructions[134].bytes = 0;

    instructions[135].name = "i2d";
    instructions[135].bytes = 0;

    instructions[136].name = "l2i";
    instructions[136].bytes = 0;

    instructions[137].name = "l2f";
    instructions[137].bytes = 0;

    instructions[138].name = "l2d";
    instructions[138].bytes = 0;

    instructions[139].name = "f2i";
    instructions[139].bytes = 0;

    instructions[140].name = "f2l";
    instructions[140].bytes = 0;

    instructions[141].name = "f2d";
    instructions[141].bytes = 0;

    instructions[142].name = "d2i";
    instructions[142].bytes = 0;

    instructions[143].name = "d2l";
    instructions[143].bytes = 0;

    instructions[144].name = "d2f";
    instructions[144].bytes = 0;

    instructions[145].name = "i2b";
    instructions[145].bytes = 0;

    instructions[146].name = "i2c";
    instructions[146].bytes = 0;

    instructions[147].name = "i2s";
    instructions[147].bytes = 0;

    instructions[148].name = "lcmp";
    instructions[148].bytes = 0;

    instructions[149].name = "fcmpl";
    instructions[149].bytes = 0;

    instructions[150].name = "fcmpg";
    instructions[150].bytes = 0;

    instructions[151].name = "dcmpl";
    instructions[151].bytes = 0;

    instructions[152].name = "dcmpg";
    instructions[152].bytes = 0;

    instructions[153].name = "ifeq";
    instructions[153].bytes = 2;

    instructions[154].name = "ifne";
    instructions[154].bytes = 2;

    instructions[155].name = "iflt";
    instructions[155].bytes = 2;

    instructions[156].name = "ifge";
    instructions[156].bytes = 2;

    instructions[157].name = "ifgt";
    instructions[157].bytes = 2;

    instructions[158].name = "ifle";
    instructions[158].bytes = 2;

    instructions[159].name = "if_icmpeq";
    instructions[159].bytes = 2;

    instructions[160].name = "if_icmpne";
    instructions[160].bytes = 2;

    instructions[161].name = "if_icmplt";
    instructions[161].bytes = 2;

    instructions[162].name = "if_icmpg2";
    instructions[162].bytes = 2;

    instructions[163].name = "if_icmpgt";
    instructions[163].bytes = 2;

    instructions[164].name = "if_icmple";
    instructions[164].bytes = 2;

    instructions[165].name = "if_acmpeq";
    instructions[165].bytes = 2;

    instructions[166].name = "if_acmpne";
    instructions[166].bytes = 2;

    instructions[167].name = "goto";
    instructions[167].bytes = 2;

    instructions[168].name = "jsr";
    instructions[168].bytes = 2;

    instructions[169].name = "ret";
    instructions[169].bytes = 1;

    instructions[170].name = "tableswitch";
    // instrução tem tamanho variável
    instructions[170].bytes = 34;

    instructions[171].name = "lookupswitch";
    // instrução tem tamanho variável
    instructions[171].bytes = 26;

    instructions[172].name = "ireturn";
    instructions[172].bytes = 0;

    instructions[173].name = "lreturn";
    instructions[173].bytes = 0;

    instructions[174].name = "freturn";
    instructions[174].bytes = 0;

    instructions[175].name = "dreturn";
    instructions[175].bytes = 0;

    instructions[176].name = "areturn";
    instructions[176].bytes = 0;

    instructions[177].name = "return";
    instructions[177].bytes = 0;

    instructions[178].name = "getstatic";
    instructions[178].bytes = 2;

    instructions[179].name = "putstatic";
    instructions[179].bytes = 2;

    instructions[180].name = "getfield";
    instructions[180].bytes = 2;

    instructions[181].name = "putfield";
    instructions[181].bytes = 2;

    instructions[182].name = "invokevirtual";
    instructions[182].bytes = 2;

    instructions[183].name = "invokespecial";
    instructions[183].bytes = 2;

    instructions[184].name = "invokestatic";
    instructions[184].bytes = 2;

    instructions[185].name = "invokeinterface";
    instructions[185].bytes = 4;

    instructions[186].name = "invokedynamic";
    instructions[186].bytes = 4;

    instructions[187].name = "new";
    instructions[187].bytes = 2;

    instructions[188].name = "newarray";
    instructions[188].bytes = 1;

    instructions[189].name = "anewarray";
    instructions[189].bytes = 2;

    instructions[190].name = "arraylength";
    instructions[190].bytes = 0;

    instructions[191].name = "athrow";
    instructions[191].bytes = 0;

    instructions[192].name = "checkcast";
    instructions[192].bytes = 2;

    instructions[193].name = "instanceof";
    instructions[193].bytes = 2;

    instructions[194].name = "monitorenter";
    instructions[194].bytes = 0;

    instructions[195].name = "monitorexit";
    instructions[195].bytes = 0;

    instructions[196].name = "wide";
    instructions[196].bytes = 3;

    instructions[197].name = "multianewarray";
    instructions[197].bytes = 3;

    instructions[198].name = "ifnull";
    instructions[198].bytes = 2;

    instructions[199].name = "ifnonnull";
    instructions[199].bytes = 2;

    instructions[200].name = "goto_w";
    instructions[200].bytes = 4;

    instructions[201].name = "jsr_w";
    instructions[201].bytes = 4;

    // reservados
    instructions[202].name = "breakpoint";
    instructions[200].bytes = 0;

    instructions[254].name = "impdep1";
    instructions[254].bytes = 0;

    instructions[255].name = "impdep2";
    instructions[255].bytes = 0;
}
