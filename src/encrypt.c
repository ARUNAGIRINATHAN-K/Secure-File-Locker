#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "encrypt.h"
#include "utils.h"

#define ENCRYPTED_DIR "data/encrypted_files/"
#define META_FILE "metadata/meta.dat"

void xorEncryptFile(const char *inputPath, const char *outputPath, const char *key) {
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

void encryptFile(const char *username) {
    char filepath[100], filename[100], key[50], newpath[150];

    printf("Enter path of file to encrypt: ");
    fgets(filepath, sizeof(filepath), stdin);
    strtok(filepath, "\n");

    printf("Enter key for encryption: ");
    fgets(key, sizeof(key), stdin);
    strtok(key, "\n");

    extractFilename(filepath, filename);
    snprintf(newpath, sizeof(newpath), "%s%s.enc", ENCRYPTED_DIR, filename);

    xorEncryptFile(filepath, newpath, key);
    printf("File encrypted and saved to: %s\n", newpath);

    appendMetadata(META_FILE, username, filename);
}
