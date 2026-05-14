#ifndef BOOKS_H
#define BOOKS_H

// The blueprint for every book in the system
struct Book {
    int bookID;
    char title[100];
    char author[100];
    char genre[50];
    int yearPublished;
    int quantity;
};

// Function Prototypes (The tools available in this branch)
void displayAllBooks(struct Book library[], int count);
void updateQuantity(struct Book library[], int count);
void saveBooksToFile(struct Book library[], int count);

#endif


