#include "InterfaceReader.h"
#include "ReadBytes.h"

void read_interface(FILE *fp, JavaClass* class_file) {
	class_file->interfaces = (u2*)malloc(class_file->interface_count*sizeof(u2));

	for (int i = 0; i < class_file->interface_count; i++) {
			class_file->interfaces[i] = read_2_bytes(file);
	}
}
