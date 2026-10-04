#include <stdio.h>

void employeeMenu(void);
void budgetMenu(void);
void supplierMenu(void);
void assetMenu(void);
void displayReportsMenu(void);

void clearInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

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
            /* user typed a letter or symbol */
            clearInput();
            printf("\nInvalid choice. Please enter a number from 1 to 6.\n");
            printf("Press Enter to continue...");
            getchar();
            choice = 0;
            continue;
        }

        clearInput();   

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
            case 6: printf("\nThank you for using the system.\n");
                 break;
            default:
                printf("\nInvalid choice. Please enter a number from 1 to 6.\n");
                printf("Press Enter to continue...");
                getchar();
        }

    } while (choice != 6);

    return 0;
}