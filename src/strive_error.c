#include "strive_error.h"

// Set Global Variable.
ui8 ERROR_NO = 0;

/*----------------------------------------------------------------------------*/
const char * get_error(error_code code){
    switch (code)
    {
        case ERR_OK:        return "No Errors.";
        case ERR_MEM_FAIL:  return "Failed to allocate memory on the HEAP";
        case ERR_UNINTIALISED_STR: return "Struct String Uninitialised.";
        case ERR_UNINTIALISED_TEXT: return "Text Input is either blank or uninitialsied.";
        case ERR_UNKOWN:    return "Unkown Error Occured";
        default: return "Error Un-defined";
    }
}

void throw_error(error_code code){
    printf("Fatal Error Occured: %s\n", get_error(code));
    exit(0);
}