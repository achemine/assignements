#include <stdio.h>

//function's prototypes
int pow_of_N(int N, int pow);
int pgcd(int a, int b);
int lcm(int a, int b);
int is_prime(int n);

//main code
int main()
{;
    int N, pow, a, b;
    //phase 1
    //getting user input for phase 1.1
    do
    {
        printf("Enter an integer N and his exponent: ");
        scanf("%d %d", &N, &pow);
    } while ( pow < 0);
    do
    {
        printf("Enter two positive integers a and b: ");
        scanf("%d %d", &a , &b);
    } while (a <= 0 || b <= 0);
    do
    {
        printf("Enter a positive integer n: ");
        scanf("%d", &n);
    } while (n <= 0);
    

        //displaying results for phase 1
    printf("%d to the power of %d is: %d\n", N, pow, pow_of_N(N, pow));
    printf("the greatest common divisor of %d and %d is: %d\n", a, b, pgcd(a, b));
    printf("the least common multiple of %d and %d is: %d\n", a, b, lcm(a, b));
    printf("%d is %s prime number\n", n, is_prime(n) ? "a" : "not a");

    
    //phase 2
    return 0;
}

//function's definitions:
//phase 1,1
int pow_of_N(int N, int pow)
{   
    int result = 1;
    for (int i = 0; i < pow; i++)
    {
       result *= N;
    }
    return result;
}


//phase 1,2 
int pgcd(int a, int b)
{

    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

int lcm(int a, int b)
{
   return (a * b) / pgcd(a, b);
}

//phase 1.3
int is_prime(int n)
{
    if (n <= 2 && n >= 0)
    {
        return 1;
    }
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

//phase 2
void euclidean_devision(int a, int b, int *quotient, int *remainder)
{
    *quotient = a / b;
    *remainder = a % b;
}

//phase 2,2
void arr_min_max(int arr[], int size, int *min, int *max)
{
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
    }
}

//phase 2,3
double arr_avg(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return (double)sum / n;
}

//phase 2,4
//phase 2,5