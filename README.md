*This project has been created as part of the 42 curriculum by odindar.*

## Description
The goal of this project is to recode the popular and versatile C function `printf()`. This library contains `ft_printf()`, a function that mimics the original `printf()` from `libc` but does not implement its buffer management. It handles the following conversions: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`. This project is a great exercise in learning how to use variadic functions in C and writing well-structured, extensible code.

## Algorithm and Data Structures
This project relies heavily on C variadic macros to handle a variable number of arguments. 
- **Data Structure:** We use `va_list` from the `<stdarg.h>` library to sequentially access the optional arguments passed to the function.
- **Algorithm:** The core logic parses the format string character by character. When a `%` symbol is encountered, a routing function evaluates the subsequent character to determine the correct conversion type. For numeric conversions (such as base 10 integers and base 16 hexadecimals), a recursive algorithm is employed. This recursive approach eliminates the need for dynamic memory allocation (`malloc`), completely avoiding the risk of memory leaks while staying within Norm limits. The total number of printed bytes is tracked and returned at the end of execution, perfectly mirroring the original `printf()` behavior.

## Instructions
To compile the library, you will need a standard C compiler (`cc`) and `make`.

1. Clone the repository to your local machine.
2. Run `make` in the root directory. This will compile the source files using the strict `-Wall -Wextra -Werror` flags and create a static library named `libftprintf.a` using the `ar` command.
3. You can then include `"ft_printf.h"` in your C projects and compile them with the library.

Available `make` commands:
- `make` or `make all`: Compiles the static library.
- `make clean`: Removes the generated `.o` (object) files.
- `make fclean`: Removes the object files and the `libftprintf.a` library.
- `make re`: Recompiles everything from scratch.

## Resources
- [C variadic functions (stdarg.h)](https://en.wikipedia.org/wiki/Stdarg.h)
- [write(2) - Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html)
- **AI Usage:** I utilized AI assistance to structure and draft this README file as per the project requirements. Additionally, the AI provided minor guidance and explanations on specific concepts (such as variadic functions and recursive logic) for learning purposes, ensuring a deeper understanding of the underlying mechanics rather than generating the core code logic.