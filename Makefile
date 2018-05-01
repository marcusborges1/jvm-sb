CC=gcc
CFLAGS=-Wall -std=c99 -Iincludes
CPPCHECK=cppcheck
GCOV=--coverage

all : clean cppcheck compile exec gcov

compile :
	@echo "Building ClassFileReader binary..."
	@$(CC) $(CFLAGS) src/ClassFileReader.c -o build/ClassFileReader $(GCOV)
	@echo "Done building!"

exec :
	@echo "Running ClassFileReader..."
	@echo "\n\n\n"
	@build/./ClassFileReader src/HelloWorld.class
	@mv ClassFileReader.gcda build; mv ClassFileReader.gcno build
	@echo "\n\n\n"
	@echo "Done running!"

cppcheck :
	@echo "Static code analysis in ClassFileReader..."
	@$(CPPCHECK) src/ClassFileReader.c
	@echo "Done static analysis!"

gcov :
	@echo "Checking coverage for ClassFileReader..."
	@gcov build/ClassFileReader
	@echo "Done checking!"

clean :
	@echo "Cleaning..."
	@rm -rf build
	@mkdir build
	@echo "Done cleaning!"
