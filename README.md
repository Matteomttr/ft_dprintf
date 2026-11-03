*This project was carried out personally by Matteo Mattera.*

# ft_dprintf

## Description

**ft_dprintf** is a re-implementation of the C standard library function `dprintf()`.
The goal of the project is to learn how **variadic functions** work in C
(`<stdarg.h>`) and how to write formatted output to any **file descriptor**,
while keeping the code clean and well-structured.

The project produces a library, `libftprintf.a`, which exposes one function:

```c
int ft_dprintf(int fd, const char *format, ...);
```

Like the original, it writes the formatted output to the file descriptor `fd`
(standard output, standard error, a file, a pipe, a socket...) and returns the
**number of characters printed**, or `-1` if a write error occurs. The buffer
management of the original `dprintf()` is not reimplemented.

### Supported conversions

| Conversion | Description                                  |
|:----------:|----------------------------------------------|
| `%c`       | Prints a single character                    |
| `%s`       | Prints a string                              |
| `%p`       | Prints a `void *` pointer in hexadecimal     |
| `%d`       | Prints a signed decimal (base 10) number     |
| `%i`       | Prints a signed integer (base 10)            |
| `%u`       | Prints an unsigned decimal (base 10) number  |
| `%x`       | Prints a number in hexadecimal (lowercase)   |
| `%X`       | Prints a number in hexadecimal (uppercase)   |
| `%%`       | Prints a percent sign                        |

## Instructions

### Compilation

The project is compiled with `cc -Wall -Wextra -Werror`.

```bash
make          # builds libftprintf.a at the root of the repository
make clean    # removes the object files
make fclean   # removes the object files and libftprintf.a
make re       # fclean + all
```

The library is created with `ar`.

### Usage

```c
#include <fcntl.h>
#include <unistd.h>
#include "ft_printf.h"

int main(void)
{
	int	len;
	int	fd;

	/* Standard output */
	len = ft_dprintf(1, "Hello %s! %d + %d = %i (0x%x)\n", "42", 1, 2, 3, 255);
	ft_dprintf(1, "Printed %d characters\n", len);

	/* Standard error */
	ft_dprintf(2, "Error: %s\n", "something went wrong");

	/* A file */
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	ft_dprintf(fd, "Pointer: %p, unsigned: %u\n", (void *)&fd, 42u);
	close(fd);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## Algorithm and data structure

### Algorithm

`ft_dprintf` reads the format string in a **single pass**, from left to right:

1. A `va_list` is initialised with `va_start`.
2. Each character of the format string is inspected:
   - if it is not a `%`, it is written as is with `write(fd, ...)`;
   - if it is a `%`, the next character is the conversion specifier and the
     matching handler is called (`c`, `s`, `p`, `d`/`i`, `u`, `x`, `X`, `%`).
3. Each handler receives the file descriptor `fd` and its argument (via `va_arg`),
   writes it directly to `fd` and returns the number of bytes written.
4. The counts are added up and the total is returned after `va_end`.
   If any `write` fails, `-1` is returned.

Numbers are printed with a **recursive base conversion**: the number is divided
by the base until a single digit remains, then digits are written on the way back.
The same function serves base 10 (`d`, `i`, `u`) and base 16 (`x`, `X`, `p`);
only the base string changes.

Special cases follow the behaviour of the original `dprintf()` on Linux:

- `%s` with a `NULL` pointer prints `(null)`;
- `%p` with a `NULL` pointer prints `(nil)`, otherwise `0x` followed by the address;
- `INT_MIN` is handled by converting to a wider type before negating, to avoid overflow.

### Why this approach?

- **Output on any file descriptor**: the `fd` is simply passed down to every
  handler, so the same code prints to stdout, stderr, a file or a pipe.
- **No buffer**: direct `write` calls keep the code simple, and the buffer
  management of the original is not reimplemented.
- **One handler per conversion**: each function does one thing, which makes the
  code readable and easy to test.
- **Each function returns the number of bytes written**: the final return value is
  computed without a second pass over the data.
- **No dynamic allocation**: everything is written on the fly, so no memory leaks.

## Resources

### References

- `man 3 dprintf`
- `man 3 stdarg`
- `man 2 write`

### Use of AI

AI was used for: README.
