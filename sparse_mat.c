#include <stdio.h>
#include <stdlib.h>

// Structure to represent a non-zero element in the matrix
struct Element {
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix
struct SparseMatrix {
    int rows;
    int cols;
    int numNonZero;
    struct Element* elements;
};

// Function to initialize a sparse matrix
struct SparseMatrix initializeSparseMatrix(int rows, int cols, int numNonZero) {
    struct SparseMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.numNonZero = numNonZero;
    matrix.elements = (struct Element*)malloc(numNonZero * sizeof(struct Element));
    return matrix;
}

// Function to input elements into the sparse matrix
void inputSparseMatrix(struct SparseMatrix* matrix) {
    printf("Enter non-zero elements (row, column, value):\n");
    for (int i = 0; i < matrix->numNonZero; ++i) {
        scanf("%d %d %d", &matrix->elements[i].row, &matrix->elements[i].col, &matrix->elements[i].value);
    }
}

// Function to display the sparse matrix
void displaySparseMatrix(struct SparseMatrix matrix) {
    printf("Sparse Matrix (%dx%d):\n", matrix.rows, matrix.cols);
    for (int i = 0; i < matrix.numNonZero; ++i) {
        printf("%d %d %d\n", matrix.elements[i].row, matrix.elements[i].col, matrix.elements[i].value);
    }
}

// Main function
int main() {
    int rows, cols, numNonZero;

    // Input matrix dimensions and number of non-zero elements
    printf("Enter number of rows, columns, and non-zero elements: ");
    scanf("%d %d %d", &rows, &cols, &numNonZero);

    // Initialize sparse matrix
    struct SparseMatrix sparseMatrix = initializeSparseMatrix(rows, cols, numNonZero);

    // Input non-zero elements
    inputSparseMatrix(&sparseMatrix);

    // Display sparse matrix
    displaySparseMatrix(sparseMatrix);

    // Free allocated memory
    free(sparseMatrix.elements);

    return 0;
}
