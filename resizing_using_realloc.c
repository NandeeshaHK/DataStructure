#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    // Get the initial number of rows and columns from the user
    printf("Enter the initial number of rows: ");
    scanf("%d", &rows);

    printf("Enter the initial number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the initial 2D matrix using calloc
    int **matrix = (int **)calloc(rows, sizeof(int *));
    
    // Check if memory allocation was successful
    if (matrix == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)calloc(cols, sizeof(int));

        // Check if memory allocation for each row was successful
        if (matrix[i] == NULL) {
            printf("Memory allocation failed. Exiting...\n");

            // Free the previously allocated memory
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);

            return 1;
        }
    }

    // Now you can use the matrix like a regular 2D array
    // For example, initializing the matrix with some values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }

    // Printing the initial matrix
    printf("Initial 2D matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Get the new size of the matrix from the user
    int newRows, newCols;
    printf("Enter the new number of rows: ");
    scanf("%d", &newRows);

    printf("Enter the new number of columns: ");
    scanf("%d", &newCols);

    // Resize the matrix using realloc
    matrix = (int **)realloc(matrix, newRows * sizeof(int *));

    // Check if memory reallocation was successful
    if (matrix == NULL) {
        printf("Memory reallocation failed. Exiting...\n");
        return 1;
    }

    for (int i = rows; i < newRows; i++) {
        matrix[i] = (int *)calloc(newCols, sizeof(int));

        // Check if memory allocation for each new row was successful
        if (matrix[i] == NULL) {
            printf("Memory allocation failed. Exiting...\n");

            // Free the previously allocated memory
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);

            return 1;
        }
    }

    // Printing the resized matrix
    printf("Resized 2D matrix:\n");
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Don't forget to free the allocated memory
    for (int i = 0; i < newRows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
