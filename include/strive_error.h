#ifndef STRIVE_ERROR_H
#define STRIVE_ERROR_H
//System Headers
#include<stdio.h>

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