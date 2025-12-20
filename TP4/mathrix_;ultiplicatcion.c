#include <stdio.h>

int main()
{
    int A[10][10], B[10][10], C[10][10];
    int rowA, colA, rowB, colB;

    // Getting dimensions for matrix A
    printf("Enter number of rows for Matrix A (max 10): ");
    scanf("%d", &rowA);
    printf("Enter number of columns for Matrix A (max 10): ");
    scanf("%d", &colA);

    // Getting dimensions for matrix B
    printf("Enter number of rows for Matrix B (max 10): ");
    scanf("%d", &rowB);
    printf("Enter number of columns for Matrix B (max 10): ");
    scanf("%d", &colB);

    // Check if multiplication is possible
    if (colA != rowB) {
        printf("Matrix multiplication not possible with given dimensions.\n");
        return 1;
    }

    // Input elements for matrix A
    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Input elements for matrix B
    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Initializing matrix C to zero
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            C[i][j] = 0;
        }
    }

    // Performing matrix multiplication
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            for (int k = 0; k < colA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    // Displaying the result matrix C
    printf("Result Matrix C:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}