// A program that initialises and prints the elements of an array
// T17A, June 2022

#include <stdio.h>

#define SIZE 6

int main(void) {
    int elements[SIZE] = {};
    int i = 0;
    while (i < SIZE) {
        printf("%d\n", elements[i]);
        i++;
    }
    return 0;
}
