#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "functions.h"

void mh_displayWebsiteNames(char fileName[100]){
    printf("\n\nYour Websites:\n\n");
    int num_of_rows = db_countRows(fileName);
    for(int i=2; i<num_of_rows+1; i++)
    {
        char *website_name = db_getComponent(fileName, i, 1);
        char *user_name = db_getComponent(fileName, i, 3);
        char *notes = db_getComponent(fileName, i, 5);
        if (website_name == NULL || user_name == NULL || notes == NULL){
            //pass if any of them is null (used to avoid displaying blank lines)
        }
        else printf("%s: %s - %s", website_name, user_name ,notes);
    }
    printf("\n");
}

void mh_addingPassword(char fileName[100]){
    char websiteName[100], URL[100], userName[100], password[100];
    char notes[100] = "";
    printf("Adding a password...\n");
    printf("\nEnter the website name [one word]: \n");
    scanf(" %s", websiteName);
    fflush(stdin);
    char websiteName2[100]; //Used to copy the websiste name to websitename2 because for some reason find row would change the websitename variable and change it to the last thing in the database 
    strcpy(websiteName2, websiteName);
    int row = db_find_row(fileName, websiteName);
    if(row == 0)
    {
        printf("\nEnter the website URL [one word]: \n");
        scanf(" %s", URL);
        fflush(stdin);
        printf("\nEnter the username [one word]: \n");
        scanf(" %s", userName);
        fflush(stdin);
        printf("\nEnter the password [one word]: \n");
        scanf(" %s", password);
        fflush(stdin);
        char* encrypted = pw_encrypt(password); //encrypt function using this line
        printf("\nEnter notes [may be multiple words]: \n");
        scanf(" %[^\n]s", notes); //used to scan multiple words seperated by a space
        db_addRecord(fileName, websiteName2, URL, userName, encrypted, notes);
        free(encrypted);
    }
    else
    {
        printf("This website name is already being used in the database. Try again.\n");
    }
}

void mh_changePassword(char fileName[100]){
    char websiteName[100];
    printf("\n\nModifying a password...\n");
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
    if(row <= 0){ 
        printf("This website does not exist in the database. Try again.");

    }else{
        int aux_choice;
        printf("\nAll the information for %s is going to be eliminated, are you sure?\n 1.Yes\n 2.No\n (Your answer): ", websiteName);
        scanf("%d", &aux_choice);
        switch(aux_choice){
            case 1:
                db_deleteRecord(fileName, row);
                printf("\nAll the data from %s has been succesfully eliminated\n\n", websiteName);
                //db_removeEmptyLines(fileName);
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

void mh_searchPassword(char fileName[100]){
    char website_name[100];
    printf("\nSearching for a password...\n\n");
    printf("Which website would you want to know the pasword of your account for?: ");
    scanf(" %s", website_name);

    if(website_name[0] == '\0'){
        printf("\nThat is not a valid name for a webpage\n\n");

    }else{
        strcpy(website_name, strtok(website_name, "\n"));
        int row_number = db_find_row(fileName, website_name);
        if(row_number > 0){
            char *enc_password = db_getComponent(fileName, row_number, 4);
            char *decrypted = pw_decrypt(enc_password);
            printf("\nThe password for %s is %s\n\n\n", website_name, decrypted);
        }else{
            printf("\nERROR - The webpage was not found (Make sure that you already have an account for that webpage)\n\n\n");
        }
    }
}