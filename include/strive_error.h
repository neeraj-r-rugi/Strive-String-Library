#ifndef STRIVE_ERROR_H
#define STRIVE_ERROR_H
// Library Header File Inclusion
#include "strive_numerals.h"

// Global Program ERROR CODE
extern ui8 ERROR_NO;

// Error Codes:
typedef enum ErrorCode error_code;
enum ErrorCode
{
    ERR_OK,
    ERR_MEM_FAIL,
    ERR_UNINTIALISED_STR,
    ERR_UNINTIALISED_TEXT,
    ERR_UNKOWN
};

/*----------------------------------------------------------------------------------------*/
//Function Declarations

const char * get_error(error_code);

void throw_error(error_code); 

#endif