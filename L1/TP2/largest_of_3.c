#include <stdio.h>

int main()
{
    /*we declare 3 variables to store the numbers the user will enter*/
    float num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    /*we use if statments to find the largest number among the three entered numbers*/
    if (num1 >= num2 && num1 >= num3)
    {
        printf("The largest number is: %.2f", num1);
    }
    else if (num2 >= num1 && num2 >= num3)
    {
        printf("The largest number is: %.2f", num2);
    }
    else
    {
        printf("The largest number is: %.2f", num3);
    }
}