#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

void mh_displayWebsiteNames(char fileName[100]){
    printf("\n\nYour Websites:\n\n");
    int num_of_rows = db_countRows(fileName);
    for(int i=2; i<num_of_rows; i++)
    {
        char *website_name = db_getComponent(fileName, i, 1);
        char *notes = db_getComponent(fileName, i, 5);
        printf("%d. %s: %s", i-1, website_name, notes);
    }
    printf("\n");
}

void mh_addingPassword(char fileName[100]){
    char websiteName[100], URL[100], userName[100], password[100];
    char notes[100] = "";
    printf("Adding a password...\n");
    printf("\nEnter the website name: \n");
    scanf(" %s", websiteName);
    int row = db_find_row(fileName, websiteName);
    if(row == 0)
    {
        printf("\nEnter the website URL: \n");
        scanf(" %s", URL);
        printf("\nEnter the username: \n");
        scanf(" %s", userName);
        printf("\nEnter the password: \n");
        scanf(" %s", password);
        char* encrypted = pw_encrypt(password); //encrypt function using this line
        printf("\nEnter notes: \n");
        scanf(" %[^\n]s", notes); //used to scan multiple words seperated by a space
        db_addRecord(fileName, websiteName, URL, userName, encrypted, notes);
        free(encrypted);
    }
    else
    {
        printf("This website name is already being used in the database. Try again.\n");
    }
}

void mh_changePassword(char fileName[100]){
    char websiteName[100];
    printf("For which website do you want to change your password? (Enter the website name): \n");
    scanf(" %s", websiteName);
    int row = db_find_row(fileName, websiteName);
    if(row == 0)
    {
        printf("The website name you entered does not exist. Try again.\n");
    }
    else
    {
        char newPassword[100];
        printf("Enter your new password for %s: \n", websiteName);
        scanf(" %s", newPassword);
        char* encrypted_new_pw = pw_encrypt(newPassword);
        db_changeComponent(fileName, encrypted_new_pw, row, 4);
        free(encrypted_new_pw);
    }
}

void mh_deletePassword(char fileName[100]){
    char websiteName[100];
    printf("\nDeleting a password...\n\n");
    printf("Which website would you want to delete the pasword of your account from?(this also eliminates all information with it, so be careful ;D): ");
    scanf(" %s", websiteName);
    int row = db_find_row(fileName, websiteName);
    printf("The row of %s %d", websiteName, row);
    if(row <= 0){ //I dont know but it crashes when "intro" is pressed as an answer (and this doesnt fix it).
        printf("This website does not exist in the database. Try again.");

    }else{
        int aux_choice;
        printf("\nAll the information for %s is going to be eliminated, are you sure?\n 1.Yes\n 2.No\n (Your answer): ", websiteName);
        scanf("%d", &aux_choice);
        switch(aux_choice){
            case 1:
                db_deleteRecord(fileName, row);
                printf("\nAll the data from %s has been succesfully eliminated\n\n", websiteName);
                break;
            case 2:
                printf("\nOk, no problem, we are stoping the process...\n\n");
                break;
            default:
                printf("\nERROR - That was not a valid option\n\n");
                break;
        }
    }
}