#include <stdio.h>

char *find_char(char const *source, char const *chars);
int main(void)
{
    char const *source = "ABCDEF", *chars = "XR";
    char *result = find_char(source, chars);
    puts(result);
    return 0;
}

char *find_char(const char *source, char const *chars)
{
    for (char *cp = &chars[0]; *cp != '\0'; cp++)
    {
        for (char *sp = &source[0]; *sp != '\0'; sp++)
        {
            if (*cp == *sp)
                return sp;
        }
    }
    return "NULL";
}

void test_1()
{
    char const *temp = "hello";
    while (*temp != '\0')
    {
        putchar(*temp++);
    }
}