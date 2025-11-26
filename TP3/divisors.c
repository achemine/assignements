#include <stdio.h>

int main()
{
    /*declaring our value */
    int N;

    /*asking user for input until a positive integer is provided*/
    do
    {
        printf("Enter a positive integer N: ");
        scanf("%d", &N);
    } while (N <= 0);

    printf("All The divisors of %d are: ", N);
    /*searching then displaying divisors of N*/
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}