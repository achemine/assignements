#include <stdio.h>

int main()
{
    int n, x;
    float result ;

    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter the exponent: ");
    scanf("%d", &x);

    for (int fac = 1; fac <= n-1 ; fac++) {
        fac *= (fac + 1);
        
    }
    

    return 0;
}