#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"

bool VERBOSE = false;

char fileName[100] = "pw_data.csv";

int main(){
    bool displayMenu = true;
    while (displayMenu)
    {
        int choice;
        displayMainMenu();

        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                mh_addingPassword(fileName);
                break;
            case 2:
                mh_displayWebsiteNames(fileName);
                break;

            case 3:
                printf("Searching for a password...\n");

                //char* decrypted = decrypt(password); decrypt function using this line
                break;

            case 4:
                mh_deletePassword(fileName);
                break;
            
            case 5:
                printf("Modifying a password...\n");
                mh_changePassword(fileName);
                break;
                
            case 0:
                printf("Exiting the password manager...\n");
                displayMenu = false;
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Add a password\n");
    printf("2. View all passwords\n");
    printf("3. Search for a password\n");
    printf("4. Delete a password\n");
    printf("5. Modify a password\n");
    printf("0. Exit\n");
}