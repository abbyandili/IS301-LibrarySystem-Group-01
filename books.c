#include <stdio.h>
#include <string.h>
#include "books.h"

// FEATURE: Display All Books (Carried over from display branch)
void displayAllBooks(struct Book library[], int count) {
    if (count == 0) {
        printf("\n[!] Inventory is empty. Please add books first.\n");
        return;
    }
    printf("\n%-5s %-25s %-20s %-5s\n", "ID", "Title", "Author", "Qty");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-05d %-25.25s %-20.20s %-5d\n", 
               library[i].bookID, library[i].title, library[i].author, library[i].quantity);
    }
}

// FEATURE: Update Quantity (The core of this branch)
void updateQuantity(struct Book library[], int count) {
    int searchID, newQty, found = 0;

    printf("\nEnter Book ID to update quantity: ");
    if (scanf("%d", &searchID) != 1) {
        printf("[!] Error: ID must be a number.\n");
        while(getchar() != '\n'); 
        return;
    }

    for (int i = 0; i < count; i++) {
        if (library[i].bookID == searchID) {
            found = 1;
            printf("\nFound: %s (Current Qty: %d)\n", library[i].title, library[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &newQty);

            if (newQty < 0) {
                printf("[!] Error: Quantity cannot be negative.\n");
            } else {
                library[i].quantity = newQty;
                // PERSISTENCE: Save to file immediately after change
                saveBooksToFile(library, count);
                printf("[+] Quantity updated and saved to books.txt.\n");
            }
            break;
        }
    }
    if (!found) printf("[!] Book ID %d not found.\n", searchID);
}

// HELPER: Save to File (Ensures data is not lost)
void saveBooksToFile(struct Book library[], int count) {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("[!] Critical Error: Could not save to books.txt\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%s,%d,%d\n", 
                library[i].bookID, library[i].title, library[i].author, 
                library[i].genre, library[i].yearPublished, library[i].quantity);
    }
    fclose(file);
}