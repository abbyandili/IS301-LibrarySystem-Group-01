#ifndef BOOKS_H
#define BOOKS_H

#define MAX_BOOKS 100

/**
 * The single, unified blueprint for a Book.
 * Matches the format in books.txt: ID, Title, Author, Genre, Year, Qty
 */
typedef struct {
    char id[20];           // Supports "001"
    char title[100];
    char author[100];
    char genre[50];
    int yearPublished;
    int quantity;
    char status[20];       // "Available" or "Out of Stock"
} Book;

/* 
   Function Prototypes 
   Logic implemented in books.c
*/

// Section 3: Book Management Requirements
void displayAllBooks();
void searchBook();
void addBook();
void updateQuantity();

// Utility function for case-insensitive search
void toLowerCase(char str[]);

#endif /* BOOKS_H */