// Copyright (C) 2024 Neeraj R Rugi

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
#ifndef STRIVE_STRING_H
#define STRIVE_STRING_H

//System Headers
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
//Frameworks inclusion.
#include "strive_error.h"

//Defines
#define str_end '\0'

//structure declaration
typedef struct String string;
struct String
{
    char * data;
    size_t length;
};
/*----------------------------------------------------------------------------*/
// Function definitions

/**
 * @brief Initializes a string object.
 * 
 * Allocates memory for a string structure and sets its data pointer to NULL and length to 0.
 * 
 * @param str Double pointer to a string structure to be initialized.
 */
void string_init(string ** str);

/**
 * @brief Copies a C-string into the string object.
 * 
 * Allocates/reallocates memory for the string data and copies the provided text.
 * Updates the length of the string.
 * 
 * @param text The source C-string to copy from.
 * @param str Pointer to the string structure to copy into.
 */
void string_update(char * text, string * str);


/**
 * @brief Calculates and updates the length of the string.
 * 
 * Returns the length of the string and updates the length field in the structure.
 * 
 * @param str Pointer to the string structure.
 * @return size_t The length of the string.
 */
size_t string_length(string * str);

/**
 * @brief Ensures that the string object (and optionally its data) exists.
 *
 * Checks if the string pointer is not NULL. If check_data is true, also checks if the data pointer is not NULL.
 * Throws an error if the checks fail.
 *
 * @param str Pointer to the string structure to check.
 * @param check_data If true, also check that str->data is not NULL.
 */
void string_enforce_exist(string * str, bool check_data);

/**
 * @brief Extracts a substring (slice) from the source string.
 *
 * Copies the substring from index start (inclusive) to end (exclusive) from src into dest.
 * Supports negative indices for start and end (relative to the end of the string).
 *
 * @param start Start index of the slice (can be negative).
 * @param end End index of the slice (can be negative).
 * @param dest Pointer to the destination string structure.
 * @param src Pointer to the source string structure.
 */
void string_slice(int start, int end, string * dest, string * src);

/**
 * @brief Concatenates the source string to the destination string.
 *
 * Appends the contents of src to the end of dest, reallocating memory as needed.
 *
 * @param dest Pointer to the destination string structure.
 * @param src Pointer to the source string structure.
 */
void string_concat(string * dest, string * src);

/**
 * @brief Formats and writes a string to a string object and optionally to a file.
 *
 * Formats a string using printf-style formatting, updates the string object, and writes the result to the specified output stream.
 *
 * @param str Pointer to the string structure to update.
 * @param out Output file stream (if NULL, writes to stdout).
 * @param fmt Format string (as in printf).
 * @param ... Additional arguments for formatting.
 */
void string_printf(string *str, FILE *out, const char *fmt, ...);

/**
 * @brief Reads and parses input from a file stream into a string object.
 *
 * Reads a line from the input stream, parses it according to the format string, and updates the string object.
 *
 * @param str Pointer to the string structure to update.
 * @param in Input file stream (if NULL, reads from stdin).
 * @param bufsize Size of the input buffer to use.
 * @param fmt Format string (as in scanf).
 * @param ... Additional arguments for parsing.
 */
void string_scanf(string * str, FILE * in, size_t bufsize, const char *fmt, ...);

/**
 * @brief Frees the memory allocated for the string object.
 * 
 * Frees both the data and the structure itself, and sets the pointer to NULL.
 * 
 * @param str Double pointer to the string structure to be freed.
 */
void string_free(string ** str);






#endif