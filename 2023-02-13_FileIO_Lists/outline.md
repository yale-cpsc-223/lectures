## Array List Encapsulation and Interface Design


## File I/O in C
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

