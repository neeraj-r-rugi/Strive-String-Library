#include <stdio.h>
#include "strive.h"

int main()
{
    string * text;
    string_init(&text);
    string_copy("LMFAO", text);
    text->data[0] = 'V';
    printf("%s\n%d", text->data, text->length);
    string_free(&text);
    return 0;
}