#include <stdio.h>

int memo[46] = {1, 1};

int fib(int n)
{
    if(memo[n] != 0) return memo[n];
    memo[n - 1] = fib(n - 1);
    memo[n - 2] = fib(n - 2);
    return memo[n - 1] + memo[n - 2];
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}
