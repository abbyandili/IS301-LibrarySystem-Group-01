#include <stdio.h>
#include <string.h>
#include "auth.h"

int authenticateAdmin() {
    char username[20];
    char password[20];
    const char adminUser[] = "admin";
    const char adminPass[] = "dwu123"; // Example password

    printf("\n============================\n");
    printf("   LIBRARY ADMIN LOGIN\n");
    printf("============================\n");

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, adminUser) == 0 && strcmp(password, adminPass) == 0) {
        printf("\nLogin Successful! Welcome, Administrator.\n");
        return 1;
    } else {
        printf("\nInvalid Credentials. Access Denied.\n");
        return 0;
    }
}