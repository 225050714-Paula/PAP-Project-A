#include <string.h>
#include "reports.h"
#include <stdio.h>
#include <string.h>
#include "assets.h"

static Asset assets[MAX_ASSETS];
static int assetCount = 0;

void addAsset(void)
{
    if (assetCount >= MAX_ASSETS)
    {
        printf("\nAsset register is full.\n");
        return;
    }

    printf("\n========== ADD ASSET ==========\n");

    printf("Enter Asset ID: ");
    scanf("%d", &assets[assetCount].assetID);
    getchar();

    printf("Enter Asset Name: ");
    fgets(assets[assetCount].assetName, sizeof(assets[assetCount].assetName), stdin);
    assets[assetCount].assetName[strcspn(assets[assetCount].assetName, "\n")] = '\0';

    printf("Enter Asset Type: ");
    fgets(assets[assetCount].assetType, sizeof(assets[assetCount].assetType), stdin);
    assets[assetCount].assetType[strcspn(assets[assetCount].assetType, "\n")] = '\0';

    printf("Enter Purchase Value (N$): ");
    scanf("%lf", &assets[assetCount].purchaseValue);
    getchar();

    printf("Enter Department: ");
    fgets(assets[assetCount].department, sizeof(assets[assetCount].department), stdin);
    assets[assetCount].department[strcspn(assets[assetCount].department, "\n")] = '\0';

    printf("Enter Condition: ");
    fgets(assets[assetCount].condition, sizeof(assets[assetCount].condition), stdin);
    assets[assetCount].condition[strcspn(assets[assetCount].condition, "\n")] = '\0';

    assetCount++;
    printf("\nAsset added successfully!\n");
}

void displayAssets(void)
{
    int i;
    printf("\n========== ASSET REGISTER ==========\n");

    if (assetCount == 0)
    {
        printf("No assets have been registered.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("------------------------------\n");
        printf("Asset ID:       %d\n", assets[i].assetID);
        printf("Asset Name:     %s\n", assets[i].assetName);
        printf("Asset Type:     %s\n", assets[i].assetType);
        printf("Purchase Value: N$%.2f\n", assets[i].purchaseValue);
        printf("Department:     %s\n", assets[i].department);
        printf("Condition:      %s\n", assets[i].condition);
    }
}

void searchAsset(void)
{
    int searchID;
    int i;
    int found = 0;

    printf("\n========== SEARCH ASSET ==========\n");

    printf("Enter Asset ID to search: ");
    scanf("%d", &searchID);
    getchar();

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].assetID == searchID)
        {
            printf("\nAsset Found!\n");
            printf("------------------------------\n");
            printf("Asset ID:       %d\n", assets[i].assetID);
            printf("Asset Name:     %s\n", assets[i].assetName);
            printf("Asset Type:     %s\n", assets[i].assetType);
            printf("Purchase Value: N$%.2f\n", assets[i].purchaseValue);
            printf("Department:     %s\n", assets[i].department);
            printf("Condition:      %s\n", assets[i].condition);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nAsset with ID %d was not found.\n", searchID);
    }
}
void assetMenu(void)
{
    int choice;

    do
    {
        printf("\n========== ASSET MANAGEMENT ==========\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
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
            case 1: addAsset();      break;
            case 2: displayAssets(); break;
            case 3: searchAsset();   break;
            case 4: printf("\nReturning to main menu...\n"); break;
            default: printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);
}

void assetMenuReport(void)
{
    char names[MAX_ASSETS][100];
    float values[MAX_ASSETS];

    for (int i = 0; i < assetCount; i++)
    {
        strncpy(names[i], assets[i].assetName, 99);
        names[i][99] = '\0';
        values[i] = assets[i].purchaseValue;
    }

    assetReport(names, values, assetCount);
}