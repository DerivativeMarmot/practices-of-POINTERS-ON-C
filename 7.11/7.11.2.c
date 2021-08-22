#include <stdio.h>

int gcd(int M, int N);
int main(void)
{
    int M = 11;
    int N = 22;
    if (M <= 0 || N <= 0)
        return 0;
    printf("%d\n", gcd(M, N));
    return 0;
}

int gcd(int M, int N)
{
    if (M % N == 0)
        return N;
    else if (M % N > 0)
        return gcd(N, M % N);
}