#include <stdio.h>

int main()
{
    /*declaring our values */
    int a, b;

    /*asking user for input until two positive integers are provided*/
    do
    {
        printf("Enter the first positive integer: ");
        scanf("%d", &a);
        printf("Enter the second positive integer: ");
        scanf("%d", &b);
    } while (a <= 0 || b <= 0);

    /*checking divisibility of a by b then of b by a*/
    if (a % b == 0)
    {
        printf("%d is divisible by %d\n", a, b);
    }
    else if (b % a == 0)
    {
        printf("%d is divisible by %d\n", b, a);
    }
    else
    {
        printf("%d is not divisible by %d\n", a, b);
    }
    return 0;
}