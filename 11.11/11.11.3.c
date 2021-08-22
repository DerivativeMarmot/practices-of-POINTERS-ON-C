#include <stdio.h>
#include <stdlib.h>

char *cpystr(char *cpy_string, char *curp, char ch, int size);
int main(void)
{
    char ch;
    int size = 2;
    char *cpy_string;
    cpy_string = malloc(size * sizeof(int));
    char *curp = cpy_string;
    while ((ch = getchar()) != '\n')
    {
        cpystr(cpy_string, curp, ch, size);
        curp++;
        size++;
    }
    *curp = '\0';
    puts(cpy_string);
    free(cpy_string);
    return 0;
}

char *cpystr(char *cpy_string, char *curp, char ch, int size)
{
    cpy_string = realloc(cpy_string, size * sizeof(int));
    *curp = ch;
}