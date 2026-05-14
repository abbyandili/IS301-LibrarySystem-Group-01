#include <stdio.h>
#include <string.h>
#include "auth.h"

int login() {
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