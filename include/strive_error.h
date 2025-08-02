// Copyright (C) 2024 Neeraj R Rugi

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
#ifndef STRIVE_ERROR_H
#define STRIVE_ERROR_H
//System Headers
#include<stdio.h>
#include<stdlib.h>

// Library Header File Inclusion


// Global Program ERROR CODE
extern int ERROR_NO;

// Error Codes:
typedef enum ErrorCode error_code;
enum ErrorCode
{
    ERR_OK = 0,
    ERR_MEM_FAIL,
    ERR_UNINITIALISED_STR,
    ERR_UNINITIALISED_TEXT,
    ERR_UNINITIALISED_DATA,
    ERR_FILE,
    ERR_UNKNOWN
};

/*----------------------------------------------------------------------------------------*/
//Function Declarations

void throw_error_impl(error_code code, const char *file, int line, const char *func);

// Macro to auto-insert file, line, and function info
#define throw_error(code) throw_error_impl(code, __FILE__, __LINE__, __func__)

void info_error(char * text);

#endif