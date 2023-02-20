## Array List Encapsulation and Interface Design
* We want to **encapsulate** the functionality of our array list because it all "goes together"
* Create a separate source file
    * Which means a separate header file! The **interface**
* Decide on what we want to do with a list
    * Create it
    * Destroy it
    * Print it
    * Append an item to the end of it
    * Remove an item from the end of it
    * Properties of the list?
        * Its length? yes.
        * Its capacity? no!
            * The *client* does not care about the capacity. That's an **implementation detail**
* This interface seems more general than just for a resizing array...could we implement it in a different way?
* How can we accomodate this, and minimize duplicate code?
    * **Opaque struct** to separate the implementation from the interface
    * A key component of **data abstraction**
    * Implementation is determined at **compile time** when we link object files

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

