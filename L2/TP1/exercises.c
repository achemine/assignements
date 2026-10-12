#include <stdio.h>
#include <time.h>

int sequential_search(int dataset[], int size, int target);
int indexed_sequential_search(int dataset[], int size, int target);
int binary_search(int dataset[], int size, int target);

int main()
{
    int N = 10;
    int dataset[N];
    int i;
    int target;
    // creating the dataset
    clock_t start_time = clock();
    for (i = 0; i < N; i++)
    {
        dataset[i] = i * 2;
    }
    printf("enter the number you're searching for: ");
    scanf("%d", &target);

    // processing the dataset
    start_time = clock();
    sequential_search(dataset, N, target);
    clock_t end_time = clock();
    double sequential_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Sequential search time: %f seconds\n", sequential_time);

    start_time = clock();
    indexed_sequential_search(dataset, N, target);
    end_time = clock();
    double indexed_sequential_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Indexed sequential search time: %f seconds\n", indexed_sequential_time);

    start_time = clock();
    binary_search(dataset, N, target);
    end_time = clock();
    double binary_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Binary search time: %f seconds\n", binary_time);
    return 0;
}

int sequential_search(int dataset[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (dataset[i] == target)
        {
            return i; // Return the index of the target
        }
    }
    return -1; // Target not found
}

int indexed_sequential_search(int dataset[], int size, int target)
{
    // This function is not implemented yet
    return -1; // Placeholder return value
}

int binary_search(int dataset[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (dataset[mid] == target)
        {
            return mid; // Target found
        }
        else if (dataset[mid] < target)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}