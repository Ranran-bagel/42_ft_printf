*This project has been created as part of the 42 curriculum by <wezhou>.*

# ft_printf

## Description
`ft_printf` is a custom implementation of the standard C `printf`function.
The goal of this project is to understand how formatted output works in C by using variadic functions, format parsing, and low-level output with `write`. The function prints formatted data to the standard output and returns the number of characters printed.
This project supports the mandatory conversions required by the subjects: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`,and `%%`.

## Instruction

### Compilation

To complie the library, run:
```bash
make 
```

This creates the static library:
```bash
libftprintf.s
```

To remove object files:

```bash
make clean
```
To remove object files:

```bash
make fclean
```

To rebuild object files and library:

```bash
make re
```

### Usage

Include the header file in your C file:
```c
#include "ft_printf.h"
```

Compile your program with `libft.a`
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a
```
Example usage:
```c
#include "ft_pirntf.h"
int main(void)
{
	ft_printf("Hello %s, number = %d\n", "world", 42);
	return (0);
}
```

### Algorithm and Data Structure

The main algorithm of `ft_printf` is based on a liner scan of the format string.
The functions read the format sting character by character. If the current character is not `%`, it is printed directly with `write`. When a `%` character is found, the next character is checked to determine the conversion type. According to the coversion , the function retrieves the next argument from `va_list` with the correct type and sends it to the corresponding output function.
For example:

- `%c` retrieves an `int` and prints it as a character.
- `%s` retrieves a `char *` and prints the string.
- `%d` and `%i` retrieves an `int` and print it as a signed decimal number.
- `%u` retrieves and `unsigned int` and prints it as an unsigned decimal number.
- `%x` and `%X` retrieves an `unsigned int` and print it in hexadecimal.
- `%p` retrieves a pointer and prints its address in hexadecimal format.
- `%%` prints a literal percent sign.

The project does not require a complex data structure. The main data strcture used is `va_list`, provided by `<stdarg.h>`, which allows access to variadic arguments. Helper functions are used to separate the logic for printing characters, strings, signed and unsigned numbers, hexadecimal numbers and pointer addresses.
This design keeps the code modular and makes each conversion easier to test and debug.

## Resources

### Documentation

- The 42 project subject for `ft_printf`
- `man 3 prinf`
- `man stdarg`

### Use of AI

AI was used to clarify concepts such as variadic arguments, `va_list`, format parsing, integer conversion, hexadecimal conversion, testing strategies and README organization.
