#include <stdio.h>
#include "auth.h"
#include "books.h"
#include "members.h"
#include "borrowing.h"
#include "filehandling.h"


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

int main() {
    int choice;

    if (!login()) {
        printf("Access denied.\n");
        return 0;
    }

    loadBooksFromFile("books.txt");
    loadMembersFromFile("members.txt");

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayAllBooks(); 
            break;
            case 2: searchBook(); 
            break;
            case 3: addBook(); 
            break;
            case 4: updateQuantity(); 
            break;
            case 5: 
            registerMember(); 
            break;     
            case 6: viewMembers(); break;
            case 7: 
            issueBook(); 
            break;
            case 8: returnBook(); 
            break;
            case 9: generateInventoryReport("inventory_report.txt"); 
            break;
        }

    } while (choice != 10);

    return 0;
}
