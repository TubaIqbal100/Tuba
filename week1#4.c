#include <stdio.h>

#define MAX 10

/* Function Prototypes - Required for older compilers */
void add_matrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c);
void subtract_matrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c);
void multiply_matrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2);
void transpose_matrix(int a[MAX][MAX], int res[MAX][MAX], int r, int c);
void print_matrix(int mat[MAX][MAX], int r, int c);
void input_matrix(int mat[MAX][MAX], int r, int c);

int main() {
    /* Pre-C99: All variables declared at the top of the block */
    int A[MAX][MAX], B[MAX][MAX], Res[MAX][MAX];
    int r1, c1, r2, c2, choice;

    printf("--- User-Friendly Matrix Tester ---\n");
    printf("1. Addition & Subtraction (Test: Zero Matrix)\n");
    printf("2. Multiplication (Test: Identity or 2x3 * 3x2)\n");
    printf("3. Transpose (Test: 1xN Row to Nx1 Column)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter rows and columns: ");
        scanf("%d %d", &r1, &c1);
        printf("Matrix A:\n"); input_matrix(A, r1, c1);
        printf("Matrix B (Enter 0s for Zero Matrix test):\n"); input_matrix(B, r1, c1);
        
        add_matrices(A, B, Res, r1, c1);
        printf("\nAddition Result:\n"); print_matrix(Res, r1, c1);
        
        subtract_matrices(A, B, Res, r1, c1);
        printf("\nSubtraction (A - B) Result:\n"); print_matrix(Res, r1, c1);

    } else if (choice == 2) {
        printf("Matrix A dimensions (rows cols): "); scanf("%d %d", &r1, &c1);
        input_matrix(A, r1, c1);
        printf("Matrix B dimensions (rows cols): "); scanf("%d %d", &r2, &c2);
        input_matrix(B, r2, c2);

        if (c1 != r2) {
            printf("\nError: Columns of A must match Rows of B!\n");
        } else {
            multiply_matrices(A, B, Res, r1, c1, c2);
            printf("\nMultiplication Result:\n"); print_matrix(Res, r1, c2);
        }

    } else if (choice == 3) {
        printf("Enter dimensions (rows cols) (Try 1 3): "); scanf("%d %d", &r1, &c1);
        input_matrix(A, r1, c1);
        transpose_matrix(A, Res, r1, c1);
        printf("\nTransposed Matrix Result (%dx%d):\n", c1, r1);
        print_matrix(Res, c1, r1);
    }

    return 0;
}

/* --- Function Definitions --- */

void input_matrix(int mat[MAX][MAX], int r, int c) {
    int i, j;
    printf("Enter elements for %dx%d matrix:\n", r, c);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

void print_matrix(int mat[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void add_matrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            res[i][j] = a[i][j] + b[i][j];
}

void subtract_matrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            res[i][j] = a[i][j] - b[i][j];
}

void multiply_matrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }
}

void transpose_matrix(int a[MAX][MAX], int res[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            res[j][i] = a[i][j]; /* Swap row and col indices */
        }
    }
}

