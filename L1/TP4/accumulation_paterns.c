#include <stdio.h>

int main()
{
    int  N, arr[100], min, max, sum, max_index;
    float avg;

    //getting the array size from user
    do{
        printf("Enter a positive integer N: ");
        scanf("%d", &N);
    } while (N <= 0 && N <= 100);

    //filling the array with user input
    for(int i = 0; i < N; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    //calculating various data
    min = arr[0];
    max = arr[0];

    for(int i = 0; i < N; i++){
        if(arr[i] <= min){
            min = arr[i];
        }
        if(arr[i] >= max){
            max = arr[i];
            max_index = i;
        }
        sum += arr[i];
        avg = (float)sum / N;
    }
    //printing the results
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Index of Maximum: %d\n", max_index);   
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);
    
    return 0;
}