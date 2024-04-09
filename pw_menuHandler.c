#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pw_manager.h"

// Function to display the main menu
void displayMainMenu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Add a password\n");
    printf("2. View all passwords\n");
    printf("3. Search for a password\n");
    printf("4. Delete a password\n");
    printf("5. Exit\n");
}

void displayWebsiteNames(char fileName[100]){
    printf("\n\nYour Websites:\n\n");
    int num_of_rows = countRows(fileName);
    for(int i=2; i<num_of_rows; i++)
    {
        char *website_name = getComponent(fileName, i, 1);
        char *notes = getComponent(fileName, i, 5);
        printf("%d. %s: %s", i-1, website_name, notes);
    }
    printf("\n");
}
