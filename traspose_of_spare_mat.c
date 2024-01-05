#include<stdio.h>

#define swap(a, b, t) { t = *(a); *(a) = *(b); *(b) = t; }

typedef struct  
{
    int row;
    int col;
    int value;
} sparse_element;

void main(){
    char x = 'w', y = '2', temp;
    swap(&x, &y, temp);
    printf("x: %c, y: %c", x, y);

}
