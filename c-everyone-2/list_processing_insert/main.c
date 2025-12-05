#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

// The function is simplified to only accept the node BEFORE the insertion point.
void insert_after(list *prev_node, list *new_node)
{
    if (prev_node == NULL || new_node == NULL)
    {
        return; // Basic error handling
    }
    // The new node's 'next' pointer now points to what the 'prev_node' used to point to
    new_node->next = prev_node->next;
    // The 'prev_node' now points to the new node
    prev_node->next = new_node;
}

void print_list(list *head)
{
    list *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void)
{
    // 1. Create the initial list structure: p1 -> p2
    list *p1 = malloc(sizeof(list));
    list *p2 = malloc(sizeof(list));
    list *q = malloc(sizeof(list));

    if (p1 == NULL || p2 == NULL || q == NULL)
    {
        // Handle memory allocation failure
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    p1->data = 10;
    p2->data = 30;
    q->data = 20; // Data for the node to be inserted

    // Link them initially: p1 points to p2
    p1->next = p2;
    p2->next = NULL; // Mark the end of the list

    printf("Before insertion:\n");
    print_list(p1); // Prints 10 -> 30 -> NULL

    // 2. Insert 'q' using the corrected function
    // We pass 'p1' as the node *after* which we want to insert 'q'
    insert_after(p1, q);

    printf("After insertion:\n");
    print_list(p1); // Prints 10 -> 20 -> 30 -> NULL

    // 3. Free the allocated memory (good practice)
    free(p1);
    free(p2);
    free(q);

    return EXIT_SUCCESS;
}
// Function declarations
/* void insert(
    list *p1, // First
    list *p2, // Last
    list *q   // Insert
)
{
    assert(p1->next == q);

    p1->next = q;
    q->next = p2;
}

void print_list(list *p1)
{
    list *current = p1;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
 */
