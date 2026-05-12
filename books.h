#ifndef BOOKS_H
#define BOOKS_H

// The Book structure based on the project requirements
typedef struct {
    char bookID[20];       // To store IDs like "001"
    char title[100];
    char author[100];
    char genre[50];
    int yearPublished;
    int quantity;
    char availabilityStatus[20]; // For the Inventory Report requirement
} Book;

// Function prototypes for Book Management (Section 3 of your requirements)
// This tells the compiler these functions exist somewhere in the project.

void displayAllBooks(Book books[], int count);
void searchBook(Book books[], int count);
void addBook(Book books[], int *count);
void updateQuantity(Book books[], int count);

#endif