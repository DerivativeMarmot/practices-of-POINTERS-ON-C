#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int is_not_print(int ch)
{
    return !isprint(ch);
}

static int (*test_func[])(int) = {
    iscntrl,
    isspace,
    isdigit,
    islower,
    isupper,
    ispunct,
    is_not_print};

#define N_CATEGORIES (sizeof(test_func) / sizeof(test_func[0]))

char *label[] = {
    "control",
    "whitespace",
    "digit",
    "lower case",
    "upper case",
    "punctuation",
    "non-printable"};

int main(void)
{
    printf("%d\n", N_CATEGORIES);
    int count[N_CATEGORIES] = {0};
    int total;
    int ch;
    while ((ch = getchar()) != EOF)
    {
        total++;
        for (int cate = 0; cate < N_CATEGORIES; cate++)
        {
            if (test_func[cate](ch)){
                count[cate]++;
            }  
        }
    }
    printf("%d\n", total);
    if (total == 0)
    {
        puts("no chars in the input");
    }
    else
    {
        for (int cate = 0; cate < N_CATEGORIES; cate++)
        {
            printf("%d %3.1f%% %s chars\n", count[cate], count[cate]/(float)(total)*100, label[cate]);
        }
    }
    return 0;
}