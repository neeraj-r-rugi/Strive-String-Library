#include <stdio.h>
#include "strive.h"

int main()
{
    string * text = NULL;
    string_update("I LOVE COCK", text);
    text->data[0] = 'V';
    printf("%s\n%d\n", text->data, (int)text->length);
    string_free(&text);
    return 0;
}