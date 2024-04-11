#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key 5

char* pw_encrypt(const char* message) {
    size_t length = strlen(message);
    char* encrypted = (char*)malloc((length + 1) * sizeof(char));

    for (size_t i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (char)('a' + (message[i] - 'a' + key) % 26);
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (char)('A' + (message[i] - 'A' + key) % 26);
        } else {
            encrypted[i] = message[i];
        }
    }

    encrypted[length] = '\0';
    return encrypted;
}

char* pw_decrypt(const char* encrypted) {
    size_t length = strlen(encrypted);
    char* decrypted = (char*)malloc((length + 1) * sizeof(char));

    for (size_t i = 0; i < length; i++) {
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = (char)('a' + (encrypted[i] - 'a' - key + 26) % 26);
        } else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = (char)('A' + (encrypted[i] - 'A' - key + 26) % 26);
        } else {
            decrypted[i] = encrypted[i];
        }
    }

    decrypted[length] = '\0';
    return decrypted;
}