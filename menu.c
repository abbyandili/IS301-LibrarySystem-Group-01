
#include <stdio.h>
#include "books.h"

void displayMenu(Book books[], int totalBooks) {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Display All Books\n");
        printf("2. Search for a Book\n"); // Your Branch
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // displayAllBooks(books, totalBooks);
                break;
            case 2:
                searchBook(books, totalBooks); // Calling your new function
                break;
            case 3:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 3);
}