#include <stdio.h>
#include <stdlib.h>
#include "auth.h"
#include "books.h"
#include "members.h"
#include "borrowing.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    // 1. Initial Authentication
    if (!login()) {
        printf("\n[ERROR] Authentication failed. Access denied.\n");
        return 1;
    }

    int choice;
    while (1) {
        printf("\n==========================================");
        printf("\n      LIBRARY MANAGEMENT SYSTEM");
        printf("\n==========================================");
        printf("\n 1. Display All Books");
        printf("\n 2. Search for a Book (Title/Author)");
        printf("\n 3. Add a New Book");
        printf("\n 4. Update Book Quantity");
        printf("\n 5. Register New Member");
        printf("\n 6. Issue a Book (Borrowing)");
        printf("\n 7. Generate Inventory Report");
        printf("\n 8. Exit");
        printf("\n------------------------------------------");
        printf("\n Enter your choice (1-8): ");
        
        // Input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            printf("\n[ERROR] Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                displayAllBooks();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                addBook();
                break;
            case 4:
                updateQuantity();
                break;
            case 5:
                registerMember();
                break;
            case 6:
                issueBook();
                break;
            case 7:
                generateInventoryReport();
                break;
            case 8:
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default:
                printf("\n[!] Invalid option. Please select 1-8.\n");
        }
        
        printf("\nPress Enter to return to menu...");
        getchar(); // Catch newline
        getchar(); // Wait for user
        clearScreen();
    }

    return 0;
}