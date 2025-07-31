#ifndef STRIVE_STRING_H
#define STRIVE_STRING_H

//System Headers
#include <stdlib.h>
#include <string.h>

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
//Function defintions
void string_init(string ** str);

void string_copy(char * text, string * str);

void string_update(char * text, string * str);

size_t string_length(string * str);

void string_free(string ** str);






#endif