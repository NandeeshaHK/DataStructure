#include <stdio.h>

#define N 3 // Assuming a 3x3 matrix for this example

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Swap mat[i][j] and mat[j][i]
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

int main() {
    int mat[N][N] = {{0, 1, 1}, {1, 0, 2}, {2, 2, 3}};

    printf("Original Matrix:\n");
    printMatrix(mat);

    // Transpose the matrix using swaps
    transposeMatrix(mat);

    printf("\nTransposed Matrix:\n");
    printMatrix(mat);

    return 0;
}
