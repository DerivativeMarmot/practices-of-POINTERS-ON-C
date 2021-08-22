#include <stdio.h>
#include <stdbool.h>

int del_substr(char *str, char *substr);
int main(void)
{
    char str[] = "ABCDEFGf", substr[] = "CDE";
    int result = del_substr(str, substr);
    printf("%d\n", result);
    puts(str);
    return 0;
}

int del_substr(char *str, char *substr)
{
    char *temp;
    while (*str != '\0'){
        if (*str == *substr){
            temp = str;
            while (*substr != '\0'){
                if (*str++ != *substr++){
                    return 0;
                }
            }
            if (*substr == '\0'){
                while (*str != '\0'){
                    *temp++ = *str++;
                }
                *temp = '\0';
                return 1;
            }
        }
        str++;
    }
    return 0;
}