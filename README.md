# Strive String Library

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![C Standard](https://img.shields.io/badge/C-C99-brightgreen.svg)]()
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)]()

A lightweight, feature-rich C string handling library designed for safe and efficient string operations with comprehensive error management. A humble student project aimed at enhancing C's string handling capabilities.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Quick Start](#quick-start)
- [API Reference](#api-reference)
  - [Core Functions](#core-functions)
  - [Advanced Operations](#advanced-operations)
  - [I/O Functions](#io-functions)
  - [Error Handling](#error-handling)
- [Usage Examples](#usage-examples)
- [Error Codes](#error-codes)
- [Memory Management](#memory-management)
- [Building](#building)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)
- [Changelog](#changelog)
- [Support](#support)

## Overview

The `String Variable Extended` [STRIVE] Library is a student project designed to provide a robust alternative to C's native string handling. Developed as a learning exercise in systems programming, memory management, and API design, this library offers automatic memory management, comprehensive error checking, and a rich set of string manipulation functions.
While created by a student for educational purposes, the library is designed with real-world safety and performance considerations in mind, demonstrating practical applications of C programming concepts and best practices.


### Key Benefits

- **Memory Safety**: Automatic memory allocation and deallocation
- **Error Resilience**: Comprehensive error handling with detailed diagnostics
- **Performance**: Optimized operations with minimal overhead
- **Flexibility**: Support for various string operations and I/O functions
- **Portability**: Standard C99 compatible

## Features

### 🔧 Core String Operations
- Dynamic string initialization and management
- Safe string copying and updating
- Automatic length calculation and tracking
- Memory-safe concatenation

### 🎯 Advanced Functionality
- String slicing with negative index support
- Printf-style formatted string creation
- Scanf-style string parsing from files/stdin
- Comprehensive bounds checking

### 🛡️ Safety & Error Handling
- Built-in error detection and reporting
- Colored terminal error messages
- Automatic memory leak prevention
- Null pointer protection

### 📊 I/O Operations
- File and standard I/O integration
- Buffered input/output operations
- Custom format string support

## Installation

### Prerequisites
- GCC or compatible C compiler
- Standard C library
- Make (optional, for building)

### Download and Setup

```bash
# Clone the repository
git clone https://github.com/yourusername/strive-string-library.git
cd strive-string-library

# Or download and extract the source files
# Include strive.h in your project
```

### Integration

Simply include the header in your C project:

```c
#include "strive.h"
```

## Quick Start

Here's a simple example to get you started:

```c
#include "strive.h"

int main() {
    string *my_string;
    
    // Initialize the string
    string_init(&my_string);
    
    // Update with content
    string_update("Hello, World!", my_string);
    
    // Print the string
    printf("String: %s (Length: %zu)\n", my_string->data, my_string->length);
    
    // Clean up
    string_free(&my_string);
    
    return 0;
}
```

## API Reference

### Core Functions

#### `void string_init(string **str)`
Initializes a new string object with allocated memory.

**Parameters:**
- `str`: Double pointer to string structure

**Example:**
```c
string *my_str;
string_init(&my_str);
```

#### `void string_update(char *text, string *str)`
Updates the string with new content, automatically managing memory.

**Parameters:**
- `text`: Source C-string to copy
- `str`: Target string structure

#### `size_t string_length(string *str)`
Calculates and returns the current length of the string.

**Returns:** Length of the string as `size_t`

#### `void string_free(string **str)`
Safely deallocates string memory and sets pointer to NULL.

### Advanced Operations

#### `void string_concat(string *dest, string *src)`
Concatenates source string to destination string.

**Parameters:**
- `dest`: Destination string (will be modified)
- `src`: Source string to append

#### `void string_slice(int start, int end, string *dest, string *src)`
Extracts a substring from source to destination.

**Parameters:**
- `start`: Start index (supports negative indexing)
- `end`: End index (exclusive, supports negative indexing)
- `dest`: Destination string for the slice
- `src`: Source string

**Example:**
```c
string *original, *slice;
string_init(&original);
string_init(&slice);
string_update("Hello World", original);
string_slice(0, 5, slice, original); // Result: "Hello"
```

#### `void string_copy(string *dest, string *src)`
Creates a complete copy of the source string.

### I/O Functions

#### `void string_printf(string *str, FILE *out, const char *fmt, ...)`
Formats string using printf-style formatting and optionally outputs to file.

**Parameters:**
- `str`: String to store formatted result
- `out`: Output stream (NULL for stdout)
- `fmt`: Format string
- `...`: Variable arguments

#### `void string_scanf(string *str, FILE *in, size_t bufsize, const char *fmt, ...)`
Reads and parses input from stream into string.

**Parameters:**
- `str`: String to store parsed result
- `in`: Input stream (NULL for stdin)
- `bufsize`: Input buffer size
- `fmt`: Format string
- `...`: Variable arguments for parsing

### Error Handling

#### `void string_enforce_exist(string *str, bool check_data)`
Validates string existence and optionally data initialization.

**Parameters:**
- `str`: String to validate
- `check_data`: Whether to check data pointer validity

## Usage Examples

### Basic String Operations

```c
#include "strive.h"

int main() {
    string *str1, *str2, *result;
    
    // Initialize strings
    string_init(&str1);
    string_init(&str2);
    string_init(&result);
    
    // Set content
    string_update("Hello", str1);
    string_update(" World!", str2);
    
    // Copy and concatenate
    string_copy(result, str1);
    string_concat(result, str2);
    
    printf("Result: %s\n", result->data);  // Output: "Hello World!"
    
    // Cleanup
    string_free(&str1);
    string_free(&str2);
    string_free(&result);
    
    return 0;
}
```

### String Slicing

```c
string *original, *slice;
string_init(&original);
string_init(&slice);

string_update("Programming", original);
string_slice(0, 7, slice, original);  // "Program"
printf("Slice: %s\n", slice->data);

// Negative indexing
string_slice(-3, -1, slice, original);  // "in"
printf("Negative slice: %s\n", slice->data);
```

### Formatted I/O

```c
string *formatted;
string_init(&formatted);

// Create formatted string
string_printf(formatted, NULL, "User: %s, Age: %d, Score: %.2f", 
              "Alice", 25, 95.7);

// Read from user input
string_scanf(formatted, NULL, 256, "%s", &user_input);
```

## Error Codes

| Code | Description |
|------|-------------|
| `ERR_OK` | No errors occurred |
| `ERR_MEM_FAIL` | Memory allocation failed |
| `ERR_UNINITIALISED_STR` | String structure not initialized |
| `ERR_UNINITIALISED_TEXT` | Input text is NULL or uninitialized |
| `ERR_UNINITIALISED_DATA` | String data not initialized |
| `ERR_FILE` | File operation error |
| `ERR_UNKNOWN` | Unknown error occurred |

## Memory Management

The library handles memory management automatically:

- **Automatic Allocation**: Memory is allocated when needed
- **Safe Reallocation**: Dynamic resizing for string operations
- **Leak Prevention**: Proper cleanup with `string_free()`
- **Error Recovery**: Memory is freed even on error conditions

### Best Practices

1. Always call `string_init()` before using a string
2. Always call `string_free()` when done with a string
3. Check for errors using the global `ERROR_NO` variable
4. Use `string_enforce_exist()` for additional safety checks

## Building

### Manual Compilation

```bash
gcc -std=c99 -Wall -Wextra -o your_program your_program.c strive_string.c strive_error.c
```

### With Makefile

```makefile
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -O2
SOURCES=strive_string.c strive_error.c
HEADERS=strive.h strive_string.h strive_error.h

your_program: your_program.c $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ your_program.c $(SOURCES)

clean:
	rm -f your_program
```

## Testing

The library includes comprehensive error checking and validation. To test your implementation:

1. Test with NULL pointers
2. Test memory allocation failures
3. Test boundary conditions (empty strings, large strings)
4. Test all string operations
5. Verify proper memory cleanup

## Contributing

We welcome contributions! Please follow these guidelines:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

### Code Style
- Follow K&R C style
- Use meaningful variable names
- Add comprehensive comments
- Include error handling
- Test thoroughly

### Reporting Issues
Please use the GitHub issue tracker to report bugs or request features.

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

```
Copyright (C) 2024 Neeraj R Rugi

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
```

## Changelog

### Version 1.0.0 (Current)
- Initial release
- Core string operations
- Memory management
- Error handling system
- I/O functions
- String slicing and manipulation

## Support

- **Documentation**: Check this README and inline code documentation
- **Issues**: [GitHub Issues](https://github.com/yourusername/strive-string-library/issues)
- **Discussions**: [GitHub Discussions](https://github.com/yourusername/strive-string-library/discussions)


---
*Strive for better string handling in C*