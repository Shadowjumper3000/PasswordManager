#ifndef PW_MANAGER_H
#define PW_MANAGER_H

//main.c
void displayMainMenu();

//menuHandler.c
void mh_displayWebsiteNames(char fileName[100]);
void mh_addingPassword(char fileName[100]);
void mh_changePassword(char fileName[100]);
void mh_deletePassword(char fileName[100]);

//db_handler.c
void db_readWholeFile(char fileName[100]);
void db_addRecord(char fileName[100], char websiteName[100], char URL[100], char userName[100], char password[100], char notes[100]);
void db_deleteRecord(char fileName[100], int LineNo);
char* db_getComponent(char fileName[100], int row, int col);
void db_changeComponent(char fileName[100], char changedComponent[100], int row, int column);
int db_countRows(char fileName[100]);
int db_find_row(char fileName[100], char website_name[100]);

//pw_encryption.c
char* pw_encrypt(char* password);
char* pw_decrypt(char* password);

#endif
