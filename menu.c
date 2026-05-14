#include <stdio.h>
#include <stdlib.h>
#include "auth.h"
#include "books.h"
#include "members.h"
#include "filehandling.h"

// Helper function to pause the screen for readability
void pause() {
    printf("\nPress Enter to continue...");
    getchar(); // Catch the newline from previous input
    getchar(); // Wait for user to press Enter
}

void displayMenu() {
    int choice;

    do {
        // Optional: clear screen for a cleaner UI (system dependent)
        // system("cls"); // For Windows
        // system("clear"); // For Linux/macOS

        printf("\n==========================================");
        printf("\n      LIBRARY MANAGEMENT SYSTEM");
        printf("\n==========================================");
        printf("\n 1. Display All Books");
        printf("\n 2. Search for a Book");
        printf("\n 3. Add a New Book");
        printf("\n 4. Update Book Quantity");
        printf("\n 5. Register New Member");
        printf("\n 6. Generate Inventory Report");
        printf("\n 7. Exit");
        printf("\n------------------------------------------");
        printf("\n Enter your choice (1-7): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n[!] Invalid input. Please enter a number.\n");
            // Clear entire buffer if user types text
            int c;
            while ((c = getchar()) != '\n' && c != EOF); 
            continue;
        }

        switch(choice) {
            case 1:
                displayAllBooks();
                pause();
                break;
            case 2:
                searchBook();
                pause();
                break;
            case 3:
                addBook();
                pause();
                break;
            case 4:
                updateQuantity();
                pause();
                break;
            case 5:
                registerMember();
                pause();
                break;
            case 6:
                generateInventoryReport();
                pause();
                break;
            case 7:
                printf("\nExiting system... Goodbye!\n");
                break;
            default:
                printf("\n[!] Invalid choice! Please select 1-7.\n");
                pause();
        }
    } while(choice != 7);
}

int main() {
    // 1. Authenticate first (Make sure login clears its own buffer)
    if (!login()) {
        printf("\n[ERROR] Authentication failed. Exiting...\n");
        return 1;
    }

    // 2. Start the menu
    displayMenu();

    return 0;
}