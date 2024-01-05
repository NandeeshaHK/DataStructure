#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the 2D matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    
    // Check if memory allocation was successful
    if (matrix == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));

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

    // Printing the matrix
    printf("The 2D matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Don't forget to free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
