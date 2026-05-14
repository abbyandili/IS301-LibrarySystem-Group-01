#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "books.h"
#include "filehandling.h"

// Assuming these are defined in books.h or a config file
#define MAX_BOOKS 100

// Utility to convert strings to lowercase for case-insensitive search
void toLowerCase(char str[]) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// FEATURE: Add New Book
void addBook() {
    Book books[MAX_BOOKS];
    int count = 0;
    loadBooks(books, &count); // Load existing data first

    if (count >= MAX_BOOKS) {
        printf("\n[!] Error: Book catalogue full.\n");
        return;
    }

    Book b;
    printf("\n--- Add New Book ---\n");
    printf("Enter Book ID: "); scanf("%s", b.id);
    printf("Title: ");         scanf(" %[^\n]", b.title);
    printf("Author: ");        scanf(" %[^\n]", b.author);
    printf("Genre: ");         scanf(" %[^\n]", b.genre);
    printf("Year: ");          scanf("%d", &b.year);
    printf("Quantity: ");      scanf("%d", &b.quantity);

    books[count++] = b;
    saveBooks(books, count); // Persist to file
    printf("\n[+] Book %s added successfully.\n", b.id);
}

// FEATURE: Display All Books
void displayAllBooks() {
    Book books[MAX_BOOKS];
    int count = 0;
    loadBooks(books, &count);

    if (count == 0) {
        printf("\n[!] Inventory is empty.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-5s\n", "ID", "Title", "Author", "Qty");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-25.25s %-20.20s %-5d\n", 
               books[i].id, books[i].title, books[i].author, books[i].quantity);
    }
}

// FEATURE: Search Book (Case Insensitive)
void searchBook() {
    Book books[MAX_BOOKS];
    int count = 0;
    loadBooks(books, &count);

    char term[100], lowerTerm[100];
    int found = 0;

    printf("\nEnter Title or Author to search: ");
    scanf(" %[^\n]", term);
    
    strcpy(lowerTerm, term);
    toLowerCase(lowerTerm);

    printf("\nSearch Results:\n");
    for (int i = 0; i < count; i++) {
        char tempTitle[100], tempAuthor[100];
        strcpy(tempTitle, books[i].title);
        strcpy(tempAuthor, books[i].author);
        toLowerCase(tempTitle);
        toLowerCase(tempAuthor);

        if (strstr(tempTitle, lowerTerm) || strstr(tempAuthor, lowerTerm)) {
            printf("[%s] %s by %s (Stock: %d)\n", 
                   books[i].id, books[i].title, books[i].author, books[i].quantity);
            found++;
        }
    }
    if (!found) printf("No matches found for '%s'.\n", term);
}

// FEATURE: Update Quantity
void updateQuantity() {
    Book books[MAX_BOOKS];
    int count = 0;
    char searchID[10];
    int newQty, found = 0;

    loadBooks(books, &count);

    printf("\nEnter Book ID to update: ");
    scanf("%s", searchID);

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].id, searchID) == 0) {
            found = 1;
            printf("Found: %s (Current Qty: %d)\n", books[i].title, books[i].quantity);
            printf("Enter new quantity: ");
            if (scanf("%d", &newQty) != 1 || newQty < 0) {
                printf("[!] Invalid quantity.\n");
                return;
            }
            books[i].quantity = newQty;
            saveBooks(books, count);
            printf("[+] Quantity updated and saved.\n");
            break;
        }
    }
    if (!found) printf("[!] Book ID %s not found.\n", searchID);
}