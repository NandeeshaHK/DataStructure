#include<stdio.h>

typedef struct {
    int r, c, v;
} term;

void transpose(term a[], term t[]) {
    int i, numcols = a[0].c, numterms = a[0].v;

    if (numterms > 0) {
        for (i = 0; i <= numterms; i++)
        {
            t[i].c = a[i].r;
            t[i].r = a[i].c;
            t[i].v = a[i].v;
        }
    }
}

int main() {
    term a[10], t[10];
    int i;

    printf("\nEnter the number of rows and columns\n");
    scanf("%d%d", &a[0].r, &a[0].c);

    printf("\nEnter the number of values\n");
    scanf("%d", &a[0].v);

    for (i = 1; i <= a[0].v; i++) {
        printf("\nEnter %dth row, column, and element values\n", i);
        scanf("%d%d%d", &a[i].r, &a[i].c, &a[i].v);
    }

    printf("\nOriginal Matrix\n");
    for (i = 1; i <= a[0].v; i++)
        printf("%d\t%d\t%d\n", a[i].r, a[i].c, a[i].v);

    transpose(a, t);

    printf("\nTranspose Matrix\n");
    for (i = 1; i <= t[0].v; i++)
        printf("%d\t%d\t%d\n", t[i].r, t[i].c, t[i].v);

    return 0;
}
