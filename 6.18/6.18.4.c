#include <stdio.h>
#include <math.h>

void find_prime(int number_list[], int UPPER_BOUND);
int main(void)
{
    int UPPER_BOUND = 3998;
    int amt = 0;
    int number_list[UPPER_BOUND];

    for (int i = 0; i < UPPER_BOUND; i++)
        number_list[i] = 1;
    
    find_prime(number_list, UPPER_BOUND);
    for (int i = 0; i < UPPER_BOUND; i++)
    {
        if (*(number_list + i)){
            amt++;
            printf("%d ", i + 2);
            if (amt % 5 == 0)
                puts("");
        }
    }
    printf("\ntotal prime: %d\n", amt);
    return 0;
}

void find_prime(int number_list[], int UPPER_BOUND)
{
    for (int i = 0; i < UPPER_BOUND; i++)
    {
        if (*(number_list + i))
        {
            int divisor = i + 2;
            int dividend = divisor + 1;
            while (dividend < UPPER_BOUND + 2){
                if (dividend % divisor == 0){
                    *(number_list + dividend - 2) = 0;
                }
                dividend++;
            }
        }
    }
    puts("finished\n");
}