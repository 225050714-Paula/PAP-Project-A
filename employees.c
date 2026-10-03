#include <stdio.h>
#include <string.h>
#include "employees.h"

#define MAX_EMPLOYEES 50

int employeeCount = 0;

int employeeIDs[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][100];
char employeeDepartments[MAX_EMPLOYEES][50];

float basicSalary[MAX_EMPLOYEES];
float housingAllowance[MAX_EMPLOYEES];
float transportAllowance[MAX_EMPLOYEES];


void addEmployee()
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("Employee limit reached.\n");
        return;
    }

    printf("\n============================================\n");
    printf("             ADD EMPLOYEE\n");
    printf("============================================\n");

    printf("Enter Employee ID: ");
    scanf("%d", &employeeIDs[employeeCount]);

    while (employeeIDs[employeeCount] <= 0)
    {
        printf("Invalid ID. Enter a positive ID: ");
        scanf("%d", &employeeIDs[employeeCount]);
    }

    getchar();

    printf("Enter employee name: ");
    fgets(employeeNames[employeeCount], 100, stdin);
    employeeNames[employeeCount][strcspn(employeeNames[employeeCount], "\n")] = '\0';

    while (strlen(employeeNames[employeeCount]) == 0)
    {
        printf("Name cannot be empty. Enter employee name: ");
        fgets(employeeNames[employeeCount], 100, stdin);
        employeeNames[employeeCount][strcspn(employeeNames[employeeCount], "\n")] = '\0';
    }

    printf("Enter department: ");
    fgets(employeeDepartments[employeeCount], 50, stdin);
    employeeDepartments[employeeCount][strcspn(employeeDepartments[employeeCount], "\n")] = '\0';

    printf("Enter basic salary: ");
    scanf("%f", &basicSalary[employeeCount]);

    while (basicSalary[employeeCount] < 0)
    {
        printf("Salary cannot be negative. Enter again: ");
        scanf("%f", &basicSalary[employeeCount]);
    }

    printf("Enter housing allowance: ");
    scanf("%f", &housingAllowance[employeeCount]);

    while (housingAllowance[employeeCount] < 0)
    {
        printf("Allowance cannot be negative. Enter again: ");
        scanf("%f", &housingAllowance[employeeCount]);
    }

    printf("Enter transport allowance: ");
    scanf("%f", &transportAllowance[employeeCount]);

    while (transportAllowance[employeeCount] < 0)
    {
        printf("Allowance cannot be negative. Enter again: ");
        scanf("%f", &transportAllowance[employeeCount]);
    }

    employeeCount++;

    printf("\nEmployee added successfully!\n");
}


void displayEmployees()
{
    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n============================================\n");
    printf("            EMPLOYEE LIST\n");
    printf("============================================\n");

    for (int i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("ID                 : %d\n", employeeIDs[i]);
        printf("Name               : %s\n", employeeNames[i]);
        printf("Department         : %s\n", employeeDepartments[i]);
        printf("Basic Salary       : NAD %.2f\n", basicSalary[i]);
        printf("Housing Allowance  : NAD %.2f\n", housingAllowance[i]);
        printf("Transport Allowance: NAD %.2f\n", transportAllowance[i]);
    }

    printf("\n============================================\n");
}


void searchEmployee()
{
    char searchName[100];
    int found = 0;

    getchar();

    printf("\n============================================\n");
    printf("            SEARCH EMPLOYEE\n");
    printf("============================================\n");

    printf("Enter employee name to search: ");
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employeeNames[i], searchName) == 0)
        {
            printf("\nEmployee found!\n");
            printf("ID                 : %d\n", employeeIDs[i]);
            printf("Name               : %s\n", employeeNames[i]);
            printf("Department         : %s\n", employeeDepartments[i]);
            printf("Basic Salary       : NAD %.2f\n", basicSalary[i]);
            printf("Housing Allowance  : NAD %.2f\n", housingAllowance[i]);
            printf("Transport Allowance: NAD %.2f\n", transportAllowance[i]);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee not found.\n");
    }
}


void calculateSalary()
{
    int employeeID;
    int found = 0;
    float totalSalary;

    printf("\n============================================\n");
    printf("           SALARY CALCULATION\n");
    printf("============================================\n");

    printf("Enter Employee ID: ");
    scanf("%d", &employeeID);

    for (int i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == employeeID)
        {
            totalSalary = basicSalary[i]
                        + housingAllowance[i]
                        + transportAllowance[i];

            printf("\nEmployee: %s\n", employeeNames[i]);
            printf("Basic Salary       : NAD %.2f\n", basicSalary[i]);
            printf("Housing Allowance  : NAD %.2f\n", housingAllowance[i]);
            printf("Transport Allowance: NAD %.2f\n", transportAllowance[i]);
            printf("Total Salary       : NAD %.2f\n", totalSalary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee not found.\n");
    }
}
void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n========== EMPLOYEE MANAGEMENT ==========\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            choice = 0;
        }

        switch (choice)
        {
            case 1: addEmployee();     break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee();  break;
            case 4: calculateSalary(); break;
            case 5: printf("\nReturning to main menu...\n"); break;
            default: printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);
}