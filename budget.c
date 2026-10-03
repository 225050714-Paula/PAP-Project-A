#include <stdio.h>
#include <string.h>
#include "budget.h"

#define MAX_DEPARTMENTS 10

char departmentNames[MAX_DEPARTMENTS][100];
float allocatedBudgets[MAX_DEPARTMENTS];
float expenditures[MAX_DEPARTMENTS];

int departmentCount = 0;

/* Add Department Budget */

void addBudget()
{
    if (departmentCount >= MAX_DEPARTMENTS)
    {
        printf("\nDepartment limit reached.\n");
        return;
    }

    getchar();

    printf("\nEnter department name: ");
    fgets(departmentNames[departmentCount],
          sizeof(departmentNames[departmentCount]), stdin);

    departmentNames[departmentCount]
        [strcspn(departmentNames[departmentCount], "\n")] = '\0';

    printf("Enter allocated budget: ");
    scanf("%f", &allocatedBudgets[departmentCount]);

    if (allocatedBudgets[departmentCount] < 0)
    {
        printf("Invalid budget. Budget cannot be negative.\n");
        allocatedBudgets[departmentCount] = 0;
        return;
    }

    printf("Enter expenditure: ");
    scanf("%f", &expenditures[departmentCount]);

    if (expenditures[departmentCount] < 0)
    {
        printf("Invalid expenditure. Expenditure cannot be negative.\n");
        expenditures[departmentCount] = 0;
        return;
    }

    departmentCount++;

    printf("\nBudget information added successfully.\n");
}

/* Display Budgets */

void displayBudgets()
{
    if (departmentCount == 0)
    {
        printf("\nNo budget information has been added.\n");
        return;
    }

    printf("\n========== BUDGET INFORMATION ==========\n");

    for (int i = 0; i < departmentCount; i++)
    {
        float remaining = allocatedBudgets[i] - expenditures[i];

        printf("\nDepartment: %s\n", departmentNames[i]);
        printf("Allocated Budget : %.2f\n", allocatedBudgets[i]);
        printf("Expenditure      : %.2f\n", expenditures[i]);
        printf("Remaining Budget : %.2f\n", remaining);

        if (remaining >= 0)
        {
            printf("Status           : WITHIN BUDGET\n");
        }
        else
        {
            printf("Status           : EXCEEDED\n");
        }
    }
}

/* Check Budget Status */

void checkBudget()
{
    int exceededCount = 0;

    if (departmentCount == 0)
    {
        printf("\nNo budget information has been added.\n");
        return;
    }

    printf("\n========== BUDGET STATUS ==========\n");

    for (int i = 0; i < departmentCount; i++)
    {
        float remaining = allocatedBudgets[i] - expenditures[i];

        if (remaining < 0)
        {
            printf("%s - EXCEEDED by %.2f\n",
                   departmentNames[i], -remaining);

            exceededCount++;
        }
        else
        {
            printf("%s - WITHIN BUDGET\n",
                   departmentNames[i]);
        }
    }

    printf("\nDepartments exceeding budget: %d\n", exceededCount);
}

void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n========== BUDGET MANAGEMENT ==========\n");
        printf("1. Add Budget Information\n");
        printf("2. Display Budgets\n");
        printf("3. Check Budget\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            choice = 0;
        }

        switch (choice)
        {
            case 1: addBudget();      break;
            case 2: displayBudgets(); break;
            case 3: checkBudget();    break;
            case 4: printf("\nReturning to main menu...\n"); break;
            default: printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);
}