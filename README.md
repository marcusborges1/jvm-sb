# JVM-SB

A Java Virtual Machine for Basic Software's course.

This program checks the following in a ``.class`` file:
- Constant pools
- Fields
- Methods
- Attributes

# Reader and Exhibitor

## Compile and check with javac/javap

Convert ``.java`` to ``.class`` file:

```
$ javac HelloWorld.java
```

To check ``.class`` files uses:

```
$ javap HelloWorld.class
```

## Test files

This system covers ``.java`` files that contains:
- String [StringDemo.class](test/StringDemo.class)
- Simulação de impressão [PrintDemo.class](test/PrintDemo.class)
- Arrays unidimensionais [ArrayUniDemo.class](test/ArrayUniDemo.class)
- Arrays multidimensionais [ArrayMultDemo.class](test/ArrayMultDemo.class)
- Herança [InheritanceDemo.class](test/InheritanceDemo.class) and
  [SuperClassInheritanceDemo.class](test/SuperClassInheritanceDemo.class)
- Reescrita [RewrittenDemo.class](test/RewrittenDemo.class),
  [SubClassRewriteDemo.class](test/SubClassRewriteDemo.class) and
  [SuperClassRewriteDemo.class](test/SuperClassRewriteDemo.class)
- Métodos estáticos [MethodStaticDemo.class](test/MethodStaticDemo.class)
- Atributos de classe [AttributeClassDemo.class](test/AttributeClassDemo.class)
- Atributos de instância [AttributeInstDemo.class](test/AttributeInstDemo.class)
- Polimorfismo [PolDemo.class](test/PolDemo.class)
- Inteiro [IntegerDemo.class](test/IntegerDemo.class)
- Float [FloatDemo.class](test/FloatDemo.class)
- Double [DoubleDemo.class](test/DoubleDemo.class)
- Métodos dinâmicos [MethodDynamicDemo.class](test/MethodDynamicDemo.class)
- Long [LongDemo.class](test/LongDemo.class)
- Classe Abstrata [AbstractClassDemo.class](test/AbstractClassDemo.class)

Future additions:
- Objetos [ObjDemo.class](test/ObjDemo.class)



## Run

To execute this software follow these commands:

```
$ make
```

It will first clean all binaries, than check static code, compile all necessary
files, check coverage and finally execute the software that reads and prints
informations about a ``.class`` file.

To generate documentation:

```
$ doxygen Doxyfile
```

After the command above, open the file [index.html](html/index.html) with a
browser.

# Setup

## Doxygen

```
$ sudo apt-get install doxygen graphviz
```

## Javac/Javap

### Install on Linux (package-manager)

```
$ sudo apt-get install openjdk-9-jdk-headless
```

## Cppcheck

We use [Cppcheck 1.83](http://cppcheck.sourceforge.net/) as static analyser for our code.

### Install on Linux (package-manager)

```
$ sudo apt-get install cppcheck
```

### Test cppcheck

1. Check up result:
```
$ which cppcheck
$ /usr/bin/cppcheck
```
2. Testing it.
```
$ touch simple.c
$ echo "int main(){ int a; a + 1; return 0}" > simple.c
$ cppcheck simple.c
Checking simple.c ...
[simple.c:1]: (error) Uninitialized variable: a
```
