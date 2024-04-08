#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <pw_manager.h>

int main() {
    bool displayMenu = true;

    while (displayMenu)
    {
        int choice;

        displayMainMenu();
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                printf("Adding a password...\n");
                break;

            case 2:
                printf("Viewing all passwords...\n");
                break;

            case 3:
                printf("Searching for a password...\n");
                break;

            case 4:
                printf("Deleting a password...\n");
                break;

            case 5:
                printf("Exiting the password manager...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }

    return 0;
    }
    
    
}
