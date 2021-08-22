#include <stdio.h>

int ascii_to_integer(char *string);
int main(void){
    char const *string = "114514";
    printf("%d\n", ascii_to_integer(string));
    return 0;
}

int ascii_to_integer(char *string){
    int num = 0;
    while (*string != '\0'){
        num *= 10;
        num += *string - 48;
        string++;
    }
    return num;
}