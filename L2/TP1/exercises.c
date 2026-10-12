#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCK_SIZE 1000

long long sequential_search(long long dataset[], long long size, long long target);

long long indexed_sequential_search(
    long long dataset[],
    long long index[],
    long long size,
    long long target);

long long binary_search(long long dataset[], long long size, long long target);

int main(void)
{
    long long N = 10000000LL; // 10 million elements
    long long i;
    long long target;

    // Creating the dataset
    long long *dataset = malloc(N * sizeof(long long));

    if (dataset == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < N; i++)
    {
        dataset[i] = i * 2;
    }

    // Creating the index for indexed sequential search
    long long number_of_blocks = (N + BLOCK_SIZE - 1) / BLOCK_SIZE;

    long long *index = malloc(number_of_blocks * sizeof(long long));

    if (index == NULL)
    {
        printf("Memory allocation failed!\n");
        free(dataset);
        return 1;
    }

    for (i = 0; i < number_of_blocks; i++)
    {
        long long end = (i + 1) * BLOCK_SIZE;

        if (end > N)
        {
            end = N;
        }

        index[i] = dataset[end - 1];
    }

    printf("Enter the number you're searching for: ");

    if (scanf("%lld", &target) != 1)
    {
        printf("Invalid input!\n");
        free(dataset);
        free(index);
        return 1;
    }

    long long result;
    clock_t start_time, end_time;
    double elapsed_time;

    // Sequential search
    start_time = clock();

    result = sequential_search(dataset, N, target);

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Sequential search: Found at index %lld\n", result);
    else
        printf("Sequential search: Target not found\n");

    printf("Sequential search time: %.6f seconds\n\n", elapsed_time);

    // Indexed sequential search
    start_time = clock();

    result = indexed_sequential_search(dataset, index, N, target);

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Indexed sequential search: Found at index %lld\n", result);
    else
        printf("Indexed sequential search: Target not found\n");

    printf("Indexed sequential search time: %.6f seconds\n\n", elapsed_time);

    // Binary search
    start_time = clock();

    result = binary_search(dataset, N, target);

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Binary search: Found at index %lld\n", result);
    else
        printf("Binary search: Target not found\n");

    printf("Binary search time: %.6f seconds\n", elapsed_time);

    // Free allocated memory
    free(dataset);
    free(index);

    return 0;
}

// 1. Sequential search
long long sequential_search(long long dataset[], long long size, long long target)
{
    for (long long i = 0; i < size; i++)
    {
        if (dataset[i] == target)
        {
            return i;
        }
    }

    return -1;
}

// 2. Indexed sequential search
long long indexed_sequential_search(
    long long dataset[],
    long long index[],
    long long size,
    long long target)
{
    long long number_of_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    long long block = 0;

    // Find the block that may contain the target
    while (block < number_of_blocks && index[block] < target)
    {
        block++;
    }

    if (block == number_of_blocks)
    {
        return -1;
    }

    // Search sequentially inside that block
    long long start = block * BLOCK_SIZE;
    long long end = start + BLOCK_SIZE;

    if (end > size)
    {
        end = size;
    }

    for (long long i = start; i < end; i++)
    {
        if (dataset[i] == target)
        {
            return i;
        }

        if (dataset[i] > target)
        {
            return -1;
        }
    }

    return -1;
}

// 3. Binary search
long long binary_search(long long dataset[], long long size, long long target)
{
    long long left = 0;
    long long right = size - 1;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (dataset[mid] == target)
        {
            return mid;
        }
        else if (dataset[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}