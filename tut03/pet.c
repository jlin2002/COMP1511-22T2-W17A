// A program that uses structs to represent pets
// W17A, June 2022

#include <stdio.h>

enum type {
    dog,
    rabbit,
    cat
};

struct pet {
    double age;
    int num_legs;
    enum type pet_type;
};

int main(void) {
    struct pet my_pet;
    // Age: 10.5, Number of legs: 4, Pet type: Dog
    my_pet.age = 10.5;
    my_pet.num_legs = 4;
    my_pet.pet_type = dog;
    
    printf("Age: %lf, Number of legs: %d, Type: %d\n", 
        my_pet.age, my_pet.num_legs, my_pet.pet_type);
        
    printf("Type: ");
    if (my_pet.pet_type == dog) {
        printf("Dog\n");
    } else if (my_pet.pet_type == rabbit) {
        printf("Rabbit\n");
    } else {
        printf("Cat\n");
    }
    return 0;
}
