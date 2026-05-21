*This activity has been created as part of the 42 curriculum by gerramir.*

# get_next_line

## Description

The purpose of this project is to implement a function called `get_next_line` capable of reading and returning one line at a time from a file descriptor.

This project introduces important concepts related to:
- static variables
- memory allocation
- file descriptors
- buffer management
- string manipulation
- efficient reading from files and standard input

The function must behave correctly regardless of the value of `BUFFER_SIZE`, including very small or very large values.

The mandatory function prototype is:

```c
char *get_next_line(int fd);
```

Each call to the function returns:
- the next line from the file descriptor
- `NULL` when the end of file is reached or an error occurs

A line is considered ended by:
- a newline character (`\n`)
- or the end of file (EOF)

---

## Project Goal

The objective of this project is to understand how low-level input works in C by recreating a line reader using only:
- `read`
- `malloc`
- `free`

The project also focuses on:
- handling dynamic memory safely
- avoiding memory leaks
- managing persistent data between function calls using static variables

---

## Instructions

### Compilation

Compile using:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

Or with another buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 *.c
```

### Usage Example

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);

	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

### Run

```bash
./a.out
```

---

## Algorithm Explanation

The implementation uses a static variable to preserve unread content between function calls.

### General Workflow

1. Read data from the file descriptor using `read()`
2. Store the data in a temporary buffer
3. Concatenate the new buffer to the existing static storage
4. Search for a newline (`\n`)
5. If a newline exists:
   - extract the line to return
   - keep the remaining content for the next call
6. If no newline exists:
   - continue reading until EOF or newline
7. Return the final remaining content at EOF

---

### Why a Static Variable?

A static variable allows the function to remember previously read content between calls.

Without it, the function would lose the unread portion of the buffer after returning a line.

Example:

```text
BUFFER: "Hello\nWorld\n"
```

After returning `"Hello\n"`, the function must preserve `"World\n"` for the next call.

---

### Chosen Design

The project was implemented using:
- dynamic string concatenation
- custom utility functions (`ft_strlen`, `ft_strjoin`, `ft_substr`, etc.)
- a static storage buffer

This approach prioritizes:
- readability
- modularity
- compatibility with the 42 project constraints

---

### Complexity Considerations

The current implementation repeatedly concatenates strings when reading large files.

This means:
- small files perform efficiently
- extremely large lines with very small `BUFFER_SIZE` values may lead to slower execution due to repeated memory allocations and copies

This tradeoff was accepted to maintain clarity and simplicity within the scope of the project.

---

## Files

| File | Description |
|---|---|
| `get_next_line.c` | Main function implementation |
| `get_next_line_utils.c` | Utility functions |
| `get_next_line.h` | Header file |

---

## Allowed Functions

The project only allows the use of:
- `read`
- `malloc`
- `free`

No standard library string functions are allowed.

---

## Resources

### Documentation

- The Open Group — `read()`:
  https://pubs.opengroup.org/onlinepubs/9699919799/functions/read.html

- Linux manual:
  https://man7.org/linux/man-pages/man2/read.2.html

- Static variables in C:
  https://www.geeksforgeeks.org/static-variables-in-c/

- File descriptors:
  https://en.wikipedia.org/wiki/File_descriptor

---

### Tutorials and References

- 42 GitBook:
  https://harm-smits.github.io/42docs/

- C Memory Management:
  https://www.tutorialspoint.com/cprogramming/c_memory_management.htm

---

## AI Usage

Artificial intelligence tools were used during this project for:
- debugging assistance
- code review
- complexity analysis
- identifying memory management issues
- README formatting and writing support

AI was not used to automatically generate the entire project implementation. The logic, testing, debugging, and final integration were completed manually.

---
