#ifndef JVM_CPP_INTERFACEINFO_H
#define JVM_CPP_INTERFACEINFO_H

#include <cstdio>
#include "JavaClass.h"

class InterfaceInfo {
	// u2  interface_count;
public:
	u2	interface_table;

	void read(JavaClass, FILE*);
	InterfaceInfo get_interface_info(FILE*, InterfaceInfo, JavaClass);
};

#endif
