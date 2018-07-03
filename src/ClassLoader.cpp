/** @file ClassLoader.cpp
 *  @brief Funções de carregar as classes para memória.
 *  @bug No know bugs.
 */
#include "ClassLoader.h"

/** @brief Verifica se é a primeira classe a ser carregada pra mémoria.
*  @return bool true ou false indicando, respectivamente, se é a primeira vez ou não.
*/
bool ClassLoader::is_first_time_loading() {
  // Verifica se a quantidade de classes é 0
  return methods_area->num_classes() == 0;
}

 /** @brief Carrega uma classe para mémoria, na área de métodos.
 *  @param *java_class A classe a ser carregada na mémoria.
 *  @return MethodsArea* uma referência a área de métodos da JVM.
 */
 MethodsArea* ClassLoader::load_class_to_memory(JavaClass* java_class) {
   // Se for a primeira classe a ser carregada para mémoria
   if (is_first_time_loading()) {
     // Inicializa a área de métodos
     methods_area = new MethodsArea();
   }
   // Adiciona nossa estrutura do .class a área de métodos
   // e retorna a área de métodos
   return methods_area->add_class(java_class);
 }
