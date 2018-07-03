#include "Frame.h"
#include "MethodInfo.h"
#include "AttributeInfo.h"
#include "Instruction.h"

Frame::Frame(MethodInfo* method, CpInfo* cp_info){
  // Frame *frame = new Frame();
  constant_pool_reference = cp_info;

  for (int i = 0; i < method->attributes_count; i++) {
      AttributeInfo* attr = method->attributes + i;
      std::string string = cp_info->get_utf8_constant_pool(cp_info, attr->attribute_name_index -1);
      if(string == "Code"){
        code = attr->code;
      }
  }
  pc = 0;
  method = method;
}

Frame::Frame(){}

void Frame::execute_frame(){
  Instruction instructions[256];
  Instruction::setup_instructions(instructions);

  std::cout << instructions[this->pc].name << std::endl;
  // for (int i = 0; i < this->code.code_length ; i++) {
  //   std::cout <<
  // }


}
