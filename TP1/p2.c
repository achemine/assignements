#include <stdio.h>

int main()
{
    float a;
    printf("Please enter the temperature in Celsius: ");
    if (scanf("%f", &a) == 1)
    {
        printf("The temperature in Fahrenheit is: %.2f ", (a * 9/5) + 32);
    }
    else
    {
        printf("Invalid input! please try again with a valid number. ");
    }

    return 0;
}