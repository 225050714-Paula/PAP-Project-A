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