# 📄 get_next_line

A 42 School project that implements a function to read from a file descriptor **one line at a time**.  
Each call to `get_next_line()` returns the next line until the end of file or an error occurs.  
This project focuses on **file I/O**, **buffer management**, and **dynamic memory allocation** in C.

---

## 📜 Function Overview — `get_next_line`

char *get_next_line(int fd);
Description
Reads from an open file descriptor and returns the next line, including the newline character \n if present.
Intended for text files — behavior is undefined for binary files.

Parameters

fd: Open file descriptor to read from.

Return Value

On success: A newly allocated string containing the next line.

On EOF or error: NULL.
## To compile
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o gnl_test

## File Structure:
./n
├── get_next_line.c  
├── get_next_line_utils.c  
├── get_next_line.h  
├── main.c # Optional test file  
└── README.md /n  




