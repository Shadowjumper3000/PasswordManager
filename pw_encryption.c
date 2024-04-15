#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key 5

char* pw_encrypt(const char* message) {
    size_t length = strlen(message);
    char* encrypted = (char*)malloc((length + 1) * sizeof(char));

    for (size_t i = 0; i < length; i++) {
        encrypted[i] = (char)((message[i] + key) % 256);
    }

    encrypted[length] = '\0';
    return encrypted;
}

char* pw_decrypt(const char* encrypted) {
    size_t length = strlen(encrypted);
    char* decrypted = (char*)malloc((length + 1) * sizeof(char));

    for (size_t i = 0; i < length; i++) {
        decrypted[i] = (char)((encrypted[i] - key + 256) % 256);
    }

    decrypted[length] = '\0';
    return decrypted;
}
