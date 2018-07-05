/** @file InterfaceInfo.cpp
 *  @brief ...
 *  @bug No know bugs.
 */
/** @cond */
#include <cstdlib>
#include <iostream>
#include <cstring>
/** @endcond */
#include "InterfaceInfo.h"
#include "ReadBytes.h"


/** @brief ...
*  @param class_file ...
*  @param file ...
*  @return void
*/
void InterfaceInfo::read(JavaClass class_file, FILE* file) {
  for (int i = 0; i < class_file.interfaces_count; i++)
      class_file.interfaces[i] = this->get_interface_info(file,
                                                          class_file.interfaces[i],
                                                          class_file);
};

/** @brief ...
*  @param fp ...
*  @param interface_info ...
*  @param class_file ...
*  @return InterfaceInfo ...
*/
InterfaceInfo InterfaceInfo::get_interface_info(FILE *fp,
                                                InterfaceInfo interface_info,
                                                JavaClass class_file) {
	interface_info.interface_table = read_2_bytes(fp);
	return interface_info;
}
