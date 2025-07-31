#ifndef STRIVE_STRING_H
#define STRIVE_STRING_H

//System Headers
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

void string_enforce_exist(string * str, bool check_data);

/**
 * @brief Frees the memory allocated for the string object.
 * 
 * Frees both the data and the structure itself, and sets the pointer to NULL.
 * 
 * @param str Double pointer to the string structure to be freed.
 */
void string_free(string ** str);






#endif