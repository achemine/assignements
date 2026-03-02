#include <stdio.h>
#include <math.h>

//function's prototypes
int pow_of_N(int N, int pow);
int GCD(int a, int b);
int lcm(int a, int b);
int is_prime(int n);
int arr_min(int arr[], int size, int *min);
int arr_max(int arr[], int size, int *max);
void euclidean_division(int a, int b, int *quotient, int *remainder);
void arr_min_and_max(int arr[], int size, int *min, int *max);
double arr_avg(int arr[], int n);
void display_array (int arr [] , int n , int *highlight_idx );
void compute_statistics (int arr [] , int n, int *highlight_idx);

//main code
int main()
{
    int choice;
    do{
        printf ("\n=== Mathematical Functions Library ===\ n") ;
        printf ("1. Integer power \n") ;
        printf ("2. GCD and LCM \n") ;
        printf ("3. Prime checker \n") ;
        printf ("4. Euclidean division \n") ;
        printf ("5. Array statistics \n") ;
        printf ("6. Quadratic equation solver \n");
        printf ("0. Exit \n");
        printf (" Choice : ");
        scanf ("%d", & choice ) ;
    while(choice != 0);
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
int GCD(int a, int b)
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
   return (a * b) / GCD(a, b);
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
void euclidean_division(int a, int b, int *quotient, int *remainder)
{
    *quotient = a / b;
    *remainder = a % b;
}

//phase 2,2
int arr_min(int arr[], int size, int *min)
{
    *min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
    return *min;
}

int arr_max(int arr[], int size, int *max)
{
    *max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
    }
    return *max;
}

void arr_min_and_max(int arr[], int size, int *min, int *max)
{
    arr_min(arr, size, min);
    arr_max(arr, size, max);
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
void display_array (int arr [] , int n , int *highlight_idx )
{
    for (int i = 0; i < n; i++)
    {
        if (i == *highlight_idx)
        {
            printf("[%d] ", arr[i]);
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}



//phase 2,5
void compute_statistics (int arr [] , int n, int *highlight_idx)
{
    int min, max;
    arr_min_and_max(arr, n, &min, &max);
    double avg = arr_avg(arr, n);
    display_array(arr, n, highlight_idx);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("sum: %d\n", arr_avg(arr, n)*n);
    printf("Average: %.2f\n", avg);
}

//phase 3
//phase 3,1
double compute_discr ( double a , double b , double c)
{
    return b * b - 4 * a * c;
}

//phase 3,2
void solve_quadratic ( double a , double b , double c , double *root1 , double *root2, int *num_roots)
{   
    double delta = compute_discr(a, b, c);
    if (delta > 0)
    {
        *root1 = (-b + sqrt(delta)) / (2 * a);
        *root2 = (-b - sqrt(delta)) / (2 * a);
        *num_roots = 2;
    }
    else if (delta == 0)
    {
        *root1 = *root2 = -b / (2 * a);
        *num_roots = 1; 
    }
    else
    {
        *num_roots = 0;
    }
}
