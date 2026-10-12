#include <stdio.h>

int main()
{
    int num, min, max;

    do
    {
        printf("how many numbers do you want to enter: ");
        scanf("%d", &num);
    } while (num <= 0);

    for (int i = 0; i < num; i++)
    {
        int current;
        printf("Enter %d'th number: ", i + 1);
        scanf("%d", &current);

        if (i == 0)
        {
            min = current;
            max = current;
        }
        else
        {
            if (current < min)
                min = current;
            if (current > max)
                max = current;
        }
    }
    printf("The minimum is: %d\n", min);
    printf("The maximum is: %d\n", max);
    return 0;
}