
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "books.h"

// Helper function to convert string to lowercase for easier searching
void toLowerCase(char str[]) {
    for(int i = 0; str[i]; i++) {
        str[i] =领域tolower(str[i]);
    }
}

void searchBook(Book books[], int totalBooks) {
    char searchTerm[100];
    int found = 0;

    printf("\n--- Search for a Book ---\n");
    printf("Enter Title or Author: ");
    scanf(" %[^\n]s", searchTerm); // Reads string with spaces

    char lowerSearch[100];
    strcpy(lowerSearch, searchTerm);
    toLowerCase(lowerSearch);

    printf("\nSearch Results:\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < totalBooks; i++) {
        char tempTitle[100], tempAuthor[100];
        strcpy(tempTitle, books[i].title);
        strcpy(tempAuthor, books[i].author);
        
        toLowerCase(tempTitle);
        toLowerCase(tempAuthor);

        // Check if search term exists in Title or Author
        if (strstr(tempTitle, lowerSearch) || strstr(tempAuthor, lowerSearch)) {
            printf("ID: %s | Title: %s | Author: %s | Qty: %d\n", 
                   books[i].bookID, books[i].title, books[i].author, books[i].quantity);
            found++;
        }
    }

    if (found == 0) {
        printf("No books found matching '%s'.\n", searchTerm);
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total matches found: %d\n", found);
    }
}