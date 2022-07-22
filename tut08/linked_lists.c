// Demo of linked lists
// F13A, July 2022
#include <stdio.h>
#include <stdlib.h>

// Representation of a node in a linked list.
struct node {
    int data;
    struct node *next;
};

// Representation of a linked list.
struct list {
    struct node *head;
};

struct list *create_list(void);
struct node *create_node(int data);
// TODO: prototypes for prepend, print_list and print_last

int main(void) {
  // Create a list

  // Prepend 2, then 1, then 3 to the list

  // Print list
  // Prints: 3 -> 1 -> 2 -> X

  // Print last element in list
  // Prints: 2

  return 0;
}

// Creates a linked list and returns a pointer to it
struct list *create_list(void) {
    struct list *new_list = malloc(sizeof(struct list));
    new_list->head = NULL;
    return new_list;
}

// Creates a node and returns a pointer to it
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Prepends a node to the provided linked list
// TODO: prepend

// Prints the list in the format
// data1 -> data2 -> ... -> X
// TODO: print_list

// Prints the last element of the list
// TODO: print_last
