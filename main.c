#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Required for tolower()
#include "auth.h"
#include "menu.h"
#include "books.h"
#include "members.h"

int main() {
    // Initial data loading
    loadBooks();
    
    // User Authentication
    if (!login()) {
        printf("\nAccess Denied. Program terminating.\n");
        return 0;
    }

    int choice = 0;
    char proceed; // Variable to store the user's stay/exit choice

    while (1) {
        displayMenu();
        
        // Input validation
        if (scanf("%d", &choice) != 1) {
            printf("\n[ERROR] Please enter a valid menu number.\n");
            while(getchar() != '\n'); 
            continue;
        }

        // Handle the explicit exit option first
        if (choice == 6) {
            printf("\nExiting the system. Data saved successfully.\n");
            return 0;
        }

        // Run the selected function
        switch (choice) {
            case 1: displayAllBooks(); break;
            case 2: searchBook(); break;
            case 3: addBook(); break;
            case 4: updateQuantity(); break;
            case 5: generateInventoryReport(); break;
            default:
                printf("\n[INVALID] %d is not a valid option.\n", choice);
                continue; // Skip the "Stay or Exit" prompt if input was invalid
        }

        // --- NEW LOGIC START ---
        printf("\nTask completed. Would you like to perform another action? (y/n): ");
        // The space before %c is CRITICAL to consume the 'Enter' key from previous input
        scanf(" %c", &proceed); 

        if (tolower(proceed) == 'n') {
            printf("\nExiting the system. Goodbye!\n");
            break; // Breaks the while(1) loop
        }
        // --- NEW LOGIC END ---
    }

    return 0;
}