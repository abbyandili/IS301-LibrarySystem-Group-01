#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include "auth.h"
#include "menu.h"
#include "books.h"
#include "members.h"
#include "borrowing.h"
#include "filehandling.h" // Added header file link

// Helper function to handle cross-platform screen clearing
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    // Initial data loading
    //loadBooks();
    // (Optional: implement a loadMembers() if you want to initialize members data from file)
    
    // User Authentication
    if (!login()) {
        printf("\nAccess Denied. Program terminating.\n");
        return 0;
    }

    // Clear the screen immediately after successful login
    clearScreen();

    int choice = 0;
    char proceed; 

    while (1) {
        displayMenu();
        
        // Input validation
        if (scanf("%d", &choice) != 1) {
            printf("\n[ERROR] Please enter a valid menu number.\n");
            while(getchar() != '\n'); 
            printf("Press Enter to continue...");
            getchar();
            clearScreen();
            continue;
        }

        // Updated Exit option index to match new expanded options sequence
        if (choice == 11) {
            printf("\nExiting the system. Data saved successfully.\n");
            return 0;
        }

        // Clear screen before running the selected function to focus on the task
        clearScreen();

        // Run the selected function
        switch (choice) {
            case 1: displayAllBooks(); break;
            case 2: searchBook(); break;
            case 3: addBook(); break;
            case 4: updateQuantity(); break;
            case 5: generateInventoryReport(); break;
            case 6: registerMember(); break;
            case 7: viewMembers(); break;
            case 8: updateMemberInfo(); break;
            case 9: issueBook(); break;
            case 10: returnBook(); break;
            default:
                printf("\n[INVALID] %d is not a valid option.\n", choice);
                printf("Press Enter to return to menu...");
                while(getchar() != '\n'); // Clear buffer
                getchar();
                clearScreen();
                continue; 
        }

        // --- Task Completion & Navigation ---
        printf("\n------------------------------------------------");
        printf("\nTask completed. Would you like to perform another action? (y/n): ");
        scanf(" %c", &proceed); 

        if (tolower(proceed) == 'n') {
            printf("\nExiting the system. Goodbye!\n");
            break; 
        }

        // Clear the screen before the loop restarts to show a fresh menu
        clearScreen();
    }

    return 0;
}

