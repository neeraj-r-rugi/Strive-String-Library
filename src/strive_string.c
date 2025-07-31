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