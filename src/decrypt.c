// File: src/decrypt.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decrypt.h"
#include "utils.h"

#define ENCRYPTED_DIR "data/encrypted_files/"

void xorDecryptFile(const char *inputPath, const char *outputPath, const char *key) {
    FILE *fin = fopen(inputPath, "rb");
    FILE *fout = fopen(outputPath, "wb");
    if (!fin || !fout) {
        perror("File error");
        return;
    }
    
    size_t keyLen = strlen(key);
    int ch, i = 0;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ key[i % keyLen], fout);
        i++;
    }

    fclose(fin);
    fclose(fout);
}

void decryptFile(const char *username) {
    char encpath[100], filename[100], key[50], newpath[150];

    printf("Enter path of file to decrypt: ");
    fgets(encpath, sizeof(encpath), stdin);
    strtok(encpath, "\n");

    printf("Enter decryption key: ");
    fgets(key, sizeof(key), stdin);
    strtok(key, "\n");

    extractFilename(encpath, filename);
    filename[strlen(filename) - 4] = '\0'; // remove .enc
    snprintf(newpath, sizeof(newpath), "%s%s", ENCRYPTED_DIR, filename);

    xorDecryptFile(encpath, newpath, key);
    printf("File decrypted and saved to: %s\n", newpath);
}
