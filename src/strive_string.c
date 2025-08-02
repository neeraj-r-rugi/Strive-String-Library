// Copyright (C) 2024 Neeraj R Rugi

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
#include "strive_string.h"

/*----------------------------------------------------------------------------*/
//Function Definition

void string_init(string ** str){
    *str = (string *) malloc(sizeof(string));
    (*str)->data = NULL;
    (*str)->length = 0;
}

size_t string_length(string * str){
    string_enforce_exist(str, false);
    size_t temp = 0;
    if(!str->data)
    {
        str->length = 0;
        return 0;
    }
    for(; str->data[temp] != str_end; temp++);
    str->length = temp;
    return temp;
}



void string_update(char * text, string * str) {
    string_enforce_exist(str, false);
    if(!text){
        ERROR_NO = ERR_UNINITIALISED_TEXT;
        throw_error(ERROR_NO);
    }
    size_t length = strlen(text);
    char * temp = realloc(str->data, (length + 1) * sizeof(char));
    if (temp == NULL) {
        ERROR_NO = ERR_MEM_FAIL;
        throw_error(ERROR_NO);
        return;
    }
    str->data = temp;
    char * dest = str->data;
    while ((*dest++ = *text++) != str_end);
    string_length(str);
}
/*
    !TODO: The current implementation of the:
        -string_printf()
        -string_scanf()
    are not optimal, in-efficient, and possibly unsafe in untested events.
    !Complete refactor from scratch of the 2 functions is to be immediately considered
    Possible fixes:
        -> Use Direct Sysytem Call for file acsses to remove abstraction and overhead
        -> Complete refactored use the current abstractions of the file functions.
    !Ideal Scenario:
        -> func(int count, [string * s1, ...])
                            (or)
        -> func(const char * fomrat, [string * s1, ...])

*/
void string_printf(FILE *out, const char *fmt, ...) {
    if (!fmt) {
        ERROR_NO = ERR_UNINITIALISED_TEXT;
        throw_error(ERROR_NO);
        return;
    }

    va_list args;
    va_start(args, fmt);

    // Calculate required buffer size
    va_list args_copy;
    va_copy(args_copy, args);
    int needed = vsnprintf(NULL, 0, fmt, args_copy);
    va_end(args_copy);

    if (needed < 0) {
        va_end(args);
        ERROR_NO = ERR_MEM_FAIL;
        throw_error(ERROR_NO);
        return;
    }

    // Allocate buffer for formatted string (+1 for null terminator)
    char * buffer = (char *)malloc((size_t)needed + 1);
    if (!buffer) {
        va_end(args);
        ERROR_NO = ERR_MEM_FAIL;
        throw_error(ERROR_NO);
        return;
    }
    if (vsnprintf(buffer, (size_t)needed + 1, fmt, args) < 0) {
        free(buffer);
        va_end(args);
        ERROR_NO = ERR_MEM_FAIL;
        throw_error(ERROR_NO);
        return;
    }
    va_end(args);
    if (!out) out = stdout;
    fwrite(buffer, 1, (size_t)needed, out);
    free(buffer);
}

void string_scanf(string * str, FILE * in,size_t bufsize, const char *fmt, ...) {
    if (!fmt) {
        ERROR_NO = ERR_UNINITIALISED_TEXT;
        throw_error(ERROR_NO);
    }
    string_enforce_exist(str, false);

    va_list args;
    va_start(args, fmt);


    char *buffer = (char *)malloc(bufsize);
    if (!buffer) {
        va_end(args);
        ERROR_NO = ERR_MEM_FAIL;
        throw_error(ERROR_NO);
    }

    if (!in) in = stdin;
    if (!fgets(buffer, (int)bufsize, in)) {
        free(buffer);
        va_end(args);
        ERROR_NO = ERR_FILE;
        throw_error(ERROR_NO);
    }
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    int ret = vsscanf(buffer, fmt, args);
    va_end(args);

    if (ret > 0) {
        string_update(buffer, str);
    }
    free(buffer);
}

void string_concat(string * dest, string * src){
    string_enforce_exist(src, true);
    string_enforce_exist(dest, false);

    size_t dest_len = dest->length;
    size_t src_len = src->length;

    char *temp = realloc(dest->data, (dest_len + src_len + 1) * sizeof(char));
    if (!temp) {
        ERROR_NO = ERR_MEM_FAIL;
        throw_error(ERROR_NO);
        return;
    }
    dest->data = temp;
    memcpy(dest->data + dest_len, src->data, src_len + 1); // +1 to copy null terminator
    dest->length = dest_len + src_len;
}

void string_slice(int start, int end, string * dest, string * src)
{
    string_enforce_exist(src, true);
    string_enforce_exist(dest, false);
    int len = src->length;

    if (start < 0) start += len;
    if (end < 0) end += len;

    if (start < 0) start = 0;
    if (end > len) end = len;
    if (end < start) end = start; 

    int slice_len = end - start;

    char * temp = (char *)malloc((slice_len + 1) * sizeof(char));
    if (!temp) {
        ERROR_NO = ERR_MEM_FAIL;
        throw_error(ERROR_NO);
        return;
    }
    strncpy(temp, src->data + start, slice_len);
    temp[slice_len] = '\0';
    string_update(temp, dest);
    free(temp);
}

void string_copy(string * dest, string * src){
    string_enforce_exist(src, true);
    string_enforce_exist(dest, false);
    string_update(src->data, dest);
}

void string_enforce_exist(string * str, bool check_data){
    if(!str){
        ERROR_NO = ERR_UNINITIALISED_STR;
        info_error("In string_enforce_exist(): str not defined prior.");
        throw_error(ERROR_NO);
    }
    if(check_data){
        if(!str->data){
            ERROR_NO = ERR_UNINITIALISED_DATA;
            info_error("In string_enforce_exist(): str->data not defined prior.");
            throw_error(ERROR_NO);
        }
    }
}


void string_free(string ** str){
    string_enforce_exist(*str, false);
    if((*str)->data){
        free((*str)->data);
        (*str)->data = NULL;
    }
    free(*str);
    *str = NULL;
}