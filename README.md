# JVM-SB

A Java Virtual Machine for Basic Software's course.

# Setups

## Cppcheck

We use [Cppcheck 1.83](http://cppcheck.sourceforge.net/) as static analyser for our code.

### On Ubuntu
1. Download file from there https://sourceforge.net/projects/cppcheck/  
2. Go to the folder with for downloads.
```
cd ~/Downloads/
```
3. Unpack archive.
```
tar -xvf cppcheck-1.83.tar.gz
```
4. Go to unpacked folder. 
```
cd cppcheck-1.83/
```
5. Install package as root.
```
$ make SRCDIR=build CFGDIR=/usr/share/cppcheck/
$ sudo make install CFGDIR=/usr/share/cppcheck/
```
6. Check up result.
```
$ which cppcheck
/usr/bin/cppcheck
```
7. Testing it.
```
$ touch simple.c
$ echo "int main(){ int a; a + 1; return 0}" > simple.c
$ cppcheck simple.c
Checking simple.c ...
[simple.c:1]: (error) Uninitialized variable: a
```
