// Takes in a school year from the user and tells them whether they are too 
// young for high school, able to go to high school or too old for high school,
// and prints their (approximate) age.
// W17A, June 2022

#include <stdio.h>

#define MIN_HIGH_SCHOOL_YEAR 7
#define MAX_HIGH_SCHOOL_YEAR 12
#define MIN_SCHOOL_AGE 5

int main(void) {
    int school_year;
    printf("Enter your school year: ");
    scanf("%d", &school_year);

    if (school_year < 0) {
        printf("Enter a valid school year.\n");
    } else if (school_year < MIN_HIGH_SCHOOL_YEAR) {
        printf("You are too young for high school.\n");
    } else if (school_year <= MAX_HIGH_SCHOOL_YEAR) {
        printf("You can go to high school.\n");
    } else {
        printf("You are too old for high school.\n");   
    }
    
    if (school_year >= 0) {
        printf("You are around %d years old\n", school_year + MIN_SCHOOL_AGE);
    }
    
    return 0;
}
