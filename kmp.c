#include <stdio.h>
#include <string.h>

int failure[20];

void fail(char *pat) {
    int i, j;
    int n = strlen(pat);
    failure[0] = -1;

    for (j = 1; j < n; j++) {
        i = failure[j - 1];
        while ((pat[j] != pat[i + 1]) && (i > 0))
            i = failure[i];

        if (pat[j] == pat[i + 1])
            failure[j] = i + 1;
        else
            failure[j] = -1;
    }
}

int match(char *string, char *pat) {
    int i = 0, j = 0;
    int lens = strlen(string);
    int lenp = strlen(pat);

    while (i < lens && j < lenp) {
        if (string[i] == pat[j]) {
            i++;
            j++;
        } 
        else if (j == 0)
            i++;
        else
            j = 0;
    }

    return ((j == lenp) ? (i - j) : -1);
}

int main() {
    int i;
    char str[30], pat[20];

    printf("\nEnter a string\n");
    scanf("%s", str);

    printf("\nEnter a substring\n");
    scanf("%s", pat);

    fail(pat);
    for(int i = 0; i < 20; i++){
        printf("%d", failure[i]);
    }
    i = match(str, pat);

    if (i == -1)
        printf("\nPattern %s Not found", pat);
    else
        printf("\nPattern %s Found at position %d", pat, i + 1);

    return 0;
}
