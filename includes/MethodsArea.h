/** @file MethodsArea.h
 *  @brief Área criada na inicialização da JVM, uma área por JVM.
 */
#ifndef JVM_CPP_METHODSAREA_H
#define JVM_CPP_METHODSAREA_H

#include <vector>
#include "JavaClass.h"


/**
 * @brief Estrutura que contém todas as classes carregadas.
 **/
class MethodsArea {
public:
  std::vector<JavaClass*> loaded_classes;

  MethodsArea* add_class(JavaClass* java_class);
  int num_classes();
};

#endif
