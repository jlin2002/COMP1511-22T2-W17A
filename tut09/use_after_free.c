// Demo of undefined behaviour when freed memory is used
// W17A, July 2022

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data);

int main(void) {
    struct node *node1 = create_node(1);
    free(node1);
    struct node *node2 = create_node(2);

    // !!! DANGER ZONE - USE AFTER FREE !!!
    node1->data = 3;
    
    // node2 contains 2... or does it?
    printf("node2 stores: %d\n", node2->data);

    return 0;
}

// Creates a node out of the given data
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}