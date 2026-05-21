/*#include <stdio.h>
#include <string.h>
#include "auth.h"*/

/*int login() {
    char user[20], pass[20];
    printf("\n--- Admin Login ---\n");
    printf("Username: "); scanf("%s", user);
    printf("Password: "); scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
        return 1;
    }
    printf("Invalid credentials!\n");
    return 0;
}
    */

#include <stdio.h>
#include <string.h>

int login() {
    char user[20], pass[20];
    int authenticated = 0;

    while (!authenticated) {
        printf("\n==============================");
        printf("\n      LIBRARY SYSTEM LOGIN     ");
        printf("\n==============================");
        printf("\nUsername: "); 
        scanf("%s", user);
        printf("Password: "); 
        scanf("%s", pass);

        // Checking against your hardcoded admin credentials
        if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
            printf("\nAccess Granted! Loading system...\n");
            authenticated = 1; // This breaks the while loop
        } else {
            // Error message and loop restarts
            printf("\n[ERROR] Invalid username or password.");
            printf("\nPlease try again.\n");
        }
    }

    return 1; // Returns true to your main() if statements
}