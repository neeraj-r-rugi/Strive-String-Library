#include <stdio.h>
#include "strive.h"

int main()
{
    int x = 10;
    string * text = NULL;

    string_init(&text);
    string_update("I LOVE STRIVE", text);

    string_printf(stdout, "%s\n%d\n", text->data, x);
    printf("%s\n%d\n", text->data, x);

    string_scanf(text, stdin, 1024, "%s", text->data);
    string_printf(NULL, "%s\n", text->data);
    string_free(&text);
    return 0;
}