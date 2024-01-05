#include<stdio.h>
#include<string.h>


#define COMPARE(x,y) (((x)<(y))? -1: ((x)==(y))?0:1)
#define SWAP(x,y,t) ((t)=(x), (x)=(y),(y)=(t))

int compare(int x, int y)
{  if(x<y)  return -1; 
   else if (x==y)  return 0;
   else  return 1;
}

// Function to swap two characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate permutations
void perm(char *list, int i, int n) {
    if (i == n) {
        // Print the permutation
        for (int j = 0; j <= n; j++)
            printf("%c", list[j]);
        printf("  ");
    } else {
        for (int j = i; j <= n; j++) {
            // Swap the current element with the element at index j
            swap(&list[i], &list[j]);
            
            // Recursively generate permutations
            perm(list, i + 1, n);
            
            // Backtrack: restore the original order for the next iteration
            swap(&list[i], &list[j]);
        }
    }
}

void main()
{
    char str[20] = "abc";
    perm(str, 0, strlen(str));
}