CC=gcc
CFLAGS=-Wall -std=c99
CPPCHECK=cppcheck
GCOV=--coverage
C_SRCS := $(wildcard *.c)

DIR_SRC=src/
DIR_OBJ=build/

# _OBJ=InterfaceReader.o FieldReader.o AttributeInfoReader.o MethodsReader.o
_OBJ=ClassFileReader.o ClassFilePrinter.o ConstantPoolReader.o ReadBytes.o main.o
OBJ = $(patsubst %,$(DIR_OBJ)%,$(_OBJ))

all : clean cppcheck compile gcov exec

gcov :
	@echo "Checking coverage..."
	# build/InterfaceReader build/FieldReader build/AttributeInfoReader
	@gcov build/ClassFileReader build/ClassFilePrinter build/ConstantPoolReader build/main
	@echo "Done checking!"

exec :
	@echo "Running main..."
	@echo "\n\n\n"
	@build/./main 
	@echo "\n\n\n"
	@echo "Done running!"

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@$(CC) $(CFLAGS) -c -o $@ $< -Iincludes $(GCOV)

compile: $(OBJ)
	@echo "Building objects..."
	@$(CC) $(CFLAGS) -o build/main $^ -Iincludes $(GCOV)
	@echo "Done building!"

cppcheck :
	@echo "Static code analysis..."
	# src/InterfaceReader.c src/FieldReader.c src/AttributeInfoReader.c src/MethodsReader.c
	@$(CPPCHECK) src/ClassFileReader.c src/ClassFilePrinter.c src/ConstantPoolReader.c src/main.c
	@echo "Done static analysis!"

clean :
	@echo "Cleaning..."
	@rm -rf build
	@mkdir build
	@echo "Done cleaning!"
