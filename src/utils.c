// File: src/utils.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

void extractFilename(const char *path, char *filename) {
    const char *slash = strrchr(path, '/');
    if (slash)
        strcpy(filename, slash + 1);
    else
        strcpy(filename, path);
}

void appendMetadata(const char *metaFile, const char *username, const char *filename) {
    FILE *fp = fopen(metaFile, "a");
    if (!fp) {
        perror("Failed to open metadata file");
        return;
    }

    time_t now = time(NULL);
    fprintf(fp, "%s | %s | %s", username, filename, ctime(&now));
    fclose(fp);
}

void listEncryptedFiles(const char *username) {
    FILE *fp = fopen("metadata/meta.dat", "r");
    if (!fp) {
        perror("Metadata file error");
        return;
    }

    char line[200];
    printf("\nEncrypted Files for %s:\n", username);
    printf("----------------------------------\n");
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, username)) {
            printf("%s", line);
        }
    }
    fclose(fp);
}
