#include <stdio.h>

int main()
{
    /*declaring our values */
    int N;
    int sum = 0;

    /*asking user for input until a positive integer is entered*/
    do
    {
        printf("Enter a positive integer N: ");
        scanf("%d", &N);
    } while (N <= 0);

    /*calculating the sum of first N integers*/
    for (int i = 1; i <= N; i++)
    {
        sum += i;
    }

    /*displaying the result*/
    printf("The sum of the first %d integers is: %d\n", N, sum);

    return 0;
}