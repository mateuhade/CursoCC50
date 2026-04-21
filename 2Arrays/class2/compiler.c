#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Hello, world\n\n");
    // when make <filename> is run in the terminal we are not actually running that exact command in a literal terminal, we are actually calling the default cs50 dev compiler
    // to execute the command clang -o <filename> <currentFile>, clang being the compiler in question, -o being short for output for creating a file, and then the name of the
    // compiled computer code file (with the extension) and the file you want to compile (with extension also).
    string csTest = get_string("Type stuff: ");
    // aditionally, when the compiler reads the #include command and the library that is to be included, it only understands that certain functions exist, and it does not
    // automatically pull the function from the library to be executed, for that to happen, the compiler also automatically includes in the terminal "make" prompt, the command
    // -l<library>, which links the library referenced to the file that is being compiled (for example -lcs50 to link the cs50 library)


    //                                                                  ------ THE COMPILER -------
    // when we say "compile the code" we are actually talking about 4 steps of compilation:
    // 1- preprocessing: the compiler reads the whole file looking for linking commands (such as #include<library>) to actually import all the functions that are necessary
    // to run the code successfully
    // 2- compiling: the compiler converts the source code that is written in a common programming language into assembly, which is a programming language that the CPU can
    // directly interpret
    // 3- assembling: the compiler converts the assembly code into machine code (binary) that the CPU can actually execute as electrical outputs and inputs
    // 4- linking: the compiler gathers the machine code for the program that is being compiled and the machine code for all the libraries that are being imported and links,
    // effectivelly concatenating all of the machine codes into a single machine core
    //                                                                  ---------------------------

    // when debugging a code you can always use the print command to show in the terminal the value of a variable that you might think that is causing the error in the program,
    // but there is a more efficient way of doing that, which is using the actual debugger tool. In the cs50 IDE, to use it, you just need to run "debug50 ./<filename>"

}
