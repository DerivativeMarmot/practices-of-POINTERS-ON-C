#include <stdio.h>
#include <stdarg.h>

int max_list(int n_values, ...);
int main(void){
    printf("%d\n", max_list(3, 11, 20, -4));
    printf("%d\n", max_list(5, 11, 20, 4, 100, -69));
    printf("%d\n", max_list(6, 11, 20, 4, 54, 33, -98));
    return 0;
}

int max_list(int n_values, ...){
    va_list var_arg;

    va_start(var_arg, n_values);
    int MAX = va_arg(var_arg, int);
    int current = MAX;
    while (current > 0){
        if (MAX < current)
            MAX = current;
        current = va_arg(var_arg, int);
    }
    va_end(var_arg);
    return MAX;
}
