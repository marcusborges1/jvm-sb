/** @file MethodsArea.h
 *  @brief Área creada na inicialização da JVM e compartilhada por todas as threads da JVM.
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
