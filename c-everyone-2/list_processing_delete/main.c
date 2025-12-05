/* To delete the node q from the provided code structure (where the final list is p1 -> q -> p2), you need a function that works similarly to insert_after, but in reverse. The key is to find the node that precedes the one you want to delete (p1 precedes q), bypass the target node (q), and then deallocate the memory for the target node.
Here is the original code rewritten with a new function, delete_after, and an updated main function to demonstrate its usage.
Rewritten Code with Deletion Function */
//c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

/*
 * Deletes the node immediately following prev_node.
 * It returns a pointer to the deleted node so it can be freed,
 * or NULL if no node was deleted (e.g., prev_node was NULL or the end of the list).
 */
list* delete_after(list *prev_node) {
    if (prev_node == NULL || prev_node->next == NULL) {
        return NULL; // Cannot delete if prev_node is null or there's nothing after it
    }

    // 1. Store a pointer to the node we intend to delete (which is q in main)
    list *node_to_delete = prev_node->next;

    // 2. ***Bypass the node to delete: Link prev_node directly to the node AFTER node_to_delete***
    prev_node->next = node_to_delete->next;

    // 3. Return the pointer to the deleted node--so the caller can free it--
    return node_to_delete;
}

// Are we printing out the resultant list here? "list" and "head" must be <stlib.h> functions since they 
// are not declared, or initialized? OR RATHER list is a struct, with types, type list, and type data 
// (and the head designation) are created on the stack (and with reference to the <stlib.h>) that 
// HAVE BEEN DECLARED as a struct.
// The following prints the list AFTER 1. delete_after(), 2. bypassing the deleted node, and 3. 
// returning a pointer to the deleted node.
void print_list(list *head) {
    list *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// int main(void) is the beginning of our code. Do we always call the code from int main(void){}?
int main(void) {
    // 1. Create the initial list structure: p1 -> p2
    list *p1 = malloc(sizeof(list));
    list *p2 = malloc(sizeof(list));
    list *q = malloc(sizeof(list));

    if (p1 == NULL || p2 == NULL || q == NULL) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    p1->data = 10;
    p2->data = 30;
    q->data = 20;

    // Link them initially: p1 points to p2***You are linking up the nodes initially.
    p1->next = p2;
    p2->next = NULL;

    printf("Initial list (p1 -> p2):\n");
    print_list(p1); // Prints 10 -> 30 -> NULL

    // 2. Insert 'q' to create: p1 -> q -> p2
    // (We reuse the insert_after function for setup)
    q->next = p1->next;
    p1->next = q;
    printf("\nAfter insertion (p1 -> q -> p2):\n");
    print_list(p1); // Prints 10 -> 20 -> 30 -> NULL

    // --- DELETION LOGIC ADDED HERE ---

    // 3. Delete 'q' using the new delete_after function.
    // We pass 'p1' as the node *before* 'q'.
    printf("\nDeleting 'q' (the node after p1):\n");
    list *deleted_node = delete_after(p1);

    if (deleted_node != NULL) {
        printf("Deleted node data: %d\n", deleted_node->data);
        free(deleted_node); // Crucial: Free the memory of the deleted node
    }

    printf("After deletion (back to p1 -> p2):\n");
    print_list(p1); // Prints 10 -> 30 -> NULL

    // 4. Free the remaining allocated memory (good practice)
    free(p1);
    free(p2);

    return EXIT_SUCCESS;
}