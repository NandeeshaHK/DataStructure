#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to check if the element at index i is unique in the range [start, i)
int isUnique(char *list, int start, int i) {
    for (int k = start; k < i; k++) {
        if (list[k] == list[i]) {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

void perm(char *list, int i, int n) {
    if (i == n) {
        for (int j = 0; j <= n; j++)
            printf("%c", list[j]);
        printf("  ");
    } else {
        for (int j = i; j <= n; j++) {
            // Check if the element at index j has not been considered before
            if (isUnique(list, i, j)) {
                swap(&list[i], &list[j]);
                perm(list, i + 1, n);
                swap(&list[i], &list[j]); // Backtrack
            }
        }
    }
}

int main() {
    char str[] = "Eucalyputus";
    int length = strlen(str);

    perm(str, 0, length - 1);

    return 0;
}
