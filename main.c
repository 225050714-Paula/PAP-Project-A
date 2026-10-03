#include <stdio.h>

void employeeMenu(void);
void budgetMenu(void);
void supplierMenu(void);
void assetMenu(void);
void displayReportsMenu(void);

void displayMenu(void)
{
    printf("\n-------------- MUNICIPAL FINANCIAL MANAGEMENT SYSTEM --------------\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
}

int main(void)
{
    int choice;

    do
    {
        displayMenu();

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            /* Not a number: clear the bad input and ask again */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("\nInvalid input. Please enter a number from 1 to 6.\n");
            choice = 0;
            continue;
        }

        switch (choice)
        {
            case 1: employeeMenu();
                   break;
            case 2: budgetMenu(); 
                   break;
            case 3: supplierMenu();
                   break;
            case 4: assetMenu();
                   break;
            case 5: displayReportsMenu();
                   break;
            case 6:
                printf("\n------------ Thank you for using the system. ------------\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number from 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}