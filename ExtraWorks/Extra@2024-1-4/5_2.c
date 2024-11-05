#include <stdio.h>
#include <stdlib.h>

void matrixMultiplication(int m, int n, int s, int** A1, int* A2, int** A3, int** B) {
    // Allocate memory for matrix B
    *B = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        B[i] = (int*)malloc(s * sizeof(int));
    }

    // Perform matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s; j++) {
            B[i][j] = 0;
            for (int k = 0; k < n; k++) {
                B[i][j] += A1[i][k] * A2[k] * A3[k][j];
            }
        }
    }
}

int main() {
    int m, n, s;
    printf("Enter the dimensions of A1 (m n): ");
    scanf("%d %d", &m, &n);
    printf("Enter the dimensions of A3 (n s): ");
    scanf("%d %d", &n, &s);

    // Allocate memory for matrices A1, A2, A3, and B
    int** A1 = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        A1[i] = (int*)malloc(n * sizeof(int));
    }
    int* A2 = (int*)malloc(n * sizeof(int));
    int** A3 = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A3[i] = (int*)malloc(s * sizeof(int));
    }
    int** B;

    // Input matrix elements
    printf("Enter the elements of A1:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A1[i][j]);
        }
    }
    printf("Enter the elements of A2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A2[i]);
    }
    printf("Enter the elements of A3:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s; j++) {
            scanf("%d", &A3[i][j]);
        }
    }

    // Perform matrix multiplication
    matrixMultiplication(m, n, s, A1, A2, A3, B);

    // Output matrix B
    printf("Matrix B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < m; i++) {
        free(A1[i]);
    }
    free(A1);
    free(A2);
    for (int i = 0; i < n; i++) {
        free(A3[i]);
    }
    free(A3);
    for (int i = 0; i < m; i++) {
        free(B[i]);
    }
    free(B);

    return 0;
}
