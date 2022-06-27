#include <stdio.h>

struct colour {
    int red;
    int green;
    int blue;
};

enum main_colours {
    RED,
    GREEN,
    BLUE,
    OTHER
};

struct colour make_colour(int red_val, int green_val, int blue_val);

int main(void) {
    // Initialise a struct colour
    struct colour c = make_colour(100, 80, 60);
    // Check the values of the fields
    printf("RGB: (%d, %d, %d)\n", c.red, c.green, c.blue);
    return 0;
}

// Write a function make_colour
// Takes in 3 inputs: a value for red, green and blue
// Returns struct colour with fields initialised to inputs
struct colour make_colour(int red_val, int green_val, int blue_val) {
    c.red = red_val;
    c.green = green_val;
    c.blue = blue_val;
    return c;
}
