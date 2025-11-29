#include <stdio.h>
#include <math.h>

int main()
{
    const float epsilon = 0.0001;
    float A;
    float Un, Un1;
    int pointeur = 0;
    // Getting user input
    printf("Enter the value of A: ");
    scanf("%f", &A);

    // Initial term of the sequence
    Un = A;
    Un1 = (Un + (A / Un)) / 2;
    while ( fabs(Un1 - Un) < epsilon) 
    {   
        Un1 = (Un + (A / Un)) / 2;
        Un = Un1;
        printf("iteration %d: %f\n", pointeur, Un);
        pointeur++;
    }
    printf(" converged after %d iterations\n", pointeur);
    printf("the square root of %d is approximately: %f\n", A, Un1);
    return 0; 
}