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
    } while (N <= 0 );

    /*printing the star pattern using nested loops*/
    /*outer loop for each row*/
    for (int i = 1; i <= N; i++)
    {
        /*printing stars for each row*/
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("_________________optional challenge 1______________________\n");

    /*optional chalenge 1*/
    for (int i = 1; i <= N; i++)
    {
        /*printing stars for each row*/
        for (int j = (N - i + 1); j > 0; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("_________________optional challenge 2______________________\n");
    /*optional chalenge 2*/
    char space = ' ';
    for (int i = 1; i <= N; i++)
    {
        /*printing stars and spaces to center each row*/
        for (int j = (N - i + 1); j > 0; j--)
        {
            printf("%c", space);
        }
        for (int j = 1; j <= i; j++)
        {
            printf("**");
        }
        printf("\n");
    }

    printf("_________________optional challenge 3______________________\n");
    /*optional chalenge 3*/
    for (int row = 1; row <= N; ++row)
    {
        for (int col = 1; col <= N; ++col)
        {
            // Print star on borders, space inside
            if (row == 1 || row == N)
                printf("*"), printf("  ");
            else if (col == 1)
                printf("*");
            else if (col == N)
                printf("  "), printf("*");
            else
                printf("   ");
        }
        printf("\n");
    }
    return 0;
}