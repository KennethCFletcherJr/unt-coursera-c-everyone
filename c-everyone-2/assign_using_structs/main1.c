#include <stdio.h>
#include <stdbool.h> // preprocessor for boolean functions

/* List months as enums and initialize them with the number for each month */
typedef enum month
{
    jan = 1,
    feb = 2,
    mar = 3,
    apr = 4,
    may = 5,
    jun = 6,
    jul = 7,
    aug = 8,
    sep = 9,
    oct = 10,
    nov = 11,
    dec = 12
} month;

/* Define a struct to hold the date (month and day) to be printed */
typedef struct date
{
    month m;
    int d;
} date;

/* In order to print out the month and the day correctly, the number of days per month have to be accounted for by creating an array of the number of days per month. The number of days per month is also equal to the last day of the month, and the last days can be used to account for and facilitate rollover from one month to another month based on the last day of the previous month. An array of 13 elements listing the number of days per month was created for 12 months, beginning with 0 as a placeholder and used to screen */
bool is_valid_date(date today)
{
    // Create an if else statement with an expression to limit the range of months between January and December, using the logical OR operator to read false for out of
    // range months.
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (today.m < jan || today.m > dec)
    {
        return false;
    }
    // Create an if else statemnt with an expression by limiting the range of the days in each month to be between 1 and the maximum/last day of the month for the current
    // month. using an appropriate expression with a logical OR operator to rule out numbers that are out of range using the days_in_month() function using the logical OR
    // operator.
    if (today.d < 1 || today.d > days_in_month[today.m])
    {
        return false;
    }
    return true; // Return true, if months and dates are with in range, and continue the operation.
}

/* In order to first print the date, pass the reference? for the struct date variable, today, to the print_date() function, and process it for printing by create a pointer variable *month_names that points to the memory address &months_names that contains the array for the months of the year. Create an if statement to confirm that the variable today is still a valid date before printing the date. Print the month and the day by accessing m and d from address for the variable today using the dot operator*/
void print_date(date today)
{
    const char *month_names[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    if (is_valid_date(today))
    {
        printf("%s %d\n", month_names[today.m], today.d);
    }
    else
    {
        printf("Invalid Date\n");
    }
}

/* After printing the month and the day, move the date forward by changing today to tomorrow by passing date today to the next_day function that is set up to screen today (after assignment to a new variable, tomorrow) to determine if today/tomorrow is the equivalent to the last day of the month.*/
date next_day(date today)
{
    // Array of number of days/maximum days in a month, beginning with 0 as a placeholder
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    date tomorrow = today;

    // Check to see if today is the last day of the current month, by checking to see if the date today equals the last day of the current month.
    if (today.d == days_in_month[today.m])
    {
        tomorrow.d = 1; // If today is the last day of the current month, rollover to the first day of the following month by assigning 1 to the day d for tomorrow.

        // Checking to see if today is the last month of the current year, December...
        if (today.m == dec)
        {
            tomorrow.m = jan; // If today is the last month of the current year, or December, assign January to m for tomorrow.
        }
        else
        {
            tomorrow.m = today.m + 1; // If the current month is not December, just add 1 to m for today and assign the value to m for tomorrow.
        }
    }
    else
    {
        tomorrow.d = today.d + 1; // If today is not equal to the last of the current month, then just add 1 to today and assign it to d in tommorrow.d
    }

    return tomorrow;
}

int main()
{
    // Run1: Enter a day that is not the last day of the current month.
    date today1 = {jan, 15};
    print_date(today1);

    date tomorrow1 = next_day(today1);
    print_date(tomorrow1);

    // Run2: Enter a day that is the last day of its respective month.
    date today2 = {feb, 28};
    print_date(today2);

    date tomorrow2 = next_day(today2);
    print_date(tomorrow2);

    // Run3: Enter the last day of December to test rolling over the day and the month.
    date today3 = {dec, 31};
    print_date(today3);

    date tomorrow3 = next_day(today3);
    print_date(tomorrow3);

    return 0;
}