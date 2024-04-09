#ifndef PW_MANAGER_H
#define PW_MANAGER_H

void displayMainMenu();

void readWholeFile(char fileName[100]);
void addRecord(char fileName[100], char websiteName[100], char URL[100], char userName[100], char password[100], char notes[100]);
void deleteRecord(char fileName[100], int LineNo);
char* getComponent(char fileName[100], int row, int col);
void changeComponent(char fileName[100], char changedComponent[100], int row, int column);
int countRows(char fileName[100]);
void displayWebsiteNames(char fileName[100]);

void encryptPassword(char* password, int key);
void decryptPassword(char* password, int key);

#endif