#include "strive_error.h"

// Set Global Variable.
int ERROR_NO = 0;

/*----------------------------------------------------------------------------*/
const char *get_error(error_code code)
{
    switch (code)
    {
    case ERR_OK:
        return "No errors.";
    case ERR_MEM_FAIL:
        return "Failed to allocate memory on the heap.";
    case ERR_UNINITIALISED_STR:
        return "Struct `string` is uninitialised.";
    case ERR_UNINITIALISED_TEXT:
        return "Text input is blank or uninitialised.";
    case ERR_UNINITIALISED_DATA:
        return "No string data in the struct to process.";
    case ERR_FILE:
        return "An Error Ocuured when reading the file or with the file system.";
    case ERR_UNKNOWN:
        return "Unknown error occurred.";
    default:
        return "Error undefined.";
    }
}


void throw_error_impl(error_code code, const char *file, int line, const char *func)
{
    fprintf(stderr,
            "\033[1;31m[FATAL ERROR]\033[0m %s\n"
            "  \033[1;33mFile:\033[0m %s\n"
            "  \033[1;33mLine:\033[0m %d\n"
            "  \033[1;33mFunction:\033[0m %s\n",
            get_error(code), file, line, func);

    fprintf(stderr, "\nProgram aborted.\n");
    exit(1); 
}

void info_error(char * text)
{
    printf("\033[1;31m[FATAL Interupt]\033[0m %s\n", text);
}