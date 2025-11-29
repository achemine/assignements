#include <stdio.h>
#include <math.h>

int main()
{
    const float epsilon = 0.0001;
    float A;
    float Un, Un1;
    int pointer = 0;

    // Getting user input
    do
    {
        printf("Enter the value of A: ");
        scanf("%f", &A);
    } while (A <= 0);

    // Initial term of the sequence
    Un = A;
    Un1 = (Un + (A / Un)) / 2;
    printf("iteration %d: %f\n", pointer, Un);
    while (fabs(Un1 - Un) > epsilon)
    {
        pointer++;
        printf("iteration %d: %f\n", pointer, Un1);

        Un = Un1;
        Un1 = (Un + (A / Un)) / 2;
    }
    pointer++;
    printf("iteration %d: %f\n", pointer, Un1);
    printf("the square root of %f is approximately: %f\n", A, Un1);
    return 0;
}