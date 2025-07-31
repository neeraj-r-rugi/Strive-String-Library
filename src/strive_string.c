#include "strive_string.h"

/*----------------------------------------------------------------------------*/
//Function Definition

void string_init(string ** str){
    *str = (string *) malloc(sizeof(string));
    (*str)->data = NULL;
    (*str)->length = 0;
}

size_t string_length(string * str){
    size_t temp = 0;
    if(!str){
        ERROR_NO = ERR_UNINTIALISED_STR;
        throw_error(ERROR_NO);
    }
    if(!str->data)
    {
        str->length = 0;
        return 0;
    }
    for(; str->data[temp] != str_end; temp++);
    str->length = temp;
    return temp;
}

void string_copy(char * text, string * str) {
    if (!str){
        ERROR_NO = ERR_UNINTIALISED_STR;
        throw_error(ERROR_NO);
    }
    if(!text){
        ERROR_NO = ERR_UNINTIALISED_TEXT;
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

void string_update(char * text, string * str){
    str->data = text;
    string_length(str);
}

void string_free(string ** str){
    if (!*str){
        ERROR_NO = ERR_UNINTIALISED_STR;
        throw_error(ERROR_NO);
    }
    if((*str)->data){
        free((*str)->data);
        (*str)->data = NULL;
    }
    free(*str);
    *str = NULL;
}