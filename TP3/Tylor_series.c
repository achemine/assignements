#include <stdio.h>
#include <math.h>

int main()
{
    // Variables declaration
    int n, x, i = 1;
    double result = 1.0, factorial = 1;

    // getting user input and verifying it
    do{
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter the exponent: ");
    scanf("%d", &x);
    } while (n <= 0);

    // Calculating the Taylor series
    do {
        result += pow(x, i) / (factorial*=i);
        i++;
    } while (i < n);

    // Displaying the result
    printf("The Taylor series result is: %.15lf\n", result);
    return 0;
}