/** @file InterfaceInfo.h
 *  @brief ...
 */
#ifndef JVM_CPP_INTERFACEINFO_H
#define JVM_CPP_INTERFACEINFO_H

/** @cond */
#include <cstdio>
/** @endcond */
#include "JavaClass.h"


/**
 * @brief ...
 **/
class InterfaceInfo {
public:
	u2	interface_table;

	void read(JavaClass, FILE*);
	InterfaceInfo get_interface_info(FILE*, InterfaceInfo, JavaClass);
};

#endif
