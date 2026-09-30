#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "suppliers.h"

int  supplierIDs[MAX_SUPPLIERS];
char supplierNames[MAX_SUPPLIERS][100];
char supplierEmails[MAX_SUPPLIERS][100];
char supplierPhones[MAX_SUPPLIERS][30];
char supplierTowns[MAX_SUPPLIERS][100];

int supplierCount = 0;

static int readIntSafe(const char *prompt)
{
    char buffer[32];
    int value;
    int valid = 0;

    while (!valid)
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &value) == 1)
            {
                valid = 1;
            }
            else
            {
                printf("Invalid number. Please try again.\n");
            }
        }
        else
        {
            value = -1;
            valid = 1;
        }
    }
    return value;
}

static int isValidEmail(const char *email)
{
    const char *at = strchr(email, '@');
    if (strlen(email) == 0 || at == NULL)
    {
        return 0;
    }
    const char *dot = strchr(at, '.');
    if (dot == NULL || dot == at + 1 || *(dot + 1) == '\0')
    {
        return 0;
    }
    return 1;
}

static int isDuplicateID(int id)
{
    for (int i = 0; i < supplierCount; i++)
    {
        if (supplierIDs[i] == id)
        {
            return 1;
        }
    }
    return 0;
}

void addSupplier()
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("\nSupplier limit reached.\n");
        return;
    }

    getchar();

    int id;
    while (1)
    {
        id = readIntSafe("Enter supplier ID: ");
        if (id <= 0)
        {
            printf("Supplier ID must be a positive number.\n");
            continue;
        }
        if (isDuplicateID(id))
        {
            printf("A supplier with ID %d already exists. Try a different ID.\n", id);
            continue;
        }
        break;
    }
    supplierIDs[supplierCount] = id;

    printf("Enter supplier name: ");
    fgets(supplierNames[supplierCount], sizeof(supplierNames[supplierCount]), stdin);
    supplierNames[supplierCount][strcspn(supplierNames[supplierCount], "\n")] = '\0';

    if (strlen(supplierNames[supplierCount]) == 0)
    {
        printf("Supplier name cannot be empty. Supplier not added.\n");
        return;
    }

    while (1)
    {
        printf("Enter email: ");
        fgets(supplierEmails[supplierCount], sizeof(supplierEmails[supplierCount]), stdin);
        supplierEmails[supplierCount][strcspn(supplierEmails[supplierCount], "\n")] = '\0';

        if (!isValidEmail(supplierEmails[supplierCount]))
        {
            printf("Invalid email format (expected something like name@domain.com).\n");
            continue;
        }
        break;
    }

    printf("Enter telephone number: ");
    fgets(supplierPhones[supplierCount], sizeof(supplierPhones[supplierCount]), stdin);
    supplierPhones[supplierCount][strcspn(supplierPhones[supplierCount], "\n")] = '\0';

    printf("Enter town/location: ");
    fgets(supplierTowns[supplierCount], sizeof(supplierTowns[supplierCount]), stdin);
    supplierTowns[supplierCount][strcspn(supplierTowns[supplierCount], "\n")] = '\0';

    supplierCount++;

    printf("\nSupplier added successfully.\n");
}

void displaySuppliers()
{
    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been added.\n");
        return;
    }

    printf("\n========== SUPPLIER LIST ==========\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d:\n", i + 1);
        printf("ID      : %d\n", supplierIDs[i]);
        printf("Name    : %s\n", supplierNames[i]);
        printf("Email   : %s\n", supplierEmails[i]);
        printf("Telephone: %s\n", supplierPhones[i]);
        printf("Town    : %s\n", supplierTowns[i]);
    }
}

void searchSupplier()
{
    if (supplierCount == 0)
    {
        printf("\nNo suppliers available to search.\n");
        return;
    }

    getchar();

    printf("\n--- Search Supplier ---\n");
    printf("1. Search by Supplier ID\n");
    printf("2. Search by Supplier Name\n");
    int subChoice = readIntSafe("Enter choice: ");

    if (subChoice == 1)
    {
        int searchID = readIntSafe("Enter supplier ID to search: ");
        int found = 0;

        for (int i = 0; i < supplierCount; i++)
        {
            if (supplierIDs[i] == searchID)
            {
                printf("\nSupplier found.\n");
                printf("ID      : %d\n", supplierIDs[i]);
                printf("Name    : %s\n", supplierNames[i]);
                printf("Email   : %s\n", supplierEmails[i]);
                printf("Telephone: %s\n", supplierPhones[i]);
                printf("Town    : %s\n", supplierTowns[i]);
                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf("\nSupplier not found.\n");
        }
    }
    else if (subChoice == 2)
    {
        char searchName[100];
        char lowerQuery[100];
        char lowerName[100];
        int found = 0;
        int i, j;

        printf("Enter supplier name (or part of it) to search: ");
        fgets(searchName, sizeof(searchName), stdin);
        searchName[strcspn(searchName, "\n")] = '\0';

        for (i = 0; searchName[i]; i++)
        {
            lowerQuery[i] = (char)tolower((unsigned char)searchName[i]);
        }
        lowerQuery[i] = '\0';

        for (i = 0; i < supplierCount; i++)
        {
            for (j = 0; supplierNames[i][j]; j++)
            {
                lowerName[j] = (char)tolower((unsigned char)supplierNames[i][j]);
            }
            lowerName[j] = '\0';

            if (strstr(lowerName, lowerQuery) != NULL)
            {
                printf("\nMatch found.\n");
                printf("ID      : %d\n", supplierIDs[i]);
                printf("Name    : %s\n", supplierNames[i]);
                printf("Email   : %s\n", supplierEmails[i]);
                printf("Telephone: %s\n", supplierPhones[i]);
                printf("Town    : %s\n", supplierTowns[i]);
                found = 1;
            }
        }
        if (!found)
        {
            printf("\nNo supplier found matching \"%s\".\n", searchName);
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

void compareSupplier()
{
    if (supplierCount < 2)
    {
        printf("\nNeed at least two suppliers to compare.\n");
        return;
    }

    getchar();

    char townQuery[100];
    char lowerQuery[100];
    char lowerTown[100];
    int matchCount = 0;
    int i, j;

    printf("\nEnter town/location to compare suppliers in: ");
    fgets(townQuery, sizeof(townQuery), stdin);
    townQuery[strcspn(townQuery, "\n")] = '\0';

    for (i = 0; townQuery[i]; i++)
    {
        lowerQuery[i] = (char)tolower((unsigned char)townQuery[i]);
    }
    lowerQuery[i] = '\0';

    printf("\n%-5s %-20s %-25s %-15s\n", "ID", "Name", "Email", "Phone");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < supplierCount; i++)
    {
        for (j = 0; supplierTowns[i][j]; j++)
        {
            lowerTown[j] = (char)tolower((unsigned char)supplierTowns[i][j]);
        }
        lowerTown[j] = '\0';

        if (strcmp(lowerTown, lowerQuery) == 0)
        {
            printf("%-5d %-20s %-25s %-15s\n",
                   supplierIDs[i], supplierNames[i], supplierEmails[i], supplierPhones[i]);
            matchCount++;
        }
    }

    if (matchCount == 0)
    {
        printf("\nNo suppliers found in \"%s\".\n", townQuery);
    }
    else if (matchCount == 1)
    {
        printf("\nOnly one supplier found in this town - nothing to compare against yet.\n");
    }
    else
    {
        printf("\nFound %d suppliers in \"%s\" above for comparison.\n", matchCount, townQuery);
    }
}
