#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <pwManager.h>

bool displayMenu = true;

// Function to display the main menu
void displayMainMenu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Add a password\n");
    printf("2. View all passwords\n");
    printf("3. Search for a password\n");
    printf("4. Delete a password\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    // Infinite loop until the user chooses to exit
    while (displayMenu) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                // Add password functionality
                printf("Adding a password...\n");
                // Implement your code here
                break;

            case 2:
                // View all passwords functionality
                printf("Viewing all passwords...\n");
                // Implement your code here
                break;

            case 3:
                // Search for a password functionality
                printf("Searching for a password...\n");
                // Implement your code here
                break;

            case 4:
                // Delete a password functionality
                printf("Deleting a password...\n");
                // Implement your code here
                break;

            case 5:
                // Exit the program
                printf("Exiting the password manager...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
