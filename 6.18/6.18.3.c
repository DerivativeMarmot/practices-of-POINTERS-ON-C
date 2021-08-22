#include <stdio.h>

void *reverse_string(char *string);
int main(void)
{
    char source[] = "ABCDEF";
    reverse_string(source);
    puts(source);
    return 0;
}

void *reverse_string(char *string){
    char *head = string;
    char *tail = string;
    int len = 0;
    while (*tail++ != '\0'){
        len++;
    }
    for (int i=0; i<len/2; i++){
        char tmp = *(string + i);
         *(string + i) = *(string + len - i - 1);
         *(string + len - i - 1) = tmp;
    }
}