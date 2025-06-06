// File: src/auth.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"

#define CREDENTIALS_FILE "data/user_credentials.dat"

void registerUser() {
    char username[50], password[50];
    FILE *fp = fopen(CREDENTIALS_FILE, "a");
    if (!fp) {
        perror("Failed to open credentials file");
        return;
    }

    printf("Enter new username: ");
    fgets(username, sizeof(username), stdin);
    strtok(username, "\n");

    printf("Enter new password: ");
    fgets(password, sizeof(password), stdin);
    strtok(password, "\n");

    fprintf(fp, "%s:%s\n", username, password);
    fclose(fp);
    printf("User registered successfully!\n");
}

int loginUser(char *loggedUser) {
    char username[50], password[50], line[100];
    char storedUser[50], storedPass[50];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    strtok(username, "\n");

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    strtok(password, "\n");

    FILE *fp = fopen(CREDENTIALS_FILE, "r");
    if (!fp) {
        perror("Failed to open credentials file");
        return 0;
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^:]:%s", storedUser, storedPass);
        if (strcmp(username, storedUser) == 0 && strcmp(password, storedPass) == 0) {
            fclose(fp);
            strcpy(loggedUser, username);
            printf("Login successful!\n");
            return 1;
        }
    }
    fclose(fp);
    printf("Invalid credentials.\n");
    return 0;
}
