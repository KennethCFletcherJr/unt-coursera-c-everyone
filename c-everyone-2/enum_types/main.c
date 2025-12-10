/* Enumerated Types */

#include <stdio.h>

enum day
{
    sun,
    mon,
    tue,
    wed,
    thu,
    fri,
    sat
};

void print_day(enum day d)
{
    switch (d)
    {
    case sun:
        printf(" sunday ");
        break;
    case mon:
        printf(" monday ");
        break;
    case tue:
        printf(" tuesday ");
        break;
    case wed:
        printf(" wenesday ");
        break;
    case thu:
        printf(" thursday ");
        break;
    case fri:
        printf(" friday ");
        break;
    case sat:
        printf(" saturday ");
        break;
    default:
        printf("%d is an error", d);
    }
}
enum day next_day(enum day d)
{
    return ((d + 1) % 7);
}

int main()
{
    enum day today = sat;
    print_day(today); // Output:
    enum day tomorrow = next_day(today);
    print_day(tomorrow); // Output:
    return 0;
}

/* Is this the signature part of the definition?*/