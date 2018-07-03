/** @file ClassLoader.cpp
 *  @brief Funções de carregar as classes para memória.
 *  @bug No know bugs.
 */
#include "MethodsArea.h"

/** @brief Adiciona uma nova classe a área de métodos.
*  @param java_class A classe a ser adicionada.
*  @return MethodsArea* a área de métodos da JVM.
*/
MethodsArea* MethodsArea::add_class(JavaClass* java_class) {
  // Adiciona o java class a lista de classes carregadas em mémoria
  loaded_classes.push_back(java_class);
  // retorna a própria referência da área de métodos
  return this;
}

/** @brief Retorna a quantidade de classes salvas na área de métodos.
*  @return int quantidade de classes salvas na área de métodos.
*/
int MethodsArea::num_classes() {
  // Retorna a quantidade de classes carregadas em mémoria
  return loaded_classes.size();
}
