#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    /*declaring our value */
    int N;
    bool is_prime = 1;

    /*asking user for input until a positive integer is provided*/
    do
    {
        printf("Enter a positive integer N: ");
        scanf("%d", &N);
    } while (N <= 1);

    /*searching then displaying divisors of N*/
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            is_prime = 0;
            break;
        }
    }
    if (is_prime)
        printf("%d is a prime number\n", N);
    else
        printf("%d is not a prime number\n", N);
    return 0;
}