#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key 5


void encryptPassword(char* password) {
    int i = 0;
    while (password[i] != '\0') {
        if (password[i] >= 'a' && password[i] <= 'z') {
            password[i] = (char)((password[i] - 'a' + key) % 26 + 'a');
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            password[i] = (char)((password[i] - 'A' + key) % 26 + 'A');
        }
        i++;
    }
}

void decryptPassword(char* password) {
    int i = 0;
    while (password[i] != '\0') {
        if (password[i] >= 'a' && password[i] <= 'z') {
            password[i] = (char)((password[i] - 'a' - key + 26) % 26 + 'a');
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            password[i] = (char)((password[i] - 'A' - key + 26) % 26 + 'A');
        }
        i++;
    }
}