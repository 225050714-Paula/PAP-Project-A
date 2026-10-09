#include <stdio.h>
#include "reports.h"

/* Data owned by the other modules */
extern int employeeCount;
extern int employeeIDs[];
extern char employeeNames[][100];
extern float basicSalary[];
extern float housingAllowance[];
extern float transportAllowance[];

extern int departmentCount;
extern char departmentNames[][100];
extern float allocatedBudgets[];
extern float expenditures[];

extern int supplierCount;
extern char supplierNames[][100];
extern char supplierEmails[][100];
extern char supplierPhones[][30];
extern char supplierTowns[][100];

void assetMenuReport(void);   /* defined at the bottom of assets.c */

void employeeReport(int employeeIDs[], char names[][100], float salaries[], int count)
{
    float totalSalaries = 0.00;
    float average;
    float highest;
    float lowest;
    int highestIndex = 0;
    int lowestIndex = 0;

    printf("\n===============================\n");
    printf("      Employee Report\n");
    printf("===============================\n");

    if (count <= 0)
    {
        printf("No employees to report on.\n");
        return;
    }

    highest = salaries[0];
    lowest = salaries[0];

    for (int i = 0; i < count; i++)
    {
        printf("%d. ID: %d, Name: %s, Salary: %.2f\n", i + 1, employeeIDs[i], names[i], salaries[i]);
        totalSalaries = totalSalaries + salaries[i];

        if (salaries[i] > highest)
        {
            highest = salaries[i];
            highestIndex = i;
        }
        if (salaries[i] < lowest)
        {
            lowest = salaries[i];
            lowestIndex = i;
        }
    }

    average = totalSalaries / count;

    printf("--------------------------------\n");
    printf("Total employees: %d\n", count);
    printf("Total salaries: %.2f\n", totalSalaries);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f (Employee: %s)\n", highest, names[highestIndex]);
    printf("Lowest salary: %.2f (Employee: %s)\n", lowest, names[lowestIndex]);
}

void budgetReport(char departments[][100], float budgets[], float spent[], int count)
{
    float totalBudget = 0.00;
    float totalSpent = 0.00;
    float remaining = 0.00;
    int exceededCount = 0;

    printf("\n===============================\n");
    printf("     Budget Report\n");
    printf("===============================\n");

    if (count <= 0)
    {
        printf("No departments to report on.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        float leftover = budgets[i] - spent[i];
        printf("%d. Department: %s\n", i + 1, departments[i]);
        printf("  Allocated Budget: %.2f, Spent: %.2f, Remaining: %.2f\n", budgets[i], spent[i], leftover);

        if (spent[i] > budgets[i])
        {
            printf(" Status: OVER BUDGET!\n");
            exceededCount++;
        }
        else
        {
            printf(" Status: Within Budget\n");
        }

        totalBudget = totalBudget + budgets[i];
        totalSpent = totalSpent + spent[i];
    }

    remaining = totalBudget - totalSpent;

    printf("--------------------------------\n");
    printf("Total allocated budget: %.2f\n", totalBudget);
    printf("Total expenditure: %.2f\n", totalSpent);
    printf("Total remaining budget: %.2f\n", remaining);
    printf("Number of departments exceeding budget: %d\n", exceededCount);

    if (exceededCount > 0)
    {
        printf("Departments exceeding budget:\n");
        for (int i = 0; i < count; i++)
        {
            if (spent[i] > budgets[i])
            {
                printf(" - %s (over by %.2f)\n", departments[i], spent[i] - budgets[i]);
            }
        }
    }
}

void supplierReport(char names[][100], char emails[][100], char phones[][30], char towns[][100], int count)
{
    printf("\n===============================\n");
    printf("     Supplier Report\n");
    printf("===============================\n");

    if (count <= 0)
    {
        printf("No suppliers to report on.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d. Name: %s, Email: %s, Phone: %s, Town: %s\n", i + 1, names[i], emails[i], phones[i], towns[i]);
    }

    printf("--------------------------------\n");
    printf("Number of suppliers: %d\n", count);
}

void assetReport(char assetNames[][100], float values[], int count)
{
    float totalAssetValue = 0;
    float highestValue = 0;
    float lowestValue = 0;
    int highestIndex = 0;
    int lowestIndex = 0;

    printf("\n===============================\n");
    printf("     Asset Report\n");
    printf("===============================\n");

    if (count <= 0)
    {
        printf("No assets to report on.\n");
        return;
    }

    highestValue = values[0];
    lowestValue = values[0];

    for (int i = 0; i < count; i++)
    {
        printf("%d. Asset: %s, Value: %.2f\n", i + 1, assetNames[i], values[i]);

        totalAssetValue = totalAssetValue + values[i];

        if (values[i] > highestValue)
        {
            highestValue = values[i];
            highestIndex = i;
        }

        if (values[i] < lowestValue)
        {
            lowestValue = values[i];
            lowestIndex = i;
        }
    }

    printf("--------------------------------\n");
    printf("Total asset value: %.2f\n", totalAssetValue);
    printf("Highest asset value: %.2f (Asset: %s)\n", highestValue, assetNames[highestIndex]);
    printf("Lowest asset value: %.2f (Asset: %s)\n", lowestValue, assetNames[lowestIndex]);
}