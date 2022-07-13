// Demo of struct pointers
// W17A, July 2022

#include <stdio.h>

enum weapon { no_weapon, big_sword, little_sword, wand, bow };
enum armor { no_armor, knight_armor, mage_robes, overalls };

struct party_member {
    char character_name[100];
    enum weapon weapon;
    enum armor armor;
};

void swap_gear(struct party_member *member1, struct party_member *member2);
void print_member(struct party_member member);

int main(void) {
    struct party_member alice = {"Alice", bow, overalls};
    struct party_member bob = {"Bob", wand, mage_robes};

    printf("Before swapping: \n");
    print_member(alice);
    print_member(bob);

    swap_gear(&alice, &bob);

    printf("After swapping: \n");
    print_member(alice);
    print_member(bob);
    return 0;
}

// Swaps the weapon and armor of member1 and member2
void swap_gear(struct party_member *member1, struct party_member *member2) {
    enum armor temp_armor = member2->armor;
    enum weapon temp_weapon = member2->weapon;
    
    member2->armor = member1->armor;
    member2->weapon = member1->weapon;
    
    member1->armor = temp_armor;
    member1->weapon = temp_weapon;
}

// Prints out the fields of a struct party_member
void print_member(struct party_member member) {
    printf("%s wields %d and wears %d.\n", member.character_name, member.weapon, member.armor);
}