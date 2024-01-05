#include <stdio.h>
#include <math.h> // Include the math.h header for pow function

#define MAX_TERMS 100

typedef struct {
    float coef;
    int expon;
} polynomial;

polynomial terms[MAX_TERMS];

float evaluatePolynomial(polynomial poly[], int numTerms, float x) {
    float result = 0.0;

    for (int i = 0; i < numTerms; i++) {
        result += poly[i].coef * pow(x, poly[i].expon);
    }
    return result;
}

void padd (int starta, int finisha, int startb, int finishb, int * startd, int *finishd)
{
/* add A(x) and B(x) to obtain D(x) */
    float coefficient;
    int avail = 0;
    *startd = avail;
    while (starta <= finisha && startb <= finishb) {
        switch (COMPARE(terms[starta].expon,terms[startb].expon)) 
{
        case -1: /* a expon < b expon */
                {attach(terms[startb].coef, terms[startb].expon);
                startb++;
                break;}
        case  0: /* equal exponents */
                { coefficient = terms[starta].coef +
                                       terms[startb].coef;
                  if (coefficient)
                     attach (coefficient, terms[starta].expon);
                  starta++;
                  startb++;
                  break;}
        case 1: /* a expon > b expon */
                {attach(terms[starta].coef, terms[starta].expon);
                starta++;}
}
}
}

int main() {
    // Example usage
    terms[0].coef = 2.0;
    terms[0].expon = 3;

    terms[1].coef = -1.5;
    terms[1].expon = 2;

    terms[2].coef = 1.0;
    terms[2].expon = 1;

    terms[3].coef = 5;
    terms[3].expon = 0;

    int numTerms = 4;
    float x = 2.0;

    float result = evaluatePolynomial(terms, numTerms, x);

    printf("Result of polynomial evaluation: %.2f\n", result);

    return 0;
}
