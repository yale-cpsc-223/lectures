# Lecture Outline 2023-01-20
* Policy introductions
* What does a C program look like?
    * Built-in data types in C:
        * `int` (fixed-width integer, probably 32 bits)
        * `long` (fixed-width integer, but 2x wider than int)
    * The factorial function computes and returns the factorial of its argument (called n)
* Programs run via the `main` function
* I/O:
    * `scanf(“%d”, &n)` reads an integer from stdin (standard input)
    * `printf(“%ld\n”, factorial(n))` prints a “long decimal” integer to stdout (standard out)
        * (Factorial function returns a long value)
* Exit codes
    * 0 means “program worked”
    * Non-zero means “error happened”
* One file is great for small examples, but not for large programs
* We want files separated by functionality
* To compile programs with multiple files, we have several options
    * #include the source file
        * Include is a textual insertion of the referenced file
        * Either from the system include path (`#include <...>`) or file’s directory (`#include "..."`)
        * Because it is textual replacement, including things multiple times can cause problems
            * Use
```c
#ifndef __FILENAME_H__
#define __FILENAME_H__
```
## Linking
* We can also include a header file (e.g., `stdio.h`)
    * Header files contain declarations of functions and variables
    * Source files contain definitions of functions and variables
    * Headers are good when we don’t necessarily have source code, or if we want to separate 
* We can compile a program with just headers included with the -c flag to gcc
    * `gcc -c factorial.c`
* We can direct gcc to create a particular output file with the -o flag
    * `gcc libfactorial.c -o lib/libfactorial.o`
* To link, perform the following steps
    * Compile sources separately into .o files
        * `gcc -c factorial.c; gcc -c lib/libfactorial.c`
    * Link the object files
        * `gcc factorial.o lib/libfactorial.o [-o Factorial]`
    * Don’t need source files when we’re linking object files!
*  Make is a tool for compiling things that require multiple steps (e.g., this factorial thing with libfactorial.h)
    * Variable declarations at the top
        * Usually CC and CFLAGS for C projects
    * A list of targets
        * Each target has prerequisites and a recipe
        * `${CC}` is value of CC variable
        * `$@` is the name of the target
        * `$^` is the list of prerequisites
        * The default make target is the first target in the file
    * Make will only run targets that haven’t been edited since the last time make was run
