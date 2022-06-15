// A program that counts from 1 to 10
// T17A, June 2022

#include <stdio.h>

int main(void) {

    int counter = 1;
    while (counter <= 10) {
        printf("%d\n", counter);
        counter = counter + 1;
    }

    return 0;
}