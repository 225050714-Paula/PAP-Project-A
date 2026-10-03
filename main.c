#include <stdio.h>
#include "assets.h"

int main(void)
{
    int choice;

    do {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }
        getchar();

        switch (choice) {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: searchAsset(); break;
            case 4: printf("\nExiting program.\n"); break;
            default: printf("\nInvalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}