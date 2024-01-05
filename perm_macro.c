#include <stdio.h>
#include <string.h>

#define IS_UNIQUE(list, start, i) ({ \
    int unique = 1; \
    for (int k = start; k < i; k++) { \
        if ((list)[k] == (list)[i]) { \
            unique = 0; \
            break; \
        } \
    } \
    unique; \
})

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void perm(char *list, int i, int n) {
    if (i == n) {
        for (int j = 0; j <= n; j++)
            printf("%c", list[j]);
        printf("  ");
    } else {
        for (int j = i; j <= n; j++) {
            // Check if the element at index j has not been considered before
            if (IS_UNIQUE(list, i, j)) {
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
