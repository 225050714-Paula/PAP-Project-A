#include <stdio.h>
#include "suppliers.h"

int main(void)
{
    int choice;

    do
    {
        printf("\n===== SUPPLIER MODULE TEST MENU =====\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers (by town)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            choice = -1;  /* -1 is not a valid menu option, unlike 0 (Exit) */
        }

        switch (choice)
        {
            case 1: addSupplier(); break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier(); break;
            case 4: compareSupplier(); break;
            case 0: printf("Exiting test menu.\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}
