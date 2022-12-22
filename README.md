# Getnextline

Function that reads from a file descriptor

## Description

Reads from a file descriptor until it encounters a newline characters or EOF and returns the line including the newline character. If there is nothing to read
it returns null.

Prototype:
char *
get_next_line(int fd);

## Getting Started

Simply use make all to compile. Gives a static library file.

### Dependencies

Coded on and for macOS x86_64. Works fine on arm64 to my knowledge

### Executing program

Simply compile with a main of your choice and the static library file to use the function.

## Authors

Yannick St-laurent
yan_1731@hotmail.com
