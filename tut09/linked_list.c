// Demo of linked list delete and miscellaneous functions.
// W17A, July 2022

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct list {
  struct node *head;
};

struct node {
  int data;
  struct node *next;
};

// Procedures to inspect our code
void demo_free(void);
void demo_linked_lists(void);

// Functions to implement
void delete_head(struct list *list);
void free_list(struct list *list);
struct list *copy(struct list *list);
int identical(struct list *first_list, struct list *second_list);

// Helpers
struct list *create_list(void);
struct node *create_node(int data);
void prepend(struct list *list, int data);
void print_list(struct list *list);
void print_list_with_addresses(struct list *list);

int main(void) {
  // PART 1: Free
  // demo_free();
  // Part 2: Linked List functions
  demo_linked_lists();

  return 0;
}

// PART 1
// Demonstrates using functions involving free
void demo_free(void) {
  struct list *list = create_list();
  prepend(list, 2);
  prepend(list, 1);
  prepend(list, 3);
  printf("Before deleting head: ");
  print_list(list);

  // Then remove the head...
  delete_head(list);
  printf("After deleting head: ");
  print_list(list);

  // Clean up the list
  free_list(list);
}

// Deletes node from head of the list, if it exists
void delete_head(struct list *list) {
  if (list->head == NULL) {
    return;
  }
  struct node *old_head = list->head;
  list->head = list->head->next;
  free(old_head);
}

// Frees memory associated with a list
void free_list(struct list *list) {
  struct node *curr = list->head;
  while (curr != NULL) {
    struct node *del_node = curr;
    curr = curr->next;
    free(del_node);
  }
  free(list);
}

// PART 2
// Used to debug linked list functions
void demo_linked_lists(void) {
  struct list *list = create_list();
  prepend(list, 1);
  prepend(list, 3);
  prepend(list, 2);

  struct list *list_copy = copy(list);

  // Ensure that the list_copy is really a copy!
  printf("Copy: ");
  print_list_with_addresses(list_copy);
  printf("Original: ");
  print_list_with_addresses(list);

  // Lists should be identical
  printf("identical returned: %d (expected 1)\n", identical(list, list_copy));

  // Delete from copy to make lists different
  delete_head(list_copy);
  printf("after deleting, identical returned: %d (expected 0)\n",
         identical(list, list_copy));

  // Free both lists to prevent memory leaks
  free_list(list);
  free_list(list_copy);
}

// Returns 1 if first_list is identical to second_list, 0 otherwise.
int identical(struct list *first_list, struct list *second_list) {
  // Broad idea: Loop through lists to check if data
  // is equal one by one.
  struct node *curr1 = first_list->head;
  struct node *curr2 = second_list->head;
  while (curr1 != NULL && curr2 != NULL) {
    if (curr1->data != curr2->data) {
      return FALSE;
    }
    curr1 = curr1->next;
    curr2 = curr2->next;
  }
  return curr1 == NULL && curr2 == NULL;
}

// Returns a copy of the provided list
struct list *copy(struct list *list) {
  // Broad idea: Create a copy for the list
  // loop the original lists, cloning the nodes, appending it
  // to the end of the copy.
  struct list *list_copy = create_list();
  struct node *copy_tail = NULL;
  struct node *curr = list->head;
  while (curr != NULL) {
    struct node *node_clone = create_node(curr->data);
    if (copy_tail == NULL) {
      list_copy->head = node_clone;
    } else {
      copy_tail->next = node_clone;
    }
    copy_tail = node_clone;
    curr = curr->next;
  }
  return list_copy;
}

// Creates a node out of the given data
struct node *create_node(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Creates an empty linked list
struct list *create_list() {
  struct list *new_list = malloc(sizeof(struct list));
  new_list->head = NULL;
  return new_list;
}

// Prepends node containing `data` to the given `list`
void prepend(struct list *list, int data) {
  struct node *new_head = create_node(data);
  new_head->next = list->head;
  list->head = new_head;
}

// Prints the provided `list` in the following format
// num1 -> num2 -> ... -> X
void print_list(struct list *list) {
  struct node *curr = list->head;
  while (curr != NULL) {
    printf("%d -> ", curr->data);
    curr = curr->next;
  }
  printf("X\n");
}

void print_list_with_addresses(struct list *list) {
  struct node *curr = list->head;
  while (curr != NULL) {
    printf("%d (%p) -> ", curr->data, curr);
    curr = curr->next;
  }
  printf("X\n");
}
