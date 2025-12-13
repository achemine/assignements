#include <stdio.h>

int main()
{
    int count = 0;
    char N;
    do
    {
        printf("Enter a character: ");
        scanf(" %c", &N);
        while (N != '#')
        {
            printf("%d You entered: %c\n", count, N);
            count++;
            break;
        }
    } while (N != '#');
}