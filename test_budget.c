 #include <stdio.h>
#include "budget.h"

/* Standalone test harness for budget.c.
   Lets me test Add / Display / Check Budget on their own,
   without needing the group's full integrated main.c. */

int main(void)
{
    int choice;

    do
    {
        printf("\n========== BUDGET MODULE TEST MENU ==========\n");
        printf("1. Add Department Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Check Budget Status\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            choice = -1;
        }

        switch (choice)
        {
            case 1: addBudget(); break;
            case 2: displayBudgets(); break;
            case 3: checkBudget(); break;
            case 4: printf("\nExiting test menu.\n"); break;
            default: printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}