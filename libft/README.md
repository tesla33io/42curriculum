| Function      | Description                                                | My Tests | `francinette` Tests |
|---------------|------------------------------------------------------------|----------|---------------------|
| `ft_isalpha`  | Checks if a character is alphabetic.                       | **pass** | [ ]                 |
| `ft_isdigit`  | Checks if a character is a digit.                          | **pass** | [ ]                 |
| `ft_isalnum`  | Checks if a character is alphanumeric.                     | **pass** | [ ]                 |
| `ft_isascii`  | Checks if a character is ASCII.                            | **pass** | [ ]                 |
| `ft_isprint`  | Checks if a character is printable.                         | **pass** | [ ]                 |
| `ft_strlen`   | Calculates the length of a string.                          | **pass** | [ ]                 |
| `ft_memset`   | Fills memory with a constant byte.                          | **pass** | [ ]                 |
| `ft_bzero`    | Erases data by writing zeros.                               | **pass** | [ ]                 |
| `ft_memcpy`   | Copies memory area.                                         | **pass** | [ ]                 |
| `ft_memmove`  | Copies memory area, allows overlapping.                     | **pass** | [ ]                 |
| `ft_strlcpy`  | Copies a string to a specific size.                         | **pass** | [ ]                 |
| `ft_strlcat`  | Concatenates strings with a specific size.                  | **pass** | [ ]                 |
| `ft_toupper`  | Converts a character to uppercase.                          | **pass** | [ ]                 |
| `ft_tolower`  | Converts a character to lowercase.                          | **pass** | [ ]                 |
| `ft_strchr`   | Locates the first occurrence of a character.                | **pass** | [ ]                 |
| `ft_strrchr`  | Locates the last occurrence of a character.                 | **pass** | [ ]                 |
| `ft_strncmp`  | Compares two strings up to a certain number.                | **pass** | [ ]                 |
| `ft_memchr`   | Locates the first occurrence of a character in a block.     | **pass** | [ ]                 |
| `ft_memcmp`   | Compares two blocks of memory.                              | **pass** | [ ]                 |
| `ft_strnstr`  | Locates a substring in a string within a limit.             | **pass** | [ ]                 |
| `ft_atoi`     | Converts the initial portion of the string pointed to by `nptr` to `int`. | **pass** | [ ] |
| `ft_calloc`   | Allocates memory for an array of `nmemb` elements of `size` bytes each and returns a pointer to the allocated memory. | **pass** | [ ] |
| `ft_strdup`   | Returns a pointer to a new string which is a duplicate of the string `s`. | **pass** | [ ]       |
| `ft_substr`   | Allocates and returns a substring from the string `s`. The substring begins at index `start` and is of maximum size `len`. | **pass** | [ ] |
| `ft_strjoin`  | Allocates and returns a new string, which is the result of the concatenation of `s1` and `s2`. | **pass** | [ ] |
| `ft_strtrim`  | Allocates and returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end of the string. | **pass** | [ ] |
| `ft_split`    | Allocates and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. The array must end with a `NULL` pointer. | **pass** | [ ] |
| `ft_itoa`     | Allocates and returns a string representing the integer received as an argument. Negative numbers must be handled. | **pass** | [ ] |
| `ft_strmapi`  | Applies the function `f` to each character of the string `s`, passing its index as the first argument to create a new string resulting from successive applications of `f`. | **pass** | [ ] |
| `ft_striteri` | Applies the function `f` on each character of the string passed as an argument, passing its index as the first argument. Each character is passed by address to `f` to be modified if necessary. | **fail** | [ ] |
| `ft_putchar_fd`| Outputs the character `c` to the given file descriptor. | **no tests** | [ ] |
| `ft_putstr_fd`| Outputs the string `s` to the given file descriptor. | **no tests** | [ ] |
| `ft_putendl_fd`| Outputs the string `s` to the given file descriptor followed by a newline. | **no tests** | [ ] |
| `ft_putnbr_fd`| Outputs the integer ’n’ to the given file descriptor. | **no tests** | [ ] |
| `ft_lstnew` \*| Allocates and returns a new node. The member variable `content` is initialized with the value of the parameter `content`. The variable `next` is initialized to `NULL`. | **pass** | [ ] |
| `ft_lstadd_front` \*| Adds the node `new` at the beginning of the list. | **pass** | [ ] |
| `ft_lstsize` \*| Counts the number of nodes in a list. | **pass** | [ ] |
| `ft_lstlast` \*| Returns the last node of the list. | **pass** | [ ] |
| `ft_lstadd_back` \*| Adds the node `new` at the end of the list. | **pass** | [ ] |
| `ft_lstdelone` \*| Takes as a parameter a node and frees the memory of the node’s content using the function `del` given as a parameter and free the node. The memory of `next` must not be freed. | **pass** | [ ] |
| `ft_lstclear` \*| Deletes and frees the given node and every successor of that node, using the function `del` and `free`. Finally, the pointer to the list must be set to `NULL`. | **fail** | [ ] |



_\* - bonus functions_

