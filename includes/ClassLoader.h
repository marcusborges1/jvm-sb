/** @file ClassLoader.h
 *  @brief Módulo responsável por carregar as classes pra mémoria.
 */
#ifndef JVM_CPP_CLASSLOADER_H
#define JVM_CPP_CLASSLOADER_H

#include <string>
#include "JavaClass.h"
#include "MethodsArea.h"

/**
 * @brief Estrutura responsável por carregar os métodos pra memória, para para a área de métodos.
 **/
class ClassLoader {
public:
  MethodsArea* methods_area;

  bool is_first_time_loading();
  MethodsArea* load_class_to_memory(JavaClass* java_class);
};


#endif
