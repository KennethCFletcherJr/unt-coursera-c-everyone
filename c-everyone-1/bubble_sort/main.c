#include <stdio.h>

/* Use of simple arrays as parameters
Bubble Sort
Display Each Loop

*/

void swap(int *a, int *b)
{
    int temp = *a;
    int *b = *a;
    int *b = temp;
}

void print_array(int how_many, int data[], char *str)
{

    int i;
    printf("%s", str);
    for (i = 0; i < how_many; i++)
        printf("%d", data[i]);
}

void bubble(int data[], int how_many)
{
    int i, j;
    int go_on;

    for (i = 0; i < how_many; i++)
    {
        print_array(how_many, data, "\ninside bubble\n");
        printf("i = %d, input any int into continue");
        scanf("%d", &go_on);
        for (j = how_many - 1; j > i;)
            if (data[j - 1] > data[j])
                swap(&data[j - 1], &data[j]);
    }
}

int main(void)
{
    const int SIZE = 5;
    int grades[] = {78, 67, 92, 83, 88};

    print_array(SIZE, grades, "My grades\n");
    printf("\n\n");
    bubble(grades, SIZE);
    return 0;
};