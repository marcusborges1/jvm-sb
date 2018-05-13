CC=gcc
CFLAGS=-Wall -std=c99
CPPCHECK=cppcheck
GCOV=--coverage
C_SRCS := $(wildcard *.c)

DIR_SRC=src/
DIR_OBJ=build/

_OBJ=ClassFileReader.o ConstantPoolReader.o InterfaceReader.o FieldReader.o AttributeReader.o MethodsReader.o ReadBytes.o 
OBJ = $(patsubst %,$(DIR_OBJ)%,$(_OBJ))

all : clean cppcheck compile exec gcov

gcov :
	@echo "Checking coverage for ClassFileReader..."
	@gcov build/ClassFileReader build/ConstantPoolReader build/InterfaceReader build/FieldReader build/AttributeReader
	@echo "Done checking!"

exec :
	@echo "Running ClassFileReader..."
	@echo "\n\n\n"
	@build/./ClassFileReader src/HelloWorld1.class
	@echo "\n\n\n"
	@echo "Done running!"

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@$(CC) $(CFLAGS) -c -o $@ $< -Iincludes $(GCOV)

compile: $(OBJ)
	@echo "Building objects..."
	$(CC) $(CFLAGS) -o build/ClassFileReader $^ -Iincludes $(GCOV)
	@echo "Done building!"

cppcheck :
	@echo "Static code analysis..."
	@$(CPPCHECK) src/ClassFileReader.c src/ConstantPoolReader.c src/InterfaceReader.c src/FieldReader.c src/AttributeReader.c src/MethodsReader.c
	@echo "Done static analysis!"

clean :
	@echo "Cleaning..."
	@rm -rf build
	@mkdir build
	@echo "Done cleaning!"
