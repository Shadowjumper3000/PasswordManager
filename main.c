#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "pw_manager.h"

char fileName[100] = "pw_data.csv";
//changes the whitespaces to underscore for notes

int main() {
    bool displayMenu = true;
    while (displayMenu)
    {
        int choice;
        char websiteName[100], URL[100], userName[100], password[100];
        char notes[100] = "";
        displayMainMenu();
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                printf("Adding a password...\n");
                printf("Enter the website name: \n");
                scanf(" %s", websiteName);
                printf("Enter the website URL: \n");
                scanf(" %s", URL);
                printf("Enter the username: \n");
                scanf(" %s", userName);
                printf("Enter the password: \n");
                scanf(" %s", password);
                printf("Enter notes: \n");
                scanf(" %[^\n]s", notes); //used to scan multiple words seperated by a space
                addRecord(fileName, websiteName, URL, userName, password, notes);
                break;

            case 2:
                printf("Viewing all passwords...\n");
                readWholeFile(fileName);
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
