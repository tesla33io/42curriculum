# ft_printf()

## Algorithm

1. Start by determining the number of arguments the function receives.
2. Next, print the provided string (2 ways):
   - [ ] Utilize the "print char by char" approach
   - [x] Implement the "print part by part" method
3. As the string is printed, specific functions will handle the processing of arguments.

> #### Print char by char
> 
> In this method, check for _conversions_. If found, navigate to the specific formatter;
>  if the character is not _conversion_, print it and continue.
>
> **Advantages**:
> 
> * **Simplicity**: It can be easier to implement, especially for simple format strings. 
>
> * **Real-time processing**: Characters are processed as they are encountered in the format string.
> 
> **Considerations**:
>
> * **Potential inefficiency**: Checking each character individually may result in more conditional
>  statements and could be less efficient for complex format strings.

> #### Print part by part
> 
> In this approach, identify indices (_start_ and _end_) between _conversions_, print the corresponding
>  string part, process the _conversion_, and continue.
>
> 
> **Advantages**:
> 
> * **Improved efficiency**: By identifying and processing larger chunks of the format string at once,
>  you may reduce the overall number of operations.
> 
> * **Better handling of complex formats**: Useful when dealing with more intricate format specifiers
>  that involve multiple characters.
> 
> **Considerations**:
> 
> * **Implementation complexity**: The logic for identifying and processing parts may be more involved
>  than the straightforward character-by-character approach.

## Conversions

| Conversion | Description 																|
|:----------:|--------------------------------------------------------------------------|
| `%c`       | Prints a single character. 												|
| `%s`       | Prints a string (as defined by the common C convention). 				|
| `%p`       | The void * pointer argument has to be printed in hexadecimal format. 	|
| `%d`       | Prints a decimal (base 10) number. 										|
| `%i`       | Prints an integer in base 10. 											|
| `%u`       | Prints an unsigned decimal (base 10) number. 							|
| `%x`       | Prints a number in hexadecimal (base 16) lowercase format. 				|
| `%X`       | Prints a number in hexadecimal (base 16) uppercase format. 				|
| `%%`       | Prints a percent sign. 													|
