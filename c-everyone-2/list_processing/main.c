/*
The ADT List Processing
C-Everyone
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// typedef shows its self-preferential nature. A list appears inside a list. A piece of data with a link to next.

typedef struct list
{
    int data;
    struct list *next;
} list;
// Checking to see if the current pointer at the list returns a boolean 1 for NULL to confirm whether or not
// the list is empty.
int is_empty(const list *l) { return (l == NULL); }

// NULL is the sentinel for being empty.

// We create a list out of a piece of data, d.
// You can work with other data types by changing the data and type deposited as the argument.
list *create_list(int d)
// We take the list and create its head pointer. We go to the heap to allot memory for head using malloc, and create
// sizeof(list). We saw that was 16 bytes. malloc() acts as a constructor in C because it allocates memory.
{
    list *head = malloc(sizeof(list));

    // Memory is allocated for data, where we store d, and
    // Memory is allocated to next, where we store NULL

    head->data = d;
    head->next = NULL;

    return head;
}
// So when we initialize a list with a single element as above, the single element has as it's next* pointer, and the tail or NULL. Then what we return from creating the list is the head that we found dynamically.

// To build the list, we add to the front of the list.

list *add_to_front(int d, list *h)
{

    // From the memory allocated for head, we create list, create_list(d), and place it there--malloc(sizeof(list)), not needed? Why? We only use malloc() once in our code? We use next to access h, to place it at the front of head. Use a list* add_to_front(int d, list* h); when "adding to the front" of the list. So searching a list can be what's called order n, and increases with increasing size of the list.

    list *head = create_list(d);
    head->next = h;
    return head;
}

// Why aren't we freeing memory up here?
// Declaring the array and size.
// list* create_list(int d); list* add_to_front(int d, list*h); and list* array_to_list(int d[], int size) -- ARE THE FUNCTION signatures/PROTOTYPES, which acts as the functions' interface, used to indentify function overloading. Use list* array_to_list(int d[], int size), when adding to the middle of the list, OR when looking randomly at elements inside a list? On the other hand searching an array is order one, how you go and look something up in an array, which doesn't depend on the size of the array. WE ARE TAKING AN ARRAY AND CONVERTING INTO A LIST. Array to List specifies the type of data array and it's size in the signature. We create the list using the first element of the array.

// Depending on the size of the data, we could add to the array at the front.
list *array_to_list(int d[], int size)
{
    // Initializing the array?
    list *head = create_list(d[0]);
    int i;
    for (int i = 1; i < size; i++)
    {

        head = add_to_front(d[i], head);
    }

    return (head);
}

void print_list(list *h, char *title)
{
    printf("%s\n", title);

    // In printf(), print list, printf("%d :", h->data); we use the sentinel h != NULL to stop the processing of the list.

    while (h != NULL)
    {
        printf("%d :", h->data);
        h = h->next;
    }
}
// Now we are going to call? on the function/or start the function? in main()?

int main()
{
    list list_of_int;
    list *head = NULL;
    // Our data array input
    int data[6] = {2, 3, 5, 7, 8, 9};
    // Create a list from the data array. 2 goes into the stack first, so we will ultimately be printing the list in reverse, LIFO, resulting in 9 as the first element in the printed list!!!
    head = array_to_list(data, 6);
    print_list(head, "data[6] made into a single element list");
    return 0;
}
