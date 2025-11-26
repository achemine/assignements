#include <stdio.h>

int main()
{
    float x, y, z;
    printf("Please enter your three values: ");
    if (scanf("%f %f %f", &x, &y, &z) == 3)
    {
        printf("the average of these 3 values is: %f\n", (x + y + z) / 3);
    }
    else
    {
        printf("Invalid input! please try again with valid values. ");
    }

    return 0;
}