# Lecture Outline 2023-01-23
### Alan Weide

## Review of Make (now with pictures!)
* Why use make?
    * Automates the build process, reducing errors
    * Only builds things it needs to, not necessarily everything in the project
        * Good for large projects where it takes a while to compile!
    * Even for simple projects, good to get in habit
* What is a `makefile`?
    * A sequence of **targets**, each with an associated **recipe** (or **rule**)
    * Evaluated when the `make` command is run from your project folder
        * Simply running `make` with no arguments builds the first target in the file
        * To build a specific target, run `make target-name`
* Where does make shine?
    * Projects with lots of files, and lots of "layers" of source code
    * Projects that have complicated build processes
    * Projects in which we want to quickly switch between several versions
        * A good example is a project with "release" and "debug" versions, compiled to differing levels of optimization (the `-O#` flag to `gcc`) and with/without `assert` statements enabled

## More on I/O in C
* `printf` / `scanf`
    * Primer on format specifiers: `%[l]d`, `%s`, `%[l]f`, `%c`
    * [Format Specifiers Reference](https://en.cppreference.com/w/c/io/fprintf)
    * `scanf` **returns** the number of items it successfully read from input
* What's so special about `stdout` (or `stdin`)?
    * Nothing! They're just files, like everything else in Unix
* Basic file I/O: input redirection
    * `$ ./foo < in.txt`
    * `$ ./foo > out.txt`
    * Read from arbitrary files with `scanf`, print to arbitrary files with `printf`
* What if we need more than one file? **File pointers**
    * `FILE* infile = fopen("input.txt", "r");`
    * `FILE* outfile = fopen("output.txt", "w");`
        * `w` mode **clears the contents of the file**, use `a` if you want to *append* to the end of a file
    * What if we're not working with text files? `FILE* binfile = fopen("foo.jpg", "rb");`
* A file...pointer?
    * We'll cover pointers later
    * For now, it means we don't have the file itself, we just know "where it is"
* Using file pointers
    * `fprintf(stream, format, ...)` is just like `printf` except you pass the file pointer as the first argument
    * `fscanf(stream, format, ...)` is just like `scanf` except you pass the file pointer as the first argument
* A file pointer is a **resource**. We have to close it when we're done using it: `fclose(infile); fclose(outfile); fclose(binfile);`

## Arrays
* Let's look at the signature of `main`
    * `int main(int argc, char* argv[]) {...}`
    * We know what an `int` is, but what is `char* argv[]`?
* `[]` denotes an **array**, so `argv` is an *array* of `char*` (character pointers, a.k.a. strings)
* An array is a group of related variables, all of the same type, and with systematically-related names
    * Each individual *element* of an array is accessed with the **accessor** syntax: `argv[i]` where `i` is an integer in [0, `argc`)
* In C, arrays have a **predefined length** that cannot change after initialization
    * `int array_of_ints[4];` *initializes* a new **array variable** named `array_of_ints` that is an array of 4 `int`s
        * **BEWARE**: the *elements* are all **unitialized**!!
    * `int array_of_ns[] = { 1, 2, 3, 4 };` *initializes* a new **array variable** named `array_of_ints` containing the (4) elements 1, 2, 3, and 4
        * This initialization syntax can *only* be used at the point of declaration
* How long can an array be?
    * Defined by the system, not the language
    * To help this, C defines `size_t` ("size type") which is, by definition "the maximum size of an object"
        * On some systems it's small: as small as 16-bit (since the late '90s)
        * On the zoo, it's big: 64-bit, specifically it is a type alias for `unsigned long`
* Arrays and factorial example
    * Factorial of each number

## Structs
* So we can keep related variables *of the same type* together with one another with an array, but what about related variables of *different types*?
* Consider a program for keeping track of people
    * People have lots of different properties: first name (`char*`), last name (`char*`), age (`int`?), address, gender, favorite color, etc.
    * These properties have different types, but we want to *associate* them with one another for a particular person
* Use a `struct`, which is a **fixed** collection of related variables, accessed *by name* with the *dot syntax*
* Simple program with `struct person;`
* `typedef` can be used to improve readability
* Opaque structs help enforce **abstraction**
    * Header file: `struct person;`
    * Source file: `struct person { char* fname; char* lname; int age; ... };`
    * Including header *does not expose fields of the struct*
        * `person.fname` will not compile
    * What if there are relationships among the fields that must be maintained?
        * `struct array_w_length;`...?
