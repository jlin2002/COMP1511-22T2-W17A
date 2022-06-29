// A demonstration of using functions with pointers to have multiple
// return values.
// T17A, June 2022

#include <stdio.h>

void prod_power(int a, int b, int *pr, int *po);

int main(void) {
    int product = 0;
    int power = 0;
    prod_power(5, 7, &product, &power);
    printf("%d %d\n", product, power);
    return 0;
}

void prod_power(int a, int b, int *pr, int *po) {
    *pr = a * b;
    *po = 1;
    int i = 0;
    while (i < b) {
        *po *= a;
        i++;
    }
}