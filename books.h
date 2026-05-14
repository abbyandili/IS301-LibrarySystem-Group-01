#ifndef BOOKS_H
#define BOOKS_H

// Make sure this structure matches your group's common definition!
struct Book {
    int bookID;
    char title[100];
    char author[100];
    char genre[50];
    int yearPublished;
    int quantity;
};

// Function Prototypes (Your "Promises" to the group)
void displayAllBooks(struct Book library[], int count);
void updateQuantity(struct Book library[], int count);
void saveBooksToFile(struct Book library[], int count); // Helper function to save changes

#endif
