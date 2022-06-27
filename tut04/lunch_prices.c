// A program that scans in a number of lunch prices
// and tells the user the average price of the lunches
// inputted

#include <stdio.h>

#define MAX_INPUTS 1000

int main(void) {
    double prices[MAX_INPUTS];
    int num_inputs = 0;
    // Scan the prices into the array
    while (scanf("%lf", &prices[num_inputs]) == 1) {
        // Keep scanning
        num_inputs++;
    }
    
    // Sum all the inputs
    double sum = 0;
    int i = 0;
    while (i < num_inputs) {
        sum = sum + prices[i];
        i++;
    }
    
    // Take the average and print it
    printf("The average is: %lf\n", sum / num_inputs);
    return 0;
}
