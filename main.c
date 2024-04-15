#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"

bool VERBOSE = false;

char fileName[100] = "pw_data.csv";

int main(){

    //Checks if pw_data.csv file exists and if not it creates it and formats it
    if(fopen(fileName, "r") == NULL){
        printf("File doesn't exist, creating file pw_data.csv\n");

        FILE *file = fopen(fileName, "w");

        if(file == NULL){
            printf("Error creating file\n");
            exit(-1);
        } else {
            fprintf(file, "%s,%s,%s,%s,%s", "websiteName", "URL", "userName", "password", "notes");
            fclose(file);

            printf("File successfully created and formatted.\n");
        }
    }else{
        printf("File pw_data.csv exists\n");
    }

    char choice;
    bool displayMenu = true;
    while (displayMenu)
    {
        fflush(stdin);
        displayMainMenu();

        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                mh_addingPassword(fileName);
                break;
            case '2':
                mh_displayWebsiteNames(fileName);
                break;

            case '3':
                mh_searchPassword(fileName);
                break;

            case '4':
                mh_deletePassword(fileName);
                break;

            case '5':
                mh_changePassword(fileName);
                break;

            case '0':
                printf("\nExiting the password manager...\n");
                displayMenu = false;
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Add a password\n");
    printf("2. View all saved websites\n");
    printf("3. Search for a password\n");
    printf("4. Delete a password\n");
    printf("5. Modify a password\n");
    printf("0. Exit\n\n");
}