// File: src/main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"
#include "encrypt.h"
#include "decrypt.h"
#include "utils.h"

void showMenu() {
    printf("\nSecure File Locker\n");
    printf("-----------------------\n");
    printf("1. Register User\n");
    printf("2. Login\n");
    printf("3. Encrypt a File\n");
    printf("4. Decrypt a File\n");
    printf("5. View Encrypted Files\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    int loggedIn = 0;
    char username[50];

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loggedIn = loginUser(username);
                break;
            case 3:
                if (loggedIn) encryptFile(username);
                else printf("Please login first.\n");
                break;
            case 4:
                if (loggedIn) decryptFile(username);
                else printf("Please login first.\n");
                break;
            case 5:
                if (loggedIn) listEncryptedFiles(username);
                else printf("Please login first.\n");
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
