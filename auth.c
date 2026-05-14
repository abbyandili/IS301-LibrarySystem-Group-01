#include <stdio.h>
#include <string.h>
#include "auth.h"

/**
 * Simple Authentication System
 * Returns 1 if successful, 0 if failed.
 */
int login(void) {
    char username[30];
    char password[30];
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    // Hardcoded credentials for the IS301 project
    const char *CORRECT_USER = "admin";
    const char *CORRECT_PASS = "is301dwu";

    printf("\n--- System Login ---\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("Username: ");
        if (fgets(username, sizeof(username), stdin) == NULL) break;
        username[strcspn(username, "\n")] = 0; // Remove newline

        printf("Password: ");
        if (fgets(password, sizeof(password), stdin) == NULL) break;
        password[strcspn(password, "\n")] = 0; // Remove newline

        if (strcmp(username, CORRECT_USER) == 0 && strcmp(password, CORRECT_PASS) == 0) {
            printf("\nLogin Successful. Welcome to the system.\n");
            return 1;
        } else {
            attempts++;
            printf("Invalid credentials. Attempts remaining: %d\n", MAX_ATTEMPTS - attempts);
        }
    }

    return 0;
}
