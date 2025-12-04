#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

// Function declarations
int count(list *h);
void concat(list *h1, list *h2);
void print_list(list *h);
void free_list(list *h);

int count(list *h)
{
    if (h == NULL)
        return 0;
    return 1 + count(h->next);
}

void concat(list *h1, list *h2)
{
    assert(h1 != NULL); // h1 must exist

    list *current = h1;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = h2; // Attach h2 to the end of h1
}

void print_list(list *h)
{
    list *current = h;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(list *h)
{
    list *tmp;
    while (h != NULL)
    {
        tmp = h;
        h = h->next;
        free(tmp);
    }
}

int main()
{
    // Create list1: 10 -> 20 -> NULL
    list *head1 = malloc(sizeof(list));
    head1->data = 10;
    head1->next = malloc(sizeof(list));
    head1->next->data = 20;
    head1->next->next = NULL;

    // Create list2: 30 -> 40 -> NULL
    list *head2 = malloc(sizeof(list));
    head2->data = 30;
    head2->next = malloc(sizeof(list));
    head2->next->data = 40;
    head2->next->next = NULL;

    // Print initial lists
    printf("The number of elements in head1: %d\n", count(head1));
    printf("The number of elements in head2: %d\n", count(head2));

    printf("\nInitial head1 (Count: %d): ", count(head1));
    print_list(head1);
    printf("Initial head2 (Count: %d): ", count(head2));
    print_list(head2);

    // Concatenate head2 onto head1
    concat(head1, head2);

    printf("\nAfter concatenation:\n");
    printf("Combined list (Count: %d): ", count(head1));
    print_list(head1);

    // Now safely free the entire combined list using head1
    // DO NOT free head2 separately — it's now part of head1!
    free_list(head1);

    // Do not touch head1 or head2 after this

    return 0;
}