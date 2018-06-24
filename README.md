# JVM-SB

A Java Virtual Machine for Basic Software's course.

This program checks the following in a ``.class`` file:

- Constant pools
- Fields
- Methods
- Attributes

# .class files

To check ```.class``` files uses:

```
$ javap HelloWorld.class
```

# Run

To execute this software follow these commands:

```
$ make
```

It will first clean all binaries, than check static code, compile all necessary
files, check coverage and finally execute the software that reads and prints
informations about a ``.class`` file.

# Setups

## Javap

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

### Install on Linux (SourceFile)

1. Download file from there https://sourceforge.net/projects/cppcheck/  
2. Go to the folder with for downloads.
```
$ cd ~/Downloads/
```
3. Unpack archive.
```
$ tar -xvf cppcheck-1.83.tar.gz
```
4. Go to unpacked folder.
```
$ cd cppcheck-1.83/
```
5. Install package as root.
```
$ make SRCDIR=build CFGDIR=/usr/share/cppcheck/
$ sudo make install CFGDIR=/usr/share/cppcheck/
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
