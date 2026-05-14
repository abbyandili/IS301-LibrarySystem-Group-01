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

    // SAFETY: Clear the input buffer before starting login.
    // This prevents fgets from skipping if there was a newline left by a previous scanf.
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("\n==============================");
    printf("\n      ADMINISTRATOR LOGIN");
    printf("\n==============================");

    while (attempts < MAX_ATTEMPTS) {
        printf("\nUsername: ");
        if (fgets(username, sizeof(username), stdin) == NULL) break;
        username[strcspn(username, "\n")] = 0; // Strip newline

        printf("Password: ");
        if (fgets(password, sizeof(password), stdin) == NULL) break;
        password[strcspn(password, "\n")] = 0; // Strip newline

        if (strcmp(username, CORRECT_USER) == 0 && strcmp(password, CORRECT_PASS) == 0) {
            printf("\n[SUCCESS] Welcome, %s.\n", username);
            return 1;
        } else {
            attempts++;
            if (attempts < MAX_ATTEMPTS) {
                printf("[!] Invalid credentials. %d attempts left.\n", MAX_ATTEMPTS - attempts);
            }
        }
    }

    printf("\n[ERROR] Too many failed attempts. Access denied.\n");
    return 0;
}