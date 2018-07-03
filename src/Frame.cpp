#include "Frame.h"

Frame::Frame(MethodInfo* method, CpInfo* cp_info){
  // Frame *frame = new Frame();
  constant_pool_reference = cp_info;
  method = method;
}

Frame::Frame(){}
