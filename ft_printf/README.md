# ft_printf

This project aims to develop a custom `ft_printf` function that works similarly to the original `printf` function.

## How it works?

> [Variadic functions](https://www.geeksforgeeks.org/variadic-functions-in-c/)

This function accepts the `format` string and an unlimited number of arguments of different types as input. Then, this function processes the formatters (conversions) inside the strings with the provided arguments.

### A brief overview of the function:
1. This function preforms some basic error checking (if `format` is `NULL` or `""`).
2. Than it initializes the `va_list` with the start of the variable arguments using `va_start()`.
3. It calls a function `print()` with the file descriptor `1` (standard output), the `format` string, and the `va_list` of arguments.
5. After printing is done, it cleans up the `va_list` with `va_end()`.
6. Finally, it returns the number of characters printed (`done`).

---

- `int print(int fd, const char *s, va_list arg);`

    This function iterates through each character of the string and outputs it to the terminal. If it encounters a `%` character, the function will try to process it using `process_formatter()`.

- `int process_formatter(const char **s, va_list arg, int fd);`

    This function checks whether the specified format is supported. If it does, it passes the argument to a special function (`formatter_*()`) that prints the argument to the terminal. If the specified format is not supported, it will simply be displayed in the terminal as a regular character ('k' for `%k`, 'a' for `%a`, etc.). If the format is `%`, the function will print '%' to the terminal.

## Conversions


| Conversion | Description 																|
|:----------:|--------------------------------------------------------------------------|
| `%c`       | Prints a single character. 												|
| `%s`       | Prints a string (as defined by the common C convention). 				|
| `%p`       | The `void *` pointer argument has to be printed in hexadecimal format. 	|
| `%d`       | Prints a decimal (base 10) number. 										|
| `%i`       | Prints an integer in base 10. 											|
| `%u`       | Prints an unsigned decimal (base 10) number. 							|
| `%x`       | Prints a number in hexadecimal (base 16) lowercase format. 				|
| `%X`       | Prints a number in hexadecimal (base 16) uppercase format. 				|
| `%%`       | Prints a percent sign. 													|
| `%*`       | Prints the specified character. 											|
