#include <stdio.h>
#include <string.h>
#include "books.h"

// FEATURE 1: Display All Books
void displayAllBooks(struct Book library[], int count) {
    if (count == 0) {
        printf("\n[!] The library is empty. No books to display.\n");
        return;
    }

    printf("\n==================== LIBRARY INVENTORY ====================\n");
    printf("%-5s %-25s %-20s %-5s\n", "ID", "Title", "Author", "Qty");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-05d %-25.25s %-20.20s %-5d\n", 
               library[i].bookID, 
               library[i].title, 
               library[i].author, 
               library[i].quantity);
    }
    printf("===========================================================\n");
}

// FEATURE 2: Update Quantity
void updateQuantity(struct Book library[], int count) {
    int id, newQty, found = 0;

    printf("\nEnter the Book ID to update quantity: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].bookID == id) {
            found = 1;
            printf("Current Quantity for '%s': %d\n", library[i].title, library[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &newQty);

            if (newQty < 0) {
                printf("[!] Error: Quantity cannot be negative.\n");
            } else {
                library[i].quantity = newQty;
                printf("[+] Quantity updated successfully!\n");
                
                // Save the change to books.txt immediately
                saveBooksToFile(library, count);
            }
            break;
        }
    }

    if (!found) {
        printf("[!] Book ID %d not found.\n", id);
    }
}

// HELPER: Save to books.txt
void saveBooksToFile(struct Book library[], int count) {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("[!] Error: Could not open books.txt for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%s,%d,%d\n", 
                library[i].bookID, library[i].title, library[i].author, 
                library[i].genre, library[i].yearPublished, library[i].quantity);
    }

    fclose(file);
}