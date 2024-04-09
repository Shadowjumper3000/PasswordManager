#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void readWholeFile(char fileName[100]){
    FILE *file = fopen(fileName, "r");
    if(file == NULL){
        perror("Error opening file");
        exit(-1);
    } else {
        printf("File opened succesfully for reading \n");
    }

    //will read the whole file
    char buffer[1000];
    while(fgets(buffer, sizeof(buffer), file)){
        printf("%s\n", buffer);
    }

    fclose(file);
}

void addRecord(char fileName[100], char websiteName[100], char URL[100], char userName[100], char password[100], char notes[100]){
    FILE *file = fopen(fileName, "a");
    if(file == NULL){
        perror("Error opening file");
        exit(-1);
    } else {
        printf("File opened succesfully for appending\n");
    }

    fprintf(file, "\n%s,%s,%s,%s,%s", websiteName, URL, userName, password, notes);
    fclose(file);
}

void deleteRecord(char fileName[100], int LineNo) {
    FILE *temp;
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(-1);
    } else {
        printf("File opened successfully for reading\n");

        temp = tmpfile();
        if (temp == NULL) {
            perror("Error creating temporary file");
            exit(-1);
        } else {
            printf("Temporary file created successfully\n");
        }

        char buffer[1000];
        bool keep_reading = true;
        int current_line = 1;

        // Skip the header line (comment if not needed)
        fgets(buffer, sizeof(buffer), file);
        fputs(buffer, temp);

        // Process data lines
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            if (current_line != LineNo) {
                fputs(buffer, temp);
            }
            current_line++;
        }    

        fclose(file);
        rewind(temp);

        file = fopen(fileName, "w");
        if (file == NULL) {
            perror("Error opening file for writing");
            exit(-1);
        } else {
            printf("File opened successfully for writing\n");
        }

        while (fgets(buffer, sizeof(buffer), temp) != NULL) {
            fputs(buffer, file);
        }

        fclose(file);
        fclose(temp);
    }
}

int countRows(char fileName[100])
{
    FILE *file = fopen(fileName, "r");
    char buffer[1000];
    int current_line = 1;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        current_line++;
    }
    fclose(file);
    return current_line;
}

//allows to get/change/delete a component of a record, the interface
//will be used to specify if its a URL, password, etc.
char* getComponent(char fileName[100], int row, int column){
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        //perror("Error opening file");
        exit(-1);
    } else {
        //printf("File opened successfully for reading\n");

        char *data;
        char buffer[1000];

        //skips to the target row
        for(int i = 0; i < row; i++){
            fgets(buffer, sizeof(buffer), file);
        }
        //printf("The target row is: %s\n", buffer);

        if(column == 1){
            data = strtok(buffer, ",");
            //printf("The first component is: %s\n", data);
        } else{
            data = strtok(buffer, ",");
            //printf("The first component is: %s\n", data);

            for(int i = 0; i < column - 1; i++){
                data = strtok(NULL, ",");
            }
        }

        fclose(file);
        printf("The final output is: %s\n", data);
        return data;
    }
}
//can be used as delete by changing the component to spaces
void changeComponent(char fileName[100], char changedComponent[100], int row, int column){
    FILE *temp;
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(-1);
    } else {
        printf("File opened successfully for reading\n");

        temp = tmpfile();
        if (temp == NULL) {
            perror("Error creating temporary file");
            exit(-1);
        } else {
            printf("Temporary file created successfully\n");
        }

        char buffer[1000];
        int currentRow = 0;

        while(fgets(buffer, sizeof(buffer), file)){
            char *data = strtok(buffer, ",");
            int currentColumn = 0;

            while(data != NULL){
                if(currentRow == row - 1 && currentColumn == column - 1){
                    if(currentColumn == 4){
                        fprintf(temp, "%s\n", changedComponent);
                        printf("The component has been changed\n");
                    } else {
                        fprintf(temp, "%s,", changedComponent);
                        printf("The component has been changed\n");
                    }
                } else if(currentColumn == 4){
                    // printf("CurrColl is equal to 5 so that thing shuld die\n");
                    fprintf(temp, "%s", data);
                } else {
                    fprintf(temp, "%s,", data);
                }

                data = strtok(NULL, ",");
                currentColumn++;
            }
            // fprintf(temp, "\n");
            currentRow++;
        }

        fclose(file);
        rewind(temp);

        file = fopen(fileName, "w");
        if (file == NULL) {
            perror("Error opening file for writing");
            exit(-1);
        } else {
            printf("File opened successfully for writing\n");
        }

        while (fgets(buffer, sizeof(buffer), temp) != NULL) {
            fputs(buffer, file);
        }

        fclose(file);
        fclose(temp);
    }
}

//csv testing data:
// Website name,URL,User name,Password,Notes
// Google,http://www.google.com,myname,mypassword,My google acocunt
// Yahoo,http://www.yahoo.com,myname,mypassword,My yahoo account
// Facebook,http://www.facebook.com,myname,mypassword,My facebook account